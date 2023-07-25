#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string entrada;
    string line;
    while(getline(cin, line)){
    if (line.empty()) {
      break;
    }
    entrada += " " + line;
  }

    map<string, int> contador;
    string palavra_atual;
    bool dentro_de_palavra = false;

    // percorre cada caractere da entrada
    for (char c : entrada) {
        if (c!= ' ') {
            // se o caractere é uma letra, adiciona à palavra atual
            palavra_atual += c;
            dentro_de_palavra = true;
        } else if (dentro_de_palavra) {
            // se acabou uma palavra, adiciona ao contador e reseta a palavra atual
            ++contador[palavra_atual];
            palavra_atual = "";
            dentro_de_palavra = false;
        }
    }

    // se a entrada terminou com uma palavra, adiciona ao contador
    if (dentro_de_palavra) {
        ++contador[palavra_atual];
    }

    // encontra a palavra mais repetida
    string mais_repetida;
    int vezes_repetida = 0;
    for (const auto& par : contador) {
        if (par.second > vezes_repetida) {
            mais_repetida = par.first;
            vezes_repetida = par.second;
        }
    }

    // imprime a palavra mais repetida
    cout << "Palavra mais comum: " << mais_repetida ;

    return 0;
}
