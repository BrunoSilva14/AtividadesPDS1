#include <iostream>
#include <vector>
using namespace std;
int main(){
int a;
int b;
int c;
cin>>a>>b>>c;
vector<vector<int>> mat1(a, vector<int>(b));
vector<vector<int>> mat2(b, vector<int>(c));
vector<vector<int>> mat3(a, vector<int>(c));
for(int m=0;m<a;m++){    //Função para receber a primeira matriz
  for(int n=0;n<b;n++){
    cin >> mat1[m][n];
}}
for(int m=0;m<b;m++){    //Função para receber a segunda matriz
  for(int n=0;n<c;n++){
    cin >> mat2[m][n];
  }
}
for(int m=0;m<a;m++) {   //Função para multiplicar as matrizes recebidas
        for(int n=0;n<c;n++) {
            int conta= 0;
            for(int mn=0; mn<b; mn++) {
                conta+= mat1[m][mn]*mat2[mn][n];
            }
            mat3[m][n]= conta;
        }
    }
    for (int m = 0; m < a; m++) {      //Função para imprimir o resultado da multiplicação das matrizes
        for (int n = 0; n < c; n++) {
            cout << mat3[m][n] << " ";
        }
        cout << endl;
    }
    
    return 0;
}