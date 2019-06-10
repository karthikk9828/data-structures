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

bool IsSubtreeLesser(BstNode* root, int value) {

	if(root == NULL)
		return true;

	if(root -> data <= value &&
	   IsSubtreeLesser(root -> left, value) && 
	   IsSubtreeLesser(root -> right, value))
		return true;
	else
		return false;
}

bool IsSubtreeGreater(BstNode* root, int value) {

	if(root == NULL)
		return true;

	if(root -> data > value &&
	   IsSubtreeGreater(root -> left, value) && 
	   IsSubtreeGreater(root -> right, value))
		return true;
	else
		return false;
}

bool IsBinarySearchTree1(BstNode* root) {

	if(root == NULL)
		return true;

	if(IsSubtreeLesser(root -> left, root -> data) &&
	   IsSubtreeGreater(root -> right, root -> data) &&
	   IsBinarySearchTree1(root -> left) &&
	   IsBinarySearchTree1(root -> right))
	   	return true;
	else
		return false;
}

bool IsBSTutil(BstNode* root, int minValue, int maxValue) {

	if(root == NULL) 
		return true;

	if(root -> data < minValue && 
	   root -> data > maxValue &&
	   IsBSTutil(root -> left, minValue, root -> data) &&
	   IsBSTutil(root -> right, root -> data, maxValue))
		return true;
	else
		return false;
}

bool IsBinarySearchTree2(BstNode* root) {

	//return IsBSTutil(root, INT_MIN, INT_MAX);
	return IsBSTutil(root, -999999, 999999);
}

int FindMaxInLeftSubtree(BstNode* node) {

	int max = node -> data;

	while(node != NULL) {
		if(node -> data < max)
			max = node -> data;
		node = node -> left;
	}

	/*while(node != NULL) {
		if(node -> data > max)
			max = node -> data;

		FindMaxInLeftSubtree(node -> left);
		FindMaxInLeftSubtree(node -> right);
	}*/
	return max;
}

int FindMinInRightSubtree(BstNode* node) {

	int min = node -> data;

	while(node != NULL) {
		if(node -> data < min)
			min = node -> data;
		node = node -> right;
	}

	return min;
}

bool IsBinarySearchTree3(BstNode* root) {

	int maxInLeftSubtree = FindMaxInLeftSubtree(root -> left),
		minInRightSubtree = FindMinInRightSubtree(root -> right);

	if(root -> data >= maxInLeftSubtree &&
	   root -> data < minInRightSubtree)
		return true;
	else
		return false;
}

// Check if Inorder traversal is sorted
bool IsBinarySearchTree4(BstNode* root) {

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

	cout << IsBinarySearchTree1(root) << "\n";
	cout << IsBinarySearchTree2(root) << "\n";
	//cout << IsBinarySearchTree3(root) << "\n";
	return 0;

}