#include <iostream>
#include <vector>
using namespace std;

long lengthPerBall(int n) {
	long sum = (long)n;
	long cur = (long)n / 2;
	while (cur >= 1) {
		sum += cur * 2;
		cur /= 2;
	}
	return sum;
}

long totalLength(int a, int b, int c, int d) {
	long ra = lengthPerBall(a);
	long rb = lengthPerBall(b);
	long rc = lengthPerBall(c);
	long rd = lengthPerBall(d);
	return  ra + rb + rc + rd;
}




void main()
{
	//int  a = -3;
	//unsigned int b = 2;
	//long c = a + b;
	//printf("%ld\n", c);

	//char p1[] = "hello";
	//void *p2 = malloc(6);
	//printf("%d, %d", sizeof(p1), sizeof(p2));

	//bool first = true;
	//int sum = 0;
	//int value;
	//unsigned short i = 0xFFFF;
	//for (; i >= 0; --i) {
	//	if (first) {
	//		value = 65536;
	//		sum += value % 3;
	//		first = false;
	//	}
	//	else {
	//		sum += --value % 3;
	//		if (value <= 0) {
	//			printf("%d,%d", sum, i);
	//			break;
	//		}
	//	}
	//}
	int t;
	cout << totalLength(2147483646, 2147483646, 2147483646, 2147483646) << endl;
	system("PAUSE");
}