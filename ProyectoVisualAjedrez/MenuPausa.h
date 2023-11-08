#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;



class MenuPausa
{

public:
	MenuPausa(float width, float heigth);

	void draw(RenderWindow& window);
	void MoverArriba();
	void MoverAbajo();

	int BotonPresionadoMenu() {
		return ObjetoSeleccionado;
	}
	~MenuPausa();

private:

	int ObjetoSeleccionado;
	Font font;
	Text MenuPausaT[1];


};


