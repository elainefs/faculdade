#include <stdio.h>
#include <string.h>

int main(){
  char senha[8] = {"12345"};
  char senha_usr[8];
  int correto;

  printf("Digite a sua senha: ");
  scanf("%s", senha_usr);

  correto = strcmp(senha_usr, senha);

  if(correto == 0){
    printf("Acesso liberado\n");
  } else {
    printf("Senha incorreta\n");
  }
}