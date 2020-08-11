#include<iostream>
using namespace std;
class Complex{
  //instance variables
  float real;
  float imaginary;
public:
  //constructors
  Complex(float r = 0.0, float c = 0.0){
    real = r;
    imaginary= c;
  }
  Complex(const Complex& copy){
    real = copy[0];
    imaginary = copy[1];
  }
  //getters
  //float getReal()const {return real;}
  //float getImg()const {return imaginary;}
  int operator[](int pos)const {
    if(pos == 0)
    return real;
    else if(pos == 1)
    return imaginary;
  }
  int& operator[](int pos){
    if(pos == 0)
    return real;
    else
    return imaginary;
  }
  //setters
  void setReal(float r){real = r;}
  void setImg(float i){imaginary = i;}
  friend istream& operator>>(istream& in, Complex& temp){
    float r, i;
    in>>r>>i;
    temp.setReal(r);
    temp.setImg(i);
    return in;
  }
  //print complex no.
  void print()const {
    cout<<real<<" ";
    imaginary>=0 ? cout<<"+ "<<imaginary<<"i" : cout<<"- "<<-imaginary<<"i";
  }
  friend ostream& operator<<(ostream& out, const Complex& temp){
    temp.print();
    return out;
  }
  //Assign values to a complex no. using '='
  void operator=(const Complex& temp){
    real = temp[0];
    imaginary = temp[1];
  }
  void operator=(float num){
    real = num;
    imaginary = 0;
  }
  /*friend operator=(float& num, const Complex& temp){
    if(temp[1] == 0){
      num =
    }
  }*/
  //Negate a complex no.
  Complex& operator-(){
    static Complex temp;
    temp.real = -real;
    temp.imaginary = -imaginary;
    return temp;
  }
  //Compare two complex no.
  int equals(const Complex& temp){
    if(real == temp[0] && imaginary == temp[1])
    return 1;
    else
    return 0;
  }
  int operator==(const Complex& temp)const{
    if(real == temp[0] && imaginary == temp[1])
    return 1;
    else
    return 0;
  }
  int operator!=(const Complex& temp)const{
    if(real == temp[0] && imaginary == temp[1])
    return 0;
    else
    return 1;
  }
  int operator==(float num)const{
    if((*this)[0] == num && (*this)[1] == 0)
    return 1;
    else
    return 0;
  }
  int operator!=(float num)const{
    if((*this)[0] == num && (*this)[1] == 0)
    return 0;
    else
    return 1;
  }
  friend int operator==(float num, const Complex& temp){
    if(num == temp[0] && 0 == temp[1])
    return 1;
    else
    return 0;
  }
  friend int operator!=(float num, const Complex& temp){
    if(num == temp[0] && 0 == temp[1])
    return 0;
    else
    return 1;
  }
  //Add two complex no.
  Complex& add(const Complex& temp){
    static Complex ans;
    ans.real = real+temp[0];
    ans.imaginary = imaginary+temp[1];
    return ans;
  }
  Complex& operator+(const Complex& temp){
    static Complex ans;
    ans.real = real+temp[0];
    ans.imaginary = imaginary+temp[1];
    return ans;
  }
  Complex& operator+(float num){
    static Complex ans;
    ans.real = real+num;
    ans.imaginary = imaginary;
    return ans;
  }
  friend Complex& operator+(float num, const Complex& temp){
    static Complex ans;
    ans.real = temp[0]+num;
    ans.imaginary = temp[1];
    return ans;
  }
  //Subtract two complex no.
  Complex& sub(const Complex& temp){
    static Complex ans;
    ans.real = real-temp[0];
    ans.imaginary = imaginary-temp[1];
    return ans;
  }
  Complex& operator-(const Complex& temp){
    static Complex ans;
    ans.real = real-temp[0];
    ans.imaginary = imaginary-temp[1];
    return ans;
  }
  Complex& operator-(float num){
    static Complex ans;
    ans.real = real-num;
    ans.imaginary = imaginary;
    return ans;
  }
  friend Complex& operator-(float num, const Complex& temp){
    static Complex ans;
    ans.real = num-temp[1];
    ans.imaginary = -temp[1];
    return ans;
  }
  //Conjugate of a complex no,
  Complex& operator!()const{
    static Complex ans((*this)[0], -(*this)[1]);
    return ans;
  }
  //Multiply two complex no.
  Complex& mul(const Complex& temp)const{
    static Complex ans;
    ans.real = ((*this)[0]*temp[0] - (*this)[1]*temp[1]);
    ans.imaginary = ((*this)[0]*temp[1] + (*this)[1]*temp[0]);
    return ans;
  }
  Complex& operator*(const Complex& temp)const{
    static Complex ans;
    ans.real = (*this)[0]*temp[0] - (*this)[1]*temp[1];
    ans.imaginary = (*this)[0]*temp[1] + (*this)[1]*temp[0];
    return ans;
  }
  Complex& operator*(float num)const{
    static Complex ans;
    ans.real = (*this)[0]*num;
    ans.imaginary = (*this)[1]*num;
    return ans;
  }
  friend Complex& operator*(float num, const Complex& temp){
    static Complex ans;
    ans.real = temp[0]*num;
    ans.imaginary = temp[1]*num;
    return ans;
  }
  //Divide two complex no.
  Complex& operator/(float num)const{
    static Complex ans;
    ans.real = (*this)[0]/num;
    ans.imaginary = (*this)[1]/num;
    return ans;
  }
  Complex& operator/(const Complex& temp)const{
    static Complex ans;
    float x = (temp*(!temp))[0];
    ans = ((*this) * (!temp))/x;
    return ans;
  }
  friend Complex& operator/(float num, const Complex& temp){
    static Complex ans;
    float x = (temp*(!temp))[0];
    x = num/x;
    ans = x*temp;
    return ans;
  }

  //destructor
  ~Complex(){}
};//EOC
int main(int argc, char const *argv[]) {
  Complex b(2, 3);
  Complex a = b;
  cout<<a<<" "<<b<<endl;
  Complex c(5);
  std::cout << c << '\n';
  Complex d = 5+a+2;
  Complex f = 5-!d;
  Complex g = d*f;
  Complex h = g/f;
  std::cout << "d: " <<d<< '\n';
  std::cout << "f: "<< f << '\n';
  std::cout << "g: "<< g << '\n';
  std::cout << "h: " <<h<< '\n';
  if(3 != b)
  cout<<"A&B are equal"<<endl;
  if(5 == c)
  cout<<"A & C are not equal"<<endl;
  Complex x(2, 3);
  std::cout << "X: "<<x << '\n';
  x[0] = 7;
  std::cout << "X new: "<< x << '\n';
  return 0;
}
