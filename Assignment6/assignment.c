#include <stdio.h>
#include<stdlib.h>
typedef struct node{
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
int deleteNode(node** root, int data);
int leftRotate(node** root);
int rightRotate(node** root);
int getHeight(node* root);
int getBalanceFactor(node* root);
int balanceAtNode(node** root);
int balanceAlongPath(node** root, node* ptr);
int* inOrderTraversal(node* root);
int* preOrderTraversal(node* root);
int* postOrderTraversal(node* root);
int main(void) {
  node* root = (node*)malloc(sizeof(node));
  root->left = NULL;
  root->right = NULL;
  printf("Enter a value: ");
  scanf("%d", &(root->data));
  int check;
  while(1){
    printf("1. addnode\n2. getMin\n3. getMax\n4. delMax\n5. delMin\n6. deleteNode\n7. empty\n8. Height\n9. BalanceFactorofRoot\n10. inOrderTraversal\n11. postOrderTraversal\n12. preOrderTraversal\n13. exit\n");
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
			printf("Invalid call\n");
	}
	else if (check == 5) {
		int data;
		if (deleteMin(&root, &data))
			printf("%d\n", data);
		else
			printf("Invalid call\n");
	}
	else if (check == 6) {
		int data;
		printf("Enter a value: ");
		scanf("%d", &data);
		if (deleteNode(&root, data))
			printf("%d\n", data);
		else
			printf("Invalid call\n");
	}
	else if (check == 7) {
		if (empty(root))
			printf("Empty\n");
		else
			printf("Not empty\n");
	}
	else if (check == 8)
		printf("%d\n", getHeight(root));
	else if (check == 9)
		printf("%d\n", getBalanceFactor(root));
	else if (check == 10) {
		int* ptr = inOrderTraversal(root);
		if (ptr[0] == 0)
			printf("Invalid call\n");
		int i = 1;
		while (i <= ptr[0]) {
			printf("%d\t", ptr[i]);
			i++;
		}
		printf("\n");
		free(ptr);
	}
	else if (check == 11) {
		int* ptr = postOrderTraversal(root);
		if (ptr[0] == 0)
			printf("Invalid call\n");
		int i = 1;
		while (i <= ptr[0]) {
			printf("%d\t", ptr[i]);
			i++;
		}
		printf("\n");
		free(ptr);
	}
	else if (check == 12) {
		int* ptr = preOrderTraversal(root);
		if (ptr[0] == 0)
			printf("Invalid call\n");
		int i = 1;
		while (i <= ptr[0]) {
			printf("%d\t", ptr[i]);
			i++;
		}
		printf("\n");
		free(ptr);
	}
	else if (check == 13)
		break;
    
    }
  return 0;
}
int empty(node* root){
  if(root == NULL)
  return 1;
  return 0;
}
int getHeight(node* root) {
	//change
	if (root == NULL)
		return -1;
	else if (root->left == NULL && root->right == NULL)
		return 0;
	else if (root->left == NULL || root->right == NULL) {
		if (root->left == NULL)
			return 1 + getHeight(root->right);
		else
			return 1 + getHeight(root->left);
	}
	else {
		int a = getHeight(root->left);
		int b = getHeight(root->right);
		if (a > b)
			return 1 + a;
		else
			return 1 + b;
	}
	return 0;
}
int getBalanceFactor(node* root) {
	return getHeight(root->left) - getHeight(root->right);
}
int rightRotate(node** root) {
	if (empty(*root))
		return 0;
	//change
	node* ptr = *root;
	node* ptr1 = (*root)->left;
	int data = ptr->data;
	ptr->data = ptr1->data;
	ptr1->data = data;
	ptr->left = ptr1->left;
	ptr1->left = ptr1->right;
	ptr1->right = ptr->right;
	ptr->right = ptr1;
	return 1;
}
int leftRotate(node** root) {
	if (empty(*root))
		return 0;
	//change
	node* ptr = (*root);
	node* ptr1 = (*root)->right;
	int data = ptr->data;
	ptr->data = ptr1->data;
	ptr1->data = data;
	ptr->right = ptr1->right;
	ptr1->right = ptr1->left;
	ptr1->left = ptr->left;
	ptr->left = ptr1;
	return 1;
}
int balanceAtNode(node** root) {
	int factor = getBalanceFactor(*root);
	if (factor == 0 || factor == 1 || factor == -1)
		return 1;
	//change
	else if (factor == 2) {
		int left = getBalanceFactor((*root)->left);
		if (left == 1)
			return rightRotate(root);
		else
			return leftRotate(&((*root)->left)) && rightRotate(root);
	}
	else if (factor == -2) {
		int right = getBalanceFactor((*root)->right);
		if (right == -1)
			return leftRotate(root);
		else
			return rightRotate(&((*root)->right)) && leftRotate(root);
	}
	return 0;
}
int balanceAlongPath(node** root, node* ptr) {
	node* temp = *root;
	int i;
	if ((*root) == ptr || ptr == NULL)
		return balanceAtNode(root);
	else if (temp->data > ptr->data) {
		temp = temp->left;
		i = balanceAlongPath(&temp, ptr);
	}
	else if (temp->data < ptr->data) {
		temp = temp->right;
		i = balanceAlongPath(&temp, ptr);
	}
	if (i == 0)
		return 0;
	return balanceAtNode(root);
}
int addNode(node** root, int data){
  node* ptr = (node*) malloc(sizeof(node));
  ptr->data = data;
  ptr->left = NULL;
  ptr->right = NULL;
  if((*root) == NULL){
    (*root) = ptr;
    return 1;
  }
  node* temp = (*root);
  while(1){
	  if (temp->data == data) {
		  free(ptr);
		  return 0;
	  }
    else if(temp->data < data){
    if(temp->right == NULL){
    break;
    }
    temp = temp->right;
    }
    else{
    if(temp->left == NULL){
    break;
    }
    temp = temp->left;
    }
  }
  if(temp->data > data){
    temp->left = ptr;
  }else{
    temp->right = ptr;
  }
  //change
  return balanceAlongPath(root, ptr);
}
int getMin(node* root, int* data){
  if(empty(root))
  return 0;
  while(root->left != NULL){
    root = root->left;
  }
  *data = root->data;
  return 1;
}
int getMax(node* root, int* data){
  if(empty(root))
  return 0;
  while(root->right != NULL){
    //printf("%d", root->data);
  root = root->right;
  }
  *data = root->data;
  return 1;
}
int deleteMin(node** root, int* data){
  if(empty(*root))
  return 0;
  if((*root)->left == NULL && (*root)->right == NULL){
    *data = (*root)->data;
    node* ptr = *root;
    *root = NULL;
    free(ptr);
    return 1;
  }
   node* ptr = *root;
   node* ptr1 = *root;
  while((ptr->left) != NULL)
    ptr = ptr->left;
  *data = ptr->data;
  while(ptr1->left != ptr)
    ptr1 = ptr1->left;
  if(ptr->right != NULL){
    ptr1->left = ptr->right;
  }else
  ptr1->left = NULL;
  free(ptr);
  return 1;
}
int deleteMax(node** root, int* data){
  if(empty(*root))
  return 0;
  if((*root)->left == NULL && (*root)->right == NULL){
    *data = (*root)->data;
    node* ptr = *root;
    *root = NULL;
    free(ptr);
    return 1;
  }
   node* ptr = *root;
   node* ptr1 = *root;
  while((ptr->right) != NULL)
    ptr = ptr->right;
  *data = ptr->data;
  while(ptr1->right != ptr)
  ptr1 = ptr1->right;
  if(ptr->left != NULL){
    ptr1->right = ptr->left;
  }else
  ptr1->right = NULL;
  free(ptr);
  return 1;
}
int deleteNode(node** root, int data){
  if(empty(*root))
  return 0;
  if((*root)->data == data){
    int num;
    if((*root)->left == NULL && (*root)->right == NULL){
		node* ptr = (*root);
		(*root) = NULL;
		free(ptr);
        return 1;
    }else if((*root)->right == NULL || (*root)->right == NULL){
		node* tmp = (*root);
		if ((*root)->right == NULL)
			(*root) = (*root)->left;
		else
			(*root) = (*root)->right;
		free(tmp);
      return balanceAlongPath(root, NULL);//change
    }else{
		node* ptr = (*root)->left;
		node* parent = *root;
		while (ptr->right != NULL)
			ptr = ptr->right;
		while (parent->right != parent)
			parent = parent->right;
		int c = deleteMax(&ptr, &num);
		(*root)->data = num;
      return balanceAlongPath(root, parent);//change
    }
  }
  node* ptr = *root;
  while(ptr != NULL && ptr->data != data){
    if(ptr->data > data)
    ptr = ptr->left;
    else if(ptr->data < data)
    ptr = ptr->right;
  }
  if(ptr == NULL)
  return 0;
  node* parent = *root;
  while (parent->left != ptr && parent->right != ptr) {
	  if (parent->data > data)
		  parent = parent->left;
	  else
		  parent = parent->right;
  }
  int num;
  if(ptr->left == NULL && ptr->right == NULL){//change
	  if (parent->left == ptr)
		  parent->left = NULL;
	  else
		  parent->right = NULL;
	  free(ptr);
    return balanceAlongPath(root, parent);
  }else if(ptr->right == NULL || ptr->left == NULL){//change
	  if (ptr->left == NULL) {
		  if (parent->left == ptr)
			  parent->left = ptr->right;
		  else
			  parent->right = ptr->right;
	  }
	  else {
		  if (parent->left == ptr)
			  parent->left = ptr->left;
		  else
			  parent->right = ptr->left;
	  }
	  free(ptr);
      return balanceAlongPath(root, parent);
  }else{
	  //change
	  node* tmp = ptr->left;
	  node* tmp1 = *root;
	  while (tmp->right != NULL)
		  tmp = tmp->right;
	  while (tmp1->right != tmp)
		  tmp1 = tmp1->right;
	  parent = tmp1;
	  if (deleteMax(&(ptr->left), &num)) {
		  ptr->data = num;
		  return balanceAlongPath(root, parent);
	  }
  }
  return 0;
}
int* inOrderTraversal(node* root) {
	//change
	int size = 1;
	int* left = NULL;
	int* right = NULL;
	if (empty(root)) {
		int* ptr = (int*)malloc(sizeof(int)*size);
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
	//change
	int size = 1;
	int* left = NULL;
	int* right = NULL;
	if (empty(root)) {
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
	//change
	int size = 1;
	int* left = NULL;
	int* right = NULL;
	if (empty(root)) {
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