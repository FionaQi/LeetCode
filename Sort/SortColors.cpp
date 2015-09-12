#include <iostream> 
#include <vector>
using namespace std;

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

	vector<int> num;
	num.push_back(1);
	num.push_back(0);
	sortColors(num);
	int t;
	}