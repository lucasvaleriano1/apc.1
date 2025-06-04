#include <stdio.h>

int main()
{
    int total = 0.0f;
    float nota_fiscal[5][3];

    for (int i = 0; i < 5; i++)
    {
        scanf("%i", &nota_fiscal[i][0]);
        scanf("%i", &nota_fiscal[i][1]);
        nota_fiscal[i][2] = nota_fiscal[i][0] * nota_fiscal[i][1];
        total = total + nota_fiscal[i][2];
    }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 3; j++){

            }
        }
    
    return 0;
}