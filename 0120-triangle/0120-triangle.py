class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        # Start from the second-to-last row and move up to the top row
        for row in range(len(triangle) - 2, -1, -1):
            for col in range(len(triangle[row])):
                # Add the minimum of the two adjacent values from the row below
                triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1])
                
        # The top element now holds the minimum path sum
        return triangle[0][0]