#ifndef _ROTEAMENTO_
#define _ROTEAMENTO_

#include <iostream>
#include "arbitro.cpp"
#include "pacote.cpp"
#include "memoria.cpp"

class Roteamento{
	public:
		Arbitro * arbitro1, *arbitro2, *arbitro3, *arbitro4;
		Memoria * memoria;
		Pacote * pacote;

		Roteamento(Arbitro * _arbitro1, Arbitro * _arbitro2, Arbitro * _arbitro3, Arbitro * _arbitro4, Memoria * _memoria){
			arbitro1 = _arbitro1;
			arbitro2 = _arbitro2;
			arbitro3 = _arbitro3;
			arbitro4 = _arbitro4;
			memoria = _memoria;
		}

		void enviarRequisicao(Pacote * pacote){
			switch(pacote->destino){
				case 0: arbitro1->receberRequisicao(0);
						std::cout << "enviando requisição para saida 0" << std::endl;
						break;
				case 1: arbitro2->receberRequisicao(1);
						std::cout << "enviando requisição para saida 1" << std::endl;
						break;
				case 2: arbitro3->receberRequisicao(2);
						std::cout << "enviando requisição para saida 2" << std::endl;
						break;
				case 3: arbitro4->receberRequisicao(3);
						std::cout << "enviando requisição para saida 3" << std::endl;
						break; 
			}
		}

		int rotear(){
			std::cout << "roteando" << std::endl;
			pacote = memoria->lerMem();
			enviarRequisicao(pacote);
			return pacote->destino;
		}
};

#endif