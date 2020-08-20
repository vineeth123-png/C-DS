#include<bits/stdc++.h>
using namespace std;
class Tool
{
public:
  int strength;
  char type;
  Tool(char t,int s=0){
    strength = s;
    type = t;
  }
  ~Tool(){}
};
/*0:Scissors, 1:Paper, 2:Rock */
/*Implement class Scissors */
class Scissors : public Tool{
public:
  Scissors(int s=0) : Tool('s', s){}
  ~Scissors(){}
  bool fight(Tool& x){
    if(x.type=='s'){
      if(strength>x.strength)
      return 1;
      else
      return 0;
    }else if(x.type=='r'){
      if(strength/2>x.strength)
      return 1;
      else
      return 0;
    }else if(x.type=='p'){
      if(2*strength>x.strength)
      return 1;
      else
      return 0;
    }
    return 0;
  }
};
/*Implement class Paper */
class Paper : public Tool{
public:
  Paper(int s=0) : Tool('p', s){}
  ~Paper(){}
  bool fight(Tool& x){
    if(x.type=='p'){
      if(strength>x.strength)
      return 1;
      else
      return 0;
    }else if(x.type=='s'){
      if(strength/2>x.strength)
      return 1;
      else
      return 0;
    }else if(x.type=='r'){
      if(2*strength>x.strength)
      return 1;
      else
      return 0;
    }
    return 0;
  }
};
/*Implement class Rock */
class Rock : public Tool{
public:
  Rock(int s=0) : Tool('r', s){}
  ~Rock(){}
  bool fight(Tool& x){
    if(x.type=='r'){
      if(strength>x.strength)
      return 1;
      else
      return 0;
    }else if(x.type=='p'){
      if(strength/2>x.strength)
      return 1;
      else
      return 0;
    }else if(x.type=='s'){
      if(2*strength>x.strength)
      return 1;
      else
      return 0;
    }
    return 0;
  }
};
int main() {
	// Example main function
	// You may add your own testing code if you like
	Scissors s1(5);
	Paper p1(7);
	Rock r1(15);
	cout << s1.fight(p1) << p1.fight(s1) << endl;
	cout << p1.fight(r1) << r1.fight(p1) << endl;
	cout << r1.fight(s1) << s1.fight(r1) << endl;
	return 0;
}
