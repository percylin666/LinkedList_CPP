#include <iostream>
#include <string>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}
    ~LinkedList() {
        clear();
    }

    void pushHead(const T& value);
    void deleteHead();
    void clear();
    int getSize() const;
    void printList() const;
};

template <typename T>
void LinkedList<T>::pushHead(const T& value) {
    Node* newNode = new Node(value);

    newNode->next = head;
    head = newNode;
    size++;
}

template <typename T>
void LinkedList<T>::deleteHead() {
    if (!head) return;

    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}

template <typename T>
void LinkedList<T>::clear() {
    while (head) {
        deleteHead();
    }
}

template <typename T>
int LinkedList<T>::getSize() const {
    return size;
}

template <typename T>
void LinkedList<T>::printList() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main(int argc, char** argv) {
    LinkedList<std::string> list;
    list.pushHead("Make");
    list.pushHead("Dreams");
    list.pushHead("Reality");

    std::cout << "Linked List size: " << list.getSize() << std::endl;
    list.printList();

    LinkedList<int> intList;
    intList.pushHead(1);
    intList.pushHead(2);
    intList.pushHead(3);

    std::cout << "Integer Linked List size: " << intList.getSize() << std::endl;
    intList.printList();

    LinkedList<double> doubleList;
    doubleList.pushHead(1.1);
    doubleList.pushHead(2.2);
    doubleList.pushHead(3.3);

    std::cout << "Double Linked List size: " << doubleList.getSize() << std::endl;
    doubleList.printList();

    return 0;
}