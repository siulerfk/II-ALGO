/* 
 * Este un ejemplo de como usar el puntero void
 */
#include <iostream>

typedef struct{
    char name[10];
    size_t edad;
}persona_t;

int main() {
    void *ptr;
    int a = 5;
    persona_t juan = {"juan", 12};

    ptr = &juan;

    ((persona_t *)ptr)->edad = 8; 
    std::cout << ((persona_t *)ptr)->name;
    return 0;
}
