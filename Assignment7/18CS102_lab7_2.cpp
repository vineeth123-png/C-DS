#include<iostream>
using namespace std;
#define abs(x) x>=0 ? x : -x
int gcd(int a, int b){
  if(b==0)
  return a;
  return gcd(b, a%b);
}
int lcm(int a, int b){
  return (a*b)/gcd(a, b);
}
class Fraction{
  int num;
  int den;
public:
  //constructors
  Fraction(int n = 0, int d = 1){
    num = n;
    den = d;
    lowest_form();
  }
  Fraction(const Fraction& temp){
    num = temp[0];
    den = temp[1];
  }
  /*Fraction(float x){
    //x = x/y;
    int n = x;
    int s = 1;
    float d = x-n;
    while(d != 0){
      n = n*10 + d*10;
      d = d*10 - int(d*10);
      s = s*10;
    }
    //cout<<n<<" "<<s<<"\n";
    num = n;
    den = s;
    lowest_form();
  }*/
  //overloading "[]" operator / getters
  int operator[](int pos)const {
    if(pos == 0)
    return num;
    else if(pos == 1)
    return den;
    return -1;
  }
  int& operator[](int pos){
    if(pos == 0)
    return num;
    else
    return den;
  }
  //setters
  void setNum(int n){num = n;}
  void setDen(int d){den = d;}
  //overload << & >> operators
  friend ostream& operator<<(ostream& out, const Fraction& temp){
    if(temp[1] !=1)
    out<<"Fraction: "<<temp[0]<<"/"<<temp[1];
    else
    out<<"Number: "<<temp[0];
    return out;
  }
  friend istream& operator>>(istream& in, Fraction& temp){
    float n, d;
    in>>n>>d;
    temp.setNum(n);
    temp.setDen(d);
    return in;
  }
  //lowest form of numbers
  void lowest_form(){
    int s;
    if((num<0 && den>0) || (num>0 && den<0))
    s = -1;
    else
    s = 1;
    int x = gcd(abs(num), abs(den));
    if(x != 1){
      num = s*(num/x);
      den = den/x;
    }
  }
  //normalize
  float decimal_form()const {return num/(den*1.0);}
  float operator*(){return num/(den*1.0);}
  //methods to Compare
  int operator==(const Fraction& a){
    return (num == a[0] && den == a[1]);
  }
  int operator==(float x){
    return (num == x && den == 1);
  }
  friend int operator==(float x, const Fraction& a){
    return (x == a[0] && a[1] == 1);
  }
  int operator!=(const Fraction& a){
    return !(num == a[0] && den == a[1]);
  }
  int operator!=(float x){
    return !(num == x && den == 1);
  }
  friend int operator!=(float x, const Fraction& a){
    return !(x == a[0] && a[1] == 1);
  }
  int operator>(const Fraction& a){
    return (decimal_form() > a.decimal_form());
  }
  int operator>(float x){
    return (decimal_form() > x);
  }
  friend int operator>(float x, const Fraction& a){
    return (x > a.decimal_form());
  }
  int operator<(const Fraction& a){
    return (decimal_form() < a.decimal_form());
  }
  int operator<(float x){
    return (decimal_form() < x);
  }
  friend int operator<(float x, const Fraction& a){
    return (x < a.decimal_form());
  }
  //Add two fractions
  Fraction& operator+(const Fraction& a2){
    static Fraction ans(num*a2[1]+a2[0]*den, den*a2[1]);
    return ans;
  }
  Fraction& operator+(float x){
    static Fraction ans(x*den+num, den);
    return ans;
  }
  friend Fraction& operator+(float x, const Fraction& temp){
    static Fraction ans(x*temp[1]+temp[0], temp[1]);
    return ans;
  }
  //Subtract two fractions
  Fraction& operator-(const Fraction& a2){
    static Fraction ans(num*a2[1]-a2[0]*den, den*a2[1]);
    return ans;
  }
  Fraction& operator-(float x){
    static Fraction ans(-x*den+num, den);
    return ans;
  }
  friend Fraction& operator-(float x, const Fraction& temp){
    static Fraction ans(x*temp[1]-temp[0], temp[1]);
    return ans;
  }
  //Multiply two fractions
  Fraction& operator*(const Fraction& a2){
    static Fraction ans(num*a2[0], den*a2[1]);
    return ans;
  }
  Fraction& operator*(float x){
    static Fraction ans(x * num, den);
    return ans;
  }
  friend Fraction& operator*(float x, const Fraction& temp){
    static Fraction ans(x*temp[0], temp[1]);
    return ans;
  }
  //Divide two fractions
  Fraction& operator/(const Fraction& a2){
    static Fraction ans(num*a2[1], den*a2[0]);
    return ans;
  }
  Fraction& operator/(float x){
    static Fraction ans(num, den*x);
    return ans;
  }
  friend Fraction& operator/(float num, const Fraction& temp){
    static Fraction ans(num*temp[1], temp[0]);
    return ans;
  }
  //destructor
  ~Fraction(){}
};//end of class
int main(){
  Fraction f1, f3(3, 2);
  Fraction f2(2, 1);
  cout<<f1<<" "<<f2<<" "<<f3<<" "<<f2/f3<<"\n";
  f2[1] = 2;
  cout<<f2<<"\n";
  int x = f1==f2;
  cout<<x<<"\n";
  return 0;
}
