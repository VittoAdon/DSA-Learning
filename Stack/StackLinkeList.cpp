#include <iostream>
#include <vector>
class LLStack{
    struct Node{
        int val;
        Node *next;
        Node(int data){
            val = data;
            next = nullptr;
        } 
    };  
    Node *head;
    public:
        LLStack(){
            head = nullptr;
        }
        
        void push(int value){
            Node *newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
        }
        void pop(){
            if(head == nullptr){
                return;
            }
            Node *temp = head;
            head = temp->next;
            std::cout<<"Pop Data: "<<temp->val<<"\n";
            delete temp;
        }
        void peek(){
            if(head == nullptr){
                std::cout<<"list empty";
                return;
            }
            std::cout<<"Top Element "<<head->val;
            std::cout<<std::endl;
        }
        
        void print(){
            Node *temp = head;
            while(temp != nullptr){
                std::cout<<temp->val<<"->";
                temp = temp->next;
            }
            std::cout<<"nullptr \n";
        }
        ~LLStack(){
            Node *current = head;
            while(current != nullptr){
                Node *next = current->next;
                delete current;
                current = next;
            }
            head = nullptr;
        }
};
int main(){
    LLStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    s.peek();
    s.pop();
    s.print();
    s.peek();
    return 0;
}