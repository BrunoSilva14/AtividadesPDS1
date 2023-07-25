#include "venda.hpp"
#include <iostream>
using namespace std;
#include <iomanip>
#include <string>
Venda::~Venda() {
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
  for(const auto pedido_feito: m_pedidos){
    delete pedido_feito;
  }
}

void Venda::adicionaPedido(Pedido* p) {
  // TODO: Implemente este metodo
  m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
  float valor_total=0;
  int count=0;
  for(const auto pedidos_feitos :m_pedidos){
    count=count+1;
    cout<<"Pedido "<< count<< endl;
    cout<<pedidos_feitos->resumo()<<endl;
    valor_total=valor_total+pedidos_feitos->calculaTotal();
  }
    cout<<"Relatorio de Vendas"<<endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<"Total de vendas: R$ "<<valor_total<<endl;
    cout<<"Total de pedidos: "<<m_pedidos.size()<<endl;
}