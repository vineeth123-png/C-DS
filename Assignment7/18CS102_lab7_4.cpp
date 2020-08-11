#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<class T=int>
class Set
{
	public:
		int size,top;// 2-dimensions
		T* arr;
		
	public:
		Set (int s=100)
		{
			this->size=s;
			top=0;
			arr=new T[s];	
		}
		~Set()
		{
			delete []arr;
		}
		
		Set (Set &St2)
		{ // =
			this->size=St2.size;
			arr=new T[size];
			top=0;
			for (int i=0;i<St2.top;i++){
				arr[i]=St2.arr[i];
				top++;
			}
		}
		//intersection
		Set & operator * (Set &St2){
			
			int hash[10000]={0};
			static Set<T> inter(size+St2.size);
			
			for (int i=0;i<top;i++){
				hash[arr[i]]++;
			}
			for (int i=0;i<St2.top;i++){
				hash[St2.arr[i]]++;
			}
			
			for (int i=0;i<10000;i++){
				if (hash[i]>1){
					inter.insert(i);
				}
			}
			
			return inter;
		}
		// union
		Set & operator + (Set &St2){
			
			int hash[10000]={0};
			static Set<T> inter(size+St2.size);
			
			for (int i=0;i<top;i++){
				hash[arr[i]]++;
			}
			for (int i=0;i<St2.top;i++){
				hash[St2.arr[i]]++;
			}
			
			for (int i=0;i<10000;i++){
				if (hash[i]!=0){
					inter.insert(i);
				}
			}
			
			return inter;
		}
		//difference=union-intersection
		Set & operator - (Set &St2){
			
			int hash[10000]={0};
			static Set<T> inter(size+St2.size);
			
			for (int i=0;i<top;i++){
				hash[arr[i]]++;
			}
			for (int i=0;i<St2.top;i++){
				hash[St2.arr[i]]++;
			}
			
			for (int i=0;i<10000;i++){
				if (hash[i]==1){
					inter.insert(i);
				}
			}
			
			return inter;
		}
		
		bool operator < (Set &St2){
			
			bool Subset=true;
			for (int i=0;i<top;i++){
				if (!(St2.find(arr[i]))){
					Subset=false;
				}
			}
			if (Subset&&top!=St2.top){
				return true;
			}
			else
			return false;
		}
		
		bool operator <= (Set &St2){
			
			bool Subset=true;
			for (int i=0;i<top;i++){
				if (!(St2.find(arr[i]))){
					Subset=false;
				}
			}
			if (Subset&&top==St2.top){
				return true;
			}
			else
			return false;
		}
		
		bool operator > (Set &St2){
			
			bool Subset=true;
			for (int i=0;i<St2.top;i++){
				if (!((*this).find(St2.arr[i]))){
					Subset=false;
				}
			}
			if (Subset&&top!=St2.top){
				return true;
			}
			else
			return false;
		}
		
		bool operator >= (Set &St2){
			
			bool Subset=true;
			for (int i=0;i<St2.top;i++){
				if (!((*this).find(St2.arr[i]))){
					Subset=false;
				}
			}
			if (Subset&&top==St2.top){
				return true;
			}
			else
			return false;
		}
		
		bool operator == (Set &St2){
			
			bool equal=true;
			if (top!=St2.top)
			return false;
			else{
				for (int i=0;i<top;i++){
					if (arr[i]!=St2.arr[i]){
						equal=false;
						break;	
					}
				}
				return equal;
			}
		}
		
		bool operator != (Set &St2){
			if ((*this)==St2){
				return false;
			}
			else
			return true;
		}
		
		// = operator
		Set &operator = (Set &St2){
			top=0;
			size=St2.size;
			for (int i=0;i<St2.top;i++)
			arr[i]=St2.arr[i],top++;
			
			return (*this);
		}
		
		void insert(T key){
			if ((*this).find(key)){
				//element already present
			}
			else{
				if (top>=size){
					cout<<"Cannot insert more values than given set size"<<endl;
					return;
				}
				arr[top]=key;
				top++;
				sort(arr,arr+top);
			}
		}
		bool find(T key){
			int low=0,high=top-1;//binary search for finding if element is present or not
			
			int idx=-1;
			while(low<=high){
				int mid=low+(high-low)/2;// mid=(low+high)/2;
				if (arr[mid]<key){
					low=mid+1;
				}
				else if (arr[mid]>key){
					high=mid-1;
				}
				else{
					idx=mid;
					break;
				}
			}
			
			if (idx!=-1){//i.e., 0<=idx<top
				return true;
			}
			else
			return false;
		}
		
		template <typename U>// all instantiations of this template are my friends
		friend istream & operator >> (istream &cin,  Set<U> &St); 
		template <typename U>
		friend ostream & operator << (ostream &cout, Set<U> &St);		
};

template<class T>
istream & operator >> (istream &cin,Set<T> &St) 
{   
	cout<<"Enter the Set Elements"<<endl;
	for (int x,i=0;i<St.size;i++){
		cin>>x;
		St.insert(x);
	}		
    return cin; 
}
template<class T>
ostream & operator << (ostream &cout,Set<T> &St) 
{ 
	cout<<"Set:"<<endl;
	cout<<"{ ";
	for (int i=0;i<St.top-1;i++){
		cout<<St.arr[i]<<" , ";
	}
	if (St.top!=0)
	cout<<St.arr[St.top-1]<<" }";
	else
	cout<<" }";
			
    return cout; 
} 

int main()
{
	Set<> st1,st2;
	st1.insert(5);
	st1.insert(1);
	st1.insert(1);
	st1.insert(5);
	st1.insert(4);
	
	st2.insert(8);
	st2.insert(3);
	st2.insert(8);
	
	cout<<st1<<endl<<st2<<endl;
	
	Set<> res1=st1+st2,res2=st1*st2,res3;
	res3=st1-st2;
	cout<<res1<<endl<<res2<<endl<<res3<<endl;
	
	return 0;
}

