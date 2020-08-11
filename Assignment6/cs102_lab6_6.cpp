#include"cs102_lab6_5.hpp"
/*in this template binary class implementation, searching a element is invalid as
binary search works only when out tree has numerals. Hence, search and delete a particular node is
vague. Here, we delete all nodes when a destructor is called.*/
template<class T>
node<T>* createNode(T idx){
	node<T>* newnode=new(node<T>);
	newnode->val=idx;
	newnode->left=newnode->right=NULL;
	return newnode;
}

template <class T=double>
class binaryTree{
		public:
			node<T>* head;

			binaryTree(){
				head=NULL;
			}
			~binaryTree(){
				// postorder style delete
				deleteHelper((this)->head);

				cout<<"Deletion Completed"<<endl;//Just to check we deleted everything properly
			}
			void deleteHelper(node<T>* &ptr){
				if (ptr==NULL)
				return;

				deleteHelper(ptr->left);
				deleteHelper(ptr->right);

				delete ptr;
			}

			void PreOrderTraversal(node<T>* &root){
				if (root==NULL)
				return;

				cout<<root->val<<endl;
				PreOrderTraversal(root->left);
				PreOrderTraversal(root->right);
			}

			void InOrderTraversal(node<T>* &root){
				if (root==NULL)
				return;

				InOrderTraversal(root->left);
				cout<<root->val<<endl;
				InOrderTraversal(root->right);
			}

			void PostOrderTraversal(node<T>* &root){
				if (root==NULL)
				return;

				PostOrderTraversal(root->left);
				PostOrderTraversal(root->right);
				cout<<root->val<<endl;
			}

			int height(node<T>* &root){//assuming height of root is 1
				if (root==NULL)
				return 0;

				int ht=0;
				ht=max(1+height(root->left),1+height(root->right));
				return ht;
			}

			void preorder(node<T>* &root,int lvl,vector<vector<T> > &data){
				if (root==NULL)
				return;

				data[lvl].push_back(root->val);
				preorder(root->left,lvl+1,data);
				preorder(root->right,lvl+1,data);
			}

			T LeftMostId(node<T>* &root){
				if (root->left==NULL)
				return root->val;
				else{
					return (LeftMostId(root->left));
				}
			}
			T RightMostId(node<T>* &root){
				if (root->right==NULL)
				return root->val;
				else{
					return (RightMostId(root->right));
				}
			}
};


int main()
{
	//Note:As no relation on ids are given to form tree(eg., < or >).We have to manually form a binary tree
	{
		binaryTree<double> bt;

		//Formation
		bt.head=createNode(5.0);

		bt.head->left=createNode(1.0);
		bt.head->right=createNode(2.0);

		bt.head->left->right=createNode(7.0);

		bt.head->right->right=createNode(4.0);

		// Tree Looks like:
		//           5
		//         /  \
		//        1    2
		//      / \   / \
		//    (N)  7 (N)  4
		//
	    // pre: 5 1 7 2 4
	    // In: 1 7 5 2 4
	    // post: 7 1 4 2 5

		cout<<"Pre-Order"<<endl;
		bt.PreOrderTraversal(bt.head);

		cout<<"In-order"<<endl;
		bt.InOrderTraversal(bt.head);

		cout<<"Post=Order"<<endl;
		bt.PostOrderTraversal(bt.head);
	}
	return 0;
}
