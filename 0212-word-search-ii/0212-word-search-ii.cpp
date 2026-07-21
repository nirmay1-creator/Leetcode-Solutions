class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string &word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->child[idx])
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->word = word;
    }


    vector<string> ans;
    int m, n;

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {

        if (i < 0 || j < 0 || i >= m || j >= n)
            return;

        char c = board[i][j];

        if (c == '#')
            return;

        if (!node->child[c - 'a'])
            return;


        node = node->child[c - 'a'];


        // Word found
        if (node->word != "") {
            ans.push_back(node->word);
            node->word = "";   // avoid duplicate
        }


        board[i][j] = '#';


        dfs(board, i+1, j, node);
        dfs(board, i-1, j, node);
        dfs(board, i, j+1, node);
        dfs(board, i, j-1, node);


        board[i][j] = c;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        for (string &word : words)
            insert(word);


        m = board.size();
        n = board[0].size();


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }


        return ans;
    }
};