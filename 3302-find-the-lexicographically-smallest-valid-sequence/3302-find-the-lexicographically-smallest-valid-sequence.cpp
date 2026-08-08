class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if (m > n) return {};

        vector<int> pre(m, -1), suf(m, -1), sufOne(m, -1);
        int p = 0;
        for (int j = 0; j < m; j++) {
            while (p < n && word1[p] != word2[j])
                p++;

            if (p == n) break;

            pre[j] = p++; }
        p = n - 1;
        for (int j = m - 1; j >= 0; j--) {
            while (p >= 0 && word1[p] != word2[j])
                p--;

            if (p < 0) break;

            suf[j] = p--;
        }
        p = n - 1;

        for (int j = m - 1; j >= 0; j--) {
            while (p >= 0) {

                if (word1[p] == word2[j]) {
                    sufOne[j] = p--;
                    break;
                }

                if (j == 0 || (pre[j - 1] != -1 && pre[j - 1] < p)) {
                    sufOne[j] = p--;
                    break;
                }

                p--;
            }
        }

        vector<int> ans;

        p = 0;
        bool usedMismatch = false;

        for (int j = 0; j < m; j++) {

            while (p < n) {

          
                if (word1[p] == word2[j]) {

                    if (j == m - 1 || 
                        (sufOne[j + 1] != -1 && p < sufOne[j + 1])) {

                        ans.push_back(p);
                        p++;
                        break;
                    }
                }

                else if (!usedMismatch) {

                    if (j == m - 1 || 
                        (suf[j + 1] != -1 && p < suf[j + 1])) {

                        ans.push_back(p);
                        p++;
                        usedMismatch = true;
                        break;
                    }
                }

                p++;
            }

            if (ans.size() != j + 1)
                return {};
        }

        return ans;
    }
};