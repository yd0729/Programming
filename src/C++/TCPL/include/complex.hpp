class complex {
  double re, im;  // representation: two doubles public:
 public:
  complex(double r, double i)
      : re{r}, im{i} {}                // construct complex from two scalars
  complex(double r) : re{r}, im{0} {}  // construct complex from one scalar
  complex() : re{0}, im{0} {}          // default complex: {0,0}

  double real() const { return re; }
  void real(double d) { re = d; }
  double imag() const { return im; }
  void imag(double d) { im = d; }

  complex& operator+=(complex z) {  // add to re and im and return the result
    re += z.re, im += z.im;
    return *this;
  }

  complex& operator-=(complex z) {
    re -= z.re, im -= z.im;
    return *this;
  }

  complex& operator*=(complex);  // deﬁned out-of-class somewhere
  complex& operator/=(complex);  // deﬁned out-of-class somewhere
};

complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; }
complex operator*(complex a, complex b) { return a *= b; }
complex operator/(complex a, complex b) { return a /= b; }

bool operator==(complex a, complex b) {  // equal
  return a.real() == b.real() && a.imag() == b.imag();
}
bool operator!=(complex a, complex b) { return !(a == b); }

void f(complex z) {
  complex a{2.3};  // construct {2.3,0.0} from 2.3
  complex b{1 / a};
  complex c{a + z*complex{1, 2.3}};

  // ...

  if (c != b) c = -(b / a) + 2*b;
}

void test(complex z1) {
  complex z2{z1};  // copy initialization
  complex z3;

  z3 = z2;  // copy assignment

  // ...

  

  
}