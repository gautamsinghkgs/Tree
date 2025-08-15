#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
};

node *create(){
    int x;
    node *newnode;
    cout<<"Enter data (-1 for no node) :";
    cin>>x;
    if(x == -1){
        return 0;
    }
    newnode = new node();
    newnode->data = x;
    cout<<"Enter Left child of "<<x<<" :";
    newnode->left = create();
    cout<<"Enter Right child of "<<x<<" :";
    newnode->right = create();
    return newnode;
}

void inorder(node *root){
    if(root == 0){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node *root){
    if(root == 0){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root){
    if(root == 0){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node *root = 0;
    root = create();
    cout<<"\nInorder Traversal is : ";
    inorder(root);
    cout<<"\nPreorder Traversal is : ";
    preorder(root);
    cout<<"\nPostorder Traversal is : ";
    postorder(root);

}