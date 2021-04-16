#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void) {
  int birthDay, birthMonth, birthYear, age, dayOfTheWeek, flippedMonth, yearOfTheCentury, zeroBasedCentury;
  char dayOfTheWeekName[13];
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

  /* Invertendo os meses de Janeiro e Fevereiro para o final da lista (seguindo a 
  ordem necessária para a Congruência de Zeller) e, caso o mês em análise seja 
  Janeiro ou Fevereiro, é necessário considerar o ano anterior (a Congruência de 
  Zeller considera Fevereiro como último mês do ano, portanto se nãão reduzir o 
  ano para estes meses, vamos calcular o dia da semana do ano seguinte ao desejado)*/
  if (birthMonth < 3) {
    flippedMonth += birthMonth + 12; 
    yearOfTheCentury = (birthYear - 1) % 100;
    zeroBasedCentury = (birthYear - 1) / 100;
  } else {
    flippedMonth = birthMonth;
    yearOfTheCentury = birthYear % 100;
    zeroBasedCentury = birthYear / 100;
  }

  // Calculando o dia da semana utilizando a Congruência de Zeller
  dayOfTheWeek = (birthDay + ((13 * (flippedMonth + 1)) / 5) + yearOfTheCentury + (yearOfTheCentury / 4) + (zeroBasedCentury / 4) + (5 * zeroBasedCentury)) % 7;

  // Corrigindo o dia da semana para o formato ISO

  dayOfTheWeek = ((dayOfTheWeek + 5) % 7) + 1;

  // convertendo o dia da semana de número para string (vetor de char)
  switch (dayOfTheWeek) {
    case 1:
      strcpy(dayOfTheWeekName , "segunda-feira");
      break;
    
    case 2:
      strcpy(dayOfTheWeekName , "terça-feira");
      break;

    case 3:
      strcpy(dayOfTheWeekName , "quarta-feira");
      break;

    case 4:
      strcpy(dayOfTheWeekName , "quinta-feira");
      break;

    case 5:
      strcpy(dayOfTheWeekName , "sexta-feira");
      break;

    case 6:
      strcpy(dayOfTheWeekName , "sábado");
      break;

    case 7:
      strcpy(dayOfTheWeekName , "domingo");
      break;

    default:
      break;
  }

  printf("\nVocê nasceu no dia %02d-%02d-%04d, um(a) %s.\nHoje é %02d-%02d-%04d, portanto, você tem: %d anos", birthDay, birthMonth, birthYear, dayOfTheWeekName, currentDay, currentMonth, currentYear, age);
  return 0;
}