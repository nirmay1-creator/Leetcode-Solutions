class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        if (n1 == 0) return 0;

        int len2 = s2.length();
        int index = 0;
        int count = 0;

        Map<Integer, int[]> map = new HashMap<>();

        int[] repeatCount = new int[n1 + 1];
        int[] nextIndex = new int[n1 + 1];

        for (int k = 1; k <= n1; k++) {
            for (int i = 0; i < s1.length(); i++) {
                if (s1.charAt(i) == s2.charAt(index)) {
                    index++;
                    if (index == len2) {
                        index = 0;
                        count++;
                    }
                }
            }

            repeatCount[k] = count;
            nextIndex[k] = index;

            if (map.containsKey(index)) {
                int[] prev = map.get(index);
                int start = prev[0];
                int prevCount = prev[1];

                int prefixCount = repeatCount[start];

                int patternLength = k - start;
                int patternCount = count - prevCount;

                int remaining = n1 - start;

                int total = prefixCount;
                total += (remaining / patternLength) * patternCount;

                int rest = remaining % patternLength;
                total += repeatCount[start + rest] - repeatCount[start];

                return total / n2;
            } else {
                map.put(index, new int[]{k, count});
            }
        }

        return repeatCount[n1] / n2;
    }
}