#include<bits/stdc++.h>
using namespace std;

class Complex{
private:
    double real, imag;

public:
    Complex(double r =0, double i = 0) : real(r), imag(i) { }
    friend double Mod(const Complex& A);
    friend const Complex Conjugate(const Complex& A);    
    friend const Complex Addition(const Complex& A, const Complex& B);
    friend const Complex Subtraction(const Complex& A, const Complex& B);
    friend const Complex Multiplication(const Complex& A, const Complex& B);    
    friend const Complex Division(const Complex& A, const Complex& B);
    friend void Print(const Complex& A);
};
double Mod(const Complex& A){
    double result = sqrt( pow(A.real, 2) + (pow(A.imag, 2)) ) ;
    return result;
}
const Complex Addition(const Complex& A, const Complex& B){
    Complex result;
    result.real = A.real + B.real;
    result.imag = A.imag + B.imag;
    return result;
}
const Complex Subtraction(const Complex& A, const Complex& B){
    Complex result;
    result.real = A.real - B.real;
    result.imag = A.imag - B.imag;
    return result;
}
const Complex Multiplication(const Complex& A,const Complex& B){
    Complex result;
    result.real = (A.real*B.real) - (A.imag * B.imag);
    result.imag = (A.imag * B.real) + (A.real * B.imag);
    return result;
}

const Complex Division(const Complex& A, const Complex& B){
    Complex result, ConjugateB;
    ConjugateB = Conjugate(B);
    Print(ConjugateB);
    auto modB = Mod(B);
    result = Multiplication(A, ConjugateB);
    result.real /= pow(modB, 2);
    result.imag /= pow(modB, 2);
    return result;
}

const Complex Conjugate(const Complex& A){
    Complex result;
    result.real = A.real;
    result.imag = -A.imag;
    return result;
}
void Print(const Complex& A){
    // cout << setprecision(2) << setw(2);
    if (A.imag > 0) {
        cout << setprecision(2) << A.real << " + "<< A.imag << "i" << endl;
    }
    else{
        cout << setprecision(2) << A.real << " - "<< A.imag * -1 << "i" << endl;
    }
        
}
int main(){
double a, b, c, d;
cout << "Input a and b: ";
cin >> a >> b;
cout << "Input c and d: ";
cin >> c >> d;
Complex A(a, b);
Complex B(c, d);
auto sum = Addition(A, B);
auto sub = Subtraction(A, B);
auto mul = Multiplication(A, B);
auto div = Division(A, B);
Print(sum);
Print(sub);
Print(mul);
Print(div);
cout << Mod(A) << endl;
cout << Mod(B) << endl;
}