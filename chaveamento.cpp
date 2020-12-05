#ifndef _CHAVEAR_
#define _CHAVEAR_

#include <iostream>
#include "arbitro.cpp"
#include "pacote.cpp"

class Chaveamento{
public:
	Pacote * pacote1;
	Pacote * pacote2;
	Pacote * pacote3;
	Pacote * pacote4;
	Arbitro * arbitro;

	Chaveamento(Arbitro * _arbitro){
		arbitro = _arbitro;
	}

	int setPacote(Pacote * pacote, int idx){
		switch(idx){
			case 0: pacote1 = pacote;
					return 1;
			case 1: pacote2 = pacote;
					return 1;
			case 2: pacote3 = pacote;
					return 1;
			case 3: pacote4 = pacote;
					return 1;
		}
		return 0;
	}

	Pacote * chavear(){
		int arbitrar = arbitro->arbitrar();
		std::cout << "chaveando para a posição " << arbitrar << std::endl;
		switch(arbitrar){
			case 0: return pacote1;
			case 1: return pacote2;
			case 2: return pacote3;
			case 3: return pacote4;
		}
		return NULL;
	}
};

#endif