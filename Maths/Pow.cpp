#include<iostream>
using namespace std;

double myPow(double x, int n) {
	if (n == 0)  return 1;

	if (n < 0) {
		if (n == INT_MIN) {
			return 1.0 / (myPow(x, 1 - n) * x);
		}
		else {
			return 1.0 / myPow(x, -n);
		}
	}

	double temp = myPow(x, n / 2);
	if (n & 1) {
		return temp * temp * x;
	}
	else {
		return temp * temp;
	}
	//return myPow(x, n/2) * myPow(x, n - (int)n/2);  //没利用资源 重复递归了很多值
}

void main()
{
	
}