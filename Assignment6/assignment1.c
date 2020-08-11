#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;
int addNode(node** root, int data);
int getMax(node* root, int* data);
int getMin(node* root, int* data);
int empty(node* root);
int deleteMin(node** root, int* data);
int deleteMax(node** root, int* data);
//int deleteNode(node** root, int data);

int main() {
	node* root = (node*)malloc(sizeof(node));
	root->left = NULL;
	root->right = NULL;
	printf("Enter a value: ");
	scanf("%d", &(root->data));
	int check;
	while (1) {
		printf("1. addnode\n2. getMin\n3. getMax\n4. delMax\n5. delMin\n6. deleteNode\n7. empty\n8. exit\n");
		scanf("%d", &check);
		if (check == 1) {
			printf("Enter a number: ");
			int i;
			scanf("%d", &i);
			if (addNode(&root, i))
				printf("yes\n");
			else
				printf("no\n");
		}
		else if (check == 3) {
			int data;
			if (getMax(root, &data))
				printf("%d\n", data);
			else
				printf("Invalid call\n");
		}
		else if (check == 2) {
			int data;
			if (getMin(root, &data))
				printf("%d\n", data);
			else
				printf("Invalid call\n");
		}
		else if (check == 4) {
			int data;
			if (deleteMax(&root, &data))
				printf("%d\n", data);
			else
				printf("Invalid cvall\n");
		}
		else if (check == 5) {
			int data;
			if (deleteMin(&root, &data))
				printf("%d\n", data);
			else
				printf("Invalid cvall\n");
		}
		/*else if (check == 6) {
			int data;
			printf("Enter a value: ");
			scanf("%d", &data);
			if (deleteNode(&root, data))
				printf("%d\n", data);
			else
				printf("Invalid cvall\n");
		}*/
		else if (check == 7) {
			if (empty(root))
				printf("Empty\n");
			else
				printf("Not empty\n");
		}
		else if (check == 8)
			break;
	}
	return 0;
}
int empty(node* root) {
	if (root == NULL)
		return 1;
	return 0;
}
int getMin(node* root, int* data) {
	if (empty(root))
		return 0;
	while (root->left != NULL) {
		root = root->left;
	}
	*data = root->data;
	return 1;
}
int getMax(node* root, int* data) {
	if (empty(root))
		return 0;
	while (root->right != NULL) {
		root = root->right;
	}
	*data = root->data;
	return 1;
}
int addNode(node** root, int data) {
	node* ptr = (node*)malloc(sizeof(node));
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->data = data;
	if (empty(*root)) {
		*root = ptr;
		return 1;
	}
	node* temp = *root;
	while (!(temp->right == NULL && temp->left == NULL)) {
		if (temp->data > data) {
			if (temp->left != NULL)
				break;
			temp = temp->left;
		}
		else if (temp->data < data) {
			if (temp->right != NULL)
				break;
			temp = temp->right;
		}
		else
			return 0;
	}
	if (temp->data < data) {
		temp->right = ptr;
		return 1;
	}
	else {
		temp->left = ptr;
		return 1;
	}
	return 0;
}
int deleteMin(node** root, int* data) {
	if (empty(*root))
		return 0;
	node* temp = *root;
	if (temp->left == NULL && temp->right == NULL) {
		*root = NULL;
		*data = temp->data;
		free(temp);
		return 1;
	}
	node* temp1 = *root;
	while (temp->left != NULL)
		temp = temp->left;
	while (temp1->left != temp)
		temp1 = temp1->left;
	*data = temp->data;
	if(temp->right != NULL){
		temp1->left = temp->right;
		free(temp);
		return 1;
	}
	else {
		temp1->left = NULL;
		free(temp);
		return 1;
	}
	return 0;
}
int deleteMax(node** root, int* data) {
	if (empty(*root))
		return 0;
	node* temp = *root;
	if (temp->left == NULL && temp->right == NULL) {
		*root = NULL;
		*data = temp->data;
		free(temp);
		return 1;
	}
	node* temp1 = *root;
	while (temp->right != NULL)
		temp = temp->right;
	while (temp1->right != temp)
		temp1 = temp1->right;
	*data = temp->data;
	if (temp->left != NULL) {
		temp1->right = temp->left;
		free(temp);
		return 1;
	}
	else {
		temp1->right = NULL;
		free(temp);
		return 1;
	}
	return 0;
}
int deleteNode(node** root, int data) {
	if (empty(*root))
		return 0;
	if ((*root)->data == data) {
		int num;
		if ((*root)->left != NULL) {
			node* ptr = (*root)->left;
			int c = deleteMax(&ptr, &num);
			(*root)->data = num;
			return 1;
		}
		else if ((*root)->right != NULL) {
			node* ptr = (*root)->right;
			int c = deleteMin(&ptr, &num);
			(*root)->data = num;
			return 1;
		}
		else {
			node* ptr = (*root);
			(*root) = NULL;
			free(ptr);
			return 1;
		}
	}

}
