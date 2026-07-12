class Solution(object):
    def pathSum(self, root, targetSum):
        res = []

        def dfs(node, target, path):
            if not node:
                return

            path.append(node.val)

            if not node.left and not node.right and node.val == target:
                res.append(path[:])
            else:
                dfs(node.left, target - node.val, path)
                dfs(node.right, target - node.val, path)

            path.pop()

        dfs(root, targetSum, [])
        return res