#pragma once
#include "Space2D.h"
 

class Box2D :public Space2D
{
public:
	Box2D(float x, float y, float x1, float y1) :m_Lcorner(x, y), m_Rcorner(x1, y1) {};
	Box2D() = default;
	Box2D(float x, float y) : m_Lcorner(0.0f, 0.0f), m_Rcorner(x, y) {};
	void correctness()
	{
		while (m_Lcorner.getX() == m_Rcorner.getX())
		{
			std::cout << "enter another X for corner" << std::endl;
			float a;
			std::cin >> a;
			m_Rcorner.setX(a);
		}
		while (m_Lcorner.getY() == m_Rcorner.getY())
		{
			std::cout << "enter another Y for corner" << std::endl;
			float a;
			std::cin >> a;
			m_Rcorner.setY(a);
		}
		while (m_Lcorner.getX() > m_Rcorner.getX())
		{
			float a = m_Lcorner.getX();
			m_Lcorner.setX(m_Rcorner.getX());
			m_Rcorner.setX(a);
		}
		while (m_Lcorner.getY() > m_Rcorner.getY())
		{
			float a = m_Lcorner.getY();
			m_Lcorner.setY(m_Rcorner.getY());
			m_Rcorner.setY(a);
		}

	}

	double getLength()
	{
		return (m_Rcorner.getX() - m_Lcorner.getX());
	};
	double getWidth()
	{
		return (m_Rcorner.getX() - m_Lcorner.getX());
	};

	void goForward(float a)
	{
		m_Lcorner.addY(a);
		m_Rcorner.addY(a);
	}
	void goBack(float a)
	{
		m_Lcorner.addY(-a);
		m_Rcorner.addY(-a);
	}
	void goRight(float a)
	{
		m_Lcorner.addX(a);
		m_Rcorner.addX(a);
	}
	void goLeft(float a)
	{
		m_Lcorner.addX(-a);
		m_Rcorner.addX(-a);
	}

	void setLcorner(float x, float y)
	{
		m_Lcorner = { x, y };
	}
	void setRcorner(float x, float y)
	{
		m_Rcorner = { x, y };
	}

	float getLcornerX()
	{
		return m_Lcorner.getX();
	}
	float getLcornerY()
	{
		return m_Lcorner.getY();
	}
	float getRcornerX()
	{
		return m_Rcorner.getX();
	}
	float getRcornerY()
	{
		return m_Rcorner.getY();
	}
	void address()
	{
		std::cout << " {" << getLcornerX() << ", " << getLcornerY()<< "}     " ;
		std::cout << " {" << getRcornerX() << ", " << getRcornerY() << "}" << std::endl;

	}

	void picture()
	{
		for (int i = 0; i < 50 - m_Lcorner.getY(); i++)
			std::cout << std::endl;
		for (int j = 0; j < getWidth(); j++)
		{
			for (int i = 0; i < m_Rcorner.getX(); i++)
			{
				std::cout << " ";
			}
			for (int i = 0; i < getLength(); i++)
			{
				std::cout << "|";
			}
			std::cout << std::endl;
		}
	}

private:
	Space2D m_Lcorner, m_Rcorner;

};

class Ray2D :public Space2D
{
public:

	Ray2D(float x0, float y0, float x, float y) :m_origin(x0, y0), m_direction(x / sqrt(x*x + y*y), y / sqrt(x*x + y*y)) {};
	Ray2D() = default;
	Ray2D(float x, float y) :m_origin(0.0f, 0.0f), m_direction(x / sqrt(x*x + y*y), y / sqrt(x*x + y*y)) {};

	float getOriginX()
	{
		return m_origin.getX();
	}
	float getOriginY()
	{
		return m_origin.getY();
	}

	float getDirectionX()
	{
		return m_direction.getX();
	}
	float getDirectionY()
	{
		return m_direction.getY();
	}
	float getK()
	{
		updateK();
		return m_k;
	}
	void updateK()
	{
		m_k = (m_direction.getY()) / (m_direction.getX());
	}

	float Fy(float x)
	{
		int a = (getK() * (x - m_origin.getX())) + m_origin.getY();
		return a;
	}
	float Fx(float y)
	{
		return (y - m_origin.getY()) / getK() + m_origin.getX();
	}
private:
	Space2D m_origin, m_direction;
	float m_k = 0.0f;
};

