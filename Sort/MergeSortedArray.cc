#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(n <= 0)  return;
    if(m <= 0)  nums1 = nums2;
    
    vector<int> nums1copy(nums1);
    nums1copy[m] = INT_MAX;
    nums2.push_back(INT_MAX);
    
    int p = 0, q = 0;
    for(int i = 0; i < m+n; i++) {
        if(nums1copy[p] < nums2[q]) {
            nums1[i] = nums1copy[p++];
        } else {
            nums1[i] = nums2[q++];
        }
    }
}

void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (n <= 0)	return;
	if (m <= 0) {
		nums1 = nums2;
		return;
	}
	int p1 = m - 1;
	int p2 = n - 1;
	int z = m + n - 1;
	while (p1 >= 0 && p2 >= 0) {
		if (nums2[p2] > nums1[p1]) {
			nums1[z--] = nums2[p2--];
		}
		else {
			nums1[z--] = nums1[p1--];
		}
	}
	while (p2 >= 0) {
		nums1[z--] = nums2[p2--];
	}
}

int main() {
    int n1[] = {0,0,3,0,0,0,0,0,0};
    int n2[] = {-1,1,1,1,2,3};
    vector<int> num1(n1, n1+9);
    vector<int> num2(n2, n2+6);
    merge(num1, 3, num2, 6);
    
    for(int i = 0; i < num1.size(); i++) {
        cout<< num1[i] << " ";
    }
    return 0;
}