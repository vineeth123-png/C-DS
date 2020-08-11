#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;
int constructFromInOrderandPostOrder(int* inOrder, int* postOrder, int numOfNodes);
int constructFromInorderandPreOrder(int* inOrder, int* preOrder, int numOfNodes);
int* inOrderTraversal(node* root);
int* postOrderTraversal(node* root);
int* preOrderTraversal(node* root);
int addNode(node** root, int data);
int main() {
	int check;
	while (1) {
		printf("1. construct from inOrder and postOrder\n2. construct from inOrder and preOrder\n3. exit\n");
		scanf("%d", &check);
		if (check == 1) {
			int num, i;
			printf("Enter number of nodes\n");
			scanf("%d", &num);
			int* inOrder = (int*)malloc(sizeof(int) * num);
			int* postOrder = (int*)malloc(sizeof(int) * num);
			printf("Enter the inOrder elements one at a time: ");
			for (i = 0; i < num; i++)
				scanf("%d", &(inOrder[i]));
			printf("Enter the postOrder elements one at a time: ");
			for (i = 0; i < num; i++)
				scanf("%d", &(postOrder[i]));
			printf("%d\n", constructFromInOrderandPostOrder(inOrder, postOrder, num));
		}
		else if (check == 2){
			int num, i;
		printf("Enter number of nodes\n");
		scanf("%d", &num);
		int* inOrder = (int*)malloc(sizeof(int) * num);
		int* preOrder = (int*)malloc(sizeof(int) * num);
		printf("Enter the inOrder elements one at a time: ");
		for (i = 0; i < num; i++)
			scanf("%d", &(inOrder[i]));
		printf("Enter the preOrder elements one at a time: ");
		for (i = 0; i < num; i++)
			scanf("%d", &(preOrder[i]));
		printf("%d\n", constructFromInOrderandPostOrder(inOrder, preOrder, num));
	    }
		else if (check == 3)
			break;
	}
	return 0;
}
int constructFromInorderandPreOrder(int* inOrder, int* preOrder, int numOfNodes) {
	if (numOfNodes == 0)
		return 0;
	else if (numOfNodes == 1) {
		return 1;
	}
	else {
		node* root = NULL;
		int i = 0;
		while (i < numOfNodes) {
			int j = addNode(&root, preOrder[i]);
			if (j == 0)
				return 0;
			i++;
		}
		int* inorder = inOrderTraversal(root);
		i = 0;
		while (i < numOfNodes) {
			if (inorder[i + 1] != inOrder[i])
				return 0;
			i++;
		}
		return 1;
	}
	return 0;
}
int constructFromInOrderandPostOrder(int* inOrder, int* postOrder, int numOfNodes) {
	if (numOfNodes == 0)
		return 0;
	else if (numOfNodes == 1) {
		return 1;
	}
	else {
		node* root = NULL;
		int i = numOfNodes - 1;
		while (i >= 0) {
			int j = addNode(&root, postOrder[i]);
			if (j == 0)
				return 0;
			i--;
		}
		int* inorder = inOrderTraversal(root);
		i = 0;
		while (i < numOfNodes) {
			if (inorder[i+1] != inOrder[i])
				return 0;
			i++;
		}
		return 1;
	}
	return 0;
}
int addNode(node** root, int data) {
	node* ptr = (node*)malloc(sizeof(node));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	if ((*root) == NULL) {
		(*root) = ptr;
		return 1;
	}
	node* temp = (*root);
	while (1) {
		if (temp->data == data) {
			free(ptr);
			return 0;
		}
		else if (temp->data < data) {
			if (temp->right == NULL) {
				break;
			}
			temp = temp->right;
		}
		else {
			if (temp->left == NULL) {
				break;
			}
			temp = temp->left;
		}
	}
	if (temp->data > data) {
		temp->left = ptr;
		return 1;
	}
	else {
		temp->right = ptr;
		return 1;
	}
	return 0;
}
int* inOrderTraversal(node* root) {
	int size = 1;
	int* left = NULL;
	int* right = NULL;
	if (root == NULL) {
		int* ptr = (int*)malloc(sizeof(int) * size);
		ptr[0] = 0;
		return ptr;
	}
	else {
		size++;
		if (root->left != NULL) {
			left = inOrderTraversal(root->left);
			size += left[0];
		}
		if (root->right != NULL) {
			right = inOrderTraversal(root->right);
			size += right[0];
		}
		int* ptr = (int*)malloc(sizeof(int) * size);
		ptr[0] = 1;
		int i = 1;
		if (left != NULL) {
			ptr[0] += left[0];
			while (i <= left[0]) {
				ptr[i] = left[i];
				i++;
			}
			free(left);
		}
		ptr[i] = root->data;
		i++;
		if (right != NULL) {
			ptr[0] += right[0];
			int j = 1;
			while (j <= right[0]) {
				ptr[i] = right[j];
				i++;
				j++;
			}
			free(right);
		}
		return ptr;
	}
	return NULL;
}
int* postOrderTraversal(node* root) {
	int size = 1;
	int* left = NULL;
	int* right = NULL;
	if (root == NULL) {
		int* ptr = (int*)malloc(sizeof(int));
		ptr[0] = 0;
		return ptr;
	}
	else {
		size++;
		if (root->left != NULL) {
			left = postOrderTraversal(root->left);
			size += left[0];
		}
		if (root->right != NULL) {
			right = postOrderTraversal(root->right);
			size += right[0];
		}
		int* ptr = (int*)malloc(sizeof(int) * size);
		ptr[0] = 1;
		int i = 1;
		if (left != NULL) {
			ptr[0] += left[0];
			while (i <= left[0]) {
				ptr[i] = left[i];
				i++;
			}
			free(left);
		}
		if (right != NULL) {
			ptr[0] += right[0];
			int j = 1;
			while (j <= right[0]) {
				ptr[i] = right[j];
				i++;
				j++;
			}
			free(right);
		}
		ptr[i] = root->data;
		return ptr;
	}
	return NULL;
}
int* preOrderTraversal(node* root) {
	int size = 1;
	int* left = NULL;
	int* right = NULL;
	if (root == NULL) {
		int* ptr = (int*)malloc(sizeof(int));
		ptr[0] = 0;
		return ptr;
	}
	else {
		size++;
		if (root->left != NULL) {
			left = postOrderTraversal(root->left);
			size += left[0];
		}
		if (root->right != NULL) {
			right = postOrderTraversal(root->right);
			size += right[0];
		}
		int* ptr = (int*)malloc(sizeof(int) * size);
		ptr[0] = 1;
		ptr[1] = root->data;
		int i = 2;
		if (left != NULL) {
			ptr[0] += left[0];
			int j = 1;
			while (j <= left[0]) {
				ptr[i] = left[j];
				i++;
				j++;
			}
			free(left);
		}
		if (right != NULL) {
			ptr[0] += right[0];
			int j = 1;
			while (j <= right[0]) {
				ptr[i] = right[j];
				i++;
				j++;
			}
			free(right);
		}
		return ptr;
	}
	return NULL;
}