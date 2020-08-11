#include<iostream>
using namespace std;
template<class T = long long int>
class Matrix{
	T** matrix;
        int rows, columns;
	public:
	Matrix(){
		*matrix = NULL;
	}
	//Matrix row and column values has to be given via the constructor and there's no other way
	Matrix(int rowsIn = 0, int columnsIn = 0){
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
  void input(T value, int row, int column){
		if(row >= rows || column >= columns){
			cout<<"Invalid call"<<endl;
			return ;
		}
	  matrix[row][column] = value;
	}
	int getRows() const{
		return rows;
	}
	int getColumns() const{
		return columns;
	}
	void inputMatrix(){
		cout<<"Enter the values of the matrix row wise"<<endl;
		for(int i=0; i<rows; i++)
			for(int j=0; j<columns; j++){
				int value;
				cin>>value;
				input(value, i, j);
			}
	}
  //overload >> operator
  friend istream& operator>>(istream& in, Matrix& m){
    cout<<"Enter the values of a "<<rows<<" X "<<columns<<" Matrix object:"<<"\n";
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < columns; j++) {
        /* code */
        in>>matrix[i][j];
      }
    }
    return in;
  }
  int getValue (int row, int column) const{
		if(row >= rows || column >= columns){
                        cout<<"Invalid call"<<endl;
                        return -1;
                }
	        return matrix[row][column];
	}
        void display() const{
		cout<<"The values of the matrix are:"<<endl;
        for(int i=0; i<rows; i++){
                for(int j=0; j<columns; j++)
                        cout<<matrix[i][j]<<"\t";
                cout<<endl;
        }
        }
	//displays the matrix which is formed by multiplication
        Matrix matrixMultiply(const Matrix& m2){
		if(columns != m2.getRows()){
			cout<<"Operatio not possible"<<endl;
			Matrix ptr;
			return ptr;
		}
		//cout<<"Cheeck"<<endl;
		Matrix ans(rows, m2.getColumns());
        for(int i = 0; i<rows; i++){
                //matrix 1's row elements are taken
                for(int j=0; j<m2.getColumns(); j++){
                        //matrix 2's column elements are taken and multiplied
                        ans.input(0, i, j);
			//int a = 0;
                        for(int k = 0; k<columns; k++){
                              int x = ans.getValue(i, j);
                              int y = m2.getValue(k, j);
                              int z  = x + y * matrix[i][k];
                              ans.input(z, i, j);
                        }
			//input(a, i, j);
			//ans.display();
                }
        }
	return ans;
        }
	//stores in the matrix through which its called
	Matrix sumWith(const Matrix& m2){
		if(rows != m2.getRows() || columns != m2.getColumns()){
			Matrix ans;
			//Matrix& ans1 = ans;
			cout<<"operation not possible"<<endl;
			return ans;
		}
		//cout<<"CHECK"<<endl;
		Matrix ans(rows, columns);
		//cout<<"MMM"<<endl;
		//Matrix& ans1 = ans;
		for(int i=0; i<rows; i++){
			for(int j=0; j<columns; j++){
				ans.input(matrix[i][j] + m2.getValue(i, j), i, j);
			}
		}
		//ans.display();
		return ans;
	}
	//function to subtract matrices stores in the matrix thpugh which its called
	Matrix subWith(const Matrix& m2){
                if(rows != m2.getRows() || columns != m2.getColumns()){
                        cout<<"operation not possible"<<endl;
			Matrix ans1;
                        return ans1;
                }
                Matrix ans1(rows, columns);
                for(int i=0; i<rows; i++){
                        for(int j=0; j<columns; j++){
                                ans1.input(matrix[i][j] - m2.getValue(i, j), i, j);
                        }
                }
                //ans1.display();
		return ans1;
        }
	~Matrix(){
		cout<<"Deleting the matrix"<<endl;
		if(*matrix != NULL){
			for(int i=0; i<rows; i++)
                        delete[] matrix[i];
			delete[] matrix;
		}
	}
};
int main(){
	Matrix<> m1(2, 2);
	Matrix<> m2(2, 2);
	cout<<"Enter the value of matrix 1"<<endl;
	m1.inputMatrix();
	m1.display();
	cout<<"Enter the values of matrix 2"<<endl;
	m2.inputMatrix();
	m2.display();
	Matrix<> m3(m2);
	m3.display();
	Matrix<> m4 = m1.matrixMultiply(m2);
	m4.display();
	return 0;
}
