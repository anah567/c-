#ifndef TOKEN_H
#define TOKEN_H

// Para trabajar con cadenas de texto
#include <string>

namespace token {

    // Tipo que se usara para representar los tokens
    using TokenType = std::string;

    // Guarda el tipo del token y su valor
    struct Token {
        TokenType type;
        std::string literal;
    };


    // Tokens especiales
    extern const TokenType ILLEGAL;
    extern const TokenType EOF_TOKEN;


    // Identificadores y literales
    extern const TokenType IDENT;
    extern const TokenType INT;


    // Operadores
    extern const TokenType ASSIGN;      // =
    extern const TokenType PLUS;        // +
    extern const TokenType MINUS;       // -
    extern const TokenType BANG;        // !
    extern const TokenType ASTERISK;    // *
    extern const TokenType SLASH;       // /

    extern const TokenType LT;          // <
    extern const TokenType GT;          // >
    extern const TokenType LTE;         // <=
    extern const TokenType GTE;         // >=

    extern const TokenType EQ;          // ==
    extern const TokenType NOT_EQ;      // !=
    extern const TokenType POW;         // **


    // Delimitadores
    extern const TokenType COMMA;       // ,
    extern const TokenType SEMICOLON;   // ;

    extern const TokenType LPAREN;      // (
    extern const TokenType RPAREN;      // )
    extern const TokenType LBRACE;      // {
    extern const TokenType RBRACE;      // }
    extern const TokenType LBRACKET;    // [
    extern const TokenType RBRACKET;    // ]


    // Palabras reservadas
    extern const TokenType FUNCTION;
    extern const TokenType LET;
    extern const TokenType TRUE_TOKEN;
    extern const TokenType FALSE_TOKEN;
    extern const TokenType IF;
    extern const TokenType ELSE;
    extern const TokenType ELIF;
    extern const TokenType RETURN;
    extern const TokenType FOR;
    extern const TokenType WHILE;
    extern const TokenType BREAK;


    // Revisa si una palabra es reservada
    TokenType lookupIdent(const std::string& ident);

}

#endif