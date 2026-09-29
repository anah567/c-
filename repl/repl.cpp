// Para usar las funciones declaradas del REPL
#include "repl.h"

// Para crear y usar el lexer
#include "../lexer/lexer.h"

// Para trabajar con los tokens
#include "../token/token.h"

// Para entrada y salida por consola
#include <iostream>

// Para trabajar con cadenas de texto
#include <string>

// Para usar transform
#include <algorithm>

// Para convertir caracteres a minusculas
#include <cctype>

namespace repl {

    // Simbolo que aparece antes de cada entrada
    const std::string PROMPT = ">> ";

    // Inicia el REPL
    void start() {

        std::string line;

        while (true) {

            std::cout << PROMPT;

            // Lee lo que escribe el usuario
            if (!std::getline(std::cin, line)) {
                return;
            }

            // Copia la linea para revisar si quiere salir
            std::string cleanedLine = line;

            // Convierte a minusculas
            std::transform(
                cleanedLine.begin(),
                cleanedLine.end(),
                cleanedLine.begin(),
                [](unsigned char c) {
                    return std::tolower(c);
                }
            );

            // Cierra el REPL
            if (cleanedLine == "exit" || cleanedLine == "salir") {
                std::cout << "Hasta luego!" << std::endl;
                return;
            }

            // Crea el lexer con la linea ingresada
            lexer::Lexer l(line);

            // Obtiene e imprime los tokens
            for (
                token::Token tok = l.nextToken();
                tok.type != token::EOF_TOKEN;
                tok = l.nextToken()
            ) {
                std::cout
                    << "{Type: "
                    << tok.type
                    << ", Literal: "
                    << tok.literal
                    << "}"
                    << std::endl;
            }
        }
    }

}