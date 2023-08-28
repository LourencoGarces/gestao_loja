#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

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


typedef struct {
    int id;
    int codigo;
    char marca[50];
    float preco;
    int dia;
    int mes;
    int ano;
    int hora;
    int minutos;
    int segundos;
} Venda_ver;

typedef struct {
    int id;
    int codigo;
    char marca[50];
    float preco;
    int dia;
    int mes;
    int ano;
    int hora;
    int minutos;
    int segundos;
} Venda_sol;

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

typedef struct node3 {
    Venda_ver venda_ver;
    struct node3 *proximo;
    struct node3 *anterior;
} Node3;

typedef struct node4 {
    Venda_sol venda_sol;
    struct node4 *proximo;
    struct node4 *anterior;
} Node4;

// Fun��es

void listar_vendas_sol(Node4 *lista4) {
    Node4 *aux = lista4;
    while (aux != NULL) {
        printf("#####################################\n");
        printf("C�digo: %d\n", aux->venda_sol.codigo);
        printf("Marca: %s\n", aux->venda_sol.marca);
        printf("Pre�o: %.2f\n", aux->venda_sol.preco);
        printf("Data atual: %04d-%02d-%02d �s %02d:%02d:%02d\n", aux->venda_sol.ano, aux->venda_sol.mes, aux->venda_sol.dia, aux->venda_sol.hora, aux->venda_sol.minutos, aux->venda_sol.segundos);
        printf("\n");
        aux = aux->proximo;
    }
    if (aux == NULL) {
        printf("N�o h� vendas registradas\n");
    }
    
}

void listar_vendas_ver(Node3 *lista3) {
    Node3 *aux = lista3;
    while (aux != NULL) {
        printf("#####################################\n");
        printf("C�digo: %d\n", aux->venda_ver.codigo);
        printf("Marca: %s\n", aux->venda_ver.marca);
        printf("Pre�o: %.2f\n", aux->venda_ver.preco);
        printf("Data atual: %04d-%02d-%02d �s %02d:%02d:%02d\n", aux->venda_ver.ano, aux->venda_ver.mes, aux->venda_ver.dia, aux->venda_ver.hora, aux->venda_ver.minutos, aux->venda_ver.segundos);
        printf("\n");
        aux = aux->proximo;
    }
    if (aux == NULL) {
        printf("N�o h� vendas registradas\n");
    }
    
}

void Vender_oculos_sol(Node2 *lista2, Node4 **lista4, Venda_sol venda_sol, int dia, int mes, int ano, int hora, int minutos, int segundos) {
    int codigo;
    Node2 *aux = lista2;
    printf("Digite o c�digo do oculos de ver: ");
    scanf("%d", &codigo);
    while (aux != NULL) {
        if (aux->oculos_sol.codigo == codigo) {
            if (aux->oculos_sol.quantidade > 0) {
                printf("Venda realizada com sucesso\n");
                Node4 *novo = (Node4 *) malloc(sizeof(Node4));
                if (novo == NULL) {
                    printf("Erro ao alocar mem�ria para Node3\n");
                    return;
                }
                novo->venda_sol = venda_sol;
                novo->venda_sol.dia = dia;  
                novo->venda_sol.mes = mes;
                novo->venda_sol.ano = ano;
                novo->venda_sol.hora = hora;
                novo->venda_sol.minutos = minutos;
                novo->venda_sol.segundos = segundos;
                novo->proximo = NULL;
                novo->anterior = NULL;
                if (*lista4 == NULL) {
                    *lista4 = novo;
                } else {
                    Node4 *aux2 = *lista4;
                    while (aux2->proximo != NULL) {
                        aux2 = aux2->proximo;
                    }
                    aux2->proximo = novo;
                    novo->anterior = aux2;
                }
                aux->oculos_sol.quantidade -= 1;
                return;
            } else {
                printf("N�o h� oculos suficiente no estoque\n");
                return;
            }
        }
        aux = aux->proximo;
    }
    printf("C�digo n�o encontrado\n");
}

void Vender_oculos_ver(Node *lista, Node3 **lista3, Venda_ver venda_ver, int dia, int mes, int ano, int hora, int minutos, int segundos) {
    int codigo;
    Node *aux = lista;
    printf("Digite o c�digo do oculos de ver: ");
    scanf("%d", &codigo);
    while (aux != NULL) {
        if (aux->oculos_ver.codigo == codigo) {
            if (aux->oculos_ver.quantidade > 0) {
                printf("Venda realizada com sucesso\n");
                Node3 *novo = (Node3 *) malloc(sizeof(Node3));
                if (novo == NULL) {
                    printf("Erro ao alocar mem�ria para Node3\n");
                    return;
                }
                novo->venda_ver = venda_ver;
                novo->venda_ver.dia = dia;  
                novo->venda_ver.mes = mes;
                novo->venda_ver.ano = ano;
                novo->venda_ver.hora = hora;
                novo->venda_ver.minutos = minutos;
                novo->venda_ver.segundos = segundos;
                novo->proximo = NULL;
                novo->anterior = NULL;
                if (*lista3 == NULL) {
                    *lista3 = novo;
                } else {
                    Node3 *aux2 = *lista3;
                    while (aux2->proximo != NULL) {
                        aux2 = aux2->proximo;
                    }
                    aux2->proximo = novo;
                    novo->anterior = aux2;
                }
                aux->oculos_ver.quantidade -= 1;
                return;
            } else {
                printf("N�o h� oculos suficiente no estoque\n");
                return;
            }
        }
        aux = aux->proximo;
    }
    printf("C�digo n�o encontrado\n");
}

void listar_oculos_sol(Node2 *lista2){
    Node2 *aux = lista2;
    while(aux != NULL){
        printf("#####################################\n");
        printf("C�digo: %d\n", aux->oculos_sol.codigo);
        printf("Marca: %s\n", aux->oculos_sol.marca);
        printf("Pre�o: %.2f\n", aux->oculos_sol.preco);
        printf("Quantidade: %d\n", aux->oculos_sol.quantidade);
        aux = aux->proximo;
    }
}

void listar_oculos_ver(Node *lista){
    Node *aux = lista;
    while(aux != NULL){
        printf("#####################################\n");
        printf("C�digo: %d\n", aux->oculos_ver.codigo);
        printf("Marca: %s\n", aux->oculos_ver.marca);
        printf("Pre�o: %.2f\n", aux->oculos_ver.preco);
        printf("Quantidade: %d\n", aux->oculos_ver.quantidade);
        aux = aux->proximo;
    }
}

void listar_codigos_por_marcas_sol(int opcao, Node2 *lista2) {
    Node2 *aux = lista2;
    while (aux != NULL) {
        if(opcao == 1){
            if (stricmp(aux->oculos_sol.marca, "Rayban") == 0) {
                printf("C�digo: %d\n", aux->oculos_sol.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 2){
            if (stricmp(aux->oculos_sol.marca, "Prada") == 0) {
                printf("C�digo: %d\n", aux->oculos_sol.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 3){
            if (stricmp(aux->oculos_sol.marca, "Gucci") == 0) {
                printf("C�digo: %d\n", aux->oculos_sol.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 4){
            if (stricmp(aux->oculos_sol.marca, "Oakley") == 0) {
                printf("C�digo: %d\n", aux->oculos_sol.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 5){
            if (stricmp(aux->oculos_sol.marca, "Vogue") == 0) {
                printf("C�digo: %d\n", aux->oculos_sol.codigo);
            }
            aux = aux->proximo;
        }
        else{
            printf("Op��o inv�lida\n");
        }
    }
}

void listar_codigos_por_marcas(int opcao, Node *lista) {
    Node *aux = lista;
    while (aux != NULL) {
        if(opcao == 1){
            if (stricmp(aux->oculos_ver.marca, "Rayban") == 0) {
                printf("C�digo: %d\n", aux->oculos_ver.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 2){
            if (stricmp(aux->oculos_ver.marca, "Prada") == 0) {
                printf("C�digo: %d\n", aux->oculos_ver.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 3){
            if (stricmp(aux->oculos_ver.marca, "Gucci") == 0) {
                printf("C�digo: %d\n", aux->oculos_ver.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 4){
            if (stricmp(aux->oculos_ver.marca, "Oakley") == 0) {
                printf("C�digo: %d\n", aux->oculos_ver.codigo);
            }
            aux = aux->proximo;
        }
        else if(opcao == 5){
            if (stricmp(aux->oculos_ver.marca, "Vogue") == 0) {
                printf("C�digo: %d\n", aux->oculos_ver.codigo);
            }
            aux = aux->proximo;
        }
        else{
            printf("Op��o inv�lida\n");
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
    printf("Digite o c�digo do oculos de ver: ");
    scanf("%d", &oculos_sol->codigo);
    printf("Digite a marca do oculos de ver: ");
    scanf("%s", oculos_sol->marca);
    printf("Digite o pre�o do oculos de ver: ");
    scanf("%f", &oculos_sol->preco);
    printf("Digite a quantidade do oculos de ver: ");
    scanf("%d", &oculos_sol->quantidade);
}

void inserir_oculos_sol(Node2 **lista2, Oculos_sol oculos_sol) {
    if (codigo_ja_existe2(*lista2, oculos_sol.codigo)) {
        int opcao;
        printf("C�digo j� existe na lista. N�o � poss�vel inserir.\n");
        printf("Deseja adicionar � mercadoria j� existente ou repetir?\n");
        printf("1 - Adicionar � mercadoria j� existente\n");
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
    printf("Digite o c�digo do oculos de ver: ");
    scanf("%d", &oculos_ver->codigo);
    printf("Digite a marca do oculos de ver: ");
    scanf("%s", oculos_ver->marca);
    printf("Digite o pre�o do oculos de ver: ");
    scanf("%f", &oculos_ver->preco);
    printf("Digite a quantidade do oculos de ver: ");
    scanf("%d", &oculos_ver->quantidade);
}

void inserir_oculos_ver(Node **lista, Oculos_ver oculos_ver) {
    if (codigo_ja_existe(*lista, oculos_ver.codigo)) {
        int opcao;
        printf("C�digo j� existe na lista. N�o � poss�vel inserir.\n");
        printf("Deseja adicionar � mercadoria j� existente ou repetir?\n");
        printf("1 - Adicionar � mercadoria j� existente\n");
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
    printf("                            4 - Consultar vendas do m�s\n");
    printf("                            5 - Consultar vendas do ano\n");
    printf("                            6 - Consultar vendas por data\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a op��o desejada: ");
    scanf("%d", opcao);
}

void menu_vender(int *opcao){
    printf("                            1 - Vender oculos de ver\n");
    printf("                            2 - Vender oculos de sol\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a op��o desejada: ");
    scanf("%d", opcao);
}

void menu_vendas(int *opcao){
    printf("                            1 - Vender oculos \n");
    printf("                            2 - Consultar vendas\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a op��o desejada: ");
    scanf("%d", opcao);
}

void menu_listar(int *opcao){
    printf("                            1 - Listar oculos de ver\n");
    printf("                            2 - Listar oculos de sol\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a op��o desejada: ");
    scanf("%d", opcao);
}

void menu_inserir(int *opcao) {
    printf("                            Bem vindo a loja Multioticas\n");
    printf("                            1 - Inserir oculos de ver\n");
    printf("                            2 - Inserir oculos de sol\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a op��o desejada: ");
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
    printf("                            Digite a op��o desejada: ");
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
    printf("                            Digite a op��o desejada: ");
    scanf("%d", opcao);
}

void menu(int *opcao) {
    printf("                            Bem vindo � loja Multioticas\n");
    printf("                            1 - Ver c�digos dos oculos de ver\n");
    printf("                            2 - Ver c�digos dos oculos de sol\n");
    printf("                            3 - Inserir\n");
    printf("                            4 - Listar\n");
    printf("                            5 - Vendas\n");
    printf("                            6 - Excluir\n");
    printf("                            7 - Ficha de cliente\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a op��o desejada: ");
    scanf("%d", opcao);
}

int main() {
    time_t currentTime;
    struct tm *localTime;
    setlocale(LC_ALL, "");
    Node *lista = NULL;
    Node2 *lista2 = NULL;
    Node3 *lista3 = NULL;
    Node4 *lista4 = NULL;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    int ano = localTime->tm_year + 1900;
    int mes = localTime->tm_mon + 1;
    int dia = localTime->tm_mday;
    int hora = localTime->tm_hour;
    int minutos = localTime->tm_min;
    int segundos = localTime->tm_sec;

    int opcao = -1;  // Defina um valor inicial diferente de 0 para entrar no loop

    while (opcao != 0) {  // O loop continuar� at� que o usu�rio escolha sair (op��o 0)
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
                            case 1:{
                                Venda_ver venda;
                                Vender_oculos_ver(lista, &lista3, venda, dia, mes, ano, hora, minutos, segundos);
                            }
                                break;
                            case 2:{
                                Venda_sol venda2;
                                Vender_oculos_sol(lista2, &lista4, venda2, dia, mes, ano, hora, minutos, segundos);  
                            }
                            default:
                                break;
                        }
                        break;
                    case 2:
                        //menu_consultar(&opcao);
                        listar_vendas_ver(lista3);
                        break;                
                    case 3:
                        //menu_consultar(&opcao);
                        listar_vendas_sol(lista4);
                        break;
                    default:
                        break;
                }
                break;
            case 6:
                // Implemente a funcionalidade de exclus�o
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

    // Libere a mem�ria alocada para a lista de �culos antes de sair
    // ...
    
    return 0;
}
