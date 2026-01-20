#include<iostream>
#include<queue>
#include<vector>
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

vector<int> lefttView(node *root) {
    queue<node*>q;
    vector<int>ans;
    
    // **Safety Check:** Agar tree khali hai to yahi se wapis jao
    if(root == NULL) {
        return ans;
    }

    q.push(root);
    while(!q.empty()){
        int n=q.size();
        
        // Is level ka pehla element ans me daalo (Left View Logic)
        ans.push_back(q.front()->value);
        
        while(n--){
            node* temp=q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}

int main() {
    vector<int> a;
    cout<<"Enter the root node : ";
    node* root;
    root = binary_tree();

    // Function call
    a = lefttView(root);
    
    // **Printing the Answer:** Vector ko print karne ke liye loop
    cout << "Left View of the Tree is: ";
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}