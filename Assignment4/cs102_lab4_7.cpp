#include<iostream>
using namespace std;
int  binarySearch(const int* arr, int size, int value){
	int start = 0;
	int end = size-1;
	while(start <= end){
		int mid = (start+end)/2;
		//if mid element is our value
		if(arr[mid] == value)
			return mid;
		//our value is less than mid value
		else if(arr[mid] > value)
			end = mid-1;
		//our value is greater than mid value
		else
			start = mid+1;
	}
	//value not present in array
	return -1;
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	//binary search works only for a sorted array
	int x = binarySearch(arr, 9, 3);
	//returns index 2
	int y = binarySearch(arr, 9, 10);
	//return index -1
	cout<<x<<"\t"<<y<<endl;
	return 0;
}
