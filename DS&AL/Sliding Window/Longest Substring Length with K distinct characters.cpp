
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
//0 1 2 3 4 5 6 7 8 9
//4 2 2 7 8 1 2 8 1 0

int maxSumArray(string s, int k) {
	unordered_map<char, int>mp;
	int maxWindowSize = INT_MIN;
	int windowStart = 0;
	for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
		mp[s[windowEnd]]++;
		while (mp.size() > k) {
			mp[s[windowStart]]--;
			if (mp[s[windowStart]] == 0) mp.erase(s[windowStart]);
			windowStart++;
			
		}
		if (mp.size() == k) {
			int currentSize= 0;
			for (auto& i : mp) currentSize += i.second;
			maxWindowSize = max(maxWindowSize, currentSize);
		}
	}
	return maxWindowSize;
}
int main()
{
	string s = "AAAHHIBC";
	int k = 3;
	cout<<maxSumArray(s, k);
}
