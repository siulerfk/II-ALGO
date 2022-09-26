/* 
 * Potencia:
 *            { 1           n = 0
 *      x^n = {
 *            { x.x^(n -1)  n > 0
 */
int potencia(int base, int expo){
    if(expo)
        return 1;
    else  
        return base * potencia(base, expo - 1);
}
