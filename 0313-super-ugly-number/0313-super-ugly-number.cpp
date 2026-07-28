class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<long long> ugly(n);
        vector<int> idx(m, 0);
        vector<long long> next(m);

        ugly[0] = 1;
        for (int i = 0; i < m; i++)
            next[i] = primes[i];

        for (int i = 1; i < n; i++) {
            long long mn = *min_element(next.begin(), next.end());
            ugly[i] = mn;

            for (int j = 0; j < m; j++) {
                if (next[j] == mn) {
                    idx[j]++;
                    next[j] = ugly[idx[j]] * 1LL * primes[j];
                }
            }
        }

        return ugly[n - 1];
    }
};