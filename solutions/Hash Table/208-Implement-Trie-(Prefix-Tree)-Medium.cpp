class Trie {
private:
    struct Node {
        Node* next[26] = {};
        bool isEnd = false;
    };
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* q = root;
        for (char c : word) {
            if (!q->next[c - 'a']) q->next[c - 'a'] = new Node();
            q = q->next[c - 'a'];
        }
        q->isEnd = true;
    }
    
    bool search(string word) {
        Node* q = root;
        for (char c : word) {
            if (!q->next[c - 'a']) return false;
            q = q->next[c - 'a'];
        }
        return q->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* q = root;
        for (char c : prefix) {
            if (!q->next[c - 'a']) return false;
            q = q->next[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */