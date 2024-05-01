//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    bool isVowels(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')return true;
        return false;
    }
    void addToTail(Node* p,Node** head,Node** rear){
        if(!(*head)){
            *head=*rear=p;
        }
        else{
            (*rear)->next=p;
            *rear=p;
        }
        p->next=NULL;
    }
    struct Node* arrangeCV(Node* head) {
        if(!head->next)return head;
        Node* p=head,*q=NULL,*r;
        Node* vhead=NULL,*vrear=NULL;
        Node* chead=NULL,*crear=NULL;
        
        while(p){
            if(isVowels(p->data)){
                q=p;
                p=p->next;
                addToTail(q,&vhead,&vrear);
            }
            else{
                q=p;
                p=p->next;
                addToTail(q,&chead,&crear);
            }
        }
        if(vhead)vrear->next=chead;
        else return chead;
        return vhead;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends