#include <iostream>
#include <string>

using namespace std;
class Sales_data{
		friend istream& read(istream& is, Sales_data& item);
		friend ostream& print(ostream& os,const Sales_data &item);
		friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
		friend ostream& operator<<(ostream& os, const Sales_data& item);
		friend istream& operator>>(istream& is, Sales_data& item);
		friend Sales_data operator+(const Sales_data& c1, const Sales_data& c2);
		friend bool operator==(const Sales_data& lhs, const Sales_data& rhs);
		friend bool operator!=(const Sales_data& lhs, const Sales_data& rhs);
	private:
		string bookNo;
		unsigned units_sold = 0;
		double revenue = 0;
		double avg_price() const;
	public:
		Sales_data() = default;
		Sales_data(const string& s): bookNo(s) {}
		Sales_data(const string& s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
    	Sales_data(istream& is);

		string isbn() const;
		Sales_data& combine(const Sales_data&);
};

istream& read(istream& is, Sales_data& item);
ostream& print(ostream& os,const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
ostream& operator<<(ostream& os, const Sales_data& item);
istream& operator>>(istream& is, Sales_data& item);
Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);

