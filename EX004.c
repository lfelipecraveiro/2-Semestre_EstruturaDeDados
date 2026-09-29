#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

// Constantes do programa
#define MINIMO 1
#define MAXIMO 5

//Definição de estruturas
typedef struct {
    int cod_cliente;
    char nm_cliente[50];
    char ds_endereco[50];
    int nr_numero;
    char nr_cpf[15];
    char ds_cidade[50];
    char est_ur[25];
    char dt_cadastro[25];
    char nr_telefone[25];
} reg_cliente;

typedef struct
{
    reg_cliente dados[MAXIMO];
    int primeiro;
    int ultimo;
} tipo_lista;
tipo_lista L;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void limpar_mensagem() {
    gotoxy(7, 23);
    printf("                                                                            ");
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Consome caracteres ate encontrar a quebra de linha
}

//Função que imprime a tela
void tela() {
    system("cls");
    int l;
    int c;

    for (l = 1; l < 25; l++)
    {
        gotoxy(01, l);
        printf("|");
        gotoxy(80, l);
        printf("|");
    }

    for (c = 1; c < 80; c++)
    {
        gotoxy(c, 01);
        printf("-");
        gotoxy(c, 04);
        printf("-");
        gotoxy(c, 22);
        printf("-");
        gotoxy(c, 24);
        printf("-");
    }

    gotoxy(03, 02);
    printf("UNICIVE");
    gotoxy(21, 02);
    printf("SISTEMA DE GESTAO DE CLIENTE");
    gotoxy(61, 02);
    printf("ESTRUTURA DE DADOS");

    gotoxy(01,01);
    printf("+");
    gotoxy(80,01);
    printf("+");

    gotoxy(01,04);
    printf("+");
    gotoxy(80,04);
    printf("+");

    gotoxy(01,22);
    printf("+");
    gotoxy(80,22);
    printf("+");

    gotoxy(01,24);
    printf("+");
    gotoxy(80,24);
    printf("+");
}

void tela_cliente(){
    gotoxy(10, 05);
    printf("Codigo cliente.: ");

    gotoxy(10, 07);
    printf("1 - Nome do cliente:");

    gotoxy(10, 9);
    printf("2 - Endereco.......:");

    gotoxy(10, 11);
    printf("3 - Numero.........:");

    gotoxy(10, 13);
    printf("4 - CPF............:");

    gotoxy(10, 15);
    printf("5 - Cidade.........:");

    gotoxy(10, 17);
    printf("6 - Estado.........:");

    gotoxy(10, 19);
    printf("7 - Data cadastro..:");

    gotoxy(10, 21);
    printf("8 - Telefone.......:");
}

//Função de pesquisa por código
int pesquisa(tipo_lista *L, int codigo) {
    int x;

    for(x=0;x<L->ultimo; x++) {
        if(L->dados[x].cod_cliente == codigo) {
            return x;
        }
    }

    return -1;
}

void incluir(tipo_lista *L) {
    reg_cliente clie;
    int result;
    int resp;

    do {
        do {
            tela();
            tela_cliente();

            gotoxy(35, 03);
            printf("---INCLUSAO---");

            gotoxy(07, 23);
            printf("Digite 0 para sair.: ");

            gotoxy(31, 05);
            scanf("%d", &clie.cod_cliente);
            limpar_buffer();

            result = pesquisa(L, clie.cod_cliente);

            if ((result != -1) && (clie.cod_cliente != 0)) {
                limpar_mensagem();
                gotoxy(2, 23);
                printf("Codigo ja existe, digite outro");
                getch();
            }

        } while ((clie.cod_cliente!=0)&&(result!=-1));

        if (clie.cod_cliente == 0) return;

        gotoxy(31, 07);
        fflush(stdin);
        fgets(clie.nm_cliente,50,stdin);

        gotoxy(31, 9);
        fflush(stdin);
        fgets(clie.ds_endereco,50,stdin);

        gotoxy(31, 11);
        scanf("%d", &clie.nr_numero);
        limpar_buffer();

        gotoxy(31, 13);
        fflush(stdin);
        fgets(clie.nr_cpf,15,stdin);

        gotoxy(31, 15);
        fflush(stdin);
        fgets(clie.ds_cidade,50,stdin);

        gotoxy(31, 17);
        fflush(stdin);
        fgets(clie.est_ur,25,stdin);

        gotoxy(31, 19);
        fflush(stdin);
        fgets(clie.dt_cadastro,25,stdin);

        gotoxy(31, 21);
        fflush(stdin);
        fgets(clie.nr_telefone,25,stdin);

        limpar_mensagem();
        gotoxy(2, 23);
        printf("Deseja gravar os dados (1=Sim; 2=Nao).: ");
        scanf("%d", &resp);

        if(resp==1) {
            if(L->ultimo >= MAXIMO) {
                limpar_mensagem();
                gotoxy(07, 23);
                printf("Lista cheia, nao e possivel gravar");
                getch();
            } else {
                L->dados[L->ultimo]=clie;
                L->ultimo++;
            }
        }

        limpar_mensagem();
        gotoxy(2, 23);
        printf("Deseja cadastrar outro (1=Sim; 2=Nao).: ");
        scanf("%d", &resp);

    } while(resp==1);
}

void alteracao(tipo_lista *L) {

    reg_cliente clie;
    int result;
    int resp;
    int opcao;

    do {
        tela();
        tela_cliente();

        gotoxy(27, 3);
        printf("-------- ALTERACAO ------");

        gotoxy(07, 23);
        printf("Digite 0 para sair.: ");

        gotoxy(31, 05);
        scanf("%d", &clie.cod_cliente);
        limpar_buffer();

        result = pesquisa(L, clie.cod_cliente);

        if ((result != -1) && (clie.cod_cliente != 0)) {

            clie = L->dados[result];

            limpar_mensagem();
            tela_cliente();

            gotoxy(31, 07);
            printf("%s", L->dados[result].nm_cliente);

            gotoxy(31, 9);
            printf("%s", L->dados[result].ds_endereco);

            gotoxy(31, 11);
            printf("%d", L->dados[result].nr_numero);

            gotoxy(31, 13);
            printf("%s", L->dados[result].nr_cpf);

            gotoxy(31, 15);
            printf("%s", L->dados[result].ds_cidade);

            gotoxy(31, 17);
            printf("%s", L->dados[result].est_ur);

            gotoxy(31, 19);
            printf("%s", L->dados[result].dt_cadastro);

            gotoxy(31, 21);
            printf("%s", L->dados[result].nr_telefone);

            limpar_mensagem();
            gotoxy(2, 23);
            printf("Digite o campo que deseja alterar (1-8).: ");
            scanf("%d", &opcao);
            limpar_buffer();

            switch (opcao) {

            case 1:
                gotoxy(31, 07);
                fflush(stdin);
                fgets(clie.nm_cliente, 50, stdin);
                break;

            case 2:
                gotoxy(31, 9);
                fflush(stdin);
                fgets(clie.ds_endereco, 50, stdin);
                break;

            case 3:
                gotoxy(31, 11);
                scanf("%d", &clie.nr_numero);
                limpar_buffer();
                break;

            case 4:
                gotoxy(31, 13);
                fflush(stdin);
                fgets(clie.nr_cpf, 15, stdin);
                break;

            case 5:
                gotoxy(31, 15);
                fflush(stdin);
                fgets(clie.ds_cidade, 50, stdin);
                break;

            case 6:
                gotoxy(31, 17);
                fflush(stdin);
                fgets(clie.est_ur, 25, stdin);
                break;

            case 7:
                gotoxy(31, 19);
                fflush(stdin);
                fgets(clie.dt_cadastro, 25, stdin);
                break;

            case 8:
                gotoxy(31, 21);
                fflush(stdin);
                fgets(clie.nr_telefone, 25, stdin);
                break;

            default:
                break;
            }

            // gravação
            limpar_mensagem();
            gotoxy(2, 23);
            printf("Deseja gravar os dados (1=Sim; 2=Nao).: ");
            scanf("%d", &resp);

            if(resp==1) {
                L->dados[result] = clie;

                limpar_mensagem();
                gotoxy(2, 23);
                printf("Dados alterados com sucesso!");
                getch();
            }

        } else if(clie.cod_cliente == 0) {

            return;

        } else {

            limpar_mensagem();
            gotoxy(2, 23);
            printf("Codigo nao encontrado!");
            getch();
        }

        limpar_mensagem();
        gotoxy(2, 23);
        printf("Deseja finalizar alteracao (1=Sim; 2=Nao).: ");
        scanf("%d", &resp);

        if(resp==1) {
            return;
        }

    } while (resp!=1);
}
void exclusao(tipo_lista *L) {

    reg_cliente clie;
    int result;
    int resp;
    int x;

    do {
        tela();
        tela_cliente();

        gotoxy(27, 3);
        printf("-------- EXCLUSAO -------");

        gotoxy(07, 23);
        printf("Digite 0 para sair.: ");

        gotoxy(31, 05);
        scanf("%d", &clie.cod_cliente);
        limpar_buffer();

        if(clie.cod_cliente == 0) {
            return;
        }

        result = pesquisa(L, clie.cod_cliente);

        if(result != -1) {

            clie = L->dados[result];

            limpar_mensagem();
            tela_cliente();

            gotoxy(31, 07);
            printf("%s", L->dados[result].nm_cliente);

            gotoxy(31, 9);
            printf("%s", L->dados[result].ds_endereco);

            gotoxy(31, 11);
            printf("%d", L->dados[result].nr_numero);

            gotoxy(31, 13);
            printf("%s", L->dados[result].nr_cpf);

            gotoxy(31, 15);
            printf("%s", L->dados[result].ds_cidade);

            gotoxy(31, 17);
            printf("%s", L->dados[result].est_ur);

            gotoxy(31, 19);
            printf("%s", L->dados[result].dt_cadastro);

            gotoxy(31, 21);
            printf("%s", L->dados[result].nr_telefone);

            limpar_mensagem();
            gotoxy(2, 23);
            printf("Deseja excluir os dados (1=Sim; 2=Nao).: ");
            scanf("%d", &resp);

            if(resp == 1) {

                for(x = result; x < L->ultimo - 1; x++) {
                    L->dados[x] = L->dados[x + 1];
                }

                L->ultimo--;

                limpar_mensagem();
                gotoxy(2, 23);
                printf("Dados excluidos com sucesso!");
                getch();
            }

        } else {

            limpar_mensagem();
            gotoxy(2, 23);
            printf("Codigo nao encontrado!");
            getch();
        }

        limpar_mensagem();
        gotoxy(2, 23);
        printf("Deseja finalizar exclusao (1=Sim; 2=Nao).: ");
        scanf("%d", &resp);

        if(resp == 1) {
            return;
        }

    } while(resp != 1);
}

void consulta(tipo_lista *L) {

    reg_cliente clie;
    int result;
    int resp;

    do {
        tela();
        tela_cliente();

        gotoxy(27, 3);
        printf("-------- CONSULTA -------");

        gotoxy(07, 23);
        printf("Digite 0 para sair.: ");

        gotoxy(31, 05);
        scanf("%d", &clie.cod_cliente);
        limpar_buffer();

        if(clie.cod_cliente == 0) {
            return;
        }

        result = pesquisa(L, clie.cod_cliente);

        if (result != -1) {

            limpar_mensagem();
            tela_cliente();

            gotoxy(31, 07);
            printf("%s", L->dados[result].nm_cliente);

            gotoxy(31, 9);
            printf("%s", L->dados[result].ds_endereco);

            gotoxy(31, 11);
            printf("%d", L->dados[result].nr_numero);

            gotoxy(31, 13);
            printf("%s", L->dados[result].nr_cpf);

            gotoxy(31, 15);
            printf("%s", L->dados[result].ds_cidade);

            gotoxy(31, 17);
            printf("%s", L->dados[result].est_ur);

            gotoxy(31, 19);
            printf("%s", L->dados[result].dt_cadastro);

            gotoxy(31, 21);
            printf("%s", L->dados[result].nr_telefone);

        } else {

            limpar_mensagem();
            gotoxy(2, 23);
            printf("Codigo nao encontrado!");
            getch();
        }

        limpar_mensagem();
        gotoxy(2, 23);
        printf("Deseja finalizar consulta (1=Sim; 2=Nao).: ");
        scanf("%d", &resp);

        if(resp==1) {
            return;
        }

    } while (resp!=1);
}


int main() {
    char opcao;

    do
    {
        tela();

        gotoxy(35, 03);
        printf("===MENU===");

        gotoxy(35, 07);
        printf("1 - Inclusao\n");

        gotoxy(35, 9);
        printf("2 - Alteracao\n");

        gotoxy(35, 11);
        printf("3 - Exclusao\n");

        gotoxy(35, 13);
        printf("4 - Consulta\n");

        gotoxy(35, 15);
        printf("5 - Listar Clientes\n");

        gotoxy(35, 17);
        printf("6 - Finalizar\n");

        gotoxy(02, 23);
        printf("Digite sua Opcao: ");
        scanf(" %c", &opcao);

        switch(opcao) {

            case '1':
                incluir(&L);
                break;

            case '2':
                tela();
                alteracao(&L);
                break;

            case '3':
                tela();
                exclusao(&L);
                break;

            case '4':
                tela();
                consulta(&L);
                break;

            case '5':
                tela();
                //listar clientes;
                break;

            case '6':
                tela();
                //fim de programa;
                break;

            default:
                tela();
                gotoxy(30, 20);
                printf("Opcao invalida!");
                break;
        }

    //6 é a opção de finalizar
    } while(opcao!='6');
}