//
//  main.cpp
//  counting_bits
//
//  Created by Roman Degtyarev on 14.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int get_ones(int num){
        int count = 0;
        while(num!=0)
        {
            num = num & (num-1);
            count++;
        }
        cout<<count;
        return count;
    }
public:
    vector<int> countBits(int num) {
        vector<int> result;
        result.clear();
        for (auto i = 0; i <= num; i++){
            result.push_back(get_ones(i));
        }
        return result;
        
    }
};


int main() {
    int num = 0;
    Solution sol;
    sol.countBits(num);
    return 0;
}
