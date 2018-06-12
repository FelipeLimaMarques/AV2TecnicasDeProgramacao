#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_MAXIMO 100

int tamanho = 0;
int escolha, i, j, matri, *p;

struct formato_aluno{
	int matricula;
	char nome[30];
	float av1;
	float av2;
	float media;
};

formato_aluno aluno[TAMANHO_MAXIMO];

float calcula_media (float av1, float av2){
	float media = ((av1 * 3) + (av2 * 4)) / 7;
	return media;
}

void formato_linha(int matricula, char *nome, float av1, float av2, float media){
	printf ("\nMatricula: %d\tNome: %s\tAV1: %.1f\tAV2: %.1f\tMedia: %.1f\n", matricula, nome, av1, av2, media);
}

void adiciona_aluno (int posicao){
		
		printf ("\nMatricula: ");
		scanf ("%d", &aluno[posicao].matricula);
		printf ("\nNome: ");
		scanf (" %s[a-zA-Z ]", &aluno[posicao].nome);
		fflush (stdin);
		printf ("\nNota AV1: ");
		scanf ("%f", &aluno[posicao].av1);
		if (aluno[posicao].av1 < 0 || aluno[posicao].av1 > 10){
			do{
				printf ("\nValor Invalido!\nNota AV1: ");
				scanf ("%f", &aluno[posicao].av1);
			}while (aluno[posicao].av1 < 0 || aluno[posicao].av1 > 10);
		}
		printf ("\nNota AV2: ");
		scanf ("%f", &aluno[posicao].av2);
		if (aluno[posicao].av2 < 0 || aluno[posicao].av2 > 10){
			do{
				printf ("\nValor Invalido!\nNota AV2: ");
				scanf ("%f", &aluno[posicao].av2);
			}while (aluno[posicao].av2 < 0 || aluno[posicao].av2 > 10);
		}
		printf ("\n");
		aluno[posicao].media = calcula_media(aluno[posicao].av1, aluno[posicao].av2);
		
}

int consulta_aluno(char *msg){
	if (tamanho == 0)
		printf ("Nao ha alunos cadastrados!\n");
	else{
		printf (msg);
		scanf ("%d", &matri);
		for (i = 0; i < tamanho; i++){
			if (matri == aluno[i].matricula){
				printf ("\nPosicao: %d\tNome: %s\tAV1: %.1f\tAV2: %.1f\tMedia: %.1f\n", i, aluno[i].nome, aluno[i].av1, aluno[i].av2, aluno[i].media);
				break;
			}
			else{
				printf ("\nNumero de matricula invalida!");
			}
		}
		printf ("\n");
		return i;
	}
}

void altera_aluno(){
	if (tamanho == 0)
		printf ("Nao ha alunos cadastrados!\n");
	else{
		consulta_aluno("Para alterar um aluno, entra com a matricula: ");
		adiciona_aluno(i);
		printf ("\n");
	}
}

void exclui_aluno(){
	if (tamanho == 0)
		printf ("Nao ha alunos cadastrados!\n");
	else{
		int del;
		del = consulta_aluno("Para excluir um aluno, entra com a matricula: ");
		for (i = del; i < tamanho; i++){
			aluno[i] = aluno[i+1];
		}
		tamanho--;
		printf ("\n");
	}
}

void lista_aluno(){
	if (tamanho == 0)
		printf ("Nao ha alunos cadastrados!\n");
	else{
		for (i = 0; i < tamanho; i++){
			formato_linha (aluno[i].matricula, aluno[i].nome, aluno[i].av1, aluno[i].av2, aluno[i].media);
		}
		printf ("\n");
	}
}

void menu (){
	
	
	do{
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
			adiciona_aluno(tamanho-1);
		}
		// Consultar;
		else if (escolha == 2){
			consulta_aluno("Para consultar um aluno, entra com a matricula: ");
		}
		// Alterar;
		else if (escolha == 3){
			altera_aluno();
		}
		// Excluir;
		else if (escolha == 4){
			exclui_aluno();
		}
		// Listagem;
		else if (escolha == 5){
			lista_aluno();
		}
	}while (escolha != 0);
	
}

main (){
	
	menu();
	
	system ("PAUSE");
	return 0;
}
