#ifndef VETOR_H_
#define VETOR_H_

#include <iostream>
#include <string>

using std::string;

template <typename Tipo> class Vetor {
public:
  Vetor(int inicio, int fim) : inicio_(inicio), fim_(fim) {
    elementos_ = new Tipo[fim - inicio + 1]();
  }

  void Redimensionar(int inicio2, int fim2) {
    Tipo *copia = new Tipo[fim2 - inicio2 + 1]();
    for (int i = inicio_; i <= fim_; i++) {
      if ((i >= inicio2) && (i <= fim2)) {
        copia[i - inicio2] = elementos_[i - inicio_];
      }
    }

    delete[] elementos_;
    elementos_ = copia;
    inicio_ = inicio2;
    fim_ = fim2;
  }

  Tipo &operator[](int i) { return elementos_[i - inicio_]; }

  ~Vetor() { delete[] elementos_; }

private:
  int inicio_;
  int fim_;
  Tipo *elementos_;
};

#endif