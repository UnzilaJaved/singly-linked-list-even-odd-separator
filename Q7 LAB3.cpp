#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class singlyLinkedList {
public:
    node* head;
    node* tail;
    singlyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(int data) {
        node* temp = new node(data);
        if (!head) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    void EvenOdd() {
        node* temp = head;
        singlyLinkedList evenList;
        singlyLinkedList oddList;

        while (temp != NULL) {
            if (temp->data % 2 == 0) {
                evenList.insertAtHead(temp->data);
            } else {
                oddList.insertAtHead(temp->data);
            }
            temp = temp->next;
        }

        if (evenList.tail != NULL) {
            evenList.tail->next = oddList.head;
        }

        head = evenList.head;
        if (oddList.tail) {
            tail = oddList.tail;
        } else {
            tail = evenList.tail;
        }
    }

    void printData() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    singlyLinkedList s1;
    s1.insertAtHead(6);
    s1.insertAtHead(7);
    s1.insertAtHead(1);
    s1.insertAtHead(4);
    s1.insertAtHead(5);
    s1.insertAtHead(10);
    s1.insertAtHead(12);
    s1.insertAtHead(8);
    s1.insertAtHead(15);
    s1.insertAtHead(17);

    cout << "Original List: ";
    s1.printData();

    s1.EvenOdd();

    cout << "Modified List: ";
    s1.printData();

    return 0;
}

