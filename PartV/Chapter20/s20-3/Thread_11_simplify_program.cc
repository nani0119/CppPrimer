#include <iostream>
#include <string>
#include <list>
#include <functional>
#include <algorithm>
#include <numeric>
#include <future>
#include <thread>
#include <mutex>

using namespace std;


template <typename T>
list<T> sequential_quick_sort(std::list<T> input)
{
	if(input.empty())
	{
		return input;
	}

	list<T> result;
	result.splice(result.begin(), input, input.begin());
	const T& pivot = *(result.begin());

	auto  pivot_point = std::partition(input.begin(), input.end(), [&](const T& t){return t < pivot;});

	list<T> lower_part;
	lower_part.splice(lower_part.end(),input, input.begin(), pivot_point);

	auto new_lower(sequential_quick_sort(std::move(lower_part)));
	auto new_higher(sequential_quick_sort(std::move(input)));
	
	result.splice(result.end(), new_higher);
	result.splice(result.begin(), new_lower);
	
	return result;
}


template <typename T>
list <T> parallel_quick_sort(std::list<T> input)
{
	if(input.empty())
		return input;

	list<T> result;
	result.splice(result.begin(),input, input.begin());
	const T& pivot = *(result.begin());

	auto pivot_point = std::partition(input.begin(), input.end(), [&](const T& t){return t < pivot;});
	list<T> lower_part;
	lower_part.splice(lower_part.end(),input, input.begin(), pivot_point);

	future<list<T>> new_lower(async(&parallel_quick_sort<T>, std::move(lower_part)));

	auto new_higher(parallel_quick_sort<T>(std::move(input)));

	result.splice(result.end(), new_higher);
	result.splice(result.begin(), new_lower.get());
	return result;
}
#if 0
template<typename F, typename A>
std::future<std::result_of<F(A&&)>::type> spawn_task(F&& f, A&& a)
{
	typedef std::result_of<F(A&&)>::type result_type;

	packaged_task<result_type(A&&)> task(std::move(f));
	future<result_type> res(task.get_future());
	thread t(std::move(task), std::move(a));
	t.detach();
	return res;
}
#endif

int main(int argc, char *argv[])
{
	list<int> l1 = {2,45,67,8,9,43,3443,455,76,9879,0,6,675,44,563,233,4,3,2,4,6,87,45,623,4,343,23};
	list<int> l2 = sequential_quick_sort(l1);
	for(auto it = l2.begin(); it != l2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "===================================================" << endl;

	list<int> l3 = parallel_quick_sort<int>(l1);
	for(auto it = l3.begin(); it != l3.end(); it++) {
		cout << *it  << " ";
	}
	cout << endl;
	return 0;
}
