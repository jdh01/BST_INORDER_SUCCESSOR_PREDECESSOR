#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* GetNewNode(int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = GetNewNode(data);
		return root;
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

Node* Find(Node* root, int data)
{
	if (root == NULL) return nullptr;
	else if (root->data == data) return root;
	else if (data <= root->data)
		return Find(root->left, data);
	else
		return Find(root->right, data);
}

Node* FindMin(Node* root)
{
	if (root == NULL) return NULL;
	while (root->left != NULL)
		root = root->left;
	return root;
}

Node* GetSuccessorPtr(Node* root, int data)
{
	Node* current = Find(root, data);
	if (current == NULL) return NULL;
	//Case 1: Node has right substree
	if (current->right != NULL) {
		return FindMin(current->right);
	}
	//Case 2: If there is no right substree
	else {
		Node* successor = NULL;
		Node* ancestor = root;
		while (ancestor != current) {
			if (current->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}

Node* GetPredecessorPtr(Node* root, int data)
{
	Node* current = Find(root, data);
	if (current == NULL) return NULL;
	//Case 1: Node has right substree
	if (current->right != NULL) {
		return FindMin(current->right);
	}
	//Case 2: If there is no right substree
	else {
		Node* successor = NULL;
		Node* ancestor = root;
		while (ancestor != current) {
			if (current->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}

int main()
{
	Node* root = NULL;

	root = Insert(root, 10);
	root = Insert(root, 5);
	root = Insert(root, 15);
	root = Insert(root, 14);
	root = Insert(root, 16);
	root = Insert(root, 4);
	root = Insert(root, 6);

	Node* GSP = GetSuccessorPtr(root, 6);
	std::cout << GSP->data << std::endl;

}