#include<iostream>
using namespace std;

//牛顿法
int mySqrt2(int x) {
	if (x < 2)   return x;
	double pre = 1;
	double cur = 1;
	do{
		pre = cur;
		cur = pre / 2.0 + double(x) / (2.0 * pre);
	} while (abs(pre - cur) > 0.00001);
	return int(cur);
}
//二分查找
int mySqrt(int x) {
	if (x < 2)   return x;
	int left = 1;
	int right = x / 2;
	int lastmid;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (mid < x / mid) {
			left = mid + 1;
			lastmid = mid;
		}
		else if (mid > x / mid) {
			right = mid - 1;
		}
		else {
			return mid;
		}
	}
	return lastmid;
}
void main()
{

}