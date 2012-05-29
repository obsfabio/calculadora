// Modulo Gerenciador

#include "Gerenciador.h"


using namespace std;

// Para debug do código basta definir a macro comentada abaixo
// #define DEBUG_MODE_GERENCIADOR     1


namespace Gerenciador
{ 
                                                                    
         

  std::string setString(string entrada)
  {                                                 
     std::string          saida;   
     string               linha = entrada; 
     string               conta;    
     string               nome;
     int                  quebra_linha;
     ostringstream        conversor; 
     bool                 fim = false;
     
     #ifdef DEBUG_MODE_GERENCIADOR
              cout << "Entrada do Gerenciador: " << entrada << endl;   
     #endif
     
     while  ( !fim  ) 
     {
            
            quebra_linha   =   linha.find(Gramatica::fim_linha);                                    // procura pela quebra de linha definida na gramatica
         
             if ( quebra_linha==string::npos )
             {                                         
                    conta = linha;
                    fim = true;       
             }
             else
             if ( quebra_linha == (linha.length() - 1) )                                            // testa se havera outras atribuições caso nao fim = true
             {
                  conta        =   linha.substr( 0, (quebra_linha) );
                  fim = true;
             }
             else
             {   
                    conta        =   linha.substr( 0, (quebra_linha) );                     
                    linha        =   linha.substr( quebra_linha+1, linha.length()-1 );      
             }
	         
             #ifdef DEBUG_MODE_GERENCIADOR
                    cout << "Antes do Validador: " << conta << endl;   
             #endif 
              
		     Validador::setString(conta);                                          

             #ifdef DEBUG_MODE_GERENCIADOR
                    cout << "Depois do Validador: " << endl << "Expressao " << conta << endl;
             #endif

             nome = Validador::getName ();                                       
             		     
             #ifdef DEBUG_MODE_GERENCIADOR
                    cout << "Variavel " << nome << endl;
             #endif
             
             Conformador::setString(conta);                                        

             #ifdef DEBUG_MODE_GERENCIADOR
                    cout << "Apos Conformador: " << conta << endl;
             #endif
		     
             double resultado   =   Unidade_aritmetica::calcular(conta);            
                                                                                   

                                                                                   
             #ifdef DEBUG_MODE_GERENCIADOR
                    cout << "Resultado: " << resultado << endl;
             #endif
              
             Memoria::insere(nome,resultado);                                      
             
   
             conversor << nome << " = "  << fixed << setprecision (8) << resultado << endl;                 // constroi a string que sera printada: [nome da variavel] = [valor]
             
             saida = conversor.str();                                                                       
             

             #ifdef DEBUG_MODE_GERENCIADOR
                    cout << "Conversor: " <<conversor << endl;
                    cout << "Valor da Saida: " << saida << endl;
             #endif
             
	}

    return (saida);

  }
  
}
