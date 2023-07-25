#include "fila.h"

#include <string>

using namespace std;

Fila::Fila() {
  primeiro_ = nullptr;
  ultimo_ = nullptr;
  tamanhoFila = 0;
}

string Fila::primeiro() {
  return primeiro_->chave;
}

string Fila::ultimo() {
  return ultimo_->chave;
}

bool Fila::vazia() {
  return (primeiro_ == nullptr) && (ultimo_ == nullptr);
}

void Fila::Inserir(string k) {
  // Pedir espaço na memória
  No* no = (No*) new No();

  // Preencheu as propriedades
  no->chave = k;
  no->proximo = nullptr;

  // Adicionando na fila
  if (vazia()) {
    primeiro_ = no;
  } else {
    ultimo_->proximo = no;
  }

  ultimo_ = no;

  tamanhoFila++;
}

void Fila::Remover() {
  No* tmp = primeiro_;

  if (primeiro_ == ultimo_) {
    ultimo_ = nullptr;
  }

  primeiro_ = primeiro_->proximo;

  delete tmp;

  tamanhoFila--;
}

int Fila::tamanho() {
  return tamanhoFila;
}

Fila::~Fila() {
  while(!vazia()) {
    Remover();
  }
}