#include <iostream>

class CircularDoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    int size;

public:
    CircularDoublyLinkedList() : head(nullptr), size(0) {}

    bool isEmpty() const {
        return head == nullptr;
    }

    int getSize() const {
        return size;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);

        if (isEmpty()) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            Node* tail = head->prev;

            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;

            head = newNode;
        }
        size++;
    }

    void insertTail(int val) {
        if (isEmpty()) {
            insertHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;

        size++;
    }

    void deleteHead() {
        if (isEmpty()) {
            std::cout << "List is empty!\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* tail = head->prev;
            Node* temp = head;

            head = head->next;
            head->prev = tail;
            tail->next = head;

            delete temp;
        }
        size--;
    }

    void deleteTail() {
        if (isEmpty() || head->next == head) {
            deleteHead();
            return;
        }

        Node* tail = head->prev;
        Node* newTail = tail->prev;

        newTail->next = head;
        head->prev = newTail;

        delete tail;
        size--;
    }

    void deleteValue(int val) {
        if (isEmpty()) {
            std::cout << "List is empty!\n";
            return;
        }

        Node* curr = head;
        do {
            if (curr->data == val) {
                if (curr == head) {
                    deleteHead();
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                    size--;
                }
                return;
            }
            curr = curr->next;
        } while (curr != head);

        std::cout << "Value " << val << " not found in the list.\n";
    }

    void displayForward() const {
        if (isEmpty()) {
            std::cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        std::cout << "Forward:  ";
        do {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        std::cout << "(back to head: " << head->data << ")\n";
    }

    void displayBackward() const {
        if (isEmpty()) {
            std::cout << "List is empty!\n";
            return;
        }

        Node* tail = head->prev;
        Node* temp = tail;
        std::cout << "Backward: ";
        do {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        } while (temp != tail);
        std::cout << "(back to tail: " << tail->data << ")\n";
    }

    ~CircularDoublyLinkedList() {
        while (!isEmpty()) {
            deleteHead();
        }
    }
};

int main() {
    CircularDoublyLinkedList cdll;

    cdll.insertTail(10);
    cdll.insertTail(20);
    cdll.insertTail(30);
    cdll.insertHead(5);

    cdll.displayForward();
    cdll.displayBackward();

    std::cout << "\nDeleting head (5) and tail (30)...\n";
    cdll.deleteHead();
    cdll.deleteTail();

    cdll.displayForward();

    std::cout << "\nDeleting value 20...\n";
    cdll.deleteValue(20);

    cdll.displayForward();

    return 0;
}