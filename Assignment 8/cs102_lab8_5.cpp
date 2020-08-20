#include<iostream>
#define ll long long 

using namespace std;

class List
{
    protected:
        ll size, front, rear;
        ll *arr;
    public:
        List(ll size = 0)
        {
            if(size > 0)
            {
                this->size = size+1;
                arr = new ll [size+1];
            }
            else
                arr = NULL;
            front = rear = -1;
        }
        void addBeg(ll &v)
        {
            if((rear+2)%size == front)
            {
                cout << "Overflow\n";
            }
            else
            {
                if(front == -1)
                    front = 0;
                else
                    front = (front+size-1)%size;    
                arr[front] = v;
                if(rear == -1)
                    rear = 0;
            }
        }
        void delBeg(ll &v)
        {
            if(rear == -1)
            {
                cout << "Underflow\n";
            }
            else
            {
                v = arr[front];
                if(front == rear)
                    front = rear = -1;
                else
                    front = (front+1)%size;
            }
        }
        void addend(ll &v)
        {
            if((rear+2)%size == front)
            {
                cout << "Overflow\n";
            }
            else
            {
                arr[(rear+1)%size] = v;
                rear = (rear+1)%size;
                if(front == -1)
                    front = 0;
            }
        }
        void delend(ll &v)
        {
            if(rear == -1)
            {
                cout << "Underflow\n";
            }
            else
            {
                v = arr[(rear-1+size)%size];
                rear = (rear-1+size)%size;
                if(rear == front)
                    rear = front = -1;
            }
        }
        void display()
        {
            ll i;
            for(i = front ; i != (rear+1)%size && i != -1 ; i = (i+1)%size)
                cout << arr[i] << " ";
            // cout << arr[i] << " ";
            cout << endl;
        }
        virtual void push(ll &v) = 0;
        virtual void pop(ll &v) = 0;
        virtual void enqueue(ll &v) = 0;
        virtual void dequeue(ll &v) = 0;
};

class Stack : public List
{
    public:
        Stack(ll size) : List{size}
        {}
        virtual ~Stack();
        virtual void push(ll &v)
        {
            addBeg(v);
        }
        virtual void pop(ll &v)
        {
            delBeg(v);
        }
        virtual void enqueue(ll &v){}
        virtual void dequeue(ll &v){}
};

Stack::~Stack()
{
    cout << "Stack destructor\n";
}

class Queue : public List
{
    public:
        Queue(ll size) : List{size}
        {}
        virtual ~Queue();
        virtual void push(ll &v){}
        virtual void pop(ll &v){}
        virtual void enqueue(ll &v)
        {
            addBeg(v);
        }
        virtual void dequeue(ll &v)
        {
            delend(v);
        }
};

Queue::~Queue()
{
    cout << "Queue destructor\n";
}

class Deque : public Queue
{
    public:
        Deque(ll size) : Queue{size}
        {}
        virtual ~Deque();
};

Deque::~Deque()
{
    cout << "Deque destructor\n";
}


int main()
{
    List *arr[] = {new Stack(5), new Queue(6), new Deque(3)};
    ll tmp;
    arr[0]->push(tmp=3);
    arr[0]->push(tmp=4);
    arr[0]->push(tmp=5);
    arr[0]->push(tmp=6);
    arr[0]->push(tmp=7);
    arr[0]->push(tmp=8);
    arr[0]->display();
    arr[0]->pop(tmp);
    arr[0]->pop(tmp);
    arr[0]->pop(tmp);
    arr[0]->pop(tmp);
    arr[0]->pop(tmp);
    arr[0]->pop(tmp);
    arr[0]->display();
    return 0;
}