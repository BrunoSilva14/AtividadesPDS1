#include <iostream>
using namespace std;
int main() {
int i; //variável para ler a palavra e contadores de vogais
int countA=0;
int countE=0;
int countI=0;
int countO=0;
int countU=0;
string palavra;
cout<< "Digite uma palavra: ";
cin >> palavra;
for (i=0;palavra[i]!='\0';i++) { //função para o programa percorrer a palavra inteira
  if(palavra[i] == 'a'){ // função para comparar a letra da palavra com uma vogal e somar nos contadores
      countA = countA +1;
  }
  else if(palavra[i] == 'e'){
      countE = countE +1;
  }
  else if(palavra[i] == 'i'){
      countI = countI +1;
  }
  else if(palavra[i] == 'o'){
      countO = countO +1;
  }
  else if(palavra[i] == 'u'){
      countU = countU +1;
  }}
if (countA > 0) { //parte para impressão de valores diferentes de 0, assim como no exemplo da questão
cout << "a " << countA<< endl;
}
if (countE > 0) {
cout << "e " << countE<< endl;
}
if (countI > 0) {
cout << "i " << countI<< endl;
}
if (countO > 0) {
cout << "o " << countO<< endl;
}
if (countU > 0) {
cout << "u " << countU<< endl;
}
  return 0;
}
