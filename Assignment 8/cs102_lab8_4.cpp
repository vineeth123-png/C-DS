#include<bits/stdc++.h>
using namespace std;
//root-base class
class Shape{
public:
  virtual void area() = 0;//pure virtual class
  virtual ~Shape(){}
};
//polygon and closedConics classes
class Polygon : public Shape{
public:
  virtual void area()=0;
  ~Polygon(){}
};
class ClosedConics : public Shape{
public:
  virtual void area()=0;
  virtual ~ClosedConics(){}
};
//class Ellipse and circle
class Ellipse : public ClosedConics{
public:
  double a, b;
  Ellipse(double a1=1, double b1=1){
    a = a1;
    b = b1;
  }
  virtual void area(){
    std::cout <<"Ellipse area is: "<< (22/7.0)*a*b << '\n';
  }
  virtual ~Ellipse(){}
};
class Circle : public ClosedConics{
public:
  double r;
  Circle(double r1 = 1){
    r = r1;
  }
  virtual void area(){
    std::cout <<"Circle area is: "<< (22/7.0)*r*r << '\n';
  }
  virtual ~Circle(){}
};
//class Triangle and Quadrilateral
class Triangle : public Polygon{
public:
  double a, b, c;
  Triangle(double a1=1, double b1=1, double c1=1){
    a = a1;
    b = b1;
    c = c1;
  }
  virtual void area(){
    double s = (a+b+c)/2.0;
    cout<<"Triangle area is: "<<sqrt(s*(s-a)*(s-b)*(s-c))<<"\n";
  }
  virtual ~Triangle(){}
};
class Rectangle : public Polygon{
public:
  double l, b;
  Rectangle(double l1=1, double b1=1){
    l =l1;
    b = b1;
  }
  virtual void area(){

    cout<<"Rectangle area is: "<<l*b<<"\n";
  }
  virtual ~Rectangle(){}
};

class Square : public Polygon{
  public:
  double s;
  Square(double s1=1){
    s = s1;
  }
  virtual void area(){

    cout<<"Square area is: "<<s*s<<"\n";
  }
  virtual ~Square(){}
};

class Trapezoid : public Polygon{
  public:
  double h, a, b;
  Trapezoid(double a1=1, double b1=1, double h1=1){
    a = a1;
    b = b1;
    h = h1;
  }
  virtual void area(){

    cout<<"Trapezoid area is: "<<0.5*(h)*(a+b)<<"\n";
  }
  virtual ~Trapezoid(){}
};

int main(){
  Shape *s[] = {new Rectangle(2, 3), new Square(5), new Ellipse(2, 3), new Circle(3), new Trapezoid(2, 3, 4)};
  for(int i=0; i<5; i++){
    s[i]->area();
  }
  return 0;
}
