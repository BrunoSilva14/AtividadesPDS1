#include <iostream>
#include <string>
#include <map>

#include "Estoque.hpp"

using namespace std;

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  estoque_[mercadoria] += qtd;
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  if(!(estoque_.find(mercadoria) != estoque_.end())) {
    cout << mercadoria << " inexistente" << endl;
    return;
  }

  int estoquequantidade = estoque_[mercadoria];
  if (estoquequantidade < qtd) {
    cout << mercadoria << " insuficiente" << endl;
    return;
  }

  estoque_[mercadoria] -= qtd;
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) {
  return estoque_[mercadoria];
}

void Estoque::imprime_estoque() const {
  map<string, int>::const_iterator it = estoque_.begin();
  while (it != estoque_.end()) {
    string nomeDoProduto = it->first;
    int quantidadeDoProduto = it->second;

    cout << nomeDoProduto << ", " << quantidadeDoProduto << endl;

    it++;
  }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  map<string, int>::const_iterator it = rhs.estoque_.begin();
  while (it != rhs.estoque_.end()) {
    string nomeDoProduto = it->first;
    int quantidadeDoProduto = it->second;

    this->add_mercadoria(nomeDoProduto, quantidadeDoProduto);

    it++;
  }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  map<string, int>::const_iterator it = rhs.estoque_.begin();
  while (it != rhs.estoque_.end()) {
    string nomeDoProduto = it->first;
    int quantidadeDoProduto = it->second;

    this->sub_mercadoria(nomeDoProduto, quantidadeDoProduto);

    it++;
  }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  map<string, int>::const_iterator operadorEsquerda = lhs.estoque_.begin();
  while (operadorEsquerda != lhs.estoque_.end()) {
    string produtoDaEsquerda = operadorEsquerda->first;
    int quantidadeDaEsquerda = operadorEsquerda->second;
    if(!(rhs.estoque_.find(produtoDaEsquerda) != rhs.estoque_.end())) {
      return false;
    }
    int quantidadeDoProdutoDaDireita = rhs.estoque_[produtoDaEsquerda];
    if (!(quantidadeDoProdutoDaDireita > quantidadeDaEsquerda)) {
      return false;
    }
    operadorEsquerda++;
  }
  return true;
}


bool operator > (Estoque& lhs, Estoque& rhs) {
  map<string, int>::const_iterator operadorDireita = rhs.estoque_.begin();
  while (operadorDireita != rhs.estoque_.end()) {
    string produtoDaDireita = operadorDireita->first;
    int quantidadeDaDiretia = operadorDireita->second;
    if(!(lhs.estoque_.find(produtoDaDireita) != lhs.estoque_.end())) {
      return false;
    }
    if (!(lhs.estoque_[produtoDaDireita] > quantidadeDaDiretia)) {
      return false;
    }
    operadorDireita++;
  }
  return true;
}