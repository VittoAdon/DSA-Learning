//Selection sort
#include <iostream>
#include <vector>
#include <algorithm>
void Merge(std::vector<int> &arr, int left, int middle, int right){
    int n1 = middle - left + 1;
    int n2 = right - middle;
    std::vector<int> L(n1), R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[middle + 1 + j];
    }
    int i = 0, j = 0;
    int k = left;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i++];
        }
        else{
            arr[k] = R[j++];
        }
        k++;
    }
    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
}

void MergeSort(std::vector<int> &arr, int left, int right){
    if(left >= right){
        return;
    }
    int middle = (right + left)/2;
    MergeSort(arr, left, middle);
    MergeSort(arr, middle + 1, right);
    Merge(arr, left, middle, right);
}

void print(std::vector<int> &arr){
    for(int num : arr){
        std::cout<<num<<" ";
    }   
}
int main(){
    std::vector<int> arr = { 5,4,3,2,10,2,1};
    int right = arr.size();
    MergeSort(arr, 0 , right - 1);
    print(arr);
    return 0;
}