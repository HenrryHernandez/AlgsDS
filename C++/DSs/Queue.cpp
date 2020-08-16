#include <bits/stdc++.h>

/*I've seen on the internet that they do it using arrays. I did it using linked lists. Here are my conclusions:
Using arrays:
    Pros: Easy to implement. Memory is saved as pointers are not involved.
    Cons: It is not dynamic. It doesn’t grow and shrink depending on needs at runtime.
    Insertion time = O(1)

Using LinkedLists:
    Pros: The linked list implementation of stack can grow and shrink according to the needs at runtime.
    Cons: Requires extra memory due to involvement of pointers.
    Insertion time = O(n), if we use tail it could drop to O(1), but we'd have to use even more memory cuz
        we'd have to use double pointer.

*/

using namespace std;

struct Node{
    Node* next;
    int val;
};

Node *head;
int nNodes;

int enqueue(int val){
    Node* newNode = new Node;
    newNode->val = val;

    if(head == NULL){
        head = newNode;
        nNodes++;
        return 0;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    nNodes++;
}

void dequeue(){
    Node *temp = head;
    head = head->next;
    delete(temp);
    nNodes--;

}

bool isEmpty(){
    return head == 0;
}

int inFront(){
    return head->val;
}

int queueSize(){
    return nNodes;
}

void printLinkedList(){
    Node* temp;
    temp = head;

    while(temp != 0){
        cout << temp->val << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    enqueue(5);
    enqueue(15);
    enqueue(25);
    enqueue(35);
    enqueue(45);
    enqueue(55);

    printLinkedList();
    cout << "in front is = "<< inFront() << endl << endl;
    cout << "how many are there = "<< queueSize() << endl << endl;

    dequeue();
    printLinkedList();
    cout << "how many are there = "<< queueSize() << endl << endl;


    return 0;
}
