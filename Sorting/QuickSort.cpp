//Selection sort
#include <iostream>
#include <vector>
#include <algorithm>
int Partition(std::vector<int> &arr, int low, int high){
    
    int pivot = arr[low];
    int i = low;
    for(int j = low + 1; j <= high; j++){
        if(arr[j] < pivot){
            i++;
            std::swap(arr[i],arr[j]);
        }
    }
    std::swap(arr[low], arr[i]);
    return i;
}

void QuickSort(std::vector<int> &arr, int low, int high){
    if(low < high){
        int pivot_index = Partition(arr, low, high);
        QuickSort(arr, low, pivot_index - 1);
        QuickSort(arr, pivot_index + 1, high);
    }
}

void print(std::vector<int> &arr){
    for(int num : arr){
        std::cout<<num<<" ";
    }   
}
int main(){
    std::vector<int> arr = { 5,4,3,2,10,2,1};
    int right = arr.size();
    QuickSort(arr, 0 , right - 1);
    print(arr);
    return 0;
}