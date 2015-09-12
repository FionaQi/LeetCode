#include <iostream>
using namespace std;
int searchInsert(int A[], int n, int target) {
        int left = 0;
        int right = n-1;
        if( target < A[left] )
            return 0;
        else if( target > A[right] )
            return n;
        while( left <= right ){
            const int mid = ( left + right ) / 2;
            if( A[mid] == target )      
                return mid;
            if( target >= A[left] && target <= A[mid] ){
                right = mid - 1;
            }
            else if( target > A[mid] && target <= A[right] ){
                left = mid + 1;
            }
            else if( target < A[left] )
                return left;
            else if( target > A[right] )
                return right + 1;
        }
    }

int main()
{
	int A[] = {1, 3};
	int t = searchInsert(A, 2, 2);
	return 0;
}