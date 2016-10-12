#pragma once
#include<iostream>
#include<math.h>

float const kEps = 1e-5;

class Space2D
{
public:

	Space2D(float x, float y) :m_x(x), m_y(y) {};
	Space2D() = default;
	Space2D(Space2D const & obj)
		: m_x(obj.m_x), m_y(obj.m_y)
	{};

	void setX(float x)
	{
		m_x = x;
	};
	void setY(float y)
	{
		m_y = y;
	};
	float getX()
	{
		return m_x;
	}
	float getY()
	{
		return m_y;
	}
	void addX(float x)
	{
		m_x += x;
	};
	void addY(float y)
	{
		m_y += y;
	};


	bool operator == (Space2D const & obj) const
	{
		return EqualWithEps(m_x, obj.m_x) && EqualWithEps(m_y, obj.m_y);
	}
	Space2D & operator = (Space2D const & obj)
	{
		if (this == &obj) return *this;
		m_x = obj.m_x;
		m_y = obj.m_y;
		return *this;
	}
	
private:

	bool EqualWithEps(float v1, float v2) const
	{
		return fabs(v1 - v2) < kEps;
	}
	float m_x = 0.0f, m_y = 0.0f;


};
