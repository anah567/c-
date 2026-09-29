// Para usar las definiciones de Token y TokenType
#include "token.h"

// Para guardar las palabras reservadas
#include <unordered_map>

namespace token {

    // Tokens especiales
    const TokenType ILLEGAL = "ILLEGAL";
    const TokenType EOF_TOKEN = "EOF";


    // Identificadores y literales
    const TokenType IDENT = "IDENT";
    const TokenType INT = "INT";


    // Operadores
    const TokenType ASSIGN   = "=";
    const TokenType PLUS     = "+";
    const TokenType MINUS    = "-";
    const TokenType BANG     = "!";
    const TokenType ASTERISK = "*";
    const TokenType SLASH    = "/";

    const TokenType LT  = "<";
    const TokenType GT  = ">";
    const TokenType LTE = "<=";
    const TokenType GTE = ">=";

    const TokenType EQ     = "==";
    const TokenType NOT_EQ = "!=";
    const TokenType POW    = "**";


    // Delimitadores
    const TokenType COMMA     = ",";
    const TokenType SEMICOLON = ";";

    const TokenType LPAREN   = "(";
    const TokenType RPAREN   = ")";
    const TokenType LBRACE   = "{";
    const TokenType RBRACE   = "}";
    const TokenType LBRACKET = "[";
    const TokenType RBRACKET = "]";


    // Palabras reservadas
    const TokenType FUNCTION    = "FUNCTION";
    const TokenType LET         = "LET";
    const TokenType TRUE_TOKEN  = "TRUE";
    const TokenType FALSE_TOKEN = "FALSE";
    const TokenType IF          = "IF";
    const TokenType ELSE        = "ELSE";
    const TokenType ELIF        = "ELIF";
    const TokenType RETURN      = "RETURN";
    const TokenType FOR         = "FOR";
    const TokenType WHILE       = "WHILE";
    const TokenType BREAK       = "BREAK";


    // Personajes usados como palabras reservadas
    const std::unordered_map<std::string, TokenType> keywords = {
        {"mickey", FUNCTION},
        {"minnie", LET},
        {"simba", TRUE_TOKEN},
        {"scar", FALSE_TOKEN},
        {"elsa", IF},
        {"anna", ELSE},
        {"olaf", ELIF},
        {"nemo", RETURN},
        {"woody", FOR},
        {"buzz", WHILE},
        {"stitch", BREAK}
    };


    // Busca si la palabra es reservada
    TokenType lookupIdent(const std::string& ident) {

        auto it = keywords.find(ident);

        // Si existe, retorna su token
        if (it != keywords.end()) {
            return it->second;
        }

        // Si no existe, es un identificador
        return IDENT;
    }

}