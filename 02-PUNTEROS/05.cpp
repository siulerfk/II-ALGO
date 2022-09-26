/* 
 * Ejemplo: Punteros a funciones con struct y conversion de tipos. 
 */
#include <iostream>
#include <cstring>

typedef struct{
    int y ;
    char name[10];
    size_t edad;
}persona_t;

int strcmp_names(const void *a, const void *b){
    char *aa = ((persona_t *)a)->name;
    char *bb = ((persona_t *)b)->name;
    return strcmp((const char *)aa, (const char *)bb);
}
int main() {
    persona_t juan = {11,"juan", 14};
    persona_t pedro = {11, "juan", 11};

    std::cout << strcmp_names(&juan, &pedro);
    return 0;
}
