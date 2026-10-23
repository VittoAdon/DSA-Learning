#include <iostream>
#include <string>

enum EntryStatus{
    Empty,
    Occupied,
    Deleted,
};

struct HashEntry{
        int key;
        std::string value;
        EntryStatus status;
        
        HashEntry(): key(0), value(""), status(Empty) {}
};

class LinearProbing{
    private:
        HashEntry *table;
        int cap;
        int size;
        
        int hashFunction(int key){
            return key % cap;
        }
        
    public:
        LinearProbing(int s){
            cap = s;
            size = 0;
            table = new HashEntry[cap];
        }
        
        bool isFull() const{
            return size == cap;
        }
        bool isEmpty() const{
            return size == 0;
        }
        
        void insert(int key, std::string name){
            if(isFull()){
                std::cout<<"Full!";
                return;
            }
            int index = hashFunction(key);
            int isAnyDeleted = -1;
            for(int i = 0; i < cap; i++){
                int currentIndex = (index + i) % cap;
                if(table[currentIndex].status == Occupied && table[currentIndex].key == key){
                    table[currentIndex].value = name;
                    return;
                }
                
                if(table[currentIndex].status == Deleted && isAnyDeleted == -1){
                     isAnyDeleted = currentIndex;
                }
                
                if(table[currentIndex].status == Empty){
                    int targetIndex = (isAnyDeleted != -1) ? isAnyDeleted : currentIndex;
                    table[targetIndex].key = key;
                    table[targetIndex].value = name;
                    table[targetIndex].status = Occupied;
                    size++;
                    return;
                }
            }
            if(isAnyDeleted != -1){
                table[isAnyDeleted].key = key;
                table[isAnyDeleted].value = name;
                table[isAnyDeleted].status = Occupied;
                size++;
                return;
            }
            else{
                std::cout<<"Not Found!\n";
            }
        }
        
        void DeleteKey(int key){
            if(isEmpty()){
                std::cout<<"Table Empty! \n";
                return;
            }
            int index = hashFunction(key);
            for(int i = 0; i < cap; i++){
                int currentIndex = (index + i) % cap;
                if(table[currentIndex].status == Occupied && table[currentIndex].key == key){
                    table[currentIndex].status = Deleted;
                    table[currentIndex].value = "";
                    std::cout<<"Deleted Value \n";
                    size--;
                    return;
                } 
                if(table[currentIndex].status == Empty){
                    break;
                }
            }
            std::cout<<"Key Not Found! \n";
        }
        
        void search(int key){
            if(isEmpty()){
                std::cout<<"Table Empty! \n";
                return;
            }
            
            int index = hashFunction(key);
            for(int i = 0; i < cap; i++){
                int currentIndex = (index + i) % cap;
                if(table[currentIndex].status == Occupied && table[currentIndex].key == key){
                    std::cout<<"Key Found with Value: "<<table[currentIndex].value<<"\n";
                    return;
                }
                if(table[currentIndex].status == Empty){
                    break;
                }
            }
            std::cout<<"Key Not Found! \n";
        }
        
        void display() const{
            if(isEmpty()){
                std::cout<<"Table Empty! \n";
                return;
            }
            for(int i = 0; i < cap; i++){
                std::cout<<"slot ["<<i<<"] ";
                if(table[i].status == Occupied){
                    std::cout<<"[Occupied] Key:"<<table[i].key<<"|Value:"<<table[i].value<<"\n";
                }
                else if(table[i].status == Deleted){
                    std::cout<<"Deleted(tombstonr) \n";
                }
                else{
                    std::cout<<"Empty \n";
                }
            }
            std::cout<<"\n";
        }
        ~LinearProbing(){
            delete[] table;
        }
};
int main() {
    LinearProbing ht(7);

    // 1. Insert elements (Notice collisions at hash index 1)
    ht.insert(50, "Alice");   // 50 % 7 = 1 -> Slot 1
    ht.insert(76, "Bob");     // 76 % 7 = 6 -> Slot 6
    ht.insert(85, "Charlie"); // 85 % 7 = 1 -> Collides! Probes to Slot 2
    ht.insert(92, "Diana");   // 92 % 7 = 1 -> Collides! Probes past 1 and 2 to Slot 3

    ht.display();

    // 2. Delete the middle item of collision chain
    std::cout << "Deleting key 85...\n";
    ht.DeleteKey(85); // Slot 2 becomes DELETED (Tombstone)
    ht.display();

    // 3. Search key 92 (Must probe PAST tombstone at Slot 2 to find 92 at Slot 3)
    ht.search(92);
    ht.search(85); 

    // 4. Insert new element that reuses the tombstone slot
    std::cout << "Inserting key 15 (15 % 7 = 1)...\n";
    ht.insert(15, "Evan"); // Probes from 1 -> reuses DELETED Slot 2
    ht.display();

    return 0;
}












