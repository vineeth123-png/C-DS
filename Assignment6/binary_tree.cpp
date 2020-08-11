#include"node_double.cpp"
template <class T=int>
class binary_tree{
	private:
		//declaring generic head pointer
		node_double <T> *head;
	public:
		//constructor
		binary_tree(){
			head=NULL;
		}
		//to check wether the binary_tree is empty or not
		bool isEmpty(){
			if(head==NULL)return true;
			else return false;
		}



/////methode pending......................






		//copy constructor
		binary_tree(const binary_tree <T> &original){
			
		}
		//destructor
		void clear_destructor__(node_double &temp){
			if(temp!=NULL){
				clear_destructor__(temp->left);
				clear_destructor__(temp->right);
				temp=NULL;
			}
		}
		~binary_tree(){
			clear_destructor__(head);
		}
};
