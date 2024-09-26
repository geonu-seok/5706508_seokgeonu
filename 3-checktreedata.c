#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

typedef TreeNode* element;

typedef struct QueueNode { 
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {
	QueueNode* front, * rear;
}LinkedQueueType;


void init(LinkedQueueType* q) {
	q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {
	return q->front == NULL;
}

void enqueue(LinkedQueueType* q, element data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}

element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) {		
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		data = temp->data; 
		q->front = q->front->link; 
		if (q->front == NULL) 	
			q->rear = NULL;
		free(temp); 		
		return data; 		
	}
}

int queue_size(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	int count = 0;
	while (temp) {
		count++;
		temp = temp->link;
	}
	return count;
}

int node_sum;

void GetHeightOfTree(TreeNode* root) {
	if (root == NULL)
		return 0;

	LinkedQueueType q;
	init(&q);
	TreeNode* ptr = root;
	int height = 0;

	enqueue(&q, ptr);

	while (!is_empty(&q)) {
		int levelSize = queue_size(&q);
		height++;

		for (int i = 0; i < levelSize; i++) {
			ptr = dequeue(&q);


			if (ptr->left != NULL) {
				enqueue(&q, ptr->left);
			}

			if (ptr->right != NULL) {
				enqueue(&q, ptr->right);
			}
		}
	}

	printf("Height of Tree: %d\n", height);
}


void GetNemberOfNodes(TreeNode* root) {
	int count = 0;
	int node_sum = 0;
	LinkedQueueType q;
	TreeNode* ptr = root;
	init(&q);

	if (root == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		node_sum += ptr->data;
		count++;

		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
	printf("Number of nodes: %d\n", count);
}


void GetSumOfNodes(TreeNode* root)
{

	int node_sum = 0;
	LinkedQueueType q;
	TreeNode* ptr = root;
	init(&q);

	if (root == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		node_sum += ptr->data;
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
	printf("Sum of nodes: %d\n", node_sum);

}

void GetNumberOfLeafNodes(TreeNode* root) {
	if (root == NULL)
		return 0;

	LinkedQueueType q;
	init(&q);
	TreeNode* ptr = root;
	int leafCount = 0;

	enqueue(&q, ptr);

	while (!is_empty(&q)) {
		ptr = dequeue(&q);

		if (ptr->left == NULL && ptr->right == NULL) {
			leafCount++;
		}

		if (ptr->left != NULL) {
			enqueue(&q, ptr->left);
		}

		if (ptr->right != NULL) {
			enqueue(&q, ptr->right);
		}
	}

	printf("Number of leaf nodes: %d\n", leafCount);
}

void PlaceNode(TreeNode* parent, int direction, int data) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	if (direction == 0) {
		parent->left = newNode;
	}
	else if (direction == 1) {
		parent->right = newNode;
	}
}

TreeNode n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15;

void GenerateLinkTree(TreeNode* root) {
	PlaceNode(root, 0, 2);
	PlaceNode(root, 1, 9);
	PlaceNode(root->left, 0, 3);
	PlaceNode(root->left, 1, 5);
	PlaceNode(root->right, 0, 10);
	PlaceNode(root->right, 1, 13);
	PlaceNode(root->left->left, 0, 4);
	PlaceNode(root->left->left, 1, 6);
	PlaceNode(root->left->right, 0, 7);
	PlaceNode(root->left->right, 1, 8);
	PlaceNode(root->right->left, 0, 11);
	PlaceNode(root->right->left, 1, 12);
	PlaceNode(root->right->right, 0, 14);
	PlaceNode(root->right->right, 1, 15);
}

main() {
	TreeNode n1 = { NULL, NULL,NULL };
	TreeNode* root = &n1;
	root->data = 1;

	GenerateLinkTree(root);

	GetSumOfNodes(root);
	GetNemberOfNodes(root);
	GetHeightOfTree(root);
	GetNumberOfLeafNodes(root);


}
