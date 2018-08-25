//
//  main.cpp
//  max_area_of_island
//
//  Created by Roman Degtyarev on 25.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int DFS(vector<vector <int>> &grid, int i, int j){
        
        int max_i = (int) grid.size();
        int max_j = (int) grid[0].size();
        
        if (i < 0 || j < 0 || i >= max_i || j >= max_j){
            return 0;
        };
        
        if (grid[i][j] == 0){
            grid[i][j] = -1;
            return 0;
        };
        
        if (grid[i][j] != -1){
            grid[i][j] = - 1;
            return 1 + DFS(grid, i, j + 1) + DFS(grid, i + 1, j) + DFS(grid, i - 1, j) + DFS(grid, i, j - 1);
        }
        else{
            return 0;
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_i = (int) grid.size();
        int max_j = (int) grid[0].size();
        
        int li = 0;
        for (auto i = 0; i < max_i; i++){
            for (auto j = 0; j < max_j; j++){
                int temp_x = DFS(grid, i, j);
                if (temp_x > li){
                    li = temp_x;
                };
            }
        }
        return li;
    }
};

int main() {
    
    vector <vector <int>> v {{0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution sol;
    int a = sol.maxAreaOfIsland(v);
    cout<< a;
    return 0;
}
