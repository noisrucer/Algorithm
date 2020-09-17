class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string,int>mp;
	vector<vector<string>>res;
	int count = 0;
	for (int i = 0; i < strs.size(); i++) {
		string temp = strs[i];
		sort(strs[i].begin(), strs[i].end());
		if (mp.count(strs[i])) {
			res[mp[strs[i]]].push_back(temp);
		}
		else {
			mp[strs[i]] = count++;
			res.push_back({ temp });
		}
	}
        return res;
    }
};