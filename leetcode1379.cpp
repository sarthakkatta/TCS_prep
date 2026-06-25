/*
Problem: LeetCode 1379 – Find a Corresponding Node of a Binary Tree
in a Clone of That Tree

Approach:
1. Perform BFS traversal on the cloned tree.
2. Use a queue to visit nodes level by level.
3. For each node:
   - Compare its value with target->val.
4. If values match:
   - Return the current node from the cloned tree.
5. Otherwise:
   - Push left child if it exists.
   - Push right child if it exists.
6. Continue until the node is found.
7. Return NULL if no matching node exists.

Key Idea:
- Traverse only the cloned tree and locate
  the node corresponding to the target value.
- Since cloned tree has the same structure
  and values as the original tree, the matching
  value identifies the corresponding node.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original,
                            TreeNode* cloned,
                            TreeNode* target) {

        queue<TreeNode*> q;
        q.push(cloned);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->val == target->val)
                return temp;

            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right != NULL)
                q.push(temp->right);
        }

        return NULL;
    }
};
