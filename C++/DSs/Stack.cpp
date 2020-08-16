#include <bits/stdc++.h>

/*I've seen on the internet that they do it using arrays. I did it using linked lists. Here are my conclusions:
Using arrays:
    Pros: Easy to implement. Memory is saved as pointers are not involved.
    Cons: It is not dynamic. It doesn’t grow and shrink depending on needs at runtime.
    Insertion time = O(1)

Using LinkedLists:
    Pros: The linked list implementation of stack can grow and shrink according to the needs at runtime.
    Cons: Requires extra memory due to involvement of pointers.
    Insertion time = O(1)

*/


using namespace std;

struct Node{
    Node* next;
    int val;
};

Node *head;
int nNodes;

/*Head will be the new node now; kinda like a Stack*/
void push(int val){
    Node* newNode = new Node;
    newNode->val = val;

    newNode->next = head;
    head = newNode;
    nNodes++;
}

void pop(){
    Node *temp = head;
    head = head->next;
    delete(temp);
    nNodes--;
}

bool isEmpty(){
    return head == 0;
}

int atPeek(){
    return head->val;
}

int nElements(){
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

    push(5);
    push(15);
    push(25);
    push(35);
    push(45);
    push(55);

    printLinkedList();
    cout << "in front is = "<< atPeek() << endl << endl;
    cout << "how many are there = "<< nElements() << endl << endl;

    pop();
    printLinkedList();
    cout << "in front is = "<< atPeek() << endl << endl;
    cout << "how many are there = "<< nElements() << endl << endl;


    return 0;
}
