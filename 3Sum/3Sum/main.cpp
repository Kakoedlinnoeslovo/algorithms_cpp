//
//  main.cpp
//  3Sum
//
//  Created by Roman Degtyarev on 04.09.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector <int>> result;
        result.clear();
        
        if (nums.size() <= 2){
            return result;
        }
    
        
        for (int i = 0; i < nums.size() - 1; i++){
            int a = nums[i];
            
            if (a > 0){
                break;
            }
            
            if (i > 0 && nums[i-1] == a){
                continue;
            }
            
            
            for (int s = i + 1, e = (int) nums.size() - 1; s < e;){
                int b = nums[s];
                int c = nums[e];
                int temp_sum = a + b + c;
                if (temp_sum == 0){
                    result.push_back(vector<int> {a, nums[s], nums[e]});
                    while (b == nums[++s]);
                    while (c == nums[--e]);
                }
                else if (temp_sum > 0){
                        e--;
                    }
                else{
                    s++;
                }
                }
                
        }
        return result;
}
};

int main(int argc, const char * argv[]) {
    
    vector <int> temp_V = {-1, -1, 2};
    
    Solution sol;
    
    vector<vector<int>> result = sol.threeSum(temp_V);
    
    for (auto i =0; i < result.size(); i++){
        for (auto j = 0; j < 3; j++){
            cout<<result[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}
