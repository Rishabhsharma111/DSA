/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MAX;

    void inorder(TreeNode* root, int &prev) {
        if (root == NULL) return;

        // Left
        inorder(root->left, prev);

        // Current
        if (prev != -1) {
            ans = min(ans, root->val - prev);
        }
        prev = root->val;

        // Right
        inorder(root->right, prev);
    }

    int minDiffInBST(TreeNode* root) {
        int prev = -1;  // initial marker
        inorder(root, prev);
        return ans;
    }
};
/**prev stores last visited node
ans keeps minimum difference

We skip first comparison using:

if (prev != -1)*/