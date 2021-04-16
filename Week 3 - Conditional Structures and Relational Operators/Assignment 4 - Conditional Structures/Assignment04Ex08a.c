#include <stdio.h>
#include <time.h>

int main(void) {
  int birthDay, birthMonth, birthYear, age;
  time_t rawTime = time(NULL);
  struct tm currentDate = *localtime(&rawTime);

  int currentDay = currentDate.tm_mday;
  int currentMonth = currentDate.tm_mon + 1;
  int currentYear = currentDate.tm_year + 1900;
  
  printf("Por favor insira a sua data de nascimento (formato dd-MM-yyyy, com os hífens): ");
  scanf("%d-%d-%d", &birthDay, &birthMonth, &birthYear);

  age = currentYear - birthYear;
  if (birthMonth > currentMonth || (birthMonth == currentMonth && birthDay > currentDay)) {
    age -= 1;
  }
  printf("\nVocê nasceu no dia %02d-%02d-%04d, hoje é %02d-%02d-%04d, portanto, você tem: %d anos", birthDay, birthMonth, birthYear, currentDay, currentMonth, currentYear, age);
  return 0;
}