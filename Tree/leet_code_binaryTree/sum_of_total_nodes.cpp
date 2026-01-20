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
void sum(node* root,int &sume) {
    if(root==NULL)
    return;
    sume+=root->value;
    sum(root->left,sume);
    sum(root->right,sume);
    // method 2
    //if(root==NULL) return 0;
    // return(root->value+sum(root->left)+sum(root->right))
}
int main() {
    cout<<"Enter the root node : ";
    node* root;
    root=binary_tree();
    //preorder traversal
    cout<<" Sum of total Nodes Are : ";
    int sume=0;
    sum(root,sume);
    cout<<sume;

}