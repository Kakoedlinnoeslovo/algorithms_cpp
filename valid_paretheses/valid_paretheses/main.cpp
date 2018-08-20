//
//  main.cpp
//  valid_paretheses
//
//  Created by Roman Degtyarev on 20.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> stak;
        for (auto a: s){
            if (a == '(' || a == '{' || a == '['){
                stak.push(a);
            }
            else if (stak.empty()){
                return false;
            }
            else if ((a == ')' && stak.top() == '(') || (a == '}' && stak.top() == '{') || (a == ']' && stak.top() == '[')){
                stak.pop();
            }
            else{
                return false;
            }
        }
        return stak.empty();
    
    };
};


int main(int argc, const char * argv[]) {
    Solution sol;
    cout << sol.isValid("()");
    return 0;
}
