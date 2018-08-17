//
//  main.cpp
//  find_all_dublicates_in_an_array
//
//  Created by Roman Degtyarev on 17.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> res;
        for (auto i = 0; i < nums.size(); i++){
            nums[abs(nums[i]) - 1] = - nums[abs(nums[i]) - 1];
            if (nums[abs(nums[i]) - 1] > 0){
                res.push_back(abs(nums[i]));
            }
            
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector <int> v {4,3,2,7,8,2,3,1};
    vector <int> result;
    
    result = sol.findDuplicates(v);
    
    for (auto i = 0; i < result.size(); i++){
        cout << result[i];
    }
    
    return 0;
}
