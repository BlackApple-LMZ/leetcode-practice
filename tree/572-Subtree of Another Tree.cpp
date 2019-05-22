bool isSubtree(TreeNode* s, TreeNode* t) {
    if(!s)
        return false;
    bool temp;
    if(s->val == t->val)
        temp = findSub(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    else{
        temp =  isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    return temp;
}
bool findSub(TreeNode* s, TreeNode* t){
    if(!s || !t)
        return (!s) && (!t);

    if(s->val == t->val)
        return findSub(s->left, t->left) && findSub(s->right, t->right);
    else
        return false;
}

//上述方法的简洁表述版 java
public class Solution {
public boolean isSubtree(TreeNode s, TreeNode t) {
    return traverse(s,t);
}
public boolean equals(TreeNode x,TreeNode y)
{
    if(x==null && y==null)
        return true;
    if(x==null || y==null)
        return false;
    return x.val==y.val && equals(x.left,y.left) && equals(x.right,y.right);
}
public boolean traverse(TreeNode s,TreeNode t)
{
    return  s!=null && ( equals(s,t) || traverse(s.left,t) || traverse(s.right,t));
}
}
