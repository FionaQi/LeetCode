#include <iostream>
#include <vector>
#include<unordered_map>
#include <algorithm>
using namespace std;

int x[501], y[501];
double a[501];
vector<int> v;

struct Point2D{
	int x;
	int y;
	Point2D(int a, int b):x(a), y(b) {}
};

int colinear(vector < Point2D> &A)
{
	int n = A.size();
	int Max = 0;
	int sum = 0;

	for (int i = 0; i < n-2; i++)
	{
		//double *a = new double[501];
		double a[501];
		int t = 0;
		for (int j = i+1 ; j < n; j++)
		{
			if (A[i].x == A[j].x)
				a[++t] = 9999999;
			else
				a[++t] = ((double)A[j].y - A[i].y) / (A[j].x - A[i].x);
		}
		sort(&a[1], &a[t + 1]);
		int now = 1;
		for (int j = 2; j <= t; j++)
		{
			if (a[j] == a[j - 1])
				now++;
			else
			{
				if (now >= 2){
					v.push_back(now);
				}
				now = 1;
			}
		}
		v.push_back(now);
		for (int i = 0; i < v.size(); i++){
			sum += v[i] * (v[i] - 1) / 2;
		}
		v.clear();
		//delete a;
	}
	return sum;
}

void main()
{
	vector<Point2D> A;
	A.push_back(Point2D(0,0));
	A.push_back(Point2D(1,1));
	A.push_back(Point2D(2,2));
	A.push_back(Point2D(3,3));
	A.push_back(Point2D(3,2));
	A.push_back(Point2D(4,2));
	A.push_back(Point2D(5,1));
	cout<< colinear(A) <<endl;
	system("pause");
}