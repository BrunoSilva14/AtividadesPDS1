#include "pedido.hpp"
#include <iostream>
using namespace std;
#include <string>
Pedido::~Pedido() {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
  for(const auto n_pedidos: m_produtos){
     delete n_pedidos;
}
}
void Pedido::setEndereco(const std::string& endereco) {
  // TODO: Implemente este metodo.
  m_endereco=endereco;
}

float Pedido::calculaTotal() const {
  // TODO: Implemente este metodo.
  float valor_total=0;
  for (const auto n_produtos : m_produtos) {
    valor_total+=n_produtos->getQtd()*n_produtos->getValor();
  }

  return valor_total;
}

void Pedido::adicionaProduto(Produto* p) {
  // TODO: Implemente este metodo.
  m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
  string relatorio= "";
    for (const auto n_produtos : m_produtos) {
      relatorio += n_produtos->descricao() + "\n";
      }
      relatorio += "Endereco: " + m_endereco;

      return relatorio;
}