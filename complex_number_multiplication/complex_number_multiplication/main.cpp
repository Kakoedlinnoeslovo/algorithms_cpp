//
//  main.cpp
//  complex_number_multiplication
//
//  Created by Roman Degtyarev on 04.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution{
public:
    string complexNumberMultiply(string a, string b) {
        stringstream is(a + b), os;
        
        int x, y, u, v;
        char ch;
        
        is >> x >> ch >> y >> ch >> u >> ch >> v;
        
        os << x*u - y*v << "+" << x*v + y*u << "i";
        
        return os.str();
    }
    
};


int main() {
    
    //Input: "1+1i", "1+1i"
    Solution sol;
    
    cout<<sol.complexNumberMultiply("1+-1i", "1+-1i")<<endl;
    return 0;
}
