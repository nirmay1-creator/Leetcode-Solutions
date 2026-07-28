class Solution {
public:
    bool isPal(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string,int> mp;

        for(int i = 0; i < words.size(); i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }

        for(int i = 0; i < words.size(); i++) {

            string word = words[i];

            for(int j = 0; j <= word.size(); j++) {

                string left = word.substr(0,j);
                string right = word.substr(j);


                if(isPal(left) && mp.count(right) && mp[right] != i) {
                    ans.push_back({mp[right], i});
                }


                if(j != word.size() && isPal(right) && mp.count(left) && mp[left] != i) {
                    ans.push_back({i, mp[left]});
                }
            }
        }

        return ans;
    }
};