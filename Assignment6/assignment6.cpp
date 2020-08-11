#include<iostream>
using namespace std;
#include "node_normal.h"
#include<cstdio>
#include<cstdlib>
class binary_tree{
	node** root;
	int empty(){
		return root == NULL;
	}
	public:
	//constructor
	binary_tree(){
		*root = NULL;
	}
	binary_tree(node**rootIn){
		root = rootIn;

	}
	//value of leftmost node
	int getMin(int* data){
		node* root = *(this->root);
                if(empty())
                       return 0;
                while(root->left != NULL){
                       root = root->left;
                }
                *data = root->data;
                return 1;
       }
	//value of right most node
       int getMax(int* data){
	       node* root = *(this->root);
                if(empty())
                       return 0;
                while(root->right != NULL){
                //printf("%d", root->data);
                       root = root->right;
                }
                *data = root->data;
                return 1;
       }
       //method to add node
       int addNode(int data){
	       node** root = (this->root);
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
             //return balanceAlongPath(root, ptr);
	     return 1;
       }
       //method to delete the leftmost node
       int deleteMin(int* data){
               if(empty())
                       return 0;
	       node** root = (this->root);
               if((*root)->left == NULL && (*root)->right == NULL){
                       *data = (*root)->data;
                       node* ptr = *root;
                       *root = NULL;
                       delete ptr;
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
               delete ptr;
               return 1;
       }
       //method to delete the right most node
       int deleteMax(int* data){
               if(empty())
                       return 0;
	       node** root = (this->root);
               if((*root)->left == NULL && (*root)->right == NULL){
                       *data = (*root)->data;
                       node* ptr = *root;
                       *root = NULL;
                       delete ptr;
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
              delete ptr;
              return 1;
       }
       int deleteNode(int data){
              if(empty())
                      return 0;
	      node** root = (this->root);
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
                              //return balanceAlongPath(root, NULL);//change
			      return 1;
                      }else{
		              node* ptr = (*root)->left;
		              node* parent = *root;
		              while (ptr->right != NULL)
			              ptr = ptr->right;
		              while (parent->right != parent)
			              parent = parent->right;
			      binary_tree temp(&ptr);
		              int c = temp.deleteMax(&num);
		              (*root)->data = num;
                              return 1;
			      //return balanceAlongPath(root, parent);//change
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
	              delete ptr;
                      //return balanceAlongPath(root, parent);
		      return 1;
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
                      //return balanceAlongPath(root, parent);
		      return 1;
	        }else{
	              //change
	                     node* tmp = ptr->left;
	                     node* tmp1 = *root;
	                     while (tmp->right != NULL)
		                     tmp = tmp->right;
	                     while (tmp1->right != tmp)
		                     tmp1 = tmp1->right;
	                     parent = tmp1;
			     binary_tree temp(&(ptr->left));
	                     if (temp.deleteMax(&num)) {
		                     ptr->data = num;
		                     return 1;
				     //return balanceAlongPath(root, parent);
	                     }
                }
                return 0;
       }
       //deconstructor
       ~binary_tree(){
	       while(!empty()){
		       int c;
		       int x = deleteMax(&c);
	       }
       }
};
int main(){
	binary_tree b1;
	int c = b1.addNode(2);
	cout<<c<<endl;
	return 0;
}
