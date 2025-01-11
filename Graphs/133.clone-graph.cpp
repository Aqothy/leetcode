// @leet start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  Node* cloneGraph(Node* node) {
    // use the original nodes as keys and the copy nodes as values in a hashmap, then traverse through the adj list and link the copy nodes

    if (!node) {
      return nullptr;
    }

    unordered_map<Node*, Node*> cloneMap;

    cloneMap[node] = new Node(node->val);

    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
      Node* curr = q.front();
      q.pop();

      for (Node* neighbor : curr->neighbors) {
        // If the neighbor hasn't been cloned yet
        if (cloneMap.find(neighbor) == cloneMap.end()) {
          cloneMap[neighbor] = new Node(neighbor->val);
          q.push(neighbor);
        }
        cloneMap[curr]->neighbors.push_back(cloneMap[neighbor]);
      }
    }

    return cloneMap[node];

  }
};
// @leet end
