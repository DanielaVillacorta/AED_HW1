#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    explicit Node(T data): data(data), next(nullptr){};
};

template <typename T>
class LinkedLists {
    Node<T>* head;
public:
    LinkedLists():head(nullptr){};

    bool empty() {
        if (head == nullptr) {
            return true;
        }
        return false;
    }

    T front() {
        if (empty()){return nullptr;}
        return head->data;
    }

    T back() {
        if (empty()){return nullptr;}

        if (head->next == nullptr){return head->data;}

        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(T Data) {
        Node<T>* newHead = new Node(Data);
        newHead->next = head;
        head = newHead;
    }

    void push_back(T Data) {
        Node<T>* newNode = new Node(Data);
        if (empty()){head = newNode;}

        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = nullptr;
    }

    T pop_front() {
        if(empty()){return nullptr;}

        Node<T>* temp = head;
        head = head->next;
        T deleteNode = temp->data;
        delete temp;
        return deleteNode;
    }

    T pop_back() {
        if (empty()){return nullptr;}

        if (head->next == nullptr) {
            T deleteNode = head->data;
            delete head;
            return deleteNode;
        }

        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        T deleteNode = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return deleteNode;
    }

    int size() {
        if (empty()){return 0;}

        int size = 1;
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    T operator[](const int position) { //revisar
        if (empty() || position < 0 || position >= size()) {
            return "Not found";
        }
        Node<T>* temp = head;
        int i = 0;
        while (i <= position) {
            temp = temp->next;
            i++;
        }
        return temp->data;
    }

    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    return 0;
}
