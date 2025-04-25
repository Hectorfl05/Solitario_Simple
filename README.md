# Solitario Simple en C++ ♠️♥️♦️♣️

![Static Badge](https://img.shields.io/badge/Lenguaje-C%2B%2B-%2300599C?logo=cplusplus)
![Static Badge](https://img.shields.io/badge/Enfoque-Estructuras_Lineales-blueviolet)

Implementación del clásico Solitario (Klondike) en C++ como proyecto académico, utilizando listas enlazadas y pilas para gestionar la lógica del juego.

## 🎯 Objetivos
- Implementar **listas enlazadas** para el mazo de cartas
- Utilizar **pilas** para las columnas del juego
- Aplicar validaciones de:
  - Secuencias descendentes (K→Q→J→...→A)
  - Colores alternados (rojo/negro)
- Cumplir con los requisitos del Laboratorio 06 de Estructuras Lineales

## 📜 Reglas del Juego
1. **Repartición inicial**:
   - 7 columnas escalonadas (1-7 cartas)
   - Solo la última carta visible en cada columna

2. **Movimientos válidos**:
   ```plaintext
   - Secuencia: 10♠ → 9♥ (descendente + color alterno)
   - Reyes (K) pueden colocarse en espacios vacíos
