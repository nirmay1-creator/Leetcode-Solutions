class Solution {
public:
    vector<string> ans;

    void dfs(string num, int target, int index, long long value, 
             long long prev, string expr) {

        if(index == num.size()) {
            if(value == target)
                ans.push_back(expr);
            return;
        }

        for(int i = index; i < num.size(); i++) {

            // Leading zero case
            if(i > index && num[index] == '0')
                break;

            string part = num.substr(index, i - index + 1);
            long long curr = stoll(part);

            // First number
            if(index == 0) {
                dfs(num, target, i + 1, curr, curr, part);
            }
            else {
                // Addition
                dfs(num, target, i + 1,
                    value + curr,
                    curr,
                    expr + "+" + part);

                // Subtraction
                dfs(num, target, i + 1,
                    value - curr,
                    -curr,
                    expr + "-" + part);

                // Multiplication
                dfs(num, target, i + 1,
                    value - prev + prev * curr,
                    prev * curr,
                    expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        dfs(num, target, 0, 0, 0, "");
        return ans;
    }
};