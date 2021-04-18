#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUESTION_AMOUNT 10
#define STUDENT_AMOUNT 5

void generateAnswers(int amount, char answers[amount]);
void generateStudentAnswers(int amountOfStudents, int amountOfQuestions, char answers[amountOfStudents][amountOfQuestions]);
void calculateGrades(int amountOfStudents, int amountOfQuestions, char studentsAnswers[amountOfStudents][amountOfQuestions], char answers[amountOfQuestions], int grades[amountOfStudents]);
void printGrades(int amountOfStudents, int grades[amountOfStudents]);
void printAnswers(int amount, char answers[]);
void printStudentAnswers(int amountOfStudents, int amountOfQuestions, char answers[amountOfStudents][amountOfQuestions]);
char convertToChar(int number);

int main(void) {
    srand(time(NULL));
    char answers[QUESTION_AMOUNT];
    char studentsAnswers[STUDENT_AMOUNT][QUESTION_AMOUNT];
    int grades[STUDENT_AMOUNT];
    int numberOfQuestions = QUESTION_AMOUNT;
    int numberOfStudents = STUDENT_AMOUNT;

    generateAnswers(numberOfQuestions, answers);
    printf("Gabarito: \n");
    printAnswers(numberOfQuestions, answers);

    generateStudentAnswers(numberOfStudents, numberOfQuestions, studentsAnswers);
    printf("Respostas dos Alunos: \n");
    printStudentAnswers(numberOfStudents, numberOfQuestions, studentsAnswers);

    calculateGrades(numberOfStudents, numberOfQuestions, studentsAnswers, answers, grades);
    printf("Notas:\n");
    printGrades(numberOfStudents, grades);
    
    return 0;
}

void generateAnswers(int amount, char answers[]) {
    int i;

    for (i = 0; i < amount; i++) {
        answers[i] = convertToChar(rand() % 4);
    }
}

void generateStudentAnswers(int amountOfStudents, int amountOfQuestions, char answers[amountOfStudents][amountOfQuestions]) {
    int i;

    for (i = 0; i < amountOfStudents; i++) {
        generateAnswers(amountOfQuestions, answers[i]);
    }
}

void calculateGrades(int amountOfStudents, int amountOfQuestions, char studentsAnswers[amountOfStudents][amountOfQuestions], char answers[amountOfQuestions], int grades[amountOfStudents]) {
    int i, j;
    int currentGrade;

    for (i = 0; i < amountOfStudents; i++) {
        currentGrade = 0;
        for (j = 0; j < amountOfQuestions; j++) {
            if (studentsAnswers[i][j] == answers[j]) {
                currentGrade++;
            }
        }
        grades[i] = currentGrade;
    }
}

void printGrades(int amountOfStudents, int grades[amountOfStudents]) {
    int i;

    for (i = 0; i < amountOfStudents; i++) {
        printf("Aluno %d: %d\n", i+1, grades[i]);
    }
}

void printAnswers(int amount, char answers[]) {
    int i;

    for (i = 0; i < amount; i++) {
        printf("%c\t", answers[i]);
    }
    printf("\n");
}

void printStudentAnswers(int amountOfStudents, int amountOfQuestions, char answers[amountOfStudents][amountOfQuestions]) {
    int i;

    for (i = 0; i < amountOfStudents; i++) {
        printAnswers(amountOfQuestions, answers[i]);
    }
}

char convertToChar(int number) {
    char c;
    switch (number) {
        case 0:
            c = 'a';
            break;

        case 1:
            c = 'b';
            break;

        case 2:
            c = 'c';
            break;

        case 3:
            c = 'd';
            break;
            
        default:
            printf("Erro na geração da resposta!!!");
            c = 'e';
    }

    return c;
}
