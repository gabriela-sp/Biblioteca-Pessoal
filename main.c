#include "funcoes.h"
#define REGISTRAR 1
#define MOSTRAR 2
#define LIMPAR 3
#define SAIR 4
//definindo opcoes do menu

int main(void) {
  cadastro livros[100] = {-1};
  //toda vez que um cadastro for feito subtrai 1 do vetor
  int opcao = 0;

	while (opcao != 4)
    //criando loop
  {
    opcao = menu();
    //chamando funcao menu
		
		switch (opcao)
      //definindo os casos de acordo com a escolha do usuario
    {
      //limpando a tela e chamando a funcao registrar
			case REGISTRAR:
        system("clear");
				cadastrar(livros);
				break;
      //limpando a tela e chamando a funcao mostrar
			case MOSTRAR:
        system("clear");
				mostrar(livros);
				break;
      //limpando a tela e chamando a funcao limpar
			case LIMPAR:
        system("clear");
				limpar(livros);
				break;
      //limpando a tela e chamando a funcao sair
			case SAIR:
        system("clear");
        sair();
				break;
      //mensagem de erro se não escolher nenhuma das opcoes acima
			default:
        system("clear");
        printf("*******************************\n");
				printf("\nOPÇÃO INVÁLIDA! TENTE NOVAMENTE\n");
        printf("\n*******************************\n");
        sleep(3); 
        system("clear");
		}
	}
}