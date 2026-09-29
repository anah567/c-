#include "lexer.h"

namespace lexer {

    // Inicializa el lexer
    Lexer::Lexer(const std::string& input)
        : input(input), position(0), readPosition(0), ch(0) {
        readChar();
    }

    // Avanza al siguiente caracter
    void Lexer::readChar() {
        if (readPosition >= static_cast<int>(input.length())) {
            ch = '\0';
        } else {
            ch = input[readPosition];
        }

        position = readPosition;
        readPosition++;
    }

    // Mira el siguiente caracter sin avanzar
    char Lexer::peekChar() const {
        if (readPosition >= static_cast<int>(input.length())) {
            return '\0';
        }

        return input[readPosition];
    }

    // Ignora espacios y saltos de linea
    void Lexer::skipWhitespace() {
        while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            readChar();
        }
    }

    // Verifica si es una letra
    bool Lexer::isLetter(char character) const {
        return (character >= 'a' && character <= 'z') ||
               (character >= 'A' && character <= 'Z') ||
               character == '_';
    }

    // Lee un identificador completo
    std::string Lexer::readIdentifier() {
        int startPosition = position;

        while (isLetter(ch)) {
            readChar();
        }

        return input.substr(startPosition, position - startPosition);
    }

    // Verifica si es un numero
    bool Lexer::isDigit(char character) const {
        return character >= '0' && character <= '9';
    }

    // Lee un numero completo
    std::string Lexer::readNumber() {
        int startPosition = position;

        while (isDigit(ch)) {
            readChar();
        }

        return input.substr(startPosition, position - startPosition);
    }

    // Crea tokens de un solo caracter
    token::Token Lexer::newToken(
        const token::TokenType& tokenType,
        char character
    ) const {
        return {
            tokenType,
            std::string(1, character)
        };
    }

    // Obtiene el siguiente token
    token::Token Lexer::nextToken() {
        token::Token tok;

        skipWhitespace();

        switch (ch) {

            case '=':
                if (peekChar() == '=') {
                    char currentChar = ch;
                    readChar();

                    std::string literal;
                    literal += currentChar;
                    literal += ch;

                    tok = {token::EQ, literal};
                } else {
                    tok = newToken(token::ASSIGN, ch);
                }
                break;

            case '+':
                tok = newToken(token::PLUS, ch);
                break;

            case '-':
                tok = newToken(token::MINUS, ch);
                break;

            case '!':
                if (peekChar() == '=') {
                    char currentChar = ch;
                    readChar();

                    std::string literal;
                    literal += currentChar;
                    literal += ch;

                    tok = {token::NOT_EQ, literal};
                } else {
                    tok = newToken(token::BANG, ch);
                }
                break;

            case '/':
                tok = newToken(token::SLASH, ch);
                break;

            case '*':
                if (peekChar() == '*') {
                    char currentChar = ch;
                    readChar();

                    std::string literal;
                    literal += currentChar;
                    literal += ch;

                    tok = {token::POW, literal};
                } else {
                    tok = newToken(token::ASTERISK, ch);
                }
                break;

            case '<':
                if (peekChar() == '=') {
                    char currentChar = ch;
                    readChar();

                    std::string literal;
                    literal += currentChar;
                    literal += ch;

                    tok = {token::LTE, literal};
                } else {
                    tok = newToken(token::LT, ch);
                }
                break;

            case '>':
                if (peekChar() == '=') {
                    char currentChar = ch;
                    readChar();

                    std::string literal;
                    literal += currentChar;
                    literal += ch;

                    tok = {token::GTE, literal};
                } else {
                    tok = newToken(token::GT, ch);
                }
                break;

            // Delimitadores
            case ';':
                tok = newToken(token::SEMICOLON, ch);
                break;

            case ',':
                tok = newToken(token::COMMA, ch);
                break;

            case '{':
                tok = newToken(token::LBRACE, ch);
                break;

            case '}':
                tok = newToken(token::RBRACE, ch);
                break;

            case '(':
                tok = newToken(token::LPAREN, ch);
                break;

            case ')':
                tok = newToken(token::RPAREN, ch);
                break;

            case '[':
                tok = newToken(token::LBRACKET, ch);
                break;

            case ']':
                tok = newToken(token::RBRACKET, ch);
                break;

            // Fin de la entrada
            case '\0':
                tok = {token::EOF_TOKEN, ""};
                break;

            default:

                // Identificadores y palabras reservadas
                if (isLetter(ch)) {
                    std::string literal = readIdentifier();
                    token::TokenType type = token::lookupIdent(literal);

                    return {type, literal};
                }

                // Numeros
                if (isDigit(ch)) {
                    std::string literal = readNumber();

                    return {token::INT, literal};
                }

                tok = newToken(token::ILLEGAL, ch);
                break;
        }

        readChar();
        return tok;
    }

}