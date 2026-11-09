#include <stdio.h>
#include <locale.h>
#include <math.h>

#define ROW 10
int check(double x, double y);
void paint();

int main() 
{
	setlocale(LC_ALL, ".utf-8");
	double x, y;
	int num;

	printf("Введите 1 - Если хотите проверить лежит ли точка в области\n"
		"Введите 2 - Если хотите вывести фигуру\n"
		"Введите 0 - Чтобы завершить программу\n");
	scanf("%d", &num);

	while (num != 0) 
	{
		switch (num) 
		{
		case 1:
			puts("Введи x y: ");
			scanf("%lf %lf", &x, &y);

			double r = sqrt(pow(x, 2) + pow(y, 2));

			if (check(x, y) == 1) {
				printf("Радиус = %.2lf. Точка (%.2lf, %.2lf) принадлежит области\n", r, x, y);
			}
			else {
				printf("Радиус = %.2lf. Точка (%.2lf, %.2lf) не принадлежит области\n", r, x, y);
			}
			break;

		case 2:
			paint();
			break;

		default:
			puts("Введено неверное число\n");
		}

		puts("Что дальше?\n");
		scanf("%d", &num);
	}

	return 0;
}

int check(double x, double y)
{
	double r = sqrt(pow(x, 2) + pow(y, 2));
	int state = (r <= 1.0) || (r >= 2.0 && r <= 3.0);
	return state;
}

void paint()
{
	for (int row = 5; row >= -5; row--) //по строкам сверху вниз (от 5 до -5)
	{

		for (int col = -10; col <= 10; col++) //по столбцам слева направо (от -10 до 10)
		{

			double x = col * 0.5; //делим на 2 для ровных кругов
			double y = row;

			if (check(x, y))
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
	}
}