#include <iostream> 
  
using namespace std; 
  
class Stack { 
    int top; 
  
public: 
    int* a;  
    const int MAX;
  //constructor  
    Stack():MAX(1000)
       	{
         top = -1; 
         a = new int[MAX];
    } 
    //deconstructor
    ~Stack(){
        delete a;
    }
    //copy constructor
    Stack(Stack& news):MAX(1000)
	{
        a= new int[MAX];
        top=news.top;
        for(int i=0;i<=top;i++)
        a[i]=news.a[i];
    }
    //methods relevant to stack
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
    void disp();
}; 
  
bool Stack::push(int x) 
{ 
    if (top >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
} 
  
int Stack::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = a[top--]; 
        return x; 
    } 
} 
int Stack::peek() 
{ 
    if (top < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        int x = a[top]; 
        cout<<x<<endl;
        return x; 
    } 
} 
  
inline bool Stack::isEmpty() 
{ 
    return (top < 0); 
} 

void Stack::disp()
{
    for(int i=0;i<=top;i++){
        cout<<a[i]<<"->";
    }
    cout<<endl;
}
  

int main(){
    Stack s;

    char c;

    int flag=1;



    while(flag){
        cin>>c;
        if(c=='p'){
            cout<<"enter the value to be enqued"<<endl;
            int n;
            cin>>n;
            s.push(n);
        }
        else if(c=='o'){
            s.pop();

        }
        else if(c=='e'){
            if (s.isEmpty())
                cout<<"stack is empty"<<endl;
            else 
                cout<<"is not empty"<<endl;

        }
        else if(c=='t'){
            s.peek();
        }
        else if(c=='c'){
            cout<<"creating a new copy stack"<<endl;
            Stack Snew(s);
        }
        else if(c=='s'){
            s.disp();
        }
        else if(c=='x'){
            flag=0;

        }
    }

}
