
#include <stdio.h>
#include <stdlib.h>
// utilisation des pointeurs 
int euclid_etendue(int a, int b, int *x, int *y) 
{
    // q represente le quotient
    // x1,x2, y1,y2 represente les variables tampons executes pour les permutations 
    int q ,r, x1, x2, y1, y2;

    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    x2 = 1;
    x1 = 0;
    y2 = 0;
    y1 = 1;

    while (b > 0) {
        q = a / b;
        r = a - q * b;
        // on met a jour les valeurs precedentes 
        *x = x2 - q * x1;
        *y = y2 - q * y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = *x;
        y2 = y1;
        y1 = *y;
    }

    *x = x2;
    *y = y2;

    return a;
}

int main() {
    int a, b, pgcd, x, y;

    printf("Entrez deux entiers a et b : ");
    scanf("%d %d", &a, &b);
// appel a la fonction euclid_etendu
    pgcd = euclid_etendue(a, b, &x, &y);

    printf("Le PGCD de %d et %d est : %d\n", a, b, pgcd);
    printf("Les coefficients x et y tels que ax + by = gcd(a, b) sont : x = %d, y = %d\n", x, y);

    return 0;
}
