#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura de dados

typedef struct  {
    int id;
    int codigo;
    char marca[50];
    float preco;
    int quantidade;
} Oculos_ver;

typedef struct  {
    int id;
    int codigo;
    char marca[50];
    float preco;
    int quantidade;
} Oculos_sol;

//uso de listas duplamente ligadas

typedef struct node {
    Oculos_ver oculos_ver;
    struct node *proximo;
    struct node *anterior;
} Node;

//uso de listas duplamente ligadas
typedef struct node {
    Oculos_sol oculos_sol;
    struct node *proximo;
    struct node *anterior;
} Node2;

// Funções

void listar_codigos_por_marcas(int opcao, Node2 *lista2) {
    Node2 *aux = lista2;
    while (aux != NULL) {
        if(opcao == 1){
            if (stricmp(aux->oculos_sol.marca, "Rayban") == 0) {
                printf("Código: %d\n", aux->oculos_sol.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 2){
            if (stricmp(aux->oculos_sol.marca, "Prada") == 0) {
                printf("Código: %d\n", aux->oculos_sol.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 3){
            if (stricmp(aux->oculos_sol.marca, "Gucci") == 0) {
                printf("Código: %d\n", aux->oculos_sol.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 4){
            if (stricmp(aux->oculos_sol.marca, "Oakley") == 0) {
                printf("Código: %d\n", aux->oculos_sol.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 5){
            if (stricmp(aux->oculos_sol.marca, "Vogue") == 0) {
                printf("Código: %d\n", aux->oculos_sol.codigo);
            }
            aux = aux->proximo;
        }
        else{
            printf("Opção inválida\n");
        }
    }
}

void listar_codigos_por_marcas(int opcao, Node *lista) {
    Node *aux = lista;
    while (aux != NULL) {
        if(opcao == 1){
            if (stricmp(aux->oculos_ver.marca, "Rayban") == 0) {
                printf("Código: %d\n", aux->oculos_ver.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 2){
            if (stricmp(aux->oculos_ver.marca, "Prada") == 0) {
                printf("Código: %d\n", aux->oculos_ver.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 3){
            if (stricmp(aux->oculos_ver.marca, "Gucci") == 0) {
                printf("Código: %d\n", aux->oculos_ver.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 4){
            if (stricmp(aux->oculos_ver.marca, "Oakley") == 0) {
                printf("Código: %d\n", aux->oculos_ver.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 5){
            if (stricmp(aux->oculos_ver.marca, "Vogue") == 0) {
                printf("Código: %d\n", aux->oculos_ver.codigo);
            }
            aux = aux->proximo;
        }
        else{
            printf("Opção inválida\n");
        }
    }
}

void listar_oculos_ver(Node *lista) {
    Node *aux = lista;
    while (aux != NULL) {
        printf("Código: %d\n", aux->oculos_ver.codigo);
        printf("Marca: %s\n", aux->oculos_ver.marca);
        printf("Preço: %.2f\n", aux->oculos_ver.preco);
        printf("Quantidade: %d\n", aux->oculos_ver.quantidade);
        aux = aux->proximo;
    }
}

int codigo_ja_existe(Node *lista, int novo_codigo) {
    Node *aux = lista;
    while (aux != NULL) {
        if (aux->oculos_ver.codigo == novo_codigo) {
            return 1; 
        }
        aux = aux->proximo;
    }
    return 0; 
}


void oculos_ver(Oculos_ver *oculos_ver) {
    printf("Digite o código do oculos de ver: ");
    scanf("%d", &oculos_ver->codigo);
    printf("Digite a marca do oculos de ver: ");
    scanf("%s", oculos_ver->marca);
    printf("Digite o preço do oculos de ver: ");
    scanf("%f", &oculos_ver->preco);
    printf("Digite a quantidade do oculos de ver: ");
    scanf("%d", &oculos_ver->quantidade);
}

void inserir_oculos_ver(Node **lista, Oculos_ver oculos_ver) {
    if (codigo_ja_existe(*lista, oculos_ver.codigo)) {
        int opcao;
        printf("Código já existe na lista. Não é possível inserir.\n");
        printf("Deseja adicionar à mercadoria já existente ou repetir?\n");
        printf("1 - Adicionar à mercadoria já existente\n");
        printf("2 - Repetir\n");
        scanf("%d", &opcao);
        if (opcao == 1) {
            Node *aux = *lista;
            while (aux != NULL) {
                if (aux->oculos_ver.codigo == oculos_ver.codigo) {
                    aux->oculos_ver.quantidade += oculos_ver.quantidade;
                    break;
                }
                aux = aux->proximo;
            }
        } else {
            return;
        }
    }
    else{
        Node *novo = (Node *) malloc(sizeof(Node));
        novo->oculos_ver = oculos_ver;
        novo->proximo = NULL;
        novo->anterior = NULL;
        
        if (*lista == NULL) {
            *lista = novo;
        } else {
            Node *aux = *lista;
            while (aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
}

//Menu

void menu_oculos_sol(int *opcao) {
    printf("                            Escolha a marca\n");
    printf("                            1 - Rayban\n");
    printf("                            2 - Prada\n");
    printf("                            3 - Gucci\n");
    printf("                            4 - Oakley\n");
    printf("                            5 - Vogue\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a opção desejada: ");
    scanf("%d", opcao);
}

void menu_oculos_ver(int *opcao) {
    printf("                            Escolha a marca\n");
    printf("                            1 - Rayban\n");
    printf("                            2 - Prada\n");
    printf("                            3 - Gucci\n");
    printf("                            4 - Oakley\n");
    printf("                            5 - Vogue\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a opção desejada: ");
    scanf("%d", opcao);
}

void menu_inserir(int *opcao) {
    printf("                            Bem vindo a loja Multioticas\n");
    printf("                            1 - Inserir oculos de ver\n");
    printf("                            2 - Inserir oculos de sol\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a opção desejada: ");
    scanf("%d", opcao);
}

void menu(int *opcao) {
    printf("                            Bem vindo a loja Multioticas\n");
    printf("                            1 - Ver códigos dos oculos de ver\n");
    printf("                            2 - Ver códigos dos oculos de sol\n");
    printf("                            3 - Inserir\n");
    printf("                            4 - Listar\n");
    printf("                            5 - Vendas\n");
    printf("                            6 - Excluir\n");
    printf("                            7 - Ficha de cliente\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a opção desejada: ");
    scanf("%d", opcao);
}

int main() {
    setlocale(LC_ALL, "");
    Node *lista = NULL;
    Node2 *lista2 = NULL;
    int opcao = -1;  // Defina um valor inicial diferente de 0 para entrar no loop

    while (opcao != 0) {  // O loop continuará até que o usuário escolha sair (opção 0)
        menu(&opcao);

        switch (opcao) {
            case 1:
                menu_oculos_ver(&opcao);
                listar_codigos_por_marcas(opcao, lista);
                break;
            case 2:
                menu_oculos_sol(&opcao);
                listar_codigos_por_marcas(opcao, lista2);
                break;
            case 3:
                menu_inserir(&opcao);
                switch (opcao) {
                    case 1: {
                        Oculos_ver newOculos;
                        oculos_ver(&newOculos);
                        inserir_oculos_ver(&lista, newOculos);
                    }
                    break;
                    default:
                        break;
                }
                break;
            case 4:
                // Implemente a funcionalidade para listar
                break;
            case 5:
                // Implemente a funcionalidade de vendas
                break;
            case 6:
                // Implemente a funcionalidade de exclusão
                break;
            case 7:
                // Implemente a funcionalidade de ficha de cliente
                break;
            case 0:
                printf("Obrigado por usar o programa!\n");
                break;
            default:
                break;
        }
    }

    // Libere a memória alocada para a lista de óculos antes de sair
    // ...
    
    return 0;
}
