//
//  main.cpp
//  Longest Uncommon Subsequence I
//
//  Created by Roman Degtyarev on 29.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int findLUSlength(string a, string b) {
        
        if (a.size() == 0 and b.size()==0){
            return -1;
        }
        
        if (a.size() != b.size()){
            return a.size() > b.size()? static_cast<int>(a.size()):static_cast<int>(b.size());
        }
        
        vector<vector <int>> table (a.size(), vector <int> (b.size()));
        

        for (int i = 0; i < a.size(); i++){
            table[i][0] = a[i] == b[0]?1:0;
        }
        
        for (int j = 0; j < b.size(); j++){
            table[0][j] = a[0] == b[j]?1:0;
        }
        
        for (int i = 1; i < a.size();  i ++){
            for (int j = 1; j < b.size(); j++){
                table[i][j] = a[i] == b[j]?table[i-1][j-1] +1: max(table[i-1][j], table[i][j-1]);
            }
        }
        
        
        
        if (a.size() == table[a.size() - 1][b.size() - 1]){
            return -1;
        }
        else{
            return static_cast<int>(a.size());
        }
        
        
    }
};


int main() {
    string a = "aaa";
    string b = "aaa";
    Solution sol;
    cout << sol.findLUSlength(a, b);
    return 0;
}
