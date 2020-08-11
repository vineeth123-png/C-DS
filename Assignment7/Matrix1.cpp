#include<iostream>
using namespace std;
template<class T = long long int>
class Matrix{
	T** matrix;
        int rows, columns;
	public:
  //constructors
	Matrix(){
    cout<<"Default Constructor"<<"\n";
		*matrix = NULL;
    rows = 0;
    columns = 0;
	}
  Matrix(int rowsIn, int columnsIn){
    cout<<"Constructor"<<"\n";
		rows = rowsIn;
		columns = columnsIn;
    matrix = new T* [rows];
    for(int i = 0; i<rows; i++)
      (matrix)[i] = new T [columns];
		for(int i=0; i<rows; i++){
			for(int j=0; j<columns; j++){
				matrix[i][j] = 0;
			}
		}
  }
	Matrix(const Matrix& m1){
    cout<<"Copy Constructor"<<"\n";
		rows = m1.getRows();
    columns = m1.getColumns();
		//cout<<"Check"<<endl;
		matrix = new T* [rows];
    for(int i = 0; i<rows; i++)
      (matrix)[i] = new T [columns];
    for(int i=0; i<rows; i++){
      for(int j=0; j<columns; j++){
        matrix[i][j] =m1.getValue(i, j);
      }
    }
	}
  //getters
  int getRows()const {return rows;}
  int getColumns()const {return columns;}
  int getValue (int row, int column) const{
    if(row >= rows || column >= columns){
      cout<<"Invalid call"<<endl;
      return -1;
    }
    return matrix[row][column];
  }
	//overload [] operator
	int operator[](int num){
		if(num == 0)
		return rows;
		else
		return columns;
	}
	T& operator()(int row, int column){
		T x = -1;
		if(row >= rows || column >= columns){
      cout<<"Invalid call"<<endl;
      return x;
    }
	  return matrix[row][column];
	}
	//overload << and >> operators
	friend istream& operator>>(istream& in, Matrix& m){
		cout<<"Enter the values of a "<<m.getRows()<<" X "<<m.getColumns()<<" Matrix object:"<<"\n";
    for (size_t i = 0; i < m.getRows(); i++) {
      for (size_t j = 0; j < m.getColumns(); j++) {
        /* code */
				T x;
        in>>x;
				m(i, j) = x;
      }
    }
    return in;
	}
	friend ostream& operator<<(ostream& out, Matrix& m){
		cout<<"The values of a "<<m.getRows()<<" X "<<m.getColumns()<<" Matrix object are:"<<"\n";
		for (size_t i = 0; i < m.getRows(); i++) {
      for (size_t j = 0; j < m.getColumns(); j++) {
        cout<<m(i, j)<<" ";
      }
			cout<<"\n";
    }
    return out;
	}
  //destructor
  ~Matrix(){
    cout<<"Deleting the matrix"<<endl;
		if(*matrix != NULL){
			for(int i=0; i<rows; i++)
                        delete[] matrix[i];
			delete[] matrix;
		}
  }
};//end of class
int main(){
  Matrix<> m1(2, 2);
  Matrix<> m2(2, 2);
	cin>>m2;
	cout<<m2;
  return 0;
}
