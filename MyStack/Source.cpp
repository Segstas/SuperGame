#include<iostream>
#include<conio.h>
#include "figures.h"
#include<ctime>

bool belongs(float a, float b, float c)
{
	if (a >= c)
		return (b <= a) && (b >= c);
	if (a <= c)
		return (b >= a) && (b <= c);
	return false;
}

bool intersection(Ray2D r, Box2D b)
{
	if (r.getDirectionX() > 0)
	{
		if (b.getRcornerX() < r.getOriginX())
			return false;
	}
	if (r.getDirectionX() < 0)
	{
		if (b.getLcornerX() > r.getOriginX())
			return false;
	}

	if (r.getDirectionY() > 0)
	{
		if (b.getRcornerY() < r.getOriginY())
			return false;
	}
	if (r.getDirectionY() < 0)
	{
		if (b.getLcornerY() > r.getOriginY())
			return false;
	}

	if (r.getDirectionX() == 0)
	{
		if (belongs(b.getLcornerX(), r.getOriginX(), b.getLcornerY()))
		{
			if (r.getDirectionY() > 0) 
				if (b.getRcornerY() >= r.getOriginY())
					return true;
			if (r.getDirectionY() < 0)
				if (b.getLcornerY() <= r.getOriginY())
					return true;
		}
	}
	if (r.getDirectionY() == 0)
	{
		if (belongs(b.getLcornerY(), r.getOriginY(), b.getLcornerY()))
		{
			if (r.getDirectionX() > 0)
				if (b.getRcornerX() >= r.getOriginX())
					return true;
			if (r.getDirectionX() < 0)
				if (b.getLcornerX() <= r.getOriginX())
					return true;
		}
	}

	float x0, y0, x1, y1;
	y0 = (b.getLcornerX() - r.getOriginX()) * r.getK();
	y1 = (b.getRcornerX() - r.getOriginX()) * r.getK();
	x0 = (b.getLcornerY() - r.getOriginY()) / r.getK();
	x1 = (b.getRcornerY() - r.getOriginY()) / r.getK();
	return belongs(b.getLcornerX(),x0, b.getRcornerX()) || belongs(b.getLcornerY(),y0, b.getRcornerY())
		|| belongs(b.getLcornerX(),x1, b.getRcornerX()) || belongs(b.getLcornerY(),y1, b.getRcornerY());
}
bool intersection(Box2D b1, Box2D b2)
{
	bool a1 = b1.getLcornerY() > b2.getRcornerY();
	bool a2 = b1.getRcornerY() < b2.getLcornerY();
	bool a3 = b1.getRcornerX() < b2.getLcornerX();
	bool a4 = b1.getLcornerX() > b2.getRcornerX();

	return (!(a1 || a2 || a3 || a4));
}


int main()
{
	char sign = 'a';
	Box2D box(5, 5, 6, 6);
	box.correctness();
	Box2D box1(1, 1, 2, 2);
	box1.correctness();
	Ray2D ray(0, 0, -1, 1);



	while (!(sign == '0'))
	{
		box.address();
		box1.address();
		int time1 = clock();
		if (intersection(box1, box))
		{
			std::cout << "intersection with box" << std::endl;

			break;
		}
		int time2 = clock();
		if (intersection(ray, box))
		{
			std::cout << "intersection with ray" << std::endl;

			break;
		}
		int time3 = clock();
		std::cout << (time2 - time1) * 1000 << "   " << (time3 - time1) * 1000 << std::endl;
		box.picture();
		sign = getch();
		system("cls");

		if (sign == 'w' || sign == 'W')
		{
			box.goForward(1);
		}
		if (sign == 's' || sign == 'S')
		{
			box.goBack(1);
		}
		if (sign == 'a' || sign == 'A')
		{
			box.goLeft(1);
		}
		if (sign == 'D' || sign == 'd')
		{
			box.goRight(1);
		}
	}


	_getch();
	return 0;
}