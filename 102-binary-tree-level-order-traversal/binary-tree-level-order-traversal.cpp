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

   
     vector<vector<int>>ans2;

    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*>q;
        

         if(root==NULL){
            return {};
         }
       

        q.push(root);


        TreeNode*temp;
        while(!q.empty()){

             vector<int>ans;

            int n=q.size();

            for(int i=0;i<n;i++)
        {
            temp=q.front();



            ans.push_back(temp->val);

            q.pop();

            if(temp->left)
            q.push(temp->left);

             if(temp->right)
            q.push(temp->right);
            }
             ans2.push_back(ans);

        }
       
        return ans2;
        
    }
};