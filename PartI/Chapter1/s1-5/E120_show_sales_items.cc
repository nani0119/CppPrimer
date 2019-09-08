#include "Sales_item.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "input sales_item with format: isbn unit_solds price" << endl;
	
	Sales_item item;
	while(cin >> item)
	{
		cout << item << endl;
	}
	return 0;
}
