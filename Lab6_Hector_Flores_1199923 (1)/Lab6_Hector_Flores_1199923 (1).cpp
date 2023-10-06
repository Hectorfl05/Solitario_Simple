#include "pch.h"
#include "Solitario.h"
#include <random>
#include <iostream>
#include <conio.h>
    
using namespace System;

int main(array<System::String ^> ^args)
{


    //Inicialización de la instancia de la clase Solitario
    Solitario Newgame;
    
    //Inicialización de la lista y las pilas para el mazo y los grupos correspondientes
    std::list<Cartas> Baraja;
    std::stack<Cartas> Mazo;
    std::stack<Cartas> Grupo1;
    std::stack<Cartas> Grupo2;
    std::stack<Cartas> Grupo3;
    std::stack<Cartas> Grupo4;
    std::stack<Cartas> Grupo5;
    std::stack<Cartas> Grupo6;
    std::stack<Cartas> Grupo7;
    int pos, or , des;
    char input;

    Newgame.Tablero(Mazo, Grupo1, Grupo2, Grupo3, Grupo4, Grupo5, Grupo6, Grupo7);

    while (true)
    {
        do
        {

            std::cout << "Si desea sacar otra carta del mazo presione P, de lo contrario, pulse otra tecla para continuar."<<"\n";
            input = _getch();
            if (input == 'P' || input == 'p')
            {
                Newgame.BarajearMazo(Mazo);
                Console::Clear();
                Newgame.ImprimirCartas(Mazo, Grupo7, Grupo6, Grupo5, Grupo4, Grupo3, Grupo2, Grupo1);
                continue;
            }

            std::cout << "\x1B[1A"; // Mueve el cursor hacia arriba
            std::cout << "\x1B[2K"; // Borra la línea

            // Solicitar entrada del usuario
            std::cout << "Posicion desde la cual tomara las cartas (de arriba hacia abajo, la posicion de la carta del MAZO es 1): ";
            std::cin >> pos;
            std::cout << "\n";

            std::cout << "*El mazo es el grupo 0" << "\n";
            std::cout << "\n";

            std::cout << "Grupo Origen: ";
            std::cin >> or;
            std::cout << "\n";


            std::cout << "Grupo Destino: ";
            std::cin >> des;
            std::cout << "\n";


            // Verificar si la jugada es válida
            if (Newgame.ComprobarGrupo(or , des) && Newgame.ElegirCarta(pos, or , des, Mazo, Grupo1, Grupo2, Grupo3, Grupo4, Grupo5, Grupo6, Grupo7))
            {
                // Si la jugada es válida, actualizar pantalla
                Console::Clear();
                Newgame.ImprimirCartas(Mazo, Grupo7, Grupo6, Grupo5, Grupo4, Grupo3, Grupo2, Grupo1);
            }
            else
            {
                // Si la jugada no es válida, mostrar un mensaje de error
                std::cout << "Error, No fue posible realizar la jugada, revise si la posicion o los grupos son correctos.\n";
                Console::ReadKey();
                Console::Clear();
                Newgame.ImprimirCartas(Mazo, Grupo7, Grupo6, Grupo5, Grupo4, Grupo3, Grupo2, Grupo1);

            }

        } while (!Newgame.Ganador(Grupo7, Grupo6, Grupo5, Grupo4, Grupo3, Grupo2, Grupo1));


        std::cout << "USTED HA GANADO" << "\n";
        std::cout << "\n";

        std::cout << "Presione R para reiniciar el juego o cualquier otra tecla para salir";
        input = _getch();
        if (input == 'R' || input == 'r')
        {
            Console::Clear();
            Newgame.Tablero(Mazo, Grupo1, Grupo2, Grupo3, Grupo4, Grupo5, Grupo6, Grupo7);
        }else
        {
            break;
        }

    }

    return 0;
}
