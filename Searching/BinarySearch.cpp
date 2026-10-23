#include <iostream>
#include <vector>
int BinarySearch(std::vector<int> &arr, int target){
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right){
        int middle = (right + left)/2;
        if(arr[middle] == target){
            return middle;
        }
        else if(target > arr[middle]){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }
    return -1;
}
int main(){
    std::vector<int> arr = {1,2,3,4,5,20,80,90};
    int target = 1;
    int index = BinarySearch(arr, target);
    if(index != -1){
        std::cout<<"The target Element index: "<<index;
    }
    else{
        std::cout<<"Element Not Found!";
    }
    return 0;
}