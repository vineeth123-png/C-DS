#include<iostream>
#include<stdlib.h>


using namespace std;

class  node{
    public:
    int val;
    node* next;
};

#define MAX 1000 
  
class queue{ 
    int front;
    int rear; 
  
public: 
    int* a;  
  //constructor
    queue() {
         front = 0;
         rear=-1 ;
         a = new(int [MAX]);
    } 
    //deconstructor
    ~queue(){
        delete a;
    }
    //copy constructor
    queue(queue& news){
        a= new (int [MAX]);
        rear=news.rear;
        front=news.front;
        for(int i=front;i<=rear;i++)
        a[i]=news.a[i];
    }
    //methods relevant on queue
    bool enqueue(int x); 
    int dequeue(); 
    int peek(); 
    bool isEmpty(); 
    void disp();
}; 
  
bool queue::enqueue(int x) 
{ 
    if (rear >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[++rear] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
} 
  
int queue::dequeue() 
{ 
    if (front==rear || front==-1) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = a[front++]; 
        return x; 
    } 
} 
int queue::peek() 
{ 
    if (rear < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        int x = a[front]; 
        cout<<x<<endl;
        return x; 
    } 
} 
  
bool queue::isEmpty() 
{ 
    return (rear< 0 || front==rear); 
} 

void queue::disp()
{
    for(int i=front;i<=rear;i++){
        cout<<a[i]<<"->";
    }
    cout<<endl;
}


int main(){
    queue q;

    char c;

    int flag=1;



    while(flag){
        cin>>c;
        if(c=='e'){
            cout<<"enter the value to be enqued"<<endl;
            int n;
            cin>>n;
            q.enqueue(n);
        }
        else if(c=='d'){
            q.dequeue();

        }
        else if(c=='k'){
            if (q.isEmpty())
                cout<<"queue is empty"<<endl;
            else 
                cout<<"is not empty"<<endl;


        }
        else if(c=='f'){
            q.peek();

        }
        else if(c=='s'){
            q.disp();
        }
        else if(c=='c'){
            cout<<"creating a new copy queue"<<endl;
            queue qnew(q);
        }
        else if(c=='x'){
            flag=0;

        }
    }

}
