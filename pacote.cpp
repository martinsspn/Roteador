#ifndef _PACOTE_
#define _PACOTE_

#include <iostream>

class Pacote{
	public:
		int fonte;
		int destino;
		int dado;
		Pacote(int entrada, int saida, int dado){
			fonte = entrada;
			destino = saida;
			this->dado = dado;
		}

		void imprimir(){
			std::cout << "Fonte: " << fonte << std::endl;
			std::cout << "Destino: " << destino << std::endl;
			std::cout << "Dado: " << dado << std::endl;
		}
};

#endif