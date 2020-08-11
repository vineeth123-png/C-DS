#include <iostream>
#include <stdlib.h>
using namespace std;

template<class T=float>
class Matrix
{
	public:
		int x,y;// 2-dimensions
		T** mat;
		
	public:
		Matrix (int x=1,int y=1)
		{
			this->x=x;
			this->y=y;
			mat=new(T* [x]);
			for (int i=0;i<x;i++)
			{
				mat[i]=new(T [y]);	
			}
			
			for (int i=0;i<x;i++)
			{
				for (int j=0;j<y;j++)
				{
					mat[i][j]=(T)0;
				}
			}	
		}
		~Matrix()
		{
			for (int i=0;i<x;i++)
			{
				delete []mat[i];
			}
			delete mat;
		}
		
		Matrix (Matrix& M2)
		{ // =
			this->x=M2.x,this->y=M2.y;
			mat=new(T* [x]);
			for (int i=0;i<x;i++)
			{
				mat[i]=new(T [y]);	
			}
			
			for (int i=0;i<x;i++)
			{
				for (int j=0;j<y;j++)
				{
					mat[i][j]=M2.mat[i][j];
				}
			}
		}
		//mult
		Matrix & operator * (Matrix&M2){
			
			int x2,y2;
			x2=M2.x;y2=M2.y;
			if (y!=x2)
			{
				static Matrix<T> ans;
				cout<<"Multiplication not possible"<<endl;
				return ans;
			}
			else
			{
				static Matrix<T> ans(x,y2);
				for (int i=0;i<x;i++)
				{
					for (int j=0;j<y2;j++)
					{
						for (int k=0;k<y;k++)
						{
							ans.mat[i][j]+=mat[i][k]*M2.mat[k][j];
						}
					}
				}
				
				return ans;
			}
		}
		// add
		Matrix & operator + (Matrix&M2){
			
			if (x==M2.x&&y==M2.y)
			{	
				static Matrix<T> ans(x,y);
				for (int i=0;i<x;i++)
				{
					for (int j=0;j<y;j++)
					{
						ans.mat[i][j]=mat[i][j]+M2.mat[i][j];
					}
				}
				return ans;
			}
			else
			{
				static Matrix<T> ans;
				cout<<"Addition not posible"<<endl;
				return ans;
			}
		}
		//sub
		Matrix & operator - (Matrix&M2){
			
			if (x==M2.x&&y==M2.y)
			{	
				static Matrix<T> ans(x,y);
				for (int i=0;i<x;i++)
				{
					for (int j=0;j<y;j++)
					{
						ans.mat[i][j]=mat[i][j]-M2.mat[i][j];
					}
				}
				return ans;
			}
			else
			{
				static Matrix<T> ans;
				cout<<"Subtraction not posible"<<endl;
				return ans;
			}
		}
		
		Matrix & operator = (const Matrix&M2){
			this->x=M2.x,this->y=M2.y;
			mat=NULL;
			mat=new(T* [x]);
			for (int i=0;i<x;i++)
			{
				mat[i]=new(T [y]);	
			}
			
			for (int i=0;i<x;i++)
			{
				for (int j=0;j<y;j++)
				{
					mat[i][j]=M2.mat[i][j];
				}
			}
		}
		
		Matrix & operator / (T deno){
			static Matrix<T> ans(x,y);
			
			if (deno==0.0)
			{
				cout<<"Division by Zero is not possible"<<endl;
				return ans;
			}
			
			for (int i=0;i<x;i++){
				for (int j=0;j<y;j++){
					ans.mat[i][j]=(T)((float)mat[i][j]/(float)deno);
				}
			}
			return ans;
		}
		
		bool operator == (Matrix &M){
			bool cmp;
			if (x!=M.x||y!=M.y){
				return false;
			}
			else{
				cmp=true;
				for (int i=0;i<x;i++){
					for (int j=0;j<y;j++){
						if (mat[i][j]!=M.mat[i][j]){
							cmp=false;
							break;
						}
					}
				}
				return cmp;
			}
		}
		
		float operator () (int a,int b){
			if (a<0||a>=x||b<0||b>=y){
				cout<<"Out of Bound Access"<<endl;
				return (float)(-1);
			}
			else{
				return (float)mat[a][b];
			}
		}
		
		// determinant
		Matrix<T>& cofactor(Matrix<T> &matrix,int pre,int n)
		{
			static Matrix<T> res(n-1,n-1);
			int col=0;
			for (int j=0;j<n;j++)
			{
				if (j!=pre)
				{
					int w=0;
					for (int i=1;i<n;i++)
					{
						res.mat[w++][col]=matrix.mat[i][j];
					}
					col++;
				}
			}
			return res;
		}
		
		int determinant(Matrix<T>& M)
		{
			if (M.x!=M.y){
				cout<<"Determinant not possible"<<endl;
				return -1;
			}
			
			int n=M.x;
			
			if (n==1)
			return M.mat[0][0];
			
			int val=0;
			for (int i=0;i<n;i++)
			{
				Matrix<T> coff=cofactor((*this),i,n);
				if (i&1)
				{
					val+=(-1)*(M.mat[0][i])*determinant(coff);
			    }
				else
				{
					val+=(M.mat[0][i])*determinant(coff);
				}
				// delete coff;
			}
			
			return val;
		}
		
		//Transpose
		Matrix<T>& Transpose(){
			if (x!=y)
			{
				static Matrix<T> ans;
				cout<<"Transpose not possible"<<endl;
				return ans;
			}
			int n=x;// x=y
			static Matrix<T> ans(n,n);
			for (int i=0;i<n;i++){
				for (int j=0;j<n;j++){
					ans.mat[i][j]=(mat[j][i]);
				}
			}
			return ans;
		}
		
		// inverse inv(A)=trans(A)/det(A),det(A)!=0
		Matrix<T>& inverse(){
			
			if (x!=y){
				static Matrix<T> inv;
				cout<<"Inverse not Possible"<<endl;
				return inv;
			}
			else{
				T detA=determinant((*this));
				
				if (detA!=0){
					Matrix<T> trans=(*this).Transpose();
					
					static Matrix<T> inv=(trans/detA);
				
					return inv;
				}
				else{
					static Matrix<T> inv;
					cout<<"Inverse not Possible"<<endl;
					return inv;//empty inv
				}
			}
		}
		
		Matrix<T>& operator ! (){
			static Matrix<T> inv=(*this).inverse();
			return inv;
		} 
		
		void * operator new(size_t size) 
	    { 
	        void * p = ::new Matrix();
	        return p; 
	    } 
	  
	    void operator delete(void * p) 
	    {
	        delete p; 
	    }
		
		template <typename U>// all instantiations of this template are my friends
		friend istream & operator >> (istream &cin,  Matrix<U> &M); 
		template <typename U>
		friend ostream & operator << (ostream &cout, Matrix<U> &M);		
};

template<class T>
istream & operator >> (istream &cin,Matrix<T> &M) 
{   
	cout<<"Enter the Matrix Elements"<<endl;
	for (int i=0;i<M.x;i++)
	{
		for (int j=0;j<M.y;j++)
		{
			cin>>M.mat[i][j];
		}
	}		
    return cin; 
}
template<class T>
ostream & operator << (ostream &cout,Matrix<T> &M) 
{ 
	for (int i=0;i<M.x;i++)
	{
		for (int j=0;j<M.y;j++)
		{
			cout<<M.mat[i][j]<<" ";
		}
		cout<<endl;
	}		
    return cout; 
} 

int main()
{
	Matrix<> mat1(2,2),mat2(2,2);
	cin>>mat1>>mat2;
	
	cout<<endl<<mat1<<endl<<mat2<<endl;
	
	Matrix<> res1;
	res1=mat1+mat2;
	cout<<res1<<endl;
	Matrix<> res2=mat1-mat2;
	cout<<res2<<endl;
	Matrix<> res3;
	res1=mat1*mat2;
	cout<<res1<<endl;
	Matrix<> inv=!mat1;
	cout<<inv<<endl;
	
	if (mat1==mat2){
		cout<<"Equal"<<endl;
	}
	else{
		cout<<"Not equal"<<endl;
	}
	
	float val=mat1(1,1);
	cout<<val<<endl;
	
	Matrix<>* Mat1=new Matrix<>(2,2);
	cin>>(*Mat1);
	cout<<(*Mat1);
	
	// you can do operations as you want :)
	
	return 0;
}

