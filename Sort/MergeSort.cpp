#include <iostream>
#include <vector>
using namespace std;
void MergeSort(int a[], int start, int end);
void merge(int a[], const int start, const int mid, const int end);

void MergeSort(int a[], int n) {
	if (n <= 1)	return;
	MergeSort(a, 0, n - 1);
}

void MergeSort(int a[], int start, int end) {
	if (start == end) {
		return;
	}
	else if (start<end) {
		int mid = start + (end - start) / 2;
		MergeSort(a, start, mid);
		MergeSort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}

void merge(int a[], const int start, const int mid, const int end) {  //mid : tail of lhs array
	const int lLen = mid + 1 - start;
	const int rLen = end - mid;
	const vector<int> Left(&a[start], &a[start] + lLen);
	const vector<int> Right(&a[mid + 1], &a[mid + 1] + rLen);

	int i = 0;
	int j = 0;
	int k = start;
	while(i < lLen && j < rLen) {
		while( j < rLen && Left[i] > Right[j] ) {
			a[k++] = Right[j++];
		}
		while ( i <= lLen && Left[i] <= Right[j]) {
			a[k++] = Left[i++];
		}
	}
	
	while( i < lLen )		
		a[k++] = Left[i++];
	
	while( j < rLen ) {
		a[k++] = Right[j++];
	}
}


void main()
{
	int a[] = {7,3,2,1,5,6};
	
	MergeSort(a, 6);
	for(auto i = 0; i<6; ++i ) 
	{
		cout<<" "<<a[i];
	}
	int t;
}