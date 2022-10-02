#include "12-Cuenta.h"

Cuenta::Cuenta(std::string nombre) {

    this->nombre = nombre;
    this->remitentesBloqueados = new Lista<Cuenta*>;
}

std::string Cuenta::obtenerNombre() {

    return this->nombre;
}

Lista<Cuenta*>* Cuenta::obtenerRemitentesBloqueados() {

    return this->remitentesBloqueados;
}

Cuenta::~Cuenta() {

    delete this->remitentesBloqueados;
}
