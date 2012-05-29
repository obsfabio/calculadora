// Modulo Unidade Aritmetica

#include "Unidade_aritmetica.h"

// Para debug do código basta definir a macro comentada abaixo
//#define VERBOSE_MODE_ARITMETICO

	double	calcularTermo ( std::string &termo )
	{
		double			    elemento, retorno;
		size_t			    indice_multiplica;
		size_t			    indice_divide;
		std::stringstream	conversor;
		std::string		    auxiliar;

        #ifdef VERBOSE_MODE_ARITMETICO
               std::cout << "\n\t\tCalculo do Termo: " << termo << std::endl;
        #endif

		indice_multiplica = termo.find_last_of ( Gramatica::multiplicacao );                              // primeira aparição do caracetere de multiplicacao
		indice_divide = termo.find_last_of ( Gramatica::divisao );                                        // primeira aparição do caracetere de divisao   


		if ( (indice_multiplica == -1) && (indice_divide == -1 ) )                                        // Nenhum caractere (chegamos ao numero)
		{
             
            if ( termo [0] == '!' )                                                                       // O numero a seguir equivalia a um parentese negativo
            {
                termo.erase ( 0, 1);                                                                      // retira o ! para a conversao

                conversor << termo;
			    conversor >> elemento;

                #ifdef VERBOSE_MODE_ARITMETICO
                       std::cout << "\t\t\tResultado é o proprio termo - " << elemento << std::endl;
                #endif

			    return (-elemento);                                                                        // valor de retorna = - o valor apos !
                 
            }
       
                                                                                                           // converte o elemento diretamente
            conversor << termo;
		    conversor >> elemento;

            #ifdef VERBOSE_MODE_ARITMETICO
                   std::cout << "\t\t\tResultado é o proprio termo - " << elemento << std::endl;
            #endif

		    return elemento;
        
        }	

		if ( (indice_multiplica != -1) && ( (indice_multiplica > indice_divide) || (indice_divide == -1 ) ) )          // operação mais a direita é uma multiplicação
		{

            if ( termo [indice_multiplica + 1] != '!' )                                                   // trata o !
            {
			    auxiliar.assign ( termo, (indice_multiplica + 1), termo.length() );

			    conversor << auxiliar;
			    conversor >> elemento;

			    termo.erase ( indice_multiplica, (termo.length() - indice_multiplica) );

                #ifdef VERBOSE_MODE_ARITMETICO
                       std::cout << "\t\t\tResultado é a multiplicacao do termo - " << termo << " pelo elemento " << elemento << std::endl;
                #endif

			    return ( elemento * calcularTermo ( termo ) );                                              // retorna a multiplicacao do elemento a direita * resultado do resto da conta
                                                                                                            // associando pelo direita
            }	
           
                
            auxiliar.assign ( termo, (indice_multiplica + 2), termo.length() );

		    conversor << auxiliar;
		    conversor >> elemento;

		    termo.erase ( indice_multiplica, (termo.length() - indice_multiplica) );

            #ifdef VERBOSE_MODE_ARITMETICO
                   std::cout << "hehe\t\t\tResultado é a multiplicacao do termo - " << termo << " pelo elemento " << (-elemento) << std::endl;
            #endif
            
		    return ( (-elemento) * calcularTermo ( termo ) );                                                // retorna a multiplicacao do elemento a direita * resultado do resto da conta
                                                                                                             // associando pelo direita
               
            
            		
		}

        if ( termo [indice_divide + 1] == '!' )
        {
       	    auxiliar.assign ( termo, (indice_divide + 2), termo.length());

		    conversor << auxiliar;
		    conversor >> elemento;
      
		    termo.erase ( indice_divide , (termo.length() - indice_divide) );

            #ifdef VERBOSE_MODE_ARITMETICO
                   std::cout << "\t\t\tResultado é a divisao do termo - " << termo << " pelo elemento " << (-elemento) << std::endl;
            #endif

		    return ( calcularTermo ( termo ) / (-elemento) );	                                             // retorna a divisao resultado do resto da conta a esquerda / pelo elemento a direita
                                                                                                             // associando pelo direita
             
        }

		auxiliar.assign ( termo, (indice_divide + 1), termo.length());

		conversor << auxiliar;
		conversor >> elemento;

		termo.erase ( indice_divide , (termo.length() - indice_divide) );

        #ifdef VERBOSE_MODE_ARITMETICO
               std::cout << "\t\t\tResultado é a divisao do do termo - " << termo << " pelo elemento " << elemento << std::endl;
	    #endif	

		if ( elemento == 0 )
			throw ( Erro::DIVISAO_POR_ZERO );

		return ( calcularTermo ( termo ) / elemento );	
		
	}

	double	calcularExpressao ( std::string &expressao )
	{
		double			      elemento, retorno;
		size_t			      indice_soma;
		size_t			      indice_subtrai;
		std::stringstream	  conversor;
		std::string		      auxiliar, termo;

		indice_soma = expressao.find_last_of ( Gramatica::soma );                                                     // primeiro caractere de soma
		indice_subtrai = expressao.find_last_of ( Gramatica::subtracao );                                             // primeiro caractere de subtracao

        #ifdef VERBOSE_MODE_ARITMETICO
               std::cout << "\n\tCalcularExpressao: " << expressao << std::endl;
        #endif

		if ( (indice_soma == -1) && (indice_subtrai == -1 ) )                                                         // nao existe nem soma nem subtração, temos um termo
		{

            #ifdef VERBOSE_MODE_ARITMETICO
                   std::cout << "\t\tO retorno da uma função calcular Termo" << std::endl;
            #endif

			return ( calcularTermo ( expressao ));
		}	


		if ( (indice_soma != -1 ) && ( (indice_soma > indice_subtrai) || (indice_subtrai == -1 ) ) )                  // temos uma expressao + um termo
		{

			auxiliar.assign ( expressao, 0, (indice_soma) );
			termo.assign ( expressao, (indice_soma + 1), expressao.length() );

            #ifdef VERBOSE_MODE_ARITMETICO
                   std::cout << "\t\tSoma do calculo da expressao - " << auxiliar << " com o termo - " << termo << std::endl;
            #endif
	
			return ( calcularExpressao ( auxiliar ) + calcularTermo ( termo ) );			

		}

                                                                                                                      // temos uma expressao - um termo

		auxiliar.assign ( expressao, 0, (indice_subtrai) );
		termo.assign ( expressao, (indice_subtrai + 1), expressao.length() );

        #ifdef VERBOSE_MODE_ARITMETICO
               std::cout << "\t\tSubtracao do calculo da expressao - " << auxiliar << " com o termo - " << termo << std::endl;
        #endif

		return ( calcularExpressao ( auxiliar ) - calcularTermo ( termo ));


	}


namespace Unidade_aritmetica
{


	double calcular (std::string expressao)
	{

		int			indice_abre, indice_fecha, indice, posicao;
		unsigned		contador;
		double			elemento;
		std::string		auxiliar;
		std::stringstream	conversor;

		indice_abre = static_cast <int> ( expressao.find_first_of ( Gramatica::abre_separador ) );               // primeiro abre parenteses


        #ifdef VERBOSE_MODE_ARITMETICO
               std::cout << "\nCalcular: " << expressao << std::endl;
        #endif

		if ( indice_abre == -1 )                                                                                 // nao abre parenteses, como numero abre = numero fecha sem parenteses, temos uma expressao
		{

            #ifdef VERBOSE_MODE_ARITMETICO
                 std::cout << "\tRetorna na funcao calcularExpressao" << std::endl;
            #endif           

			return ( calcularExpressao (expressao) );                                                            
		}

		for ( contador = 1, posicao = indice_abre; contador != 0 ;  )                                            // for para localizar o fecha parenteses equivalente a primeiro abre parenteses
		{
			indice = static_cast <int> ( expressao.find_first_of ( Gramatica::abre_separador, (posicao + 1) ) );             // primeiro abre parenteses a partir da posicao		
			indice_fecha = static_cast <int> ( expressao.find_first_of ( Gramatica::fecha_separador, (posicao + 1) ) );      // primeiro fecha parenteses a partir da posicao
			
			if ( (indice < indice_fecha) && ( indice != -1) )                                                    // outro abre antes de um fecha é necessario acha o ignorar um fecha (contador++)  
			{			
				contador ++;
				posicao = indice;                                                                                // procurando a partir do fecha encontrado para nao achar o mesmo de novo   
			}
			else                                                                                                 // achei um fecha antes de um abre mais proximo do primeiro (contador--)
			{
				posicao = indice_fecha;
				contador --;                                                                                     // procurando a partir do abre encontrado para nao achar o mesmo de novo
			}
		}		

	
		if ( (indice_fecha - indice_abre - 1) < 1 )                                                              // ()
			throw (Erro::SEPARADOR_SEM_CONTEUDO);

                                                                                                                 // Substituindo os () por seu valor
                                                                                                                 
		auxiliar.assign ( expressao, indice_abre + 1, (indice_fecha - indice_abre - 1) );                        // auxiliar rebece a expressao (que pode conter parenteses) que estava entre parenteses

        #ifdef VERBOSE_MODE_ARITMETICO
               std::cout << "\tO resultado da expressao " << auxiliar;
        #endif
		
		elemento = calcular ( auxiliar );                                                                        // chama a si mesmo para calcular o valor de auxiliar


        #ifdef VERBOSE_MODE_ARITMETICO
               std::cout << "\t" << elemento << std::endl;
        #endif

        if ( elemento >= 0 )                                                                                     // substitui na expressao
        {
		   conversor << std::fixed << std::setprecision (12) << elemento;
		   conversor >> auxiliar;
		
		   expressao.erase (indice_abre, (indice_fecha - indice_abre + 1) );
		   expressao.insert ( indice_abre, auxiliar );
        }
        else                                                                                                     // substitui na expressao usando o ! pra indicar o numero era negativo
        {
           conversor << std::fixed << std::setprecision (12) << (-elemento);
		   conversor >> auxiliar;
		
           expressao.erase (indice_abre, (indice_fecha - indice_abre + 1) );
		   expressao.insert ( indice_abre, auxiliar );
           expressao.insert ( indice_abre, "!" );                               // Para evitar um erro inesperado que na substituicao de um () negativo fica operado-valor dois operadores juntos da erro
        
        }

		return ( calcular (expressao) );

	}


}
