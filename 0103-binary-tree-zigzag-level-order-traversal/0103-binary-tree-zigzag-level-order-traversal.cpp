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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {} ;

        vector<vector<int>>res ; 
        queue<TreeNode*> q ;

        q.push(root) ;
        int flag = true ;

        while (!q.empty()){
            int qlevel = q.size();
            vector<int> temp(qlevel) ;

            for (int i = 0 ; i < qlevel ; i ++){
                TreeNode* node = q.front() ;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right) ;
                q.pop(); 
                int index = flag ? i : qlevel - 1 - i ;
                temp[index] = node -> val ;
            }

            res.push_back(temp) ;
            flag = !flag ;

        }


        return res ;
        
    }
};