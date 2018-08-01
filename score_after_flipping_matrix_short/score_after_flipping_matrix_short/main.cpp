//
//  main.cpp
//  score_after_flipping_matrix_short
//
//  Created by Roman Degtyarev on 01.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{
    public:
    int matrixScore(vector<vector<int>> A){
        int rows = int(A.size());
        int cols =  int(A[0].size());
        int result = (1<<(cols - 1)) * rows;
        
        for (auto i = 1; i < cols; i++){
            int res = 0;
            for (auto j = 0; j<rows; j++){
                res += A[j][i] == A[j][0];
            }
            result+= max(res, (rows - res)) * (1<<(cols-i-1));
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> A {{0, 0, 1, 1}, {1,0,1,0}, {1,1,0,0}};
    Solution sol;
    cout << sol.matrixScore(A);
    return 0;
}
