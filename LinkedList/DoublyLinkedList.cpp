#include <iostream>
#include <vector>

class DoublyLinkedList{
    private:
        struct Node{
            int val;
            Node *next;
            Node *prev;
            Node(int value){
                val = value;
                next = nullptr;
                prev = nullptr;
            }
        };
    Node *head;
    public:
        DoublyLinkedList(){
            head = nullptr;
        }
        void insertAtBeginning(int value){
            Node *newNode = new Node(value);
            if (head == nullptr){
                head = newNode;
                return;
            }
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        void insertAtEnd(int value){
            Node *newNode = new Node(value);
            if (head == nullptr){
                head = newNode;
                return;
            }
            Node *temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            newNode->prev = temp;
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
            newNode->prev = temp;
            if(temp->next != nullptr){
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }

        void deleteAtBeginning(){
            if(head == nullptr){
                return;
            }
            Node *temp = head;
            head = head->next;
            if(head != nullptr){
                head->prev = nullptr;
            }
            delete temp;

        }
        void deleteAtEnd(){
            if(head == nullptr){
                return;
            }
            if(head->next == nullptr){
                delete head;
                head = nullptr;
                return;
            }
            Node *temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->prev->next = nullptr;
            delete temp;
        }

        void deleteAtPosition(int position){
            if(position == 0){
                deleteAtBeginning();
                return;
            }
            int count = 0;
            Node *temp = head;
            while(temp != nullptr && count < position - 1){
                temp = temp->next;
                count++;
            }
            if(temp==nullptr || temp->next == nullptr){
                return;
            }
            Node *del = temp->next;
            temp->next = del->next;
            if(del->next != nullptr){
                del->next->prev = temp;
            }
            delete del;
        }
        void print(){
            Node *temp = head;
            while(temp != nullptr){
                std::cout<<temp->val<<"->";
                temp = temp->next;
            }
            std::cout<<"nullptr \n";
        }
        void printBack(){
            if (head == nullptr) {
                std::cout << "nullptr \n"; 
                return;
            }
            Node *temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            while(temp!=nullptr){
                std::cout<<temp->val<<"->";
                temp = temp->prev;
            }
            std::cout<<"nullptr \n";

        }
        ~DoublyLinkedList(){
            Node *current = head;
            while(current != nullptr){
                Node *next = current->next;
                delete current;
                current = next;
            }
        }
};
int main(){
    DoublyLinkedList list;
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
    list.printBack();
    return 0;
}