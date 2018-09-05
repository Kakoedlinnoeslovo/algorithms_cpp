//
//  main.cpp
//  letter_combinations_of_a_phone_number
//
//  Created by Roman Degtyarev on 05.09.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;



#define toDigit(c) (c-'0')
#define toChar(c) (c + '0')

class Solution {
public:
    stringstream ss;
    map <int, string> mapper = {{1,""}, {2,"abc"}, {3,"def"}, {4,"ghi"}, {5,"jkl"}, {6,"mno"}, {7,"pqrs"}, {8, "tuv"}, {9,"wxyz"}};
    
    vector <string> letterRecursively(string digits, int pos){
        
        vector <string> this_step;
        this_step.clear();
        
        if (pos == digits.size() - 1){
            string temp = mapper[toDigit(digits[pos])];
            for (int i = 0; i < temp.size(); i++){
                this_step.push_back(string (&temp[i], 1));
            }
            return this_step;
        }
        
        string one = mapper[toDigit(digits[pos])];
        
        
        for (auto i = 0; i < one.size(); i++){
            vector <string> right_part = letterRecursively(digits, pos + 1);
            if (right_part.size() == 1){
            for (auto e = 0; e < right_part.size(); e++){
                for (auto j = 0; j < right_part[e].size(); j++){
                    char two = right_part[e][j];
                    string toVector = string( &one[i], 1) + string( &two, 1 );
                    this_step.push_back(toVector);
                }
            }
            }
            else{
                for (auto e = 0; e < right_part.size(); e++){
                    string two = right_part[e];
                    string toVector = string( &one[i], 1) + two;
                    this_step.push_back(toVector);
                }
            }
        }
        return this_step;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        v.clear();
        
        
        v = letterRecursively(digits, 0);
        return v;
    }
};


int main() {
    Solution sol;
    vector<string> v;
    v = sol.letterCombinations("23");
    
    for (auto a:v){
        cout << a << " ";
    }
    return 0;
}
