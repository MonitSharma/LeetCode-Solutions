/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    if (!root)
      return {};

    vector<vector<int>> ans;
    queue<Node*> q{{root}};

    while (!q.empty()) {
      vector<int> currLevel;
      for (int sz = q.size(); sz > 0; --sz) {
        Node* node = q.front();
        q.pop();
        currLevel.push_back(node->val);
        for (Node* child : node->children)
          q.push(child);
      }
      ans.push_back(currLevel);
    }

    return ans;
  }
};
