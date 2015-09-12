#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int last = 0;
        int cur = getNextTop(height, last);
        while(cur != last) {
            if(!BOTTOM) {
                BOTTOM = true;
                res += getTrapInMiddle(h, last, cur);
            }
            last = cur;
            cur = getNextTop(height, last);
        }
        return res;
    }
private:
    bool BOTTOM = false;
    int getNextTop(vector<int> &h, int start) {
        int m = start;
        int bottom = start;
        while(h[m+1] < h[m] && m+1 < h.size()) 
            m++;
        bottom = m;
        while(h[m+1] > h[m] && m+1 < h.size())
            m++;
        if(m == bottom) {
            BOTTOM = true;
        }
        return m;
    } 
    int getTrapInMiddle(vector<int> &h, int start, int end){
        int res = 0;
        if(end - start <= 1)    return 0;
        int topLevel = h[start] > h[end] ? h[end]:h[start];
        for(int i = start+1; i < end; i++) {
            res += (topLevel - h[i]);
        }
        return res;
    }
};

int main() {
    int t[] = { 0, 1, 0, 2, 1, 0, 1, 2, 1, 0, 1 };
	vector<int> r(t, t + sizeof(t) / sizeof(int));
	Solution s;
	int res = s.trap(r);
	cout << res << end;
	return 0;
}