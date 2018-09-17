//
//  main.cpp
//  generate_parentheses
//
//  Created by Roman Degtyarev on 17.09.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void extraGenerate(string s, int n, int ob, int balance, vector<string> &result){
        if (ob < n){
            extraGenerate(s + "(", n, ob + 1, balance + 1, result);
        }
        
        if (balance > 0){
            extraGenerate(s + ")", n, ob, balance - 1, result);
        }
        
        if (ob == n and balance == 0){
                result.push_back(s);
            }
        
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        result.clear();
        int ob = 1;
        int balance = 1;
        extraGenerate("(", n, ob, balance, result);
        return result;
    }
};

int main() {
    Solution sol;
    
    vector <string> res;
    
    res = sol.generateParenthesis(3);
    
    for (auto i = 0; i < res.size(); i++){
        cout << res[i]<< endl;
    }
    
    return 0;
}
