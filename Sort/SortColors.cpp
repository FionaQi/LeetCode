#include <iostream> 
#include <vector>
using namespace std;

// o(n), with 2 ptr
void sortColors2(vector<int> &nums) { 
	int first = -1;
	int second = nums.size();
	if (second == 0)
		return;
	int cur = 0;
	while (cur < second) {
		if (nums[cur] < 1) {
			first++;
			swap(nums[first], nums[cur]);
			cur++;
		}
		else if(nums[cur] > 1) {
			second--;
			swap(nums[second], nums[cur]);
		}
		else {
			cur++;
		}

	}
}

// Quick sort
void partition(vector<int> &nums, int pivot) {
        int left = 0; 
        int right = nums.size()-1;
        while( left < right ){
            while( nums[left] <= pivot && left < right )
                ++left;
            while( nums[right] > pivot && left < right )
                --right;
            swap( nums[left], nums[right] );
        }
    }

void swap(int &x, int &y){
        int temp = x;
        x = y;
        y = temp;
    }

void sortColors(vector<int> &nums) {
        if( nums.size() <= 1 )
            return;
        partition(nums, 0);
        partition(nums, 1);
    }

void main(){
	int a[] = {1, 0, 1,2,0,1,1};
	vector<int> num(a, a+ 7);
	sortColors2(num);
	int t;
	}