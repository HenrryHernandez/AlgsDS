#include <bits/stdc++.h>

/*

Binary Search Tree: Used for searching. A binary tree where the left child contains only
nodes with values less than the parent node, and where the right child only contains nodes
with values greater than or equal to the parent.

Propeties:
    -2 Children max
    -Smaller or equal values go to the left of the root.
    -Bigger values go to the right of the root.

*What are the differences between Binary Trees and BTS?
Binary Tree stands for a data structure which is made up of nodes that can only have two
children references.
Binary Search Tree (BST) on the other hand, is a special form of Binary Tree data structure
where each node has a comparable value, and smaller valued children attached to left and larger
valued children attached to the right.
Thus, all BST's are Binary Tree however only some Binary Tree's may be also BST. Notify that BST
is a subset of Binary Tree.
So, Binary Tree is more of a general data-structure than Binary Search Tree. And also you have to
notify that Binary Search Tree is a sorted tree whereas there is no such set of rules for generic
Binary Tree.

*What are the differences between AVL Trees and BTS?
The only difference between AVL Tree and Binary Search Tree is that AVL Tree is a self-balancing tree BST.

            Average     Worst case
Space		O(n)	    O(n)
Search		O(log n)	O(n)
Insert		O(log n)	O(n)
Delete		O(log n)	O(n)
*/

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void insertNodeIterative(Node** root, int data){

    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;

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
    if(*root == NULL){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
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

void preorderTraversal(Node* root){ //<root><left><right>
    if(root == NULL) return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root){ //<left><root><right>
    if(root == NULL) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root){ //<left><right><root>
    if(root == NULL) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void levelorderTraversar(queue<Node*>& levelQueue){
    if(levelQueue.front() == NULL) return;

    if(levelQueue.front()->left != NULL) levelQueue.push(levelQueue.front()->left);
    if(levelQueue.front()->right != NULL) levelQueue.push(levelQueue.front()->right);
    cout << levelQueue.front()->data << " ";
    levelQueue.pop();
    levelorderTraversar(levelQueue);
}

bool checkIfBST(Node* root, int minVal, int maxVal){
    if(root == NULL) return true;

    if(minVal > root->data || root->data > maxVal)
        return false;
    else
        return checkIfBST(root->left, minVal, root->data) && checkIfBST(root->right, root->data, maxVal);
}

Node* inorderSuccessor(Node* root, int value, Node* parentNode){
    if(root == NULL){
        return root;
    }

    if(root->data == value && root->right != NULL){
        return findMin(&root->right);
    }else if(root->data == value && root->right == NULL && root->data > parentNode->data){
        return NULL;
    }else if(root->data == value && root->right == NULL && root->data < parentNode->data){
        return parentNode;
    }else if(root->data < value){
        return inorderSuccessor(root->right, value, root);
    }else{
        return inorderSuccessor(root->left, value, root);
    }
}

void invertTree(Node** root){
    if(*root == NULL) return;

    invertTree(&(*root)->left);
    invertTree(&(*root)->right);

    Node* temp = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = temp;
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
    insertNodeIterative(&root, 10);
    insertNodeIterative(&root, 14);


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
    levelorderTraversar(levelQueue);
    cout << endl;

    //this code helps to test the "checkIfBST()" function with the insertions made upper in the code. It should not be a BST.
    /*Node* newNode = new Node();
    newNode->data = 11;
    newNode->left = newNode->right = NULL;
    root->right->left = newNode;
    cout << root->right->left->data << endl;
    printTree(&root);*/

    cout << "IS IT A BST? ";
    if(checkIfBST(root, INT_MIN, INT_MAX)) cout << "It is" << endl;
    else cout << "It's not" << endl;

    int inS = 52;
    cout << "WHAT IS THE SUCCESSOR OF " << inS << "? ";
    Node* inSNode = inorderSuccessor(root, inS, root);
    if(inSNode == NULL) cout << "There is no successor" << endl;
    else cout << inSNode->data << endl;

    /*deleteNodeRecursive(&root, 50);
    cout << endl;
    cout << endl;
    printTree(&root);*/

    cout << endl;
    printTree(&root);
    cout << endl;

    invertTree(&root);

    cout << endl;
    printTree(&root);
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


//THIS IS A LESS EFICIENT WAY TO CHECK IF A TREE IS A BST, BUT IT'S INTERESTING SO I APPEND IT HERE
/*bool isSubtreeLesser(Node* root, int data){
    if(root == NULL) return true;

    if( root->data <= data &&
        isSubtreeLesser(root->left, data) &&
        isSubtreeLesser(root->right, data))
        return true;
    else
        return false;
}

bool isSubtreeGreater(Node* root, int data){
    if(root == NULL) return true;

    if( root->data > data &&
        isSubtreeGreater(root->left, data) &&
        isSubtreeGreater(root->right, data))
        return true;
    else
        return false;
}

bool isBinarySearchTree(Node* root){
    if(root == NULL) return true;

    if( isSubtreeLesser(root->left, root->data) &&
        isSubtreeGreater(root->right, root->data) &&
        isBinarySearchTree(root->left) &&
        isBinarySearchTree(root->right))
        return true;
    else
        return false;
}*/
