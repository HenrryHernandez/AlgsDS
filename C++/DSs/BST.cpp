#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void insertNodeIterative(Node** root, int data){

    Node* newNode = new Node();
    newNode->data = data;

    if(*root == NULL){
        *root = newNode;
        return;
    }

    Node* temp = *root;
    while(true)
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
}

void insertNodeRecursive(Node** root, int data){
    Node* newNode = new Node();
    newNode->data = data;

    if(*root == NULL){
        *root = newNode;
        return;
    }

    if(data <= (*root)->data)
        insertNodeRecursive(&(*root)->left, data);
    else
        insertNodeRecursive(&(*root)->right, data);
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

        if(value < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    cout << "c = " << c << endl;
    return false;
}

Node* findMin(Node** root){
    if(*root == NULL) return *root;

    Node* temp = *root;
    while(temp->left != NULL)
        temp = temp->left;

    return temp;
}

Node* findMax(Node** root){
    if(*root == NULL) return *root;

    Node* temp = *root;
    while(temp->right != NULL)
        temp = temp->right;

    return temp;
}

void deleteNodeIterative(Node** root, int value){

    if(!findNode(*root, value)){
        cout << "there is no such node" << endl;
        return;
    }

    Node* temp = *root;
    while(temp->data != value)
        if(temp->data < value)
            temp = temp->right;
        else
            temp = temp->left;

    temp->data = findMin(&temp->right)->data;
    delete(findMin(&temp->right));
}

Node* deleteNodeRecursive(Node** root, int value){

    if(*root == NULL) return NULL;

    if((*root)->data < value)
        (*root)->right = deleteNodeRecursive(&(*root)->right, value);
    else if((*root)->data > value)
        (*root)->left = deleteNodeRecursive(&(*root)->left, value);
    else
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

    return *root;

}

int findHeight(Node* root){
    if(root == NULL)
        return -1;
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void printTree(Node** root){
    if(*root == NULL) return;

    if((*root)->left == NULL)
        cout << "NULL";
    else
        cout << (*root)->left->data;

    cout << " <= " << (*root)->data << " => ";

    if((*root)->right == NULL)
        cout << "NULL" << endl;
    else
        cout << (*root)->right->data << endl;

    printTree(&(*root)->left);
    printTree(&(*root)->right);
}

void preorderTraversal(Node* root){
    if(root == NULL) return;

    preorderTraversal(root->left);
    cout << root->data << " ";
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root){
    if(root == NULL) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrder(queue<Node*>& levelQueue){
    if(levelQueue.front() == NULL && !levelQueue.empty()){
        levelQueue.pop();
        levelOrder(levelQueue);
        return;
    };

    levelQueue.push(levelQueue.front()->left);
    levelQueue.push(levelQueue.front()->right);
    cout << levelQueue.front()->data << endl;
    levelQueue.pop();
    levelOrder(levelQueue);
}

void levelorderTraversar(queue<Node*>& levelQueue){
    while(!levelQueue.empty()){
        cout << levelQueue.front()->data << " ";
    }
    cout << endl;
}


int main(){

    Node* root = NULL;
    insertNodeIterative(&root, 14);
    insertNodeIterative(&root, 9);
    insertNodeIterative(&root, 7);
    insertNodeIterative(&root, 10);
    insertNodeIterative(&root, 15);
    insertNodeIterative(&root, 40);
    insertNodeIterative(&root, 20);
    insertNodeIterative(&root, 45);
    insertNodeIterative(&root, 19);
    insertNodeRecursive(&root, 25);
    insertNodeRecursive(&root, 43);
    insertNodeRecursive(&root, 50);
    insertNodeRecursive(&root, 52);
    insertNodeRecursive(&root, 42);
    insertNodeRecursive(&root, 44);
    insertNodeRecursive(&root, 51);
    insertNodeRecursive(&root, 0);
    insertNodeRecursive(&root, -1);


    printTree(&root);
    cout << endl;
    cout << endl;

    cout << "MIN = " << findMin(&root)->data << endl;
    cout << "MAX = " << findMax(&root)->data << endl;
    cout << "HEIGHT = " << findHeight(root) << endl;
    cout << "PREORDER = ";
    preorderTraversal(root);
    cout << endl;
    cout << "INORDER = ";
    inorderTraversal(root);
    cout << endl;
    cout << "POSTORDER = ";
    postorderTraversal(root);
    cout << endl;

    queue<Node*> levelQueue;
    levelQueue.push(root);
    cout << "LEVEL TRAVERSAL = ";
    levelOrder(levelQueue);
    //levelorderTraversar(levelQueue);


    /*deleteNodeRecursive(&root, 50);
    cout << endl;
    cout << endl;
    printTree(&root);*/


    cout << endl;
    cout << endl;

    return 0;
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
