#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string>& dict) {
        if(start == end)    return 2;
        if(dict.size() <= 0)    return 0;
		int len = start.size();
        queue<string> que;
        unordered_set<string> visited;
        int res = 1;
        que.push(start);
        que.push("");
        while(!que.empty()) {
            string cur = que.front();
            que.pop();
            if(cur == "") {
                if(que.empty()) {
                    return 0;
                } else {
                    res++;
                    que.push("");
                    continue;
                }
            }
            for(int i = 0; i < len; i++) {
                char temp = cur[i];
                for(char c= 'a'; c <= 'z'; c++) {
                    if(c == temp)   continue;
                    cur[i] = c;
                    if(cur == end)  return res+1;
                    if(dict.find(cur) != dict.end()) {
                        if(visited.find(cur) == visited.end()) {
                            que.push(cur);
                            visited.insert(cur);
                        }
                    }
                }
                cur[i] = temp;
            }
        }
    }
};

int main() {
   // int t[] = { 5, 2, 1, 2, 1, 5 };
	
	//vector<string> r(t, t + sizeof(t) / sizeof(int));
	string a[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
	unordered_set<string> dict(a, a + 95 );
	//dict.insert("hot");
	//dict.insert("dog");
	//dict.insert("dot");
	Solution s;
	int res = s.ladderLength("qa", "sq", dict);
	cout << res << endl;
	return 0;
}


