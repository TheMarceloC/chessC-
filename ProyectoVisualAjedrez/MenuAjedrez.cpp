#include "MenuAjedrez.h"

MenuAjedrez::MenuAjedrez(float width, float heigth)

{
	if (!font.loadFromFile("Fuente/a.ttf")) {
	}
	!font2.loadFromFile("Fuente/B.ttf");

	// Opcion Jugar

	menuAjedrez[0].setFont(font);
	menuAjedrez[0].setFillColor(Color::White);
	menuAjedrez[0].setString("Jugar");
	menuAjedrez[0].setCharacterSize(70);
	menuAjedrez[0].setPosition(400, 300);

	//Opcion Ver historial
	menuAjedrez[1].setFont(font);
	menuAjedrez[1].setFillColor(Color::White);
	menuAjedrez[1].setString("Ver Historial");
	menuAjedrez[1].setCharacterSize(70);
	menuAjedrez[1].setPosition(400, 400);

	//Opcion Salir
	menuAjedrez[2].setFont(font);
	menuAjedrez[2].setFillColor(Color::White);
	menuAjedrez[2].setString("Salir");
	menuAjedrez[2].setCharacterSize(70);
	menuAjedrez[2].setPosition(400, 500);

	//Titulo 
	menuAjedrez[3].setFont(font2);
	menuAjedrez[3].setFillColor(Color::Cyan);
	menuAjedrez[3].setString("Ajedrez en C++");
	menuAjedrez[3].setCharacterSize(70);
	menuAjedrez[3].setPosition(130, 1);

	ObjetoSeleccionado = -1;

}

MenuAjedrez::~MenuAjedrez()
{

}

//Dibujar menu

void MenuAjedrez::draw(RenderWindow& window)
{
	for (int i = 0; i < 4; i++) {
		window.draw(menuAjedrez[i]);
	}
}


// Movimiento en el menu arriba
void MenuAjedrez::MoverArriba()
{
	if (ObjetoSeleccionado - 1 >= 0)
	{
		menuAjedrez[ObjetoSeleccionado].setFillColor(Color::White);

		ObjetoSeleccionado--;

		if (ObjetoSeleccionado == -1) {
			ObjetoSeleccionado = 3;
		}
		menuAjedrez[ObjetoSeleccionado].setFillColor(Color::Blue);
	}
}

//Movimiento hacia abajo
void MenuAjedrez::MoverAbajo()
{
	if (ObjetoSeleccionado + 1 <= 3)
	{
		menuAjedrez[ObjetoSeleccionado].setFillColor(Color::White);


		ObjetoSeleccionado++;

		if (ObjetoSeleccionado == 3) {
			ObjetoSeleccionado = 0;
		}
		menuAjedrez[ObjetoSeleccionado].setFillColor(Color::Blue);
	}
}
