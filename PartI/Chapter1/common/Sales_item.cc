#include "Sales_item.h"

using namespace std;


ostream& operator<<(ostream& os,const Sales_item& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.avg_price(); 
	return os;
}

istream& operator>>(istream& is, Sales_item& item)
{
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item item;
	item.revenue = lhs.revenue + rhs.revenue;
	item.units_sold = lhs.units_sold + rhs.units_sold;
	return item;
}

