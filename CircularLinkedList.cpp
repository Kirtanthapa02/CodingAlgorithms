// Circular Linkedlist implementation
#include <bits/stdc++.h>

using namespace std;

struct Node{
  int data;
  Node *next;
  Node(): data(0),next(nullptr){}
};

class CircularLinkedList{
    Node *head,*tail;
  public:
    CircularLinkedList(){
        head = NULL;
        tail = NULL;
    }
    void insert_at_head(int val){
        Node *newNode = new Node();
        newNode->data = val;
        if(head == NULL){
            head = newNode;
            tail = newNode;
            head->next = tail;
        }else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    void insert_at_tail(int val){
        Node *newNode = new Node();
        newNode->data = val;
        if(head == NULL){
            cout<<"No tail to insert"<<endl;
        }else{
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void delete_at_head(){
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        tail->next = head;
        delete temp;
    }
    void delete_at_tail(){
        Node *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = head;
        tail->next = NULL;
        delete tail;
    }
    void print_circularll(){
        Node *temp = head;
        do{
            cout<<temp->data<<"=>";
            temp = temp->next;
        }while(temp != head);
        cout<<temp->data<<endl;
    }
};

int main(){
    CircularLinkedList cll;
    // insert at head
    cll.insert_at_head(1);
    cll.insert_at_head(2);
    cll.insert_at_head(3);
    cll.insert_at_head(4);
    cll.insert_at_head(5);
    // insert at tail
    cll.insert_at_tail(2);
    cll.insert_at_tail(3);
    cll.insert_at_tail(4);
    cll.insert_at_tail(5);
    cll.print_circularll();
    // delete at head
    cll.delete_at_head();
    cll.print_circularll();
    // delete at tail
    cll.delete_at_tail();
    cll.print_circularll();
    return 0;
}
