// @leet start
class Word {
public:
  Word* children[26];
  bool isWord;
  Word(){
    isWord = false;
    for(auto &c : children){
      c = nullptr;
    } 
  }
};

//brute force would be try every letter and back track if it doenst work, brute force is the optimal solution lol
class WordDictionary {
public:
  Word *root;
  WordDictionary() {
    root = new Word(); 
  }

  void addWord(string word) {
    Word* n = root; 
    for (auto &c : word){
      int p = c - 'a';
      if(!n->children[p]){
        n->children[p] = new Word();
      }
      n = n->children[p];
    }
    n->isWord = true;
  }

  //if char == '.', run a for loop through all of the 26 letters and see if their children matches the remaining word, if it doesn't, then backtrack
  bool search(string word) {
    return dfs(root, word, 0);
  }

  bool dfs(Word* node, string word, int index){
    if(index == word.size()){
      return node->isWord;
    }

    char c = word[index];

    if(c == '.'){
      for(auto &p : node->children){
        if (p && dfs(p, word, index + 1)) { // Check if p is not null
          return true;
        }
      }
      return false;
    } else{
      int p = c - 'a';
      if (!node->children[p]) {
        return false;
      }
      return dfs(node->children[p], word, index + 1);
    }
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @leet end
