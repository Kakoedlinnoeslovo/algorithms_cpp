//
//  main.cpp
//  quick_sort
//
//  Created by Roman Degtyarev on 18.08.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void quicksort(vector <int> &v, int s, int e){
    int i = s;
    int j = e;
    int pivot_val = v[(s + e)/2];
    int temp;
    
    while (i <= j){
        while(v[i] < pivot_val){
            i++;
        }
        while (v[j] > pivot_val){
            j--;
        }
        if (i <= j){
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
        
    }
    
    if (s < j){
        quicksort(v, s, j);
    }
    if (i < e){
        quicksort(v, i, e);
    }
    
}

int main() {
    
    vector <int> v {14, 7, 26, 12};
    quicksort(v, 0, (int) v.size() - 1);
    
    for (int i = 0; i< v.size(); i++){
        cout << v[i] << " ";
    };
    
    return 0;
}
