#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
using namespace std;
template <class T=int>
class BHeap {
   private:
   vector <T> heap;
   //left & right child
   int l(int parent);
   int r(int parent);
   //parent of a child
   int par(int child);
   //function called when an element is inserted so as to maintain heap property.
   void heapifyup(int index);
   //function called when an element is deleted so as to maintain heap property.
   void heapifydown(int index);
   public:
      BHeap() {}
      //insert an element
      void Insert(T element);
      //delete the min.
      void DeleteMin();
      //show the min.
      int ExtractMin();
      //show entire heap
      void showHeap();
      int Size();
};
template <class T>
int BHeap<T>::Size() {
   return heap.size();
}
template <class T>
void BHeap<T>::Insert(T ele) {
   heap.push_back(ele);
   heapifyup(heap.size() -1);
}
template <class T>
void BHeap<T>::DeleteMin() {
   if (heap.size() == 0) {
      cout<<"Heap is Empty"<<endl;
      return;
   }
   heap[0] = heap.at(heap.size() - 1);
   heap.pop_back();
   heapifydown(0);
   cout<<"Element Deleted"<<endl;
}
template <class T>
int BHeap<T>::ExtractMin() {
   if (heap.size() == 0) {
      return -1;
   }
   else
   return heap.front();
}
template <class T>
void BHeap<T>::showHeap() {
   vector <T>::iterator pos = heap.begin();
   cout<<"Heap --> ";
   while (pos != heap.end()) {
      cout<<*pos<<" ";
      pos++;
   }
   cout<<endl;
}
template <class T>
T BHeap<T>::l(T parent) {
   T l = 2 * parent + 1;
   if (l < heap.size())
      return l;
   else
      return -1;
}
template <class T>
T BHeap<T>::r(T parent) {
   T r = 2 * parent + 2;
   if (r < heap.size())
      return r;
   else
      return -1;
}
template <class T>
T BHeap<T>::par(T child) {
   int p = (child - 1)/2;
   if (child == 0)
      return -1;
   else
      return T;
}
template <class T>
void BHeap<T>::heapifyup(T in) {
   if (in >= 0 && par(in) >= 0 && heap[par(in)] > heap[in]) {
      T temp = heap[in];
      heap[in] = heap[par(in)];
      heap[par(in)] = temp;
      heapifyup(par(in));
   }
}
template <class T>
void BHeap<T>::heapifydown(T in) {
   T child = l(in);
   T child1 = r(in);
   if (child >= 0 && child1 >= 0 && heap[child] > heap[child1]) {
      child = child1;
   }
   if (child > 0 && heap[in] > heap[child]) {
      T t = heap[in];
      heap[in] = heap[child];
      heap[child] = t;
      heapifydown(child);
   }
}


int main() {
   BHeap h<float>;
   while (1) {
      cout<<"1.Insert Element"<<endl;
      cout<<"2.Delete Minimum Element"<<endl;
      cout<<"3.Extract Minimum Element"<<endl;
      cout<<"4.Show Heap"<<endl;
      cout<<"5.Exit"<<endl;
      int c, e;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Enter the element to be inserted: ";
            cin>>e;
            h.Insert(e);
         break;
         case 2:
            h.DeleteMin();
         break;
         case 3:
            if (h.ExtractMin() == -1) {
               cout<<"Heap is Empty"<<endl;
            }
            else
            cout<<"Minimum Element: "<<h.ExtractMin()<<endl;
         break;
         case 4:
            cout<<"Displaying elements of Hwap: ";
            h.showHeap();
         break;
         case 5:
            exit(1);
            default:
            cout<<"Enter Correct Choice"<<endl;
      }
   }
   return 0;
}
