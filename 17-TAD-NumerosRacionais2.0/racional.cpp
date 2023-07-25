#include "racional.h"
#include <cmath>
#include <iostream>
using namespace std;
int mdc(int x, int y) {
    int resto;
    x=abs(x);
    while (y != 0) {
        resto = x % y;
        x = y;
        y = resto;
    }
    return x;
}
void Racional::Simplificar() {
  if (den<0){
    den=-den;
  }
  int mdc1=mdc(num, den);
  num=num/mdc1;
  den=den/mdc1;
  }
  


Racional::Racional() {
  num=0;
  den=1;
  Simplificar();
}

Racional::Racional(int n)  {
  num=n;
  den=1;
  Simplificar();
}

Racional::Racional(int n, int d) {
  num=n;
  den=d;
  Simplificar();
}

int Racional::numerador() const {
  return num;
}

int Racional::denominador() const {
  return den;
}
Racional Racional::operator-() const{
  return Racional(-num, den); 
}


Racional Racional::operator+(Racional k) const {
  int mdc2= k.denominador()*den;
  int num2= num*k.denominador();
  int numout= den*k.numerador();
  int somaout= num2+numout;
  
  return Racional(somaout, mdc2);
}

Racional Racional::operator-(Racional k) const {
  int mdc2=k.denominador()*den;
  int num2= num*k.denominador();
  int numout=den*k.numerador(); 
  int subout= num2-numout;
  return Racional(subout,mdc2);
  
}

Racional Racional::operator*(Racional k) const {
   int multnum= num*k.numerador();
  int multden= den*k.denominador();
  return Racional(multnum,multden);
}

Racional Racional::operator/(Racional k) const {
   int multnum= num*k.denominador();
  int multden= den*k.numerador();
  return Racional(multnum, multden);
}
Racional::operator float() const { 
  return num / (float) den;
}
Racional::operator string() const{
  return to_string(num) + "/" + to_string(den);
}
ostream& operator<<(ostream& out, Racional r){
out<<(string) r ;
  return out;
}
istream& operator>>(istream& in, Racional& r){
  in >>r.num;
  in >>r.den;
  r.Simplificar();
  return in;
  }