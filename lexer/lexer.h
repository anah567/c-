#ifndef LEXER_H
#define LEXER_H

// Para trabajar con cadenas de texto
#include <string>

// Para usar los tokens definidos en token.h
#include "../token/token.h"

namespace lexer {

    // Analizador lexico
    class Lexer {

    private:

        // Entrada que se va a analizar
        std::string input;

        // Posicion actual
        int position;

        // Siguiente posicion
        int readPosition;

        // Caracter actual
        char ch;

        // Avanza al siguiente caracter
        void readChar();

        // Mira el siguiente caracter sin avanzar
        char peekChar() const;

        // Ignora espacios y saltos de linea
        void skipWhitespace();

        // Lee identificadores
        std::string readIdentifier();

        // Lee numeros
        std::string readNumber();

        // Verifica si es una letra
        bool isLetter(char character) const;

        // Verifica si es un numero
        bool isDigit(char character) const;

        // Crea un token
        token::Token newToken(
            const token::TokenType& tokenType,
            char character
        ) const;

    public:

        // Inicializa el lexer
        explicit Lexer(const std::string& input);

        // Obtiene el siguiente token
        token::Token nextToken();
    };

}

#endif