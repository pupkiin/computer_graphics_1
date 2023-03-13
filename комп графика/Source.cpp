#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <math.h>
#include <locale.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

void SetLine(double x0, double y0, double x1, double y1, COLORREF color);
void SetLineBrez(double x0, double y0, double x1, double y1, COLORREF color);
void ShowMenu();

int main(void)
{
	setlocale(LC_ALL, "Russian");
	initwindow(720, 480); // инициализация окна
	float a = 0.05; // Угол в радианах на который вращаем
	float b = 1.1; // Коэффициент маштабирования

	// координаты линии
	double x1dd = 10;
	double y1dd = 40;
	double x2dd = 50;
	double y2dd = 90;
	// координаты линии для алг. Брезенхэма
	double x1br = 80;
	double y1br = 100;
	double x2br = 600;
	double y2br = 159;

	SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
	SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
	ShowMenu();

	while (true)
	{
		char k = getch();
		if (k == 0x31) // 1 - действия над обычн линией
		{
			std::cout << "1" << std::endl;
			while (true) {
				char s = getch();
				if (s == 0x41) { // A - движение налево (x--)
					clearviewport();
					x1dd--;
					x2dd--;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "A" << std::endl;
				}
				if (s == 0x44) { // D - движение вправо (x++)
					clearviewport();
					x1dd++;
					x2dd++;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "D" << std::endl;
				}
				if (s == 0x57) { // W - движение вверх (y++)
					clearviewport();
					y1dd--;
					y2dd--;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "W" << std::endl;
				}
				if (s == 0x53) { // S - движение вниз (y--)
					clearviewport();
					y1dd++;
					y2dd++;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "S" << std::endl;
				}
				if (s == 0x52) { // R - поворот линии

					double x3dd = (x1dd + x2dd) / 2;
					double y3dd = (y1dd + y2dd) / 2;

					/*int xn1 = static_cast<int>(-sin(a) * (y1dd - y3dd) + cos(a) * (x1dd - x3dd) + x3dd);
					int yn1 = static_cast<int>(cos(a) * (y1dd - y3dd) + sin(a) * (x1dd - x3dd) + y3dd);

					int xn2 = static_cast<int>(-sin(a) * (y2dd - y3dd) + cos(a) * (x2dd - x3dd) + x3dd);
					int yn2 = static_cast<int>(cos(a) * (y2dd - y3dd) + sin(a) * (x2dd - x3dd) + y3dd);*/

					// перемещаем в центр координат
					x1dd -= x3dd;
					x2dd -= x3dd;
					y1dd -= y3dd;
					y2dd -= y3dd;

					double xn1 = (x1dd * cos(a) + y1dd * sin(a));
					double yn1 = (-(x1dd * sin(a)) + y1dd * cos(a));

					double xn2 = (x2dd * cos(a) + y2dd * sin(a));
					double yn2 = (-(x2dd * sin(a)) + y2dd * cos(a));

					x1dd = xn1;
					y1dd = yn1;
					x2dd = xn2;
					y2dd = yn2;
					// перемещаем обратно
					x1dd += x3dd;
					x2dd += x3dd;
					y1dd += y3dd;
					y2dd += y3dd;

					clearviewport();
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "R" << std::endl;
				}
				if (s == 0x51) { // Q - уменьшение линии

					double x3dd = (x1dd + x2dd) / 2;
					double y3dd = (y1dd + y2dd) / 2;

					// перемещаем в центр координат
					x1dd -= x3dd;
					x2dd -= x3dd;
					y1dd -= y3dd;
					y2dd -= y3dd;

					x1dd /= b;
					x2dd /= b;
					y1dd /= b;
					y2dd /= b;

					// перемещаем обратно
					x1dd += x3dd;
					x2dd += x3dd;
					y1dd += y3dd;
					y2dd += y3dd;

					clearviewport();
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "Q" << std::endl;
				}
				if (s == 0x45) { // E - увеличение линии

					double x3dd = (x1dd + x2dd) / 2;
					double y3dd = (y1dd + y2dd) / 2;

					// перемещаем в центр координат
					x1dd -= x3dd;
					x2dd -= x3dd;
					y1dd -= y3dd;
					y2dd -= y3dd;

					x1dd *= b;
					x2dd *= b;
					y1dd *= b;
					y2dd *= b;

					// перемещаем обратно
					x1dd += x3dd;
					x2dd += x3dd;
					y1dd += y3dd;
					y2dd += y3dd;

					clearviewport();
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "E" << std::endl;
				}
				if (s == 0x4D) { // M - показать меню действий
					ShowMenu();
					std::cout << "M" << std::endl;
				}
				if (s == 0x1B) { // ESC
					std::cout << "ESC" << std::endl;
					break;
				}
			}

		}
		if (k == 0x32) // 2 - действия над линией Брезенхэма
		{
			std::cout << "2" << std::endl;
			while (true) {
				char s = getch();
				if (s == 0x41) { // A - движение налево (x--)
					clearviewport();
					x1br--;
					x2br--;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "A" << std::endl;
				}
				if (s == 0x44) { // D - движение вправо (x++)
					clearviewport();
					x1br++;
					x2br++;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "D" << std::endl;
				}
				if (s == 0x57) { // W - движение вверх (y++) наоборот так как оси инвертированы
					clearviewport();
					y1br--;
					y2br--;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "W" << std::endl;
				}
				if (s == 0x53) { // S - движение вниз (y--)
					clearviewport();
					y1br++;
					y2br++;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "S" << std::endl;
				}
				if (s == 0x52) { // R - поворот линии

					double x3br = (x1br + x2br) / 2;
					double y3br = (y1br + y2br) / 2;

					// перемещаем в центр координат
					x1br -= x3br;
					x2br -= x3br;
					y1br -= y3br;
					y2br -= y3br;

					double xn1 = (x1br * cos(a) + y1br * sin(a));
					double yn1 = (-(x1br * sin(a)) + y1br * cos(a));

					double xn2 = (x2br * cos(a) + y2br * sin(a));
					double yn2 = (-(x2br * sin(a)) + y2br * cos(a));

					x1br = xn1;
					y1br = yn1;
					x2br = xn2;
					y2br = yn2;
					// перемещаем обратно k
					x1br += x3br;
					x2br += x3br;
					y1br += y3br;
					y2br += y3br;

					clearviewport();
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "R" << std::endl;
				}
				if (s == 0x51) { // Q - уменьшение линии

					double x3br = (x1br + x2br) / 2;
					double y3br = (y1br + y2br) / 2;

					// перемещаем в центр координат
					x1br -= x3br;
					x2br -= x3br;
					y1br -= y3br;
					y2br -= y3br;

					x1br /= b;
					x2br /= b;
					y1br /= b;
					y2br /= b;

					// перемещаем обратно
					x1br += x3br;
					x2br += x3br;
					y1br += y3br;
					y2br += y3br;

					clearviewport();
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "Q" << std::endl;
				}
				if (s == 0x45) { // E - увеличение линии

					double x3br = (x1br + x2br) / 2;
					double y3br = (y1br + y2br) / 2;

					// перемещаем в центр координат
					x1br -= x3br;
					x2br -= x3br;
					y1br -= y3br;
					y2br -= y3br;

					x1br *= b;
					x2br *= b;
					y1br *= b;
					y2br *= b;

					// перемещаем обратно
					x1br += x3br;
					x2br += x3br;
					y1br += y3br;
					y2br += y3br;

					clearviewport();
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // зеленая
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // фиолетовая
					std::cout << "E" << std::endl;
				}
				if (s == 0x4D) { // M - показать меню действий
					ShowMenu();
					std::cout << "M" << std::endl;
				}
				if (s == 0x1B) { // ESC
					std::cout << "ESC" << std::endl;
					break;
				}
			}
		}
		if (k == 0x1B) // ESC
		{
			std::cout << "ESC" << std::endl;
			break;
		}

	}
	closegraph(); // выход из графического режима
	return 0;
}

void SetLine(double x0, double y0, double x1, double y1, COLORREF color)
{
	setcolor(10);
	line(x0, y0, x1, y1);
}

// алгоритм Брезенхэма
void SetLineBrez(double x0, double y0, double x1, double y1, COLORREF color)
{
	int const deltaX = x1 - x0;
	int const deltaY = y1 - y0;
	int const absDeltaX = std::abs(deltaX);
	int const absDeltaY = std::abs(deltaY);

	int accretion = 0; // прирост

	if (absDeltaX >= absDeltaY)
	{
		int y = y0;
		const int direction = deltaY != 0 ? (deltaY > 0 ? 1 : -1) : 0;
		for (int x = x0; deltaX > 0 ? x <= x1 : x >= x1; deltaX > 0 ? x++ : x--)
		{
			putpixel(x, y, color);
			accretion += absDeltaY;

			if (accretion >= absDeltaX)
			{
				accretion -= absDeltaX;
				y += direction;
			}
		}
	}
	else
	{
		int x = x0;
		const int direction = deltaX != 0 ? (deltaX > 0 ? 1 : -1) : 0;
		for (int y = y0; deltaY > 0 ? y <= y1 : y >= y1; deltaY > 0 ? y++ : y--)
		{
			putpixel(x, y, color);
			accretion += absDeltaX;

			if (accretion >= absDeltaY)
			{
				accretion -= absDeltaY;
				x += direction;
			}
		}
	}
}

void ShowMenu()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "***Choose action***" << std::endl;
	std::cout << "1 - выбор 1 линии (зеленой)" << std::endl;
	std::cout << "2 - выбор 2 линии (фиолетовой)" << std::endl;
	std::cout << "A - движение влево" << std::endl;
	std::cout << "D - движение вправо" << std::endl;
	std::cout << "W - движение вверх" << std::endl;
	std::cout << "S - движение вниз" << std::endl;
	std::cout << "R - поворот выбранной линии" << std::endl;
	std::cout << "M - показать меню действий" << std::endl;
	std::cout << "E - увеличение линии" << std::endl;
	std::cout << "Q - уменьшение линии" << std::endl;
	std::cout << "ESC - возврат на пункт назад (если взаимодействовали с линией, то возвращаетесь в менб выбора линии" "\n" <<
		"Если находились в меню выбора линии, выходите из программы, окно уничтожается" << std::endl;
}