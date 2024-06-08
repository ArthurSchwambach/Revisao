#include <stdio.h>


void Funcionario(float SB, int Q, int C, float *SL, float *VA) {

  float plano_saude = 605.50 + (0.01 * SB * Q);

  float adicional_vae;
  if (C == 1) {
    adicional_vae = 0.10 * SB;
  } else if (C == 2) {
    adicional_vae = 0.05 * SB;
  } else if (C == 3) {
    adicional_vae = 0.01 * SB;
  } else {
    adicional_vae = 0; 
  }

  *VA = 1201.25 + (0.01 * SB * Q) + adicional_vae;
  *SL = SB - plano_saude;
}

int main(void) {
  int escolhas = 0;
  float SB, SL, VA;
  int Q, C;

  do {
    printf("Menu de Escolhas:\n");
    printf("1 - Inserir Funcionário\n");
    printf("0 - Sair do Programa\n");
    scanf("%d", &escolhas);

    if (escolhas == 0) {
      printf("Saindo do programa...\n");
      break;
    } else if (escolhas == 1) {
      printf("Digite seu salário bruto:\n");
      scanf("%f", &SB);

      if (SB < 1201.25) {
        printf("Seu salário é menor que 1201.25!\n");
        continue;
      }

      printf("Digite a quantidade de dependentes:\n");
      scanf("%d", &Q);

      if (Q < 0) {
        printf("Quantidade de dependentes não pode ser menor que 0!\n");
        continue;
      }

      printf("Digite sua classificação (1: OPERACIONAL, 2: TÁTICO, 3: "
             "ESTRATÉGICO):\n");
      scanf("%d", &C);

      if (C != 1 && C != 2 && C != 3) {
        printf("Classificação inválida! Deve ser 1, 2 ou 3.\n");
        continue;
      }

      Funcionario(SB, Q, C, &SL, &VA);

      printf("Seu salário líquido: R$ %.2f\n", SL);
      printf("Seu vale alimentação é: R$ %.2f\n", VA);
    } else {
      printf("Erro! Valor não aceito.\n");
      printf("Encerrando programa...\n");
    }

  } while (escolhas != 0);

  return 0;
}
