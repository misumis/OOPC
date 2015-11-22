#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class IndexOutOfBounds{};

class poly{
private:
	int polyOrder;
	vector<int> orders;
	vector<float> data;
public:
	poly()
	{
	  polyOrder = 0;
	orders.push_back(0);
	data.push_back(0);
	};
	poly(int zeroCoeff)
	{
	polyOrder = 0;
	orders.push_back(0);
	data.push_back(zeroCoeff);
	};
	poly(const poly& secondPoly)
	{
	  unsigned int i;
	  for( i = 0 ; i < secondPoly.orders.size() ; i++ )
	  {
		  orders.push_back( secondPoly.orders[i] );
		  data.push_back( secondPoly.data[i] );
	  }
	  polyOrder = secondPoly.polyOrder;
  };
	float& operator[] (int position)
	{
	int index = this->searchFor( position );
	if( index != -1 )
		return data[index];
	else
	{
		if( position > polyOrder )
			polyOrder = position;
		orders.push_back( position );
		data.push_back( 0 );
		this->sort();
		return data[this->searchFor( position )];
	
	}
	};
	int searchFor(int position)
	{
	unsigned int i = 0;
	while( i < orders.size() )
	{
		if( position == orders[i] )
			return i;
		++i;
	}
	return -1;
	};
	void sort(void)
	{ 
	  unsigned int i, n = orders.size();
	  int tmpOrder;
	  float tmpData;
	  
	  do
	  {
		  for( i = 0 ; i < ( n - 1 ) ; i++ )
		  {
			  if( orders[i+1] > orders[i] )
			  {					
				  tmpOrder = orders[i+1];
				  orders[i+1] = orders[i];
				  orders[i] = tmpOrder;
				  
				  tmpData = data[i+1];
				  data[i+1] = data[i];
				  data[i] = tmpData;
			  }
		  }
		  n = n - 1;
	  }while( n > 1);
	};
	float at(int position)
	{
	cout << "position: " << position << endl;
	if( position > polyOrder )
	{
		throw IndexOutOfBounds();
	}
	int index = this->searchFor( position );
	if( index != -1 )
		return data[index];
	else
		return 0;
	};
	int order(void) const
	{
	return polyOrder;
	};

	
	poly& operator= (const poly& secondPoly);
	friend ostream & operator << (ostream& str, const poly& polyToPrint);
	double operator() (double point);	
	poly& operator*= (const poly& secondPoly);
	poly& operator+= (const poly& secondPoly);

};

inline poly operator* (const poly& firstPoly, const poly& secondPoly)
{
	poly tmp( secondPoly );
	return tmp *= firstPoly;
}

inline poly operator+ (const poly& firstPoly, const poly& secondPoly)
{
	poly tmp( secondPoly );
	return tmp += firstPoly;
}

poly& poly::operator= (const poly& secondPoly)
{
	if( this == &secondPoly )
		return *this;
	
	unsigned int i;
	orders.clear();
	data.clear();
	for( i = 0 ; i < secondPoly.orders.size() ; i++ )
	{
		orders.push_back( secondPoly.orders[i] );
		data.push_back( secondPoly.data[i] );
	}
	polyOrder = secondPoly.polyOrder;
	
	return *this;
}

ostream& operator << (ostream& str, const poly& polyToPrint)
{
	unsigned int i;
	
	str << " p(x) = " ;
	for( i = 0 ; i < polyToPrint.orders.size() ; i++ )
	{
		double tmp = fabs(polyToPrint.data[i]);
		
		if( polyToPrint.orders[i] == 0 )
			str << tmp;
		else if(polyToPrint.data[i+1] < 0 )
			str << tmp << " * x^" << polyToPrint.orders[i] << " - ";
		else
			str << tmp << " * x^" << polyToPrint.orders[i] << " + ";
	}

	return str;
}

double poly::operator() (double point)
{
	double pointValue = 0;
	unsigned int i;
	
	for( i = 0 ; i < orders.size() ; i++ )
	{
		pointValue += data[i] * pow( point , orders[i] );
	}
	
	return pointValue;
}

poly& poly::operator*= (const poly& secondPoly)
{
	poly tmp;
	unsigned int i, j;
	int index;
	
	tmp.polyOrder = 0;
	for( i = 0 ; i < orders.size() ; i++ )
	{
		for( j = 0 ; j < secondPoly.orders.size() ; j++ )
		{
			index = tmp.searchFor( orders[i] + secondPoly.orders[j] );
			if( index != -1 )
				tmp.data[index] += data[i] * secondPoly.data[j];
			else
			{
				tmp.orders.push_back( orders[i] + secondPoly.orders[j] );
				tmp.data.push_back( data[i] * secondPoly.data[j] );
			}
			if(  ( orders[i] + secondPoly.orders[j] ) > tmp.polyOrder )
				tmp.polyOrder = orders[i] + secondPoly.orders[j];
		}
	}
	tmp.sort();
	*this = tmp;
	
	return *this;
}

poly& poly::operator+= (const poly& secondPoly)
{
	poly tmp;
	unsigned int i;
	int index;
	
	tmp.polyOrder = 0;
	for( i = 0 ; i < orders.size() ; i++ )
	{
		index = tmp.searchFor( orders[i] );
		if( index != -1 )
			tmp.data[index] += data[i];
		else
		{
			tmp.orders.push_back( orders[i] );
			tmp.data.push_back( data[i] );
		}
		if( orders[i] > tmp.polyOrder )
			tmp.polyOrder = orders[i];
	}
	
	for( i = 0 ; i < secondPoly.orders.size() ; i++ )
	{
		index = tmp.searchFor( secondPoly.orders[i] );
		if( index != -1 )
			tmp.data[index] += secondPoly.data[i];
		else
		{
			tmp.orders.push_back( secondPoly.orders[i] );
			tmp.data.push_back( secondPoly.data[i] );
		}
		if( secondPoly.orders[i] > tmp.polyOrder )
			tmp.polyOrder = secondPoly.orders[i];
	}
	tmp.sort();
	*this = tmp;
	
	return *this;
}
