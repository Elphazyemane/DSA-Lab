class Solution{
    TreeNode *resultNode;
    int ancestor;
    int lowcommon(TreeNode *topNode, int topLevel){
        if(!topNode) {
            return topLevel - 1;
        }
        if(topLevel > ancestor){
            ancestor = topLevel;
            resultNode = topNode;
        }
        int leftDepth = lowcommon(topNode->left, topLevel + 1);
        int rightDepth = lowcommon(topNode->right, topLevel +1);

        if(leftDepth == ancestor && rightDepth == ancestor){
            resultNode = topNode;
        }
        return max(leftDepth, rightDepth);
    }
    public:
    TreeNode *lcaDeepestLeaves(TreeNode *root){
        ancestor = 0;
        lowcommon(root, 1);
        return resultNode;
    }
};