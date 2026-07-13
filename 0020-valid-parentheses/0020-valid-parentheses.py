class Solution(object):
    def isValid(self, s):
        stack = []
        mapping = {
            ')': '(',
            '}': '{',
            ']': '['
        }

        for ch in s:
            if ch in mapping:
                if not stack or stack.pop() != mapping[ch]:
                    return False
            else:
                stack.append(ch)

        return not stack
        

        for char in s:
            if char in mapping.values():
                stack.append(char)
            else:
                if not stack or stack.pop() != mapping[char]:
                    return False

        return len(stack) == 0