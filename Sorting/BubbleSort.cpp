//Selection sort
#include <iostream>
#include <vector>
#include <algorithm>
void BubbleSort(std::vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i -1; j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j + 1]);
            }
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
    BubbleSort(arr);
    print(arr);
    return 0;
}