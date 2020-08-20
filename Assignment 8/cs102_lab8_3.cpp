#include<bits/stdc++.h>
using namespace std;
//#include <stdio.h>

class Shape {
public:
	virtual ~Shape();
	//virtual void draw() = 0;
  //Question 3:
  virtual void draw(){
    cout<<" Shape::draw"<<endl;
  }
};

class Circle : public Shape {
public:
	virtual ~Circle();
	virtual void draw();
};
//Question 4:
class Ellipse : public Shape{
public:
  virtual~Ellipse();
  virtual void draw();
};
Shape::~Shape() {
	cout<<"shape destructor"<<endl;
}
/*Question 1
 void Shape::draw() {
	cout<<" Shape::draw"<<endl;
}*/

Circle::~Circle() {
	cout<<" circle destructor "<<endl;
}

void Circle::draw() {
	cout<<" Circle::draw "<<endl;
}
Ellipse::~Ellipse() {
	cout<<" ellipse destructor "<<endl;
}

void Ellipse::draw() {
	cout<<" Ellipse::draw "<<endl;
}
int main() {
  //Question 5:
  Circle c;
  Shape *s = &c;
  s->draw();
	Shape *shape = new Circle;
	shape->draw();
	delete shape;

  //Question 6:
  Ellipse e1, e2, e3;
  Shape *s1[] = {new Circle, new Circle, &e1, &e2, &e3};
  for(int i=0; i<5; i++){
    s1[i]->draw();
  }
	return 0;
}
/*Question 2:
We know, as there's no garbage collector in C++, removing virtual keyword from
the class destructors will cause obect slicing and creates garbage.
Removing virtual from circle's destructor will not cause any changes as it's a derived class.
Removing virtual from Shape's draw will stop dynamic binding into taking place.
We get a compile error removing virtual from shape's draw as it has "= 0" after
its definition making shape a absract class. However, removing it will give our
first line as Shape::draw" not Circle::draw.
There's no problem if we dont add virtual after circle's draw, as it will be
virtual as its inherited from shape class.*/
