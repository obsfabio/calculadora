// Modulo de Erro

#include "Erro.h"

namespace Erro
{

	std::string getError ( tipoErro erro )
	{
    
        switch ( erro )
        {
               	case VARIAVEL_NAO_EXISTENTE:               return ("Erro: Voce tentou utilizar uma variavel ainda nao declarada");
                                                           break;
                                                           
                case VARIAVEL_INVALIDA:                    return ("Erro: So e permitida a declaracao de variaveis como caracteres");
                                                           break;
                                                           
                case SEM_ATRIBUICAO:                       return ("Erro: E necessario realizar atribuicoes na calculadora");
                                                           break;
                                                           
                case SEM_EXPRESSAO:                        return ("Erro: E necessario atribuir alguma coisa a variavel");
                                                           break;
                                                           
                case EXPRESSAO_INVALIDA:                   return ("Erro: Esta expressao nao é valida, certifique-se de usar apenas numero, operadores, parenteses e caracteres na sua expressao");
                                                           break;
                                                           
                case PRIMEIRO_CARACTERE_INVALIDO:          return ("Erro: A expressao nao pode comecar com caraceteres de multiplicacao, soma ou ponto");
                                                           break;
                                                           
                case ULTIMO_CARACTERE_INVALIDO:            return ("Erro: A expressao nao pode terminar com um operador nem com ponto");
                                                           break;
                                                           
                case OPERADORES_JUNTOS:                    return ("Erro: Nao e permitido utilizar dois caracteres juntos, use o parenteses");
                                                           break;
                                                           
                case NUMERO_SEPARADORES:                   return ("Erro: O numero de parenteses esta errado");
                                                           break;
                                                           
                case USO_INADEQUADO_DO_SEPARADOR:          return ("Erro: O parenteses foi usado incoretamento verifique sua expressao");
                                                           break;
                                                           
                case AUSENCIA_OPERADOR:                    return ("Erro: As variaveis devem ser apenas caracteres, nao e permitido usar mais de uma nem um caractere junto com um numero");
                                                           break;
                                                           
                case USO_INADEQUADO_DO_PONTO:              return ("Erro: O ponto so deve ser usado para indicar valores decimais, deve estar sempre cercado por numeros");
                                                           break;
                                                           
                case DIVISAO_POR_ZERO:                     return ("Erro: Voce tentou dividir por zero");
                                                           break;
                                                           
                case SEPARADOR_SEM_CONTEUDO:               return ("Erro: Utilizacao dos parenteses sem conter uma expressao");
                                                           break;
                                                           
                default:                                   return ("Erro: Ocorreu um erro tratado, mas esquecido, desculpe.");
                                                           break;
               
               
               
               
               
        }        
    
    
    
                
    }

}
