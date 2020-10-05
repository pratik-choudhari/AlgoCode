package complex;
import java.math.*;

public class Complex {
	double real;
	double imaginery;
	Complex(double real,double imaginery){
		this.real = real;
		this.imaginery = imaginery;
	}
	static void add(Complex c1, Complex c2) {
		Complex temp = new Complex(0,0);
		temp.real = c1.real + c2.real;
		temp.imaginery =c1.imaginery + c2.imaginery;
		System.out.println(temp.real + "+"+temp.imaginery+"i");
	}
	static void sub(Complex c1, Complex c2) {
		Complex temp = new Complex(0,0);
		temp.real = c1.real - c2.real;
		temp.imaginery =c1.imaginery - c2.imaginery;
		System.out.println(temp.real + "+"+temp.imaginery+"i");
	}
	static void multiply(Complex c1, Complex c2) {
		Complex temp = new Complex(0,0);
		temp.real = c1.real * c2.real;
		temp.imaginery =c1.imaginery * c2.imaginery;
		System.out.println(temp.real + "+"+temp.imaginery+"i");
	}
	static void mod(Complex c1) {
		Double temp = Math.sqrt((c1.real*c1.real)+(c1.imaginery*c1.imaginery));
		System.out.println(temp);
	}
	static void division(Complex c1, Complex c2) {
		Complex temp = new Complex(0,0);
		temp.real = c1.real / c2.real;
		temp.imaginery =c1.imaginery / c2.imaginery;
		System.out.println(temp.real + "+"+temp.imaginery+"i");
	}
	
	public static void main(String[] args) {
		Complex c1 = new Complex(2,4);
		Complex c2 = new Complex(4,2);
		add(c1,c2);
		sub(c1,c2);
		multiply(c1,c2);
		division(c1,c2);
		mod(c1);
		mod(c2);
		
	}

}
