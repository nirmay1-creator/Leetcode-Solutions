#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool end;

    TrieNode() {
        end = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class WordDictionary {
    TrieNode* root;

    bool dfs(const string& word, int idx, TrieNode* node) {
        if (!node) return false;

        if (idx == word.size())
            return node->end;

        char c = word[idx];

        if (c == '.') {
            // Try all possible children
            for (int i = 0; i < 26; i++) {
                if (node->child[i] && dfs(word, idx + 1, node->child[i]))
                    return true;
            }
            return false;
        } else {
            return dfs(word, idx + 1, node->child[c - 'a']);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!cur->child[idx])
                cur->child[idx] = new TrieNode();

            cur = cur->child[idx];
        }

        cur->end = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */