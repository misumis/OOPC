#include <iostream>
#include <math.h>
using namespace std;
class Complex
{
private:
	double Real, Imag;
public:
        Complex (double Real, double Imag);
        Complex & operator= (const Complex & s);
        Complex operator- () const;
        Complex & operator= (double co);
        Complex operator+ (const Complex& co) const;
        Complex & operator-= (Complex co);
        Complex & operator+= (Complex co);
        friend Complex operator / (Complex c1, Complex c2);
        friend Complex operator * (Complex c1, Complex c2);
        friend Complex operator- (Complex, Complex);
        friend ostream & operator << (ostream & s, const Complex & c);
        double real(void);
        double imaginative(void);
        double amplitude(void);
        double phase(void);
        Complex conjugate(void);
        Complex& operator *= (Complex s2);
        Complex& operator/=(Complex co);
        bool operator == (Complex co);
};
	Complex::Complex (double Real = 0, double Imag = 0)
	{
	    this->Real = Real;
	    this->Imag = Imag;
	}
		
	ostream & operator << (ostream & s, const Complex & c)
	{
	    s << "( " << c.Real << " , " << c.Imag << " )";
	    return s;
	}

	
	Complex::Complex & operator= (const Complex & s)
	{
	    Real = s.Real;
	    Imag = s.Imag;
	    return *this;
	}

	Complex::Complex operator- () const
	{
	    return Complex(-Real,-Imag);
	}

	Complex::Complex & operator= (double co)
	{
	    Real = co;
	    Imag = 0;
	    return *this;
	}
	
	Complex::Complex operator+ (const Complex& co) const
	{
	    Complex n;
	    n.Real = this->Real + co.Real;
	    n.Imag = this->Imag + co.Imag;
	    return n;
	}

	Complex::Complex & operator-= (const Complex& co)
	{
	    Real -= co.Real;
	    Imag -= co.Imag;
	    return *this;
	}
	
	Complex::Complex & operator+= (const Complex& co)
	{
	    Real += co.Real;
	    Imag += co.Imag;
	    return *this;
	}

	friend Complex operator- (Complex, Complex);
	
	double Complex::real(){
	    return Real;
	}

	double Complex::imaginative(){
	    return Imag;
	}
	double Complex::amplitude(){
	    return sqrt(Real*Real+Imag*Imag);
	}
	double Complex:: phase(){
	    
		return atan(Imag/Real);
	    
	}
	Complex Complex:: conjugate(){
	    Complex n (Real, -Imag);
	    return n;
	}
	friend Complex operator ~(Complex s1);
	Complex& operator *= (Complex s2){
	    double tmpReal, tmpImag;
	    tmpReal = Real*s2.real()-Imag*s2.imaginative();
	    tmpImag = Real*s2.imaginative() + s2.real()*Imag;
	    Real = tmpReal;
	    Imag = tmpImag;
	    return * this;    
	}
	Complex::Complex& operator/=(Complex s1){
	    double tmpReal, tmpImag;
	    tmpReal = (Real*s1.real()+Imag*s1.imaginative())/(s1.real()*s1.real()+s1.imaginative()*s1.imaginative());
	    tmpImag=(Imag*s1.real()-Real*s1.imaginative())/(s1.real()*s1.real()+s1.imaginative()*s1.imaginative());
	    Real=tmpReal;
	    Imag=tmpImag;
	    return *this;
	}
	bool Complex::operator == (Complex s1){
	    if(Real == s1.real() && Imag == s1.imaginative()){
		return true;
	    }
	    else{
		return false;
	    }
	}

};



inline Complex operator - (Complex s1, Complex s2)
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

//pastebin.com/zlbUDkfw