//
//  main.cpp
//  flipping_an_image
//
//  Created by Roman Degtyarev on 07.07.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>


#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        unsigned long rows = A.size() - 1;
        unsigned long cols  = A[0].size() - 1;
        
        vector<vector<int>> result (rows+1, vector <int> (cols+1, 0));
        
        for (int i=0; i<=rows; i++){
            for (int j = int (cols); j>=0; j--){
                if (A[i][j] == 1){
                    result[i][cols - j] = 0;
                }
                else{
                    result[i][cols - j] = 1;
                }

            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> A {{1,1,0},{1,0,1},{0,0,0}};
    
    unsigned long rows = A.size()-1;
    unsigned long cols  = A[0].size()-1;
    
    Solution sol;
    vector<vector<int>> res (rows+1, vector<int> (cols+1, 0));
    res = sol.flipAndInvertImage(A);
    
    for (int i=0; i<=rows; i++){
        for (int j=0; j<=cols; j++){
            cout<<res[i][j];
        }
        cout<<endl;
    }

    return 0;
}
