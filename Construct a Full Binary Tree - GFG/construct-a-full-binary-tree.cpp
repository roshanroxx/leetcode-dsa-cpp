//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
  
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        return pp(pre,preMirror,0,size-1,0,size-1);
    }
    Node* pp(int pre[], int preMirror[],int l1,int r1,int l2 ,int r2){
        if(l1>r1 || l2>r2){
            return NULL;
        }
        Node* root = new Node(pre[l1]);
        if(l1==r1){
            return root;
        }
        
        else{
            int l,r;
            for(int i=l2;i<=r2;i++){
                if(pre[l1+1]==preMirror[i]){
                    l=i;
                    break;
                }
            }
            for(int i=l1;i<=r1;i++){
                if(preMirror[l2+1]==pre[i]){
                    r=i;
                    break;
                }
            }
            root->left = pp(pre,preMirror,l1+1,r-1,l,r2);
            root->right = pp(pre,preMirror,r,r1,l2+1,l-1);
            
        }
        return root;
        
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends