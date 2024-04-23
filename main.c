#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TIMES 5

main(){
  int l, c, cont, cont2, pontos[TIMES][TIMES - 1], gols1, gols2, soma;
  char nomes[TIMES][255];
  srand(time(NULL));
  for(l = 0; l < TIMES; l++){
    printf("Digite o nome do %iº time: ", l + 1);
    gets(nomes[l]);
  }
  cont = 0;
  cont2 = 1;
  printf("\n");
  for(l = 0; l < TIMES; l++){
    for(c = cont; c < TIMES - 1; c++){
      gols1 = rand() % 5;
      gols2 = rand() % 5;
      printf("Placar de %s contra %s: %i x %i\n", nomes[l], nomes[l + cont2], gols1, gols2);
      if(gols1 > gols2){
        pontos[l][c] = 3;
        pontos[l + cont2][cont] = 0;
      }
      if(gols1 < gols2){
        pontos[l][c] = 0;
        pontos[l + cont2][cont] = 3;
      }
      if(gols1 == gols2){
        pontos[l][c] = 1;
        pontos[l + cont2][cont] = 1;
      }
      cont2++;
    }
    cont2 = 1;
    cont++;
  }
  cont = 1;
  cont2 = 1;
  printf("\n\n");
  printf("Times: \n");
  for(l = 0; l < TIMES; l++){
    printf("%i - %s\n",l + 1, nomes[l]);
  }
  printf("\n");
  for(l = - 2; l < TIMES; l++){
    for(c = - 1; c < TIMES - 1; c++){
      if(l >= 0 && c >= 0){
        if(c == TIMES - 2){
          printf("\t%i\n", pontos[l][c]);
        }
        else{
          printf("\t%i\t-", pontos[l][c]);
        }
      }
      else{
        if(l == - 2 && c == - 1){
          printf("\t\t");
        }
        if(l == - 2 && c >= 0){
          if(c == TIMES - 2){
            printf("Jogo%i\n", c + 1);
          }
          else{
            printf("Jogo%i\t", c + 1);
          }
        }
        if(l == - 1 && c == - 1){
          printf("Times\t");
        }
        if(l == - 1 && c >= 0){
          printf("%i\t\t", cont2);
          cont2++;
        }
        if(l >= 0 && c == - 1){
          if(l == 0){
            printf("\n");
          }
          printf("%i\t", cont);
          cont++;
        }
      }
    }
  }
  printf("\n");
  for(l = 0; l < TIMES; l++){
    for(c = 0; c < TIMES - 1; c++){
      soma = soma + pontos[l][c];
    }
    printf("Total de pontos %s: %i\n", nomes[l], soma);
    soma = 0;
  }
  getchar();
}