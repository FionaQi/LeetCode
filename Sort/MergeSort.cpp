#include <iostream>
using namespace std;
void merge(int a[], int temp[], const int l, const int r, const int end) {  //合并两个已排序好的序列
	int i = l;
	int left = l;
	int right = r;
	while(left<r && right <= end) {
		while(a[left] <= a[right] && left < r) {
			temp[i++] = a[left++];
		}
		while(a[left]>a[right] && right <= end) {
			temp[i++] = a[right++];
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
}

void MergeSortIter(int a[], int temp[], int start, int end) {
	if(start==end) {
		temp[start] = a[start];
		return;
	}
	else if(start<end) {
		int len = (end - start)/2;
		MergeSortIter(a, temp, start, start+len);
		MergeSortIter(a, temp, start+len+1, end);
		merge(a, temp, start, start+len+1, end);
	}
}
void MergeSort(int a[], int n) {
	if(n<=1)	return;
	int * temp = new int[n];
	MergeSortIter(a, temp, 0, n-1);
	//swap(a, temp);

}



void main()
{
	int a[] = {7,3,2,1,5,6};
	int *b = new int[6];
	MergeSort(a, 6);
	for(auto i = 0; i<6; ++i ) 
	{
		cout<<" "<<b[i];
	}
	int t;
}