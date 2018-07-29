//
//  main.cpp
//  judge_route_circle
//
//  Created by Roman Degtyarev on 29.07.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;




class Solution {
public:
    bool judgeCircle(string moves) {
        stack<char> updown;
        stack<char> leftright;
        
        if (moves.size() == 0){
            return false;
        }
        
        
        bool up = 0;
        bool left = 0;
        
        
        size_t N = moves.size();

        for (auto i =0; i < N; i++){
            if (char(moves[i]) == 'L' or char(moves[i]) == 'U'){
                
                if (char(moves[i]) == 'L'){
                    if (leftright.empty()) left = 1;
                    if (left == 1) leftright.push('L');
                    else leftright.pop();
                }
                
                
                if (char(moves[i]) == 'U'){
                    if (updown.empty()) up = 1;
                    if (up == 1) updown.push('U');
                    else updown.pop();
                }
                
            }
            
            else if (char(moves[i]) == 'R' or char(moves[i]) == 'D'){
                if (char(moves[i]) == 'R'){
                    if (leftright.empty()) left = 0;
                    if(left == 1) leftright.pop();
                    else leftright.push('R');
    
                }
                if (char(moves[i] == 'D')){
                    if (updown.empty()) up = 0;
                    if (up == 1) updown.pop();
                    else updown.push('D');
                }
            }
            
            else {
                return false;
            }
        }
        
        if (leftright.empty() and updown.empty()){
            return true;
        }
        else {
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    cout<<sol.judgeCircle("LL");
    return 0;
}


