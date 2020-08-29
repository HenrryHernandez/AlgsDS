#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};


void insertNode(Node** root, int data){
    Node* newNode = new Node();
    newNode->data = data;

    if(*root == NULL){
        *root = newNode;
        return;
    }

    //RECURSIVE WAY OF INSERTING AN ELEMENT
    if(data <= (*root)->data){
        insertNode(&(*root)->left, data);
    }else{
        insertNode(&(*root)->right, data);
    }


    //ITERATIVE WAY OF INSERTING AN ELEMENT
    /*Node* temp = *root;
    while(true){
        if(data <= temp->data){
            if(temp->left == NULL){
                temp->left = newNode;
                return;
            }
            temp = temp->left;

        }else{
            if(temp->right == NULL){
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }*/

}

bool findNode(Node* root, int value){
    Node* temp = root;

    int c = 0;
    while(temp != NULL){
        c++;
        if(temp->data == value){
            c--;
            cout << "c = " << c << endl;
            return true;
        }

        if(value < temp->data){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }

    cout << "c = " << c << endl;
    return false;
}

Node* findMin(Node** root){
    if(*root == NULL) return *root;

    Node* temp = *root;
    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

//THIS IS MY APROACH TO DO THE DELETION ITERATIVELY
void deleteNodeIterative(Node** root, int value){

    if(!findNode(*root, value)){
        cout << "there is no such node" << endl;
        return;
    }

    Node* temp = *root;
    while(temp->data != value){
        if(temp->data < value){
            temp = temp->right;
        }else{
            temp = temp->left;
        }
    }

    temp->data = findMin(&temp->right)->data;
    delete(findMin(&temp->right));
}

//THIS IS MY APROACH TO DO THE DELETION RECURSIVELY
Node* deleteNodeRecursive(Node** root, int value){

    if(*root == NULL){
        return NULL;
    }

    if((*root)->data < value){
        (*root)->right = deleteNodeRecursive(&(*root)->right, value);
    }else if((*root)->data > value){
        (*root)->left = deleteNodeRecursive(&(*root)->left, value);
    }else{
        if((*root)->left == NULL && (*root)->right == NULL){
            delete *root;
            *root = NULL;
        }else if((*root)->right == NULL){
            Node* temp = *root;
            *root = (*root)->left;
            delete(temp);
        }else if((*root)->left == NULL){
            Node* temp = *root;
            *root = (*root)->right;
            delete(temp);
        }else{
            (*root)->data = findMin(&(*root)->right)->data;
            delete(findMin(&(*root)->right));
        }
    }

    return *root;

}

void printTree(Node** root){
    if(*root == NULL) return;

    if((*root)->left == NULL){
        cout << "NULL";
    }else{
        cout << (*root)->left->data;
    }

    cout << " <= " << (*root)->data << " => ";

    if((*root)->right == NULL){
        cout << "NULL" << endl;
    }else{
        cout << (*root)->right->data << endl;
    }

    printTree(&(*root)->left);
    printTree(&(*root)->right);
}


//THIS IS A WAY I FOUND ON THE INTERNET TO DO THE DELETION
/*Node* deleteNode(Node** root, int value){
    if(*root == NULL){
        return *root;
    }else if(value < (*root)->data){
        (*root)->left = deleteNode(&(*root)->left, value);
    }else if(value > (*root)->data){
        (*root)->right = deleteNode(&(*root)->right, value);
    }else{
        //Case 1: No child
        if((*root)->left == NULL && (*root)->right == NULL){
            delete *root;
            *root = NULL;

        //Case 2: One child
        }else if((*root)->left == NULL){
            Node* temp = *root;
            *root = (*root)->right;
            delete temp;
        }else if((*root)->right == NULL){
            Node* temp = *root;
            *root = (*root)->left;
            delete temp;

        //Case 3: 2 children
        }else{
            Node* temp = findMin(&(*root)->right);
            (*root)->data = temp->data;
            (*root)->right = deleteNode(&(*root)->right, temp->data);
        }

    }

    return *root;

}*/

int main(){

    Node* root;
    insertNode(&root, 14);
    insertNode(&root, 9);
    insertNode(&root, 7);
    insertNode(&root, 10);
    insertNode(&root, 15);
    insertNode(&root, 40);
    insertNode(&root, 20);
    insertNode(&root, 45);
    insertNode(&root, 19);
    insertNode(&root, 25);
    insertNode(&root, 43);
    insertNode(&root, 50);
    insertNode(&root, 52);
    insertNode(&root, 42);
    insertNode(&root, 44);
    insertNode(&root, 51);
    insertNode(&root, 0);
    insertNode(&root, -1);


    printTree(&root);
    cout << endl;
    cout << endl;
    //cout << findNode(root, 50) << endl;
    deleteNodeRecursive(&root, 50);
    //cout << findNode(root, 50) << endl;
    printTree(&root);

    return 0;
}
