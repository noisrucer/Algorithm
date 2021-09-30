
int res;

pair<int,int> longest(Tree* root){
    if(!root) return {0,0};

    auto leftChild = longest(root->left);
    auto rightChild = longest(root->right);

    int leftLongest = leftChild.second + 1;
    int rightLongest = rightChild.first + 1;

    res = max({res, leftLongest, rightLongest});
    return {leftLongest, rightLongest};
}

int solve(Tree* root) {
    if(!root) return 0;
    res = INT_MIN;
    longest(root);
    return res;
}