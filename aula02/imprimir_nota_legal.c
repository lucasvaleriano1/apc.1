
#include <stdio.h>
int main(){
    printf("--------------------------------------\n");
    printf("               NOTA LEGAL             \n");
    printf("--------------------------------------\n");
    printf("Item             Qde     Prc     Valor\n");
    printf("%-16s %03i %8.2f %7.2f\n", "Caneta Azul", 2, 2.0, 4.0);
    printf("%-16s %03i %8.2f %7.2f\n", "Borracha", 1, 5.0, 5.0);
    printf("%-16s %03i %8.2f %7.2f\n", "Resma de papel", 1, 12.0, 12.0);
    printf("--------------------------------------\n");
    printf("TOTAL.......................: R$ %3.2f\n", 21.00);
    return 0;
}