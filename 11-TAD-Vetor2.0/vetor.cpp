#include <iostream>
#include "vetor.h"
#include <string>

Vetor::Vetor(int inicio, int fim){
  if (fim - inicio < 0) {
    throw IntervaloVazio{inicio,fim};
  }
  inicio_ = inicio;
  fim_=fim;
elementos_ =new string[fim-inicio+1]; 
}

void Vetor::atribuir(int i, std::string valor){
    int diferenca = fim_ - inicio_;
  int index = i - inicio_;

  if ( (diferenca - index) < 0 || index < 0) {
    throw IndiceInvalido{inicio_,fim_,i};
  }

  elementos_[i-inicio_]=valor;
}

string Vetor::valor(int i) const{
     int diferenca = fim_ - inicio_;
  int index = i - inicio_;

  if ( (diferenca - index) < 0 || index < 0) {
    throw IndiceInvalido{inicio_,fim_,i};
  }
  string v=elementos_[i-inicio_];
  if(v==""){
    throw IndiceNaoInicializado{i};
  }
  
  return(v);
}
Vetor::~Vetor(){
  delete []elementos_;
}
