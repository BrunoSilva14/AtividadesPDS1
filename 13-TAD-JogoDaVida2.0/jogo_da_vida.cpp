#include "jogo_da_vida.h"

JogoDaVida::JogoDaVida(int l, int c) {
  vivas_.resize(l, std::vector<bool>(c, false));
}

bool JogoDaVida::viva(int i, int j) {
  return vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j) {
  vivas_[i][j] = false;
}

void JogoDaVida::Reviver(int i, int j) {
  if ((i >= linhas() || i < 0) || (j >= colunas() || j < 0)) {
    ExcecaoCelulaInvalida error;
    error.linha = i;
    error.coluna = j;
    throw error;
  }

  vivas_[i][j] = true;
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y) {
  int count = 0;
  int l = vivas_.size();
  int c = vivas_[0].size();

  int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int i = 0; i < 8; i++) {
    int nx = (x + dx[i] + l) % l;
    int ny = (y + dy[i] + c) % c;
    if (vivas_[nx][ny]) {
      count++;
    }
  }

  return count;
}

void JogoDaVida::ExecutarProximaIteracao() {
  int l = vivas_.size();
  int c = vivas_[0].size();

  std::vector<std::vector<bool>> proxima_iteracao = vivas_;

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      int vizinhas_vivas = NumeroDeVizinhasVivas(i, j);

      if (vivas_[i][j]) {
        if (vizinhas_vivas < 2 || vizinhas_vivas > 3) {
          proxima_iteracao[i][j] = false;
        }
      } else {
        if (vizinhas_vivas == 3) {
          proxima_iteracao[i][j] = true;
        }
      }
    }
  }

  vivas_ = proxima_iteracao;
}
