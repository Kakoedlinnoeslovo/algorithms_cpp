//
//  main.cpp
//  partition_labels
//
//  Created by Roman Degtyarev on 03.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;


class Solution{
public:
vector<int> partitionLabels(string S) {

    vector <int> result;
    result.clear();
    
    vector<int> count (26, -1);
    
    if (S.size() == 0){
        return result;
    }
    
    for (auto i = 0; i< S.size(); i++){
        count[S[i] - 'a'] = i;
    }
    
    int i = 0;
    
    while(i < S.size()){
        int tail = count[S[i] - 'a'];
        
        for (auto j = 0; j <= tail; j++){
            tail = max(tail, count[S[j] - 'a']);
        }
        
        result.push_back(tail - i + 1);
        i += (tail - i + 1);
    }
    return result;
}
};


int main() {
    string S  = "qiejxqfnqceocmy";
    //-1 -1 12 -1 10 6 -1 -1 1 3 -1 -1 13 7 11 -1 8 -1 -1 -1 -1 -1 -1 4 14 -1
    Solution sol;
    vector <int> res;
    res = sol.partitionLabels(S);
    
    for (auto i = 0; i < res.size(); i++){
        cout<<res[i]<< ' ';
    }
    
    return 0;
}
