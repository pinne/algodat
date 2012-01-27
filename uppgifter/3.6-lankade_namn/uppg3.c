#include <stdio.h>
#include <conio.h>
#include "list.h"

void skrivut(person *start){
  printf("UTSKRIFTEN\n");
}

void main(void){
  person *start;
  start=laesin();
  skrivut(start);
  tabort(start);
  getch();
}