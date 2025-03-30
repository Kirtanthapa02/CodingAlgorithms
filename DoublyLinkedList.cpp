// Doubly Linkedlist Implementation
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node *prev;
    Node *next;
    Node(): val(0),prev(nullptr),next(nullptr) {}
};
class DoublyLinkedList{
    Node *head;
  public:
    DoublyLinkedList(){
        head = NULL;
    }
    void push_front(int val){
        Node *newNode = new Node();
        if(head == NULL){
            newNode->val = val;
            head = newNode;
        }else{
            newNode->val = val;
            newNode->prev = NULL;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void push_back(int val){
        Node *newNode = new Node();
        if(head == NULL) cout<<"Empty list"<<endl;
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        newNode->val = val;
        newNode->prev = temp;
        temp->next = newNode;
    }
    void pop_front(){
        Node *temp = head;
        head = temp->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    void pop_back(){
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    void print_doublyll(){
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->val<<"<=>";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    DoublyLinkedList dll;
    // push_front method
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_front(4);
    dll.push_front(5);
    // push_back method
    dll.push_back(2);
    dll.push_back(3);
    dll.push_back(4);
    dll.push_back(5);
    dll.print_doublyll();
    // pop_front method
    dll.pop_front();
    dll.print_doublyll();
    // pop_back method
    dll.pop_back();
    dll.print_doublyll();
    return 0;
}
