#include <stdio.h>
#include <string.h>

#define MAXTAM 32
//#define TESTE

char *cifraz(char *msg, int passo);

// Rotinas de Teste
int testa_troca_A_passo3(void) {
	int retorno = 0;
	char *txtcifrado;
	char *mensagem;
	mensagem = "A";
	txtcifrado = (void *)cifraz(mensagem,3);
	retorno = strcmp(txtcifrado,"D");
	return(retorno);
}

// Executa testes
int RodaTestes(void) {
	int resultado;
	
	resultado = testa_troca_A_passo3();
	if(resultado) {
 	    printf("Teste 01 Falhou");
 	}
	return(resultado);
}

// Main
void main (void) {
	int chave = 0;
	char *msg, *msg2;
	
	#ifdef TESTE		
		return(RodaTestes());
	#endif
		
	printf("Entre com a sua mensagem\n");
	gets(msg);

	printf("Entre com um numero de 1 a 9 como chave criptografica.: ");
	scanf("%d",&chave);
	msg2 = cifraz(msg,chave);

	// Testa se é WINDOWS, se for coloca o pause, se não for (Linux/Mac/DOS) não coloca
	#ifdef WIN32
		printf("\n\n");
		system("pause");
	#endif 
}

// Rotinas do programa
char *cifraz(char *msg, int passo) {
	int i;
    char *cifra;
    cifra = msg;
    int aux, aux2;
    int tam;
    tam = strlen(msg)-1;
    for(i = 0; i <= tam; i++) {      
	  aux = msg[i];
      aux2  = aux + passo;
      //cifra[i] = (int)aux2;
      cifra[i] = msg[i]+passo;
    }
}
