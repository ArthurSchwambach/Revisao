#include <stdio.h>

float IMC(float Massa, float Altura, char Sexo) {
  if (Sexo == 'F') {
    return 1.03 * (Massa / (Altura * Altura));
  } else {
    return 0.97 * (Massa / (Altura * Altura));
  }
}

int main(void) {

  float massa = 0, altura = 0;
  char sexo = 0;
  int escolhas = 0;

  do {

    printf("\nMenu de Escolhas:\n");
    printf("1 - Inserir Aluno\n");
    printf("0 - Sair do Programa\n");
    scanf("%i", &escolhas);

    if (escolhas == 0) {
      printf("Encerrando programa!\n");
      break;
    }

    if (escolhas != 1 && escolhas != 0) {
      printf("ERRO! Valor Inválido!\n");
      printf("Encerrando programa!\n");
      break;
    }

    if (escolhas == 1) {
      printf("Digite sua Altura:\n");
      scanf("%f", &altura);
      printf("Digite sua Massa:\n");
      scanf("%f", &massa);
      printf("Digite seu Gênero:\n");
      scanf("%s", &sexo);
    }

    if (altura <= 0 || massa <= 0 || (sexo != 'F' && sexo != 'M')) {
      if (massa <= 0) {
        printf("Massa não pode ser 0 ou negativa.\n");
      }
      if (altura <= 0) {
        printf("Altura não pode ser 0 ou negativa.\n");
      }
      if (sexo != 'F' && sexo != 'M') {
        printf("Digite 'M' ou 'F'\n");
      }
    } else {
      printf("Seu IMC é %f\n", IMC(massa, altura, sexo));
    }
  } while (escolhas != 0);

  return 0;
}
