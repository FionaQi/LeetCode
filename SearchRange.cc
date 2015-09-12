#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		res.push_back(-1);
		res.push_back(-1);
		if (nums.size() <= 0)  return res;
		res.clear();
		res.push_back(getRangeLeft(nums, target));
		res.push_back(getRangeRight(nums, target));
		return res;
	}
private:
	int getRangeLeft(vector<int>& A, int target) {
		int left = 0, right = A.size() - 1;
		int mid = (left + right) / 2;
		while (left <= right) {
			if (A[mid] < target) {
				left = mid + 1;
				mid = (left + right) / 2;
			}
			if (A[mid] > target) {
				right = mid - 1;
				mid = (left + right) / 2;
			}
			if (A[mid] == target) {
				if (mid == 0 || (A[mid - 1] < target && mid > 0) ) {
					return mid;
				}
				else {
					mid = mid - 1;
				}
			}
		}
		return -1;
	}
	int getRangeRight(vector<int>& A, int target) {
		int n = A.size();
		int left = 0, right = n - 1;
		int mid = (left + right) / 2;
		while (left <= right) {
			if (A[mid] < target) {
				left = mid + 1;
				mid = (left + right) / 2;
			}
			if (A[mid] > target) {
				right = mid - 1;
				mid = (left + right) / 2;
			}
			if (A[mid] == target) {
				if (mid == (n - 1) || (A[mid + 1] > target && mid < (n - 1)) ) {
					return mid;
				}
				else {
					mid = mid + 1;
				}
			}	
		}
		return -1;
	}
};

int main()
{
	int t[] = { 1, 4 };
	vector<int> r(t, t + sizeof(t) / sizeof(int));
	Solution s;
	vector<int> res = s.searchRange(r, 4);
	return 0;
}

