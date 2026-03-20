class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>& arr) {
        if(!root) return;
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    
    TreeNode* buildBST(vector<int>& arr, int left, int right) {
        if(left > right) return NULL;
        
        int mid = (left + right) / 2;
        
        TreeNode* root = new TreeNode(arr[mid]);
        
        root->left = buildBST(arr, left, mid - 1);
        root->right = buildBST(arr, mid + 1, right);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> arr;
        
        // Step 1: inorder → sorted
        inorder(root, arr);
        
        // Step 2: build balanced BST
        return buildBST(arr, 0, arr.size() - 1);
    }
};