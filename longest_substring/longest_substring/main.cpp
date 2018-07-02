//
//  main.cpp
//  longest_substring
//
//  Created by Roman Degtyarev on 02.07.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    bool indicator = false;
    string ls;
    string temp;
    set <char> A;
    int result;
    int lengthOfLongestSubstring(string s) {
        if (s == ""){
            return 0;
        };
        if (s.size()==1){
            return 1;
        }
        ls = "";
        temp = "";
        size_t len = s.size();
        for (int i = 0; i < len; i++){
            for (int j = i; j < len; j++){
                if (temp.find(s[j]) != std::string::npos) {
                    indicator = true;
                    if (temp.size() > ls.size()){
                        ls = temp;
                        temp = "";
                    }
                    else{
                        temp = "";
                    }
                    break;
                }
                temp+=s[j];
        }
        }
        if (not indicator) ls = temp;
        result = int(ls.size());
        cout<<ls<<endl;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    string a;
    a = "asjrgapa";
    cout<<sol.lengthOfLongestSubstring(a)<<endl;
    return 0;
}
