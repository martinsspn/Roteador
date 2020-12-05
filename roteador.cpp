#include <iostream>
#include "controleDeFluxo.cpp"
#include "chaveamento.cpp"
#include "memoria.cpp"
#include "roteamento.cpp"
#include "arbitro.cpp"
#include "pacote.cpp"

using namespace std;

int main(){
	ControleDeFluxo * ctrlFluxoR1, *ctrlFluxoR2, *ctrlFluxoR3, *ctrlFluxoR4, *ctrlFluxoR5;
	Arbitro * arbitro1 = new Arbitro();
	Arbitro * arbitro2 = new Arbitro();
	Arbitro * arbitro3 = new Arbitro();
	Arbitro * arbitro4 = new Arbitro();
	Arbitro * arbitro5 = new Arbitro();
	Chaveamento * chaveamento1 = new Chaveamento(arbitro1);
	Chaveamento * chaveamento2 = new Chaveamento(arbitro2);
	Chaveamento * chaveamento3 = new Chaveamento(arbitro3);
	Chaveamento * chaveamento4 = new Chaveamento(arbitro4);
	Chaveamento * chaveamento5 = new Chaveamento(arbitro5); 
	Pacote * pacote = new Pacote(1, 3, 92);
	ctrlFluxoR1 = new ControleDeFluxo(chaveamento1, arbitro2, arbitro3, arbitro4, arbitro5);
	ctrlFluxoR2 = new ControleDeFluxo(chaveamento2, arbitro1, arbitro3, arbitro4, arbitro5);
	ctrlFluxoR3 = new ControleDeFluxo(chaveamento3, arbitro1, arbitro2, arbitro4, arbitro5);
	ctrlFluxoR4 = new ControleDeFluxo(chaveamento4, arbitro1, arbitro2, arbitro3, arbitro5);
	ctrlFluxoR5 = new ControleDeFluxo(chaveamento5, arbitro1, arbitro2, arbitro3, arbitro4);
	ctrlFluxoR1->setControles(ctrlFluxoR2, ctrlFluxoR3, ctrlFluxoR4, ctrlFluxoR5);
	ctrlFluxoR2->setControles(ctrlFluxoR1, ctrlFluxoR3, ctrlFluxoR4, ctrlFluxoR5);
	ctrlFluxoR3->setControles(ctrlFluxoR1, ctrlFluxoR2, ctrlFluxoR4, ctrlFluxoR5);
	ctrlFluxoR4->setControles(ctrlFluxoR1, ctrlFluxoR2, ctrlFluxoR3, ctrlFluxoR5);
	ctrlFluxoR5->setControles(ctrlFluxoR1, ctrlFluxoR2, ctrlFluxoR3, ctrlFluxoR4);
	ctrlFluxoR1->memoria->escreverMem(pacote);
	cout << "Roteador 1 envia requisição para o roteador 3" << endl;
	ctrlFluxoR1->enviarPacote(); //Roteador 1 manda valid
	//ctrlFluxoR2->enviarPacote();
	//ctrlFluxoR3->enviarPacote();
	//ctrlFluxoR4->enviarPacote();
	//ctrlFluxoR5->enviarPacote();
	//ctrlFluxoR1->receberPacote();
	//ctrlFluxoR2->receberPacote();
	//ctrlFluxoR3->receberPacote();
	//ctrlFluxoR4->receberPacote();
	ctrlFluxoR5->receberPacote(); //Roteador 2 responde ack
	ctrlFluxoR5->memoria->pacote->imprimir();
}