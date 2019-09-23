#include <iostream>
#include <set>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Quote
{
private:
	string bookNo;
protected:
	double price = 0.0;

public:
	Quote()=default;
	Quote(const string& book, double sale_price): bookNo(book), price(sale_price) {
		// debug();
	};
	Quote(const Quote& q)
	{
		// cout << "Quote copy control construct" << endl;
		bookNo = q.bookNo;
		price = q.price;
	}
	virtual  Quote* clone() const &
	{
		return new Quote(*this);
	}
	virtual Quote* clone() const &&
	{
		return new Quote(std::move(*this));
	}
	Quote& operator=(const Quote& q)
	{
		// cout << "Quote copy assignment operatopr" << endl;
		bookNo = q.bookNo;
		price = q.price;
		return *this;
	}
	string isbn() const {return bookNo;}

	virtual double net_price(size_t n) const
	{
		// cout << "call Quote net_price" <<endl;
		return n*price;
	}
	virtual void debug(ostream& os = cout)
	{
		os << "============================" << endl;
		os << "Quote:\t" << endl;
		os << "bookNo:\t" << isbn() << endl;
		os << "price:\t" << price << endl;
		os << "============================" << endl;
	}
	virtual ~Quote()=default;
};

class Disc_quote:public Quote {

	protected:
		size_t quantity = 0;
		double discount = 0.0;
	public:
		Disc_quote() = default;
		Disc_quote(const string& book, double sale_price, size_t qty, double disc): Quote(book, sale_price), quantity(qty), discount(disc)
		{
			// debug();
		}
		Disc_quote(const Disc_quote& d):Quote(d)
		{
			// cout << "Disc_quote copy control construct" << endl;
			quantity = d.quantity;
			discount = d.discount;
		}
		Disc_quote& operator=(const Disc_quote& d)
		{
			// cout << "Disc_quote copy assignment operator" << endl;
			Quote::operator=(d);
			quantity = d.quantity;
			discount = d.discount;
			return *this;
		}
		double net_price(size_t n) const = 0;
		Disc_quote* clone() const & = 0;
		void debug(ostream& os = cout) override
		{
			os << "============================" << endl;
			os << "Disc_quote:" << endl;
			os << "quantity:\t" << quantity<<endl;
			os << "discount:\t" << discount<<endl;
			os << "============================" << endl;
		}

};

class Bulk_quote:  public Disc_quote {
	public:
		// Bulk_quote()=default;
		// Bulk_quote(const string& book, double sale_price,size_t qty, double disc):Disc_quote(book,sale_price,qty,disc)
		// {
		// 	// debug();	
		// }
		// Bulk_quote(const Bulk_quote& b):Disc_quote(b)
		// {
		// 	// cout << "Bluk_qutoe copy contrl construct"<<endl;
		// }
		using Disc_quote::Disc_quote;
		Bulk_quote* clone() const &
		{
			return new Bulk_quote(*this);
		}
		Bulk_quote* clone() const &&
		{
			return new Bulk_quote(std::move(*this));
		}
		Bulk_quote& operator=(const Bulk_quote& b)
		{
			// cout << "Bulk_quote copy assignment operation" << endl;
			Disc_quote::operator=(b);
			return *this;
		}
		double net_price(size_t n) const override
		{
			// cout << "call Bulk_quote net_price" <<endl;
			if (n < quantity)
				return n*price;
			else
				return n*price*(1-discount);
		}
		void debug(ostream& os = cout) override
		{
			os << "============================" << endl;
			os << "Bluk_quote:" << endl;
			os << "bookNo:\t" << isbn() << endl;
			os << "price:\t" << price << endl;
			os << "min_qty:\t" << quantity << endl;
			os << "discount:\t" << discount << endl;
			os << "============================" << endl;
		}
};

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
}

class Basket {

	private:
	   static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs)
	   {
		   return lhs->isbn() < rhs->isbn();
	   }

	   multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
	
	public:
	   void add_item(const shared_ptr<Quote>& item)
	   {
		   items.insert(item);
	   }
       void add_item(const Quote& sale)
	   {
		   items.insert(shared_ptr<Quote>(sale.clone()));
	   }
	   void add_item(const Quote&& sale)
	   {
		   items.insert(shared_ptr<Quote>(std::move(sale.clone())));
	   }
	   double total_receipt(ostream& os) const
	   {
		  double sum = 0.0;
		  for(auto it = items.cbegin(); it != items.cend(); it=items.upper_bound(*it)) {
		  	sum+=print_total(os, **it, items.count(*it));
		  }
		  os << "Total Sale: " << sum << endl;
		  return sum;
	  }

};


int main(int argc, char *argv[])
{
#if 0
	// string book = "123-456-7890";
#if 0
	Quote q("123-456-7890", 35);
	Bulk_quote bq("098-765-4321",40,5,0.8);
	print_total(cout, q, 4);
	print_total(cerr, bq, 3);
	print_total(cout,bq,5);
	Quote & rq = bq;
	print_total(cout,rq,5);
	q.debug();
	rq.debug();
	Quote* pq = &bq;
	bq.debug();
	Bulk_quote bcq(bq);
	bcq.debug();
	Bulk_quote beq;
    beq	= bq;
	beq.debug();
#else
	Bulk_quote bq("098-765-4321",40,5,0.8);
	vector<Quote> vq;
	vq.push_back(bq);
	cout << vq.back().net_price(6) << endl;
	
	vector<shared_ptr<Quote>> vsq;
	vsq.push_back(make_shared<Bulk_quote>(bq));
	cout << vsq.back()->net_price(6) << endl;
#endif
#else
	Basket bsk;
	bsk.add_item(make_shared<Quote>("123", 45));
	bsk.add_item(make_shared<Quote>("123", 45));
	bsk.add_item(make_shared<Quote>("456", 45));

	bsk.add_item(make_shared<Bulk_quote>("345", 45, 3, .15));
	bsk.add_item(make_shared<Bulk_quote>("345", 45, 3, .15));
	bsk.add_item(make_shared<Bulk_quote>("345", 45, 3, .15));
	bsk.add_item(make_shared<Bulk_quote>("567", 45, 3, .15));
	
	Quote q("123",45);
	bsk.add_item(q);
	bsk.add_item(std::move(q));

	Bulk_quote bq("345",45,3,.15);
	bsk.add_item(bq);
	bsk.add_item(std::move(bq));

	bsk.total_receipt(cout);
#endif
	return 0;

}
