#include <stdio.h>
#include <string.h>
char *cifraz(char *msg, int passo);

// Main
int main (void) {
	int chave = 0;
	char *msg;
	int resultado;
			
	printf("Entre com a sua mensagem\n");
	gets(msg);

	printf("Entre com um numero de 1 a 9 como chave criptografica.: ");
	scanf("%d",&chave);
	msg = cifraz(msg,chave);
	printf("Cifra = %s",msg);

	// Testa se é WINDOWS, se for coloca o pause, se não for (Linux/Mac/DOS) não coloca
	#ifdef WIN32
		printf("\n\n");
		system("pause");
	#endif 
	
	return(0);
}

// Rotinas do programa
char *cifraz(char *msg, int passo) {
	int i, tam;
    char *cifra;
    int x;
    cifra = msg; // responsavel por nao dar erro na conversao
    tam = strlen(msg) - 1;
    for(i = 0; i <= tam; i++) {
      cifra[i] = msg[i]+passo;
 	}      
    return(cifra);
}
