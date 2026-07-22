class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for(int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];

            if(mp1.count(a)) {
                if(mp1[a] != b)
                    return false;
            } else {
                mp1[a] = b;
            }
            if(mp2.count(b)) {
                if(mp2[b] != a)
                    return false;
            } else {
                mp2[b] = a;
            }
        }

        return true;
    }
};