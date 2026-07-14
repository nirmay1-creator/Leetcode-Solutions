from collections import Counter

class Solution(object):
    def minWindow(self, s, t):
        if not s or not t:
            return ""

        need = Counter(t)
        missing = len(t)
        left = start = end = 0

        for right in range(len(s)):
            if need[s[right]] > 0:
                missing -= 1
            need[s[right]] -= 1

            while missing == 0:
                if end == 0 or right - left + 1 < end - start:
                    start = left
                    end = right + 1

                need[s[left]] += 1
                if need[s[left]] > 0:
                    missing += 1
                left += 1

        return s[start:end]