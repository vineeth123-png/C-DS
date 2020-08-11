#include<iostream>
using namespace std;
struct node{
        int value;
        struct node* next;
};
class queue{
	//here the head of the linked list acts like rear of a queue and the last node of the linked list is the front of queue
	//this class uses functions insertAtFront, deleteNode to carry out poeerations like enqueue and dequeue
	private: node* frontPtr;
	private: int isEmpty(){
		if(frontPtr == NULL)
			return 1;
		return 0;
	}
	public: queue(){
		cout<<"Starting a queue"<<endl;
		frontPtr = NULL;
	}
		queue(queue& q1){
			cout<<"Copying a queue"<<endl;

	public: int enqueue(int value){
			//uses insertAtFront function
		if(insertAtFront(value))
			return 1;
		else
			return 0;
	}
	public: int dequeue(){
		if(isEmpty()){
			cout<<"Queue is empty"<<endl;
			return 0;
		}
		node* ptr = frontPtr;
		while(ptr->next != NULL)
			ptr = ptr->next;
		int x = ptr->value;
		if(deleteNode(x))
			return x;
		else
			return 0;
	}
	public: int rear(){
			//discussed above in the first comment
		if(isEmpty())
			return 0;
		return frontPtr->value;
	}
	public: int front(){
			//discussed above
		if(isEmpty())
			return 0;
		node* ptr = frontPtr;
		while(ptr->next != NULL)
			ptr = ptr->next;
		return ptr->value;
        }
	private: int insertAtFront(int value){
        //function to insert at front
        node* ptr = new node;
        ptr->value = value;
        ptr->next = frontPtr;
        frontPtr = ptr;
        return 1;
        }
	private: int deleteNode(int value){
        //function to delete node
        //different test cases
        node* ptr = frontPtr;
        //case 1
        if(ptr == NULL)
                return 0;
        //bool check = false;
        //case 2
        if(ptr->value == value){
                frontPtr = frontPtr->next;
                delete ptr;
                return 1;
        }
        while(ptr != NULL){
                if(ptr->value == value)
                        break;
                ptr = ptr->next;
        }
        //case 3
        if(ptr == NULL)
        return 0;
        //case 4
        node* temp  = frontPtr;
        while(temp->next != ptr && temp !=NULL)
        temp = temp->next;
        temp->next = ptr->next;
        delete ptr;
	return 1;
	}
};
int main(){
	queue k = queue();
	int check;
	do{
                //loop to take inputs
                cout<<"Type the numbers at beginning for the following tasks:"<<endl;
                cout<<"1.enqueue a node at rear in queue."<<endl;
                cout<<"2.dequeue the top of linked list."<<endl;
                cout<<"3.print the top value of queue"<<endl;
		cout<<"4.print the rear value of queue"<<endl;
                cout<<"To exit, press 0."<<endl;
                cin>>check;
                if(check==1){
                        cout<<"enter the value to be inserted:"<<endl;
                        cin>>check;
                        if(k.enqueue(check))
                                cout<<"Element enqueued."<<endl;
                        else
                                cout<<"Error"<<endl;
			check = 1;
                }else if(check == 2){
			check = k.dequeue();
                        if(check)
                                cout<<"Element dequeued:\t"<<check<<endl;
                        else
                                cout<<"Error"<<endl;
			check = 2;
                }else if(check == 3){
			check = k.front();
			if(check)
                                cout<<"Front element:\t"<<check<<endl;
			else
				cout<<"Error"<<endl;
			check = 3;
		}else if(check == 4){
			check = k.rear();
                        if(check)
                                cout<<"Rear element:\t"<<check<<endl;
                        else
                                cout<<"Error"<<endl;
			check = 4;
		}
        }while(check);
        return 0;
}
