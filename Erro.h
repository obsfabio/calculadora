// Modulo de Erro

#ifndef   _ERRO_H_
#define   _ERRO_H_  1

# include <iostream>
# include <string>


namespace Erro
{

	typedef enum 
	{
	// Erros da Memoria
	VARIAVEL_NAO_EXISTENTE,

	// Erros Gerenciador

	// Erros Validador
	VARIAVEL_INVALIDA,
	SEM_ATRIBUICAO,
	SEM_EXPRESSAO,				   // a:=;
	EXPRESSAO_INVALIDA,
	
	// Erros Conformador

    PRIMEIRO_CARACTERE_INVALIDO,   // a:=*
    ULTIMO_CARACTERE_INVALIDO,     // a:=3+
	OPERADORES_JUNTOS,			   // **
	NUMERO_SEPARADORES,			   // ((( )
	USO_INADEQUADO_DO_SEPARADOR,   // (*
    AUSENCIA_OPERADOR,             // ab a7
    USO_INADEQUADO_DO_PONTO,       // 2.3.4


	// Erros da Unidade_aritmetica
	DIVISAO_POR_ZERO,
	SEPARADOR_SEM_CONTEUDO,
	
	} tipoErro;	

	std::string getError ( tipoErro erro );
	

}


#endif
