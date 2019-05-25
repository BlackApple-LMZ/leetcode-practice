TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* node = root;
    if(!root){
        TreeNode* temp = new TreeNode(val);
        return temp;
    }
    while(node){
        if(val>node->val){
            if(node->right)
                node = node->right;
            else{
                TreeNode* temp = new TreeNode(val);
                node->right = temp;
                break;
            }
        }
        else if(val<node->val){
            if(node->left)
                node = node->left;
            else{
                TreeNode* temp = new TreeNode(val);
                node->left = temp;
                break;
            }
        }
    }
    return root;

}
//下面是一点点代码方面的优化
TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode *cur = root, *node = new TreeNode(val);
    while (cur) {
        if (cur -> val > val) {
            if (cur -> left) {
                cur = cur -> left;
            } else {
                cur -> left = node;
                break;
            }
        } else {
            if (cur -> right) {
                cur = cur -> right;
            } else {
                cur -> right = node;
                break;
            }
        }
    }
    return root ? root : node;
}
