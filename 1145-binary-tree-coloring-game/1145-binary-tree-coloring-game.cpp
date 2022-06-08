class Solution {
public:
	// Function to count nodes in given tree
    int countNodes(TreeNode* curr){
        if(curr==NULL)
            return 0;
        
        return 1 + countNodes(curr->left) + countNodes(curr->right);
    }
	// Function to return a particular node
    TreeNode* getNode(TreeNode* curr, int x){
        if(curr==NULL)
            return curr;
        
        if(curr->val==x)
            return curr;
        
        TreeNode* left = getNode(curr->left,x);
        TreeNode* right = getNode(curr->right,x);
        
        return left!=NULL?left:right;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* xNode = getNode(root,x);
        
        int countLeft = countNodes(xNode->left);
        int countRight = countNodes(xNode->right);
        int countParents = n-(countLeft+countRight+1);
        
        int maxElement = max(countLeft,max(countRight,countParents));
        int minElement = min(countLeft,min(countRight,countParents));
        int midElement = n-maxElement-minElement;
        
        return maxElement>(minElement+midElement)?true:false;
    }
};