#include <iostream>
#include <queue>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
};

Node* createNode(char data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// BFS YA GES
void BFS(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
}

// DFS 
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    Node* A = createNode('A');
    Node* B = createNode('B');
    Node* C = createNode('C');
    Node* D = createNode('D');
    Node* H = createNode('H');

    A->left = B;
    A->right = H;
    B->left = C;
    B->right = D;

    cout << "BFS  : ";
    BFS(A);

    cout << "\nDFS Inorder       : ";
    inorder(A);

    cout << "\nDFS Preorder      : ";
    preorder(A);

    cout << "\nDFS Postorder     : ";
    postorder(A);

    return 0;
}