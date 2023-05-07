#pragma once
#include <SFML/Graphics.hpp>
#include <thread>
#include<chrono>
using namespace std;

class Life
{
public:
	int pz = 0;
	std::chrono::milliseconds mil = std::chrono::milliseconds(pz);
	int fl = 1;
	Life();
	int CalculateTmp(int i, int x, int y);
	void Game_Start();
	void Calculate();
	void Draw();
};

