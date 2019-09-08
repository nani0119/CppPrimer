#ifndef SALES_ITEM_H
#define SALES_ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Sales_item;
ostream& operator<<(ostream& os, const Sales_item& item);
istream& operator>>(istream& is, Sales_item& item);
Sales_item operator+(const Sales_item& lhs, const Sales_item& rhl);

class Sales_item
{
friend ostream& operator<<(ostream& os, const Sales_item& item);
friend istream& operator>>(istream& is, Sales_item& item);
friend Sales_item operator+(const Sales_item& lhs, const Sales_item& rhl);
private:
	string bookNo;
	unsigned int units_sold = 0;
	double revenue = 0.0;

public:
	Sales_item() = default;
	Sales_item(string book, unsigned int s, double p ): bookNo(book), units_sold(s), revenue(p*s) {}
	string isbn() const
	{
		return bookNo;
	}

	double avg_price() const
	{
		if (units_sold != 0)
			return revenue / units_sold;
		else
			return 0.0;
	}
	Sales_item& operator=(const Sales_item& rhs)
	{
		bookNo = rhs.bookNo;
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
		return *this;
	}
	Sales_item& operator+=(const Sales_item& rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	virtual ~Sales_item() = default;
};

#endif /* SALES_ITEM_H */
