class Solution {
    int[] pref, suff, best, len;
    char[] first, last;

    public int[] longestRepeating(String s, String queryCharacters, int[] queryIndices) {
        int n = s.length();

        pref = new int[4 * n];
        suff = new int[4 * n];
        best = new int[4 * n];
        len = new int[4 * n];
        first = new char[4 * n];
        last = new char[4 * n];

        build(1, 0, n - 1, s.toCharArray());

        int[] ans = new int[queryIndices.length];

        for (int i = 0; i < queryIndices.length; i++) {
            update(1, 0, n - 1,
                   queryIndices[i],
                   queryCharacters.charAt(i));

            ans[i] = best[1];
        }

        return ans;
    }

    void build(int node, int l, int r, char[] s) {
        if (l == r) {
            pref[node] = suff[node] = best[node] = len[node] = 1;
            first[node] = last[node] = s[l];
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        merge(node, node * 2, node * 2 + 1);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            pref[node] = suff[node] = best[node] = len[node] = 1;
            first[node] = last[node] = c;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        merge(node, node * 2, node * 2 + 1);
    }

    void merge(int node, int a, int b) {
        len[node] = len[a] + len[b];

        first[node] = first[a];
        last[node] = last[b];

        pref[node] = pref[a];
        suff[node] = suff[b];

        best[node] = Math.max(best[a], best[b]);

        if (last[a] == first[b]) {
            best[node] = Math.max(best[node], suff[a] + pref[b]);

            if (pref[a] == len[a])
                pref[node] = len[a] + pref[b];

            if (suff[b] == len[b])
                suff[node] = len[b] + suff[a];
        }
    }
}