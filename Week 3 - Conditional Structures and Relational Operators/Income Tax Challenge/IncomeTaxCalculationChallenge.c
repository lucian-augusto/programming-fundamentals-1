#include <stdio.h>

double calculateIncomeTax(int income, double incomeThresholds[], int thresholdsArraySize) {
  double aliquot[] = {0, 0.075, 0.15, 0.225, 0.275};
  int aliquotLength = sizeof(aliquot) / sizeof(aliquot[0]);
  
  double totalTaxAmount = 0;
  double effectiveIncomeForCalc = 0;
  int i;

for (i = 1; i < thresholdsArraySize; i++) {
    if (income <= incomeThresholds[i]) {
      effectiveIncomeForCalc = income - incomeThresholds[i-1];
    } else {
      effectiveIncomeForCalc = incomeThresholds[i] - incomeThresholds[i-1];
    }
    totalTaxAmount += effectiveIncomeForCalc * aliquot[i-1];
  }
  if (income > incomeThresholds[thresholdsArraySize-1]) {
    totalTaxAmount += (income - incomeThresholds[thresholdsArraySize-1]) * aliquot[aliquotLength-1];
  }
  return totalTaxAmount;
}

int main(void) {
  double income;
  int month;
  double totalTaxAmount = 0;
  
  double incomeThresholds1[] = {0, 1499.15, 2246.75, 2995.70, 3743.19};
  int incomeThresholds1Length = sizeof(incomeThresholds1) / sizeof(incomeThresholds1[0]);
  double incomeThresholds2[] = {0, 1566.61, 2347.85, 3130.51, 3911.63};
  int incomeThresholds2Length = sizeof(incomeThresholds2) / sizeof(incomeThresholds2[0]);

  printf("Por favor insira o seu salário: ");
  scanf("%lf", &income);

  printf("Por favor insira o mêês que deseja calcular o imposto de renda: ");
  scanf("%d", &month);

  if (month > 3) {
    totalTaxAmount = calculateIncomeTax(income, incomeThresholds2, incomeThresholds2Length);
  } else {
    totalTaxAmount = calculateIncomeTax(income, incomeThresholds1, incomeThresholds1Length);
  }
  
  printf("%.2lf", totalTaxAmount);
  return 0;
}