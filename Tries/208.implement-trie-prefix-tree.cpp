// @leet start
class TrieNode {
public:
  TrieNode* children[26];
  bool word;

  TrieNode(){
    word = false;
    for(auto &c : children){
      c = nullptr;
    }
  }
};

class Trie {

public:
  TrieNode* root;

  // use linked list for this, each node will be a letter, since its only lower case english letters, use array to keep track of if preceding letters where each of the 26 positions represent a letter
  Trie() {
    root = new TrieNode(); 
  }

  void insert(string word) {
    TrieNode *n = root;
    for(auto &c : word){
      int p = c - 'a';
      if(!n->children[p]){
        n->children[p] = new TrieNode();
      }
      n = n->children[p];
    }
    n->word = true;
  }

  bool search(string word) {
    TrieNode *n = root;
    for(auto &c : word){
      int p = c - 'a';
      if(!n->children[p]){
        return false;
      }
      n = n->children[p];
    }
    return n->word;
  }

  bool startsWith(string prefix) {
    TrieNode *n = root;
    for(auto &c : prefix){
      int p = c - 'a';
      if(!n->children[p]){
        return false;
      }
      n = n->children[p];
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
// @leet end
