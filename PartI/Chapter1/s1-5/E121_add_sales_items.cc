#include <Sales_item.h>

using namespace std;

int main(int argc, char *argv[])
{
	Sales_item item1, item2;
	cout << "input two Sales_item with the same isbn and add them" << endl;
	cin >> item1 >> item2;
	cout << item1 + item2 << endl;
	return 0;
}
