#include "pch.h"
#include "Solitario.h"
#include <random>
#include <iostream>
#include <iomanip>

using namespace std;


void Solitario::CrearMazo(std::list<Cartas> &deck)
{
	int cantN = 0;
	int cantR = 0;

	// Se realiza la iteración proceso dos veces, una vez para cartas negras (N) y otra vez para cartas rojas (R)
	do
	{
		// Se itera a través de los números del 1 al 13
		for (int i = 1; i < 14; i++)
		{
			Cartas NuevaN;

			// Se asigna el número e indica que es una carta negra (N)
			NuevaN.Numero = i;
			NuevaN.Color = "N";

			// Se agrega la carta al mazo
			deck.push_back(NuevaN);
		}

		cantN++;

	} while (cantN < 2); // Se itera el proceso hasta que se hayan creado dos juegos completos de cartas negras, 26 cartas (N) de 1 al 13

	do
	{
		for (int i = 1; i < 14; i++)
		{
			Cartas NuevaR;

			// Se asigna el número e indica que es una carta roja (R)
			NuevaR.Numero = i;
			NuevaR.Color = "R";

			// Se agrega la carta al mazo
			deck.push_back(NuevaR);
		}

		cantR++;

	} while (cantR < 2); // Se itera el proceso hasta que se hayan creado dos juegos completos de cartas rojas, 26 cartas (R) de 1 al 13
}


void Solitario::Barajear(std::list<Cartas> &list, std::stack<Cartas> &pila)
{
	//Se inicializa el generador de números aleatorios
	random_device rd;
	mt19937 g(rd());

	//Se crea un vector 'Baraja' a partir de la lista
	vector<Cartas>Baraja(list.begin(), list.end());

	//Se barajean las cartas del vector
	shuffle(Baraja.begin(), Baraja.end(), g);

	//Se actualiza la lista con el nuevo orden de las cartas
	list.assign(Baraja.begin(), Baraja.end());

	//Se mueven las cartas barajeadas de la lista a una pila "Mazo"
	while (!list.empty())
	{
		pila.push(list.front());
		list.pop_front();
	}
}


void Solitario::BarajearMazo(stack<Cartas>& mazo)
{
	// Se inicializa el generador de números aleatorios
	random_device rd;
	mt19937 g(rd());

	//Se crea una lista temporal llamada "Mazolist" y un vector "Baraja"
	list<Cartas> Mazolist;
	vector<Cartas>Baraja;

	//Se mueven las cartas del mazo a la lista temporal y las vuelve no visibles
	while (!mazo.empty())
	{
		mazo.top().visible = false;
		Baraja.push_back(mazo.top());
		mazo.pop();
	}

	// Se barajan las cartas en el vector "Baraja"
	shuffle(Baraja.begin(), Baraja.end(), g);

	// Se transfieren las cartas barajadas de "Baraja" de vuelta al mazo
	while (!Baraja.empty())
	{
		mazo.push(Baraja.back());
		Baraja.pop_back();
	}
	// Se hace la carta superior del mazo visible
	mazo.top().visible = true;
}


void Solitario::MostrarUltima(std::stack<Cartas> &pila)
{
	//Vuelve visible la carta que está en la primera posición de la pila
	pila.top().visible = true;
}


stack<Cartas>& Solitario::GrupoSelec(int n,stack<Cartas> &mazo, stack<Cartas> &g1, stack<Cartas> &g2, stack<Cartas> &g3, stack<Cartas> &g4, stack<Cartas> &g5, stack<Cartas> &g6, stack<Cartas> &g7)
{
	// Esta función toma un entero n y un conjunto de pilas de cartas.
	// Dependiendo del valor de n, retorna la pila de cartas correspondiente.

	switch (n)
	{
	case 0:
		return mazo;
		break;
	case 1:
		return g1;
		break;
	case 2:
		return g2;
		break;
	case 3:
		return g3;
		break;
	case 4:
		return g4;
		break;
	case 5:
		return g5;
		break;
	case 6:
		return g6;
		break;
	case 7:
		return g7;
		break;
	}
}


bool Solitario::VerificarPos(int pos, stack<Cartas> origen)
{

	int tamano = 0; // Inicializa la variable tamano que almacenará la cantidad de cartas visibles en la pila.

	// Recorre la pila origen.

	while (!origen.empty())
	{
		if (origen.top().visible == true)
		{
			tamano++; // Si la carta es visible, incrementa tamano.
		}

		origen.pop(); // Saca la carta                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  de la pila.
	}

	

	// Comprueba si la posición pos es válida en relación al número de cartas visibles en 'origen'.
	if (pos > 0 && pos <= tamano)
	{
		return true; // Si "pos" está en el rango de cartas visibles, retorna verdadero (true).
	}
	else
	{
		return false;// Si "pos" está fuera del rango de cartas visibles, retorna falso (false).
	}
}



bool Solitario::ComprobarGrupo(int origen, int destino)
{
	//Verifica si los valores de origen y destino son válidos
	// Ambos deben estar en el rango de 0 a 7 y no pueden ser iguales.
	if(origen >= 0  && origen < 8 && destino > 0 && destino < 8 && origen != destino)
	{
		return true; // Si las condiciones se cumplen, retorna true
	}else
	{
		return false;
	}
}












void Solitario::ImprimirTablero(stack <Cartas> mazo, stack<Cartas> g1, stack<Cartas> g2, stack<Cartas> g3, stack<Cartas> g4, stack<Cartas> g5, stack<Cartas> g6, stack<Cartas> g7)
{
	//Inicializacion de Stacks temporales para el libre uso dentro de la funcion
	stack<Cartas> MazoTemp = mazo;
	stack<Cartas> grupos[] = { g1,g2,g3,g4,g5,g6,g7 };
	stack<Cartas> Invertido;

	//Imprimir el Mazo
	cout << "MAZO:" << MazoTemp.top().Numero << MazoTemp.top().Color;
	cout << endl;

	for(int j = 7; j > 0; j--)
	{
		cout << "G" << j << "\t";
	}
	cout << endl;

	int MaxCartas = 0;
	for(int k = 0; k < 7; k++)
	{
		if(grupos[k].size() > MaxCartas)
		{
			MaxCartas = grupos[k].size();
		}
	}


	
	//Imprimir las cartas
	for(int i = 0; i < MaxCartas; i++)
	{
		for (int l = 0; l < 7; l++)
		{
			if(!grupos[l].empty())
			{
				if (grupos[l].top().visible == true)
				{
					cout << grupos[l].top().Numero << grupos[l].top().Color << "\t";

				}
				grupos[l].pop();

			}else
			{
				cout << "\t";
			}
		}
		cout << endl;
	}
	

}

int Solitario::MaximoCartas(std::stack<Cartas> g1, std::stack<Cartas> g2, std::stack<Cartas> g3, std::stack<Cartas> g4, std::stack<Cartas> g5, std::stack<Cartas> g6, std::stack<Cartas> g7)
{
	// Se crea un arreglo de pilas con los grupos de cartas
	std::stack<Cartas> grupos[] = { g1, g2, g3, g4, g5, g6, g7 };

	// Variable para almacenar el máximo número de cartas visibles
	int Maximo = 0;

	// Se itera a través de los grupos
	for (int i = 0; i < 7; i++)
	{
		std::stack<Cartas> Max;

		// Mientras el grupo no esté vacío
		while (!grupos[i].empty())
		{
			// Si la carta en la cima del grupo es visible
			if (grupos[i].top().visible == true)
			{
				// Se agrega a la pila Max
				Max.push(grupos[i].top());
			}

			// Se retira la carta del grupo
			grupos[i].pop();
		}

		// Se compara el tamaño de Max con el máximo actual
		if (Max.size() > Maximo)
		{
			Maximo = Max.size(); // Si es mayor, se actualiza el máximo
		}
	}

	// Se retorna el máximo número de cartas visibles
	return Maximo;
}


void Solitario::ImprimirCartas(std::stack <Cartas> mazo, std::stack<Cartas> g1, std::stack<Cartas> g2, std::stack<Cartas> g3, std::stack<Cartas> g4, std::stack<Cartas> g5, std::stack<Cartas> g6, std::stack<Cartas>  g7)
{
	// Copiar el mazo para no modificar la original
	stack<Cartas> MazoTemp = mazo;

	// Crear un arreglo de grupos
	stack<Cartas> grupos[] = { g1,g2,g3,g4,g5,g6,g7 };

	// Encontrar el máximo número de cartas visibles entre los grupos
	int MaxCartas = MaximoCartas(g1, g2, g3, g4, g5, g6, g7);

	// Variable para controlar la cantidad de repeticiones
	int repetir = -1;

	// Encontrar el máximo entre el tamaño de los grupos y el MaxCartas actual
	for (int k = 0; k < 7; k++)
	{
		if (grupos[k].size() > MaxCartas)
		{
			MaxCartas = grupos[k].size();
		}
	}

	// Imprimir el mazo
	cout << "MAZO:" << MazoTemp.top().Numero << MazoTemp.top().Color << endl;

	// Imprimir los nombres de los grupos
	for (int j = 7; j > 0; j--)
	{
		cout << "G" << j << "\t";
	}
	cout << endl;

	// Imprimir las cartas
	for (int i = 0; i < MaxCartas; i++)
	{
		repetir++;
		for (int l = 0; l < 7; l++)
		{
			stack<Cartas> Invertido;
			stack<Cartas> Dese = grupos[l];

			// Invertir la pila temporalmente
			while (!Dese.empty()) {
				if (Dese.top().visible)
				{
					Invertido.push(Dese.top());
				}
				Dese.pop();
			}

			// Retirar cartas según el valor de repetir
			for (int f = 0; f < repetir; f++)
			{
				if (!Invertido.empty())
				{
					Invertido.pop();
				}
				else
				{
					break;
				}
			}

			if (!Invertido.empty())
			{
				if (Invertido.top().visible)
				{
					cout << Invertido.top().Numero << Invertido.top().Color << "\t";
				}
				else
				{
					cout << "     \t"; // Espacios para las cartas no visibles
				}
			}
			else
			{
				cout << "\t";
			}
		}
		cout << endl;
	}
}

bool Solitario::ElegirCarta(int pos, int origen, int destino, stack<Cartas>& mazo, stack<Cartas>& g1, stack<Cartas>& g2, stack<Cartas>& g3, stack<Cartas>& g4, stack<Cartas>& g5, stack<Cartas>& g6, stack<Cartas>& g7)
{
	// Obtener las referencias a los grupos de origen y destino
	stack<Cartas>& ori = GrupoSelec(origen, mazo, g1, g2, g3, g4, g5, g6, g7);
	stack<Cartas>& dest = GrupoSelec(destino, mazo, g1, g2, g3, g4, g5, g6, g7);

	// Crear una copia temporal del grupo de origen
	stack<Cartas> Temp = ori;

	// Crear una lista temporal para almacenar las cartas visibles
	list<Cartas> Temporal;

	// Llenar la lista temporal con cartas visibles
	while (!Temp.empty())
	{
		if (Temp.top().visible == true)
		{
			Temporal.push_front(Temp.top());
		}
		Temp.pop();
	}

	// Obtener la cantidad de cartas visibles en la lista temporal
	int Max = Temporal.size();

	// Obtener el número de la última carta visible
	int aver = Temporal.back().Numero;

	// Obtener la cantidad de cartas a mover
	int cant = pos;

	if (VerificarPos(pos, ori))
	{
		if (pos != 1)
		{
			cant = pos;
			cant = cant - 1;

			// Retirar las primeras cartas no seleccionadas
			for (int c = 0; c < cant; c++)
			{
				Temporal.pop_front();
			}
		}

		if (!dest.empty())
		{
			if (dest.top().Numero == (1 + Temporal.front().Numero) && dest.top().Color != Temporal.front().Color)
			{
				// Mover las cartas al grupo de destino
				while (!Temporal.empty())
				{
					dest.push(Temporal.front());
					Temporal.pop_front();
				}
				// Retirar las cartas del grupo de origen
				for (pos; pos <= Max; pos++)
				{
					ori.pop();
				}
				// Si el grupo de origen no está vacío, hacer la carta superior visible
				if (!ori.empty())
				{
					if (ori.top().visible != true)
					{
						ori.top().visible = true;
					}
				}
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			// Mover las cartas al grupo de destino
			while (!Temporal.empty())
			{
				dest.push(Temporal.back());
				Temporal.pop_back();
			}
			// Retirar las cartas del grupo de origen
			for (pos; pos <= Max; pos++)
			{
				ori.pop();
			}
			// Si el grupo de origen no está vacío, hacer la carta superior visible
			if (!ori.empty())
			{
				if (ori.top().visible != true)
				{
					ori.top().visible = true;
				}
			}
			return true;
		}
	}
	else
	{
		return false;
	}
}



bool Solitario::Ganador(std::stack<Cartas> g1, std::stack<Cartas> g2, std::stack<Cartas> g3, std::stack<Cartas> g4, std::stack<Cartas> g5, std::stack<Cartas> g6, std::stack<Cartas> g7)
{
	// Inicialización de las variables
	int maxgrupos = 7;
	stack <Cartas> grupos[] = { g1,g2,g3,g4,g5,g6,g7 };
	int sucesion;
	bool winner = false;

	// Iteración para recorrer cada pila
	for (int i = 0; i < 7; i++)
	{
		sucesion = 0;
		// Declaro una "Stack" con los elementos del grupo correspondiente
		stack<Cartas> group = grupos[i];
		stack<Cartas> Escalera;

		while (!group.empty())
		{
			if (group.top().visible == true)
			{
				Escalera.push(group.top());
			}
			group.pop();
		}

		while (!Escalera.empty())
		{
			// Declaro instancias de la Struct Cartas, para poder realizar las validaciones necesarias
			Cartas first = Escalera.top();
			Escalera.pop();

			if (Escalera.empty())
			{
				break;
			}
			else
			{
				Cartas second = Escalera.top();

				// Verifica si se cumple la condicion
				if (first.Numero == (second.Numero + 1) && first.Color != second.Color)
				{
					// Si se cumple le suma al contador de ganador
					sucesion++;
				}
				else
				{
					// Si no cumple, detiene la iteracion
					break;
				}
			}
		}

		// Si el contador llega hasta 4 significa que ganó, y vuelve al ganador True
		if (sucesion == 4)
		{
			winner = true;
			break;
		}
	}

	// Regresa el bool Winner
	return winner;
}





void Solitario::Tablero(std::stack <Cartas>& mazo, std::stack<Cartas>& g1, std::stack<Cartas>& g2, std::stack<Cartas>& g3, std::stack<Cartas>& g4, std::stack<Cartas>& g5, std::stack<Cartas>& g6, std::stack<Cartas>& g7)
{
	// Inicialización de las listas y pilas para el mazo y los grupos correspondientes
	std::list<Cartas> Baraja;
	std::stack<Cartas> Mazo;
	std::stack<Cartas> Grupo1;
	std::stack<Cartas> Grupo2;
	std::stack<Cartas> Grupo3;
	std::stack<Cartas> Grupo4;
	std::stack<Cartas> Grupo5;
	std::stack<Cartas> Grupo6;
	std::stack<Cartas> Grupo7;

	// Creación del mazo y barajado
	CrearMazo(Baraja);
	Barajear(Baraja, Mazo);

	// Llenado de los grupos de cartas a partir del mazo
	for (int i = 7; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			switch (i)
			{
			case 1: Grupo1.push(Mazo.top());
				break;

			case 2: Grupo2.push(Mazo.top());
				break;

			case 3: Grupo3.push(Mazo.top());
				break;

			case 4: Grupo4.push(Mazo.top());
				break;

			case 5: Grupo5.push(Mazo.top());
				break;

			case 6: Grupo6.push(Mazo.top());
				break;

			case 7: Grupo7.push(Mazo.top());
				break;

			}
			Mazo.pop();
		}
	}

	// Muestra cada una de las primeras cartas de cada grupo
	MostrarUltima(Mazo);
	MostrarUltima(Grupo1);
	MostrarUltima(Grupo2);
	MostrarUltima(Grupo3);
	MostrarUltima(Grupo4);
	MostrarUltima(Grupo5);
	MostrarUltima(Grupo6);
	MostrarUltima(Grupo7);

	// Asignación de las pilas actualizadas a los argumentos de la función
	mazo = Mazo;
	g1 = Grupo1;
	g2 = Grupo2;
	g3 = Grupo3;
	g4 = Grupo4;
	g5 = Grupo5;
	g6 = Grupo6;
	g7 = Grupo7;

	// Imprime el tablero
	ImprimirTablero(Mazo, Grupo7, Grupo6, Grupo5, Grupo4, Grupo3, Grupo2, Grupo1);
}




