#include<iostream>
using namespace std;
class node{
    public:
    int data,height;
    node* left, *right;

    node(int data){
        this->data=data;
        height=1;
        left=right=NULL;
    }
};
int getheight(node* root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}
int getbalance(node* root){
    return getheight(root->left)-getheight(root->right);
}
// R R
node* left_rotation(node* root){
    node* child =root->right;
    node* childright=child->left;

    child->left=root;
    root->right=childright;

    //updata height
    root->height=1+max(getheight(root->left),getheight(root->right));
    child->height=1+max(getheight(child->left),getheight(child->right));

    return child;

}
// L L
node* right_rotation(node* root){
    node* child =root->left;
    node* childright=child->right;

    child->right=root;
    root->left=childright;

    //updata height
    root->height=1+max(getheight(root->left),getheight(root->right));
    child->height=1+max(getheight(child->left),getheight(child->right));

    return child;

}
node* insert(node* root, int value){
    // Step 1: Base case
    if(root == NULL){
        return new node(value);
    }

    // Step 2: Decide left or right
    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else if(value > root->data){
        root->right = insert(root->right, value);
    }
    // equal value -> ignore
    // return root;


    //update Height
    root->height=1+max(getheight(root->left),getheight(root->right));
    //balancing check
    int balance=getbalance(root);

    //cases for balancing : 

    //left left case
    if(balance>1&&value<root->left->data)
    return  right_rotation(root);

    //right right case
    else if(balance<-1&&value>root->right->data)
     return left_rotation(root);

    //left right case
    else if(balance>1&&value>root->left->data){
      root->left =left_rotation(root->left);
    return  right_rotation(root);  
 }

    //right left case
    else if(balance<-1&&value<root->right->data){
    root->right= right_rotation(root->right);
    return  left_rotation(root);
 }

    //no Unbalancing
    else{
        return root;
    }
}
void preorder(node* root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    node* root=NULL;
    int arr[]={10,20,30,50,69,45,35,80,90,120};
    for(int i=0;i<10;i++){
        root=insert(root,arr[i]);   
    }   
     cout << "Preorder: ";
    preorder(root);
}