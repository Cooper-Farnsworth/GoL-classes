#include "Life.h"

const int Sx = 100;
const int Sy = 100;
short lifeT[Sx][Sy] = { 0 };
short life[Sx][Sy] = { 0 };
int pz = 0;
sf::CircleShape shape[Sx][Sy];

Life::Life()
{
	sf::RenderWindow window(sf::VideoMode(Sx * 10, Sy * 10), "Life Ver 1.0");
	window.setPosition({ 0, 0 });
	Game_Start();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(mil));

		Draw();
		for (int x = 1; x < Sx - 1; x++)
			for (int y = 1; y < Sy - 1; y++)
				window.draw(shape[x][y]);
		Calculate();
		window.display();
	}
}

int Life::CalculateTmp(int i, int x, int y)
{
	int tmp = 0;

	if (life[x - 1][y] == i)	    tmp++;
	if (life[x - 1][y + 1] == i)	tmp++;
	if (life[x][y + 1] == i)	    tmp++;
	if (life[x + 1][y + 1] == i)	tmp++;
	if (life[x + 1][y] == i)	    tmp++;
	if (life[x + 1][y - 1] == i)	tmp++;
	if (life[x][y - 1] == i)	    tmp++;
	if (life[x - 1][y - 1] == i) 	tmp++;

	return tmp;
}

void Life::Game_Start()
{
	srand(time(NULL));
	for (int x = 1; x < Sx - 1; x++)
		for (int y = 1; y < Sy - 1; y++) 
		{
			life[x][y] = rand() % 3;
			shape[x][y].setRadius(4.0f);
		}
	memcpy(lifeT, life, sizeof(lifeT));
}

void Life::Calculate()
{
	for (int x = 1; x < Sx - 1; x++)
		for (int y = 1; y < Sy - 1; y++)
		{
			int g = CalculateTmp(1, x, y);
			if (life[x][y] != 1)
			{
				if (g == 3) lifeT[x][y] = 1;
			}
			else if (life[x][y] == 1)
			{
				if (g > 3 || g < 2) lifeT[x][y] = 0;
			}
		}
}

void Life::Draw()
{
	memcpy(life, lifeT, sizeof(life));
	for (int x = 1; x < Sx - 1; x++)
		for (int y = 1; y < Sy - 1; y++)
		{
			shape[x][y].setPosition(x * 10, y * 10);
			if (life[x][y] == 1) shape[x][y].setFillColor(sf::Color::Green);
			else shape[x][y].setFillColor(sf::Color::Black);
		}
}
