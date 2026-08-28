class Solution {
    public String lexPalindromicPermutation(String s, String target) {
        int n = s.length();
        int[] cnt = new int[26];

        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                odd++;
                mid = (char) ('a' + i);
            }
        }

        if (odd > 1) return "";

        int[] halfCnt = new int[26];

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        String targetHalf = target.substring(0, n / 2);
        String half = smallestGE(halfCnt, targetHalf);

        if (half == null) return "";

        String ans = makePalindrome(half, mid, n);

        if (ans.compareTo(target) > 0) {
            return ans;
        }

        half = nextPermutation(half);

        if (half == null) return "";

        return makePalindrome(half, mid, n);
    }

    private String smallestGE(int[] original, String target) {
        int[] cnt = original.clone();
        char[] ans = new char[target.length()];

        for (int i = 0; i < target.length(); i++) {
            int x = target.charAt(i) - 'a';

            if (cnt[x] > 0) {
                ans[i] = target.charAt(i);
                cnt[x]--;
                continue;
            }

            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    ans[i] = (char) ('a' + c);
                    cnt[c]--;
                    fill(ans, i + 1, cnt);
                    return new String(ans);
                }
            }

            for (int j = i - 1; j >= 0; j--) {
                cnt[ans[j] - 'a']++;

                int prev = ans[j] - 'a';

                for (int c = prev + 1; c < 26; c++) {
                    if (cnt[c] > 0) {
                        ans[j] = (char) ('a' + c);
                        cnt[c]--;
                        fill(ans, j + 1, cnt);
                        return new String(ans);
                    }
                }
            }

            return null;
        }

        return new String(ans);
    }

    private void fill(char[] ans, int pos, int[] cnt) {
        for (int c = 0; c < 26; c++) {
            while (cnt[c] > 0) {
                ans[pos++] = (char) ('a' + c);
                cnt[c]--;
            }
        }
    }

    private String makePalindrome(String half, char mid, int n) {
        StringBuilder sb = new StringBuilder();

        sb.append(half);

        if (n % 2 == 1) {
            sb.append(mid);
        }

        sb.append(new StringBuilder(half).reverse());

        return sb.toString();
    }

    private String nextPermutation(String s) {
        char[] a = s.toCharArray();

        int i = a.length - 2;

        while (i >= 0 && a[i] >= a[i + 1]) {
            i--;
        }

        if (i < 0) return null;

        int j = a.length - 1;

        while (a[j] <= a[i]) {
            j--;
        }

        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        reverse(a, i + 1, a.length - 1);

        return new String(a);
    }

    private void reverse(char[] a, int l, int r) {
        while (l < r) {
            char temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            l++;
            r--;
        }
    }
}