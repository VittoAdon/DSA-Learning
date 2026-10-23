#include <iostream>
class QueueStack{
    private:
        int *arr;
        int capacity;
        int front;
        int rear;
    public:
        QueueStack(int size){
            capacity = size;
            arr = new int[capacity];
            front = -1;
            rear = -1;
        }
        
        bool isFull() const{
            return rear == capacity - 1;
        }
        bool isEmpty(){
            return front == -1;
        }
        
        void enqueue(int value){
            if(isFull()){
                std::cout<<"Queue is full! \n";
                return;
            }
            if(front == -1){
                front = 0;
            }
            rear++;
            arr[rear] = value;
        }
        void dequeue(){
            if(isEmpty()){
                std::cout<<"Queue is empty"<<" \n";
                return;
            }
            std::cout<<"dequeue element is: "<<arr[front]<<"\n";
            front++;
            if(front>rear){
                front = -1;
                rear = -1;
            }
        }
        void peek(){
            if(isEmpty()){
                std::cout<<"Queue is empty";
                return;
            }
            std::cout<<arr[front]<<"\n";
        }
        void display(){
            if(isEmpty()){
                std::cout<<"Queue is empty";
                return;
            }
            for(int i = front; i <= rear; i++){
                std::cout<<arr[i]<<" ";
            }
            std::cout<<std::endl;
        }
        ~QueueStack(){
            delete[] arr;
        }
};
int main() {

    QueueStack q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    q.dequeue();
    q.display();

    return 0;
}







