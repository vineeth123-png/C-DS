#include<iostream>
using namespace std;
template<class T = long long int>
class Node{
        public:
                T value;
                Node<T>* next;
                //constructors
                Node(){
                        value = -1;
                        next = NULL;
                }
                Node(T x){
                        value = x;
                        next = NULL;
                }
                Node(T x, Node<T>* ptr){
                        value = x;
                        next = ptr;
                }
                ~Node(){}
};
int main(){
	//Node<> a;
	Node<int> f1(3);
	Node<int> i1(2, &f1);
	cout<<i1.next->value<<endl;
	return 0;
}

