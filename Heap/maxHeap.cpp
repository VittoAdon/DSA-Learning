#include <iostream>
#include <vector>
void insert(std::vector<int> &arr, int value){
    arr.push_back(value);
    int index = arr.size() - 1;
    while(index > 0){
        int parent = (index - 1)/2;
        if(arr[index] > arr[parent]){
            std::swap(arr[index], arr[parent]);
            index = parent;
        }
        else{
            break;
        }
    }
}

void deletes(std::vector<int> &arr){
    if(arr.empty()){
        return;
    }
    if(arr.size() == 1){
        arr.pop_back();
    }
    arr[0] = arr[(arr.size() - 1)];
    arr.pop_back();
    
    int index = 0;
    while(true){
        int left = (2*index) + 1;
        int right = (2*index) + 2;
        int target = index;
        if(left < arr.size() && arr[left] > arr[target]){
            target = left;
        }
        if(right < arr.size() && arr[right] > arr[target]){
            target = right;
        }
        if(target == index){
            break;
        }
        std::swap(arr[index], arr[target]);
        index = target;
    }
}
void print(std::vector<int> &arr){
    for(auto i : arr){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
}
int main(){
    std::vector<int> heap = {90, 70, 80, 40, 50, 60, 30};
    insert(heap, 100);
    print(heap);
    deletes(heap);
    print(heap);
    return 0;
}