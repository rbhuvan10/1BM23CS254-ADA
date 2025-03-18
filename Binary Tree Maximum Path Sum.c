#include <stdio.h>
#include <limits.h>

int maxSum(struct TreeNode* root, int* result) {
    if (root == NULL) return 0;
    int left = maxSum(root->left, result);
    int right = maxSum(root->right, result);

    int maxSingle;
    if (left > right) {
        maxSingle = left;
    } else {
        maxSingle = right;
    }
   
    if (maxSingle < 0) {
        maxSingle = 0;
    }

    int maxTop = left + root->val + right;
    if (*result < maxTop) {
        *result = maxTop;
    }

    return root->val + maxSingle;
}

int maxPathSum(struct TreeNode* root) {
    int result = INT_MIN;
    maxSum(root, &result);
    return result;
}
Output:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
