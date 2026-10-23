#include<iostream>
#include<vector>

void SelectionSort(std::vector<int> &arr){
    for(int i = 0; i < arr.size() - 1; i++){
        int minIndex = i;
        for(int j = i; j < arr.size(); j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            std::swap(arr[i], arr[minIndex]);
        }
        
    }
}