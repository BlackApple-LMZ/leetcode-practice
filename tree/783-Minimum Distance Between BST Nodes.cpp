int minDiffInBST(TreeNode* root) {
    if(!root){
        return -1;
    }
    int val(INT_MAX);
    findMin(root, val);
    return val;
}
void findMin(TreeNode* root, int& val){
    int left = find(root->left, root->val);
    int right = find(root->right, root->val);
    val = min(val, min(left, right));
    if(root->left){
        findMin(root->left, val);
    }
    if(root->right){
        findMin(root->right, val);
    }
    return ;
}
int find(TreeNode* root, int val){
    int minD(INT_MAX);
    TreeNode* node = root;
    while(node){
        if(val>node->val){
            minD = val - node->val;
            node = node->right;
        }
        else{
            minD = node->val - val;
            node = node->left;
        }
    }
    return minD;
}

int res = INT_MAX, pre = -1;
int minDiffInBST(TreeNode* root) {
    if (root->left != NULL) minDiffInBST(root->left);
    if (pre >= 0) res = min(res, root->val - pre);
    pre = root->val;
    if (root->right != NULL) minDiffInBST(root->right);
    return res;
}
