#include<iostream>
using namespace std;

//�ж�����Խ�磬INT_MIN �� INT_MAX ��һ�������ܰѸ��źϲ���Ŀǰֻ����������ָ��
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