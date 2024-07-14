// Agenda Telefônica
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILHOS 34
#define MAX_CONTATOS 1000

typedef struct {
  char nome[50];
  char telefone[20];
  char email[50];
} Contato;

typedef struct No {
  Contato contato;
  struct No *filhos[MAX_FILHOS];
  int numFilhos;
} No;

// Função para converter uma string para maiúsculas
void strToUpper(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    str[i] = toupper(str[i]);
  }
}

// Função para criar um novo nó
No *criarNo(Contato contato) {
  No *novoNo = (No *)malloc(sizeof(No));
  if (novoNo == NULL) {
    printf("Erro ao alocar memória para o nó.\n");
    exit(1);
  }
  novoNo->contato = contato;
  novoNo->numFilhos = 0;
  int i;
  for (i = 0; i < MAX_FILHOS; i++) {
    novoNo->filhos[i] = NULL;
  }
  return novoNo;
}

// Função para buscar um contato e retornar o pai do nó encontrado
No *buscarContatoComPai(No *raiz, char *nome, No **pai) {
  if (raiz == NULL) {
    return NULL;
  }
  if (strcmp(raiz->contato.nome, nome) == 0) {
    return raiz;
  }
  int i;
  for (i = 0; i < raiz->numFilhos; i++) {
    No *resultado = buscarContatoComPai(raiz->filhos[i], nome, pai);
    if (resultado != NULL) {
      *pai = raiz;
      return resultado;
    }
  }
  return NULL;
}

// Função para buscar um contato
No *buscarContato(No *raiz, char *nome) {
  No *pai = NULL;
  return buscarContatoComPai(raiz, nome, &pai);
}

// Função para inserir um contato ou atualizar se já existir
void inserirContato(No **raiz, Contato contato) {
  No *encontrado = buscarContato(*raiz, contato.nome);
  if (encontrado != NULL) {
    // Contato já existe, solicitação de atualização
    char opcao;
    printf("\nContato com o nome \"%s\" já existe. Deseja atualizar as "
           "informações? (s/n): ",
           contato.nome);
    scanf(" %c", &opcao);
    if (opcao == 's' || opcao == 'S') {
      // Atualiza as informações do contato existente
      strcpy(encontrado->contato.telefone, contato.telefone);
      strcpy(encontrado->contato.email, contato.email);
      printf("\nContato atualizado com sucesso!\n");
    } else {
      printf("\nContato não foi atualizado.\n");
    }
  } else {
    // Criação de um novo contato
    if (*raiz == NULL) {
      // Se a raiz é nula, cria um novo nó pai com a primeira letra do nome do
      // contato
      *raiz = criarNo(contato);
    } else {
      // Obtém a primeira letra do nome do contato
      char primeiraLetraContato = toupper(contato.nome[0]);
      // Verifica se já existe um nó filho correspondente à primeira letra do
      // nome do contato
      No *filhoCorrespondente = NULL;
      int i;
      for (i = 0; i < (*raiz)->numFilhos; i++) {
        char primeiraLetraFilho = toupper((*raiz)->filhos[i]->contato.nome[0]);
        if (primeiraLetraFilho == primeiraLetraContato) {
          filhoCorrespondente = (*raiz)->filhos[i];
          break;
        }
      }
      if (filhoCorrespondente != NULL) {
        // Se já existe um nó filho correspondente, insere o contato como filho
        // desse nó
        if (filhoCorrespondente->numFilhos < MAX_FILHOS) {
          filhoCorrespondente->filhos[filhoCorrespondente->numFilhos] =
              criarNo(contato);
          filhoCorrespondente->numFilhos++;
        } else {
          inserirContato(&(filhoCorrespondente->filhos[0]),
                         contato); // Recursivamente insere no primeiro filho do
                                   // filho correspondente
        }
      } else {
        // Se não existe um nó filho correspondente, cria um novo nó filho com a
        // primeira letra do nome do contato e insere o contato nele
        if ((*raiz)->numFilhos < MAX_FILHOS) {
          // Cria um novo nó filho com a primeira letra do nome do contato
          No *novoFilho =
              criarNo((Contato){.nome = {primeiraLetraContato, '\0'},
                                .telefone = "",
                                .email = ""});
          // Insere o contato como filho desse novo nó
          novoFilho->filhos[novoFilho->numFilhos] = criarNo(contato);
          novoFilho->numFilhos++;
          // Insere o novo nó filho na árvore
          (*raiz)->filhos[(*raiz)->numFilhos] = novoFilho;
          (*raiz)->numFilhos++;
        } else {
          inserirContato(
              &((*raiz)->filhos[0]),
              contato); // Recursivamente insere no primeiro filho do nó raiz
        }
      }
    }
    printf("\nContato inserido com sucesso!\n");
  }
}

// Função para remover um nó da árvore
void removerContato(No **raiz, char *nome) {
  if (*raiz == NULL) {
    printf("\nContato não encontrado.\n");
    return;
  }
  if (strcmp((*raiz)->contato.nome, nome) == 0) {
    int i;
    for (i = 0; i < (*raiz)->numFilhos; i++) {
      free((*raiz)->filhos[i]);
    }
    free(*raiz);
    *raiz = NULL;
    printf("\nContato removido com sucesso.\n");
    return;
  }
  int i;
  for (i = 0; i < (*raiz)->numFilhos; i++) {
    if (strcmp((*raiz)->filhos[i]->contato.nome, nome) == 0) {
      // Remove o nó encontrado
      free((*raiz)->filhos[i]);
      // Move os nós à direita para a esquerda para preencher o espaço
      int j;
      for (j = i; j < (*raiz)->numFilhos - 1; j++) {
        (*raiz)->filhos[j] = (*raiz)->filhos[j + 1];
      }
      (*raiz)->numFilhos--;
      printf("\nContato removido com sucesso.\n");
      return;
    }
  }
  // Se o contato não foi encontrado neste nó, continue a busca nos filhos
  for (i = 0; i < (*raiz)->numFilhos; i++) {
    removerContato(&((*raiz)->filhos[i]), nome);
  }
}

// Função para coletar todos os contatos
void coletarContatos(No *raiz, Contato *contatos, int *numContatos) {
  if (raiz == NULL) {
    return;
  }
  contatos[*numContatos] = raiz->contato;
  (*numContatos)++;
  int i;
  for (i = 0; i < raiz->numFilhos; i++) {
    coletarContatos(raiz->filhos[i], contatos, numContatos);
  }
}

// Função para comparar dois contatos
int compararContatos(const void *a, const void *b) {
  Contato *contatoA = (Contato *)a;
  Contato *contatoB = (Contato *)b;
  return strcmp(contatoA->nome, contatoB->nome);
}

// Função para exibir todos os contatos em ordem alfabética com cores diferentes
// Função para exibir todos os contatos em ordem alfabética, excluindo nós que
// são apenas letras
void listarContatos(No *raiz) {
  Contato contatos[MAX_CONTATOS];
  int numContatos = 0;
  coletarContatos(raiz, contatos, &numContatos);
  qsort(contatos, numContatos, sizeof(Contato), compararContatos);

  // Cores ANSI
  const char *cores[] = {"\033[0;31m", "\033[0;32m", "\033[0;33m", "\033[0;34m",
                         "\033[0;35m"};
  int numCores = sizeof(cores) / sizeof(cores[0]);

  int i;
  for (i = 0; i < numContatos; i++) {
    // Verifica se o nome do contato não representa apenas uma letra
    if (strlen(contatos[i].nome) > 1) {
      printf("%sNome = \"%s\"\nTelefone = \"%s\"\nE-mail = %s\n\n\033[0m",
             cores[i % numCores], contatos[i].nome, contatos[i].telefone,
             contatos[i].email);
    }
  }
}

// Função para exibir a árvore com cores diferentes
void imprimirArvore(No *raiz, int nivel) {
  // Cores ANSI
  const char *cores[] = {"\033[0;31m", "\033[0;32m", "\033[0;33m", "\033[0;34m",
                         "\033[0;35m"};
  int numCores = sizeof(cores) / sizeof(cores[0]);

  if (raiz == NULL) {
    return;
  }

  // Espaço entre os níveis
  const int espaco = 5;

  // Imprimir este nó
  if (nivel > 0) {
    int i;
    for (i = 0; i < nivel - 1; i++) {
      if (i % espaco == 0) {
        printf("|");
      } else {
        printf(" ");
      }
    }
    printf("|--");
  }
  // Imprimir este nó com a cor correspondente ao nível
  printf("%s%s\033[0m\n", cores[nivel % numCores], raiz->contato.nome);

  // Imprimir os filhos deste nó com cores diferentes
  int i;
  for (i = 0; i < raiz->numFilhos; i++) {
    imprimirArvore(raiz->filhos[i], nivel + 1);
  }
}

// Função para liberar memória da árvore
void liberarArvore(No *raiz) {
  if (raiz == NULL) {
    return;
  }
  int i;
  for (i = 0; i < raiz->numFilhos; i++) {
    liberarArvore(raiz->filhos[i]);
  }
  free(raiz);
}

int main() {
  setlocale(LC_ALL, "Portuguese");

  No *raiz = criarNo((Contato){"PESSOAL", "", ""});

  inserirContato(
      &raiz, (Contato){"CAIO", "9111111111", "caio.ndnamaral@aluno.uepa.br"});
  inserirContato(
      &raiz, (Contato){"ELAINE", "9122222222", "elaine.fdsantos@aluno.uepa.br"});
  inserirContato(&raiz, (Contato){"JONATHAN", "9133333333",
                                  "jonathan.madnascimento@aluno.uepa.br"});
  inserirContato(
      &raiz, (Contato){"SAMILY", "9144444444", "samily.vbmendes@aluno.uepa.br"});

  int escolha;
  char nome[50];
  char telefone[20];
  char email[50];

  do {
    printf("\nSistema de Gerenciamento de Contatos\n");
    printf("1. Inserir Contato\n");
    printf("2. Pesquisar Contato\n");
    printf("3. Remover Contato\n");
    printf("4. Exibir Contatos\n");
    printf("5. Exibir árvore\n");
    printf("6. Sair\n");
    printf("O que você deseja fazer: ");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      printf("Digite o nome: ");
      scanf("%s", nome);
      strToUpper(nome);
      printf("Digite o número de telefone: ");
      scanf("%s", telefone);
      printf("Digite o Email: ");
      scanf("%s", email);
      {
        Contato contato;
        strcpy(contato.nome, nome);
        strcpy(contato.telefone, telefone);
        strcpy(contato.email, email);
        inserirContato(&raiz, contato);
      }
      break;

    case 2:
      printf("Digite o nome para pesquisar: ");
      scanf("%s", nome);
      strToUpper(nome);
      {
        No *encontrado = buscarContato(raiz, nome);
        if (encontrado != NULL) {
          printf("\nContato encontrado:\n");
          printf("Nome: %s\n", encontrado->contato.nome);
          printf("Telefone: %s\n", encontrado->contato.telefone);
          printf("Email: %s\n", encontrado->contato.email);
        } else {
          printf("\nContato não encontrado.\n");
        }
      }
      break;

    case 3:
      printf("\nDigite o nome para remover: ");
      scanf("%s", nome);
      strToUpper(nome);
      removerContato(&raiz, nome);
      break;

    case 4:
      printf("\nLista de Contatos:\n");
      listarContatos(raiz);
      break;

    case 5:
      printf("\nÁrvore de Contatos:\n");
      imprimirArvore(raiz, 0);
      break;

    case 6:
      printf("Saindo do programa...\n");
      break;

    default:
      printf("Escolha inválida. Digite um número de 1 a 6.\n");
    }
  } while (escolha != 6);

  liberarArvore(raiz);

  return 0;
}