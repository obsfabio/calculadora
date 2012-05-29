// Modulo da Gramatica

#include <string>


namespace Gramatica 
{

	extern const std::string	atribuicao;                                       //      ":="
	extern const std::string	fim_linha;                                        // 	  ";"

// caracteres validos para as variaveis da calculadora
	extern const std::string	caracteres_validos_variaveis;                     // 	  "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
	extern const std::string	caracteres_validos;                               // 	  "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789."
    extern const std::string    numeros_validos;                                  //      "0123456789"

// operadores validos
	extern const char		    multiplicacao;                                    //	   '*'
	extern const char		    divisao;                                          //      '/'
	extern const char		    soma;                                             //      '+'
	extern const char		    subtracao;                                        //      '-'
	
	extern const char           charPoint;                                        //      '.'
	extern const std::string    point;                                            //      "."

    extern const std::string    operators;                                        //      "*/+-"


// separadores
	extern const char		    abre_separador;                                   //      '('
	extern const char		    fecha_separador;                                  //      ')'

    extern const std::string    separador_esquerda;                               //      "("
    extern const std::string    separador_direita;                                //      ")"



// Regras da Gramática consideradas:

     // Verificando se o primeiro e o ultimo caracter são válidos
     // Nao se pode começar por * / ou .
     // Nao se pode terminar por */+- . 
     
     // Testes do separador, tem que haver o mesmo numero de abre e fecha separadores
     // Nao se pode fechar antes de abrir 


     // Nao pode haver numero com dois pontos 2.3.4
     
     // Nao pode haver dois operadores juntos
     
     // Variaveis so podem ser caracteres, 
     // portanto nao pode haver dois caracteres juntos
     // nao pode haver numero juntos a caracteres


// String para analise das regras

    extern const std::string      invalidCharAfterOperator;                //        "+-/*)."
    extern const std::string      invalidCharAfterVariable;                //        "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789(."
    extern const std::string      invalidCharAfterLeftParentheses;         //        "/*)."
    extern const std::string      invalidCharAfterNumber;                  //        "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz("
    extern const std::string      invalidCharAfterRightParentheses;        //        "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789(."
    extern const std::string      invalidCharAfterPoint;                   //        "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz()+-/*."



}
