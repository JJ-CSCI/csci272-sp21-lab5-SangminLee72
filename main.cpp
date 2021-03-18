//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------
#include <iostream>
using namespace std;
// Write the assignment code here
class Real {
public:
  Real() {};

  explicit Real(double numer) {
    realNumber_ = numer;
  }

  double GetReal() {
    return realNumber_;
  }

  virtual Real operator*(const double &rhs) const {
    Real temp(realNumber_ * rhs);
    return temp;
  }

protected:
  double realNumber_;

};

class Complex: public Real {
public:
  Complex() {}
  explicit Complex(double realNumber, double imaginaryNumber) {
    realNumber_ = realNumber;
    imaginaryNumber_ = imaginaryNumber;
  }

  double GetImaginary() {
    return imaginaryNumber_;
  }

  Complex operator*(const double &rhs) {
    Complex temp(realNumber_ * rhs, imaginaryNumber_ * rhs);
    return temp;
  }

protected:
  double imaginaryNumber_;
};

class Surreal: public Complex {
public:
  explicit Surreal(double realNumber, double imaginaryNumber, double surreal) {
    realNumber_ = realNumber;
    imaginaryNumber_ = imaginaryNumber;
    surreal_ = surreal;
  }

  double GetSurreal() {
    return surreal_;
  }

  Surreal operator*(const double &rhs) {
    Surreal temp(realNumber_ * rhs, imaginaryNumber_ * rhs, surreal_ * rhs);
    return temp;
  }
protected:
  double surreal_;
};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------

TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
        REQUIRE( r.GetSurreal() == 60.0 );
    }
}
//------------------------------
