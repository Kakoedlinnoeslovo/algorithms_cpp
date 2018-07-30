//
//  main.cpp
//  Goat Latin
//
//  Created by Roman Degtyarev on 30.07.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//


/*
 
 class Solution(object):
    def toGoatLatin(self, S):
        wordList = S.split(' ')
        vowel = ['a','e','i','o','u']
        result = []
        for i,word in enumerate(wordList):
            if word[0].lower() in vowel:
                word = word + 'ma'
            else:
                element = word[0]
                word = word[1:]
                word = word+element+ 'ma'
 
            word = word + (i+1)*'a'
            result.append(word)
            return(' '.join(result))
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    
    void split(const std::string &txt, std::vector<std::string> &strs, char ch)
    {
        size_t pos = txt.find( ch );
        size_t init_pos = 0;
        strs.clear();
    
        while( pos != std::string::npos ) {
            strs.push_back( txt.substr( init_pos, pos - init_pos ) );
            init_pos = pos + 1;
            
            pos = txt.find( ch, init_pos );
        }
        
        strs.push_back( txt.substr( init_pos, std::min( pos, txt.size() ) - init_pos + 1 ) );
        
    }
    
    
    const set<char> alphabet = {'a', 'e', 'i', 'o', 'u'};
    string word_end = "ma";
    
    vector <string> strs;
    
    string toGoatLatin(string S) {
        
        split(S, strs, ' ');
        
        unsigned long n = strs.size();
        
        string last = "";
        set<char>::iterator it;
        
        
        vector <string> result;
        
        for (auto i = 0; i <n; ++i){
            string temp = "";
            unsigned long temp_size = strs[i].size();
            char tmp_chr[] {strs[i][0]};
            
            string sas = strs[i];
            std::transform(sas.begin(), sas.end(), sas.begin(), ::tolower);
            it = alphabet.find(sas[0]);
            
            string extra = "";
            for (auto j=0; j<=i; j++) extra += "a";
            
            
            if (*it){
                temp+=strs[i] + "ma" + extra;
                
            }
            else{
                for (auto k = 1; k< temp_size; k++){
                    temp+=strs[i][k];
                }
                temp+= string(tmp_chr) + "ma" + extra;
            }
            
            result.push_back(temp);
        }
        
        string res = "";
        
        for (auto i = 0; i < n; i++) {
        if (i !=0){
            res+=  " " +result[i];
        }
        else{
            res +=result[i];
        }
        }
        return res;
    };
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    
    
    cout << sol.toGoatLatin("I speak Goat Latin");
    return 0;
}
