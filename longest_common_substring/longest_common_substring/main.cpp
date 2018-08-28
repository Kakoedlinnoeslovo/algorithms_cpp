//
//  main.cpp
//  longest_common_substring
//
//  Created by Roman Degtyarev on 28.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    int longest_substring(string one, string two){
        
        int one_size = (int) one.size();
        int two_size = (int) two.size();
        vector<vector <int>> table (one_size, vector <int> (two_size, 0));
        
        
        table[0][0] = one[0] == two[0]?1:0;

        for (auto j = 1; j < two_size; j++){
            table[0][j] = max(table[0][j-1], one[0] == two[j]?1:0);
        }
        
        for (auto i = 1; i < one_size; i++){
            table[i][0] = max(table[i-1][0], one[i] == two[0]?1:0);
        }
        
        for (auto i = 1; i < one_size; i++){
            for (auto j = 1; j < two_size; j++){
                if (one[i] == two[j]){
                    table[i][j] = table[i-1][j-1] +1;
                }
                else{
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }
        
        
        return table[one_size-1][two_size-1];

        
    }
    
};


int main() {
    Solution sol;
    cout << sol.longest_substring("GeeksforGeeks", "GeeksQuiz");
    return 0;
}










