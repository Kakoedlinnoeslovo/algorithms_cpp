//
//  main.cpp
//  decoded_string_at_index
//
//  Created by Roman Degtyarev on 23.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#define toDigit(c) (c-'0')

class Solution {
private:
    string decodeAtIndex(string& S, int start, int end, int K){
        long long cnt = 0;
        for (auto i = start; i <= end; i++){
            if(isdigit(S[i])){
                int num = toDigit(S[i]);
                long long old_cnt = cnt;
                while (num - 1){
                    cnt+=old_cnt;
                    if (cnt >= K){
                        return decodeAtIndex(S, start, i - 1, K - (cnt - old_cnt));
                    }
                    num--;
                }
            }
            else{
                cnt++;
                if (cnt == K){
                    return S.substr(i, 1);
                }
            }
        }
        return "";
    }
public:
    string decodeAtIndex(string S, int K) {
        return decodeAtIndex(S, 0, S.size() - 1, K);
};
};

int main(int argc, const char * argv[]) {
    Solution sol;
    cout << sol.decodeAtIndex("a23", 6) << endl;
    return 0;
}
