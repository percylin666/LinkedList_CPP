#include <iostream>

// 使用模板以支持不同类型
template <typename T>
class LinkedList {
private:
    // 内部节点结构
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    //构造函数
    LinkedList() : head(nullptr), size(0) {
        std::cout << "LinkedList created" << std::endl;
    }

    //析构函数
    ~LinkedList() {
        clear();
        std::cout << "LinkedList destroyed" << std::endl;
    }

    void push_front(const T& value);
    void del_front();
    void clear();
    void print() const;
};

template <typename T>
void LinkedList<T>::push_front(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
}

template <typename T>
void LinkedList<T>::del_front() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}

template <typename T>
void LinkedList<T>::clear() {
    while(head) {
        del_front();
    }
}

template <typename T>
void LinkedList<T>::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main(int argc, char **argv) {
    LinkedList<int> List_int;

    List_int.push_front(11);
    List_int.push_front(22);
    List_int.push_front(33);

    List_int.print();

    LinkedList<std::string> List_string;
    List_string.push_front("Hello");
    List_string.push_front("World");
    List_string.push_front("and");
    List_string.push_front("Enjoy");

    List_string.print();

    return 0;
}