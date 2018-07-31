//
//  main.cpp
//  max_increase_to_keep_city_skyline
//
//  Created by Roman Degtyarev on 31.07.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int suma = 0;
        vector <int> max_top;
        vector <int> max_left;
        
        max_left.clear();
        max_top.clear();
        
        unsigned long rows = grid.size();
        unsigned long cols = grid[0].size();
        
        if (rows!=cols or rows == cols == 0 or rows > 50 or cols > 50){
            return suma;
        }
        
        
        
        for (auto i=0; i<rows; i++){
            int temp_max_left = grid[i][0];
            int temp_max_top = grid[0][i];
            for (auto j=1; j<cols; j++){
                if (grid[i][j] > temp_max_left) temp_max_left = grid[i][j];
                if (grid[j][i] > temp_max_top) temp_max_top = grid[j][i];
            }
            max_left.push_back(temp_max_left);
            max_top.push_back(temp_max_top);
        }
        
        for (auto i = 0; i < rows; i ++){
            for (auto j = 0; j < cols; j++){
                int temp = (max_left[i]  < max_top[j])?max_left[i]:max_top[j];
                if (grid[i][j] < 0 or grid[i][j] > 100){
                    return 0;
                }
                suma+=abs(grid[i][j] - temp);
            }
        }
        
        return suma;
    }
};

int main(int argc, const char * argv[]) {
    vector <vector<int>> v {{3,0,8,4},
                            {2,4,5,7},
                            {9,2,6,3},
                            {0,3,1,0}};
    
    Solution sol;
    cout<<sol.maxIncreaseKeepingSkyline(v)<<endl;
    
    
    return 0;
}
