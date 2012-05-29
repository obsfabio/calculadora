// Modulo Conformador

#include "Conformador.h"


using namespace std;


//
//Funcao doubleToString:
//       
//       Recebera o numero como double e retornara a string correspondente a conversao do double
//

  string doubleToString (double number)
  {
       ostringstream buffer;
       
       buffer << fixed << setprecision(12) << number;
 
       return buffer.str();
  }

//
//Funcao checkField:
//       
//       Dado um caractere (mychar), a funcao retornara 1 caso exista o mesmo
//       caractere em um conjunto de caracteres definidos pelo myset.
//       
//       Ex:        
//       mychar == 'c' ; myset == "abc" ; checkField retorna 1
//        
//       mychar == 'd' ; myset == "abc" ; checkField retorna 0       
// 


   unsigned checkField (string myset,char mychar)
   {
       unsigned counter;
  
       for (counter = 0; counter <= myset.length() - 1; counter++)
           if (myset[counter] == mychar)
              return 1;                                                         // PELO MENOS UMA OCORRENCIA DO CARACTERE 
  
       return 0;                                                                // NAO FOI ENCONTRADO 
  }





namespace Conformador
{



  void setString(string &entrada)
   {
     
     unsigned           contador;
     unsigned           numEsquerda;                                                      // contador para numero de '('
     unsigned           numDireita;                                                       // contador para numero de ')' 
     size_t             found;
     string             converted;                                                        // string que armazenara o valor convertido do double 
     string             auxiliar;
     double             number;  
     stringstream       conversor;

         
     // Verificando se o primeiro e o ultimo caracter são válidos
     // Nao se pode começar por * / ou .
     // Nao se pode terminar por */+- . 
     
     
     if ((entrada[0] == Gramatica::multiplicacao) || (entrada[0] == Gramatica::divisao) || (entrada[0] == Gramatica::charPoint))
      throw (Erro::PRIMEIRO_CARACTERE_INVALIDO);
     
     if ((entrada[entrada.length()-1] == Gramatica::charPoint) || (checkField(Gramatica::operators,entrada[entrada.length()-1]) == 1))
      throw (Erro::ULTIMO_CARACTERE_INVALIDO);
          

     // Testes do separador, tem que haver o mesmo numero de abre e fecha separadores
     // Nao se pode fechar antes de abrir     
          
     numDireita = 0;
     numEsquerda = 0;
     
     for(contador = 0; contador <= entrada.length() - 1;contador++)
     {
        if (entrada[contador] == Gramatica::abre_separador )
         numEsquerda++;
       
        if (entrada[contador] == Gramatica::fecha_separador )
         numDireita++;
                      
        if (numDireita > numEsquerda)
         throw (Erro::USO_INADEQUADO_DO_SEPARADOR);
     }
          
     if (numDireita != numEsquerda)
      throw (Erro::NUMERO_SEPARADORES);   
     
 
  
     
     // Trata situacoes como 2.2.3
     // procurando por numero cercado por pontos 
     
     if ( entrada.length () > 2 )
     {
         for(contador = 0; contador <= ( entrada.length() - 3) ;contador++)
             if( checkField(Gramatica::numeros_validos,entrada[contador+2]) == 1 )
                 if ((checkField(Gramatica::point,entrada[contador+1]) == 1) && (checkField(Gramatica::point,entrada[contador+3]) == 1))
                     throw ( Erro::USO_INADEQUADO_DO_PONTO );      
     }


     // Trata casos de erro na escrita da expressao
     // Seguindo as regras da gramatica
     
     if ( entrada.length () > 1 )
     {
     
       for (contador = 0; contador <= (entrada.length() - 2);contador++)
       {
       
           if ((entrada[contador] == Gramatica::abre_separador ) && (checkField("+-", entrada[contador+1])))
              entrada.insert(contador+1,"0"); // If necessario para consertar a sequencia (+ ou (- para (0+ ou (0- respectivamente 
       
           if ((checkField (Gramatica::operators,entrada[contador]) == 1) && (checkField (Gramatica::invalidCharAfterOperator,entrada[contador+1]) == 1))
              throw (Erro::OPERADORES_JUNTOS); // Entrar nesse if significa dois operadores juntos ou operador seguido por )
       
           if ((checkField (Gramatica::caracteres_validos_variaveis,entrada[contador]) == 1) && (checkField (Gramatica::invalidCharAfterVariable,entrada[contador+1]) == 1))
              throw (Erro::AUSENCIA_OPERADOR); // Entrar nesse if significa duas variaveis juntas ou uma variavel seguida por um numero. Ex: 5 + a5 + b
       
           if ((checkField (Gramatica::separador_esquerda,entrada[contador]) == 1) && (checkField (Gramatica::invalidCharAfterLeftParentheses,entrada[contador+1]) == 1))
              throw (Erro::USO_INADEQUADO_DO_SEPARADOR); // Entrar nesse if significa que ocorreu *)/. depois de um ( 
       
           if ((checkField (Gramatica::numeros_validos,entrada[contador]) == 1) && (checkField (Gramatica::invalidCharAfterNumber,entrada[contador+1]) == 1))
              throw (Erro::AUSENCIA_OPERADOR); // Entrar nesse if significa que foi usada uma variavel ou um ( logo apos um numero 
       
           if ((checkField (Gramatica::separador_direita,entrada[contador]) == 1) && (checkField (Gramatica::invalidCharAfterRightParentheses,entrada[contador+1]) == 1))
              throw (Erro::USO_INADEQUADO_DO_SEPARADOR); // Entrar nesse if significa que foi usado uma variavel ou numero ou ( logo apos o ) 
       
           if ((checkField (Gramatica::point,entrada[contador]) == 1) && (checkField (Gramatica::invalidCharAfterPoint,entrada[contador+1]) == 1))
              throw (Erro::USO_INADEQUADO_DO_PONTO); // Entrar nesse if significa que foi usado alguma coisa que nao seja numero apos o ponto 
        
        }

      }



                                                                                // Nesse ponto teremos uma expressao valida 


      found = entrada.find_first_of (Gramatica::caracteres_validos_variaveis);  // Ira procurar se existe alguma variavel na expressao 
     
      while (found != string::npos)                                             // So permacenera no while caso exista pelo menos uma variavel
      {                  

         auxiliar = entrada.substr (found, 1);
         
         number = Memoria::busca( auxiliar );                                   // A variavel a ser procurada estara sempre na posicao found
         converted = doubleToString(number);   

         if (number < 0)
           converted = "(0" + doubleToString(number)+")";            
         else converted = doubleToString(number);
         
         
         entrada.replace(found,1, converted);                                            
         found = entrada.find_first_of (Gramatica::caracteres_validos_variaveis,found + 1);    
         
      }
      
      if ((entrada[0] == Gramatica::soma) || (entrada[0] == Gramatica::subtracao))
         entrada.insert(0,"0"); 
          
   }
}
