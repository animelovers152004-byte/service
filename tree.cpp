#include <iostream> 
using namespace std; 
 
struct Node 
{ 
    int data; 
    Node *left, *right; 
 
    Node(int value) 
    { 
        data = value; 
        left = right = NULL; 
    } 
}; 
 
Node *insert(Node *root, int value) 
{ 
    if (root == NULL) 
        return new Node(value); 
 
    if (value < root->data) 
        root->left = insert(root->left, value); 
    else if (value > root->data) 
        root->right = insert(root->right, value); 
 
    return root; 
} 
 
int height(Node *root) 
{ 
    if (root == NULL) 
        return 0; 
    int leftHeight = height(root->left); 
    int rightHeight = height(root->right); 
    return max(leftHeight, rightHeight) + 1; 
} 
 

int findMin(Node *root) 
{ 
    if (root == NULL) 
    { 
        cout << "Tree is empty!" << endl; 
        return -1; 
    } 
    while (root->left != NULL) 
        root = root->left; 
    return root->data; 
} 
 

void mirror(Node *root) 
{ 
    if (root == NULL) 
        return; 
    
    Node *temp = root->left; 
    root->left = root->right; 
    root->right = temp; 
 
    
    mirror(root->left); 
    mirror(root->right); 
} 
 

bool search(Node *root, int key) 
{ 
    if (root == NULL) 
        return false; 
    if (root->data == key) 
        return true; 
    else if (key < root->data) 
        return search(root->left, key); 
    else 
        return search(root->right, key); 
} 
 
 
void inorder(Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout << root->data << " "; 
        inorder(root->right); 
    } 
} 
 

int main() 
{ 
    Node *root = NULL; 
    int n, value; 
 
    cout << "Enter number of elements to insert initially: "; 
    cin >> n; 
 
    cout << "Enter values: "; 
    for (int i = 0; i < n; i++) 
    { 
        cin >> value; 
        root = insert(root, value); 
    } 
 
    cout << "\nInorder traversal of BST: "; 
    inorder(root); 
    cout << endl; 
 
    
    cout << "\nEnter value to insert: "; 
    cin >> value; 
    root = insert(root, value); 
 
    cout << "Inorder after insertion: "; 
    inorder(root); 
    cout << endl; 
 
   
    cout << "\nNumber of nodes in longest path (Height): " << height(root) << endl; 
 
   
    cout << "Minimum value in BST: " << findMin(root) << endl; 
 
    
    cout << "\nEnter value to search: "; 
    cin >> value; 
    if (search(root, value)) 
        cout << value << " found in BST!" << endl; 
    else 
        cout << value << " not found in BST!" << endl; 
 
  
    mirror(root); 
    cout << "Inorder traversal after mirroring: "; 
    inorder(root); 
    cout << endl; 
 
    return 0; 
} 

