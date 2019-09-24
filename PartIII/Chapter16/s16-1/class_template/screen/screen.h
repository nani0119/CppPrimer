#include <iostream>
#include <vector>
#include <memory>
#include <initializer_list>

using namespace std;

template <typename T, size_t W, size_t H>
class screen
{
private:
	shared_ptr<vector<T>> data;
public:
	screen(initializer_list<T> il): data(make_shared<vector<T>>(il)) {}
	void show()
	{
		cout << W << "X" << H << ":" << endl;
		for(auto it = data->begin(); it != data->end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
};
