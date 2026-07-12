class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # Clean the string: keep only alphanumeric characters and lowercase them
        cleaned_str = "".join(char.lower() for char in s if char.isalnum())
        
        # Check if the cleaned string reads the same forward and backward
        return cleaned_str == cleaned_str[::-1]