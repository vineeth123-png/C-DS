#include<bits/stdc++.h>
using namespace std;
//pure abstract class
class Employee{
public:
  Employee(){
    cout<<"This is a employee."<<"\n";
  }
  static double da;
  virtual void calcSalary()=0;
  ~Employee(){}
};
double Employee::da = 0.26;
class AdminStaff : virtual public Employee{
public:
  double basic, bonus, gross;
  AdminStaff(double basic1, double bonus1): Employee(){
    basic = basic1;
    bonus = bonus1;
  }
  virtual void calcSalary(){
    gross = basic+bonus+(basic*Employee::da)/100;
    cout<<"Salary of AdminStaff is: "<<gross<<"\n";
  }
  ~AdminStaff(){}
};

class Faculty : virtual public Employee{
public:
  double basic, bonus, gross;
  Faculty(double basic1, double bonus1): Employee(){
    basic = basic1;
    bonus = bonus1;
  }
  virtual void calcSalary(){
    gross = basic+bonus+(basic*Employee::da)/100;
    cout<<"Salary of faculty is: "<<gross<<"\n";
  }
  ~Faculty(){}
};

class Dean : public AdminStaff, public Faculty{
public:
  double basic, bonus, gross;
  Dean(double basic1, double bonus1) :Employee(), AdminStaff(basic1, bonus1), Faculty(basic1, bonus1)
  {
    basic = basic1;
    bonus = bonus1;
  }
  virtual void calcSalary(){
    gross = basic+bonus+(basic*Employee::da)/100;
    cout<<"Salary of dean is: "<<gross<<"\n";
  }
  ~Dean(){}
};

int main(){
  Employee *e = new Dean(200, 300);
  e->calcSalary();
  return 0;
}
