#include<iostream>
using namespace std;

//判断数组越界，INT_MIN 比 INT_MAX 多一个，不能把负号合并，目前只能这样单独指出
int reverse(int x) {
	int res = 0;
	while (x) {
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && x % 10 > INT_MAX % 10) || res < INT_MIN / 10 || (res == INT_MIN / 10 && x % 10 < INT_MIN % 10))
			return 0;
		res = res * 10 + x % 10;
		x = x / 10;
	}
	return res;
}

void main()
{
	
}