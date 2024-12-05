#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
        Bir üçgenin açılarını girdi olarak alan ve bu üçgenin
        eşitkenar, çeşitkenar, dik üçgen olup olmadığını belirleyen bir c programı yazınız.
        Açıların üçgen oluşturup oluşturmadığı da kontrol edilmelidir.
    */

    float aci1, aci2, aci3, toplamAci;

    // Kullanıcıdan üçgenin iç açılarını alıyoruz
    printf("Lutfen ucgenin ic acilarini giriniz (aci1 aci2 aci3):\n");
    scanf("%f %f %f", &aci1, &aci2, &aci3);


    toplamAci = aci1 + aci2 + aci3;

    // Üçgenin açıları geçerli mi diye kontrol ediyoruz
    if (toplamAci == 180.00) {

        // Üçgenin türünü belirliyoruz
        if (aci1 == aci2 && aci2 == aci3) {
            printf("Girdiginiz acilara gore ucgeniniz bir eskenar ucgeni temsil etmektedir.\n");
        }
        else if (aci1 != aci2 && aci2 != aci3 && aci1 != aci3) {
            printf("Girdiginiz acilara gore ucgeniniz bir cesitkenar ucgeni temsil etmektedir.\n");
        }
        else if (aci1 == 90 || aci2 == 90 || aci3 == 90) {
            printf("Girdiginiz acilara gore ucgeniniz bir dik ucgeni temsil etmektedir.\n");
        }
    }
    else {
        printf("Bir ucgenin ic acilari toplami 180 derece olmalidir.\n");
    }

    return 0;
}
