int kthSmallest(struct TreeNode* root, int k) {
 int result=-1;
 int count=0;

    void inorder(struct TreeNode* root){

        if(root==NULL || count==k){
            return;
            }
        
            inorder(root->left);
            count++;

            if(count==k){
                result=root->val;
                return;
            }
            inorder(root->right);

    }
       inorder(root);
       return result;
    }
Output:
Input: root = [3,1,4,null,2], k = 1
Output: 1
