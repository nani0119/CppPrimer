#include "Sales_data.h"

Sales_data::Sales_data(istream& is)
{
   read(cin, *this);
}

string Sales_data::isbn() const
{
	return bookNo;
}

double Sales_data::avg_price() const
{
	return this->units_sold? this->revenue/this->units_sold: 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& read(istream&is, Sales_data& item)
{
	double price = 0;
	is >>item.bookNo;
	is >> item.units_sold;
	is >> price;
	item.revenue = item.units_sold*price;
	return is;
}

ostream& print(ostream& os,const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price()<<endl;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;  // copy data members from lhs into sum
    sum.combine(rhs);      // add data members from rhs into sum
    return sum;
}

ostream& operator<<(ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

istream& operator>>(istream& is, Sales_data& item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if(is)
		item.revenue = price * item.units_sold;
	else
		item = Sales_data();

	return is;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

bool operator==(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data& lhs, const Sales_data& rhs)
{
	return !(lhs == rhs);
}
