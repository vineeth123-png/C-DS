#include<iostream>
using namespace std;
template<class T = long long int>
class Node{
	public:
	        T value;
	        Node<>* next;
		//constructors
		Node(){
			value = -1;
			next = NULL;
		}
		Node(T x){
			value = x;
			next = NULL;
		}
		Node(T x, Node<>* ptr){
			value = x;
			next = ptr;
		}
		~Node(){}
};
template<class T>
class LinkedList{
	Node<>* head;
	int nodeCount;
	int isEmpty(){
		if(head == NULL)
			return 1;
		return 0;
	}
	public:
	LinkedList(){
		head = NULL;
		nodeCount = 0;
	}
	int getNodeCount() const;
	LinkedList(LinkedList &l1){
		//nodeCount = l1.getNodeCount();
		head = NULL;
		nodeCount = 0;
		while(l1.getNodeCount() > 0){
			//cout<<"CCC"<<endl;
			int c = l1.deleteAtFront();
			//cout<<c<<"   "<<"ZZZ"<<endl;
			c = insert(c);
			//cout<<c<<"  "<<"AA"<<endl;
		}
		Node<>* ptr = head;
		while(ptr != NULL){
			l1.insert(ptr->value);
			ptr = ptr->next;
		}
	}
	int insertAtFront(int value){
		if(searchNode(value) != NULL){
			cout<<"Node is already present"<<endl;
			return 0;
		}
		Node<>* ptr = new Node<>(value, head);
		head = ptr;
		cout<<"Value "<<value<<" inserted at front."<<endl;
		nodeCount++;
		return 1;
	}
	int insert(int value){
		//cout<<"ACH"<<endl;
		if(isEmpty()){
			if(insertAtFront(value))
				return 1;
			else
				return 0;
		}
		//cout<<"ASDF"<<endl;
		if(searchNode(value) != NULL){
			cout<<"Node is already present"<<endl;
			return 0;
		}
		Node<>* ptr = new Node<>(value, NULL);
		//cout<<"AACD"<<endl;
		Node<>* temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		//cout<<"AQZ"<<endl;
		temp->next = ptr;
		nodeCount++;
		return 1;
	}
	int deleteAtFront(){
		if(isEmpty())
			return 0;
		Node<>* ptr = head;
		int v = ptr->value;
		head = head->next;
		delete ptr;
		cout<<"Front node deleted"<<endl;
		nodeCount--;
		return v;
	}
	//method to search whether a value is present in the list
	Node<>* searchNode(int value){
		Node<>* ptr;
		if(isEmpty()){
			//ptr = NULL;
			return NULL;
		}
		ptr = head;
		while(ptr != NULL && ptr->value != value)
			ptr = ptr->next;
		return ptr;
	}
	//method to delete a node
	int deleteNode(int value){
		Node<>* ptr = searchNode(value);
		if(ptr == NULL){
			cout<<"Node not present"<<endl;
			return 0;
		}
		if(ptr == head){
			if(deleteAtFront())
				return 1;
			else
				return 0;
		}
		cout<<"Value to be deleted "<<ptr->value<<endl;
		Node<>* temp = head;
		while(temp->next != ptr){
			temp = temp->next;
		}
		temp->next = ptr->next;
		delete ptr;
		nodeCount--;
		return 1;
	}
	//method to print all 
	void printList(){
		if(isEmpty()){
			cout<<"List is empty"<<endl;
			return;
		}
		Node<>* ptr = head;
		while(ptr != NULL){
			cout<<ptr->value<<"\t";
			ptr = ptr->next;
		}
		cout<<"end"<<endl;
	}
	//destructor
	~LinkedList(){
		//cout<<"Deleting the list"<<endl;
		if(!isEmpty()){
			Node<>* ptr = head;
			while(head != NULL){
				head = head->next;
				delete ptr;
				ptr = head;
			}
			nodeCount = 0;
		}
	}
};
//template<class T = long long int>
inline int LinkedList::getNodeCount() const{
                return nodeCount;
}

int main(){
	//statements to check the working of methods in class linkedlist
	LinkedList l;
	Node<>* ptr1 = l.searchNode(2);
	cout<<ptr1<<endl;
	int a = l.insert(1);
	int x = l.insertAtFront(2);
	l.printList();
	Node<>* ptr = l.searchNode(2);
	cout<<ptr->value<<endl;
	x = l.insertAtFront(2);
	ptr = l.searchNode(3);
	if(ptr == NULL)
		cout<<"NULL"<<endl;
	x = l.insertAtFront(3);
	x = l.deleteAtFront();
	x = l.insert(5);

	l.printList();
	//cout<<l.getNodeCount()<<endl;
	//x =l.deleteNode(2);
	//l.printList();
	//x = l.deleteAtFront();
	//cout<<x<<endl;
	//l.printList();
	LinkedList l2(l);
	l2.printList();
	l.printList();
	return 0;
}
