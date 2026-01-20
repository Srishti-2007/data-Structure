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
void counter(node* root,int &count){
    if(root==NULL)
    return;
    count++;
    counter(root->left,count);
    counter(root->right,count);
}
int main() {
    cout<<"Enter the root node : ";
    node* root;
    root=binary_tree();
    //preorder traversal
    cout<<"total Nodes Are : "<<endl;
    int count=0;
    counter(root,count);
    cout<<count<<" ";
}
