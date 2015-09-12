#include <iostream>
using namespace std;
int merge(int a[], int temp[], const int l, const int r, const int end) {  //合并两个已排序好的序列
	int i = l;
	int left = l;
	int right = r;
	int cnt = 0;
	while(left<r && right <= end) {
		while(a[left] <= a[right] && left < r) {
			temp[i++] = a[left++];
		}
		while(a[left]>a[right] && right <= end) {
			temp[i++] = a[right++];
			cnt += r - left;
		}
	}
	if( right > end ) {
		while( i <= end )		
			temp[i++] = a[left++];
	}
	else if( left >= r ) {
		while( i <= end )	temp[i++] = a[right++];
	}
	//***************************
	for(int j = l; j <= end; ++j )
	{
		a[j] = temp[j];
	}
	return cnt;
}

int MergeSortIter(int a[], int temp[], int start, int end) {
	if(start==end) {
		temp[start] = a[start];
		return 0;
	}
	else if(start<end) {
		int len = (end - start)/2;
		int left = MergeSortIter(a, temp, start, start+len);
		int right = MergeSortIter(a, temp, start+len+1, end);
		int cur = merge(a, temp, start, start+len+1, end);
		return left+right+cur;
	}
}
int InversePairs(int a[], int n) {
	int res = 0;
	if(n<=1)	return res;
	int * temp = new int[n];
	return MergeSortIter(a, temp, 0, n-1);
	//swap(a, temp);

}



void main()
{
	int a[] = {7,5,6,4};
	int *b = new int[4];
	int t = InversePairs(a, 4);

	for(auto i = 0; i<6; ++i ) 
	{
		cout<<" "<<b[i];
	}
	int to;
}