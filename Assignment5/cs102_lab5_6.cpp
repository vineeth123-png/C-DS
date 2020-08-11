#include<iostream>
using namespace std;
class String{
	char* arr;
	int size;
	public:
	String(int num = 0){
		size = num;
		arr = new char[num+1];
		arr[size] = '\0';
	}
	String(const String& s1){
		size = s1.getSize();
		arr = new char[size+1];
		arr[size] = '\0';
		for(int i=0; i<size; i++){
			arr[i] = s1.getAtIndex(i);
		}
	}
	void inputAtIndex(char x, int i){
		if(i<0 || i>=size){
			cout<<"Invalid call"<<endl;
			return ;
		}
		arr[i] = x;
	}
	int getSize() const;
	char getAtIndex(int i) const{
		if(i<0 || i>=size){
                        cout<<"Invalid call"<<endl;
                        return '\0';
                }
                return arr[i];
	}
	int isAtIndex(char x, int i){
		if(i<0 || i>=size){
                        cout<<"Invalid call"<<endl;
                        return 0;
                }
		else if(arr[i] == x)
			return 1;
		else
			return 0;
	}
	void printString(){
		for(int i=0; i<size; i++)
			cout<<arr[i]<<"  ";
		cout<<endl;
	}
	void inputFromUser(int x){
		cout<<"This deletes all the contents in the present string"<<endl;
		cout<<"If ok, press 1 else, press 0"<<endl;
		int a;
		cin>>a;
		if(!a)
			return ;
		//cout<<"Enter size"<<endl;
		//cin>>size;
		size = x;
		delete[] arr;
		arr = new char[size+1];
		arr[size] = '\0';
		cout<<"Enter content of string of size "<<x<<endl;
		for(int i=0; i<size; i++)
			cin>>arr[i];
	}
	void pushBack(char x){
		size++;
		char* arr1 = new char[size];
		arr1[size] = '\0';
		arr1[size-1] = x;
		for(int i=0; i<size-1; i++)
			arr1[i] = arr[i];
		delete[] arr;
		arr = arr1;
	}
	void concatenate(const String& s2){
		int x = size;
	        size = size + s2.getSize();
                arr[size] = '\0';
                for(int i = 0; i<s2.getSize(); i++){
	                arr[i+x-1] = s2.getAtIndex(i);
		}
        }
        ~String(){
	        delete[] arr;
	}
};
inline int String::getSize() const{
                return size;
        }

int main(){
	String a(3);
	a.inputFromUser(5);
	a.printString();
	a.pushBack('p');
	a.printString();
	String b;
	b.inputFromUser(5);
	a.concatenate(b);
	a.printString();
	return 0;
}
