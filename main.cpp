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

    T front() {
        return head->data;
    }

    T back() {
        if (head->next == nullptr)
            return head->data;
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
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = nullptr;
    }

    void pop_front() { //revisar
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back() { //revisar
        if (head->next == nullptr) {
            delete head;
        }
        else {
            Node<T>* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }

    bool empty() {
        if (head == nullptr) {
            return true;
        }
        return false;
    }

    int size() {
        int i = 0;
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
            i++;
        }
        return i;
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

    void sort() {

    }
};

int main() {
    return 0;
}
