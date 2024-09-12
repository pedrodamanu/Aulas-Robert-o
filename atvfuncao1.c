#include <stdio.h>
#include <math.h>

void menu();
float hip(int cat1, int cat2);
void res(int res);
int main ()
{
    float cat1, cat2, hip;
    menu();
    scanf("%f%f", &cat1, &cat2);
    hip = hip(cat1, cat2);
    res(hip);
}
void menu()
{
    printf("Digite os valores dos dois catetos: ");
}
float hip (int cat1, int cat2)
{
    int hip;
    hip = (pow(cat1, 2)) + (pow(cat2, 2));
    hip = sqrt(hip);
    return hip;
}
void res(int res)
{
    printf("%f\n", res);
}