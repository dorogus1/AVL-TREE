#ifndef ARBORIB_H
#define ARBORIB_H

typedef int TipCheie;

#define N 2
#define NN (2 * N)

typedef struct {
    TipCheie cheie;
    int contor;
    struct Pagina *p;
} Nod;

typedef struct Pagina {
    int m;
    Nod e[NN + 1];
    struct Pagina *p0;
} Pagina;

void initializare(Pagina **pag);
Pagina* insereaza(Pagina *pag, TipCheie x, Nod *nod);
void afisare_recursiva(Pagina *arbore, int nivel);
int cautare(Pagina *pag, TipCheie x, int *contor);
Pagina* suprima(Pagina *pag, TipCheie x, Nod *nod);
int mare_key(Pagina *pag);
int next_mare(Pagina *pag, int x);
int nr_key(Pagina *arbore);

#endif // ARBORIB_H
