#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos string

int registro() //Função para registrar um usuário
{
	//inicio da criação das variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	////Final da criação das variaveis/string

	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se as string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores dos strings
	
	FILE *file; //Cria o arquivo
	file = fopen (arquivo, "w"); //Cria o arquivo "w" significa escrever
	fprintf (file,cpf); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf ("Digite o nome a ser cadastrado: "); //Coletando informações do usuário
	scanf ("%s",nome);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,nome); //salva o valor
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações do arquivo
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

int consulta() //Função para consultar um usuário
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
		printf("Não foi possível abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo,100, file) != NULL)
	{
		printf("\n Essas são as informações do usuario: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system ("pause");
}

int deletar() //Função para deletar um usuário
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //Solicita ao usuário o CPF a ser deletado
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //verifica se o arquivo não foi encontrado
	{
		printf("CPF não encontrado no sistema: ");
		system("pause");
	}

}



int main()
{
	int opcao=0; //Definindo variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio de menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar usuário\n");
		printf("\t2 - Consultar usuário\n");
		printf("\t3 - Excluir usuário\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
		
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:	
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
			printf("Obrigado por usar o sistema\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;	
			
		}
	}
}	

