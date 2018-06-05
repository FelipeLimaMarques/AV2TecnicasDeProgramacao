#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_MAXIMO 100

struct formato_aluno{
	int matricula;
	char nome[30];
	float av1;
	float av2;
	float media;
};

float calcula_media (float av1, float av2){
	float media = ((av1 * 3) + (av2 * 4)) / 7;
	return media;
}

void formato_linha(int matricula, char *nome, float av1, float av2, float media){
	printf ("\nMatricula: %d\tNome: %s\tAV1: %.1f\tAV2: %.1f\tMedia: %.1f\n", matricula, nome, av1, av2, media);
}

void menu (){
	printf ("|Menu principal|\n");
	printf ("1 - Adicionar\n2 - Consultar\n3 - Alterar\n4 - Excluir\n5 - Listar\n0 - Sair\n");
}

main (){
	// Adicionar; Consultar; Alterar; Excluir; Listagem
	int escolha, i, j, tamanho, matri;
	formato_aluno aluno[TAMANHO_MAXIMO];
	do{
		
		menu();
		scanf ("%d", &escolha);
		
		if (escolha == 1){
			printf ("\nQuantidade de alunos: ");
			scanf ("%d", &tamanho);
			for (i = 0; i < tamanho; i++){
				printf ("\nMatricula: ");
				scanf ("%d", &aluno[i].matricula);
				printf ("\nNome: ");
				scanf (" %s[a-zA-Z ]", &aluno[i].nome);
				fflush (stdin);
				printf ("\nNota AV1: ");
				scanf ("%f", &aluno[i].av1);
				printf ("\nNota AV2: ");
				scanf ("%f", &aluno[i].av2);
				printf ("\n");
				aluno[i].media = calcula_media(aluno[i].av1, aluno[i].av2);
			}
		}
		else if (escolha == 2){
			printf ("Para consultar um aluno, entra com a matricula: ");
			scanf ("%d", &matri);
			for (i = 0; i < tamanho; i++){
				if (matri == aluno[i].matricula){
					printf ("\nPosicao: %d\tNome: %s\tAV1: %.1f\tAV2: %.1f\tMedia: %.1f\n", i, aluno[i].nome, aluno[i].av1, aluno[i].av2, aluno[i].media);
				}
			}
			printf ("\n");
		}
		else if (escolha == 3){
			printf ("Escolha a posicao do aluno a ser alterado:\n");
			for (i = 0; i < tamanho; i++){
				printf ("\nPosicao: %d", i);
				formato_linha (aluno[i].matricula, aluno[i].nome, aluno[i].av1, aluno[i].av2, aluno[i].media);
			}
			scanf ("%d", &j);
			printf ("\nMatricula: ");
			scanf ("%d", &aluno[j].matricula);
			printf ("\nNome: ");
			scanf (" %s[a-zA-Z ]", &aluno[j].nome);
			fflush (stdin);
			printf ("\nNota AV1: ");
			scanf ("%f", &aluno[j].av1);
			printf ("\nNota AV2: ");
			scanf ("%f", &aluno[j].av2);
			printf ("\n");
			aluno[j].media = calcula_media(aluno[j].av1, aluno[j].av2);
			printf ("\n");
		}
		else if (escolha == 4){
			printf ("\nEscolha a posicao do aluno a ser deletado:\n");
			for (i = 0; i < tamanho; i++){
				printf ("\nPosicao: %d", i);
				formato_linha (aluno[i].matricula, aluno[i].nome, aluno[i].av1, aluno[i].av2, aluno[i].media);
			}
			scanf ("%d", &j);
			for (i = j; i < tamanho; i++){
				aluno[i] = aluno[i+1];
			}
			tamanho--;
			printf ("\n");
		}
		else if (escolha == 5){
			for (i = 0; i < tamanho; i++){
				formato_linha (aluno[i].matricula, aluno[i].nome, aluno[i].av1, aluno[i].av2, aluno[i].media);
			}
			printf ("\n");
		}
		
		
		
	
	
	
	}while (escolha != 0);
	
	system ("PAUSE");
	return 0;
}
