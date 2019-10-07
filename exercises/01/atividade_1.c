/*

Para facilitar a compreensão do código irei utilizar a seguinte nomenclatura
para referir a arvore:

        P1
       /  \
      P2  P3
    / | \   \
   P4 P5 P6  P7

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

void removeLowercase (char *s);
void removeVogals (char *s);

int main()
{
  clock_t t;
  double time_taken;
  t = clock();
  int status, length;
  char string[100];
  pid_t idProcesso; // Processo pai "P1"
  pid_t idChild;    // Identificador de filhos
  printf("[LOG] Sou o processo P1: %d\n", getpid());

  printf("Digite uma string de no máximo 100 caracteres: \n");
  fgets(string, sizeof(string), stdin);

  idProcesso = fork();

  switch (idProcesso) {
    case 0: // Processo "P2"
      printf("[LOG] Sou o processo P2: %d  |  Meu pai P1: %d\n", getpid(), getppid());
      idProcesso = fork();
      switch (idProcesso) {
        case 0: // Processo "P4"
          removeLowercase(string);
          printf("[LOG] Sou o processo P4: %d  |  Meu pai P2: %d\n", getpid(), getppid());
          break;
        default: // Continua em "P2"
          idProcesso = fork(); // Processo "P5"
          switch (idProcesso) {
            case 0:  // P5
              printf("[LOG] Sou o processo P5: %d  |  Meu pai é P2: %d\n", getpid(), getppid());
              break;
            default: // Continue P5
              idProcesso = fork(); // Processo "P6"
              switch (idProcesso) {
                case 0: // P6
                  removeVogals(string);
                  printf("[LOG] Sou o processo P6: %d  |  Meu pai é P2: %d\n", getpid(), getppid());
                  break;
                default:
                  idChild = wait(&status);
                  printf("[LOG] Sou o processo P2: %d  |  Já esperei pelo meu filho: %d\n", getpid(), idChild);
                  idChild = wait(&status); 
                  printf("[LOG] Sou o processo P2: %d  |  Já esperei pelo meu filho: %d\n", getpid(), idChild);
                  idChild = wait(&status); 
                  printf("[LOG] Sou o processo P2: %d  |  Já esperei pelo meu filho: %d\n", getpid(), idChild);
                  break;
              };
          };
      };
      break;
    default: // Continua no processo raiz P1
      idProcesso = fork(); // Cria filho de P1
      switch (idProcesso) {
        case -1:
          exit(-1); //ERROR
        case 0: // P3
          printf("[LOG] Sou o processo P3: %d  |  Meu pai é P1: %d\n", getpid(), getppid());
          idProcesso = fork(); // P3 cria filho P7
          switch (idProcesso) {
            case -1:
              exit(-1); //ERROR
            case 0:  // P7
              printf("[LOG] Sou o processo P7: %d  |  Meu pai é P3: %d\n", getpid(), getppid());
              length = strlen(string);
              printf("- Tamanho da string informada dado por P7: %d\n", (length - 1));
              break;
            default: // Continua P3
                idChild = wait(&status); // P3 espera por P7
                printf("[LOG] Sou o processo P3: %d  |  Já esperei pelo meu filho: %d\n", getpid(), idChild);
              break;
          }
          break;
        default: // Continua P1
          idChild = wait(&status);
          printf("[LOG] Sou o processo P1: %d  |  Já esperei pelo meu filho: %d\n", getpid(), idChild);
          idChild = wait(&status);
          printf("[LOG] Sou o processo P1: %d  |  Já esperei pelo meu filho: %d\n", getpid(), idChild);
          printf("[LOG] Sou o processo P1 de novo, meu id é: %d\n", getpid());
          t = clock() - t;
          time_taken = ((double)t) / CLOCKS_PER_SEC;
          printf("Tempo usado em segundos: %f\n", time_taken);
      };
      break;
  };
};


void removeLowercase (char *s){
    int c, j = 0;
    char newString[100];
    while (s[c] != '\0'){
        if ((s[c] >= 'a') && (s[c] <= 'z')) {
            // É uma letra minuscula
        } else {
            newString[j] = s[c];
            j++;
        };
        c++;
    };
    s = newString;
    printf("- Removido caracteres minúsculos por P4: %s", newString);
};


void removeVogals (char *s){
    int c, j = 0;
    char newString[100];
    while (s[c] != '\0'){
        if ((s[c] == 'a') || (s[c] == 'A') || (s[c] == 'e') || (s[c] == 'E') || 
        (s[c] == 'i') || (s[c] == 'I') || (s[c] == 'o') || (s[c] == 'O') ||
        (s[c] == 'u') || (s[c] == 'U')) {
            // É uma lvogal
        } else {
            newString[j] = s[c];
            j++;
        };
        c++;
    };
    s = newString;
    printf("- Removido vogais por P6: %s", newString);
};