#include <stdio.h>
#include <stdlib.h>
/*
#define PATH "C:\\Users\\Pedro\\Desktop\\Prog\\TrabalhoPratico\\ficheiros"
#define NOME_FICH "pessoas.dat"



/*	Para resolver a questão dos caminhos absolutos*/
#ifdef WINDOWS
    #include <direct.h>
    #define PATH _getcwd
#else
    #include <unistd.h>
    #define PATH getcwd
#endif


struct dados{					/*Estrutura PESSOA*/
	char nome[100];
	int idade;
	int id;
};
typedef struct dados pessoa;


int mostraPessoa(char *nomeFicheiro, int total)
{
	/*int total;*/
	FILE *f;
	pessoa b;

	f = fopen(nomeFicheiro, "rb");
	if(f==NULL)
	{
		printf("Erro no acesso ao ficheiro\n");
		return 0;
	}
	while(fread(&b, sizeof(pessoa), total, f) == 1){
		fread(&total, sizeof(total), 1, f);
		fread(&b, sizeof(pessoa), total, f);
		printf("%s  | %d\n", b.nome, b.idade);
	}

	fclose(f);
	
}

void adicionar_pessoa(char *nomeFicheiro, int total){

	FILE *f;
	pessoa a;

	f = fopen(nomeFicheiro, "ab");

	printf("Nome:\n");
	scanf(" %[^\n]", &a.nome);
	printf("Idade:\n");
	scanf("%d", &a.idade);
	a.id = 1;

	if(f == NULL){
		printf("Erro ao ler do ficheiro\n");
		return;
	}
	fwrite(&total, sizeof(total), 1, f);
	fwrite(&a, sizeof(pessoa), total, f);
	

	

	/*printf("%s | %d\n", a.nome, a.idade);*/
}

void elimina_pessoa(char *nomeFicheiro){



}



int main()
{
	int total = 0;
	pessoa x;


	char cCurrentPath[FILENAME_MAX];

 if (!PATH(cCurrentPath, sizeof(cCurrentPath)))
     {
     return errno;
     }
/*
cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

printf ("The current working directory is %s", cCurrentPath);
	

	/*
		char fullPath[100];
		char fileName[50];
	*/

	/*caminho para o ficheiro*/
	
	/* char *path = "C:\\Users\\Pedro\\Desktop\\Prog\\TrabalhoPratico\\pessoas.dat"; */

	/*
	char *symlinkpath = "/ficheiros/pessoas.dat";
	char actualpath [PATH_MAX+1];
	char *ptr;


	ptr = realpath(symlinkpath, actualpath);

	printf("%s\n", ptr);
	
	*/
	
	/*inserePessoa(PATH, total);
	mostraPessoa(PATH, 2);

	*/

	/* code */
	return 0;
}
