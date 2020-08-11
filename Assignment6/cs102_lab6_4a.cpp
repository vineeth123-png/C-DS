#include<iostream>
using namespace std;
class node{
	public: int value;
		node* next;
};
class stack{
	public: node* head;
		stack(){
			cout<<"Creating a Stack"<<endl;
			head = NULL;
		}
		int isEmpty(){
			if(head == NULL)
				return 1;
			return 0;
		}
		int push(int value){
			if(insertAtFront(value))
				return 1;
			else
				return 0;
		}
		int top(){
			if(isEmpty())
				return 0;
			return head->value;
		}
		int pop(){
			if(isEmpty())
				return 0;
			int x = top();
			if(deleteNode(x))
				return x;
			else
				return 0;
		}
	private: int deleteNode(int value){
        //function to delete node
        //different test cases
        node* ptr = head;
        //case 1
        if(ptr == NULL)
                return 0;
        //bool check = false;
        //case 2
        if(ptr->value == value){
                head = head->next;
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
        node* temp  = head;
        while(temp->next != ptr && temp !=NULL)
        temp = temp->next;
        temp->next = ptr->next;
        delete ptr;
        return 1;
        }
	private: int insertAtFront(int value){
        //function to insert at front
        node* ptr = new node;
        ptr->value = value;
        ptr->next = head;
        head = ptr;
        return 1;
        }
};
int main(){
	stack k = stack();
        int check;
        do{
                //loop to take inputs
                cout<<"Type the numbers at beginning for the following tasks:"<<endl;
                cout<<"1.push a node in stack."<<endl;
                cout<<"2.pop a node of stack."<<endl;
                cout<<"3.print the top value of stack"<<endl;
                //cout<<"4.print the rear value of queue"<<endl;
                cout<<"To exit, press 0."<<endl;
                cin>>check;
                if(check==1){
                        cout<<"enter the value to be inserted:"<<endl;
                        cin>>check;
                        if(k.push(check))
                                cout<<"Element pushed."<<endl;
                        else
                                cout<<"Error"<<endl;
                        check = 1;
                }else if(check == 2){
                        check = k.pop();
                        if(check)
                                cout<<"Element popped:\t"<<check<<endl;
                        else
                                cout<<"Error"<<endl;
                        check = 2;
                }else if(check == 3){
                        check = k.top();
                        if(check)
                                cout<<"Front element:\t"<<check<<endl;
                        else
                                cout<<"Error"<<endl;
                        check = 3;
                }/*else if(check == 4){
                        check = k.rear();
                        if(check)
                                cout<<"Rear element:\t"<<check<<endl;
                        else
                                cout<<"Error"<<endl;
                        check = 4;
                }*/
        }while(check);
        return 0;
}

