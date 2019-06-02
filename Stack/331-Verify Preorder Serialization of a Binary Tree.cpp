bool isValidSerialization(string preorder) {
    if (preorder.empty()) return false;
    preorder+=',';
    int sz=preorder.size(),idx=0;
    int capacity=1;
    for (idx=0;idx<sz;idx++){
        if (preorder[idx]!=',') continue;
        capacity--;
        if (capacity<0) return false;
        if (preorder[idx-1]!='#') capacity+=2;
    }
    return capacity==0;
}
bool isValidSerialization(string preorder) {
    stack<char> res;
    preorder += ',';
    for(int i=0; i<preorder.size(); i++){
        char c=preorder[i];
        if(c == '#'){
            while(!res.empty() && res.top() == '#'){
                res.pop();
                if(res.empty())
                    return false;
                res.pop();
            }
            res.push(c);
        }
        else if(c>='0' && c<='9'){
            if(preorder[i+1]<'0' || preorder[i+1]>'9')
                res.push(c);
        }
        else
            continue; 
    }
    return res.size()==1 && res.top()=='#';
}
