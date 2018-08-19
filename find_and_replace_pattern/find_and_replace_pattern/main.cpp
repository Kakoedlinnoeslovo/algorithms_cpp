//
//  main.cpp
//  find_and_replace_pattern
//
//  Created by Roman Degtyarev on 19.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        
        unsigned long n = pattern.size();
        vector<string> result;
        
        for (auto i = 0; i < words.size(); i++){
            int lp [26] = {0};
            int rp [26] = {0};
            bool indicator = true;
            for (auto c = 0; c < n; c++){
                if (lp[words[i][c] - 'a'] != rp[pattern[c] - 'a']){
                    indicator = false;
                }
                else{
                    lp[words[i][c] - 'a'] = rp[pattern[c] - 'a'] = c + 1;
                }
                if (!indicator){
                    break;
                }
            }
            if (indicator){
                result.push_back(words[i]);
            }
                    
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector <string> v {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    vector <string> result;
    result = sol.findAndReplacePattern(v, pattern);
    
    for (auto i =0; i < result.size(); i++){
        cout<<result[i]<< " ";
    }
    return 0;
}
