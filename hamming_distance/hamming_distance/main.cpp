//
//  main.cpp
//  hamming_distance
//
//  Created by Roman Degtyarev on 07.07.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        if (x == y){
            return 0;
        }
        else {
            return ((x&1)^(y&1)) + hammingDistance(x>>1, y>>1);
        }
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    std::cout <<sol.hammingDistance(1, 4)<<std::endl;
    return 0;
}
