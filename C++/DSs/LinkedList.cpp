#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node* next;
    int val;
};

Node *head;

/*Head will be the new node now; kinda like a Stack*/
void insertNodeAtBeginning(int val){
    Node* newNode = new Node;
    newNode->val = val;

    newNode->next = head;
    head = newNode;
}

/*Head will be the first node that was inserted; kinda like a Queue*/
int insertNodeAtEnd(int val){
    Node* newNode = new Node;
    newNode->val = val;

    if(head == NULL){
        head = newNode;
        return 0;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNodeAtPosition(int pos){
    Node* temp = head;
    Node* temp2;
    while(--pos > 1){
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp->next->next;
    delete(temp2);
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

void reverseLinkedListRecursion(Node* p){
    /*This is a beautiful solution to reverse the linkedlist by recursion; mine is down below,
    but of course it's not as nice as this one, but I wanted to keep mine anyways as well as the
    Internet solution*/
    if(p->next == NULL){
        head = p;
        return;
    }
    reverseLinkedListRecursion(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;


    /*int reverseLinkedListRecursion(int n){
    if(n == 1){
        head->next = NULL;
        return 0;
    }

    Node* temp = head;
    Node* temp2;

    int c = 0;
    while(c < n - 2){
        temp = temp->next;
        c++;
    }

    temp2 = temp;
    temp = temp->next;
    temp->next = temp2;
    reverseLinkedListRecursion(n - 1);
    head = temp;

    return 0;*/

}

void reverseLinkedListIteration(){


    /*the difference with the code below is that here we are a step "further"
    so it means that we'd have to 'rewind' by removing 4th line in the code, put 4th line
    in the loop at the beginning of it, change the n by c in while condition, remove
    the line after the while loop, and change head = 3th line in loop which in this
    case now it'd be 'p'
    The reason I left it like this is because that's how I thought it first and
    the code below found it on the Internet, so I wanted to keep my solution as well as
    another more beautiful;
    */
    Node *p, *c, *n;
    p = NULL;
    c = head;
    n = c->next;

    while(n != NULL){
        c->next = p;
        p = c;
        c = n;
        n = c->next;
    }
    c->next = p;

    head = c;


    /*Node* current, *prev, *next;
    current = head;
    prev = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;*/

}

void reverseLinkedListWithStack(){
    stack<Node*> reverseLL;
    Node* temp = head;
    while(temp != NULL){
        reverseLL.push(temp);
        temp = temp->next;
    }

    temp = reverseLL.top();
    reverseLL.pop();
    head = temp;
    while(!reverseLL.empty()){
        temp->next = reverseLL.top();
        reverseLL.pop();
        temp = temp->next;
    }
    temp->next = NULL;

}

int main(){

    insertNodeAtEnd(5);
    insertNodeAtEnd(15);
    insertNodeAtEnd(25);
    insertNodeAtEnd(35);
    insertNodeAtEnd(45);
    insertNodeAtEnd(55);

    printLinkedList();
    reverseLinkedListWithStack();
    cout << endl;
    printLinkedList();

    return 0;
}
