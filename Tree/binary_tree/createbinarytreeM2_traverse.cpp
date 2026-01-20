#include<iostream>
using namespace std;
class node{
    public:
    int value;
    node* left, *right;
    node(int data) {
        value=data;
        left=right=NULL;
    }
};
node* binary_tree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    node* newnode=new node(x);
    cout<<"Enter the left child of : "<<x<<" ";
    newnode->left=binary_tree();
     cout<<"Enter the right child of : "<<x<<" ";
    newnode->right=binary_tree();
    return newnode;
}
void pre_order(node* root){
    if(root==NULL)
    return;
    //node
    cout<<root->value<<" ";
    //left
    pre_order(root->left);
    //right
    pre_order(root->right);
}
void in_order(node* root){
    if(root==NULL)
    return;
     //left
    in_order(root->left);
    //node
    cout<<root->value<<" ";
    //right
    in_order(root->right);
}
void post_order(node* root){
    if(root==NULL)
    return;
    //left
    post_order(root->left);
    //right
    post_order(root->right);
    //node
    cout<<root->value<<" ";
}
int main() {
    cout<<"Enter the root node : ";
    node* root;
    root=binary_tree();
    //preorder traversal
    cout<<"printing : "<<endl;
    pre_order(root);
}
