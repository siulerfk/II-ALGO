#include "12-Mensajero.h"

unsigned int Mensajero::contarMensajesBloqueados(Lista<Mensaje*>* mensajesPendientes) {

    unsigned int bloqueados = 0;

    mensajesPendientes->iniciarCursor();

    while (mensajesPendientes->avanzarCursor()) {

        Mensaje* mensajeActual = mensajesPendientes->obtenerCursor();

        if (this->estaBloqueado(mensajeActual)) {

            bloqueados++;
        }
    }

    return bloqueados;
}

bool Mensajero::estaBloqueado(Mensaje* unMensaje) {

    bool mensajeEstaBloqueado = false;

    Cuenta* remitente = unMensaje->obtenerRemitente();
    Lista<Cuenta*>* destinatarios = unMensaje->obtenerDestinatarios();
    destinatarios->iniciarCursor();

    while (!mensajeEstaBloqueado && destinatarios->avanzarCursor()) {

        Cuenta* destinatario = destinatarios->obtenerCursor();

        mensajeEstaBloqueado = this->destinatarioBloqueaRemitente(destinatario, remitente);
    }

    return mensajeEstaBloqueado;
}

bool Mensajero::destinatarioBloqueaRemitente(Cuenta* destinatario, Cuenta* remitente) {

    bool bloqueaRemitente = false;

    Lista<Cuenta*>* cuentasBloqueadas = destinatario->obtenerRemitentesBloqueados();

    cuentasBloqueadas->iniciarCursor();
    while (!bloqueaRemitente && cuentasBloqueadas->avanzarCursor()) {

        Cuenta* cuentaBloqueada = cuentasBloqueadas->obtenerCursor();
        bloqueaRemitente = (cuentaBloqueada->obtenerNombre() == remitente->obtenerNombre());
    }

    return bloqueaRemitente;
}
