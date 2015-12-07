#include <iostream>
#include <fstream>
using namespace std;

class Bad_Alloc {};
class Out_Of_Range {};
class Wrong_Dimmension {};

class Matrix
{
	class Cref;
	public:
		struct CMatrix;
		CMatrix* data;
		Matrix();
		Matrix(unsigned int rows, unsigned int columns);
		Matrix(const Matrix& m);
		Matrix(istream& in);
		~Matrix();
		friend Matrix operator+ (Matrix& m1, Matrix& m2);
		friend Matrix operator* (Matrix& m1, Matrix& m2);
		friend Matrix operator- (Matrix& m1, Matrix& m2);
		Matrix& operator*= (Matrix m);
		Matrix& operator+= (Matrix m);
		Matrix& operator-= (Matrix m);
		bool operator== (Matrix& m);
		friend ostream & operator << (ostream & s, const Matrix & m);
		void write(unsigned int row, unsigned int col, double num);
		double read(unsigned int row, unsigned int col);
		void check (unsigned int row, unsigned int col);
		Matrix& operator= (const Matrix& m);
		Cref operator() (unsigned int a, unsigned int b);
};

struct Matrix::CMatrix 
{
	unsigned int counter;
	unsigned int Rows;
	unsigned int Columns;
	double** matrix;
	
	CMatrix(unsigned int rows, unsigned int columns)
	{
		Rows = rows;
		Columns = columns;
	
		try
		{
			matrix = new double* [rows];
		}catch(bad_alloc&)
		{
			throw Bad_Alloc();
		}
		
		try
		{
			for(unsigned int i = 0; i < rows; i++)
				matrix[i] = new double[columns];
		}catch(bad_alloc&)
		{
			delete[] matrix;
			throw Bad_Alloc{};
		}
		
		for(unsigned int r=0; r<rows; r++)
			for(unsigned int c=0; c<columns; c++)
				matrix[r][c] = 0; 
				
		counter = 1;
	};
	
	~CMatrix()
	{
		for(unsigned int i = 0; i < Rows; i++)
			delete[] matrix[i];
			
		delete[] matrix;
	};
	
	CMatrix* detach()
	{
		if(counter == 1)
			return this;
		
		CMatrix* m = new CMatrix(Rows, Columns);
		counter--;
		return m;	
	};	
};

class Matrix::Cref
{
	friend class Matrix;
	Matrix& m;
	unsigned int row, col;
	public:
		operator double()
		{
			return m.read(row, col);
		};	
		Matrix::Cref& operator= (double num)
		{
			m.write(row, col, num);
			return *this;
		};
		Cref(Matrix &m, unsigned int a, unsigned int b): m(m), row(a), col(b)
		{
		};
};

void Matrix::check (unsigned int row, unsigned int col)
{
	if(data->Rows <= row || data->Columns <= col)
		throw Out_Of_Range();
}

Matrix::Cref Matrix::operator() (unsigned int row, unsigned int col)
{
	check(row, col);
	return Matrix::Cref(*this, row, col);
}

double Matrix::read(unsigned int row, unsigned int col)
{
	return data->matrix[row][col];
}

void Matrix::write(unsigned int row, unsigned int col, double num)
{
	data = data->detach();
	data->matrix[row][col] = num;
}

Matrix::Matrix()
{
	data = new CMatrix(0,0);
}

Matrix::Matrix(unsigned int rows, unsigned int columns)
{
	data = new CMatrix(rows, columns);
}

Matrix::Matrix(const Matrix& m)
{
	m.data->counter++;
	data = m.data;
}

Matrix::Matrix(istream& in)
{
	unsigned int row, col;
	
	in >> row;
	in >> col;
	
	data = new CMatrix(row, col);
	
	for(unsigned int r=0; r<row; r++)
		for(unsigned int c=0; c<col; c++)
		    in >> data->matrix[r][c];
	
}

Matrix::~Matrix()
{
	data->counter--;
	if(data->counter == 0)
		delete data;
}

Matrix& Matrix::operator= (const Matrix& m)
{
	m.data->counter++;
	if(--data->counter == 0)
		delete data;
	data = m.data;
	return *this;	
}

Matrix operator+ (Matrix& m1, Matrix& m2)
{
	if((m1.data->Rows != m2.data->Rows) || (m1.data->Columns != m2.data->Columns))
		throw Wrong_Dimmension();
	
	Matrix temp(m1.data->Rows, m1.data->Columns);
	
	for(unsigned int r=0; r<m1.data->Rows; r++)
		for(unsigned int c=0; c<m1.data->Columns; c++)
			temp.data->matrix[r][c] = m1.data->matrix[r][c] + m2.data->matrix[r][c];
			
	return temp;
}

Matrix operator* (Matrix& m1, Matrix& m2)
{
	if(m1.data->Rows != m2.data->Columns)
		throw Wrong_Dimmension();
		
	Matrix temp(m1.data->Rows, m1.data->Rows);
	
	for(unsigned int r=0; r<m1.data->Rows; r++)
		for(unsigned int c=0; c<m1.data->Rows; c++)
			for(unsigned int k=0; k<m1.data->Rows; k++)
				temp.data->matrix[r][c] += m1.data->matrix[r][k] * m2.data->matrix[k][c];
				
	return temp;
}

Matrix operator- (Matrix& m1, Matrix& m2)
{
	if((m1.data->Rows != m2.data->Rows) || (m1.data->Columns != m2.data->Columns))
		throw Wrong_Dimmension();
	
	Matrix temp(m1.data->Rows, m1.data->Columns);
	
	for(unsigned int r=0; r<m1.data->Rows; r++)
		for(unsigned int c=0; c<m1.data->Columns; c++)
			temp.data->matrix[r][c] = m1.data->matrix[r][c] - m2.data->matrix[r][c];
			
	return temp;
}

Matrix& Matrix::operator+= (Matrix m)
{
	*this = *this + m;
	return *this;
}

Matrix& Matrix::operator-= (Matrix m)
{
	*this = *this - m;
	return *this;
}

Matrix& Matrix::operator*= (Matrix m)
{
	*this = *this * m;
	return *this;
}

bool Matrix::operator== (Matrix& m)
{
	int cmp = 1;
	
	if(((*this).data->Rows != m.data->Rows) || ((*this).data->Columns != m.data->Columns))
		throw Wrong_Dimmension();
	
	for(unsigned int r=0; r<m.data->Rows; r++)
		for(unsigned int c=0; c<m.data->Columns; c++)
			if((*this).data->matrix[r][c] != m.data->matrix[r][c])
				cmp = 0;
				
	if(cmp == 0)
		return false;
		
	return true;
}

ostream & operator << (ostream & s, const Matrix & m)
{
	if(m.data->Rows == 0 || m.data->Columns == 0)
		throw Wrong_Dimmension();
		
	s << endl << "[";
	
	for(unsigned int r=0; r<m.data->Rows; r++)
	{
		for(unsigned int c=0; c<m.data->Columns; c++)
		{
			s << m.data->matrix[r][c];
			if(c != m.data->Columns - 1)
				s << " ";
		}	
		
		if(r == m.data->Rows - 1)
			s << "]";
			
		s << endl;	
	}
	
	s << endl;
	
	return s;
}
