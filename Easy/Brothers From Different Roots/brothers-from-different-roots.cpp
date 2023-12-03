//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        if (root1 == NULL || root2 == NULL)return 0;
        
        //creating two stacks to store nodes from each BST.
        stack<Node*> st1, st2;
        Node* top1, *top2;
        int count = 0;
        
        //iterating over the BSTs and storing nodes in stacks.
        while (1) {
            while (root1 != NULL) {
                st1.push(root1);
                root1 = root1->left;
            }
            while (root2 != NULL) {
                st2.push(root2);
                root2 = root2->right;
            }
            //if any of the stack is empty, break the loop.
            if (st1.empty() || st2.empty())break;
            
            //taking the top elements from both stacks.
            top1 = st1.top();
            top2 = st2.top();
            
            //if the sum of data of both nodes is equal to x.
            if ((top1->data + top2->data) == x) {
                //incrementing count and popping both elements from stack.
                count++;
                st1.pop();
                st2.pop();
                //updating the roots of BSTs.
                root1 = top1->right;
                root2 = top2->left;
            }
            //if the sum is less than x, pop the top from stack1 and move root1 to right.
            else if ((top1->data + top2->data) < x) {
                st1.pop();
                root1 = top1->right;
            }
            //if the sum is greater than x, pop the top from stack2 and move root2 to left.
            else {
                st2.pop();
                root2 = top2->left;
            }
        }
        //returning the count of pairs.
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}

// } Driver Code Ends