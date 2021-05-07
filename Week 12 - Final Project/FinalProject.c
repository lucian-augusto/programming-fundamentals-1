/* =============================================================================
 * Libraries
 * ========================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// Add compatibility with Linux, MacOS and Windows
#if defined(__APPLE__) || defined(__linux__)
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
#endif

/* =============================================================================
 * Macro Definitions
 * ========================================================================== */

#define ORG 'X'
#define VAZ '.'
#define TAM 101
#define BUFFER 2048
#define BOARD_SIZE_MIN 5
#define BOARD_SIZE_MAX 50
#define LIFE_CYCLE_MIN 10
#define LIFE_CYCLE_MAX 100
#define CUSTOM_INIT_FILE_PATH "./customInit.csv"
#define SPLASH_SCREEN_FILE_PATH "./SplashScreen.txt"

/* =============================================================================
 * Struct Declarations
 * ========================================================================== */

typedef struct {
    char gameName[TAM];
    int numberLines, numberColumns;
    char **board;
    int numberLifeCycles;
} Game;

/* =============================================================================
 * Syscall Functions/Utilities (Compatible with Linux, MacOS and Windows)
 * ========================================================================== */

void callSleep(int timeInMs) {
#if defined(__APPLE__) || defined(__linux__)
    usleep(timeInMs * 1000);
#elif _WIN32
    Sleep(timeInMs);
#endif
}

void clearScreen() {
#if defined(__APPLE__) || defined(__linux__)
    system("clear");
#elif _WIN32
    system("cls");
#endif
}

/* =============================================================================
 * Memory Utilities
 * ========================================================================== */

int checkMemoryAllocation(char **a, int numberLines) {
    int i;
    
    if (a == NULL) {
        return 0;
    }

    for (i = 0; i < numberLines; i++) {
        if (a == NULL) {
            return 0;
        }
    }
    return 1;
}

char **alocaMatriz(int nL, int nC) {
    char **m;
    int i;
    int err = 0;

    m = (char**) malloc(nL * sizeof(char*));
        
    for (i = 0; i < nL; i++) {
        m[i] = (char*) malloc(nC * sizeof(char*));

    }

    if (!checkMemoryAllocation(m, nL)) {
        printf("Erro ao alocar matriz");
    }
    
    return m;
}

void desalocaMatriz(char **m, int nL) {
    int i;

    for (i = 0; i < nL; i++) {
        free(m[i]);
    }
    free(m);
}

/* =============================================================================
 * Matrix Utilities
 * ========================================================================== */

void copiaMatriz(char **copy, char **original, int nL, int nC) {
    int i, j;

    for (i = 0; i < nL; i++) {
        for (j = 0; j < nC; j++) {
            copy[i][j] = original[i][j];
        }
    }
}

void imprimeMatriz(char **m, int nL, int nC) {
    int i, j;

    for (i = 0; i < nL; i++) {
        for (j = 0; j < nC; j++) {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}

/* =============================================================================
 * Board Initialization Functions
 * ========================================================================== */

void limpaMatriz(char **m, int nL, int nC) {
    int i,j;
    for(i=0;i<nL;i++)
        for(j=0;j<nC;j++)
            m[i][j]=VAZ;
}

void inicBlinker(char **m, int nL, int nC) {
    char padrao[1][3]={{ORG,ORG,ORG}};
    int i,j, xInic=nL/2, yInic=nC/2;

    limpaMatriz(m,nL,nC);

    for(i=0;i<1;i++)
        for(j=0;j<3;j++)
            m[xInic+i][yInic+j]=padrao[i][j];
}

void inicBloco(char **m, int nL, int nC) {
    char padrao[2][2]={{ORG,ORG},{ORG,ORG}};
    int i,j,xInic=nL/2, yInic=nC/2;


    limpaMatriz(m,nL,nC);


    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            m[xInic+i][yInic+j]=padrao[i][j];
}

void inicSapo(char **m, int nL, int nC) {
    char padrao[2][4]={{VAZ,ORG,ORG,ORG},{ORG,ORG,ORG,VAZ}};
    int i,j,xInic=nL/2, yInic=nC/2;

    limpaMatriz(m,nL,nC);


   for(i=0;i<2;i++)
      for(j=0;j<4;j++)
          m[xInic+i][yInic+j]=padrao[i][j];

}

void inicGlider(char **m, int nL, int nC) {
    char padrao[3][3]={{ORG,ORG,ORG},{ORG,VAZ,VAZ},{VAZ,ORG,VAZ}};
    int i,j,xInic,yInic;

    limpaMatriz(m,nL,nC);

    xInic=nL-4;
    yInic=nC-4;

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            m[xInic+i][yInic+j]=padrao[i][j];
}

void inicLWSS(char **m, int nL, int nC) {
    char padrao[4][5]={{VAZ,ORG,VAZ,VAZ,ORG},{ORG,VAZ,VAZ,VAZ,VAZ},{ORG,VAZ,VAZ,VAZ,ORG},{ORG,ORG,ORG,ORG,VAZ}};
    int i,j,xInic,yInic;

    limpaMatriz(m,nL,nC);

    xInic=nL-5;
    yInic=nC-6;

    for(i=0;i<4;i++)
        for(j=0;j<5;j++)
            m[xInic+i][yInic+j]=padrao[i][j];

}

/* =============================================================================
 * Game Mechanics Functions
 * ========================================================================== */

int countAliveCellsAround(char **board, int currentLine, int currentColumn, int numberLines, int numberColumns) {
    int aliveCellCount = 0;
    int initialSweepY, finalSweepY;
    int initialSweepX, finalSweepX;
    int i, j;

    initialSweepY = currentLine == 0 ? currentLine : currentLine - 1;
    finalSweepY = currentLine == numberLines - 1 ? currentLine : currentLine + 1;

    initialSweepX = currentColumn == 0 ? currentColumn : currentColumn - 1;
    finalSweepX = currentColumn == numberColumns - 1 ? currentColumn : currentColumn + 1;

    for (i = initialSweepY; i <= finalSweepY; i++) {
        for (j = initialSweepX; j <= finalSweepX; j++) {
            if ((i != currentLine || j != currentColumn) && (board[i][j] == ORG)) {
                aliveCellCount++;
            }
        }
    }

    return aliveCellCount;
}

char evaluateCell(char **board, int currentLine, int currentColumn, int numberLines, int numberColumns) {
    char newStatus = VAZ;
    int aliveCellsAmount;

    aliveCellsAmount = countAliveCellsAround(board, currentLine, currentColumn, numberLines, numberColumns);

    if (aliveCellsAmount == 3) {
        newStatus = ORG;
    }
    if (aliveCellsAmount == 2) {
        newStatus = board[currentLine][currentColumn];
    }

    return newStatus;
}

void createNextGenerationBoard(char **nextGenBoard, char **currentGenBoard, int numberLines, int numberColumns) {
    int i, j;

    for (i = 0; i < numberLines; i++) {
        for (j = 0; j < numberColumns; j++) {
            nextGenBoard[i][j] = evaluateCell(currentGenBoard, i, j, numberLines, numberColumns);
        }
    }
}

void jogaJogoVida(char **m, int nL, int nC, int generationAmount) {
    char **aux;
    int i;

    aux = alocaMatriz(nL,nC); // matriz que devera ser usada para atualizar cada jogada

    ////laco de repeticao para jogar TOTAL DE CICLOS

    for (i = 0; i < generationAmount; i++) {
        createNextGenerationBoard(aux, m, nL, nC);
        copiaMatriz(m,aux,nL,nC);
        clearScreen();
        imprimeMatriz(aux,nL,nC);
        callSleep(500);

    }

    ////fim do laco de repeticao para jogar TOTAL DE CICLOS

    desalocaMatriz(aux,nL);

}

/* =============================================================================
 * Game Initialization Functions
 * ========================================================================== */

void menuInicJogo(char **mat, int nL, int nC) {
    int opcao;

    printf("(1)Bloco\n(2)Blinker\n(3)Sapo\n(4)Glider\n(5)LWSS\nEntre com a opcao: ");
    scanf("%d",&opcao);
    switch(opcao) {
        case 1:   inicBloco(mat,nL,nC); break;
        case 2:   inicBlinker(mat,nL,nC); break;
        case 3:   inicSapo(mat,nL,nC); break;
        case 4:   inicGlider(mat,nL,nC); break;
        case 5:   inicLWSS(mat,nL,nC); break;
    }

    imprimeMatriz(mat,nL,nC);

    printf("Se inicializacao correta digite qualquer tecla para iniciar o jogo...");
    while(getchar()!='\n');
    getchar();

}

int shouldKeepOptions() {
    char keepOptions;

    printf("Deseja manter as mesmas opções (nome, dimensões do tabuleiro e número de ciclos)? (s/n): ");
    scanf(" %c", &keepOptions);

    keepOptions = tolower(keepOptions);
    
    while (keepOptions != 's' && keepOptions != 'n') {
        printf("Opção inválida! Deseja manter as mesmas opções? (s/n): ");
        scanf(" %c", &keepOptions);
    }

    getchar();

    if (keepOptions == 's') {
        return 1;
    }
    return 0;
}

int replayGame(int *keepOptions) {
    char option;
    printf("Deseja jogar novamente? (s/n): ");
    scanf(" %c", &option);

    option = tolower(option);
    
    while (option != 's' && option != 'n') {
        printf("Opção inválida! Deseja jogar novamente? (s/n): ");
        scanf(" %c", &option);
    }

    getchar();

    if (option == 's') {
        *keepOptions = shouldKeepOptions();
        return 1;
    }
    return 0;
}

int captureBoardParam(char *paramName, int min, int max) {
    int param;

    printf("Insira o %s: ", paramName);
    scanf("%d", &param);

    while (param < min || param > max) {
        printf("Entrada inválida! O %s deve estar entre %d e %d. Tente novamente: ", paramName, min, max);
        scanf("%d", &param);
    }

    return param;
}


void captureGameOptions(Game *g) {
    printf("Insira o seu nome: ");
    fgets(g->gameName, TAM, stdin);
    g->gameName[strcspn(g->gameName, "\n")] = 0;

    g->numberLines = captureBoardParam("número de linhas", BOARD_SIZE_MIN, BOARD_SIZE_MAX);

    g->numberColumns = captureBoardParam("número de colunas", BOARD_SIZE_MIN, BOARD_SIZE_MAX);

    g->numberLifeCycles = captureBoardParam("número de ciclos de vida", LIFE_CYCLE_MIN, LIFE_CYCLE_MAX);
}

void playGame(Game *g) {
        menuInicJogo(g->board, g->numberLines, g->numberColumns);

        jogaJogoVida(g->board, g->numberLines, g->numberColumns,
                     g->numberLifeCycles);
    
}

void newGame(Game *g, int isReplay) {
    if (isReplay) {
        desalocaMatriz(g->board, g->numberLines);
    }

    captureGameOptions(g);

    g->board = alocaMatriz(g->numberLines, g->numberColumns);

    playGame(g);    
}

void callSplashScreen() {
    FILE *f;
    char str[BUFFER];

    f = fopen(SPLASH_SCREEN_FILE_PATH, "r");

    if (f != NULL) {
        while (fgets(str, BUFFER, f) != NULL) {
            printf("%s", str);
        }

        fclose(f);
        
    } else {
        printf("*** JOGO DA VIDA ***");
    }

    
    printf("\n\n\nPressione ENTER para começar...");
    while (getchar() != '\n');
    getchar();
}

int main() {
    Game game;
    int replay = 0;
    int keepOptions = 0;

    callSplashScreen();

    do {

        if (!keepOptions) {
            newGame(&game, replay);
        } else {
            playGame(&game);
        }
        
        replay = replayGame(&keepOptions);

    } while (replay);
    
    desalocaMatriz(game.board, game.numberLines);

}
