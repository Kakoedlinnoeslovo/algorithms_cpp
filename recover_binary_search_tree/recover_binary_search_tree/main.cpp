//
//  main.cpp
//  recover_binary_search_tree
//
//  Created by Roman Degtyarev on 03.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>





struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
 };

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        if (root->left){
            root->left = pruneTree(root->left);
        }
        if (root->right){
            root->right = pruneTree(root->right);
        }
        
        if (root->left == NULL && root->right == NULL){
            if (root->val == 0){
                root = NULL;
            }
            return root;
        }
        return root;
    }
};

int main() {
    return 0;
}
