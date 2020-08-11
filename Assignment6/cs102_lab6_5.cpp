#include<iostream>
using namespace std;
template<class T>
class Node{
	public:
	Node<T>* previous;
	T value;
	Node<T>* next;
	//constructors
	Node(T val = -1){
		value = val;
		previous = NULL;
		next = NULL;
	}
	Node(T valIn, Node* pre, Node* ne){
		previous = pre;
		value = valIn;
		next = ne;
	}
	//deconstructor
	~Node(){}
};
int main(){
	Node<int> a;
	Node<int> a1(9, NULL, NULL);
	cout<<a.value<<"  "<<a1.value<<endl;
	return 0;
}
