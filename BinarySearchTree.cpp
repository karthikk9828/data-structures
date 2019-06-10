#include<iostream>
#include<queue>
using namespace std;

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();

	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;

	return newNode;
}

BstNode* Insert(BstNode* root, int data) {

	if(root == NULL)   // if the tree is empty
		root = GetNewNode(data);

	else if(data <= root -> data)
		root -> left = Insert(root -> left, data);
	else
		root -> right = Insert(root -> right, data);

	return root;
}

bool Search(BstNode* root, int data) {

	if(root == NULL)
		return false;

	if(root -> data == data)
		return true;

	else if(data <= root -> data)
		return Search(root -> left, data);

	else
		return Search(root -> right, data);

	return false;
}

// LEVEL OREDRE TRAVERSAL OF BINARY SEARCH TREE
void LevelOrderTraversal(BstNode * root) {

	if(root == NULL) 
		return;

	queue<BstNode*> Q;

	Q.push(root);  // initially push the address of the root node into the queue 

	while(!Q.empty()) {

		BstNode* current = Q.front();
		cout << current -> data << " ";

		if(current -> left != NULL)
			Q.push(current -> left);
		if(current -> right != NULL)
			Q.push(current -> right);

		Q.pop();  // remove the element at the front
	}
}

//PREORDER TRAVERSAL OF BINARY SEARCH TREE
void PreOrder(BstNode* root) {

	if(root == NULL) 
		return;

	cout << root -> data << " ";
	PreOrder(root -> left);
	PreOrder(root -> right);
}

//INORDER TRAVERSAL OF BINARY SEARCH TREE
void InOrder(BstNode* root) {

	if(root == NULL) 
		return;

	InOrder(root -> left);
	cout << root -> data << " ";
	InOrder(root -> right);
}

//POSTORDER TRAVERSAL OF BINARY SEARCH TREE
void PostOrder(BstNode* root) {

	if(root == NULL) 
		return;

	PostOrder(root -> left);
	PostOrder(root -> right);
	cout << root -> data << " ";
}
 
// find minimum element of BST using iterative approach
int FindMin(BstNode* root) {

	if(root == NULL) {
		cout << "Error: Tree is empty\n";
		return -1;
	}
	while(root -> left != NULL)
		root = root -> left;

	return root -> data;
}

// find maximum element of BST using iterative approach
int FindMax(BstNode* root) {

	if(root == NULL) {
		cout << "Error: Tree is empty\n";
		return -1;
	}
	while(root -> right != NULL)
		root = root -> right;

	return root -> data;
}

// find minimum element of BST using recursion
int FindMinUsingRecursion(BstNode* root) {

	if(root == NULL) {
		cout << "Error: Tree is empty\n";
		return -1;
	}
	
	else if(root -> left == NULL)
		return root -> data;

	else
		return FindMin(root -> left);
}

// find minimum element of BST using recursion
int FindMaxUsingRecursion(BstNode* root) {

	if(root == NULL) {
		cout << "Error: Tree is empty\n";
		return -1;
	}
	
	else if(root -> right == NULL)
		return root -> data;

	else
		return FindMin(root -> right);
}

// find height of the binary tree
int FindHeight(BstNode* root) {

	int leftHeight = 0, rightHeight = 0;

	if(root == NULL)
		return -1;   // tree is empty, height of empty tree is -1

	return max(FindHeight(root -> left), FindHeight(root -> right)) + 1;

	/*leftHeight = FindHeight(root -> left);
	rightHeight = FindHeight(root -> right);

	return max(leftHeight, rightHeight) + 1;*/
}

// find minimum value in right subtree
BstNode* MinimumInRightSubtree(BstNode* root) {

	while(root -> left != NULL)
		root = root -> left;

	return root;
}

// delete a node from BST
BstNode* Delete(BstNode* root, int data) {

	// search for the node to be deleted
	if(root == NULL)
		return root;

	else if(data < root -> data)
		root -> left = Delete(root -> left, data);

	else if(data > root -> data) 
		root -> right = Delete(root -> right, data);

	else { // we have found the node to be deleted 
		
		// Case 1: Node to be deleted is a leaf node
		if(root -> left == NULL && root -> right == NULL) {
			delete root;
			root = NULL;
		}

		// Case 2: Node to be deleted has only one child
		// has right child
		else if(root -> left == NULL) {
			BstNode* temp = root;
			root = root -> right;
			delete temp;
		}

		// has left child
		else if(root -> right == NULL) {
			BstNode* temp = root;
			root = root -> left;
			delete temp;
		}

		// Case 3: Node to be deleted has two children
		else {
			BstNode* temp = MinimumInRightSubtree(root -> right);
			root -> data = temp -> data;
			root -> right = Delete(root -> right, temp -> data);
		}
	}
	return root;
}

// find inorder successor of a node
int GetInorderSuccessor(BstNode* root, int data) {

	// search the node
	BstNode* current = Search(root, data);

	if(current == NULL)
		return NULL;

	// Case 1: Node has right subtree
	if(current -> right != NULL)
		return FindMin(current -> right);

	// Case 2: No right subtree
	else {
		BstNode* successor = NULL,
				 ancestor = root;

		while(ancestor != NULL) {
			if(current -> data < ancestor -> data) {
				successor = ancestor;
				ancestor = ancestor -> left;
			}
			else
				ancestor = ancestor -> right;
		}
		return successor -> data;
	}
}

int main() {

	BstNode* root = NULL;

	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	root = Insert(root, 17); 

	int number;

	cout << "Enter number to be searched: ";
	cin >> number;

	if(Search(root, number))
		cout << "Found\n";
	else
		cout << "Not found\n";

	// find minimum value
	//cout << "Minimum: " << FindMin(root) << "\n";

	// find maximum value 
	//cout << "Maximum: " << FindMax(root) << "\n";

	// find height of the tree
	//cout << "Height: " << FindHeight(root) << "\n";

	cout << "\n\nLevelOrderTraversal is: \n";
	LevelOrderTraversal(root);

	cout << "\n\nPreOrder Traversal is: \n";
	PreOrder(root);

	cout << "\n\nInOrder Traversal is: \n";
	InOrder(root);

	cout << "\n\nPostOrder Traversal is: \n";
	PostOrder(root);

	// delete a node from BST
	root = Delete(root , 15);

	// level order traversal after deleting 15
	cout << "\n\nLevel order traversal after deleting 15\n";
	LevelOrderTraversal(root);

	// inorder successor of 12
	int succ = GetInorderSuccessor(root, 12);
	cout << "\n\nInOrder successor of 12 : " << succ << "\n";

	return 0;
}
