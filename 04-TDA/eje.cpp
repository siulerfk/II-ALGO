#include <iostream>

int main(){
    int *g = new int[4];

    for(int i = 0; i < 4; i++)
    g[i] = 0;

    delete[] g;
    return 0;
}
