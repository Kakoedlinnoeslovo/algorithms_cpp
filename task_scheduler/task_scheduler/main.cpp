//
//  main.cpp
//  task_scheduler
//
//  Created by Roman Degtyarev on 25.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector <int> tasks_int (26, 0);
        
        for (auto i: tasks){
            tasks_int[i - 'A']++;
        }
        
        int max_elem = *max_element(tasks_int.begin(), tasks_int.end());
        
        int answer = max_elem + (max_elem - 1)*n - 1;
        
        for (auto i = 0; i < tasks_int.size(); i++){
            if (tasks_int[i] == max_elem){
                answer++;
            }
        };
        return max((int)tasks.size(), answer);
    };
};



int main() {
    Solution sol;
    vector<char> v {'A', 'A', 'A', 'B', 'B', 'B'};
    int re = sol.leastInterval(v, 0);
    cout <<re;
    
    return 0;
}
