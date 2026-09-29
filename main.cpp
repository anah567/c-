// Para mostrar mensajes en consola
#include <iostream>

// Para iniciar el REPL
#include "repl/repl.h"

int main() {

    std::cout << "********************************************\n";
    std::cout << "**                                        **\n";
    std::cout << "**      BIENVENIDO A DISNEY COMPILER      **\n";
    std::cout << "**                                        **\n";
    std::cout << "**       Donde la magia se convierte      **\n";
    std::cout << "**              en tokens!                **\n";
    std::cout << "**                                        **\n";
    std::cout << "********************************************\n\n";

    std::cout << "Escribe un comando para comenzar.\n";
    std::cout << "Escribe 'salir' para terminar.\n\n";

    // Inicia la consola
    repl::start();

    return 0;
}