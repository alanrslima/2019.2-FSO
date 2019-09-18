#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

void removeLowercase();
void removeVogals();

char S[101];

int main(void)
{
    int i;
    pid_t p1002, p1004, p1006, p1007 ;

    printf("Digite uma string de no máximo 100 caracteres: \n");
    fgets(S, sizeof(S), stdin);

    if ((p1002 = fork()) == 0) {
        printf("Processo p1002 %d | %d \n", getpid(), getppid());
        if ((p1004 = fork()) == 0) {
            printf("Processo p1004 %d | %d \n", getpid(), getppid());
        } else {
            if ((p1006 = fork()) == 0) { 
                printf("Processo p1006 %d | %d \n", getpid(), getppid());
            } else {
                if ((p1007 = fork()) == 0) {
                    printf("Processo p1007 %d | %d \n", getpid(), getppid());
                } else {
                    // Continua no processo p1002
                };
            };
        };
    } else {
        if (fork() == 0) {
            printf("Processo p1003 %d | %d \n", getpid(), getppid());
            if (fork() == 0) { // p1005
                int length = strlen(S);
                exit(length - 1);
            } else { // p1003
                int l;
                wait(&l); // Recebendo retorno de p1005
                exit(WEXITSTATUS(l));
            };
        } else { // p1001
            int l;
            wait(&l); // Recebendo retorno de p1003
            printf("Recebi o tamanho da string = %d\n", WEXITSTATUS(l));
        };
    };

    scanf("%d", &i);
    exit(0);
};


void removeLowercase(){
    int c, j = 0;
    char newString[101];
    while (S[c] != '\0'){
        if (!(S[c] >= 'a') && !(S[c] <= 'z')) {
            newString[j] = S[c];
            j++;
        };
        c++;
    };
    // S = newString;
    printf("- Removido caracteres minúsculos por P4: %s", newString);
};


void removeVogals(){
    int c, j = 0;
    char newString[100];
    while (S[c] != '\0'){
        if ((S[c] == 'a') || (S[c] == 'A') || (S[c] == 'e') || (S[c] == 'E') || 
        (S[c] == 'i') || (S[c] == 'I') || (S[c] == 'o') || (S[c] == 'O') ||
        (S[c] == 'u') || (S[c] == 'U')) {
            // É uma lvogal
        } else {
            newString[j] = S[c];
            j++;
        };
        c++;
    };
    // S = newString;
    printf("- Removido vogais por P6: %s", newString);
};