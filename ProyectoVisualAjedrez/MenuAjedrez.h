#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class MenuAjedrez
{

public:
	MenuAjedrez(float width, float heigth);

	void draw(RenderWindow& window);
	void MoverArriba();
	void MoverAbajo();

	int BotonPresionadoMenu() {
		return ObjetoSeleccionado;
	}
	~MenuAjedrez();

private:

	int ObjetoSeleccionado;
	Font font;
	Font font2;
	Text menuAjedrez[4];

};

