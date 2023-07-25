#include "jogo_da_vida.h"

JogoDaVida::JogoDaVida(int l, int c) {
  // Inicializa todas as células como mortas
  vivas_.resize(l, std::vector<bool>(c, false));
}

bool JogoDaVida::viva(int i, int j) {
  return vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j) {
  vivas_[i][j] = false;
}

void JogoDaVida::Reviver(int i, int j) {
  vivas_[i][j] = true;
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y) {
  int count = 0;
  int l = vivas_.size();
  int c = vivas_[0].size();

  // Verifica as células vizinhas no sentido horário começando pelo canto superior esquerdo
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

  // Cria uma cópia temporária do estado atual
  std::vector<std::vector<bool>> proxima_iteracao = vivas_;

  // Aplica as regras do Jogo da Vida para cada célula
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      int vizinhas_vivas = NumeroDeVizinhasVivas(i, j);

      if (vivas_[i][j]) {
        // Regra 1: Qualquer célula viva com menos de duas células vizinhas vivas morre
        // Regra 3: Qualquer célula viva com mais de três células vizinhas vivas morre
        if (vizinhas_vivas < 2 || vizinhas_vivas > 3) {
          proxima_iteracao[i][j] = false;
        }
      } else {
        // Regra 4: Qualquer célula morta com exatamente três células vizinhas vivas se torna viva
        if (vizinhas_vivas == 3) {
          proxima_iteracao[i][j] = true;
        }
      }
    }
  }

  // Atualiza o estado do jogo para a próxima iteração
  vivas_ = proxima_iteracao;
}