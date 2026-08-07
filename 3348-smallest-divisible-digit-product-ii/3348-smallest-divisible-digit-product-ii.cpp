#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool canForm(int c2, int c3, int c5, int c7, int targetLen, string &res) {
        int count7 = c7;
        int count5 = c5;
        int count9 = c3 / 2;
        int rem3 = c3 % 2;
        int count8 = c2 / 3;
        int rem2 = c2 % 3;

        int rem23_len = 0;
        if (rem2 == 2 && rem3 == 1) rem23_len = 2;
        else if (rem2 == 1 && rem3 == 1) rem23_len = 1;
        else if (rem2 == 2 && rem3 == 0) rem23_len = 1;
        else if (rem2 == 1 && rem3 == 0) rem23_len = 1;
        else if (rem2 == 0 && rem3 == 1) rem23_len = 1;

        int minLen = count7 + count5 + count9 + count8 + rem23_len;
        if (minLen > targetLen) return false;

        res = "";
        int ones = targetLen - minLen;
        res.append(ones, '1');

        for (int d = 2; d <= 9; ++d) {
            while (true) {
                int nc2 = c2, nc3 = c3, nc5 = c5, nc7 = c7;
                int temp = d;
                while (temp > 1 && temp % 2 == 0) { nc2 = max(0, nc2 - 1); temp /= 2; }
                while (temp > 1 && temp % 3 == 0) { nc3 = max(0, nc3 - 1); temp /= 3; }
                if (temp == 5) nc5 = max(0, nc5 - 1);
                if (temp == 7) nc7 = max(0, nc7 - 1);

                int n7 = nc7, n5 = nc5, n9 = nc3 / 2, r3 = nc3 % 2, n8 = nc2 / 3, r2 = nc2 % 3;
                int r_len = 0;
                if (r2 == 2 && r3 == 1) r_len = 2;
                else if (r2 > 0 || r3 > 0) r_len = 1;

                int req = n7 + n5 + n9 + n8 + r_len;
                int remSpots = targetLen - (int)res.length() - 1;

                if (req <= remSpots) {
                    res += (char)('0' + d);
                    c2 = nc2; c3 = nc3; c5 = nc5; c7 = nc7;
                } else {
                    break;
                }
            }
        }
        return true;
    }

    void consumeDigit(char d, int &c2, int &c3, int &c5, int &c7) {
        int val = d - '0';
        while (val > 1 && val % 2 == 0) { c2 = max(0, c2 - 1); val /= 2; }
        while (val > 1 && val % 3 == 0) { c3 = max(0, c3 - 1); val /= 3; }
        if (val == 5) c5 = max(0, c5 - 1);
        if (val == 7) c7 = max(0, c7 - 1);
    }

public:
    string smallestNumber(string num, long long t) {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        long long temp = t;

        while (temp % 2 == 0) { c2++; temp /= 2; }
        while (temp % 3 == 0) { c3++; temp /= 3; }
        while (temp % 5 == 0) { c5++; temp /= 5; }
        while (temp % 7 == 0) { c7++; temp /= 7; }

        if (temp > 1) return "-1";

        int n = num.length();
        vector<int> req2(n + 1, c2), req3(n + 1, c3), req5(n + 1, c5), req7(n + 1, c7);

        int zero_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                zero_idx = i;
                break;
            }
            int d2 = req2[i], d3 = req3[i], d5 = req5[i], d7 = req7[i];
            consumeDigit(num[i], d2, d3, d5, d7);
            req2[i + 1] = d2; req3[i + 1] = d3; req5[i + 1] = d5; req7[i + 1] = d7;
        }

        if (zero_idx == -1 && req2[n] == 0 && req3[n] == 0 && req5[n] == 0 && req7[n] == 0) {
            return num;
        }

        int limit = (zero_idx == -1) ? n - 1 : zero_idx;

        for (int i = limit; i >= 0; --i) {
            int start_d = num[i] - '0' + 1;
            for (int d = start_d; d <= 9; ++d) {
                int r2 = req2[i], r3 = req3[i], r5 = req5[i], r7 = req7[i];
                consumeDigit(d + '0', r2, r3, r5, r7);

                int rem_len = n - 1 - i;
                string suffix;
                if (canForm(r2, r3, r5, r7, rem_len, suffix)) {
                    return num.substr(0, i) + (char)('0' + d) + suffix;
                }
            }
        }

        int targetLen = n + 1;
        while (true) {
            string suffix;
            if (canForm(c2, c3, c5, c7, targetLen, suffix)) return suffix;
            targetLen++;
        }
    }
};