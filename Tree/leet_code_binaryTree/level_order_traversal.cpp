#include<iostream>
#include<queue>
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
void level_order_traversal(node* root){
    queue<node*>q;
    q.push(root);
    node* temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        cout<<temp->value<<" ";
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
}
int main() {
    cout<<"Enter the root node : ";
    node* root;
    root=binary_tree();
    //preorder traversal
    cout<<"printing : "<<endl;
    level_order_traversal(root);
}