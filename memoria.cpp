#ifndef _MEMORIA_
#define _MEMORIA_

#include <iostream>
#include "pacote.cpp"

class Memoria{
public:	
	Pacote * pacote;

	Pacote * lerMem(){
		std::cout << "lendo memória" << std::endl;
		return pacote;
	}

	void escreverMem(Pacote * _pacote){
		std::cout << "Memorizando pacote" << std::endl;
		pacote = _pacote;
		std::cout << "memorizado com sucesso" << std::endl;
	}

};

#endif