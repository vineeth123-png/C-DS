#include<iostream>
using namespace std;
class node{
        public:
        node* left;
        int data;
        node* right;
        //constructors
        node(int val = -1){
                data = val;
                left = NULL;
                right = NULL;
        }
        node(int valIn, node* pre, node* ne){
                left = pre;
                data = valIn;
                right = ne;
        }
        //deconstructor
        ~node(){}
};
class binary_tree{
	//root
	node* head;
	int isEmpty(){
		return head == NULL;
	}
	public:
	//constructor
	binary_tree(){
		cout<<"Creating a tree normally"<<endl;
		head = NULL;
	}
	binary_tree(node* &headIn){
		cout<<"Creating a tree using a node ptr"<<endl;
		head = headIn;
	}
	private:
	//get the node of a given data 
	node* searchNode(int data){
		if(isEmpty())
			return NULL;
		node* ptr = head;
		//binary search
		while(ptr != NULL && ptr->data != data){
			if(ptr->data > data)
				ptr = ptr->right;
			else
				ptr = ptr->left;
		}
		return ptr;
	}
	public:
	//insert a node
	int insertNode(int data){
		node* ptr = new node(data);
		if(isEmpty()){
			head = ptr;
			cout<<"Successful Insertion"<<endl;
			return 1;
		}
		if(searchNode(data) != NULL){
			delete ptr;
			cout<<"data already present"<<endl;
			return 0;
		}else{
			node* temp = head;
			while(1){
			if(temp->data < data){
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
		       cout<<"Successful insertion"<<endl;	
		       return 1;
		}
	}
	//min Value in a tree, value recieved via referenced parameter
	int getMin(/*int &tempD*/){
		if(isEmpty()){
			cout<<"Tree is empty"<<endl;
			//tempD = -1;
			return -1;
		}
		node* temp = head;
		while(temp->left != NULL){
			temp = temp->left;
		}
		//tempD = temp->data;
		return temp->data;
	}
	//max value in a tree, value recieved via referenced parameter
	int getMax(/*int &tempD*/){
	        if(isEmpty()){
                        cout<<"Tree is empty"<<endl;
                        //tempD = -1;
                        return -1;
                }
                node* temp = head;
                while(temp->right != NULL){
                        temp = temp->right;
                }
                //tempD = temp->data;
		return temp->data;
	}
	//delete min Node, 0 for unsuccesful & 1 for successful 
	/*int deleteMin(int* data){
                if(isEmpty())
                        return 0;
                if(head->left == NULL && head->right == NULL){
                        *data = head->data;
                        node* ptr = head;
                        head = NULL;
			cout<<"Deleting a node"<<endl;
                        delete ptr;
                        return 1;
                }
                node* ptr = head;
                node* ptr1 =head;
                while((ptr->left) != NULL)
                        ptr = ptr->left;
                *data = ptr->data;
		int val;
		if(ptr == ptr1){
			binary_tree tree1(ptr->right);
			if(tree1.deleteMin(&val)){
				ptr->data = val;
				cout<<"Deleting a node in a new way"<<endl;
				return 1;
			}
			return 0;
		}
                while(ptr1->left != ptr)
                        ptr1 = ptr1->left;
                if(ptr->right != NULL){
                        ptr1->left = ptr->right;
                }else
                        ptr1->left = NULL;
		cout<<"Deleting a node"<<endl;
                delete ptr;
                return 1;
        }*/
	int deleteMin(int* data){
		if(isEmpty()){
			cout<<"Empty tree"<<endl;
			return 0;
		}
		*data = getMin();
		if(head->data == *data){
			if(head->right == NULL){
				node* ptr = head;
				delete ptr;
				return 1;
			}else{
				binary_tree tree(head->right);
				int v;
				tree.deleteMin(&v);
				head->data = v;
				return 1;
			}
		}
		while((head->left) != NULL){
			binary_tree tree(head->left);
			int v;
			int x = tree.deleteMin(&v);
		}
	}
	//delete max Node, 0 for unsuccesful & 1 for successful
	int deleteMax(int* data){
                if(isEmpty())
                        return 0;
                if(head->left == NULL && head->right == NULL){
                        *data = head->data;
                        node* ptr = head;
                        head = NULL;
                        cout<<"Deleting a node"<<endl;
                        delete ptr;
                        return 1;
                }
                node* ptr = head;
                node* ptr1 =head;
                while((ptr->right) != NULL)
                        ptr = ptr->right;
                *data = ptr->data;
                int val;
                if(ptr == ptr1){
                        binary_tree tree1(ptr->left);
                        if(tree1.deleteMin(&val)){
                                ptr->data = val;
                                cout<<"Deleting a node in a new way"<<endl;
                                return 1;
                        }
                        return 0;
                }
                while(ptr1->right != ptr)
                        ptr1 = ptr1->right;
                if(ptr->left != NULL){
                        ptr1->right = ptr->left;
                }else
                        ptr1->right = NULL;
                cout<<"Deleting a node"<<endl;
                delete ptr;
                return 1;
        }
	//delete a node
	/*int deleteNode(int data){
		node* ptr = searchNode(data);
		if(ptr == NULL)
			return -1;
	}*/
	//destructor
	~binary_tree(){
		cout<<"Ending a tree"<<endl;
		int v;
		while(!isEmpty())
			int x = deleteMin(&v);
	}
};
int main(){
	binary_tree b1;
	b1.insertNode(2);
	b1.insertNode(2);
	b1.insertNode(3);
	b1.insertNode(1);
	int value = 0;
	value = b1.getMin();
	cout<<"Min:"<<" "<<value<<endl;
	value = b1.getMax();
	cout<<"Max:"<<" "<<value<<endl;
	int x = b1.deleteMin(&value);
	cout<<x<<" "<<value<<" "<<b1.getMin()<<" "<<b1.getMax()<<endl;
	x = b1.deleteMin(&value);
        cout<<x<<" "<<value<<" "<<b1.getMin()<<" "<<b1.getMax()<<endl;
	return 0;
}
