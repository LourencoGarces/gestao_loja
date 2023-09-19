#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

// Estrutura de dados

typedef struct {
    int id;
    int codigo;
    char marca[50];
    float preco;
    int quantidade;
    int tipo; 
} Oculos;

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
    int tipo; 
} Venda;

// Lista duplamente ligada única para óculos
typedef struct node_oculos {
    Oculos oculos;
    struct node_oculos *proximo;
    struct node_oculos *anterior;
} NodeOculos;

// Lista duplamente ligada única para vendas
typedef struct node_venda {
    Venda venda;
    struct node_venda *proximo;
    struct node_venda *anterior;
} NodeVenda;

// Funções
void horas_atuais(int *dia, int *mes, int *ano, int *hora, int *minutos, int *segundos) {
    time_t currentTime;
    struct tm *localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    *ano = localTime->tm_year + 1900;
    *mes = localTime->tm_mon + 1;
    *dia = localTime->tm_mday;
    *hora = localTime->tm_hour;
    *minutos = localTime->tm_min;
    *segundos = localTime->tm_sec;
}

void listar_vendas_dia(NodeVenda *lista){
    NodeVenda *aux = lista;
    int encontrou = 0; 
    int dia, mes, ano, hora, minutos, segundos;
    horas_atuais(&dia, &mes, &ano, &hora, &minutos, &segundos);
    while (aux != NULL) {
        if (aux->venda.dia == dia && aux->venda.mes == mes && aux->venda.ano == ano) { 
            encontrou = 1; 
            printf("#####################################\n");
            printf("ID: %d\n", aux->venda.id);
            printf("Código: %d\n", aux->venda.codigo);
            printf("Marca: %s\n", aux->venda.marca);
            printf("Preço: %.2f\n", aux->venda.preco);
            printf("Data atual: %04d-%02d-%02d às %02d:%02d:%02d\n", aux->venda.ano, aux->venda.mes, aux->venda.dia, aux->venda.hora, aux->venda.minutos, aux->venda.segundos);
            printf("\n");
        }
        aux = aux->proximo;
    }
    if (!encontrou) {
        printf("Não há vendas registradas\n");
    }
}

void listar_vendas_sol(NodeVenda *lista) {
    NodeVenda *aux = lista;
    int encontrou = 0; 
    while (aux != NULL) {
        if (aux->venda.tipo == 1) { 
            encontrou = 1; 
            printf("#####################################\n");
            printf("ID: %d\n", aux->venda.id);
            printf("Código: %d\n", aux->venda.codigo);
            printf("Marca: %s\n", aux->venda.marca);
            printf("Preço: %.2f\n", aux->venda.preco);
            printf("Data atual: %04d-%02d-%02d às %02d:%02d:%02d\n", aux->venda.ano, aux->venda.mes, aux->venda.dia, aux->venda.hora, aux->venda.minutos, aux->venda.segundos);
            printf("\n");
        }
        aux = aux->proximo;
    }
    if (!encontrou) {
        printf("Não há vendas de óculos de ver registradas\n");
    }
}

void listar_vendas_ver(NodeVenda *lista) {
    NodeVenda *aux = lista;
    int encontrou = 0; 
    while (aux != NULL) {
        if (aux->venda.tipo == 0) { 
            encontrou = 1; 
            printf("#####################################\n");
            printf("ID: %d\n", aux->venda.id);
            printf("Código: %d\n", aux->venda.codigo);
            printf("Marca: %s\n", aux->venda.marca);
            printf("Preço: %.2f\n", aux->venda.preco);
            printf("Data atual: %04d-%02d-%02d às %02d:%02d:%02d\n", aux->venda.ano, aux->venda.mes, aux->venda.dia, aux->venda.hora, aux->venda.minutos, aux->venda.segundos);
            printf("\n");
        }
        aux = aux->proximo;
    }
    if (!encontrou) {
        printf("Não há vendas de óculos de ver registradas\n");
    }
}

void Vender_oculos(NodeOculos *lista, NodeVenda **lista2, Venda venda, int tipo, int *id) {
    int codigo;
    int dia, mes, ano, hora, minutos, segundos;
    NodeOculos *aux = lista;
    if (tipo == 1) {
        printf("Digite o código do óculos de sol: ");
    } else if (tipo == 0) {
        printf("Digite o código do óculos de ver: ");
    } else {
        printf("Tipo de óculos inválido\n");
        return;
    }
    scanf("%d", &codigo);
    while (aux != NULL) {
        if (aux->oculos.codigo == codigo) {
            if (aux->oculos.quantidade > 0) {
                (*id) += 1;
                printf("Venda realizada com sucesso\n");
                horas_atuais(&dia, &mes, &ano, &hora, &minutos, &segundos);
                venda.dia = dia;
                venda.mes = mes;
                venda.ano = ano;
                venda.hora = hora;
                venda.minutos = minutos;
                venda.segundos = segundos;
                venda.id = *id;
                venda.codigo = aux->oculos.codigo;
                strcpy(venda.marca, aux->oculos.marca);
                venda.preco = aux->oculos.preco;
                venda.tipo = aux->oculos.tipo;
                NodeVenda *novo = (NodeVenda *)malloc(sizeof(NodeVenda));
                if (novo == NULL) {
                    printf("Erro ao alocar memória para Node\n");
                    return;
                }
                novo->venda = venda;
                novo->proximo = NULL;
                novo->anterior = NULL;
                if (*lista2 == NULL) {
                    *lista2 = novo;
                } else {
                    NodeVenda *aux2 = *lista2;
                    while (aux2->proximo != NULL) {
                        aux2 = aux2->proximo;
                    }
                    aux2->proximo = novo;
                    novo->anterior = aux2;
                }
                aux->oculos.quantidade -= 1;
                return;
            } else {
                printf("Não há óculos suficientes no estoque\n");
                return;
            }
        }
        aux = aux->proximo;
    }
    printf("Código não encontrado\n");
}


void listar_oculos_sol(NodeOculos *lista) {
    NodeOculos *aux = lista;
    while (aux != NULL) {
        if (aux->oculos.tipo == 1) {
            printf("#####################################\n");
            printf("Código: %d\n", aux->oculos.codigo);
            printf("Marca: %s\n", aux->oculos.marca);
            printf("Preço: %.2f\n", aux->oculos.preco);
            printf("Quantidade: %d\n", aux->oculos.quantidade);
        }
        aux = aux->proximo;
    }
}

void listar_oculos_ver(NodeOculos *lista) {
    NodeOculos *aux = lista;
    while (aux != NULL) {
        if (aux->oculos.tipo == 0) {
            printf("#####################################\n");
            printf("Código: %d\n", aux->oculos.codigo);
            printf("Marca: %s\n", aux->oculos.marca);
            printf("Preço: %.2f\n", aux->oculos.preco);
            printf("Quantidade: %d\n", aux->oculos.quantidade);
        }
        aux = aux->proximo;
    }
}

void listar_codigos_por_marcas_sol(int opcao, NodeOculos *lista) {
    NodeOculos *aux = lista;
    while (aux != NULL) {
        if (aux->oculos.tipo == 1) {
            if (opcao == 1) {
                if (stricmp(aux->oculos.marca, "Rayban") == 0) {
                    printf("Código: %d\n", aux->oculos.codigo);
                }
            } else if (opcao == 2) {
                if (stricmp(aux->oculos.marca, "Prada") == 0) {
                    printf("Código: %d\n", aux->oculos.codigo);
                }
            } else if (opcao == 3) {
                if (stricmp(aux->oculos.marca, "Gucci") == 0) {
                    printf("Código: %d\n", aux->oculos.codigo);
                }
            } else if (opcao == 4) {
                if (stricmp(aux->oculos.marca, "Oakley") == 0) {
                    printf("Código: %d\n", aux->oculos.codigo);
                }
            } else if (opcao == 5) {
                if (stricmp(aux->oculos.marca, "Vogue") == 0) {
                    printf("Código: %d\n", aux->oculos.codigo);
                }
            } else {
                printf("Opção inválida\n");
            }
        }
        aux = aux->proximo;
    }
}

void listar_codigos_por_marcas(int opcao, NodeOculos *lista) {
    NodeOculos *aux = lista;
    while (aux != NULL) {
        if (aux->oculos.tipo == 0) {
            if (opcao == 1) {
                if (stricmp(aux->oculos.marca, "Rayban") == 0) {
                    printf("Código: %d\n", aux->oculos.codigo);
                }
            } else if (opcao == 2) {
                if (stricmp(aux->oculos.marca, "Prada") == 0) {
                    printf("Código: %d\n", aux->oculos.codigo);
                }
            } else if (opcao == 3) {
                if (stricmp(aux->oculos.marca, "Gucci") == 0) {
                    printf("Código: %d\n", aux->oculos.codigo);
                }
            } else if (opcao == 4) {
                if (stricmp(aux->oculos.marca, "Oakley") == 0) {
                    printf("Código: %d\n", aux->oculos.codigo);
                }
            } else if (opcao == 5) {
                if (stricmp(aux->oculos.marca, "Vogue") == 0) {
                    printf("Código: %d\n", aux->oculos.codigo);
                }
            } else {
                printf("Opção inválida\n");
            }
        }
        aux = aux->proximo;
    }
}

int codigo_ja_existe(NodeOculos *lista, int novo_codigo) {
    NodeOculos *aux = lista;
    while (aux != NULL) {
        if (aux->oculos.codigo == novo_codigo) {
            return 1;
        }
        aux = aux->proximo;
    }
    return 0;
}

void oculos_sol(Oculos *oculos) {
    printf("Digite o código do óculos de sol: ");
    scanf("%d", &oculos->codigo);
    printf("Digite a marca do óculos de sol: ");
    scanf("%s", oculos->marca);
    printf("Digite o preço do óculos de sol: ");
    scanf("%f", &oculos->preco);
    printf("Digite a quantidade do óculos de sol: ");
    scanf("%d", &oculos->quantidade);
    oculos->tipo = 1;
}

void inserir_oculos(NodeOculos **lista, Oculos oculos) {
    if (codigo_ja_existe(*lista, oculos.codigo)) {
        int opcao;
        printf("Código já existe na lista. Não é possível inserir.\n");
        printf("Deseja adicionar à mercadoria já existente ou repetir?\n");
        printf("1 - Adicionar à mercadoria já existente\n");
        printf("2 - Repetir\n");
        scanf("%d", &opcao);
        if (opcao == 1) {
            NodeOculos *aux = *lista;
            while (aux != NULL) {
                if (aux->oculos.codigo == oculos.codigo) {
                    aux->oculos.quantidade += oculos.quantidade;
                    break;
                }
                aux = aux->proximo;
            }
        } else {
            return;
        }
    } else {
        NodeOculos *novo = (NodeOculos *)malloc(sizeof(NodeOculos));
        novo->oculos = oculos;
        novo->proximo = NULL;
        novo->anterior = NULL;
        if (*lista == NULL) {
            *lista = novo;
        } else {
            NodeOculos *aux = *lista;
            while (aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
}

void oculos_ver(Oculos *oculos) {
    printf("Digite o código do óculos de ver: ");
    scanf("%d", &oculos->codigo);
    printf("Digite a marca do óculos de ver: ");
    scanf("%s", oculos->marca);
    printf("Digite o preço do óculos de ver: ");
    scanf("%f", &oculos->preco);
    printf("Digite a quantidade do óculos de ver: ");
    scanf("%d", &oculos->quantidade);
    oculos->tipo = 0;
}

//Menus
void menu_excluir(int *opcao) {
    printf("                            1 - Excluir oculos de ver\n");
    printf("                            2 - Excluir oculos de sol\n");
    printf("                            3 - Venda\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a opção desejada: ");
    scanf("%d", opcao);
}

void menu_consultar(int *opcao) {
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

void menu_vender(int *opcao) {
    printf("                            1 - Vender oculos de ver\n");
    printf("                            2 - Vender oculos de sol\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a opção desejada: ");
    scanf("%d", opcao);
}

void menu_vendas(int *opcao) {
    printf("                            1 - Vender oculos \n");
    printf("                            2 - Consultar vendas\n");
    printf("                            0 - Sair\n");
    printf("                            Digite a opção desejada: ");
    scanf("%d", opcao);
}

void menu_listar(int *opcao) {
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
    printf("                            Bem vindo à loja Multioticas\n");
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
    NodeOculos *lista_oculos = NULL;
    NodeVenda *lista_vendas = NULL;
    Venda venda;
    int id = 0;
    int opcao = 1; 
    while (opcao != 0) { 
        menu(&opcao);
        switch (opcao) {
            case 1:
                menu_oculos_ver(&opcao);
                listar_codigos_por_marcas(opcao, lista_oculos);
                break;
            case 2:
                menu_oculos_sol(&opcao);
                listar_codigos_por_marcas_sol(opcao, lista_oculos);
                break;
            case 3:
                menu_inserir(&opcao);
                switch (opcao) {
                    case 1: {
                        Oculos oculos;
                        oculos_ver(&oculos);
                        inserir_oculos(&lista_oculos, oculos);
                    }
                        break;
                    case 2: {
                        Oculos oculos;
                        oculos_sol(&oculos);
                        inserir_oculos(&lista_oculos, oculos);
                    }
                        break;
                    case 0:
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                menu_listar(&opcao);
                switch (opcao) {
                    case 1:
                        listar_oculos_ver(lista_oculos);
                        break;
                    case 2:
                        listar_oculos_sol(lista_oculos);
                        break;
                    case 0:
                        break;
                    default:
                        break;
                }
                break;
            case 5:
                menu_vendas(&opcao);
                switch (opcao) {
                    case 1:
                        menu_vender(&opcao);
                        switch (opcao) {
                            case 1:
                                Vender_oculos(lista_oculos, &lista_vendas, venda, 0, &id);
                                break;
                            case 2:
                                Vender_oculos(lista_oculos, &lista_vendas, venda, 1, &id);
                                break;
                            case 0:
                                break;
                            default:
                                break;
                        }
                        break;
                    case 2:
                        menu_consultar(&opcao);
                        switch (opcao) {
                            case 1:{
                                Venda venda;
                                listar_vendas_ver(lista_vendas);
                            }
                                break;
                            case 2:{
                                Venda venda;
                                listar_vendas_sol(lista_vendas);
                            }break;
                            case 3:{
                                Venda venda;
                                listar_vendas_dia(lista_vendas);
                            }
                                break;
                            case 4:
                                {
                                Venda venda;
                                //listar_vendas_mes(lista_vendas);
                            }
                                break;
                            case 0:
                                break;
                            default:
                                break;
                        }
                    case 0:
                        break;
                    default:
                        break;
                }
                break;
            case 6:
                menu_excluir(&opcao);
                switch (opcao) {
                    case 1:
                        // Implemente a funcionalidade de exclusão de óculos de ver.
                        break;
                    case 2:
                        // Implemente a funcionalidade de exclusão de óculos de sol.
                        break;
                    case 3:
                        // Implemente a funcionalidade de venda.
                        break;
                    case 0:
                        break;
                    default:
                        break;
                }
                break;
            case 7:
                // Implemente a funcionalidade de ficha de cliente.
                break;
            case 0:
                break;
            default:
                break;
        }
    }
    return 0;
}

