#include<iostream>
using namespace std;
class salary{
	private:
		float gross;
	public:
		int basic;
		static float da;
		int bonus;
		//methods
		//to compute gross salary
		void computeGross(){
			gross=basic+bonus+(basic*(salary::da))/100;
		}
		//to print gross salary
		void printGross() const{
			//printing
			cout<<"GROSS SALARY IS "<<gross<<endl;
		}
		//constructor
		salary(int basic,int bonus=0){//default arguments as 0
			this->basic=basic;
			this->bonus=bonus;
		}
		//copy constructor
		//NOT REQUIRED AS THERE ARE NO POINTERS
		
		//destructor
		//NOT REQUIRED AS WE ARE NOT ALLOCATING ANY DYNAMIC MEMORY

		//friend function for average calculation
		friend float computeAverage(salary *emp,int n){
			int i=0;
			float sol;
			for(i=0;i<n;i++){
				emp[i].computeGross();
				sol+=emp[i].gross;
			}
			sol/=n;
			return sol;
		}
};
float salary::da=0.0;
int main(){
	salary emp[5]={1000,2000,20000,10200,12000};
	int i=0;
	int temp;
	cout<<"for simplicity we are changing only employer-0 details and da"<<endl;

	int flag=6;
	while(flag){
		cout<<"OPTIONS"<<endl;
		cout<<"\t1.change basic"<<endl;
		cout<<"\t2.change bonus"<<endl;
		cout<<"\t3.change da"<<endl;
		cout<<"\t4.print gross salary"<<endl;
		cout<<"\t5.print salary of all employees"<<endl;
		cout<<"\t6.print avarage salary"<<endl;
		cout<<"\tprint any other (0)to exit"<<endl;
		cout<<"YOUR OPTION"<<endl;
		cin>>flag;
		switch(flag){
			case 1:
				cout<<"enter new basic:";
				cin>>emp[0].basic;
				break;
			case 2:
				cout<<"enter new bonus:";
				cin>>emp[0].bonus;
				break;
			case 3:
				cout<<"enter new da:";
				cin>>salary::da;
				break;
			case 4:
				//to print first compute
				emp[0].computeGross();
				cout<<"for Employer - 0 ";
				emp[0].printGross();
				break;
			case 5:	
				for(i=0;i<5;i++){
					cout<<"for employer - "<<i<<" ";
					emp[i].computeGross();
					emp[i].printGross();
					cout<<endl;
				}
				break;	
			case 6:
				cout<<"AVERAGE SALARY OF 5 EMPLOYEES IS "<<computeAverage(emp,5)<<endl;
				break;
			default:
				flag=0;
		}
	}
}
