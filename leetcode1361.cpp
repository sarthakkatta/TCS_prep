/*
Problem: LeetCode 1361 – Validate Binary Tree Nodes

Approach:
1. Compute indegree of every node.
2. For each child:
   - Increase its indegree.
   - If any node gets indegree > 1:
       → A node has multiple parents.
       → Return false.
3. Find root node:
   - Root must have indegree = 0.
   - There must be exactly one root.
4. Perform BFS from the root:
   - Mark nodes as visited.
   - Count visited nodes.
5. During BFS:
   - If a node is visited again:
       → Cycle exists.
       → Return false.
6. After traversal:
   - All nodes must be reachable.
   - count must equal n.
7. Return true if all conditions are satisfied.

Key Idea:
A valid binary tree must satisfy:
1. Exactly one root.
2. No node has more than one parent.
3. No cycles.
4. All nodes are connected.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);

        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){
                indegree[leftChild[i]]++;
                if(indegree[leftChild[i]] > 1)
                    return false;
            }

            if(rightChild[i] != -1){
                indegree[rightChild[i]]++;
                if(indegree[rightChild[i]] > 1)
                    return false;
            }
        }

        int root = -1;
        int roots = 0;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                root = i;
                roots++;
            }
        }

        if(roots != 1)
            return false;

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(root);

        int count = 0;

        while(!q.empty()){
            int f = q.front();
            q.pop();

            if(visited[f] == true)
                return false;

            visited[f] = true;
            count++;

            if(leftChild[f] != -1){
                q.push(leftChild[f]);
            }

            if(rightChild[f] != -1){
                q.push(rightChild[f]);
            }
        }

        return count == n;
    }
};
