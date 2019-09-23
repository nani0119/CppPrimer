#include "BlobPtr.h"
#include "Blob.h"
#include <string>
#include <initializer_list>
#include <list>
using namespace std;

template <typename T>
using BlobType =  Blob<T>;
int main(int argc, char *argv[])
{
	Blob <string> bs;
	Blob<string> bs1 = {"a", "b", "c"};
	Blob<string> bs2 = {"a", "b", "c"};
	bs = bs1;
	cout << "bs size:" << bs.size() << endl;
	cout << "bs:" << endl;
	for(auto i =0; i < bs.size(); i++)
		cout << bs[i] << " ";

	cout << endl;

	cout << "bs1 == bs2:" << (bs1==bs2? "true":"false") << endl;


	BlobPtr<string> bp(bs1);
	cout << *bp <<endl;        //a
	++bp;
	cout << *bp <<endl;        //b
	--bp;
	cout << *bp<<endl;         //a
	bp++;
	cout << *bp << endl;       //b
	cout << *(bp++) << endl;      //b
	cout << *(bp--) << endl;  // c
	cout << *bp << endl;   //b

	typedef Blob<string> StrBlob;
	StrBlob b = {"aa","bb"};
	cout << b[1] << endl;


	BlobType<int>  bi = {1,2,3,4};
	cout << bi[0] << endl;


	vector<string> vs = {"abcdefdh","aa"};
	Blob<string> bls(vs.begin(), vs.end());
	cout << bls[0] << endl;
	return 0;
}
