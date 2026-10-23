#include <iostream>
class CircularQueue{
    private:
        int *arr;
        int cap;
        int front;
        int rear;
        int count;
    public:
        CircularQueue(int size){
            cap = size;
            arr = new int[cap];
            front = 0;
            rear = -1;
            count = 0;
        }
         bool isFull() const{
             return count == cap;
         }
         bool isEmpty() const{
             return count == 0;
         }
         
         void enqueue(int value){
             if(isFull()){
                 std::cout<<"Queue is full \n";
                 return;
             }
             rear = (rear+1)%cap;
             arr[rear] = value;
             count++;
         }
         void dequeue(){
             if(isEmpty()){
                 std::cout<<"Queus is empty \n";
                 return;
             }
             std::cout<<"dequeue element is: "<<arr[front];
             front = (front + 1)%cap;
             count--;
         }
         void peek(){
             if(isEmpty()){
                 std::cout<<"Queus is empty \n";
                 return;
             }
             std::cout<<"Peek is: "<<arr[front]<<"\n";
         }
         void print(){
             if(isEmpty()){return;}
             int index = front;
             for(int i = 0; i<count;i++){
                 std::cout<<arr[index]<<" ";
                 index = (index+1)%cap;
             }
         }
         ~CircularQueue(){
             delete[] arr;
         }
};
int main() {

    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();
    return 0;
    
}






