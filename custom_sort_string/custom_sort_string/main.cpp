//
//  main.cpp
//  custom_sort_string
//
//  Created by Roman Degtyarev on 16.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> dir;
        for (int i = 0; i < S.size(); i++) {
            dir[S[i]] = i;
        }
        sort(T.begin(), T.end(),
             [&dir](const char &a, const char &b) { return dir[a] < dir[b]; });
        return T;
    }
};

int main() {
    Solution sol;
    cout << sol.customSortString("cba", "abcd");
    return 0;
}
