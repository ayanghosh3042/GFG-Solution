//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    private:
    int findPosition(int in[],int element ,int inorderStart,int inorderEnd){
        for(int i =inorderStart ; i<= inorderEnd;i++){
            if(in[i] == element) return i;
        }
        return -1;
    }
    Node* solve(int in[],int post[],int &postIndex , int inorderStart,int inorderEnd , int n){
        // Base Case
        if(postIndex < 0|| inorderStart> inorderEnd){
            return nullptr;
        }
        int element = post[postIndex--]; // At every interation index is decreasing
        Node* root = new Node(element);
        int positionIn = findPosition(in,element,inorderStart,inorderEnd);

        //  Following right part First then then last part because LRN postOrder Format
        // Recursive Call         
        // Right Call 
        root->right = solve(in,post,postIndex,positionIn+1,inorderEnd,n);
    //  Left Call
        root->left = solve(in,post,postIndex,inorderStart,positionIn-1,n);

        
    return root;
    }
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        int postIndex = n-1;//Post order is LRN so last element is root .
        Node* ans = solve(in,post,postIndex,0,n-1,n);
        return ans;
        // Your code here
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends