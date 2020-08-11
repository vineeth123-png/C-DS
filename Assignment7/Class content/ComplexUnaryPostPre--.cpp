#include<iostream>
using namespace std;

class complex
{
	float rl, img;
	public:
		float arg, amp;

		complex(float f1=1.0,float f2=1.0)   //constructor with default arguments
		{
			//cout<<"constructing a complex obj"<<endl;
			rl=f1; img=f2;
		}
		
		~complex() // destructor
		{    //cout<<"destroying a complex object"<<endl;
		}

        // member functions
		void DispComplex(void) const;
		complex &SubComplex(const complex &c);
        complex &operator-(const complex &c);	
        
        complex &operator--(void); //pre
        //complex &operator--(int dummy); 
        friend complex &operator--(complex &c,int dummy);  //post
        //friend ostream &operator<<(const ostream &x,const complex &c);

};  // End of class definition

//.........................................................
//  Member function definitions
void complex::DispComplex(void) const
{
    cout<<rl;
    if(img>=0)
    {  cout<<" + "; cout<<img<<"i"<<endl; }
    else
    {  cout<<" - "; cout<<-img<<"i"<<endl;}
}

complex &complex::SubComplex(const complex &c)
{
	cout<<"member function  ";
	static complex t;
	t.rl=rl-c.rl;
	t.img=img-c.img;
	return t;
}

complex &complex::operator-(const complex &c)
{
    cout<<"member operator (a-b) function  ";
	static complex t;
	t.rl=rl-c.rl;
	t.img=img-c.img;
	return t;
}

complex &complex::operator--(void)  // predecrement
{
    cout<<"member operator --a function  ";
    rl--; img--;
    return *this;
}

complex &operator--(complex &c,int dummy)  //postdecrement
{
    cout<<"friend operator a-- function  ";
    static complex t=c;
    c.rl--; c.img--;
    return t;
}
/*
ostream &operator<<(ostream &x,const complex &c)   // << operator
{
    cout<<c.rl;
    if(c.img>=0)
    {  x<<" + "; x<<c.img<<"i"<<endl; }
    else
    {  x<<" - "; x<<-c.img<<"i"<<endl;}
    
    return x;
}*/
//..........................................................
int main()
{
   complex a, b(3,0),c;

   a.DispComplex(); b.DispComplex();

   c=a-b;  // using member operator function
   c.DispComplex();
   
   --b;  // predecrement
   b.DispComplex();
   
   c=b--;  // post decrement
   c.DispComplex(); b.DispComplex();
   return 0;
}