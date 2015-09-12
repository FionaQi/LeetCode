#include <iostream>
#include <vector>
#include<unordered_map>
#include <algorithm>
using namespace std;
struct Point3D {
 int x;
 int y;
 int z;
};
//int solution(vector<Point3D> &A) {
//    // write your code in C++11
//    unordered_map<long long, int> mymap;
//	for(int i = 0; i < A.size(); ++i )
//	{
//		long long temp = A[i].x *A[i].x + A[i].y *A[i].y +A[i].z *A[i].z; 
//		if( mymap.find(temp) == mymap.end() ){
//			std::pair<long long, int> radius(temp, 1);
//			mymap.insert(radius);
//		}
//	}
//	int res = mymap.size();
//}
//
//int solution(vector<int> &A){
//		if( A.size() == 0 ){
//			return 0;
//		}
//		if( A.size() == 1 ){
//			return A[0];
//		}
//		int i = A.size();
//		int sum = 0;
//		while( i>1 ){
//			sort( A.begin(), A.end() );
//			int t = A[0] + A[1];
//			sum = sum + t;
//			A[0] = t;
//			A[1] = INT_MAX;
//			i--;
//		}
//		return sum;
//	}


 //int solution(int N){
	//	if( N==0 ){
	//		return 1;
	//	}
	//	if( N==1 ){
	//		return 2;
	//	}
	//	vector<int> a(N+1, 0);  //[N+1];
	//	a[0] = 1;
	//	a[1] = 2;
	//	int two = 1;
	//	int three = 0;
	//	for( int i=2; i < N+1; i++ ){
	//		if( 2 * a[two] < 3 * a[three] ){
	//			a[i] = 2*a[two];
	//			two++;
	//		}else if( 2 * a[two] > 3 * a[three] ){
	//			a[i] = 3 * a[three];
	//			three++;
	//		}else{
	//			a[i] = 3 * a[three];
	//			two++;
	//			three++;
	//		}
	//	}
	//	return a[N];
	//}

struct Point2D{
	int x;
	int y;
	Point2D(int a, int b):x(a), y(b) {}
};

int x[501], y[501];
double a[501];
vector<int> v;

int colinear(vector < Point2D> &A)
{
	int n = A.size();
	int Max = 0;
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		for (int j = 1; j < n; j++)
		{
			if (i == j)
				continue;
			if (A[i].x == A[j].x)
				a[++t] = 9999999;
			else
				a[++t] = ((double)A[j].y - A[i].y) / (A[j].x - A[i].x);
		}
		sort(&a[1], &a[t + 1]);
		int now = 1;
		for (int j = 2; j <= n; j++)
		{
			if (a[j] == a[j - 1])
				now++;
			else
			{
				if (now >= 3){
					v.push_back(now);
				}
				now = 1;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++){
		sum += v[i] * (v[i] - 1) *(v[i] - 2) / 6;
	}
	return sum;
}

void main()
{
//	int A[] = {100,1000,250,750};
//	solution(A);
//	solution(7);
	vector<Point2D> A;
	A.push_back(Point2D(0,0));
	A.push_back(Point2D(1,1));
	A.push_back(Point2D(2,2));
	A.push_back(Point2D(3,3));
	A.push_back(Point2D(3,2));
	A.push_back(Point2D(4,2));
	A.push_back(Point2D(5,1));
	colinear(A);
}