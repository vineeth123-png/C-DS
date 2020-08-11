#include <iostream>
#define ll long long
#define ld long double

using namespace std;

template<class T=int>

class node
{ public:
T val;
node<T> *link;
static node<T>* avail;
node(T x=-1, node<T> *p=NULL){
  val = x;
  link = p;
}
void* operator new(size_t sz){
  void* p;
  if(node::avail == NULL){
    p = ::operator new(sz);
  }else{
    p = node::avail;
    node::avail = node::avail->link;
  }
  return p;
}
void operator delete(void* p){
  node<T>* t = (node<T>*)p;
  t->link = node::avail;
  node::avail = t;
  return ;
}
~node(){}
};
template<class T=int>
node<T>* node<T>::avail = NULL;


template <class T=int>

class llist
{
	public:
		node<T>* head;

	public:

		llist()
		{
			head=NULL;
		}

		~llist()
		{
			node<T> *start=head,*back=head;

			while(start!=NULL)
			{
				back=start;
				delete back;
			}
			delete back;
		}

		llist(llist &L2)
		{
			head=NULL;
			node<T>* start=L2.head;
			while(start!=NULL)
			{
				insert(start->val);
				start=start->link;
			}
		}

		void search_key(T key);

		void insert(T value);

		void del(T d);

		node<T>* create(T value)
		{
			node<T>* tmp=new(node<T>);
			tmp->val=value;
			tmp->link=NULL;

			return tmp;
		}

		llist &operator + (llist &L2){
			static llist<T> res;
			node<T>* ptr=head;
			while(ptr!=NULL)
			{
				res.insert(ptr->val);
				ptr=ptr->link;
			}
			ptr=L2.head;
			while(ptr!=NULL)
			{
				res.insert(ptr->val);
				ptr=ptr->link;
			}

			return res;
		}

		llist &operator ! (){
			static llist<T> reverse;
			node<T>* ptr=head;
			T temp[10000];
			int sz=0;
			while(ptr!=NULL)
			{
				temp[sz++]=ptr->val;
				ptr=ptr->link;
			}

			for (int i=sz-1;i>=0;i--){
				reverse.insert(temp[i]);
			}

			return reverse;
		}

		llist &operator = (llist& L2){
			if (head!=NULL){
			node<T>* ptr1=head->link;
			recdel(&ptr1);
			}
			head=NULL;
			node<T>* ptr2=L2.head;
			while(ptr2!=NULL){
				(*this).insert(ptr2->val);
				ptr2=ptr2->link;
			}

			return (*this);
		}

		void recdel(node<T>** ptr){
			if ((*ptr)!=NULL){
				recdel(&((*ptr)->link));
				delete (*ptr);
			}
		}

		bool operator == (llist &L2){
			T temp[10000];
			int sz1=0,sz2=0;
			node<T>* ptr=head;
			while(ptr!=NULL)
			{
				sz1++;
				ptr=ptr->link;
			}
			ptr=L2.head;
			while(ptr!=NULL)
			{
				sz2++;
				ptr=ptr->link;
			}

			if (sz1==sz2){
				bool cmp=true;
				node<T>* ptr1=head,ptr2=L2.head;
				while(ptr1!=NULL)
				{
					if (ptr1->val!=ptr2->val){
						cmp=false;
						break;
					}

					ptr1=ptr1->link;
					ptr2=ptr2->link;
				}
				return cmp;
			}
			else
			return false;
		}

		T operator [] (int pos){
			node<T>* ptr=head;
			int sz=0,val=-1;
			while(ptr!=NULL)
			{
				if (sz==pos){
					// 0 indexed
					val=ptr->val;
				}
				sz++;
				ptr=ptr->link;
			}

			if (pos>=sz){
				cout<<"index is more than size of list"<<endl;
				return -1;
			}
			else{
				return val;
			}
		}

		void * operator new(size_t size)
	    {
	        void * p = ::new llist();
	        return p;
	    }

	    void operator delete(void * p)
	    {
	        delete p;
	    }


		template <typename U>// all instantiations of this template are my friends
		friend istream & operator >> (istream &cin,  llist<U> &Lst);
		template <typename U>
		friend ostream & operator << (ostream &cout, llist<U> &Lst);

};

template <class T>
istream & operator >> (istream &cin,llist<T> &Lst){
	cout<<"Enter no. of numbers to be inserted"<<endl;
	ll sz=0;
	cin>>sz;
	cout<<"Enter List Elements"<<endl;
	T x;
	for (int i=0;i<sz;i++)
	{
		cin>>x;
		Lst.insert(x);
	}

	return cin;
}

template <class T>
ostream & operator << (ostream &cout,llist<T> &Lst){
	if (Lst.head==NULL)
	{
		cout<<"Linked List is already empty!!";
	}
	else
	{
		cout<<"List:"<<endl;
		node<T>* ptr=Lst.head;
		while(ptr!=NULL)
		{
			cout<<ptr->val<<" ";

			ptr=ptr->link;
		}
		delete ptr;
	}

	return cout;
}

template <class T>
node<T>* create(T value)
{
	node<T>* tmp=new(node<T>);
	tmp->val=value;
	tmp->link=NULL;

	return tmp;
}

template <class T>
void llist<T>::insert(T value)
{
	node<T>* temp=(node<T>*)create(value);

	node<T>* ptr=head;
	if (ptr==NULL)
	{
		head=temp;
	}
	else
	{
		while(ptr->link!=NULL){
			ptr=ptr->link;
		}
		ptr->link=temp;
	}
}

int main()
{

	llist<> l1,l2;
	cin>>l1>>l2;

	cout<<l1<<endl<<l2<<endl;

	llist<> res=l1;
	res=l1+l2;
	cout<<res<<endl;

	llist<> rev=l1;
	rev=!l1;
	cout<<(rev)<<endl;

	llist<>* ptr=new llist<>;
	cin>>(*ptr);

	cout<<(*ptr)<<endl;

	delete (ptr);

	return 0;
}
