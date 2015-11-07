#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
    private:
	double Real, Imag;
    public:
	Complex ():Real (0), Imag (0)
    {
    };

	Complex (double co)
	{
	    Real = co;
	    Imag = 0;
	};

	Complex (double Real, double Imag)
	{
	    this->Real = Real;
	    this->Imag = Imag;
	};

	Complex & operator= (const Complex & s)
	{
	    Real = s.Real;
	    Imag = s.Imag;
	    return *this;
	};

	Complex operator- () const
	{
	    return Complex(-Real,-Imag);
	};

	Complex & operator= (double co)
	{
	    Real = co;
	    Imag = 0;
	    return *this;
	};

	Complex operator+ (const Complex& co) const
	{
	    Complex n;
	    n.Real = this->Real + co.Real;
	    n.Imag = this->Imag + co.Imag;
	    return n;
	};


	Complex & operator-= (Complex co)
	{
	    Real -= co.Real;
	    Imag -= co.Imag;
	    return *this;
	};

	friend Complex operator- (Complex, Complex);
	friend ostream & operator << (ostream & s, const Complex & c)
	{
	    s << "(" << c.Real << "," << c.Imag << ")";
	    return s;
	};
	//my work starts from here
	double real(void){
	    return Real;
	};
	double imaginative(void){
	    return Imag;
	};
	double amplitude(void){
	    return sqrt(Real*Real+Imag*Imag);
	};
	double phase(void){
	    if(Real > 0)
		return atan(Imag/Real);
	    else if(Real < 0 && Imag >= 0)
		return atan(Imag/Real) + M_PI;
	    else if(Real < 0 && Imag < 0)
		return atan(Imag/Real) - M_PI;
	    else if(Real == 0 && Imag >0)
		return M_PI/2.0;
	    else if(Real == 0 && Imag < 0)
		return -M_PI;
	    else{
		cerr << "Cannot calculate phase" << endl;
		return 0;
	    }
	};
	Complex conjugate(void){
	    Complex n (Real, -Imag);
	    return n;
	};
	friend Complex operator ~(Complex s1);
	Complex& operator *= (Complex s2){
	    double tmpReal, tmpImag;
	    tmpReal = Real*s2.real()-Imag*s2.imaginative();
	    tmpImag = Real*s2.imaginative() + s2.real()*Imag;
	    Real = tmpReal;
	    Imag = tmpImag;
	    return * this;    
	}
	Complex& operator/=(Complex s1){
	    double tmpReal, tmpImag;
	    tmpReal = (Real*s1.real()+Imag*s1.imaginative())/(s1.real()*s1.real()+s1.imaginative()*s1.imaginative());
	    tmpImag=(Imag*s1.real()-Real*s1.imaginative())/(s1.real()*s1.real()+s1.imaginative()*s1.imaginative());
	    Real=tmpReal;
	    Imag=tmpImag;
	    return *this;
	}
	bool operator == (Complex s1){
	    if(Real == s1.real() && Imag == s1.imaginative()){
		return true;
	    }
	    else{
		return false;
	    }
	}

};

    inline Complex
operator - (Complex s1, Complex s2)
{
    Complex n (s1);
    return n -= s2;
}
inline Complex operator ~(Complex s1){
    Complex n (s1);
    return n.conjugate();
}
Complex operator * (Complex s1, Complex s2){
    Complex n(s1);
    return n*=s2;
}
Complex operator / (Complex s1, Complex s2){
    Complex n(s1);
    return n /= s2;
}
#endif /* __Complex_H__ */
