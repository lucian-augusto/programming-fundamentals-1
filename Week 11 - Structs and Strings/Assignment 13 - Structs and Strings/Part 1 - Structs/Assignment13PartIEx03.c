#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define APPLIANCES_AMOUNT 15

typedef struct {
    int code;
    int storePhone;
    float price;
} Appliance;

void * allocateArray(int totalSize);
float calculateAveragePrice(Appliance *a, int amount);
Appliance * createApplianceArray(int size);
void fillApplianceInfo(Appliance *a);
int generateRandomNumber(int min, int max);
int isBellowAveragePrice(int avgPrice, int price);


int main(void) {
    srand(time(NULL));
    Appliance *applianceList;
    float avgPrice;
    int i;

    applianceList = createApplianceArray(APPLIANCES_AMOUNT);

    avgPrice = calculateAveragePrice(applianceList, APPLIANCES_AMOUNT);

    printf("O preço médio do eletrodoméstico é: R$%.2f\n", avgPrice);

    printf("Os telefones das lojas cujo preço do eletrodoméstico está abaixo da média são:\n");
    for (i = 0; i < APPLIANCES_AMOUNT; i++) {
        if (isBellowAveragePrice(avgPrice, applianceList[i].price)) {
            printf("%d\n", applianceList[i].storePhone);
        }
    }

    free(applianceList);

    return 0;
}

void * allocateArray(int totalSize) {
    void *a;

    a = malloc(totalSize);

    if (a == NULL) {
        printf("Erro ao alocar memória.");
    }

    return a;
}

float calculateAveragePrice(Appliance *a, int amount) {
    float totalPrice = 0;
    int i;

    for (i = 0; i < amount; i++) {
        totalPrice += a[i].price;
    }

    return totalPrice / amount;
}

Appliance * createApplianceArray(int size) {
    Appliance *a;
    int i;

    a = (Appliance*) allocateArray(size * sizeof(Appliance));

    for (i = 0; i < size; i++) {
        fillApplianceInfo(&a[i]);
    }

    return a;
}

void fillApplianceInfo(Appliance *a) {
    a->code = generateRandomNumber(1, 999);
    a->storePhone = (generateRandomNumber(100, INT_MAX / 1000)) + 30000000; // Generates a "random phone number" that always starts with 3 (Brazilian
                                                                            // Standard for comercial phone numbers) not accouting for area and country codes.
    a->price = (((float)rand()/(float)(RAND_MAX)) * 2000) + 500;
}

int generateRandomNumber(int min, int max) {
    return (rand() % (max - min)) + min;
}

int isBellowAveragePrice(int avgPrice, int price) {
    if (price < avgPrice) {
        return 1;
    }
    return 0;
}
