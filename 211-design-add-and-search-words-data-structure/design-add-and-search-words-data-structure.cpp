class WordDictionary {
    struct Node {
        Node* links[26];
        bool isEnd;

        Node() {
            isEnd = false;

            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
        }
    };

    Node* root;

    bool dfs(string &word, int index, Node* node) {

        if (index == word.size()) {
            return node->isEnd;
        }

        char ch = word[index];

        // Wildcard character
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {

                if (node->links[i] != nullptr) {
                    if (dfs(word, index + 1, node->links[i])) {
                        return true;
                    }
                }
            }

            return false;
        }

        // Normal character
        int pos = ch - 'a';

        if (node->links[pos] == nullptr) {
            return false;
        }

        return dfs(word, index + 1, node->links[pos]);
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->links[index] == nullptr) {
                node->links[index] = new Node();
            }

            node = node->links[index];
        }

        node->isEnd = true;
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