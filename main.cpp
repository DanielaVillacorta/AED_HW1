#include <iostream>
#include <stack>
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
        if (empty()){
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    T back() {
        if (empty()){
            throw std::out_of_range("List is empty");
        }

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
        else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    T pop_front() {
        if(empty()) {
            throw std::out_of_range("List is empty");
        }

        Node<T>* temp = head;
        head = head->next;
        T deleteNode = temp->data;
        delete temp;
        return deleteNode;
    }

    T pop_back() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }

        if (head->next == nullptr) {
            T deleteNode = head->data;
            delete head;
            head = nullptr;
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
        if(empty()) {
            throw std::out_of_range("List is empty");
        }
        if(position<0) {
            throw std::out_of_range("Negative index");
        }
        if(position>=size()) {
            throw std::out_of_range("Indez out of range");
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

    void reverse() {
        Node<T>* antes = nullptr;
        Node<T>* actual = head;
        Node<T>* siguiente = nullptr;

        while (actual != nullptr) {
            siguiente = actual->next;
            actual->next = antes;
            antes = actual;
            actual = siguiente;
        }

        head = antes;

    }
};

int main() {
    return 0;
}
