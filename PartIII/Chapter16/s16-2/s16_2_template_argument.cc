#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

template <typename R, typename T1, typename T2>

R sum_template(const T1& t1, const T2& t2)
{
	return t1+t2;
}


// trailing type
template <typename It>
auto fnc(It beg, It end)  -> decltype(*beg)
{
	return *beg;   // // return a reference to an element from the range
}


// Standard Type Transformation Templates  ----- type_traits
template <typename It>
auto func_not_reference(It beg, It end)  -> typename remove_reference<decltype(*beg)>::type   // we must use typename in the declaration of 
																							  //the return type to tell the  compiler 
																							  //that type represents a decltype
{
	return *beg;
}



int main(int argc, char *argv[])
{
	// error: can't infer initial template parameters
	// auto val3 = sum_template<long long>(i, lng);

	// ok: all three parameters are explicitly specified
	auto sum = sum_template<double, int, double>(3,5.0);
	cout << sum << endl;
	
	
	return 0;
}
