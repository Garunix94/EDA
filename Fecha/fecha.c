#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

struct F {
    unsigned int d;
    unsigned int m;
    unsigned int y;
};

Fecha crearFecha(){
    Fecha nueva = malloc(sizeof(struct F));
    printf("Insert year: ");
    scanf("%d", &nueva->y);

    printf("Insert mounth: ");
    scanf("%d", &nueva->m);
    while (nueva->m > 12){
        printf("Wrong mounth, try again: ");
        scanf("%d", &nueva->m);
    }
    
    printf("Insert day: ");
    scanf("%d", &nueva->d);
    while (nueva->d > 31){
        printf("Wrong day, try again: ");
        scanf("%d", &nueva->d);
    }

    return nueva;

}

void mostrarFecha(Fecha f){
    printf("%d/%d/%d", f->d, f->m, f->y);
}

void destruirFecha(Fecha f){
    free(f);
}

int compararFecha(Fecha f1, Fecha f2){ // 0 = igual, -1 = f1 < f2, 1 = f1 > f2
    if (f1->y < f2->y){
        return -1;
    }else if (f1->y > f2->y){
        return 1;
    }else if (f1->y == f2->y && f1->m < f2->m){
        return -1;
    }else if (f1->y == f2->y && f1->m > f2->m){
        return 1;
    }else if (f1->y == f2->y && f1->m == f2->m && f1->d < f2->d){
        return -1;
    }else if (f1->y == f2->y && f1->m == f2->m && f1->d > f2->d){
        return 1;
    }else if (f1->y == f2->y && f1->m == f2->m && f1->d == f2->d){
        return 0;
    }
    
} 







