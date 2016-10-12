#include "gtest/gtest.h"
#include "figures.h"



TEST(space2d_test, test_construction)
{
	// Тест на создание объекта по умолчанию.
	Space2D p1;
	EXPECT_EQ(p1.getX(), 0.0f);
	EXPECT_EQ(p1.getY(), 0.0f);
	// Тест на создание объекта с параметрами.
	Space2D p2 = { 1.2f, 2.4f };
	EXPECT_EQ(p2.getX(), 1.2f);
	EXPECT_EQ(p2.getY(), 2.4f);
	// Тест на создание копии объекта.
	Space2D p3 = p2;
	EXPECT_EQ(p3, p2);
}
TEST(space2d_test, test_assignment)
{
	Space2D p1;
	p1 = { 1.2f, 2.4f };
	EXPECT_EQ(p1, Space2D(1.2f, 2.4f));
}


TEST(box2d_test, test_constuction)
{
	// Тест на создание объекта по умолчанию.
	Box2D b1;
	EXPECT_EQ(b1.getLcornerX(), 0.0f);
	EXPECT_EQ(b1.getLcornerY(), 0.0f);
	EXPECT_EQ(b1.getRcornerX(), 0.0f);
	EXPECT_EQ(b1.getRcornerY(), 0.0f);
	// Тест на создание объекта с параметрами.
	Box2D b2 = { 1.2f, 2.4f };
	EXPECT_EQ(b2.getLcornerX(), 0.0f);
	EXPECT_EQ(b2.getLcornerY(), 0.0f);
	EXPECT_EQ(b2.getRcornerX(), 1.2f);
	EXPECT_EQ(b2.getRcornerY(), 2.4f);

	Box2D b3(1.2f, 2.0f, 3.2f, 1.0f);
	EXPECT_EQ(b3.getLcornerX(), 1.2f);
	EXPECT_EQ(b3.getLcornerY(), 2.0f);
	EXPECT_EQ(b3.getRcornerX(), 3.2f);
	EXPECT_EQ(b3.getRcornerY(), 1.0f);

	// Тест на создание копии объекта.
	Box2D b4 = b2;
	EXPECT_EQ(b4, b2);
}
TEST(ray2d_test, test_construction)
{
	// Тест на создание объекта по умолчанию.
	Ray2D r1;
	EXPECT_EQ(r1.getOriginX(), 0.0f);
	EXPECT_EQ(r1.getOriginY(), 0.0f);
	// Тест на создание объекта с параметрами.
	Ray2D r2(1.0f, 2.0f);
	EXPECT_EQ(r2.getOriginX(), 0.0f);
	EXPECT_EQ(r2.getOriginY(), 0.0f);
	EXPECT_EQ(r2.getDirectionX(), 1.0f / sqrt(1.0f*1.0f + 2.0f*2.0f));
	EXPECT_EQ(r2.getDirectionY(), 2.0f / sqrt(1.0f*1.0f + 2.0f*2.0f));
	
}

