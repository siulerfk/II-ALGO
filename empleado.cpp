class Empleado{
    private:
        char *nombre;
        char *apellido;
        int id;
        float sueldo;
    public:
        Empleado(const char *, const char *, int, float);
        Empleado(const Empleado &);
};

Empleado::Empleado(const char *nombre_empl, const char *apellido_empl, int id_empl, float sueldo_empl){
	nombre = (char *)nombre_empl;
	apellido = (char *)apellido_empl;
	id = id_empl;
	sueldo = sueldo_empl;
}
Empleado::Empleado(const Empleado &trabajador){
	nombre = trabajador.nombre; 
	apellido =  trabajador.apellido; 
	id = trabajador.id; 
	sueldo = trabajador.sueldo; 
}
