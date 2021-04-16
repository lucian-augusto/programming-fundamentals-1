#include <stdio.h>

int main() {
  int amount, bills;
  int standardBills[] = {50, 20, 5, 1};
  int standardBillsLength = sizeof(standardBills) / sizeof(standardBills[0]);

  scanf("%d", &amount);

  bills = amount;
  
  printf("NOTAS:\n");
  for (int i = 0; i < standardBillsLength; i++) {
    printf("%d nota(s) de R$ %d.00\n", bills/standardBills[i], standardBills[i]);
    bills = bills % standardBills[i];
  }

  return 0;
}