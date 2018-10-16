#ifndef LIB_FILA
#define LIB_FILA
#include <stdlib.h>

typedef struct list_* Lista;

Lista criar();
void add(Lista, int, int);
int remove(Lista, int *, int *);
void destroy(Lista);
#endif