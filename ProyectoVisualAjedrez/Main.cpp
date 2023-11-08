#include <SFML/Graphics.hpp>
#include <iostream>
#include "MenuAjedrez.h"
#include "MenuPausa.h"

#define Longitud 8
#define PeonNegroPos 1
#define PeonBlancoP -1
#define TorreNegraP 2
#define TorreBlancaP -2
#define CaballoBlancoP -3
#define CaballoNegroP 3
#define AlfilNegroP 4
#define AlfilBlancoP -4
#define ReinaBlancaP -5
#define ReinaNegraP 5
#define ReyNegroP 6
#define ReyBlancoP -6

using namespace sf;
using namespace std;

struct poz  // Estructura de datos
{
	int x, y;
}PoscicionAntigua, ReyBlancoS, ReyNegroS, TransformacionBlancas, TransformacionNegras;

int  Dimenisiones = 100, Movimiento = 0, x, y;
int TableroNumerico[8][8] =
{ 2, 3, 4, 5, 6, 4, 3, 2,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
 -1,-1,-1,-1,-1,-1,-1,-1,
 -2,-3,-4,-5,-6,-4,-3,-2, };

int TorreBlancaDerecha = 0, TorreBlancaIzquierda = 0, ReyBlancoPos = 0; // Enrroque
int TorreNegraDerecha = 0, TorreNegraIzquierda = 0, ReyNegroPos = 0;

int Turno = 0; // 0 para blanca, 1 para negra

int TurnoBlanco = 0, TurnoNegras = 0;

int TransformacionBlanca = 0, TransformacionNegro = 0;


int PeonBlancoM(int fo, int co, int fd, int cd)
{
	if (PoscicionAntigua.y == 6)
	{
		if ((cd == co - 1 && fd == fo && TableroNumerico[co - 1][fo] == 0) || (cd == co - 2 && fd == fo && TableroNumerico[co - 1][fo] == 0 && TableroNumerico[co - 2][fo] == 0))
		{
			return 1;
		}
	}
	else if (cd == co - 1 && fd == fo && TableroNumerico[co - 1][fo] == 0)
	{
		return 1;
	}
	if (TableroNumerico[co - 1][fo - 1] > 0)
	{
		if (cd == co - 1 && fd == fo - 1)
		{
			return 1;
		}
	}
	if (TableroNumerico[co - 1][fo + 1] > 0)
	{
		if (cd == co - 1 && fd == fo + 1)
		{
			return 1;
		}
	}
	return 0;
}

int PeonNegroM(int fo, int co, int fd, int cd)
{
	if (PoscicionAntigua.y == 1)
	{
		if ((cd == co + 1 && fd == fo && TableroNumerico[co + 1][fo] == 0) || (cd == co + 2 && fd == fo && TableroNumerico[co + 1][fo] == 0 && TableroNumerico[co + 2][fo] == 0))
		{
			return 1;
		}
	}
	else if (cd == co + 1 && fd == fo && TableroNumerico[co + 1][fo] == 0)
	{
		return 1;
	}
	if (TableroNumerico[co + 1][fo - 1] < 0)
	{
		if (cd == co + 1 && fd == fo - 1)
		{
			return 1;
		}
	}
	if (TableroNumerico[co + 1][fo + 1] < 0)
	{
		if (cd == co + 1 && fd == fo + 1)
		{
			return 1;
		}
	}
	return 0;
}

int TorreBlancaM(int fo, int co, int fd, int cd)
{
	for (int i = fo - 1; i >= 0; i--) // Izquierda
	{
		if (TableroNumerico[co][i] >= 0 && (fd == i && cd == co))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co - 1; i >= 0; i--) // Arriba
	{
		if (TableroNumerico[i][fo] >= 0 && (cd == i && fd == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	for (int i = fo + 1; i <= 7; i++) // Derecha
	{
		if (TableroNumerico[co][i] >= 0 && (cd == co && fd == i))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co + 1; i <= 7; i++) // Abajo
	{
		if (TableroNumerico[i][fo] >= 0 && (cd == i && fd == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	return 0;
}

int TorreNegraM(int fo, int co, int fd, int cd)
{
	for (int i = fo - 1; i >= 0; i--) // Izquierda
	{
		if (TableroNumerico[co][i] <= 0 && (fd == i && cd == co))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co - 1; i >= 0; i--) // Arriba
	{
		if (TableroNumerico[i][fo] <= 0 && (cd == i && fd == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	for (int i = fo + 1; i <= 7; i++) // Derecha
	{
		if (TableroNumerico[co][i] <= 0 && (cd == co && fd == i))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co + 1; i <= 7; i++) // Abajo
	{
		if (TableroNumerico[i][fo] <= 0 && (cd == i && fd == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	return 0;
}

int AlfilBlancoM(int fo, int co, int fd, int cd)
{
	int j = fo - 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal superior izquierda
	{
		if (TableroNumerico[i][j] >= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal superior derecha
	{
		if (TableroNumerico[i][j] >= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = fo - 1;
	for (int i = co + 1; i <= 7; i++) // Diagnal inferior izquierda
	{
		if (TableroNumerico[i][j] >= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co + 1; i <= 7; i++)  // Diagnal inferior derecha
	{
		if (TableroNumerico[i][j] >= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int AlfilNegroM(int fo, int co, int fd, int cd)
{
	int j = fo - 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal superior izquierda
	{
		if (TableroNumerico[i][j] <= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal superior derecha
	{
		if (TableroNumerico[i][j] <= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = fo - 1;
	for (int i = co + 1; i <= 7; i++) // Diagnal inferior izquierda
	{
		if (TableroNumerico[i][j] <= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co + 1; i <= 7; i++)  // Diagnal inferior derecha
	{
		if (TableroNumerico[i][j] <= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int ReinaBlancaM(int fo, int co, int fd, int cd)
{
	for (int i = fo - 1; i >= 0; i--) // Izquierda
	{
		if (TableroNumerico[co][i] >= 0 && (fd == i && cd == co))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co - 1; i >= 0; i--) // arriba
	{
		if (TableroNumerico[i][fo] >= 0 && (cd == i && fd == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	for (int i = fo + 1; i <= 7; i++) // derecha
	{
		if (TableroNumerico[co][i] >= 0 && (cd == co && fd == i))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co + 1; i <= 7; i++) // Abajo
	{
		if (TableroNumerico[i][fo] >= 0 && (cd == i && fd == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	int j = fo - 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal Superior Izquierda
	{
		if (TableroNumerico[i][j] >= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal Superior Derecha
	{
		if (TableroNumerico[i][j] >= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = fo - 1;
	for (int i = co + 1; i <= 7; i++) // Diagonal inferior izquierda
	{
		if (TableroNumerico[i][j] >= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co + 1; i <= 7; i++)  // Diagonal inferior derecha
	{
		if (TableroNumerico[i][j] >= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int ReinaNegraM(int fo, int co, int fd, int cd)
{
	for (int i = fo - 1; i >= 0; i--) // Izquierda
	{
		if (TableroNumerico[co][i] <= 0 && (fd == i && cd == co))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co - 1; i >= 0; i--) // arriba
	{
		if (TableroNumerico[i][fo] <= 0 && (cd == i && fd == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	for (int i = fo + 1; i <= 7; i++) // Derecha
	{
		if (TableroNumerico[co][i] <= 0 && (cd == co && fd == i))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co + 1; i <= 7; i++) // Abajo
	{
		if (TableroNumerico[i][fo] <= 0 && (cd == i && fd == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	int j = fo - 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal Superior Izquierda
	{
		if (TableroNumerico[i][j] <= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal Superior Derecha
	{
		if (TableroNumerico[i][j] <= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = fo - 1;
	for (int i = co + 1; i <= 7; i++) // Diagonal Inferior Izquierda
	{
		if (TableroNumerico[i][j] <= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co + 1; i <= 7; i++)  // Diagonal Inferior Derecha
	{
		if (TableroNumerico[i][j] <= 0 && (cd == i && fd == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int CaballoBlancoM(int fo, int co, int fd, int cd)
{
	if (co - 2 >= 0 && fo - 1 >= 0 && cd == co - 2 && fd == fo - 1 && TableroNumerico[cd][fd] >= 0)
	{
		return 1; // Arriba izquierda
	}
	if (co - 2 >= 0 && fo + 1 < Longitud && cd == co - 2 && fd == fo + 1 && TableroNumerico[cd][fd] >= 0)
	{
		return 1; // Arriba Derecha
	}
	if (co - 1 >= 0 && fo + 2 < Longitud && cd == co - 1 && fd == fo + 2 && TableroNumerico[cd][fd] >= 0)
	{
		return 1; // Derecha
	}
	if (co + 1 >= 0 && fo + 2 < Longitud && cd == co + 1 && fd == fo + 2 && TableroNumerico[cd][fd] >= 0)
	{
		return 1; // Derecha abajo
	}
	if (co + 2 < Longitud && fo + 1 < Longitud && cd == co + 2 && fd == fo + 1 && TableroNumerico[cd][fd] >= 0)
	{
		return 1; // Abajo
	}
	if (co + 2 < Longitud && fo - 1 >= 0 && cd == co + 2 && fd == fo - 1 && TableroNumerico[cd][fd] >= 0)
	{
		return 1; //izquierda Abajo
	}
	if (co + 1 < Longitud && fo - 2 >= 0 && cd == co + 1 && fd == fo - 2 && TableroNumerico[cd][fd] >= 0)
	{
		return 1; // Izquierda
	}
	if (co - 1 >= 0 && fo - 2 >= 0 && cd == co - 1 && fd == fo - 2 && TableroNumerico[cd][fd] >= 0)
	{
		return 1;
	}
	return 0;
}

int CaballoNegroM(int fo, int co, int fd, int cd)
{
	if (co - 2 >= 0 && fo - 1 >= 0 && cd == co - 2 && fd == fo - 1 && TableroNumerico[cd][fd] <= 0)
	{
		return 1; // Arriba izquierda
	}
	if (co - 2 >= 0 && fo + 1 < Longitud && cd == co - 2 && fd == fo + 1 && TableroNumerico[cd][fd] <= 0)
	{
		return 1; // Arriba Derecha
	}
	if (co - 1 >= 0 && fo + 2 < Longitud && cd == co - 1 && fd == fo + 2 && TableroNumerico[cd][fd] <= 0)
	{
		return 1; // Derecha
	}
	if (co + 1 >= 0 && fo + 2 < Longitud && cd == co + 1 && fd == fo + 2 && TableroNumerico[cd][fd] <= 0)
	{
		return 1; // Derecha abajo
	}
	if (co + 2 < Longitud && fo + 1 < Longitud && cd == co + 2 && fd == fo + 1 && TableroNumerico[cd][fd] <= 0)
	{
		return 1; // Abajo
	}
	if (co + 2 < Longitud && fo - 1 >= 0 && cd == co + 2 && fd == fo - 1 && TableroNumerico[cd][fd] <= 0)
	{
		return 1; //izquierda Abajo
	}
	if (co + 1 < Longitud && fo - 2 >= 0 && cd == co + 1 && fd == fo - 2 && TableroNumerico[cd][fd] <= 0)
	{
		return 1; // Izquierda
	}
	if (co - 1 >= 0 && fo - 2 >= 0 && cd == co - 1 && fd == fo - 2 && TableroNumerico[cd][fd] <= 0)
	{
		return 1;
	}
	return 0;
}


int PeonBlancoMCiclo(int posx, int posy, int ReyPx, int ReyPy)
{

	if (TableroNumerico[posy - 1][posx - 1] >= 0)
	{
		if (posy - 1 == ReyPy && posx - 1 == ReyPx)
		{
			return 1;
		}
	}
	if (TableroNumerico[posy - 1][posx + 1] >= 0)
	{

		if (posy - 1 == ReyPy && posx + 1 == ReyPx)
		{
			return 1;
		}
	}
	return 0;
}

int TorreBlancaMCiclo(int fo, int co, int ReyPx, int ReyPy)
{
	for (int i = fo - 1; i >= 0; i--) // Izquierda
	{
		if (TableroNumerico[co][i] >= 0 && (ReyPx == i && ReyPy == co))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co - 1; i >= 0; i--) // Arriba
	{
		if (TableroNumerico[i][fo] >= 0 && (ReyPy == i && ReyPx == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	for (int i = fo + 1; i < Longitud; i++) // Derecha
	{
		if (TableroNumerico[co][i] >= 0 && (ReyPy == co && ReyPx == i))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co + 1; i < Longitud; i++) // Abajo
	{
		if (TableroNumerico[i][fo] >= 0 && (ReyPy == i && ReyPx == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	return 0;
}

int AlfilBlancoMCiclo(int fo, int co, int ReyPx, int ReyPy)
{
	int j = fo - 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal superior izquierda
	{
		if (TableroNumerico[i][j] >= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal superior derecha
	{
		if (TableroNumerico[i][j] >= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = fo - 1;
	for (int i = co + 1; i <= 7; i++) // Diagnal inferior izquierda
	{
		if (TableroNumerico[i][j] >= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co + 1; i <= 7; i++)  // Diagnal inferior derecha
	{
		if (TableroNumerico[i][j] >= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int ReinaBlancaMCiclo(int fo, int co, int ReyPx, int ReyPy)
{
	for (int i = fo - 1; i >= 0; i--) // Izquierda
	{
		if (TableroNumerico[co][i] >= 0 && (ReyPx == i && ReyPy == co))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co - 1; i >= 0; i--) // arriba
	{
		if (TableroNumerico[i][fo] >= 0 && (ReyPy == i && ReyPx == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	for (int i = fo + 1; i < Longitud; i++) // derecha
	{
		if (TableroNumerico[co][i] >= 0 && (ReyPy == co && ReyPx == i))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co + 1; i < Longitud; i++) // Abajo
	{
		if (TableroNumerico[i][fo] >= 0 && (ReyPy == i && ReyPx == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	int j = fo - 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal Superior Izquierda
	{
		if (TableroNumerico[i][j] >= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal Superior Derecha
	{
		if (TableroNumerico[i][j] >= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = fo - 1;
	for (int i = co + 1; i <= 7; i++) // Diagonal Inferior Izquierda
	{
		if (TableroNumerico[i][j] >= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co + 1; i < Longitud; i++)  // Diagonal Inferior Derecha
	{
		if (TableroNumerico[i][j] >= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int CaballoBlancoMCiclo(int fo, int co, int ReyPx, int ReyPy)
{
	if (co - 2 >= 0 && fo - 1 >= 0 && ReyPy == co - 2 && ReyPx == fo - 1 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1; // Arriba izquierda
	}
	if (co - 2 >= 0 && fo + 1 < Longitud && ReyPy == co - 2 && ReyPx == fo + 1 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1; // Arriba Derecha
	}
	if (co - 1 >= 0 && fo + 2 < Longitud && ReyPy == co - 1 && ReyPx == fo + 2 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1; // Derecha
	}
	if (co + 1 >= 0 && fo + 2 < Longitud && ReyPy == co + 1 && ReyPx == fo + 2 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1; // Derecha abajo
	}
	if (co + 2 < Longitud && fo + 1 < Longitud && ReyPy == co + 2 && ReyPx == fo + 1 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1; // Abajo
	}
	if (co + 2 < Longitud && fo - 1 >= 0 && ReyPy == co + 2 && ReyPx == fo - 1 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1; //izquierda Abajo
	}
	if (co + 1 < Longitud && fo - 2 >= 0 && ReyPy == co + 1 && ReyPx == fo - 2 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1; // Izquierda
	}
	if (co - 1 >= 0 && fo - 2 >= 0 && ReyPy == co - 1 && ReyPx == fo - 2 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1;
	}
	return 0;
}

int ReyBlancoMCiclo(int fo, int co, int ReyPx, int ReyPy)
{
	if (fo - 1 >= 0 && co - 1 >= 0 && ReyPy == co - 1 && ReyPx == fo - 1 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1;
	}
	if (co - 1 >= 0 && ReyPx == fo && ReyPy == co - 1 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1;
	}
	if (co - 1 >= 0 && fo + 1 < Longitud && ReyPx == fo + 1 && ReyPy == co - 1 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1;
	}
	if (fo + 1 < Longitud && ReyPy == co && ReyPx == fo + 1 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1;
	}
	if (fo + 1 < Longitud && co + 1 < Longitud && ReyPy == co + 1 && ReyPx == fo + 1 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1;
	}
	if (co + 1 < Longitud && ReyPy == co + 1 && ReyPx == fo && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1;
	}
	if (fo - 1 >= 0 && co + 1 < Longitud && ReyPx == fo - 1 && ReyPy == co + 1 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1;
	}
	if (fo - 1 >= 0 && ReyPy == co && ReyPx == fo - 1 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1;
	}
	return 0;
}


int PeonNegroMCiclo(int fo, int co, int ReyPx, int ReyPy)
{
	if (TableroNumerico[co + 1][fo - 1] <= 0)
	{
		if (ReyPy == co + 1 && ReyPx == fo - 1)
		{
			return 1;
		}
	}
	if (TableroNumerico[co + 1][fo + 1] <= 0)
	{
		if (ReyPy == co + 1 && ReyPx == fo + 1)
		{
			return 1;
		}
	}
	return 0;
}

int TorreNegraMCiclo(int fo, int co, int ReyPx, int ReyPy)
{
	for (int i = fo - 1; i >= 0; i--) // Izquierda
	{
		if (TableroNumerico[co][i] <= 0 && (ReyPx == i && ReyPy == co))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co - 1; i >= 0; i--) // Arriba
	{
		if (TableroNumerico[i][fo] <= 0 && (ReyPy == i && ReyPx == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	for (int i = fo + 1; i < Longitud; i++) // Derecha
	{
		if (TableroNumerico[co][i] <= 0 && (ReyPy == co && ReyPx == i))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co + 1; i < Longitud; i++) // Abajo
	{
		if (TableroNumerico[i][fo] <= 0 && (ReyPy == i && ReyPx == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	return 0;
}

int AlfilNegroMCiclo(int fo, int co, int ReyPx, int ReyPy)
{
	int j = fo - 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal superior izquierda
	{
		if (TableroNumerico[i][j] <= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal superior derecha
	{
		if (TableroNumerico[i][j] <= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = fo - 1;
	for (int i = co + 1; i <= 7; i++) // Diagnal inferior izquierda
	{
		if (TableroNumerico[i][j] <= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co + 1; i <= 7; i++)  // Diagnal inferior derecha
	{
		if (TableroNumerico[i][j] <= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int ReinaNegraMCiclo(int fo, int co, int ReyPx, int ReyPy)
{
	for (int i = fo - 1; i >= 0; i--) // Izquierda
	{
		if (TableroNumerico[co][i] <= 0 && (ReyPx == i && ReyPy == co))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co - 1; i >= 0; i--) // arriba
	{
		if (TableroNumerico[i][fo] <= 0 && (ReyPy == i && ReyPx == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	for (int i = fo + 1; i < Longitud; i++) // derecha
	{
		if (TableroNumerico[co][i] <= 0 && (ReyPy == co && ReyPx == i))
		{
			return 1;
		}
		else if (TableroNumerico[co][i] != 0)
		{
			break;
		}
	}
	for (int i = co + 1; i < Longitud; i++) // Abajo
	{
		if (TableroNumerico[i][fo] <= 0 && (ReyPy == i && ReyPx == fo))
		{
			return 1;
		}
		else if (TableroNumerico[i][fo] != 0)
		{
			break;
		}
	}
	int j = fo - 1;
	for (int i = co - 1; i >= 0; i--)  // Diagonal Superior Izquierda
	{
		if (TableroNumerico[i][j] <= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co - 1; i >= 0; i--) // Diagonal Superior Derecha
	{
		if (TableroNumerico[i][j] <= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = fo - 1;
	for (int i = co + 1; i <= 7; i++) // Diagonal Inferior Izquierda
	{
		if (TableroNumerico[i][j] <= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = fo + 1;
	for (int i = co + 1; i < Longitud; i++)  // Diagonal Inferior Derecha
	{
		if (TableroNumerico[i][j] <= 0 && (ReyPy == i && ReyPx == j))
		{
			return 1;
		}
		else if (TableroNumerico[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int CaballoNegroMCiclo(int fo, int co, int ReyPx, int ReyPy)
{
	if (co - 2 >= 0 && fo - 1 >= 0 && ReyPy == co - 2 && ReyPx == fo - 1 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1; // Arriba izquierda
	}
	if (co - 2 >= 0 && fo + 1 < Longitud && ReyPy == co - 2 && ReyPx == fo + 1 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1; // Arriba Derecha
	}
	if (co - 1 >= 0 && fo + 2 < Longitud && ReyPy == co - 1 && ReyPx == fo + 2 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1; // Derecha
	}
	if (co + 1 >= 0 && fo + 2 < Longitud && ReyPy == co + 1 && ReyPx == fo + 2 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1; // Derecha abajo
	}
	if (co + 2 < Longitud && fo + 1 < Longitud && ReyPy == co + 2 && ReyPx == fo + 1 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1;  // Abajo
	}
	if (co + 2 < Longitud && fo - 1 >= 0 && ReyPy == co + 2 && ReyPx == fo - 1 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1;  //izquierda Abajo
	}
	if (co + 1 < Longitud && fo - 2 >= 0 && ReyPy == co + 1 && ReyPx == fo - 2 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1; // Izquierda
	}
	if (co - 1 >= 0 && fo - 2 >= 0 && ReyPy == co - 1 && ReyPx == fo - 2 && TableroNumerico[ReyPy][ReyPx] <= 0)
	{
		return 1;
	}
	return 0;
}

int ReyNegroMCiclo(int fo, int co, int ReyPx, int ReyPy)
{
	if (fo - 1 >= 0 && co - 1 >= 0 && ReyPy == co - 1 && ReyPx == fo - 1 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1;
	}
	if (co - 1 >= 0 && ReyPx == fo && ReyPy == co - 1 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1;
	}
	if (co - 1 >= 0 && fo + 1 < Longitud && ReyPx == fo + 1 && ReyPy == co - 1 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1;
	}
	if (fo + 1 < Longitud && ReyPy == co && ReyPx == fo + 1 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1;
	}
	if (fo + 1 < Longitud && co + 1 < Longitud && ReyPy == co + 1 && ReyPx == fo + 1 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1;
	}
	if (co + 1 < Longitud && ReyPy == co + 1 && ReyPx == fo && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1;
	}
	if (fo - 1 >= 0 && co + 1 < Longitud && ReyPx == fo - 1 && ReyPy == co + 1 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1;
	}
	if (fo - 1 >= 0 && ReyPy == co && ReyPx == fo - 1 && TableroNumerico[ReyPy][ReyPx] >= 0)
	{
		return 1;
	}
	return 0;
}



int ReyNegroCicloJaque(int PosReyx, int PosReyY)
{
	int Validacion = 0;
	for (int i = 0; i < Longitud; i++)
	{
		for (int j = 0; j < Longitud; j++)
		{
			if (TableroNumerico[i][j] < 0)
			{
				if (TableroNumerico[i][j] == PeonBlancoP)
				{
					Validacion = PeonBlancoMCiclo(j, i, PosReyx, PosReyY);
				}
				if (TableroNumerico[i][j] == TorreBlancaP)
				{
					Validacion = TorreBlancaMCiclo(j, i, PosReyx, PosReyY);
				}
				if (TableroNumerico[i][j] == CaballoBlancoP)
				{
					Validacion = CaballoBlancoMCiclo(j, i, PosReyx, PosReyY);
				}
				if (TableroNumerico[i][j] == AlfilBlancoP)
				{
					Validacion = AlfilBlancoMCiclo(j, i, PosReyx, PosReyY);
				}
				if (TableroNumerico[i][j] == ReinaBlancaP)
				{
					Validacion = ReinaBlancaMCiclo(j, i, PosReyx, PosReyY);
				}
				if (TableroNumerico[i][j] == ReyBlancoP)
				{
					Validacion = ReyBlancoMCiclo(j, i, PosReyx, PosReyY);
				}
				if (Validacion == 1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int ReyNegro(int fo, int co, int fd, int cd)
{
	if (fo - 1 >= 0 && co - 1 >= 0 && cd == co - 1 && fd == fo - 1 && TableroNumerico[cd][fd] <= 0)
	{
		int Validacion = ReyNegroCicloJaque(fo - 1, co - 1);
		if (Validacion == 1)
		{
			return 1;  // Chequeo de arriba a la izquierda
		}
	}
	if (co - 1 >= 0 && fd == fo && cd == co - 1 && TableroNumerico[cd][fd] <= 0)
	{
		int Validacion = ReyNegroCicloJaque(fo, co - 1);
		if (Validacion == 1)
		{
			return 1; // Chequeo de abajo
		}
	}
	if (co - 1 >= 0 && fo + 1 < Longitud && fd == fo + 1 && cd == co - 1 && TableroNumerico[cd][fd] <= 0)
	{
		int Validacion = ReyNegroCicloJaque(fo + 1, co - 1);
		if (Validacion == 1)
		{
			return 1; // Chequeo de arriba a la derecha
		}
	}
	if (fo + 1 < Longitud && cd == co && fd == fo + 1 && TableroNumerico[cd][fd] <= 0)
	{
		int Validacion = ReyNegroCicloJaque(fo + 1, co);
		if (Validacion == 1)
		{
			return 1; // Chequeo de derecha
		}
	}
	if (fo + 1 < Longitud && co + 1 < Longitud && cd == co + 1 && fd == fo + 1 && TableroNumerico[cd][fd] <= 0)
	{
		int Validacion = ReyNegroCicloJaque(fo + 1, co + 1);
		if (Validacion == 1)
		{
			return 1; // Chequeo de derecha abajo
		}
	}
	if (co + 1 < Longitud && cd == co + 1 && fd == fo && TableroNumerico[cd][fd] <= 0)
	{
		int Validacion = ReyNegroCicloJaque(fo, co + 1);
		if (Validacion == 1)
		{
			return 1; // Chequeo de abajo
		}
	}
	if (fo - 1 >= 0 && co + 1 < Longitud && fd == fo - 1 && cd == co + 1 && TableroNumerico[cd][fd] <= 0)
	{
		int Validacion = ReyNegroCicloJaque(fo - 1, co + 1);
		if (Validacion == 1)
		{
			return 1; // Chequeo de izquierda abajo
		}
	}
	if (fo - 1 >= 0 && cd == co && fd == fo - 1 && TableroNumerico[cd][fd] <= 0)
	{
		int Validacion = ReyNegroCicloJaque(fo - 1, co);
		if (Validacion == 1)
		{
			return 1; // Chequeo de izquierda
		}
	}
	// Enrroque validacion del rey
	if (TorreNegraDerecha == 0 && ReyNegroPos == 0 && TableroNumerico[0][5] == 0 && TableroNumerico[0][6] == 0 && cd == 0 && fd == 6)
	{
		int Validacion = ReyNegroCicloJaque(4, 0);
		if (Validacion == 1)
		{
			Validacion = ReyNegroCicloJaque(5, 0);
			if (Validacion == 1)
			{
				Validacion = ReyNegroCicloJaque(6, 0);
				if (Validacion == 1)
				{
					ReyNegroPos = 1;
					TorreNegraDerecha = 1;
					TableroNumerico[0][7] = 0;
					TableroNumerico[0][5] = TorreNegraP;
					return 1;
				}
			}
		}
	}
	if (TorreNegraIzquierda == 0 && ReyNegroPos == 0 && TableroNumerico[0][3] == 0 && TableroNumerico[0][2] == 0 && TableroNumerico[0][1] == 0 && cd == 0 && fd == 2)
	{
		int Validacion = ReyNegroCicloJaque(4, 0);
		if (Validacion == 1)
		{
			Validacion = ReyNegroCicloJaque(3, 0);
			if (Validacion == 1)
			{
				Validacion = ReyNegroCicloJaque(2, 0);
				if (Validacion == 1)
				{
					Validacion = ReyNegroCicloJaque(1, 0);
					if (Validacion == 1)
					{
						ReyNegroPos = 1;
						TorreNegraIzquierda = 1;
						TableroNumerico[0][0] = 0;
						TableroNumerico[0][3] = TorreNegraP;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}


int ReyBlancoCicloJaque(int PosReyx, int PosReyY)
{
	int Validacion = 0;
	for (int i = 0; i < Longitud; i++)
	{
		for (int j = 0; j < Longitud; j++)
		{
			if (TableroNumerico[i][j] > 0)
			{
				if (TableroNumerico[i][j] == PeonNegroPos)
				{
					Validacion = PeonNegroMCiclo(j, i, PosReyx, PosReyY);
				}
				if (TableroNumerico[i][j] == TorreNegraP)
				{
					Validacion = TorreNegraMCiclo(j, i, PosReyx, PosReyY);
				}
				if (TableroNumerico[i][j] == CaballoNegroP)
				{
					Validacion = CaballoNegroMCiclo(j, i, PosReyx, PosReyY);
				}
				if (TableroNumerico[i][j] == AlfilNegroP)
				{
					Validacion = AlfilNegroMCiclo(j, i, PosReyx, PosReyY);
				}
				if (TableroNumerico[i][j] == ReinaNegraP)
				{
					Validacion = ReinaNegraMCiclo(j, i, PosReyx, PosReyY);
				}
				if (TableroNumerico[i][j] == ReyNegroP)
				{
					Validacion = ReyNegroMCiclo(j, i, PosReyx, PosReyY);
				}
				if (Validacion == 1)
				{

					return 0;
				}
			}
		}
	}
	return 1;
}

int ReyBlanco(int fo, int co, int fd, int cd)
{
	if (fo - 1 >= 0 && co - 1 >= 0 && cd == co - 1 && fd == fo - 1 && TableroNumerico[cd][fd] >= 0)
	{
		int Validacion = ReyBlancoCicloJaque(fo - 1, co - 1);
		if (Validacion == 1)
		{
			return 1;  // Chequeo de arriba a la izquierda
		}
	}
	if (co - 1 >= 0 && fd == fo && cd == co - 1 && TableroNumerico[cd][fd] >= 0)
	{
		int Validacion = ReyBlancoCicloJaque(fo, co - 1);
		if (Validacion == 1)
		{
			return 1; // Chequeo de abajo
		}
	}
	if (co - 1 >= 0 && fo + 1 < Longitud && fd == fo + 1 && cd == co - 1 && TableroNumerico[cd][fd] >= 0)
	{
		int Validacion = ReyBlancoCicloJaque(fo + 1, co - 1);
		if (Validacion == 1)
		{
			return 1; // Chequeo de arriba a la derecha
		}
	}
	if (fo + 1 < Longitud && cd == co && fd == fo + 1 && TableroNumerico[cd][fd] >= 0)
	{
		int Validacion = ReyBlancoCicloJaque(fo + 1, co);
		if (Validacion == 1)
		{
			return 1; // Chequeo de derecha
		}
	}
	if (fo + 1 < Longitud && co + 1 < Longitud && cd == co + 1 && fd == fo + 1 && TableroNumerico[cd][fd] >= 0)
	{
		int Validacion = ReyBlancoCicloJaque(fo + 1, co + 1);
		if (Validacion == 1)
		{
			return 1; // Chequeo de derecha abajo
		}
	}
	if (co + 1 < Longitud && cd == co + 1 && fd == fo && TableroNumerico[cd][fd] >= 0)
	{
		int Validacion = ReyBlancoCicloJaque(fo, co + 1);
		if (Validacion == 1)
		{
			return 1; // Chequeo de abajo
		}
	}
	if (fo - 1 >= 0 && co + 1 < Longitud && fd == fo - 1 && cd == co + 1 && TableroNumerico[cd][fd] >= 0)
	{
		int Validacion = ReyBlancoCicloJaque(fo - 1, co + 1);
		if (Validacion == 1)
		{
			return 1; // Chequeo de izquierda abajo
		}
	}
	if (fo - 1 >= 0 && cd == co && fd == fo - 1 && TableroNumerico[cd][fd] >= 0)
	{
		int Validacion = ReyBlancoCicloJaque(fo - 1, co);
		if (Validacion == 1)
		{
			return 1; // Chequeo de izquierda
		}
	}
	// Enrroque validacion del rey derecha
	if (ReyBlancoPos == 0 && TorreBlancaDerecha == 0 && TableroNumerico[7][5] == 0 && TableroNumerico[7][6] == 0 && cd == 7 && fd == 6)
	{
		int Validacion = 1;
		Validacion = ReyBlancoCicloJaque(4, 7);
		if (Validacion == 1)
		{
			Validacion = ReyBlancoCicloJaque(5, 7);
			if (Validacion == 1)
			{
				Validacion = ReyBlancoCicloJaque(6, 7);
				if (Validacion == 1)
				{
					TableroNumerico[7][7] = 0;
					TableroNumerico[7][5] = TorreBlancaP;
					ReyBlancoPos = 1;
					TorreBlancaDerecha = 1;
					return 1;
				}
			}
		}
	}
	// Enrroque a la iquierda validacion
	if (ReyBlancoPos == 0 && TorreBlancaDerecha == 0 && TableroNumerico[7][3] == 0 && TableroNumerico[7][2] == 0 && TableroNumerico[7][1] == 0 && cd == 7 && fd == 2)
	{
		int Validacion = 1;
		Validacion = ReyBlancoCicloJaque(4, 7);
		if (Validacion == 1)
		{
			Validacion = ReyBlancoCicloJaque(3, 7);
			if (Validacion == 1)
			{
				Validacion = ReyBlancoCicloJaque(2, 7);
				if (Validacion == 1)
				{
					Validacion = ReyBlancoCicloJaque(1, 7);
					if (Validacion == 1)
					{
						TableroNumerico[7][0] = 0;
						TableroNumerico[7][3] = TorreBlancaP;
						ReyBlancoPos = 1;
						TorreBlancaIzquierda = 1;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}


void PosReyBlanco()
{
	for (int i = 0; i < Longitud; i++)
	{
		for (int j = 0; j < Longitud; j++)
		{
			if (TableroNumerico[i][j] == ReyBlancoP)
			{
				ReyBlancoS.x = j;
				ReyBlancoS.y = i;
				break;
			}
		}
	}
}

void PosReyNegro()
{
	for (int i = 0; i < Longitud; i++)
	{
		for (int j = 0; j < Longitud; j++)
		{
			if (TableroNumerico[i][j] == ReyNegroP)
			{
				ReyNegroS.y = i;
				ReyNegroS.x = j;
				break;
			}
		}
	}
}

int main()
{
	RenderWindow MENU(VideoMode(800, 800), "Menu principal", Style::Default);
	MenuAjedrez menuAjedrez(MENU.getSize().x, MENU.getSize().y);



	RectangleShape fondopantalla;
	fondopantalla.setSize(Vector2f(800, 800));
	Texture fondo;
	fondo.loadFromFile("Texturas/A.jpg");
	fondopantalla.setTexture(&fondo);
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;

	t1.loadFromFile("Texturas/Tablero.png");
	t2.loadFromFile("Texturas/PionBlanco.png");
	t3.loadFromFile("Texturas/CaballoBlanco.png");
	t4.loadFromFile("Texturas/AlfilBlanco.png");
	t5.loadFromFile("Texturas/ReyBlanco.png");
	t6.loadFromFile("Texturas/ReinaBlanca.png");
	t7.loadFromFile("Texturas/TorreBlanca.png");
	t8.loadFromFile("Texturas/PeonNegro.png");
	t9.loadFromFile("Texturas/CaballoNegro.png");
	t10.loadFromFile("Texturas/AlfilNegro.png");
	t11.loadFromFile("Texturas/ReyNegro.png");
	t12.loadFromFile("Texturas/ReinaNegra.png");
	t13.loadFromFile("Texturas/TorreNegra.png");
	t14.loadFromFile("Texturas/TransformacionBlancas.png");
	t15.loadFromFile("Texturas/TransformacionNegras.png");

	// Sprite es la textura completa, con dimensiones y permite movimientos

	Sprite tabla(t1);
	Sprite PeonBlancoSP(t2);
	Sprite CaballoBlancoSP(t3);
	Sprite AlfilBlancoSP(t4);
	Sprite ReyBlancolb(t5);
	Sprite ReinaBlancaSP(t6);
	Sprite TorreBlancaSP(t7);
	Sprite PeonNegroMSP(t8);
	Sprite CaballoNegroMSP(t9);
	Sprite AlfilNegroMSP(t10);
	Sprite ReyNegroSP(t11);
	Sprite ReinaNegraMSP(t12);
	Sprite TorreNegraMSP(t13);
	Sprite TransformacionBlanco(t14);
	Sprite TransformacionNegros(t15);
	Sprite MovimientoSprite;
	// Va a cambiar de valor constantemente

	float dx = 0, dy = 0;
	int PiezaMovida = 0;

	while (MENU.isOpen())
	{
		Event MenuW;
		while (MENU.pollEvent(MenuW))
		{
			if (MenuW.type == Event::Closed)
			{
				MENU.close();
			}
			if (MenuW.type == Event::KeyPressed)
			{
				if (MenuW.key.code == Keyboard::Up) {
					menuAjedrez.MoverArriba();
					break;
				}
				if (MenuW.key.code == Keyboard::Down)
				{
					menuAjedrez.MoverAbajo();
					break;
				}

				if (MenuW.key.code == Keyboard::Return)
				{
					RenderWindow window(VideoMode(800, 800), "Ajedrez hecho por los isometricos");
					RenderWindow Historial(VideoMode(800, 800), "Historial de partidas");
					RenderWindow Salir(VideoMode(800, 800), "Salir");
					RenderWindow MenuEsc(VideoMode(800, 800), "Menu pausa", Style::Default);
					int xy = menuAjedrez.BotonPresionadoMenu();
					if (xy == 0)
					{
						MENU.close();
						while (window.isOpen())
						{
							Vector2i pos = Mouse::getPosition(window);
							x = pos.x / Dimenisiones;
							y = pos.y / Dimenisiones;
							Event e;
							while (window.pollEvent(e))
							{
								if (e.key.code == Keyboard::Escape)
								{
									RenderWindow MenuEsc(VideoMode(800, 800), "Menu pausa", Style::Default);
									MenuPausa MenuPausa(MenuEsc.getSize().x, MenuEsc.getSize().y);

									while (MenuEsc.isOpen())
									{
										Event c;
										while (MenuEsc.pollEvent(c))
										{
											if (c.type == Event::Closed)
											{
												MenuEsc.close();
											}

											if (MenuW.key.code == Keyboard::Up)
											{
												MenuPausa.MoverArriba();
												break;
											}
											if (c.type == Event::KeyReleased)
											{
												if (c.key.code == Keyboard::Down)
												{
													MenuPausa.MoverAbajo();
													break;
												}
												if (c.key.code == Keyboard::Return) {

													RenderWindow MenuEsc(VideoMode(800, 800), "Menu pausa", Style::Default);

													int xz = MenuPausa.BotonPresionadoMenu();
													if (xz == 0)
													{
														Text Ganador[1];
														Font font3;



													}

													if (xz == 1)
													{
														MenuEsc.close();
														break;
													}



												}
											}
											MenuEsc.clear();
											MenuEsc.draw(fondopantalla);
											MenuPausa.draw(MenuEsc);
											MenuEsc.display();
										}
									}



								} // cambiar
								if (e.type == Event::Closed)
								{
									window.close();
								}
								window.clear();

								if (e.type == Event::MouseButtonPressed)
								{
									if (e.key.code == Mouse::Left)
									{
										if (TransformacionBlanca == 1)
										{
											if (pos.y >= TransformacionBlancas.y * Dimenisiones && pos.y <= (TransformacionBlancas.y + 1) * Dimenisiones && pos.x >= TransformacionBlancas.x * Dimenisiones && pos.x <= (TransformacionBlancas.x + 1) * Dimenisiones)
											{
												int xx = pos.x % 100, yy = pos.y % 100;

												if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
												{
													TableroNumerico[TransformacionBlancas.y][TransformacionBlancas.x] = TorreBlancaP;
													TransformacionBlanca = 0;
												}
												if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
												{
													TableroNumerico[TransformacionBlancas.y][TransformacionBlancas.x] = ReinaBlancaP;
													TransformacionBlanca = 0;
												}
												if (xx > 50 && xx < 100 && yy>50 && yy < 100)
												{
													TableroNumerico[TransformacionBlancas.y][TransformacionBlancas.x] = CaballoBlancoP;
													TransformacionBlanca = 0;
												}
												if (xx < 50 && xx>0 && yy > 50 && y < 100)
												{
													TableroNumerico[TransformacionBlancas.y][TransformacionBlancas.x] = AlfilBlancoP;
													TransformacionBlanca = 0;
												}
												if (TransformacionBlanca == 0)
												{
													PosReyNegro();
													int h = ReyNegroCicloJaque(ReyNegroS.x, ReyNegroS.y);
													if (h == 0)
													{
														TurnoNegras = 1;
													}
												}
											}
										}
										if (TransformacionNegro == 1)
										{
											if (pos.y >= TransformacionNegras.y * Dimenisiones && pos.y <= (TransformacionNegras.y + 1) * Dimenisiones && pos.x >= TransformacionNegras.x * Dimenisiones && pos.x <= (TransformacionNegras.x + 1) * Dimenisiones)
											{
												int xx = pos.x % 100, yy = pos.y % 100;

												if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
												{
													TableroNumerico[TransformacionNegras.y][TransformacionNegras.x] = TorreNegraP;
													TransformacionNegro = 0;
												}
												if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
												{
													TableroNumerico[TransformacionNegras.y][TransformacionNegras.x] = ReinaNegraP;
													TransformacionNegro = 0;
												}
												if (xx > 50 && xx < 100 && yy>50 && yy < 100)
												{
													TableroNumerico[TransformacionNegras.y][TransformacionNegras.x] = CaballoNegroP;
													TransformacionNegro = 0;
												}
												if (xx < 50 && xx>0 && yy > 50 && y < 100)
												{
													TableroNumerico[TransformacionNegras.y][TransformacionNegras.x] = AlfilNegroP;
													TransformacionNegro = 0;
												}
												if (TransformacionNegro == 0)
												{
													PosReyBlanco();
													int h = ReyBlancoCicloJaque(ReyBlancoS.x, ReyBlancoS.y);
													if (h == 0)
													{
														TurnoBlanco = 1;
													}
												}
											}
										}
										if (TableroNumerico[y][x] != 0)
										{
											dx = pos.x - x * 100;
											dy = pos.y - y * 100;
											if (TableroNumerico[y][x] == PeonNegroPos && Turno == 1)
											{
												PiezaMovida = PeonNegroPos;
												MovimientoSprite = PeonNegroMSP;
												TableroNumerico[y][x] = 0;
											}
											if (TableroNumerico[y][x] == PeonBlancoP && Turno == 0)
											{
												PiezaMovida = PeonBlancoP;
												MovimientoSprite = PeonBlancoSP;
												TableroNumerico[y][x] = 0;
											}
											if (TableroNumerico[y][x] == TorreNegraP && Turno == 1)
											{
												PiezaMovida = TorreNegraP;
												MovimientoSprite = TorreNegraMSP;
												TableroNumerico[y][x] = 0;

											}
											if (TableroNumerico[y][x] == TorreBlancaP && Turno == 0)
											{
												PiezaMovida = TorreBlancaP;
												MovimientoSprite = TorreBlancaSP;
												TableroNumerico[y][x] = 0;

											}
											if (TableroNumerico[y][x] == CaballoBlancoP && Turno == 0)
											{
												PiezaMovida = CaballoBlancoP;
												MovimientoSprite = CaballoBlancoSP;
												TableroNumerico[y][x] = 0;
											}
											if (TableroNumerico[y][x] == CaballoNegroP && Turno == 1)
											{
												PiezaMovida = CaballoNegroP;
												MovimientoSprite = CaballoNegroMSP;
												TableroNumerico[y][x] = 0;
											}
											if (TableroNumerico[y][x] == AlfilNegroP && Turno == 1)
											{
												PiezaMovida = AlfilNegroP;
												MovimientoSprite = AlfilNegroMSP;
												TableroNumerico[y][x] = 0;
											}
											if (TableroNumerico[y][x] == AlfilBlancoP && Turno == 0)
											{
												PiezaMovida = AlfilBlancoP;
												MovimientoSprite = AlfilBlancoSP;
												TableroNumerico[y][x] = 0;
											}
											if (TableroNumerico[y][x] == ReinaBlancaP && Turno == 0)
											{
												PiezaMovida = ReinaBlancaP;
												MovimientoSprite = ReinaBlancaSP;
												TableroNumerico[y][x] = 0;
											}
											if (TableroNumerico[y][x] == ReinaNegraP && Turno == 1)
											{
												PiezaMovida = ReinaNegraP;
												MovimientoSprite = ReinaNegraMSP;
												TableroNumerico[y][x] = 0;
											}
											if (TableroNumerico[y][x] == ReyNegroP && Turno == 1)
											{
												PiezaMovida = ReyNegroP;
												MovimientoSprite = ReyNegroSP;
												TableroNumerico[y][x] = 0;
											}
											if (TableroNumerico[y][x] == ReyBlancoP && Turno == 0)
											{
												PiezaMovida = ReyBlancoP;
												MovimientoSprite = ReyBlancolb;
												TableroNumerico[y][x] = 0;
											}
											if (TableroNumerico[y][x] == 0)
											{
												Movimiento = 1;
												PoscicionAntigua.x = x;
												PoscicionAntigua.y = y;
											}
										}
									}
								}
								if (e.type == Event::MouseButtonReleased)
								{
									if (e.key.code == Mouse::Left)
									{
										int Validacion = 2;
										if (PiezaMovida == PeonBlancoP && Movimiento == 1)
										{
											Validacion = PeonBlancoM(PoscicionAntigua.x, PoscicionAntigua.y, x, y);
										}
										if (PiezaMovida == PeonNegroPos && Movimiento == 1)
										{
											Validacion = PeonNegroM(PoscicionAntigua.x, PoscicionAntigua.y, x, y);
										}
										if (PiezaMovida == TorreBlancaP && Movimiento == 1)
										{
											Validacion = TorreBlancaM(PoscicionAntigua.x, PoscicionAntigua.y, x, y);
											if (Validacion == 1 && TorreBlancaIzquierda == 0 && PoscicionAntigua.y == 7 && PoscicionAntigua.x == 0)
											{
												TorreBlancaIzquierda = 1;
												//Enrroque corto blanca
											}
											if (Validacion == 1 && TorreBlancaDerecha == 0 && PoscicionAntigua.y == 7 && PoscicionAntigua.x == 7)
											{
												TorreBlancaDerecha = 1;
												//Enrroque largo blanca
											}
										}
										if (PiezaMovida == TorreNegraP && Movimiento == 1)
										{
											Validacion = TorreNegraM(PoscicionAntigua.x, PoscicionAntigua.y, x, y);
											if (Validacion == 1 && TorreNegraDerecha == 0 && PoscicionAntigua.y == 0 && PoscicionAntigua.x == 7)
											{
												TorreNegraDerecha = 1;
												//enrroque corto negra

											}
											if (Validacion == 1 && TorreNegraIzquierda == 0 && PoscicionAntigua.y == 0 && PoscicionAntigua.x == 0)
											{
												TorreNegraIzquierda = 1;
												//enrroque largo blanca
											}
										}
										if (PiezaMovida == AlfilBlancoP && Movimiento == 1)
										{
											Validacion = AlfilBlancoM(PoscicionAntigua.x, PoscicionAntigua.y, x, y);
										}
										if (PiezaMovida == AlfilNegroP && Movimiento == 1)
										{
											Validacion = AlfilNegroM(PoscicionAntigua.x, PoscicionAntigua.y, x, y);
										}
										if (PiezaMovida == ReinaBlancaP && Movimiento == 1)
										{
											Validacion = ReinaBlancaM(PoscicionAntigua.x, PoscicionAntigua.y, x, y);
										}
										if (PiezaMovida == ReinaNegraP && Movimiento == 1)
										{
											Validacion = ReinaNegraM(PoscicionAntigua.x, PoscicionAntigua.y, x, y);
										}
										if (PiezaMovida == CaballoBlancoP && Movimiento == 1)
										{
											Validacion = CaballoBlancoM(PoscicionAntigua.x, PoscicionAntigua.y, x, y);
										}
										if (PiezaMovida == CaballoNegroP && Movimiento == 1)
										{
											Validacion = CaballoNegroM(PoscicionAntigua.x, PoscicionAntigua.y, x, y);
										}
										if (PiezaMovida == ReyNegroP && Movimiento == 1)
										{
											Validacion = ReyNegro(PoscicionAntigua.x, PoscicionAntigua.y, x, y);
											if (Validacion == 1 && ReyNegroPos == 0)
											{
												ReyNegroPos = 1;

											}
										}
										if (PiezaMovida == ReyBlancoP && Movimiento == 1)
										{
											Validacion = ReyBlanco(PoscicionAntigua.x, PoscicionAntigua.y, x, y);
											if (Validacion == 1 && ReyBlancoPos == 0)
											{
												ReyBlancoPos = 1;

											}
										}
										if (Validacion == 1)
										{
											int NoJaque = TableroNumerico[y][x];
											TableroNumerico[y][x] = PiezaMovida;
											if (y == 0 && PiezaMovida == PeonBlancoP)
											{
												TransformacionBlanca = 1;
												TransformacionBlancas.x = x;
												TransformacionBlancas.y = y;
												TableroNumerico[y][x] = 0;
											}
											if (y == 7 && PiezaMovida == PeonNegroPos)
											{
												TransformacionNegro = 1;
												TransformacionNegras.x = x;
												TransformacionNegras.y = y;
												TableroNumerico[y][x] = 0;
											}
											if (Turno == 0)
											{
												if (TurnoBlanco == 1)
												{
													PosReyBlanco();
													int s = ReyBlancoCicloJaque(ReyBlancoS.x, ReyBlancoS.y);
													if (s == 0)
													{
														TableroNumerico[PoscicionAntigua.y][PoscicionAntigua.x] = PiezaMovida;
														TableroNumerico[y][x] = NoJaque;
													}
													else
													{
														TurnoBlanco = 0;
														PosReyNegro();
														int L = ReyNegroCicloJaque(ReyNegroS.x, ReyNegroS.y);
														if (L == 0)
														{
															TurnoNegras = 1;
														}
														Turno = 1;
													}
												}
												else
												{
													PosReyBlanco();
													int SiJaque = ReyBlancoCicloJaque(ReyBlancoS.x, ReyBlancoS.y);
													if (SiJaque == 0)
													{
														TableroNumerico[PoscicionAntigua.y][PoscicionAntigua.x] = PiezaMovida;
														TableroNumerico[y][x] = NoJaque;
													}
													else
													{
														PosReyNegro();
														int L = ReyNegroCicloJaque(ReyNegroS.x, ReyNegroS.y);
														if (L == 0)
														{
															TurnoNegras = 1;
														}
														Turno = 1;
													}
												}
											}
											else
											{
												if (TurnoNegras == 1)
												{
													PosReyNegro();
													int s = ReyNegroCicloJaque(ReyNegroS.x, ReyNegroS.y);
													if (s == 0)
													{
														TableroNumerico[PoscicionAntigua.y][PoscicionAntigua.x] = PiezaMovida;
														TableroNumerico[y][x] = NoJaque;
													}
													else
													{
														TurnoNegras = 0;

														int L = ReyBlancoCicloJaque(ReyBlancoS.x, ReyBlancoS.y);
														if (L == 0)
														{
															TurnoBlanco = 1;
														}
														Turno = 0;
													}
												}
												else
												{
													PosReyNegro();
													int SiJaque = ReyNegroCicloJaque(ReyNegroS.x, ReyNegroS.y);
													if (SiJaque == 0)
													{
														TableroNumerico[PoscicionAntigua.y][PoscicionAntigua.x] = PiezaMovida;
														TableroNumerico[y][x] = NoJaque;
													}
													else
													{

														int L = ReyBlancoCicloJaque(ReyBlancoS.x, ReyBlancoS.y);
														if (L == 0)
														{
															TurnoBlanco = 1;
														}
														Turno = 0;
													}
												}
											}
										}
										else if (Validacion == 0)
										{
											TableroNumerico[PoscicionAntigua.y][PoscicionAntigua.x] = PiezaMovida;
										}
										Movimiento = 0;
									}
								}
							}

							window.clear();
							window.draw(tabla);
							if (TransformacionBlanca == 1)
							{
								TransformacionBlanco.setPosition(TransformacionBlancas.x * Dimenisiones, TransformacionBlancas.y * Dimenisiones);
								window.draw(TransformacionBlanco);
							}
							if (TransformacionNegro == 1)
							{
								TransformacionNegros.setPosition(TransformacionNegras.x * Dimenisiones, TransformacionNegras.y * Dimenisiones);
								window.draw(TransformacionNegros);
							}
							if (Movimiento == 1)
							{
								MovimientoSprite.setPosition(pos.x - dx, pos.y - dy);
								window.draw(MovimientoSprite);
							}
							for (int i = 0; i < Longitud; i++)
							{
								for (int j = 0; j < Longitud; j++)
								{

									if (TableroNumerico[i][j] != 0)
									{
										if (TableroNumerico[i][j] == PeonNegroPos)
										{
											PeonNegroMSP.setPosition(j * Dimenisiones, i * Dimenisiones);
											window.draw(PeonNegroMSP);
										}
										if (TableroNumerico[i][j] == PeonBlancoP)
										{
											PeonBlancoSP.setPosition(j * Dimenisiones, i * Dimenisiones);
											window.draw(PeonBlancoSP);
										}
										if (TableroNumerico[i][j] == TorreNegraP)
										{
											TorreNegraMSP.setPosition(j * Dimenisiones, i * Dimenisiones);
											window.draw(TorreNegraMSP);

										}
										if (TableroNumerico[i][j] == TorreBlancaP)
										{
											TorreBlancaSP.setPosition(j * Dimenisiones, i * Dimenisiones);
											window.draw(TorreBlancaSP);

										}
										if (TableroNumerico[i][j] == CaballoBlancoP)
										{
											CaballoBlancoSP.setPosition(j * Dimenisiones, i * Dimenisiones);
											window.draw(CaballoBlancoSP);
										}
										if (TableroNumerico[i][j] == CaballoNegroP)
										{
											CaballoNegroMSP.setPosition(j * Dimenisiones, i * Dimenisiones);
											window.draw(CaballoNegroMSP);
										}
										if (TableroNumerico[i][j] == AlfilNegroP)
										{
											AlfilNegroMSP.setPosition(j * Dimenisiones, i * Dimenisiones);
											window.draw(AlfilNegroMSP);
										}
										if (TableroNumerico[i][j] == AlfilBlancoP)
										{
											AlfilBlancoSP.setPosition(j * Dimenisiones, i * Dimenisiones);
											window.draw(AlfilBlancoSP);
										}
										if (TableroNumerico[i][j] == ReinaBlancaP)
										{
											ReinaBlancaSP.setPosition(j * Dimenisiones, i * Dimenisiones);
											window.draw(ReinaBlancaSP);
										}
										if (TableroNumerico[i][j] == ReinaNegraP)
										{
											ReinaNegraMSP.setPosition(j * Dimenisiones, i * Dimenisiones);
											window.draw(ReinaNegraMSP);
										}
										if (TableroNumerico[i][j] == ReyNegroP)
										{
											ReyNegroSP.setPosition(j * Dimenisiones, i * Dimenisiones);
											window.draw(ReyNegroSP);
										}
										if (TableroNumerico[i][j] == ReyBlancoP)
										{
											ReyBlancolb.setPosition(j * Dimenisiones, i * Dimenisiones);
											window.draw(ReyBlancolb);
										}
									}
								}
							}
							Historial.close();
							Salir.close();
							MenuEsc.close();
							window.display();
						}


					}
					if (xy == 1)
					{
						while (Historial.isOpen())
						{
							Event a;
							while (Historial.pollEvent(a))
							{
								if (a.type == Event::Closed)
								{
									Historial.close();
								}
								if (a.key.code == Keyboard::Escape)// cambiar
								{
									Historial.close();
								}
							}
							window.close();
							Salir.close();
							Historial.clear();
							Historial.display();
						}
					}
					if (xy == 2)
					{
						MENU.close();
						break;
					}


				}
			}
			MENU.clear();
			MENU.draw(fondopantalla);
			menuAjedrez.draw(MENU);
			MENU.display();
		}
	}

	return 0;
}
