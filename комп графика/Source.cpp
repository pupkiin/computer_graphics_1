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
	initwindow(720, 480); // ������������� ����
	float a = 0.05; // ���� � �������� �� ������� �������
	float b = 1.1; // ����������� ��������������

	// ���������� �����
	double x1dd = 10;
	double y1dd = 40;
	double x2dd = 50;
	double y2dd = 90;
	// ���������� ����� ��� ���. ����������
	double x1br = 80;
	double y1br = 100;
	double x2br = 600;
	double y2br = 159;

	SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
	SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
	ShowMenu();

	while (true)
	{
		char k = getch();
		if (k == 0x31) // 1 - �������� ��� ����� ������
		{
			std::cout << "1" << std::endl;
			while (true) {
				char s = getch();
				if (s == 0x41) { // A - �������� ������ (x--)
					clearviewport();
					x1dd--;
					x2dd--;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "A" << std::endl;
				}
				if (s == 0x44) { // D - �������� ������ (x++)
					clearviewport();
					x1dd++;
					x2dd++;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "D" << std::endl;
				}
				if (s == 0x57) { // W - �������� ����� (y++)
					clearviewport();
					y1dd--;
					y2dd--;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "W" << std::endl;
				}
				if (s == 0x53) { // S - �������� ���� (y--)
					clearviewport();
					y1dd++;
					y2dd++;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "S" << std::endl;
				}
				if (s == 0x52) { // R - ������� �����

					double x3dd = (x1dd + x2dd) / 2;
					double y3dd = (y1dd + y2dd) / 2;

					/*int xn1 = static_cast<int>(-sin(a) * (y1dd - y3dd) + cos(a) * (x1dd - x3dd) + x3dd);
					int yn1 = static_cast<int>(cos(a) * (y1dd - y3dd) + sin(a) * (x1dd - x3dd) + y3dd);

					int xn2 = static_cast<int>(-sin(a) * (y2dd - y3dd) + cos(a) * (x2dd - x3dd) + x3dd);
					int yn2 = static_cast<int>(cos(a) * (y2dd - y3dd) + sin(a) * (x2dd - x3dd) + y3dd);*/

					// ���������� � ����� ���������
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
					// ���������� �������
					x1dd += x3dd;
					x2dd += x3dd;
					y1dd += y3dd;
					y2dd += y3dd;

					clearviewport();
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "R" << std::endl;
				}
				if (s == 0x51) { // Q - ���������� �����

					double x3dd = (x1dd + x2dd) / 2;
					double y3dd = (y1dd + y2dd) / 2;

					// ���������� � ����� ���������
					x1dd -= x3dd;
					x2dd -= x3dd;
					y1dd -= y3dd;
					y2dd -= y3dd;

					x1dd /= b;
					x2dd /= b;
					y1dd /= b;
					y2dd /= b;

					// ���������� �������
					x1dd += x3dd;
					x2dd += x3dd;
					y1dd += y3dd;
					y2dd += y3dd;

					clearviewport();
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "Q" << std::endl;
				}
				if (s == 0x45) { // E - ���������� �����

					double x3dd = (x1dd + x2dd) / 2;
					double y3dd = (y1dd + y2dd) / 2;

					// ���������� � ����� ���������
					x1dd -= x3dd;
					x2dd -= x3dd;
					y1dd -= y3dd;
					y2dd -= y3dd;

					x1dd *= b;
					x2dd *= b;
					y1dd *= b;
					y2dd *= b;

					// ���������� �������
					x1dd += x3dd;
					x2dd += x3dd;
					y1dd += y3dd;
					y2dd += y3dd;

					clearviewport();
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "E" << std::endl;
				}
				if (s == 0x4D) { // M - �������� ���� ��������
					ShowMenu();
					std::cout << "M" << std::endl;
				}
				if (s == 0x1B) { // ESC
					std::cout << "ESC" << std::endl;
					break;
				}
			}

		}
		if (k == 0x32) // 2 - �������� ��� ������ ����������
		{
			std::cout << "2" << std::endl;
			while (true) {
				char s = getch();
				if (s == 0x41) { // A - �������� ������ (x--)
					clearviewport();
					x1br--;
					x2br--;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "A" << std::endl;
				}
				if (s == 0x44) { // D - �������� ������ (x++)
					clearviewport();
					x1br++;
					x2br++;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "D" << std::endl;
				}
				if (s == 0x57) { // W - �������� ����� (y++) �������� ��� ��� ��� �������������
					clearviewport();
					y1br--;
					y2br--;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "W" << std::endl;
				}
				if (s == 0x53) { // S - �������� ���� (y--)
					clearviewport();
					y1br++;
					y2br++;
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "S" << std::endl;
				}
				if (s == 0x52) { // R - ������� �����

					double x3br = (x1br + x2br) / 2;
					double y3br = (y1br + y2br) / 2;

					// ���������� � ����� ���������
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
					// ���������� ������� k
					x1br += x3br;
					x2br += x3br;
					y1br += y3br;
					y2br += y3br;

					clearviewport();
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "R" << std::endl;
				}
				if (s == 0x51) { // Q - ���������� �����

					double x3br = (x1br + x2br) / 2;
					double y3br = (y1br + y2br) / 2;

					// ���������� � ����� ���������
					x1br -= x3br;
					x2br -= x3br;
					y1br -= y3br;
					y2br -= y3br;

					x1br /= b;
					x2br /= b;
					y1br /= b;
					y2br /= b;

					// ���������� �������
					x1br += x3br;
					x2br += x3br;
					y1br += y3br;
					y2br += y3br;

					clearviewport();
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "Q" << std::endl;
				}
				if (s == 0x45) { // E - ���������� �����

					double x3br = (x1br + x2br) / 2;
					double y3br = (y1br + y2br) / 2;

					// ���������� � ����� ���������
					x1br -= x3br;
					x2br -= x3br;
					y1br -= y3br;
					y2br -= y3br;

					x1br *= b;
					x2br *= b;
					y1br *= b;
					y2br *= b;

					// ���������� �������
					x1br += x3br;
					x2br += x3br;
					y1br += y3br;
					y2br += y3br;

					clearviewport();
					SetLine(x1dd, y1dd, x2dd, y2dd, 10); // �������
					SetLineBrez(x1br, y1br, x2br, y2br, 13); // ����������
					std::cout << "E" << std::endl;
				}
				if (s == 0x4D) { // M - �������� ���� ��������
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
	closegraph(); // ����� �� ������������ ������
	return 0;
}

void SetLine(double x0, double y0, double x1, double y1, COLORREF color)
{
	setcolor(10);
	line(x0, y0, x1, y1);
}

// �������� ����������
void SetLineBrez(double x0, double y0, double x1, double y1, COLORREF color)
{
	int const deltaX = x1 - x0;
	int const deltaY = y1 - y0;
	int const absDeltaX = std::abs(deltaX);
	int const absDeltaY = std::abs(deltaY);

	int accretion = 0; // �������

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
	std::cout << "1 - ����� 1 ����� (�������)" << std::endl;
	std::cout << "2 - ����� 2 ����� (����������)" << std::endl;
	std::cout << "A - �������� �����" << std::endl;
	std::cout << "D - �������� ������" << std::endl;
	std::cout << "W - �������� �����" << std::endl;
	std::cout << "S - �������� ����" << std::endl;
	std::cout << "R - ������� ��������� �����" << std::endl;
	std::cout << "M - �������� ���� ��������" << std::endl;
	std::cout << "E - ���������� �����" << std::endl;
	std::cout << "Q - ���������� �����" << std::endl;
	std::cout << "ESC - ������� �� ����� ����� (���� ����������������� � ������, �� ������������� � ���� ������ �����" "\n" <<
		"���� ���������� � ���� ������ �����, �������� �� ���������, ���� ������������" << std::endl;
}