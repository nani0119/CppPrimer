#include <stack>
#include <istream>
#include <string>
#include "common.h"
#include <memory>
#include <vector>

using namespace std;

class QueryExpression
{
private:
	stack<string> postfix;
	void deletAllSpace(string& s)
	{
		size_t pos = 0;
		while(1)
		{
			pos = s.find_first_of(" ");
			if (pos == string::npos)
			{
				return;
			}
			s.erase(pos,1);
		}
		cout << "deletAllSpace:" << s << endl;

	}

	int getPriorityLevel(const string& s) const
	{
		int ret = 0;
		switch (s[0]) {
			case '(':
				ret = 5;
				break;
			case '~':
				ret = 4;
				break;
			case '&':
				ret = 3;
				break;
			case '|':
				ret = 2;
				break;
			case ')':
				ret = 1;
				break;
			default:
				ret = 0;
				break;
		}
		return ret;
	}

	bool opAisBiggerThanOpB(const string& opA, const string& opB) const
	{
		return getPriorityLevel(opA) > getPriorityLevel(opB);
	}

	shared_ptr<vector<string>> parseString2Words(string& s) 
	{
		auto words_ptr = make_shared<vector<string>>();
		size_t i = 0;
		size_t old_pos = 0;
		while(i < s.size())
		{
			if(s[i] == '('|| s[i] == '&' 
					|| s[i] == '|' || s[i] == '~'
					|| s[i] == ')')
			{
				string operand(s, old_pos, i - old_pos);
				if(operand.size()){
					words_ptr->push_back(operand);
				}
				string op(1, s[i]);
				words_ptr->push_back(op);
				i++;
				old_pos = i;
			}
			else
			{
				i++;
			}
		}

		string operand(s, old_pos, i - old_pos);
		if(operand.size()){
			words_ptr->push_back(operand);
		}
		return words_ptr;
	}
	bool isOperator(const string& op) const
	{
		set<string> opSet = {"(", ")","|","&","~"};
		return opSet.find(op) != opSet.end();
	}
	void infix2postfix(string& s)
	{

		stack<string> symbol;
		stack<string> temp;
		auto words = parseString2Words(s);
#if DEBUG
		cout << "=========words==============" << endl;
		for(auto it = words->begin(); it != words->end(); it++) {
			cout <<"word:" <<*it << endl;
		}
		cout << "=======================" << endl;
#endif
		for(auto it = words->begin(); it != words->end(); it++) {
			
			if(!isOperator(*it))
			{
				// 如果是操作数直接入操作数栈
				temp.push(*it);
			}
			else
			{
				if(symbol.empty() || *it == "(")
				{
					// '('直接入栈
					symbol.push(*it);
				}
				else if (*it == ")")
				{
					// 弹出所有符号直到遇到'('为止
					while(!symbol.empty()&&symbol.top() != "(")
					{
						temp.push(symbol.top());
						symbol.pop();
					}
					symbol.pop();  // 弹出 '('
				}
				else
				{
					//  当其优先级高于栈顶运算符或者栈顶为'('，直接入栈
					if(opAisBiggerThanOpB(*it, symbol.top()) || symbol.top()=="(")
					{
						symbol.push(*it);
					}
					else
					{
						// 从栈顶开始，依次弹出比当前处理的运算符优先级高和优先级相等的运算符，
						// 直到一个比它优先级低的或者遇到了一个左括号为止
						while(!symbol.empty()&&!opAisBiggerThanOpB(*it, symbol.top()))
						{
							if (symbol.top() == "(")
							{
								symbol.pop();
								break;
							}
							else
							{
								temp.push(symbol.top());
								symbol.pop();
							}
						}
						symbol.push(*it);
					}
				}

			}

		}
		// 弹出所有符号
		while(!symbol.empty())
		{
			temp.push(symbol.top());
			symbol.pop();
		}

		while(!temp.empty())
		{
			postfix.push(temp.top());
			temp.pop();		
		}
#if DEBUG
		cout << "===========stack=============" << endl;
		temp = postfix;
		while(!temp.empty())
		{
			cout << temp.top() << endl;
			temp.pop();
		}
		cout << "=============================" << endl;
#endif
	}
	public:
		QueryExpression(string& s) 
		{
			deletAllSpace(s);
			infix2postfix(s);
		}
		Query calcQueryResult()
		{
			stack<Query> query_stack;
			while(!postfix.empty())
			{
				if (postfix.top() == "~")
				{
					Query q = ~(query_stack.top());
					query_stack.pop();
					query_stack.push(q);
				}
				else if (postfix.top() == "&")
				{
					Query q1 = query_stack.top();
					query_stack.pop();
					Query q2 = query_stack.top();
					query_stack.pop();
					Query ret = q2 & q1;
					query_stack.push(ret);
				}
				else if (postfix.top() == "|")
				{
					Query q1 = query_stack.top();
					query_stack.pop();
					Query q2 = query_stack.top();
					query_stack.pop();
					query_stack.push(q2|q1);
				}
				else
				{
					query_stack.push(Query(postfix.top()));
				}
				postfix.pop();
			}
			// cout << "query stack size:" << query_stack.size() << endl;
			return query_stack.top();
		}
	virtual ~QueryExpression() =default;
};
