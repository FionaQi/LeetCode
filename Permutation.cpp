#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> temp;

void recursion(vector<int>& nums, int start, int end)
{
	if( start == end )
	{
		temp.push_back(nums[start]);
		res.push_back(temp);
		temp.erase(temp.end()-1);
		return;
	}
	for(int i = start; i < end; ++i )
	{
		temp.push_back(nums[start]);
		recursion(nums, start+1, end);
		temp.erase(temp.end()-1);
	}
}
vector<vector<int>> permute(vector<int>& nums) {
    recursion(nums, 0, nums.size()-1);
	return res;
}
void main()
{
	int a[] = {1,2,3};
	vector<int> m;
	for( int i = 0; i < 3; ++i )
	{
		m.push_back(a[i]);
	}
	permute(m);
}