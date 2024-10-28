#include <iostream>
void move(int amount, int point1, int point2)
{
	std::cout << amount << " " << point1 << " " << point2;
	std::cout << std::endl;
}
void moveTower(int amount, int point1, int point2, int temp)
{
	if (amount == 0)
	{
		return;
	}
	moveTower(amount - 1, point1, temp, point2);
	move(amount, point1, point2);
	moveTower(amount - 1, temp, point2, point1);
}
void moveTower2(int amount, int point1, int point2, int temp)
{
	if (amount == 0)
	{
		return;
	}
	else if (amount < 3)
	{
		move(amount - 1, point1, point2);
		move(0, point1, point2);
		move(amount - 1, point1, point2);
	}
	else
	{
		if (amount == 0)
		{
			return;
		}
		move(1, point1, temp);
		move(0, point1, temp);
		move(1, point1, point2);
		move(2, temp, point1);
		move(1, point2, point1);
		moveTower(amount - 1, point1, temp, point2);
		move(amount, point1, point2);
		moveTower(amount - 1, temp, point2, point1);
	}
}
void main()
{
	int amount = 0;
	std::cin >> amount;
	moveTower2(amount, 1, 3, 2);
}