//#define _CRT_SECURE_NO_WARNINGS_
//#include <iostream>
//#include <math.h>
//#include <locale.h>
//#include "graphics.h"
//#pragma comment(lib,"graphics.lib")
//
//// треугольник 
//
//void SetLine(double x0, double y0, double x1, double y1, COLORREF color);
//void ShowMenu();
//
//float coordinati[3][3] = {
//	{255, 45, 1},
//	{47, 67, 1},
//	{100, 100, 1}
//};
//
//int main(void)
//{
//	setlocale(LC_ALL, "Russian");
//
//	initwindow(720, 480); // инициализация окна
//	float a = 0.05; // Угол в радианах на который вращаем
//	float b = 1.1; // Коэффициент маштабирования
//
//	SetLine(coordinati[0][0], coordinati[0][1], coordinati[1][0], coordinati[1][1], 13);
//	SetLine(coordinati[1][0], coordinati[1][1], coordinati[2][0], coordinati[2][1], 13);
//	SetLine(coordinati[2][0], coordinati[2][1], coordinati[0][0], coordinati[0][1], 13);
//	ShowMenu();
//
//	while (true)
//	{
//		char s = getch();
//		if (s == 0x41) { // A - движение налево (x--)
//			clearviewport();
//			for (int i = 0; i < 3; i++) {
//				coordinati[i][0]--;
//			}
//			SetLine(coordinati[0][0], coordinati[0][1], coordinati[1][0], coordinati[1][1], 13);
//			SetLine(coordinati[1][0], coordinati[1][1], coordinati[2][0], coordinati[2][1], 13);
//			SetLine(coordinati[2][0], coordinati[2][1], coordinati[0][0], coordinati[0][1], 13);
//			std::cout << "A" << std::endl;
//		}
//		if (s == 0x44) { // D - движение вправо (x++)
//			clearviewport();
//			for (int i = 0; i < 3; i++) {
//				coordinati[i][0]++;
//			}
//			SetLine(coordinati[0][0], coordinati[0][1], coordinati[1][0], coordinati[1][1], 13);
//			SetLine(coordinati[1][0], coordinati[1][1], coordinati[2][0], coordinati[2][1], 13);
//			SetLine(coordinati[2][0], coordinati[2][1], coordinati[0][0], coordinati[0][1], 13);
//			std::cout << "D" << std::endl;
//		}
//		if (s == 0x57) { // W - движение вверх (y++)
//			clearviewport();
//			for (int i = 0; i < 3; i++) {
//				coordinati[i][1]--;
//			}
//			SetLine(coordinati[0][0], coordinati[0][1], coordinati[1][0], coordinati[1][1], 13);
//			SetLine(coordinati[1][0], coordinati[1][1], coordinati[2][0], coordinati[2][1], 13);
//			SetLine(coordinati[2][0], coordinati[2][1], coordinati[0][0], coordinati[0][1], 13);
//			std::cout << "W" << std::endl;
//		}
//		if (s == 0x53) { // S - движение вниз (y--)
//			clearviewport();
//			for (int i = 0; i < 3; i++) {
//				coordinati[i][1]++;
//			}
//			SetLine(coordinati[0][0], coordinati[0][1], coordinati[1][0], coordinati[1][1], 13);
//			SetLine(coordinati[1][0], coordinati[1][1], coordinati[2][0], coordinati[2][1], 13);
//			SetLine(coordinati[2][0], coordinati[2][1], coordinati[0][0], coordinati[0][1], 13);
//			std::cout << "S" << std::endl;
//		}
//		if (s == 0x52) { // R - поворот 
//			// координаты центра треугольника
//			double x = (coordinati[0][0] + coordinati[1][0] + coordinati[2][0]) / 3;
//			double y = (coordinati[0][1] + coordinati[1][1] + coordinati[2][1]) / 3;
//
//			// перемещаем в центр координат
//			coordinati[0][0] -= x;
//			coordinati[1][0] -= x;
//			coordinati[2][0] -= x;
//			coordinati[0][1] -= y;
//			coordinati[1][1] -= y;
//			coordinati[2][1] -= y;
//			// поворот линий
//			
//			double x1 = (coordinati[0][0] * cos(a) + coordinati[0][1] * sin(a));
//			double x2 = (coordinati[1][0] * cos(a) + coordinati[1][1] * sin(a));
//			double x3 = (coordinati[2][0] * cos(a) + coordinati[2][1] * sin(a));
//
//			double y1 = (-(coordinati[0][0] * sin(a)) + coordinati[0][1] * cos(a));
//			double y2 = (-(coordinati[1][0] * sin(a)) + coordinati[1][1] * cos(a));
//			double y3 = (-(coordinati[2][0] * sin(a)) + coordinati[2][1] * cos(a));
//
//			coordinati[0][0] = x1;
//			coordinati[1][0] = x2;
//			coordinati[2][0] = x3;
//			coordinati[0][1] = y1;
//			coordinati[1][1] = y2;
//			coordinati[2][1] = y3;
//			// перемещаем обратно
//			coordinati[0][0] += x;
//			coordinati[1][0] += x;
//			coordinati[2][0] += x;
//			coordinati[0][1] += y;
//			coordinati[1][1] += y;
//			coordinati[2][1] += y;
//
//			clearviewport();
//			SetLine(coordinati[0][0], coordinati[0][1], coordinati[1][0], coordinati[1][1], 13);
//			SetLine(coordinati[1][0], coordinati[1][1], coordinati[2][0], coordinati[2][1], 13);
//			SetLine(coordinati[2][0], coordinati[2][1], coordinati[0][0], coordinati[0][1], 13);
//			
//			std::cout << "R" << std::endl;
//		}
//		if (s == 0x51) { // Q - уменьшение 
//			// координаты центра треугольника
//			double x = (coordinati[0][0] + coordinati[1][0] + coordinati[2][0]) / 3;
//			double y = (coordinati[0][1] + coordinati[1][1] + coordinati[2][1]) / 3;
//
//			// перемещаем в центр координат
//			coordinati[0][0] -= x;
//			coordinati[1][0] -= x;
//			coordinati[2][0] -= x;
//			coordinati[0][1] -= y;
//			coordinati[1][1] -= y;
//			coordinati[2][1] -= y;
//			// уменьшаем
//			coordinati[0][0] /= b;
//			coordinati[1][0] /= b;
//			coordinati[2][0] /= b;
//			coordinati[0][1] /= b;
//			coordinati[1][1] /= b;
//			coordinati[2][1] /= b;
//
//			// перемещаем обратно
//			coordinati[0][0] += x;
//			coordinati[1][0] += x;
//			coordinati[2][0] += x;
//			coordinati[0][1] += y;
//			coordinati[1][1] += y;
//			coordinati[2][1] += y;
//
//			clearviewport();
//			SetLine(coordinati[0][0], coordinati[0][1], coordinati[1][0], coordinati[1][1], 13);
//			SetLine(coordinati[1][0], coordinati[1][1], coordinati[2][0], coordinati[2][1], 13);
//			SetLine(coordinati[2][0], coordinati[2][1], coordinati[0][0], coordinati[0][1], 13);
//			
//			std::cout << "Q" << std::endl;
//		}
//		if (s == 0x45) { // E - увеличение 
//
//			// координаты центра треугольника
//			double x = (coordinati[0][0] + coordinati[1][0] + coordinati[2][0]) / 3;
//			double y = (coordinati[0][1] + coordinati[1][1] + coordinati[2][1]) / 3;
//
//			// перемещаем в центр координат
//			coordinati[0][0] -= x;
//			coordinati[1][0] -= x;
//			coordinati[2][0] -= x;
//			coordinati[0][1] -= y;
//			coordinati[1][1] -= y;
//			coordinati[2][1] -= y;
//			// увеличиваем
//			coordinati[0][0] *= b;
//			coordinati[1][0] *= b;
//			coordinati[2][0] *= b;
//			coordinati[0][1] *= b;
//			coordinati[1][1] *= b;
//			coordinati[2][1] *= b;
//
//			// перемещаем обратно
//			coordinati[0][0] += x;
//			coordinati[1][0] += x;
//			coordinati[2][0] += x;
//			coordinati[0][1] += y;
//			coordinati[1][1] += y;
//			coordinati[2][1] += y;
//
//			clearviewport();
//			SetLine(coordinati[0][0], coordinati[0][1], coordinati[1][0], coordinati[1][1], 13);
//			SetLine(coordinati[1][0], coordinati[1][1], coordinati[2][0], coordinati[2][1], 13);
//			SetLine(coordinati[2][0], coordinati[2][1], coordinati[0][0], coordinati[0][1], 13);
//		
//			std::cout << "E" << std::endl;
//		}
//		if (s == 0x4D) { // M - показать меню действий
//			ShowMenu();
//			std::cout << "M" << std::endl;
//		}
//		if (s == 0x1B) { // ESC
//			std::cout << "ESC" << std::endl;
//			break;
//		}
//	}
//	closegraph(); // выход из графического режима
//	return 0;
//}
//
//void SetLine(double x0, double y0, double x1, double y1, COLORREF color)
//{
//	setcolor(13);
//	line(x0, y0, x1, y1);
//}
//
//void ShowMenu()
//{
//	setlocale(LC_ALL, "Russian");
//	std::cout << "***Choose action***" << std::endl;
//	std::cout << "A - движение влево" << std::endl;
//	std::cout << "D - движение вправо" << std::endl;
//	std::cout << "W - движение вверх" << std::endl;
//	std::cout << "S - движение вниз" << std::endl;
//	std::cout << "R - поворот" << std::endl;
//	std::cout << "M - показать меню действий" << std::endl;
//	std::cout << "E - увеличение" << std::endl;
//	std::cout << "Q - уменьшение" << std::endl;
//	std::cout << "ESC - выход из программы" << std::endl;
//}