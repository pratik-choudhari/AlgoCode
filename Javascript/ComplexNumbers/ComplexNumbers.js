class Complex {

    constructor(real, imaginary) {
        this.real = 0;
        this.imaginary = 0;
        this.real = (typeof real === 'undefined') ? this.real : parseFloat(real);
        this.imaginary = (typeof imaginary === 'undefined') ? this.imaginary : parseFloat(imaginary);
    }
    add(other) {
        return new Complex(this.real + other.real, this.imaginary + other.imaginary);
    }
    sub(other) {
        return new Complex(this.real - other.real, this.imaginary - other.imaginary);
    }
    mult(other) {
        var r = this.real * other.real - this.imaginary * other.imaginary;
        var i = this.real * other.imaginary + this.imaginary * other.real;
        return new Complex(r, i);
    }
    mod() {
        return Math.sqrt(this.real * this.real + this.imaginary * this.imaginary);
    }
    div(other) {
        var r = this.real * other.real + this.imaginary * other.imaginary;
        var i = this.imaginary * other.real - this.real * other.imaginary;
        var m = Math.pow(other.mod(), 2);
        if (m == 0) {
            return NaN;
        }
        return new Complex(r / m, i / m);
    }
    print(){
    console.log(this.real.toString() + '+' + this.imaginary.toString() + 'i');
    }
}

//testing
input1 = '2 1'
input2 = '5 6'

a = input1.split(' ');
b = input2.split(' ');

a = new Complex(a[0], a[1]);
b = new Complex(b[0], b[1]);

a.add(b).print();
a.sub(b).print();
a.mult(b).print();
a.div(b).print();
console.log(a.mod());
console.log(b.mod());