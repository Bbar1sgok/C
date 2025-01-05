#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    ocak = 1,
    subat,
    mart,
    nisan,
    mayis,
    haziran,
    temmuz,
    agustos,
    eylul,
    ekim,
    kasim,
    aralik


}aylar;

void ayiGoster(aylar ay)
{
    switch(ay)
    {
    case ocak:
        printf("Ocak");
        break;
    case subat:
        printf("Subat");
        break;
    case mart:
        printf("Mart");
        break;
    case nisan:
        printf("Nisan");
        break;
    case mayis:
        printf("Mayis");
        break;
    case haziran:
        printf("Haziran");
        break;
    case temmuz:
        printf("Temmuz");
        break;
    case agustos:
        printf("Agustos");
        break;
    case eylul:
        printf("Eylul");
        break;
    case ekim:
        printf("Ekim");
        break;
    case kasim:
        printf("Kasim");
        break;
    case aralik:
        printf("Aralik");
        break;
    default:
        printf("Boyle bir ay yok");
    }

}

int main()
{

    aylar ay = nisan;

    ayiGoster(ay);


    return 0;
}
