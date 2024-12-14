#include <stdio.h>
#include <stdlib.h>

// İkinin katı mı diye kontrol ediyoruz

int ikininKatiMi(int sayi){

    if(sayi % 2 == 0){

        return 1;
    }
    else{

        return 0;
    }

}

// Üçün katı mı diye kontrol ediyoruz

int ucunKatiMi(int sayi){

    if(sayi % 3 == 0){

        return 1;
    }
    else{

        return 0;
    }

}



int main()
{
    int girilenSayi;

    printf("Lutfen bir tam sayi giriniz:\n");
    scanf("%d", &girilenSayi);

    if(ikininKatiMi(girilenSayi) == 1){

        printf("Sayimiz cift sayidir.\n");
    }
    
    if(ucunKatiMi(girilenSayi) == 1){

        printf("Sayimiz 3 ile tam  bolunur.\n");
    }
    
    if(ikininKatiMi(girilenSayi) == 1 && ucunKatiMi(girilenSayi) == 1){

        printf("Sayimiz 6 ile tam bolunur.");
    }
    
    return 0;
}
