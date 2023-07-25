#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

void FilaDePrioridade::Adicionar(Pessoa p) {
lista_.push_back(p);
  return;
}

string FilaDePrioridade::RemoverMaiorPrioridade() {
  int maiorpriori = 0;
  Pessoa k;
  list<Pessoa>::iterator it= lista_.begin();
  while(it!=lista_.end()){
    if((*it).prioridade>maiorpriori){
      maiorpriori = (*it).prioridade;
      k = (*it);
    }
    it++;
  }
  lista_.remove(k);
  return(k.nome);
}

void FilaDePrioridade::Remover(string nome) {
  Pessoa k;
  list<Pessoa>::iterator it= lista_.begin();
  while(it!=lista_.end()){
    if((*it).nome==nome){
      k = (*it);
    }
    it++;
  
  }
lista_.remove(k);
}
int FilaDePrioridade::tamanho() {
  return lista_.size();
}

vector<string> FilaDePrioridade::listar() {
  lista_.sort([ ](Pessoa& a, Pessoa& b ){
       return a.prioridade > b.prioridade;
  });
  vector<string> v;
  for(Pessoa p:lista_)v.push_back(p.nome);
  return v; 
}