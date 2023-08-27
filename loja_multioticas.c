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
typedef struct node2 {
    Oculos_sol oculos_sol;
    struct node2 *proximo;
    struct node2 *anterior;
} Node2;

// Funções

void Vender_oculos_sol(Node2 *lista2){
    int codigo;
    Node2 *aux = lista2;
    printf("Digite o código do oculos de sol: ");
    scanf("%d", &codigo);
    while (aux != NULL) {
        if (aux->oculos_sol.codigo == codigo) {
            if(aux->oculos_sol.quantidade > 0){
                printf("Venda realizada com sucesso\n");
                aux->oculos_sol.quantidade -= 1;
                return;
            }
            else{
                printf("Não há oculos suficiente no estoque\n");
                return;
            }
        }
        aux = aux->proximo;
    }
    printf("Código não encontrado\n");
}

void Vender_oculos_ver(Node *lista) {
    int codigo;
    Node *aux = lista;
    printf("Digite o código do oculos de ver: ");
    scanf("%d", &codigo);
    while (aux != NULL) {
        if (aux->oculos_ver.codigo == codigo) {
            if(aux->oculos_ver.quantidade > 0){
                printf("Venda realizada com sucesso\n");
                aux->oculos_ver.quantidade -= 1;
                return;
            }
            else{
                printf("Não há oculos suficiente no estoque\n");
                return;
            }
        }
        aux = aux->proximo;
    }
    printf("Código não encontrado\n");
}


void listar_oculos_sol(Node2 *lista2){
    Node2 *aux = lista2;
    while(aux != NULL){
        printf("#####################################\n");
        printf("Código: %d\n", aux->oculos_sol.codigo);
        printf("Marca: %s\n", aux->oculos_sol.marca);
        printf("Preço: %.2f\n", aux->oculos_sol.preco);
        printf("Quantidade: %d\n", aux->oculos_sol.quantidade);
        aux = aux->proximo;
    }
}

void listar_oculos_ver(Node *lista){
    Node *aux = lista;
    while(aux != NULL){
        printf("#####################################\n");
        printf("Código: %d\n", aux->oculos_ver.codigo);
        printf("Marca: %s\n", aux->oculos_ver.marca);
        printf("Preço: %.2f\n", aux->oculos_ver.preco);
        printf("Quantidade: %d\n", aux->oculos_ver.quantidade);
        aux = aux->proximo;
    }
}

void listar_codigos_por_marcas_sol(int opcao, Node2 *lista2) {
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

int codigo_ja_existe2(Node2 *lista2, int novo_codigo) {
    Node2 *aux = lista2;
    while (aux != NULL) {
        if (aux->oculos_sol.codigo == novo_codigo) {
            return 1; 
        }
        aux = aux->proximo;
    }
    return 0; 
}


void oculos_sol(Oculos_sol *oculos_sol) {
    printf("Digite o código do oculos de ver: ");
    scanf("%d", &oculos_sol->codigo);
    printf("Digite a marca do oculos de ver: ");
    scanf("%s", oculos_sol->marca);
    printf("Digite o preço do oculos de ver: ");
    scanf("%f", &oculos_sol->preco);
    printf("Digite a quantidade do oculos de ver: ");
    scanf("%d", &oculos_sol->quantidade);
}

void inserir_oculos_sol(Node2 **lista2, Oculos_sol oculos_sol) {
    if (codigo_ja_existe2(*lista2, oculos_sol.codigo)) {
        int opcao;
        printf("Código já existe na lista. Não é possível inserir.\n");
        printf("Deseja adicionar à mercadoria já existente ou repetir?\n");
        printf("1 - Adicionar à mercadoria já existente\n");
        printf("2 - Repetir\n");
        scanf("%d", &opcao);
        if (opcao == 1) {
            Node2 *aux = *lista2;
            while (aux != NULL) {
                if (aux->oculos_sol.codigo == oculos_sol.codigo) {
                    aux->oculos_sol.quantidade += oculos_sol.quantidade;
                    break;
                }
                aux = aux->proximo;
            }
        } else {
            return;
        }
    }
    else{
        Node2 *novo = (Node2 *) malloc(sizeof(Node2));
        novo->oculos_sol = oculos_sol;
        novo->proximo = NULL;
        novo->anterior = NULL;
        
        if (*lista2 == NULL) {
            *lista2 = novo;
        } else {
            Node2 *aux = *lista2;
            while (aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
            novo->anterior = aux;
        }
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

//Menus

void menu_consultar(int *opcao){
    printf("                            1 - Consultar oculos de ver\n");
    printf("                            2 - Consultar oculos de sol\n");
    printf("                            3 - Consultar vendas do dia\n");
    printf("                            4 - Consultar vendas do mês\n");
    printf("                            5 - Consultar vendas do ano\n");
    printf("                            6 - Consultar vendas por data\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a opção desejada: ");
    scanf("%d", opcao);
}

void menu_vender(int *opcao){
    printf("                            1 - Vender oculos de ver\n");
    printf("                            2 - Vender oculos de sol\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a opção desejada: ");
    scanf("%d", opcao);
}

void menu_vendas(int *opcao){
    printf("                            1 - Vender oculos \n");
    printf("                            2 - Consultar vendas\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a opção desejada: ");
    scanf("%d", opcao);
}

void menu_listar(int *opcao){
    printf("                            1 - Listar oculos de ver\n");
    printf("                            2 - Listar oculos de sol\n");
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
                listar_codigos_por_marcas_sol(opcao, lista2);
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
                    case 2: {
                        Oculos_sol newOculos;
                        oculos_sol(&newOculos);
                        inserir_oculos_sol(&lista2, newOculos);
                    }
                    break;
                    
                    default:
                        break;
                }
                break;
            case 4:
                menu_listar(&opcao);
                switch (opcao)
                {
                    case 1:
                        listar_oculos_ver(lista);
                        break;
                        
                    case 2:
                        listar_oculos_sol(lista2);
                        break;
                    default:
                        break;
                }
                break;
            case 5:
                menu_vendas(&opcao);
                switch (opcao)
                {
                    case 1:
                        menu_vender(&opcao);
                        switch (opcao)
                        {
                            case 1:
                                Vender_oculos_ver(lista);
                                break;
                            case 2:
                                Vender_oculos_sol(lista2);  
                                    break;
                        }
                        break;
                    case 2:
                        menu_consultar(&opcao);
                        break;                
                    default:
                        break;
                }
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
