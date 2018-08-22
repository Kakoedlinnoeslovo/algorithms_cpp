//
//  main.cpp
//  balanced_binary_tree
//
//  Created by Roman Degtyarev on 22.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

 
class Solution {
public:
    int isbalanced(TreeNode *root, bool &answ){
        if (!root){
            return 0;
        }
        
        int left_height = isbalanced(root->left, answ);
        int right_height  = isbalanced(root->right, answ);
        
        if (abs(left_height - right_height) > 1){
            answ = false;
        }
        
        return left_height>right_height?left_height + 1:right_height+1;
    }
    
    bool isBalanced(TreeNode* root) {
        bool answ = true;
        isbalanced(root, answ);
        return answ;
        
    };
};

int main(int argc, const char * argv[]) {
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(9);
    node->right = new TreeNode(20);
    
    node->left->left = new TreeNode(15);
    node->left->right = new TreeNode(17);
    
    node->left->left->left = new TreeNode(15);
    node->left->left->right = new TreeNode(15);
    Solution sol;
    
    cout<<sol.isBalanced(node)<<endl;
    
    return 0;
}
