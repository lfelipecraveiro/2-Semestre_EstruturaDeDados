#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

// Constantes do programa
#define MINIMO 1
#define MAXIMO 5

// Definição de estruturas
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

typedef struct {
    reg_cliente dados[MAXIMO];
    int primeiro;
    int ultimo;
} tipo_lista;

tipo_lista L;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );
}

void limpar_mensagem() {
    gotoxy(7, 23);
    printf("                                                                            ");
}

void limpar_buffer() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

// Função que imprime a tela
void tela() {
    system("cls");

    int l;
    int c;

    for (l = 1; l < 25; l++) {
        gotoxy(1, l);
        printf("|");

        gotoxy(80, l);
        printf("|");
    }

    for (c = 1; c < 80; c++) {
        gotoxy(c, 1);
        printf("-");

        gotoxy(c, 4);
        printf("-");

        gotoxy(c, 22);
        printf("-");

        gotoxy(c, 24);
        printf("-");
    }

    gotoxy(3, 2);
    printf("UNICIVE");

    gotoxy(21, 2);
    printf("SISTEMA DE GESTAO DE CLIENTE");

    gotoxy(61, 2);
    printf("ESTRUTURA DE DADOS");

    gotoxy(1, 1);
    printf("+");

    gotoxy(80, 1);
    printf("+");

    gotoxy(1, 4);
    printf("+");

    gotoxy(80, 4);
    printf("+");

    gotoxy(1, 22);
    printf("+");

    gotoxy(80, 22);
    printf("+");

    gotoxy(1, 24);
    printf("+");

    gotoxy(80, 24);
    printf("+");
}

void tela_cliente() {
    gotoxy(10, 5);
    printf("Codigo cliente.: ");

    gotoxy(10, 7);
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

// Função de pesquisa por código
int pesquisa(tipo_lista *L, int codigo) {
    int x;

    for (x = 0; x < L->ultimo; x++) {
        if (L->dados[x].cod_cliente == codigo) {
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

            gotoxy(35, 3);
            printf("---INCLUSAO---");

            gotoxy(7, 23);
            printf("Digite 0 para sair.: ");

            gotoxy(31, 5);
            scanf("%d", &clie.cod_cliente);

            limpar_buffer();

            result = pesquisa(L, clie.cod_cliente);

            if ((result != -1) && (clie.cod_cliente != 0)) {
                limpar_mensagem();

                gotoxy(2, 23);
                printf("Codigo ja existe, digite outro");

                getch();
            }

        } while ((clie.cod_cliente != 0) && (result != -1));

        if (clie.cod_cliente == 0) {
            return;
        }

        gotoxy(31, 7);
        fgets(clie.nm_cliente, 50, stdin);

        gotoxy(31, 9);
        fgets(clie.ds_endereco, 50, stdin);

        gotoxy(31, 11);
        scanf("%d", &clie.nr_numero);

        limpar_buffer();

        gotoxy(31, 13);
        fgets(clie.nr_cpf, 15, stdin);

        gotoxy(31, 15);
        fgets(clie.ds_cidade, 50, stdin);

        gotoxy(31, 17);
        fgets(clie.est_ur, 25, stdin);

        gotoxy(31, 19);
        fgets(clie.dt_cadastro, 25, stdin);

        gotoxy(31, 21);
        fgets(clie.nr_telefone, 25, stdin);

        limpar_mensagem();

        gotoxy(2, 23);
        printf("Deseja gravar os dados (1=Sim; 2=Nao).: ");

        scanf("%d", &resp);

        if (resp == 1) {

            if (L->ultimo >= MAXIMO) {
                limpar_mensagem();

                gotoxy(7, 23);
                printf("Lista cheia, nao e possivel gravar");

                getch();

            } else {
                L->dados[L->ultimo] = clie;
                L->ultimo++;
            }
        }

        limpar_mensagem();

        gotoxy(2, 23);
        printf("Deseja cadastrar outro (1=Sim; 2=Nao).: ");

        scanf("%d", &resp);

    } while (resp == 1);
}

void alteracao() {
    tela();
    tela_cliente();

    gotoxy(27, 3);
    printf("-------- ALTERACAO ------");
}

void exclusao() {
    tela();
    tela_cliente();

    gotoxy(27, 3);
    printf("-------- EXCLUSAO -------");
}

void consulta() {
    tela();
    tela_cliente();

    gotoxy(27, 3);
    printf("-------- CONSULTA -------");
}

int main() {
    char opcao;

    // Inicialização da lista
    L.primeiro = 0;
    L.ultimo = 0;

    do {
        tela();

        gotoxy(35, 3);
        printf("===MENU===");

        gotoxy(35, 9);
        printf("1 - Inclusao");

        gotoxy(35, 11);
        printf("2 - Alteracao");

        gotoxy(35, 13);
        printf("3 - Exclusao");

        gotoxy(35, 15);
        printf("4 - Consulta");

        gotoxy(35, 17);
        printf("5 - Finalizar");

        gotoxy(2, 23);
        printf("Digite sua Opcao: ");

        scanf(" %c", &opcao);

        switch (opcao) {

            case '1':
                incluir(&L);
                getch();
                break;

            case '2':
                alteracao();
                getch();
                break;

            case '3':
                exclusao();
                getch();
                break;

            case '4':
                consulta();
                getch();
                break;

            case '5':
                tela();

                gotoxy(30, 12);
                printf("Programa finalizado!");

                getch();
                break;

            default:
                tela();

                gotoxy(30, 20);
                printf("Opcao invalida!");

                getch();
                break;
        }

    } while (opcao != '5');

    return 0;
}
