#include <iostream>
#include <vector>

int LinearSearch(std::vector<int> &arr, int target){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}
int main(){
    std::vector<int> arr = {50,30,20,1,4,3,2,9};
    int target = 10;
    int index = LinearSearch(arr,target);
    if(index != -1){
        std::cout<<"The index of target is: "<<index<<" ";
    }
    else{
        std::cout<<"target not found!";
    }
    
    return 0;
}
