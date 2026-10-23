//Hashing - open, chaining
#include <iostream>
#include <string>
class HashTable{
    private:
        struct Node{
            int key;
            std::string value;
            Node *next;
            Node(int k, std::string name){
                key = k;
                value = name;
                next = nullptr;
            }
        };
        
    Node **table;
    int capacity;
    int size = 0;
    
    int hashFunction(int key){
        return key % capacity;
    }
    public:
        HashTable(int n){
            capacity = n;
            size = 0;
            table = new Node *[capacity];
            for(int i = 0; i < capacity; i++){
                table[i] = nullptr;
            }
        }
        
        void insert(int key, std::string name){
            int index = hashFunction(key);
            Node *temp = table[index];
            while(temp != nullptr){
                if(temp->key == key){
                    temp->value = name;
                    return;
                }
                temp = temp->next;
            }
            Node *newNode = new Node(key, name);
            newNode->next = table[index];
            table[index] = newNode;
            size++;
        }
        
        void DeleteKey(int key){
            int index = hashFunction(key);
            Node *temp = table[index];
            Node *prev = nullptr;
            while(temp != nullptr && temp->key != key){
                prev = temp;
                temp = temp->next;
            }
            if(temp == nullptr){
                std::cout<<"Key Not Found! \n";
                return;
            }
            
            if(prev == nullptr){
                table[index] = temp->next;
            }
            else{
                prev->next = temp->next;
            }
            delete temp;
            size--;
        }
        
        std::string search(int key){
            int index = hashFunction(key);
            Node *temp = table[index];
            while(temp != nullptr){
                if(temp->key == key){
                    return temp->value;
                }
                temp = temp->next;
            }
            return "Not Found! \n";
        }
        
        void display(){
            for(int i = 0; i < capacity; i++){
                std::cout<<"Bucket table ["<<i<<"] ";
                Node *temp = table[i];
                while(temp != nullptr){
                    std::cout<<"key:"<<temp->key<<"|value:"<<temp->value<<" ";
                    temp = temp->next;
                }
                std::cout<<std::endl;
            }
        }
        
        ~HashTable(){
            for(int i = 0; i < capacity; i++){
                Node *current = table[i];
                while(current != nullptr){
                    Node *next = current->next;
                    delete current;
                    current = next;
                }
            }
            delete[] table;
        }
        
};

int main() {
    HashTable ht(7);

    ht.insert(50, "Alice");
    ht.insert(76, "Bob");
    ht.insert(85, "Charlie"); 
    ht.insert(92, "Diana");  

    ht.display();

    std::cout << "\nSearch key 85: " << ht.search(85) << "\n";
    std::cout << "Search key 99: " << ht.search(99) << "\n\n";

    ht.DeleteKey(85);
    ht.display();

    return 0;
}




