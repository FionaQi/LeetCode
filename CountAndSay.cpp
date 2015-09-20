#include <iostream>
using namespace std;

struct SingleCount{
	char val;
	int count;
	SingleCount(char x) : val(x), count(1) {}
};

string countAndSay(int n) {
	if ( n == 1 )
		return "1";
	string res ;
	string res_last = countAndSay( n-1 );
	SingleCount *node = NULL;
	for( string::iterator it = res_last.begin(); it != res_last.end(); ++it )
	{
		char x = *it  ;
		if( node == NULL ){
			node = new SingleCount(x);
		}
		else{
			if( node->val == x ){
				node->count ++;
			}
			else{
				//输出上一个node到result中
				char num = (char)( node->count + 48 );
				res.push_back(num);
				res.push_back( node->val );
				delete node;
				//新建一个新的node存当前的新字符
				node = new SingleCount(x);
			}
		}
	}
	if( node != NULL ){
		char num = (char)( node->count + 48 );
		res.push_back(num);
		res.push_back( node->val );
	}
	return res;
}

void main()
{
	string p = countAndSay(5);
	p = countAndSay(3);
}