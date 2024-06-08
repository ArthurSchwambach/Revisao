#include <stdio.h>
#include <string.h>
#define tamanho 100

void Duplicador(char *palavra, char *palavraDuplicada) {
  int i = 0, j = 0;

  for (i = 0; palavra[i] != '\0'; i++) {
    palavraDuplicada[j++] = palavra[i];
    palavraDuplicada[j++] = palavra[i];
  }
}

int main(void) {
  char palavra[tamanho];
  char palavraDuplicada[2 * tamanho + 1];

  do {
    printf("Digite uma palavra:\n");
    scanf("%s", palavra);

    if (strcmp(palavra, "sair") != '\0') {
      Duplicador(palavra, palavraDuplicada);
      printf("Nova Palavra: %s\n", palavraDuplicada);
    }
  } while (strcmp(palavra, "sair") != '\0');

  return 0;
}
