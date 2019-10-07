#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>


void removeLowercase();
void removeVogals();
void removeUppercase();

char S[101];

int main(void)
{
    int i;
    pid_t p1002, p1003, p1004, p1005, p1006, p1007 ;

    printf("Digite uma string de no máximo 100 caracteres: \n");
    fgets(S, sizeof(S), stdin);

    if ((p1002 = fork()) == 0) {
        if((p1004 = fork()) == 0){
            sleep(3);
            removeLowercase();
        } else {
            if((p1006 = fork()) == 0){
                signal(SIGUSR1, removeUppercase);
                while(1);
            } else {
                if((p1007 = fork()) == 0){
                    sleep(2);
                    removeVogals();
                } else {};
            };
        };
    } else {
        if ((p1003 = fork()) == 0) {
            if ((p1005 = fork()) == 0) { 
                int length = strlen(S);
                exit(length - 1);
            } else {
                int l;
                wait(&l);
                exit(WEXITSTATUS(l));
            };
        } else { 
            int l;
            wait(&l);
            printf("* Recebi o tamanho da string: %d\n", WEXITSTATUS(l));
        };
        sleep(4);
        kill(p1006, SIGUSR1);
    };

    scanf("%d", &i);
    // exit(0);
};


void removeLowercase(){
    int c = 0, j = 0;
    char newString[101];
    while (S[c] != '\0'){
        if ((S[c] >= 'a') && (S[c] <= 'z')) {
            // É um caracter minúsculo
        } else {
            // É um caracter maisculo
            newString[j] = S[c];
            j++;
        };
        c++;
    };
    printf("* Caracteres minusculos retirados: %s", newString);
};

void removeUppercase(){
    int c = 0, j = 0;
    char newString[101];
    while (S[c] != '\0'){
        if ((S[c] >= 'A') && (S[c] <= 'Z')) {
            // É um caracter maisculo
        } else {
            // É um caracter minusculo
            newString[j] = S[c];
            j++;
        };
        c++;
    };
    printf("* Caracteres maiúsculos retirados: %s", newString);
};


void removeVogals(){
    int c = 0, j = 0;
    char newString[100];
    while (S[c] != '\0'){
        if ((S[c] == 'a') || (S[c] == 'A') || (S[c] == 'e') || (S[c] == 'E') || 
        (S[c] == 'i') || (S[c] == 'I') || (S[c] == 'o') || (S[c] == 'O') ||
        (S[c] == 'u') || (S[c] == 'U')) {
            // É uma vogal
        } else {
            newString[j] = S[c];
            j++;
        };
        c++;
    };
    printf("* Removido vogais: %s", newString);
};