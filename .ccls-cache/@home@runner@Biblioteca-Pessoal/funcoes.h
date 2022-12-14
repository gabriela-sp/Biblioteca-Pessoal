//biblioteca virtual pessoal para resgistro de livros lidos em documento de texto, realizando funções de cadastro, mostrar e deletar dados cadastrados, e sair do programa.

#include <stdio.h>
#include "struct.h"

int menu()
{
  int opcao = 0, i;
  char opcoesPossiveis[4][40] = 
  {"\n1 - REGISTRE UM LIVRO\n", "2 - MOSTRAR LIVROS REGISTRADOS\n", "3 - LIMPAR LISTA DE REGISTROS\n", "4 - SAIR DA BIBLIOTECA\n"};
    //imprimindo mensagem inicial
  printf("\n*******SEJA BEM VIND@ A SUA BIBLIOTECA PESSOAL!!********\n");
  printf("\nAqui você pode registrar os livros que você leu e a sua nota sobre eles! :)\n");
  printf("\n***********************\n");
  
  for (i = 0; i < 4; i++)
  { 
    //imprimindo opcoes de escolha
    printf("%s\n", opcoesPossiveis[i]); 
  }
  printf("***********************\n");	
	printf("\nDigite a opção que você deseja: ");
	scanf(" %i", &opcao);	
  //retorna as informações de acordo com a opção escolhida pelo usuário 
	return opcao;
}

int cadastrar(cadastro *livros)
{
  //criando e abrindo arquivo de texto
  FILE *arquivo;
  arquivo =fopen("livros.txt","a");
  //pedindo informacoes para o cadastro
  printf("\n********** REGISTRE UM LIVRO **********\n");
  printf("Digite o título (use _ no lugar de espaços): ");
  scanf(" %s", livros->titulo);
  printf("Digite o/a autor(a) (use _ no lugar de espaços): ");
  scanf(" %s", livros->autor);
  printf("Digite a nota: ");
  scanf(" %i", &livros->nota);
  
  if (arquivo == NULL) //mensagem de erro se não existir arquivo
  {
    printf("\nERRO! NÃO FOI POSSÍVEL FAZER O REGISTRO.");
    return 0;
  }
  printf("\n********************************");
  printf("\nREGISTRO REALIZADO COM SUCESSO!!");
  printf("\n********************************\n");
  fprintf(arquivo, "%s, %s, %i\n", livros->titulo, livros->autor, livros->nota);
  fclose(arquivo);
  //registrando informacoes e fechando o arquivo
  sleep(3);
  system("clear");
  //limpando a tela
  return 1;
}

int mostrar( cadastro *livros){
  char temp[255];
  FILE *arquivo;
  int fim=!EOF;
  
  arquivo =fopen("livros.txt","r");
  //abrindo arquivo de texto
  if ( arquivo == NULL){
    printf("\n ERRO! NÃO FOI POSSÍVEL ABRIR SUA LISTA DE LIVROS REGISTRADOS.");
    //erro se nao existir arquivo
    return 0;
  }
  printf("\n*******************************\n");
  printf("SUA LISTA DE LIVROS REGISTRADOS\n");
  printf("*******************************\n\n");
  printf("TÍTULO, AUTOR(A), NOTA\n");
  do {
    fim=fscanf(arquivo, "%s %s %i ", livros->titulo, livros->autor, &livros->nota);
    if ( fim != EOF )
      printf("%s %s %i\n", livros->titulo, livros->autor, livros->nota);
  }
  while( fim != EOF );
  fclose(arquivo);
  //percorrer o arquivo, imprimir os registros e fechar o arquivo
  sleep(10);
  system("clear");
  //limpando a tela
  return 1;
}

int limpar (){
  char nome[] = {"livros.txt"};
  //criando uma variavel para o arquivo de texto
  FILE *arquivo = fopen(nome, "w");
  //abrindo arquivo
  if(arquivo == NULL){
    printf("\nERRO! NÃO FOI POSSÍVEL LIMPAR A SUA LISTA DE LIVROS.\n");
  //mensagem de erro se o arquivo não existir
  }
  else{
  fclose(arquivo);
    //fechar arquivo
  printf("\n****************************************************");
  printf("\nLIMPEZA DA LISTA DE LIVROS REALIZADA COM SUCESSO! ;)\nVOCÊ TEM %d LIVROS REGISTRADOS.\n****************************************************\n", remove(nome));
  }
  //mostrar mensagem de sucesso e limpar arquivo
  sleep(4);
  system("clear");
  //limpando a tela
  return 0;
}

void sair(void)
{
  system("clear");
  //limpando a tela
  printf("********************************************\n");
  printf("\nOBRIGADA POR USAR O CÓDIGO E BOA LEITURA! :)\n");
  printf("\n********************************************");
  //mensagem de encerramento do programa
}

void Clear(void) {
  system("clear");
  //definindo funcao de limpar a tela
}