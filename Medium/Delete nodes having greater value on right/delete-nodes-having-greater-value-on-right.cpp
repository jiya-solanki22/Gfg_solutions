//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node *curr = head;
        Node *prev = NULL;
        Node *nextNode;
    
        while(curr!=NULL)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
        Node *current = head;
        Node *maxNode = head;
        Node *temp;
         while (current != NULL && current->next != NULL)
         {
             if(current->next->data < maxNode->data)
             {
                 temp = current->next;
                 current->next = temp->next;
                 free(temp);
             }
             else
             {
                 current = current->next;
                 maxNode= current;
             }
         }
         curr = head;
         prev = NULL;
         nextNode;
         while(curr!=NULL)
         {
             nextNode = curr->next;
             curr->next = prev;
             prev = curr;
             curr = nextNode;
         }
         head = prev;
    
        return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends