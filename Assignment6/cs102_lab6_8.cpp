#include<iostream>
using namespace std;
template<class T = int>
class node
{
public:
    T data;
    node<T> *next;
    node(T a = -1, node<T> *p = NULL)
    {
        //constructor with default argument
        data = a;
        next = p;
    }
    node(const node<T> *p)
    {
        //copy constructor
        data = p->data;
        next = p->next;
    }
    ~node()
    {
        //destructor of node class
    }
};
template<class T = int>
class linklist
{
    node<T> *head;
public:
    int count;
    linklist()
    {
        head = NULL;
        count = 0;
    }
    linklist(T num)
    {
        head = new node<T>(num);
        count++;
    }
    linklist(const linklist *&p)
    {
        //copy constructor
        int t = p->count;
        node<T> *q = p->head;
        for(int i = 0;i<t;i++)
        {
            head = new node<T>(q->data,head);
            q = q->next;
        }
    }
    inline void insert_node(T num)
    {
        head = new node<T>(num,head);
        count++;
    }
    int delete_node()
    {
        node<T> *temp = head;
        if(head!=NULL)
        {
            head = head->next;
            delete []temp;
            count--;
            return 1 ;
        }
        return 0;
    }
    void display_list()
    {
        node<T> *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
    int search_node(T key)
    {
        node<T> *temp = head;
        while(temp!=NULL)
        {
            if(temp->data == key)
                return 1;
            else
                temp = temp->next;
        }
        return 0;
    }
    int delete_node(T key)
    {
        node<T> *temp = head, *prev = NULL;
        while(temp!=NULL)
        {
            if(temp->data == key)
                break;
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL)
            return 0;
        else
        {
            if(temp == head)
            {
                head = head->next;
                delete []temp;
            }
            else
            {
                prev->next = temp->next;
                delete [] temp;
            }
            count--;
            return 1;
        }
    }
    ~linklist()
    {
        if(count!=0)
        {
            node<T> *p = head;
            while(head!=NULL)
            {
                head = head->next;
                delete []p;
                p = head;
            }
            count = 0;
        }
    }
    void disposeoff() //to dispose off linked list from hash table
    {
        node<T>* temp;
        while(head!=NULL)
        {
            temp=head->next;
            delete []head;
            head=temp;
        }
    }
};
template<class T = int>
class hasht
{
	linklist<T> *ht;
	int htsize;	//size of hash table
	public:
	//constructor with default argument
    hasht(int s=0)
	{
		ht= new linklist<T>[s];
		htsize=s;
	}
	//copy constructor for the hasht class
	hasht(const hasht<T> *&temp)
	{
		ht= new linklist<T>[temp->size];
		for(int i =0;i<temp->size;i++)
		{
			node<T> *p = temp[i]->head;
			ht[i]->head = p;
			node<T> *q = ht[i]->head;
			p = p->next;
			while(p!=NULL)
			{
				q->next = new node<T>(p->data);
				p = p->next;
				q = q->next;
			}
		}
	}
	~hasht()
	{
		for(int i=0; i<htsize; i++)
		{
			ht[i].disposeoff();
		}
		delete []ht;
	}
	inline int hashfunction(T d)
	{
		//hash function
		return (d%htsize);
	}
	int insertht(T data)
	{
		int index = hashfunction(data);
		ht[index].insert_node(data);
	}
	void displayht(void)
	{
		//display the hash table
		for(int i =0;i<htsize;i++)
		{
			//display the list at ith position in the hash table
			ht[i].display_list;
			cout<<"\n";
		}
	}
};
int main()
{
    return 0;
}
