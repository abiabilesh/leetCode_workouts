/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int __maxDepth(struct TreeNode *p){
    int depth_right = 0;
    int depth_left  = 0;
    
    if(p == NULL){
        return depth_left;
    }
    
    depth_right++;
    depth_left++;
    
    depth_left += __maxDepth(p->left);
    depth_right += __maxDepth(p->right);
    
    return MAX(depth_left, depth_right);
    
}

int maxDepth(struct TreeNode* root){
    return __maxDepth(root);
}
