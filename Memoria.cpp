// Modulo Memoria

#include "Memoria.h"


	struct celula                  
	{
		std::string 	identificador;
		double 		    valor;
	};

	std::list<celula> ram;                                                                 // Variavel Global do Modulo que armazena a lista de elementos da memoria
                                                                                           // Memoria Volatil

namespace Memoria
{

	void insere ( std::string nome, double dado) 
	{
         
		std::list<celula>::iterator 	it;
		bool 				            duplicate = false;
		celula 				            elemento;
		
		

		for (it = ram.begin(); (it != ram.end()) && (!duplicate); it++)                    // Procurando na lista pela variavel a ser inserida
		{
			if ( !(nome.compare(it->identificador) ) )                                     // Se verdadeiro a variavel ja existia
			{
				duplicate = true;
				it->valor = dado;
			}
		}
		
		if (!duplicate)                                                                    // Se a variavel nao existia cria-la e inseri-la na memoria
		{
			elemento.identificador = nome;
			elemento.valor = dado;
			ram.push_back (elemento);
		}
	}
			

	double busca ( std::string nome )
	{
		std::list<celula>::iterator it;

		for (it = ram.begin(); it != ram.end(); it++)                                       // Procurando na lista pela variavel 
		{
			if ( !(nome.compare(it->identificador) ) )                                      // Se verdadeiro achei
			{
				return (it->valor);                                                         // Retorna o valor da variavel 
			}
		}
		
		throw(Erro::VARIAVEL_NAO_EXISTENTE);                                                // Erro, buscando variavel inexistente
	}


    void exibirMemoria ( void )                                                             // Exibindo memoria
    {
        std::list<celula>::iterator it;

        std::cout << "\nValores armazenados na memoria:" << std::endl;

		for (it = ram.begin(); it != ram.end(); it++)
		{
			
			std::cout << "\t" << it->identificador << "\t" << it->valor << std::endl;
			
		}
    
        std::cout << std::endl; 
         
    }
       
}
