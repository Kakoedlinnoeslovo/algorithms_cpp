//
//  main.cpp
//  maximum_binary_tree
//
//  Created by Roman Degtyarev on 01.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    
    
int get_maximum_index(vector<int>& nums){
    int max = 0;
    int index = 0;
    for (auto i=0; i<nums.size(); i++)
        if (nums[i] > max){
            max = nums[i];
            index = i;
        }
    return index;
};
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int max_index = get_maximum_index(nums);
        
        TreeNode * treenode = new TreeNode(nums[max_index]);
        
        
        vector<int>::const_iterator first = nums.begin();
        vector<int>::const_iterator last = nums.begin() + max_index;
        vector<int> left_side(first, last);
        
        first = nums.begin() + max_index + 1;
        last = nums.end();
        
        vector<int> right_side(first, last);
        
        if (left_side.size() >= 1){
            if (left_side.size() == 1) treenode->left = new TreeNode(left_side[0]);
            else {
                treenode ->left = constructMaximumBinaryTree(left_side);
            }
        }

        if (right_side.size() >=1){
            
            if (right_side.size() == 1) treenode->right = new TreeNode(right_side[0]);
            else{
                treenode ->right = constructMaximumBinaryTree(right_side);
            }
        }
        
        
        return treenode;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> v {3,2,1,6,0,5};
    Solution sol;
    sol.constructMaximumBinaryTree(v);
    return 0;
}
