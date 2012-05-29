// Programa principal

#include "Gerenciador.h"
#include "Memoria.h"
#include "Erro.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
    
    const int SUCESSO = 0;
    string expressao;                                                           /* Define a string que sera passado para os outros modulos*/
 
    cout << "\n\n\t\tCalculadora\n\n\tPara sair digite 'quit'\n\tPara mostrar o valor de todas as variaveis digite 'all'\n\tPara ajuda digite 'help'\n\t\n\tOu digite sua expressao\n\n" << endl;
    cout << ">>> ";
    
    getline(cin,expressao);                                                      
    
    
    while (expressao != "quit")                                                 // Define um metodo de parada 
    {                                                                           
    
          try
          {                                                                     
 
 
              if       ( expressao == "all")                                    // tratamento dos casos com if else por ser string
                  Memoria::exibirMemoria ();
                  
              else if  ( expressao == "help")
              {
                  cout << "\n\nUma expressao valida se baseia na atribuicao de uma expressao a uma variavel" << endl;
                  cout << "\tExemplo: \"a:=1+2*3\"" << endl;
                  cout << "Pode-se fazer varias atribuicoes em sequencia usando ; como separador" << endl;
                  cout << "\tExemplo: \"a:=2;b:=3;c:=a+b;\"\n" << endl;
              }
              else if ( expressao == "" );                                      // Para que o simples enter nao seja tratado como expressao
                        
              else if  ( expressao != "quit" )
                  cout << Gerenciador::setString( expressao ) << endl;                        
              




          }
    
          catch ( Erro::tipoErro erro ) 
          {                             
              cout << Erro::getError(erro) << endl ;                            // a funcao getError retorna o texto referente a cada tipo de erro 
          }
          catch (...)
          {
              cout << "Desculpe Ocorreu um erro inesperado, tente novamente" << endl;
          }
          
          cout << ">>> ";                                                       /* Caso nao ocorra erro e quit seja digitado, o programa continua executando*/
    
          getline(cin,expressao);
    }
    
    return (SUCESSO);
}
