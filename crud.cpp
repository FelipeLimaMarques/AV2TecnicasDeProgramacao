#include <stdio.h>
#include <stdlib.h>

//Variáveis globais
int tamanho = 0;
int escolha, i, j, matri;
bool flag = true;

struct formato_aluno{
	int matricula;
	char nome[30];
	float av1;
	float av2;
	float media;
};
//Ponteiro de aluno
formato_aluno *p;
//Variável global tipo formato_aluno
formato_aluno aluno;

//Calcula media de aluno
float calcula_media (float av1, float av2){
	float media = ((av1 * 3) + (av2 * 4)) / 7;
	return media;
}
//Formatação de aluno
void formato_linha(int matricula, char *nome, float av1, float av2, float media){
	printf ("\nMatricula: %d\tNome: %s\n\tAV1: %.1f\tAV2: %.1f\tMedia: %.1f\n", matricula, nome, av1, av2, media);
}
//Adiciona aluno
void adiciona_aluno (int posicao){
		
		printf ("\nMatricula: ");
		scanf ("%d", &p[posicao].matricula);
		if (tamanho > 1){
			do{
				for (int i = 0; i < tamanho; i++){
					if (p[posicao].matricula == p[i-1].matricula){
						printf ("Matricula ja cadastrada!\n");
						flag = false;
						printf ("Matricula: ");
						scanf ("%d", &p[posicao].matricula);
						break;
					}
					else
						flag = true;
				}
			}while (flag == false);
		}
		printf ("\nNome: ");
		fflush (stdin);
		//scanf ("%s[a-zA-Z ]", &p[posicao].nome);
		fgets(p[posicao].nome, 30, stdin);
		//fflush (stdin);
		printf ("\nNota AV1: ");
		scanf ("%f", &p[posicao].av1);
		if (p[posicao].av1 < 0 || p[posicao].av1 > 10){
			do{
				printf ("\nValor Invalido!\nNota AV1: ");
				scanf ("%f", &p[posicao].av1);
			}while (p[posicao].av1 < 0 || p[posicao].av1 > 10);
		}
		printf ("\nNota AV2: ");
		scanf ("%f", &p[posicao].av2);
		if (p[posicao].av2 < 0 || p[posicao].av2 > 10){
			do{
				printf ("\nValor Invalido!\nNota AV2: ");
				scanf ("%f", &p[posicao].av2);
			}while (p[posicao].av2 < 0 || p[posicao].av2 > 10);
		}
		printf ("\n");
		p[posicao].media = calcula_media(p[posicao].av1, p[posicao].av2);
		
}
//Consulta aluno pela matricula
int consulta_aluno(char *msg){
	if (tamanho == 0)
		printf ("Nao ha alunos cadastrados!\n");
	else{
		printf (msg);
		scanf ("%d", &matri);
		for (i = 0; i < tamanho; i++){
			if (matri == p[i].matricula){
				printf ("\nPosicao: %d\tNome: %s\tAV1: %.1f\tAV2: %.1f\tMedia: %.1f\n", i, p[i].nome, p[i].av1, p[i].av2, p[i].media);
				break;
			}
			else if (matri != p[i].matricula && i == tamanho-1){
				printf ("\nNumero de matricula invalida!");
			}
		}
		printf ("\n");
		return i;
	}
}
//Altera aluno pela matricula
void altera_aluno(){
	if (tamanho == 0)
		printf ("Nao ha alunos cadastrados!\n");
	else{
		consulta_aluno("Para alterar um aluno, entra com a matricula: ");
		adiciona_aluno(i);
		printf ("\n");
	}
}
//Exclui um aluno pela matricula
void exclui_aluno(){
	if (tamanho == 0)
		printf ("Nao ha alunos cadastrados!\n");
	else{
		int del;
		del = consulta_aluno("Para excluir um aluno, entre com a matricula: ");
		for (i = del; i < tamanho; i++){
			p[i] = p[i+1];
		}
		tamanho--;
		//Realoca espaço na memória para vetor de tamanho int
		p = (formato_aluno *)realloc( p, tamanho * sizeof(formato_aluno));
		printf ("\n");
	}
}
//Lista alunos cadastrados
void lista_aluno(){
	if (tamanho == 0)
		printf ("Nao ha alunos cadastrados!\n");
	else{
		for (i = 0; i < tamanho; i++){
			formato_linha (p[i].matricula, p[i].nome, p[i].av1, p[i].av2, p[i].media);
		}
		printf ("\n");
	}
}
//Menu principal
void menu (){
	
	
	do{
		system ("cls");
		printf ("|Menu principal|\n");
		printf ("1 - Adicionar\n2 - Consultar\n3 - Alterar\n4 - Excluir\n5 - Listar\n0 - Sair\n");
		scanf ("%d", &escolha);
		if (escolha < 0 || escolha > 5){
			do{
				printf ("\nOperacao invalida!\n");
				printf ("|Menu principal|\n");
				printf ("1 - Adicionar\n2 - Consultar\n3 - Alterar\n4 - Excluir\n5 - Listar\n0 - Sair\n");
				scanf ("%d", &escolha);
			}while (escolha < 0 || escolha > 5);
		}
		
		
		// Adicionar;
		if (escolha == 1){
			tamanho++;
			//Aloca espaço na memória para vetor de tamanho int
			if (tamanho == 0)
				p = (formato_aluno *)malloc( tamanho * sizeof(formato_aluno));
			else
				p = (formato_aluno *)realloc(p, tamanho * sizeof(formato_aluno));
			adiciona_aluno(tamanho-1);
			system ("PAUSE");
		}
		// Consultar;
		else if (escolha == 2){
			consulta_aluno("Para consultar um aluno, entra com a matricula: ");
			system ("PAUSE");
		}
		// Alterar;
		else if (escolha == 3){
			altera_aluno();
			system ("PAUSE");
		}
		// Excluir;
		else if (escolha == 4){
			exclui_aluno();
			system ("PAUSE");
		}
		// Listagem;
		else if (escolha == 5){
			lista_aluno();
			system ("PAUSE");
		}
	}while (escolha != 0);
	
}

main (){
	
	menu();
	
	system ("PAUSE");
	return 0;
}
