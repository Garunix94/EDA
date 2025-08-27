#ifndef FECHA_H
#define FECHA_H

typedef struct F *Fecha;

Fecha crearFecha();

void mostrarFecha(Fecha f);

int compararFecha(Fecha f1, Fecha f2); // 0 = igual, -1 = f1 < f2, 1 = f1 > f2

void destruirFecha(Fecha f);

#endif
