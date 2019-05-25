vector<int> postorder1(Node* root) {
    vector<int> res;
    help(root, res);
    return res;
}
void help(Node* root, vector<int>& res){
    if(!root)
        return ;
    for(auto node:root->children)
        help(node, res);
    res.push_back(root->val);
    return;
}
vector<int> postorder2(Node* root) {
    stack<Node*> s; s.push(root);
    vector<int> result;
    while (!s.empty() && root) {
        Node * n = s.top(); s.pop();
        result.insert(result.begin(), n->val);
        for (auto & ch : n->children) s.push(ch);
    }
    return result;
}
vector<int> postorder(Node* root) {
    stack<Node*> s,res; s.push(root);
    vector<int> result;
    while (!s.empty() && root) {
        Node * n = s.top(); s.pop();
        res.push(n);
        //result.insert(result.begin(), n->val);
        for (auto & ch : n->children) s.push(ch);
    }
    while (!res.empty() && root) {
        Node * n = res.top(); res.pop();
        result.push_back(n->val);
    }
    return result;
}
