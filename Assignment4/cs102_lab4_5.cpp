#include<iostream>
using namespace std;
template<class T>
class Vector{
	T arr[3];
	public:
	Vector(){
		arr[0] = 0.0;
		arr[1] = 0.0;
		arr[2] = 0.0;
	}
	Vector(T x, T y, T z){
		arr[0] = x;
		arr[1] = y;
		arr[2] = z;
	}
	Vector(const Vector& v1){
		arr[0] = v1.getX();
		arr[1] = v1.getY();
		arr[2] = v1.getZ();
	}
	T getX() const;
	T getY() const;
	T getZ() const;
	void setX(T x){
		arr[0] = x;
	}
	void setY(T y){
		arr[1] = y;
	}
	void setZ(T z){
		arr[2] = z;
	}
	void scalarMult(float scalar){
		for(int i=0; i<3; i++){
			arr[i] = arr[i] * scalar;
		}
	}
	T dotProduct(const Vector& v2){
		T ans = 0.0;
		ans = arr[0] * v2.getX() + arr[1] * v2.getY() + arr[2] * v2.getZ();
		return ans;
	}
	Vector addWith(const Vector& v2){
		Vector v3(arr[0] + v2.getX(), arr[1] + v2.getY(), arr[1] + v2.getZ());
		return v3;
	}
	Vector subWith(const Vector& v2){
		Vector v3(arr[0] - v2.getX(), arr[1] - v2.getY(), arr[1] - v2.getZ());
                return v3;
	}
	~Vector(){
		cout<<"Deleting vector"<<endl;
	}
};
template<class T>
inline T Vector<T>::getX() const{
        return arr[0];
}
template<class T>
inline T Vector<T>::getY() const{
                return arr[1];
        }
template<class T>
inline T Vector<T>::getZ() const{
                return arr[2];
        }
int main(){
	Vector <float> v1;
	Vector <float> v2(1.2, 3.4, 5.6);
	v1.setX(1.3);
	v2.scalarMult(8);
	v1.scalarMult(2.0);
	Vector <float> v3 = v1.addWith(v2);
	Vector <float> v4 = v1.subWith(v2);
	cout<<v1.getX()<<"  "<<v1.getY()<<"  "<<v1.getZ()<<endl;
	cout<<v2.getX()<<"  "<<v2.getY()<<"  "<<v2.getZ()<<endl;
	cout<<v3.getX()<<"  "<<v3.getY()<<"  "<<v3.getZ()<<endl;
	cout<<v4.getX()<<"  "<<v4.getY()<<"  "<<v4.getZ()<<endl;
	cout<<v1.dotProduct(v2)<<endl;
	return 0;
}
