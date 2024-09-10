#include <Stdio.h>
#include <stdlib.h>
#include <memory.h>


typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

int index;

void GenerateArrayTree(int* tree) {
	int list[15] = { 1,2,9,3,5,10,13,4,6,7,8,11,12,14,15 };

	for (int i = 0; i < 15; i++) {
		tree[i] = list[i];
	}

	for (int i = 0; i < 15; i++) {
		printf("%d ", tree[i]);s
	}
	printf("\n");
}

void ArrayPreOrder(int* tree, int index) {
	if (index >= 15)
		return;
	printf("  %d", tree[index]);
	ArrayPreOrder(tree, 2 * index + 1);
	ArrayPreOrder(tree, 2 * index + 2);
}


void ArrayInOrder(int* tree, int index) {
	if (index >= 15)
		return;
	ArrayInOrder(tree, 2 * index + 1);
	printf("  %d", tree[index]);
	ArrayInOrder(tree, 2 * index + 2);
}

void ArrayPostOrder(int* tree, int index) {
	if (index >= 15)
		return;
	ArrayPostOrder(tree, 2 * index + 1);
	ArrayPostOrder(tree, 2 * index + 2);
	printf("  %d", tree[index]);
}

void ArrayOrders(int* tree) {
	index = 0;
	ArrayPreOrder(tree, index);
	printf("\n");
	index = 0;
	ArrayInOrder(tree, index);
	printf("\n");
	index = 0;
	ArrayPostOrder(tree, index);
	printf("\n");
}


void PlaceNode(TreeNode* node, int direction, int data) {
	TreeNode* n;
	n = (TreeNode*)malloc(sizeof(TreeNode));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	if (direction == 0) {
		node->left = n;
	}
	else
		node->right = n;
}

void GenerateLinkTree(TreeNode* root) {
	PlaceNode(root, 0, 2);
	PlaceNode(root->left, 0, 3);
	PlaceNode(root->left->left, 0, 4);
	PlaceNode(root->left->left, 1, 6);
	PlaceNode(root->left, 1, 5);
	PlaceNode(root->left->right, 0, 7);
	PlaceNode(root->left->right, 1, 8);

	PlaceNode(root, 1, 9);
	PlaceNode(root->right, 0, 10);
	PlaceNode(root->right->left, 0, 11);
	PlaceNode(root->right->left, 1, 12);
	PlaceNode(root->right, 1, 13);
	PlaceNode(root->right->right, 0, 14);
	PlaceNode(root->right->right, 1, 15);

}

void LinkPreOrder(TreeNode* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		LinkPreOrder(root->left);
		LinkPreOrder(root->right);
	}
}


void LinkInOrder(TreeNode* root) {
	if (root != NULL) {
		LinkInOrder(root->left);
		printf("%d ", root->data);
		LinkInOrder(root->right);
	}
}


void LinkPostOrder(TreeNode* root) {
	if (root != NULL) {
		LinkPostOrder(root->left);
		LinkPostOrder(root->right);
		printf("%d ", root->data);
	}
}

void LinkOrders(TreeNode* root) {
	LinkPreOrder(root);
	printf("\n");
	LinkInOrder(root);
	printf("\n");
	LinkPostOrder(root);
	printf("\n");
}

int main() {
	int arr[15];
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = 1;

	GenerateArrayTree(arr);
	GenerateLinkTree(root);

	ArrayOrders(arr);
	LinkOrders(root);

	return 0;
}