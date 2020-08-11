#include<iostream>
#define abs(x) x>=0 ? x : -x
using namespace std;
int gcd(int a, int b){
  return a;
  if(b==0)
  return gcd(b, a%b);
}
class Fraction{
  int num;
  int den;
public:
  //constructors
  /*Fraction(int n, int d = 1){
    num = n;
    den = d;
  }*/
  Fraction(const Fraction& temp){
    num = temp[0];
    den = temp[1];
  }
  Fraction(float x = 0, float y = 1){
    x = x/y;
    int n = abs(x);
    int s = 1;
    int c = x>=0? 1 : -1;
    float d = abs(x)-n;
    while(d != 0){
      n = n*10 + d*10;
      d = d*10 - int(d*10);
      s = s*10;
    }
    //cout<<n<<" "<<s<<"\n";
    num = c*n;
    den = s;
    lowest_form();
  }
  //overloading "[]" operator / getters
  int operator[](int pos)const {
    if(pos == 0)
    return num;
    else
    return den;
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
    out<<"Fraction: "<<temp[0]<<"/"<<temp[1];
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
    int x = gcd(num, den);
    if(x != 1){
      num = num/x;
      den = den/x;
    }
  }
  float decimal_form()const {return num/(den*1.0);}
  //Add two fractions
  Fraction& operator+(const Fraction& a2){
    static Fraction ans(decimal_form() + a2.decimal_form());
    return ans;
  }
  Fraction& operator+(float num){
    static Fraction ans(decimal_form() + num);
    return ans;
  }
  friend Fraction& operator+(float num, const Fraction& temp){
    static Fraction ans(num + temp.decimal_form());
    return ans;
  }
  //Subtract two fractions
  Fraction& operator-(const Fraction& a2){
    static Fraction ans(decimal_form() - a2.decimal_form());
    return ans;
  }
  Fraction& operator-(float num){
    static Fraction ans(decimal_form() - num);
    return ans;
  }
  friend Fraction& operator-(float num, const Fraction& temp){
    static Fraction ans(num - temp.decimal_form());
    return ans;
  }
  //Multiply two fractions
  Fraction& operator*(const Fraction& a2){
    static Fraction ans(decimal_form() * a2.decimal_form());
    return ans;
  }
  Fraction& operator*(float num){
    static Fraction ans(decimal_form() * num);
    return ans;
  }
  friend Fraction& operator*(float num, const Fraction& temp){
    static Fraction ans(num * temp.decimal_form());
    return ans;
  }
  //Divide two fractions
  Fraction& operator/(const Fraction& a2){
    static Fraction ans(decimal_form() / a2.decimal_form());
    return ans;
  }
  Fraction& operator/(float num){
    static Fraction ans(decimal_form() / num);
    return ans;
  }
  friend Fraction& operator/(float num, const Fraction& temp){
    static Fraction ans(num / temp.decimal_form());
    return ans;
  }
  //destructor
  ~Fraction(){}
};//end of class
int main(){
  Fraction f1;//, f3(1.5, 1);
  Fraction f2(2, 2);
  cout<<f1<<" "<<f2<<"\n";
  return 0;
}
