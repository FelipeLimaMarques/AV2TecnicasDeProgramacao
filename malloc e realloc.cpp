#include <stdio.h>
#include <stdlib.h>

main()
{
  int *p;
  int i;
  int qtde;
  
  printf("Deseja cadastrar quantos elementos ? \n");
  scanf("%d",&qtde);

  p = (int *)malloc( qtde * sizeof(int));

  printf("cadastrando os elementos \n" );
  for (i = 0; i < qtde ; i++)
     scanf("%d",&p[i]);   
  
  printf(" \n imprimindo os elementos \n" );
  for (i = 0; i < qtde; i++)
    printf("%d ",p[i]);
    

    
  qtde++;
  p = (int *)realloc( p, qtde * sizeof(int));
  p[qtde-1] = 999;



  printf(" \n imprimindo os elementos \n" );
  for (i = 0; i < qtde; i++)
    printf("%d ",p[i]);
  
  
  system("pause");
}

