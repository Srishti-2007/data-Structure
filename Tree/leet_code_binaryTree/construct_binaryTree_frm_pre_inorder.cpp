// #include<iostream>
// using namespace std;
// class node{
//     public:
//     int value;
//     node* left, *right;
//     node(int data) {
//         value=data;
//         left=right=NULL;
//     }
// };
// int find(int inorder[], int target,int start, int end){
//     for(int i=start;i<=end;i++){
//         if(inorder[i]==target){
//             return i;
//         }
//     }
//     return -1;
// }
// node* tree(int inorder[],int preorder[],int Instart,int Inend,int index){
//    //first element of preorder of is always a root
//     node* root=new node(preorder[index]); 
//     //find position of first elem in inorder
//     int pos=find(inorder,preorder[index],Instart,Inend);
//     //bulid left and right side around root
//     root->left=tree(inorder,preorder,Instart,pos-1,index+1);
//     root->right=tree(inorder,preorder,pos+1,Inend,index+(pos-Instart)+1);
//     return root;
// }
// node* buildtree(int in[], int pre[],int n){
//     return tree(in,pre,0,n-1,0);
// }

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

// Aapka find function (Linear Search)
int find(int inorder[], int target, int start, int end){
    for(int i=start; i<=end; i++){
        if(inorder[i]==target){
            return i;
        }
    }
    return -1;
}

node* tree(int inorder[], int preorder[], int Instart, int Inend, int index){
    // **IMPORTANT CHANGE**: Base Case add kiya hai
    // Agar start index end se bada ho jaye, matlab koi element nahi bacha
    if(Instart > Inend) {
        return NULL;
    }

    // First element of preorder is always root
    node* root = new node(preorder[index]); 
    
    // Find position in inorder
    int pos = find(inorder, preorder[index], Instart, Inend);
    
    // Build left and right side
    // Logic aapka bilkul same hai
    root->left = tree(inorder, preorder, Instart, pos-1, index+1);
    
    // Right side logic: index + (left subtree ka size) + 1
    root->right = tree(inorder, preorder, pos+1, Inend, index + (pos-Instart) + 1);
    
    return root;
}

node* buildtree(int in[], int pre[], int n){
    return tree(in, pre, 0, n-1, 0);
}

// Ye function bas check karne ke liye hai ki Tree sahi bana ya nahi
// Hum Preorder print karenge, agar ye input wale preorder jaisa aaya to code sahi hai
void printPreorder(node* root) {
    if(root == NULL) return;
    cout << root->value << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // Example Input
    int inorder[] = {4, 2, 5, 1, 3};
    int preorder[] = {1, 2, 4, 5, 3};
    
    // Size nikalna
    int n = sizeof(inorder)/sizeof(inorder[0]);

    // Tree build karna
    node* root = buildtree(inorder, preorder, n);

    // Print karvana
    cout << "Tree ban gaya! Check karne ke liye Preorder print kar rahe hain: " << endl;
    printPreorder(root); 
    cout << endl;

    return 0;
}