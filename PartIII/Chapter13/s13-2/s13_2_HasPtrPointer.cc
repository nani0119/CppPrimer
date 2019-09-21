#include <iostream>
#include <string>
#include <new>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()):ps(new string(s)), i(0), use(new size_t(1)){
		cout << "====HasPtr construct===="<<endl;
		cout << "----->"<<endl<<"\tps:" << ps <<endl<<"\ti:" << i <<endl<< "\tuse:"<<*use<<endl<<"<------"<<endl;
	};
	HasPtr(const HasPtr& c):ps(c.ps), i(c.i), use(c.use) {
		(*use)++;

		cout << "====HasPtr copy  construct===="<<endl;
		cout << "----->"<<endl<<"\tps:" << ps <<endl<<"\ti:" << i <<endl<< "\tuse:"<<*use<<endl<<"<------"<<endl;
	}
	HasPtr& operator=(const HasPtr& c)
	{
		(*(c.use))++;
		(*use)--;
		if(*use == 0)
		{
			delete ps;
			delete use;
		}
		ps = c.ps;
		i = c.i;
		use = c.use;
		cout << "====HasPtr copy assigment operator====:"<<endl;
		cout << "----->"<<endl<<"\tps:" << ps <<endl<<"\ti:" << i <<endl<< "\tuse:"<<*use<<endl<<"<------"<<endl;
		return *this;
	}
	~HasPtr(){
		
		cout << "====HasPtr destroy===="<<endl;
		(*use)--;
		if(*use == 0){
			delete ps;
			delete use;
		}
		cout << "----->"<<endl<<"\tps:" << ps <<endl<<"\ti:" << i <<endl<< "\tuse:"<<*use<<endl<<"<------"<<endl;
	}

private:
	string* ps;
	int i;
	size_t* use;
};

int main(int argc, char *argv[])
{
	HasPtr h1("aaaaaaa");
	HasPtr h2;
	h2 = h1;	
	return 0;
}
