#ifndef MENSAJE_H_
#define MENSAJE_H_

#include <string>
#include "12-Cuenta.h"
#include "09-Lista.h"

class Mensaje {

    private:

        Cuenta* remitente;

        std::string contenido;

        Lista<Cuenta*>* destinatarios;

    public:

        /* post: Mensaje con el contenido indicado y sin Destinatarios.
         */
        Mensaje(Cuenta* remitente, std::string contenido);

        /* post: devuelve el contenido del Mensaje.
         */
        std::string obtenerContenido();

        /* post: devuelve la Cuenta que env�a el Mensaje.
         */
        Cuenta* obtenerRemitente();

        /* post: devuelve todas las Cuentas a las que debe enviar el Mensaje.
         */
        Lista<Cuenta*>* obtenerDestinatarios();

        /* post: libera los recursos tomados.
         */
        ~Mensaje();
};

#endif /* MENSAJE_H_ */
