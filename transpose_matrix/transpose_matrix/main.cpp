//
//  main.cpp
//  transpose_matrix
//
//  Created by Roman Degtyarev on 08.07.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        unsigned long n = A.size()-1;
        unsigned long m = A[0].size() -1;
        
        vector<vector<int>>  result (m+1, std::vector <int> (n+1, 0));
        
        for (int j = 0; j<=m; j++)
            for (int i = 0; i<=n; i++)
                result[j][i] = A[i][j];
        
        return result;
    };
};


int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    vector<vector<int>> A {{1,2,3},{4,5,6},{7,8,9}};
    
    unsigned long n = A.size()-1;
    unsigned long m = A[0].size() -1;
    vector<vector<int>> result (m+1, (vector<int> (n+1, 0)));
    Solution sol;
    result = sol.transpose(A);
    
    for (int i = 0; i<=m; i++){
        for (int j = 0; j<=n; j++)
            cout<<result[i][j];
        cout<<endl;
    }
    return 0;
}
