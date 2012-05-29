// Modulo Memoria

#ifndef _MEMORIA_H_
#define _MEMORIA_H_     1

#include <list>
#include "Erro.h"


namespace Memoria
{

	void insere ( std::string nome, double dado);
			

	double busca ( std::string nome );

    void exibirMemoria ( void );

}

#endif
