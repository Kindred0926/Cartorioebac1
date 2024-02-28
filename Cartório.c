#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos string

int registro() //Fun��o para registrar um usu�rio
{
	//inicio da cria��o das variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	////Final da cria��o das variaveis/string

	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se as string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores dos strings
	
	FILE *file; //Cria o arquivo
	file = fopen (arquivo, "w"); //Cria o arquivo "w" significa escrever
	fprintf (file,cpf); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf ("Digite o nome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf ("%s",nome);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,nome); //salva o valor
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es do arquivo
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,sobrenome); //salva o arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
	
}

int consulta() //Fun��o para consultar um usu�rio
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo,100, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usuario: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system ("pause");
}

int deletar() //Fun��o para deletar um usu�rio
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //Solicita ao usu�rio o CPF a ser deletado
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //verifica se o arquivo n�o foi encontrado
	{
		printf("CPF n�o encontrado no sistema: ");
		system("pause");
	}

}



int main()
{
	int opcao=0; //Definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio de menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar usu�rio\n");
		printf("\t2 - Consultar usu�rio\n");
		printf("\t3 - Excluir usu�rio\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
		
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:	
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por usar o sistema\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;	
			
		}
	}
}	

