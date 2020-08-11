#include <iostream>
using namespace std;

#define ll long long
#define ld long double

//template<class T=int>

class node
{ public:
int val;
node *link;
static node* avail;
node(int x=-1, node *p=NULL){
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
  node* t = (node*)p;
  t->link = node::avail;
  node::avail = t;
  return ;
}
~node(){}
};
node* node::avail = NULL;

class llist{
  node* head;
public:
  llist()
  {
    head=NULL;
  }

  ~llist()
  {
    node *start=head,*back=head;

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
    node* start=L2.head;
    while(start!=NULL)
    {
      insert(start->val);
      start=start->link;
    }
  }


};
int main(){
  node* x = new node(1, NULL);
  delete x;
  x = new node(2, NULL);
  delete x;
  return 0;
}
