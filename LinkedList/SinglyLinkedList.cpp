#include <iostream>
#include <vector>

class LinkedList{
    private:
        struct Node{
            int val;
            Node *next;
            Node (int value){
                val = value;
                next = nullptr;
            }
        };
    Node *head;
    public:
        LinkedList(){
            head = nullptr;
        }
        void insertAtBeginning(int value){
            Node *newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }
        void insertAtEnd(int value){
            Node *newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
                return;
            }
           
            Node *temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        void insertAtPosition(int value, int position){
            if(position == 0){
                insertAtBeginning(value);
                return;
            }
            Node *temp = head;
            int count = 0;
            while(temp != nullptr && count < position - 1){
                temp = temp->next;
                count++;
            }
            if(temp == nullptr){
                return;
            }
            Node *newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;

        }

        void deleteAtBeginning(){
            if(head == nullptr){
                return;
            }
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        void deleteAtEnd(){
            if(head == nullptr){
                return ;
            }
            if(head->next == nullptr){
                delete head;
                head = nullptr;
                return;
            }
            Node *temp = head;
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            Node *del = temp->next;
            temp->next = nullptr;
            delete del;
        }
        void deleteAtPosition(int position){
            if(head == nullptr){
                return;
            }
            if(position == 0){
                deleteAtBeginning();
                return;
            }
            Node *temp = head;
            int count = 0;
            while(temp != nullptr && count < position - 1){
                temp = temp->next;
                count++;
            }
            if(temp == nullptr || temp->next == nullptr){
                return;
            }
            Node *del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
        void reverseList(){
            Node *prev = nullptr;
            Node *current = head;
            Node *nextNode = nullptr;
            while(current != nullptr){
                nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            }
            head = prev;
            Node *temp = head;
            while(temp != nullptr){
                std::cout<<temp->val<<"->";
                temp = temp->next;
            }
            std::cout<<"nullptr \n";
        }

        void print(){
            Node *temp = head;
            while(temp != nullptr){
                std::cout<<temp->val<<"->";
                temp = temp->next;
            }
            std::cout<<"nullptr \n";
        }

        ~LinkedList(){
            Node *current = head;
            while(current != nullptr){
                Node *nextNode = current->next;
                delete current;
                current = nextNode;

            }
        }

};
int main(){
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtPosition(30,1);
    list.print();
    std::cout<<std::endl;
    list.deleteAtBeginning();
    list.print();
    list.deleteAtEnd();
    list.print();
    list.insertAtBeginning(40);
    list.print();
    list.deleteAtPosition(1);
    list.print();
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.insertAtBeginning(40);
    list.print();
    list.reverseList();
    return 0;
}