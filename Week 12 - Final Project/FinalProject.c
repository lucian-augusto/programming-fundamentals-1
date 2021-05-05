#include <stdio.h>
#include <stdlib.h>
#if defined(__APPLE__) || defined(__linux__)
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
#endif

#define ORG 'X'
#define VAZ '.'
#define TAM 101

/* ==========================================================================================
 * Syscall Functions/Utilities
 * ======================================================================================== */

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

/* ==========================================================================================
 * Board Initialization Functions
 * ======================================================================================== */

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

/* ==========================================================================================
 * Matrix Utilities
 * ======================================================================================== */

char **alocaMatriz(int nL, int nC) {
    char **m;
    int i;

    m = (char**) malloc(nL * sizeof(char*));

    for (i = 0; i < nL; i++) {
        m[i] = (char*) malloc(nC * sizeof(char*));
    }
    // Add Error verification

    return m;
}

void copiaMatriz(char **copy, char **original, int nL, int nC) {
    int i, j;

    for (i = 0; i < nL; i++) {
        for (j = 0; j < nC; j++) {
            copy[i][j] = original[i][j];
        }
    }
}

void desalocaMatriz(char **m, int nL) {
    int i;

    for (i = 0; i < nL; i++) {
        free(m[i]);
    }
    free(m);
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

/* ==========================================================================================
 * Game Mechanics Functions
 * ======================================================================================== */

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

void createNextGenerationBoard(char **nextGenBoard,char **currentGenBoard,  int numberLines, int numberColumns) {
    int i, j;

    for (i = 0; i < numberLines; i++) {
        for (j = 0; j < numberColumns; j++) {
            nextGenBoard[i][j] = evaluateCell(currentGenBoard, i, j, numberLines, numberColumns);
        }
    }
}

void jogaJogoVida(char **m, int nL, int nC, int generationAmount) {
    char **aux;
    int viz,k;
    int i,j;

    aux = alocaMatriz(nL,nC); //matriz que devera ser usada para atualizar cada jogada

    ////laco de repeticao para jogar TOTAL DE CICLOS

    for (i = 0; i < generationAmount; i++) {
        createNextGenerationBoard(aux, m, nL, nC);
        copiaMatriz(m,aux,nL,nC); //implemente uma funcao que copia uma matriz em outra
        clearScreen();
        imprimeMatriz(aux,nL,nC);
        callSleep(500);

    }

    ////fim do laco de repeticao para jogar TOTAL DE CICLOS

    desalocaMatriz(aux,nL);

}

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


int main() {


    char **mat;

    int nL=20,nC=20; //ou fornecido pelo usuario
    int generationAmount = 15;


    mat = alocaMatriz(nL,nC);

    menuInicJogo(mat,nL,nC);

    jogaJogoVida(mat,nL,nC, generationAmount); //defina o numero de ciclos que o jogo vai rodar (def. pelo usuario ou constante)

    desalocaMatriz(mat,nL);


}
