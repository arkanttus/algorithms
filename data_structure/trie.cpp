#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define READ_SPEED cin.tie(0)->sync_with_stdio(0);
#define MOD 1000000007
#define MAXN 100000
#define INF 0x3f3f3f3f

struct TrieNode {
  
    TrieNode* children[26];

    // marca esse node como fim da palavra
    bool word_end;

    TrieNode() {
        word_end = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

void insert_key(TrieNode* root, const string& key) {
    // Inicializa o ponteiro atual com o node raiz
    TrieNode* node = root;

    for (char c : key) {
      
        int index = c - 'a';
        
        if (!node->children[index])  {
            TrieNode* newNode = new TrieNode();
            node->children[index] = newNode;
        }
      
        node = node->children[index];
    }

    node->word_end = true;
}

bool search_key(TrieNode* root, const string& key) {
    TrieNode* node = root;

    for (char c : key) {
        int index = c - 'a';

        if (!node->children[index]) 
            return false;
        
        node = node->children[index];
    }

    return node->word_end;
}

bool starts_with(TrieNode* root, string prefix){
    TrieNode* node = root;

    for (char c : prefix) {
        int index = c - 'a';

        if (!node->children[index]) {
            return false;
        }

        node = node->children[index];
    }

    return true;
}

int main() {
    TrieNode* root = new TrieNode();

    vector<string> arr = 
      {"and", "ant", "do", "geek", "dad", "ball"};

    for (const string& s : arr) {
        insert_key(root, s);
    }

    vector<string> search_keys = {"do", "gee", "bat"};

    for (string& s : search_keys) {
        cout << "Key : " << s << "\n";
        if (search_key(root, s)) 
            cout << "Present\n";
        else 
            cout << "Not Present\n";        
    }

    cout << "starts with: gee : " << starts_with(root, "gee") << endl;
    cout << "starts with: balz : " << starts_with(root, "balz") << endl;
  
    return 0;
}