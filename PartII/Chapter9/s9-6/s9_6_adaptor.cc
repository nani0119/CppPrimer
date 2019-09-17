#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>


using  namespace std;


int main(int argc, char *argv[])
{
	vector<string> vs = {"aa", "bb"};
	stack<int> sti;     // default  deque
	stack<string, vector<string>>  sts(vs);  // Explicitly using vector

	sts.push("cc");
	cout <<"st.top():"<< sts.top() << endl;
	sts.emplace("dd");
	cout << "st.top():" << sts.top() << endl;

	cout << "print elements in stack:" << endl;
	while(!sts.empty())
	{
		cout << sts.top() << " ";
		sts.pop();
	}
	cout << endl;
	cout << "=====================================================" << endl;

	queue<int> que;

	que.push(1);
	que.emplace(2);
	que.push(3);

	cout << "q.front():" << que.front() << endl; // only for queue
	cout << "q.back():" << que.back() << endl;   // only for queue

	cout << "print elements in queue:" << endl;
	while(!que.empty())
	{
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;

	cout << "===================================================" << endl;
	priority_queue<int>  priority_q;

	priority_q.push(1);
	priority_q.push(3);
	priority_q.push(5);
	priority_q.push(0);
	priority_q.push(2);

	cout << "pq.top():" << priority_q.top()<< endl;  // only for priority_queue
	priority_q.pop();
	cout << "pq.top():" << priority_q.top()<< endl;

	priority_q.push(5);
	priority_q.emplace(3);

	cout << "print priority queue element:" << endl;

	while(!priority_q.empty())
	{
		cout << priority_q.top() << "  ";
		priority_q.pop();
	}
	cout << endl;
	return 0;
}
