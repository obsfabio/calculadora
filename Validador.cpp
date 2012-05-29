// Modulo Validador

#include "Validador.h"



using namespace std;


namespace Validador
{

  string nome;    
      
  void setString(string &linha)
  {

    stringstream        conversor;
    string              caracteres_conta;   
    string              exp;
    size_t              indice;
    
    //concatena todos os caracteres validos para a conta obtidos na gramatica    
    conversor << Gramatica::caracteres_validos << Gramatica::multiplicacao << Gramatica::divisao <<Gramatica::soma
    <<Gramatica::subtracao<<Gramatica::charPoint<<Gramatica::abre_separador << Gramatica::fecha_separador << Gramatica::atribuicao;                                                   
    
    conversor >> caracteres_conta;   


     // Apaga todos os caracteres spacos da linha
    for ( indice = 0; indice < linha.length() ; indice++)
    {
      if ( linha[indice] == ' ' )
        {
                linha.erase ( indice , 1 );
                indice--;
        }
    }
    


    indice = linha.find(Gramatica::atribuicao);

	if ( indice == string::npos )                                                                         // confere se o operador de atribuição existe
    {                                         
        throw ( Erro::SEM_ATRIBUICAO );                    
	}

    
    nome    =   linha.substr( 0, indice );                                                                // Separa o nome (antes da atribuição)
    exp     =   linha.substr( indice + 2 , linha.length());                                               // Da expressao (depois da atribuição)
    
    
		
    if ( exp.length()==0 )                                                                                // Testa se existe uma expressao atribuida à variável
    {                                               
        throw ( Erro::SEM_EXPRESSAO );                     
	}
		
	else if ( nome.length()!=1  ||  Gramatica::caracteres_validos_variaveis.find(nome)==-1 )              // Valida o nome da variavel nova
    {                                                                                       	
            throw Erro::VARIAVEL_INVALIDA;  
    }

	for (int i=0;i<exp.length();i++)
    {                                                                                                     //Testa há caracteres inválidos na conta(expressao);	
	    if (caracteres_conta.find(exp[i])==-1)
        {                                        
				throw Erro::EXPRESSAO_INVALIDA;             
		}         
	}
    
    linha=exp;                                                                                            //Altera a string de referencia;
    
    
}    




  std::string getName ()
  {
  
    return( nome );           
    
  }


}
