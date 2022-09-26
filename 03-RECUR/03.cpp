bool invertir_cadena(char *cadena){
	return invertir_cadena_rec(cadena, 0); 
}

bool invertir_cadena_rec(char *cadena, int acumulador){
	if(acumulador == strlen(cadena) / 2)
		return
	return invertir_cadena_rec(cadena, acumulador + 1);
}