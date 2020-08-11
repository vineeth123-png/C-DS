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
        complex &operator-(float x);
        
        friend complex &operator-(float x, complex &c);

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
	static complex t;
	t.rl=rl-c.rl;
	t.img=img-c.img;
	return t;
}

complex &complex::operator-(const complex &c)
{
	static complex t;
	t.rl=rl-c.rl;
	t.img=img-c.img;
	return t;
}

complex &complex::operator-(float x)
{
	static complex t;
	t.rl=rl-x;
	t.img=img;
	return t;
}

complex &operator-(float x, complex &c)
{
	static complex t;
	t.rl=x-c.rl;
	t.img=c.img;
	return t;
}

//..........................................................
int main()
{
   complex a, b(3,5),c;

   a.DispComplex(); b.DispComplex();

   c=a-b;   c.DispComplex();  // using member operator function
   c=a-3.0;   c.DispComplex();  // using member operator function
   c=3.0-b;   c.DispComplex();   // using friend operator function
   
   return 0;
}