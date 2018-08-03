//
//  main.cpp
//  all_path_from_source_to_target
//
//  Created by Roman Degtyarev on 03.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



class Solution{
public:
    
    
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &pathes, vector<int> path, int src, int dst){
        
        path.push_back(src);
        if (src == dst){
            pathes.push_back(path);
            return;
        }
        
        for (auto cur:graph[src]){
            dfs(graph, pathes, path, cur, dst);
        }
        
        
    }
    
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph){
        size_t N = graph.size();
        
        vector<vector<int>> pathes;
        vector<int> path;
        
        path.clear();
        pathes.clear();
        
        if (N ==0){
            return pathes;
        }
        
        dfs(graph, pathes, path, 0, int(N-1));
        
        return pathes;
    };
};

int main(){
    

    vector < vector < int > > graph {{1,2}, {3}, {3}, {}};
    
    
    Solution sol;
    sol.allPathsSourceTarget(graph);
    
    return 0;
}
