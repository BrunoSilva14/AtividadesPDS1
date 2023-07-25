// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
real_=0;
imag_=0;
}


Complexo::Complexo(double a, double b) {
real_=a;
imag_=b;
}

double Complexo::real() {

  return real_;
}

double Complexo::imag() {
  return imag_;
}

bool Complexo::igual(Complexo x) {
  
  
  return (real_ == x.real() && imag_ == x.imag());
  
}

void Complexo::Atribuir(Complexo x) {
  real_= x.real();  
  imag_=x.imag();
}

double Complexo::modulo() {
  double a = pow(real_, 2);
  double b = pow(imag_, 2);
  return sqrt(a + b);
}

Complexo Complexo::conjugado() {
  return Complexo(real_, -imag_);
}

Complexo Complexo::simetrico() {
  return Complexo(-real_, -imag_);;
}

Complexo Complexo::inverso() {
  return Complexo(real_/((real_)*(real_)+(imag_)*(imag_)), -imag_ /((real_)*(real_)+(imag_)*(imag_)));
}

Complexo Complexo::somar(Complexo y) {
   //somar parte real

  
  //somar parte imaginária
  return Complexo(real_ + y.real(), imag_ + y.imag());
}

Complexo Complexo::subtrair(Complexo y) {
   //subtrair parte real

  
  //subtrair parte imaginária
  return Complexo(real_ - y.real(), imag_ - y.imag());;
}

Complexo Complexo::multiplicar(Complexo y) {
 //multiplicar parte real

  
//multiplicar parte imaginária
  return Complexo((real_*y.real())-(imag_*y.imag()), (real_*y.imag())+(y.real()*imag_));
}

Complexo Complexo::dividir(Complexo y) {
  //dividir parte real


  //dividir parte imaginária
  return Complexo(((real_*y.real())+(imag_*y.imag()))/(y.real()*y.real()+y.imag()*y.imag()),((y.real()*imag_)-(real_*y.imag()))/(y.real()*y.real()+y.imag()*y.imag()));
}
