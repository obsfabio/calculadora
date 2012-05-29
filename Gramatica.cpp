// Modulo da Gramatica

#include "Gramatica.h"

namespace Gramatica 
{
	extern const std::string	atribuicao                            = 			":=";
	extern const std::string	fim_linha                             = 			";";
	extern const std::string	caracteres_validos_variaveis          = 	        "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	extern const std::string	caracteres_validos                    = 		    "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.";
    extern const std::string    numeros_validos                       =             "0123456789";
	extern const char		    multiplicacao                         =		        '*';
	extern const char		    divisao                               =			    '/';
	extern const char		    soma                                  =				'+';
	extern const char		    subtracao                             =			    '-';
	extern const char           charPoint                             =             '.';
	extern const std::string    point                                 =             ".";
    extern const std::string    operators                             =             "*/+-";
	extern const char		    abre_separador                        =		        '(';
	extern const char		    fecha_separador                       =		        ')';
    extern const std::string    separador_esquerda                    =             "(";
    extern const std::string    separador_direita                     =             ")";
    extern const std::string    invalidCharAfterOperator              =             "+-/*).";
    extern const std::string    invalidCharAfterVariable              =             "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789(.";
    extern const std::string    invalidCharAfterLeftParentheses       =             "/*).";
    extern const std::string    invalidCharAfterNumber                =             "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz(";
    extern const std::string    invalidCharAfterRightParentheses      =             "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789(.";
    extern const std::string    invalidCharAfterPoint                 =             "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz()+-/*.";
}
