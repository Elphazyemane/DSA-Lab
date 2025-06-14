class Solution {
 public:
    int  sumNumbers(TreeNode* root){
        return sum(root, 0);
    }
    int  sum(TreeNode* node, int sumNum){
        if  (!node) {
           return 0;
        }
        sumNum = sumNum * 10 + node -> val;
         if (!node->left && !node->right) {
             return sumNum;
        }
    return sum(node->left, sumNum) + sum(node->right, sumNum);
    }
};