#include "MenuPausa.h"


MenuPausa::MenuPausa(float width, float heigth)

{
	(!font.loadFromFile("Fuente/a.ttf"));


	// Opcion Rendirse

	MenuPausaT[0].setFont(font);
	MenuPausaT[0].setFillColor(Color::White);
	MenuPausaT[0].setString("Rendirse");
	MenuPausaT[0].setCharacterSize(70);
	MenuPausaT[0].setPosition(400, 400);

	//Opcion Reanudar
	MenuPausaT[1].setFont(font);
	MenuPausaT[1].setFillColor(Color::White);
	MenuPausaT[1].setString("Reanudar");
	MenuPausaT[1].setCharacterSize(70);
	MenuPausaT[1].setPosition(400, 500);



	ObjetoSeleccionado = -1;

}

MenuPausa::~MenuPausa()
{

}

//Dibujar menu

void MenuPausa::draw(RenderWindow& window)
{
	for (int i = 0; i < 2; i++) {
		window.draw(MenuPausaT[i]);
	}
}


// Movimiento en el menu arriba
void MenuPausa::MoverArriba()
{
	if (ObjetoSeleccionado - 1 >= 0)
	{
		MenuPausaT[ObjetoSeleccionado].setFillColor(Color::White);

		ObjetoSeleccionado--;

		if (ObjetoSeleccionado == -1) {
			ObjetoSeleccionado = 1;
		}
		MenuPausaT[ObjetoSeleccionado].setFillColor(Color::Blue);
	}
}

//Movimiento hacia abajo
void MenuPausa::MoverAbajo()
{
	if (ObjetoSeleccionado + 1 <= 2)
	{
		MenuPausaT[ObjetoSeleccionado].setFillColor(Color::White);


		ObjetoSeleccionado++;

		if (ObjetoSeleccionado == 2) {
			ObjetoSeleccionado = 0;
		}
		MenuPausaT[ObjetoSeleccionado].setFillColor(Color::Blue);
	}
}

