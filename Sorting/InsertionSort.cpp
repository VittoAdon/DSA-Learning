//Selection sort
#include <iostream>
#include <vector>
#include <algorithm>
void InsertionSort(std::vector<int> &arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print(std::vector<int> &arr){
    for(int num : arr){
        std::cout<<num<<" ";
    }   
}
int main(){
    std::vector<int> arr = { 5,4,3,2,10,2,1};
    InsertionSort(arr);
    print(arr);
    return 0;
}