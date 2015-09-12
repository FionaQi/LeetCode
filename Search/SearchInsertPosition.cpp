#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;   //notice
		if (end < 0)
			return -1;
       
        while( start <= end ){     //note for "=", while terminate condition
            const int mid = start + ( end - start ) >> 1;
            if( nums[mid] == target )      
                return mid;
			else if( nums[mid] > target ){
                end = mid - 1;
            }
            else if( nums[mid] < target){
                start = mid + 1;
            }
        }
		return start;             // both returns start
    }

int main()
{
	int A[] = {1, 3};
	vector<int> a(A, A + 2);
	int t = searchInsert(a, 2);
	return 0;
}