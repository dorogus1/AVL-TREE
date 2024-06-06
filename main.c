#include <stdio.h>
#include <stdlib.h>
#include "arborib.h"

Pagina *arbore = NULL;
void initializare_arbore() {
    initializare(&arbore);
}
void inserare_cheie(TipCheie x) {
    arbore = insereaza(arbore, x, NULL);
}

void suprimare_cheie(TipCheie x) {
    arbore = suprima(arbore, x, NULL);
}
int cautare_cheie(TipCheie x) {
    int contor = 0;
    int rezultat = cautare(arbore, x, &contor);
    printf("Numarul de comparatii efectuate: %d\n", contor);
    return rezultat;
}
void afisare_arbore() {
    printf("Afisare arbore:\n");
    afisare_recursiva(arbore, 0);
}
TipCheie cea_mai_mare_cheie() {
    return mare_key(arbore);
}
int numar_chei_arbore() {
    return nr_key(arbore);
}
TipCheie cheie_imediat_mai_mare(TipCheie x) {
    return next_mare(arbore, x);
}
int main() {
    int optiune;
    TipCheie cheie;

    do {
        printf("\nMeniu:\n");
        printf("1. Initializare arbore\n");
        printf("2. Inserare cheie\n");
        printf("3. Suprimare cheie\n");
        printf("4. Cautare cheie\n");
        printf("5. Afisare arbore\n");
        printf("6. Cea mai mare cheie\n");
        printf("7. Numarul de chei din arbore\n");
        printf("8. Cheia imediat mai mare valoric\n");
        printf("0. Iesire\n");
        printf("Alege optiune: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                initializare_arbore();
                printf("Arbore initializat.\n");
                break;
            case 2:
                printf("Introdu cheia de inserat: ");
                scanf("%d", &cheie);
                inserare_cheie(cheie);
                printf("Cheie inserata.\n");
                break;
            case 3:
                printf("Introdu cheia de sters: ");
                scanf("%d", &cheie);
                suprimare_cheie(cheie);
                printf("Cheie stearsa.\n");
                break;
            case 4:
                printf("Introdu cheia de cautat: ");
                scanf("%d", &cheie);
                if (cautare_cheie(cheie))
                    printf("Cheia exista in arbore.\n");
                else
                    printf("Cheia nu exista in arbore.\n");
                break;
            case 5:
                afisare_arbore();
                break;
            case 6:
                printf("Cea mai mare cheie: %d\n", cea_mai_mare_cheie());
                break;
            case 7:
                printf("Numarul de chei din arbore: %d\n", numar_chei_arbore());
                break;
            case 8:
                printf("Introdu cheia de referinta: ");
                scanf("%d", &cheie);
                printf("Cheia imediat mai mare valoric este: %d\n", cheie_imediat_mai_mare(cheie));
                break;
            case 0:
                printf("La revedere!\n");
                break;
            default:
                printf("Optiune invalida. Te rog sa alegi din nou.\n");
        }
    } while (optiune != 0);

    return 0;
}
