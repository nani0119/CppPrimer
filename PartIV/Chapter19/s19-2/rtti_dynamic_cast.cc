#include <iostream>
#include <typeinfo>

class Base
{
	friend bool operator==(const Base& lhs, const Base& rhs);
public:
	Base() = default;
	Base(int n): i(n) {};
protected:
	virtual bool equal(const Base& b) const
	{
		std::cout <<"Base equal:" << i << "   " <<b.i << std::endl; 
		return  i == b.i;
	}
private:
	int i = 0;
};

class Derived: public Base
{
private:
	int j = 0;
public:
	Derived() = default;
	Derived(int a, int b):Base(a), j(b) {};
protected:
	virtual bool equal(const Base& b) const
	{
		auto r = dynamic_cast<const Derived&>(b);
		std::cout << "Derived:" << j << "   " << r.j << std::endl;
		return j == r.j && Base::equal(b);
	}
};

bool operator==(const Base& lhs, const Base& rhs)
{
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}


int main(int argc, char *argv[])
{
	Derived d1(1,2);
	Derived d2(3,2);

	std::cout << "d1 == d2:" <<std::endl<< std::boolalpha << (d1==d2) << std::noboolalpha << std::endl;
	return 0;
}
