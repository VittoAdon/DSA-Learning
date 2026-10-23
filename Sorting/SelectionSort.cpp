//Selection sort
#include <iostream>
#include <vector>
#include <algorithm>
void selectionSort(std::vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

void print(std::vector<int> &arr){
    for(int num : arr){
        std::cout<<num<<" ";
    }   
}
int main(){
    std::vector<int> arr = { 5,4,3,2,10,2,1};
    selectionSort(arr);
    print(arr);
    return 0;
}