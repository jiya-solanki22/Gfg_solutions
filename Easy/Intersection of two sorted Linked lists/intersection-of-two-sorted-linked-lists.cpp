//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        Node *p1=head1, *p2=head2;
        Node *head=NULL, *tail=NULL;
        
        while(p1 && p2)
            if(p1->data > p2->data)
                // nodes dont match
                // moving to next node in list with smaller node
                p2 = p2->next;
            
            else if(p2->data > p1->data)
                // nodes dont match
                // moving to next node in list with smaller node
                p1 = p1->next;
            
            else
            {
                // nodes match
                
                if(head==NULL)
                    head = tail = new Node(p1->data);
                    // creating new head for intersection list
                else
                {
                    // appending new node at the end
                    tail->next = new Node(p1->data);
                    tail = tail->next;
                }
                p1 = p1->next;
                p2 = p2->next;
                // moving to next nodes in both lists
            }
        
        return head;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends