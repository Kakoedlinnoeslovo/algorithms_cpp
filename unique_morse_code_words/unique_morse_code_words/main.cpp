//
//  main.cpp
//  unique_morse_code_words
//
//  Created by Roman Degtyarev on 05.07.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;



class Solution {
public:
    vector<string> MORSE {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int bias = 97;
    
    vector<string> temp_result;
    int res = 0;
    int uniqueMorseRepresentations(vector<string>& words) {
        
        if ( words.empty() )
        {
            return 0;
        }
        
        for (int i = 0; i<=words.size()-1; i++){
            string temp_word = "";
            for (int c = 0; c <= words[i].size()-1; c++){
                temp_word+=MORSE[int(words[i][c]) - bias];
            }
            temp_result.push_back(temp_word);
        }
        set<string> result(temp_result.begin(), temp_result.end());
        res = int(result.size());
        return res;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution sol;
    vector <string> a  {"gin", "zen", "gig", "msg"};
    cout <<sol.uniqueMorseRepresentations(a)<<endl;
    return 0;
}
