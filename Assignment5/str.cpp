#include<iostream>
using namespace std;
#include "cs102_lab4_4.h"
#include<cstring>
#include<cstdio>
class HashTable{
        int m;
        LinkedList** hashTable;
        public:
        HashTable(int m = 20){
                hashTable = new LinkedList*[m];
                for(int i=0; i<m; i++){
                        hashTable[i] = new LinkedList;
                }
        }
        void printLinkedLists(){
        //printing all nodes stored in all buckets
        for(int i=0; i<20; i++){
                cout<<"In bucket "<<i<<"\t";
                (hashTable[i])->printList();
        }
        }
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
        //string s = "17CS8032";
        //cout<<table.search(s)<<endl;
        table.printLinkedLists();
        //cout<<"CCC"<<endl;
        fclose(fp);
        return 0;
}

