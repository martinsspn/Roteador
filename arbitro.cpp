#ifndef _ARBITRO_
#define _ARBITRO_

#include <iostream>

class Arbitro{
public:
	int escolha;
	int req[4];
	Arbitro(){
		escolha = 0;
		for(int i=0;i<4;i++){
			req[i] = 0;
		}
	}

	void receberRequisicao(int entrada){
		std::cout << "recebendo requisição "<< entrada <<std::endl;
		switch(entrada){
			case 0: req[0] = 1;
					break;
			case 1: req[1] = 1;
					break;
			case 2: req[2] = 1;
					break;
			case 3: req[3] = 1;
					break;
		}
	}

	int arbitrar(){
		std::cout << "arbitrando" << std::endl;
		for(int j=0;j<10;j++){
			std::cout << "posição " << escolha << " prioridade " << req[escolha] << std::endl; 
			if(req[escolha] == 1){
				req[escolha] = 0;
				return escolha;	
			}
			escolha++;
			if(escolha > 3){
				escolha = 0;
			}
		}
		return -1;
	}
};

#endif