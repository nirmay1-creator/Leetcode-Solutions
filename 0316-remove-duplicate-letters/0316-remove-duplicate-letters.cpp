class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> last(26);

        // Store last occurrence
        for(int i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        string ans = "";

        for(int i = 0; i < s.length(); i++) {

            char ch = s[i];

            // Already included
            if(visited[ch - 'a'])
                continue;

            // Remove bigger characters if they appear later
            while(!ans.empty() && 
                  ans.back() > ch && 
                  last[ans.back() - 'a'] > i) {

                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return ans;
    }
};