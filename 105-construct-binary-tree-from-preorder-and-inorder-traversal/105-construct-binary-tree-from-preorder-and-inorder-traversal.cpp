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
    
    
    //first sol that takes more time because of finding position
    //of element in each recursive call so we can reduce it 
    //by applying map and then search in O(1);
    
//     int findPos(vector<int>& inorder, int x){
//         for(int i=0;i<inorder.size();i++){
//             if(x == inorder[i]){
//                 return i;
//             }
//         }
        
//         return -1;
//     }
    
    
//     TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int inorderStart, int inorderEnd, int size){
        
//         if(index>=size || inorderStart>inorderEnd){
//             return NULL;
//         }
        
//         int element = preorder[index++];
//         int position = findPos(inorder, element);
//         TreeNode* newnode = new TreeNode(element);
//         newnode->left = solve(preorder, inorder, index, inorderStart, position-1, size);
//         newnode->right = solve(preorder, inorder, index, position+1, inorderEnd, size);
//         return newnode;
//     }
    
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int preorderIndex = 0;
//         TreeNode* ans = solve(preorder, inorder, preorderIndex, 0, inorder.size()-1, preorder.size());
//         return ans;
//     }
    
    

    
    
    //using map for storing position
    
    
    
//     int findPos(vector<int>& inorder, int x){
//         for(int i=0;i<inorder.size();i++){
//             if(x == inorder[i]){
//                 return i;
//             }
//         }
        
//         return -1;
//     }
    
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int inorderStart, int inorderEnd, int size, map<int, int> &mp){
        
        if(index>=size || inorderStart>inorderEnd){
            return NULL;
        }
        
        int element = preorder[index++];
        int position = mp[element];
        TreeNode* newnode = new TreeNode(element);
        newnode->left = solve(preorder, inorder, index, inorderStart, position-1, size, mp);
        newnode->right = solve(preorder, inorder, index, position+1, inorderEnd, size, mp);
        return newnode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        map<int, int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* ans = solve(preorder, inorder, preorderIndex, 0, inorder.size()-1,                 preorder.size(), mp);
        return ans;
    }
};