#include "dicionario.h"

Dicionario::Dicionario() {}

int Dicionario::tamanho() {
  return elementos_.size();
}

bool Dicionario::pertence(string chave) {
  for (const Elemento& elemento : elementos_) {
    if (elemento.chave == chave) {
      return true;
    }
  }
  return false;
}

string Dicionario::menor() {
  if (elementos_.empty()) {
    throw DicionarioVazio(); // Exceção: dicionário vazio.
  }

  string menor_chave = elementos_.front().chave;
  for (const Elemento& elemento : elementos_) {
    if (elemento.chave < menor_chave) {
      menor_chave = elemento.chave;
    }
  }
  return menor_chave;
}

string Dicionario::valor(string chave) {
  for (const Elemento& elemento : elementos_) {
    if (elemento.chave == chave) {
      return elemento.valor;
    }
  }
  throw ChaveInexistente{chave}; // Exceção: chave não encontrada.
}

void Dicionario::Inserir(string chave, string valor) {
  if (pertence(chave)) {
    throw ChaveRepetida{chave}; // Exceção: chave já existe.
  }

  Elemento novo_elemento;
  novo_elemento.chave = chave;
  novo_elemento.valor = valor;
  elementos_.push_back(novo_elemento);
}

void Dicionario::Remover(string chave) {
  for (auto it = elementos_.begin(); it != elementos_.end(); ++it) {
    if (it->chave == chave) {
      elementos_.erase(it);
      return;
    }
  }
  throw ChaveInexistente{chave}; // Exceção: chave não encontrada.
}

void Dicionario::Alterar(string chave, string valor) {
  for (Elemento& elemento : elementos_) {
    if (elemento.chave == chave) {
      elemento.valor = valor;
      return;
    }
  }
  throw ChaveInexistente{chave}; // Exceção: chave não encontrada.
}

Dicionario::~Dicionario() {
  elementos_.clear();
}

