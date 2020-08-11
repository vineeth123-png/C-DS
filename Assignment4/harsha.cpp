#include<iostream>
using namespace std;
class Matrix{
	int** matrix;
        int rows, columns;
	public:
	Matrix(){
		*matrix = NULL;
		rows = 0;
		columns = 0;
	}
	//Matrix row and column values has to be given via the constructor and there's no other way
	Matrix(int rowsIn, int columnsIn){
//cout<<"constructer-1"<<endl;
		rows = rowsIn;
		columns = columnsIn;
                matrix = new int* [rows];
                for(int i = 0; i<rows; i++)
                        (matrix)[i] = new int [columns];
		for(int i=0; i<rows; i++){
			for(int j=0; j<columns; j++){
				matrix[i][j] = 0;
			}
		}
        }
	Matrix(const Matrix& m1){
//cout<<"constructor-2"<<endl;
		rows = m1.getRows();
		columns = m1.getColumns();
/*
		if(*matrix != NULL){
                        for(int i=0; i<rows; i++)
                        delete[] matrix[i];
			delete[] matrix;
                }
*/
//		cout<<"Check"<<endl;
		matrix = new int* [rows];
                for(int i = 0; i<rows; i++)
                        (matrix)[i] = new int [columns];
                for(int i=0; i<rows; i++){
                        for(int j=0; j<columns; j++){
                                matrix[i][j] =m1.getValue(i, j);
                        }
                }
//cout<<"const2 end"<<endl;
	}
        void input(int value, int row, int column){
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
		cout<<"Cheeck"<<endl;
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
//			ans.display();
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
	void subWith(const Matrix& m2){
                if(rows != m2.getRows() || columns != m2.getColumns()){
                        cout<<"operation not possible"<<endl;
			//Matrix ans1;
                        return;
                }
                //Matrix ans1(rows, columns);
                for(int i=0; i<rows; i++){
                        for(int j=0; j<columns; j++){
                                input(matrix[i][j] - m2.getValue(i, j), i, j);
                        }
                }
                //ans1.display();
		//return ans1;
        }
	~Matrix(){
//cout<<"Deleting the matrix"<<endl;
		if(*matrix != NULL){
			for(int i=0; i<rows; i++)
                        delete[] matrix[i];
			delete[] matrix;
		}
	}
};
int main(){
	Matrix m1(2, 2);
	Matrix m2(2, 2);
	cout<<"Enter the value of matrix 1"<<endl;
	m1.inputMatrix();
	m1.display();
	cout<<"Enter the values of matrix 2"<<endl;
	m2.inputMatrix();
	m2.display();
	Matrix &ma = m1;
	Matrix &mb = m2;
//cout<<"test point -1:"<<endl;
	//Matrix m3(m1.getRows(), m2.getColumns());
	//Matrix& m3 = m1.sumWith(m2);
	//cout<<"ENter"<<endl;
	Matrix m3(m1.sumWith(m2));
//	cout<<"Enter"<<endl;
//	m3.display();
//	cout<<"Enter"<<endl;
	m3.display();
//	ma.display();
	m1.subWith(m2);
m1.display();
	//mb.display();
//	ma.display();
//cout<<"no  errors upto test point-2"<<endl;
//	Matrix result;
//	result = m1.matrixMultiply(m2);
Matrix result=m1.matrixMultiply(m2);
	//ma.display();
	result.display();
	//m4->display();
	//delete[] m4;
	//cout<<"hi"<<endl;
	//Matrix* m3 = m1.matrixMultiply(m2);
	//cout<<"hi1"<<endl;
	//m3->display();
	//m1.subWith(m2);
	//m5->display();
	//delete[] m5;
	//cout<<m3.rows<<"\t"<<m3.columns<<endl;
	return 0;
}
