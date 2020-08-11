#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//template<class T = string>
class Node{
        public:
                string rollNo;
		string name;
                Node* next;
                //constructors
                Node(){
                        next = NULL;
                }
                Node(string roll, string nameIn, Node* ptr){
                        rollNo = roll;
			name = nameIn;
                        next = ptr;
                }
                ~Node(){}
};
class LinkedList{
        Node* head;
        int nodeCount;
        int isEmpty(){
                if(head == NULL)
                        return 1;
                return 0;
        }
        public:
        LinkedList(){
                head = NULL;
                nodeCount = 0;
        }
        int getNodeCount() const;
        int insertAtFront(string &rollNo, string &nameIn){
                if(searchNode(rollNo) != NULL){
                        cout<<"Node is already present"<<endl;
                        return 0;
                }
                Node* ptr = new Node(rollNo, nameIn, head);
                head = ptr;
                cout<<"Value "<<rollNo<<" inserted at front."<<endl;
		nodeCount++;
                return 1;
        }
        int insert(string &roll, string &nameIn){
                if(searchNode(roll) != NULL){
                        cout<<"Node is already present"<<endl;
                        return 0;
                }
		//cout<<"LL"<<endl;
		if(head == NULL){
			if(insertAtFront(roll, nameIn))
				return 1;
			else
				return 0;
		}
                Node* ptr = new Node(roll, nameIn, NULL);
                Node* temp = head;
                while(temp->next != NULL)
                        temp = temp->next;
                temp->next = ptr;
		nodeCount++;
                return 1;
        }
        int deleteAtFront(){
                if(isEmpty())
                        return 0;
                Node* ptr = head;
                string roll = ptr->rollNo;
                head = head->next;
                delete ptr;
                cout<<"Front node deleted "<<roll<<endl;
                nodeCount--;
                return 1;
        }
        //method to search whether a value is present in the list
        Node* searchNode(string &roll){
                Node* ptr;
                if(isEmpty()){
                        ptr = NULL;
                        return ptr;
                }
                ptr = head;
                while(ptr != NULL && ptr->rollNo != roll)
                        ptr = ptr->next;
                return ptr;
        }
        //method to delete a node
        int deleteNode(string &roll){
                Node* ptr = searchNode(roll);
                if(ptr == NULL){
                        cout<<"Node not present"<<endl;
                        return 0;
                }
                if(ptr == head){
                        if(deleteAtFront())
                                return 1;
                        else
                                return 0;
                }
                cout<<"Value to be deleted "<<ptr->rollNo<<endl;
                Node* temp = head;
                while(temp->next != ptr){
                        temp = temp->next;
                }
                temp->next = ptr->next;
                delete ptr;
                nodeCount--;
                return 1;
        }
        //method to print all
        void printList(){
                if(isEmpty()){
                        cout<<"List is empty"<<endl;
                        return;
                }
                Node* ptr = head;
                while(ptr != NULL){
                        cout<<ptr->rollNo<<"\t"<<ptr->name<<endl;
                        ptr = ptr->next;
                }
                cout<<"end"<<endl;
        }
        //destructor
        ~LinkedList(){
                //cout<<"Deleting the list"<<endl;
                if(!isEmpty()){
                        Node* ptr = head;
                        while(head != NULL){
                                head = head->next;
                                delete ptr;
				ptr = head;
                        }
                        nodeCount = 0;
                }
        }
};
inline int LinkedList::getNodeCount() const{
                return nodeCount;
}
//template<class T = string>
class HashTable{
	int m;
	LinkedList** hashTable;
	public:
	//constructor
	HashTable(int m = 20){
		hashTable = new LinkedList*[m];
		for(int i=0; i<m; i++){
			hashTable[i] = new LinkedList;
		}
	}
	//print all buckets nodes
	void printLinkedLists(){
        //printing all nodes stored in all buckets
        for(int i=0; i<20; i++){
                cout<<"In bucket "<<i<<"\t";
		(hashTable[i])->printList();
	}
	}
	//insert nodes using hash function
	void insert(Node& node){
		string nameIn = node.rollNo;
		int sum = 0;
		for(int i=0; i<nameIn.size(); i++){
			sum+= int(nameIn[i]);
		}
		sum = sum%20;
		cout<<sum<<endl;
		if((hashTable[sum])->insert(node.rollNo, node.name))
			cout<<"successful insertion"<<endl;
		else
			cout<<"unsuccessful insertion"<<endl;
	}
	//search nodes
	string search(string& roll){
		int sum = 0;
                for(int i=0; i<roll.size(); i++){
                        sum+= int(roll[i]);
                }
                sum = sum%20;
                //cout<<sum<<endl;
		Node* ptr = hashTable[sum]->searchNode(roll);
		if(ptr != NULL){
			return ptr->name;
		}
		else
			return "Not found";
	}
	//deconstructor
	~HashTable(){
		//cout<<"Deleting hash table"<<endl;
		for(int i=0; i<20; i++){
			delete hashTable[i];
		}
		delete[] hashTable;
	}
};
int main(){
	HashTable table;
	FILE *fp = fopen("OOPs Lab Hashing.csv", "r");
        char str[200], *roll, *name;
	Node node;
        while(fgets(str, 200, fp)){
                //cout<<s<<endl;
                roll = strtok(str, ",");
		name = strtok(NULL, ",");
		string r = roll;
		string n = name;
		node.rollNo = r;
		node.name = n;
		table.insert(node);
		//cout<<roll<<"   "<<name<<endl;
        }
	//cout<<"check"<<endl;
	string s = "17CS8032";
	cout<<table.search(s)<<endl;
	table.printLinkedLists();
	//cout<<"CCC"<<endl;
	fclose(fp);
	return 0;
}
