#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

typedef TreeNode* element;

typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode *top;
} LinkedStackType;

int is_empty(LinkedStackType * s) {
	if (s->top == NULL)
		return 1;
	else
		return 0;
}

element peek(LinkedStackType* s) {
	if (is_empty(s))
		return NULL;
	return s->top->data;
}

void init(LinkedStackType* s) {
	s->top = NULL;
}

void push(LinkedStackType * s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
	printf("push(%d) ", s->top->data->data); //temp->data->data
}

element pop(LinkedStackType *s) {
	StackNode* temp = s->top;
	element data = temp->data;
	s->top = temp->link;
	printf("pop(%d) ", temp->data->data);
	free(temp);
	return data;
}

void PlaceNode(TreeNode* node, int direction, int data) {
	TreeNode* n = (TreeNode*)malloc(sizeof(TreeNode));
	n->data = data;
	n->left = NULL;
	n->right = NULL;

	if (direction == 0)
		node->left = n;
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

void LinkInOrder(TreeNode* root) {
	LinkedStackType s;
	TreeNode* nptr = root;

	init(&s);

	while (nptr != NULL || !is_empty(&s)) {
		while (nptr != NULL) {
			push(&s, nptr);
			nptr = nptr->left;
		}
		nptr = pop(&s);
		printf("visit(%d) \n", nptr->data);
		nptr = nptr->right;
	}

}

void LinkPreOrder(TreeNode* root) {
	LinkedStackType s;
	TreeNode* nptr = root;
	init(&s);
	while (nptr != NULL || !is_empty(&s)) {
		while (nptr != NULL) {
			push(&s, nptr);
			printf("visit(%d) \n", nptr->data);
			nptr = nptr->left;
		}
		nptr = pop(&s);
		nptr = nptr->right;
	}
}

void LinkPostOrder(TreeNode* root) {
	LinkedStackType s;
	TreeNode* nptr = root;
	TreeNode* temp = NULL;

	init(&s);

	while (nptr != NULL || !is_empty(&s)) {
		while (nptr != NULL) {
			push(&s, nptr);
			nptr = nptr->left;
		}

		nptr = peek(&s);


		if (nptr->right != NULL && temp != nptr->right)
			nptr = nptr->right;
		else {
			printf("visit(%d) \n", nptr->data);
			temp = nptr;
			pop(&s);
			nptr = NULL;
		}
	}
}

void LinkOrders(TreeNode* root) {
	printf("전위 순회 시작\n");
	LinkPreOrder(root);
	printf("중위 순회 시작\n");
	LinkInOrder(root);
	printf("후위 순회 시작\n");
	LinkPostOrder(root);
}

int main() {
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	GenerateLinkTree(root);

	LinkOrders(root);
	return 0;
}



