//
//  main.cpp
//  two_sums
//
//  Created by Roman Degtyarev on 27.06.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unsigned long nums_size = nums.size();
        vector<int> result (2, 0);
        if (target < 0){
            target = - target;
            for (int i = 0; i<nums_size; i++){
                if (nums[i] < 0){
                    nums[i] = abs(nums[i]);
                }
                else{
                    nums[i] = - nums[i];
                }
            }
        }
        
        if (nums_size == 0){
            vector<int> result1 (0, 0);
            return result1;
        };
        
        //reverse(nums.begin(), nums.end());
        
        
        
        vector <int> abs_nums(nums_size, 0);
        vector <int> inv_nums(nums_size, 0);
        for (int i =0; i<nums_size; i++){
            abs_nums[i] = abs(nums[i] - target);
            inv_nums[i] = (nums[i] - target);
        }
        
        for (int i =0; i<nums_size; i++){
            if (inv_nums[i] > 0)
                continue;
            for (int j = i+1; j< nums_size; j++){
                if (abs_nums[i] == nums[j]){
                    result[0] = i;
                    result[1] = j;
                }
                }
            }
        
        sort(result.begin(), result.end());
        for (int i =0; i<2; i++){
            cout<<result[i]<<" ";
        }
        return result;
    };
        
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solution;
    int myints[] = {-1,-2,-3,-4,-5};
    std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );
    solution.twoSum(nums, -8);
    return 0;
}
