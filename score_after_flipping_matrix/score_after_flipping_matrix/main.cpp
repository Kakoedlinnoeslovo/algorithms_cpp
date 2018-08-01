//
//  main.cpp
//  score_after_flipping_matrix
//
//  Created by Roman Degtyarev on 01.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calc_sum(vector<vector<int>> &A, int x, int y, int axis){
        int suma = 0;
        vector<int> temp_row = A[x];
        vector<int> temp_col;
        temp_col.clear();
        for (auto i = 0; i < A.size(); i++) temp_col.push_back(A[i][y]);
        
        
        if (axis ==1){
            unsigned long n = temp_row.size() - 1;
            for(auto i = 0; i < temp_row.size(); i++){
                //if (i == y) continue;
                if (temp_row[i] == 1) suma+=table[n - i];
                }
        }
        if (axis ==0){
            unsigned long m = temp_row.size() - 1;
            for(auto i = 0; i < temp_col.size(); i++){
                //if (i == x) continue;
                if (temp_col[i] == 1) suma+=table[m - y];
            }
        }
        return suma;
}
    
    void swap(vector<vector<int>> &A, int n, int axis){
        if (axis == 1){
            for (auto i = 0; i < A[n].size(); i++)
                A[n][i] = (A[n][i] == 1)? 0:1;
            }
        if (axis == 0){
            for (auto i =0; i < A.size(); i++)
                A[i][n] = (A[i][n] == 1)? 0:1;
        }
    }
    
    
    vector<unsigned long> table {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
    
    int matrixScore(vector<vector<int>>& A) {
        unsigned long rows = A.size();
        unsigned long cols = A[0].size();
        
        if (rows == 1 and cols == 1){
            return 1;
        }
        
        int result = 0;
        if (rows < 1 or rows > 20 or cols < 1 or cols > 20) return 0;
        
        for (auto i = 0; i< cols; i++){
            for (auto j =0; j < rows; j++){
                if (A[j][i] != 0 and A[j][i] != 1){
                    return 0;
                }
                if (A[j][i] == 0){
                    int row_sum_before = calc_sum(A, j, i, 1);
                    int col_sum_before = calc_sum(A, j, i, 0);
                    swap(A, j, 1);
                    int row_sum_after = calc_sum(A, j, i, 1);
                    swap(A, j, 1);
                    swap(A, i, 0);
                    int col_sum_after = calc_sum(A, j, i, 0);
                    swap(A, i, 0);
                    
                    if (row_sum_after > row_sum_before) swap(A, j, 1);
                    else if (col_sum_after > col_sum_before) swap(A, i, 0);
                    
                    
                }
            }
        }
        
        for (auto i = 0; i< rows; i++) result+=calc_sum(A, i, 0, 1);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> A = {{0,0},{0,1},{1,1},{0,1},{1,1},{0,0},{1,1},{0,0}};
    Solution sol;
    //sol.swap(A, 0, 0);
    cout<<sol.matrixScore(A);
    
    return 0;
}
