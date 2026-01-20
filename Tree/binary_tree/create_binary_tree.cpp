#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int value;
    node* left;
    node* right;
    node(int data){
        this->value=data;
        this->left=NULL;
        this->right=NULL;
    }
};
int main(){
    int x;
    int first,second;
    cout<<"Enter the Root Value! "<<endl;
    cin>>x;
    node* root=new node(x);
    queue<node*> q;
    q.push(root);
    //Build binary Tree
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        //left node create
        cout<<"Enter the left child of "<<temp->value<<endl;
        cin>>first;
        if(first != -1){
            temp->left=new node(first);
            q.push(temp->left);
        }
         //right node create
        cout<<"Enter the right child of "<<temp->value<<endl;
        cin>>second;
        if(second!=-1){
            temp->right= new node(second);
            q.push(temp->right);
        }
    }
    return 0;
}