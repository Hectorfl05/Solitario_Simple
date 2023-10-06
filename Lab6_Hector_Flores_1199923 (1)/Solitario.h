#pragma once
#include "Cartas.h"
#include <list>
#include <stack>

class Solitario
{

public:

	void CrearMazo(std::list<Cartas>& list);
	void Barajear(std::list<Cartas>& list, std::stack<Cartas>& pila);
	void BarajearMazo(std::stack<Cartas>& mazo);
	void MostrarUltima(std::stack<Cartas> &pila);

	std::stack<Cartas>& GrupoSelec(int n, std::stack<Cartas>& mazo,std::stack<Cartas>& g1, std::stack<Cartas>& g2, std::stack<Cartas>& g3, std::stack<Cartas>& g4, std::stack<Cartas>& g5, std::stack<Cartas>& g6, std::stack<Cartas>& g7);
	bool VerificarPos(int n, std::stack<Cartas> origen);
	bool ComprobarGrupo(int origen, int destino);
	bool ElegirCarta(int pos,int ori, int des, std::stack<Cartas> &mazo, std::stack<Cartas>& g1, std::stack<Cartas>& g2, std::stack<Cartas>& g3, std::stack<Cartas>& g4, std::stack<Cartas>& g5, std::stack<Cartas>& g6, std::stack<Cartas>& g7);
	
	
	void ImprimirCartas(std::stack <Cartas> mazo, std::stack<Cartas> g1, std::stack<Cartas> g2, std::stack<Cartas> g3, std::stack<Cartas> g4, std::stack<Cartas> g5, std::stack<Cartas> g6, std::stack<Cartas>  g7);
	int MaximoCartas(std::stack<Cartas> g1, std::stack<Cartas> g2, std::stack<Cartas> g3, std::stack<Cartas> g4, std::stack<Cartas> g5, std::stack<Cartas> g6, std::stack<Cartas>  g7);

	void ImprimirTablero(std::stack <Cartas> mazo, std::stack<Cartas> g1, std::stack<Cartas> g2, std::stack<Cartas> g3, std::stack<Cartas> g4, std::stack<Cartas> g5, std::stack<Cartas> g6, std::stack<Cartas>  g7);
	

	void Tablero(std::stack <Cartas>& mazo, std::stack<Cartas>& g1, std::stack<Cartas>& g2, std::stack<Cartas>& g3, std::stack<Cartas>& g4, std::stack<Cartas> &g5, std::stack<Cartas> &g6, std::stack<Cartas>  &g7);
	bool Ganador(std::stack<Cartas> g1, std::stack<Cartas> g2, std::stack<Cartas> g3, std::stack<Cartas> g4, std::stack<Cartas> g5, std::stack<Cartas> g6, std::stack<Cartas> g7);
	
};

