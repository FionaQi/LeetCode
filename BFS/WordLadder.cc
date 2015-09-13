#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string>& dict) {
        if(start == end)    return 1;
        //if(dict.size() <= 0)    return 0;
		this->shortestLen = 1;
        lastLevel.push(start);
		return bfs(end, dict);
    }
private:
	queue<string> curLevel;
	queue<string> lastLevel;
	unordered_set<string> visited;
	int shortestLen;
	int bfs(string end, unordered_set<string>& dict){
		while (!lastLevel.empty()) {
			string cur = lastLevel.front();
			lastLevel.pop();
			int len = end.size();
			for (int k = 0; k < len; k++) {
				const char temp = cur[k];
				for (char c = 'a'; c <= 'z'; c++) {
					if (c == temp)   continue;   //check
					cur[k] = c; 
					if (cur == end)  return this->shortestLen + 1;
					if (dict.find(cur) != dict.end()) {
						if (visited.find(cur) == visited.end()) {
							curLevel.push(cur);
							visited.insert(cur);
						}
					}
				}
				cur[k] = temp;
			}
			if (lastLevel.empty()) {     //两个条件相反
				swap(lastLevel, curLevel);
				this->shortestLen++;
			}
		}
		return 0;
	}
};

int main() {
//	string a[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
//	unordered_set<string> dict(a, a + 95 );
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dog");
	dict.insert("dot");
	Solution s;
	int res = s.ladderLength("hot", "dog", dict);
	//int res = s.ladderLength("qa", "sq", dict);
	cout << res << endl;
	return 0;
}


