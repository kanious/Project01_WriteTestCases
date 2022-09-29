#include <iostream>
#include "gtest/gtest.h"

#include "WhiteTests.h"
#include "BlackBox.h"

using namespace std;

// ------------- White Tests -------------
TEST(WHITE_01, Square)
{
	EXPECT_EQ(4, Square(2));
	EXPECT_EQ(9, Square(3));
	EXPECT_EQ(16, Square(4));
	EXPECT_EQ(25, Square(5));
	EXPECT_EQ(36, Square(6));
	EXPECT_EQ(4096, Square(64));
	EXPECT_EQ(65536, Square(256));
}
TEST(WHITE_02, Round_HalfUp)
{
	EXPECT_EQ(158460, RoundHalfUp(1, 158459));
	EXPECT_EQ(158500, RoundHalfUp(2, 158459));
	EXPECT_EQ(158000, RoundHalfUp(3, 158459));
	EXPECT_EQ(160000, RoundHalfUp(4, 158459));
	EXPECT_EQ(200000, RoundHalfUp(5, 158459));
}
TEST(WHITE_03, Rectangle_Area)
{
	EXPECT_EQ(50, RectangleArea(5, 10));
	EXPECT_EQ(10000, RectangleArea(100, 100));
	EXPECT_EQ(2400, RectangleArea(75, 32));
	EXPECT_EQ(-10500, RectangleArea(-12, 875));
}
TEST(WHITE_04, Hour_To_Second)
{
	EXPECT_EQ(3600, HourToSec(1));
	EXPECT_EQ(86400, HourToSec(24));
	EXPECT_EQ(604800, HourToSec(168));
	EXPECT_EQ(31536000, HourToSec(8760));
}
TEST(WHITE_05, Count_Aliquot)
{
	EXPECT_EQ(4, CountAliquot(10));
	EXPECT_EQ(4, CountAliquot(125));
	EXPECT_EQ(64, CountAliquot(10000000));
	EXPECT_EQ(81, CountAliquot(100000000));
}

// ------------- Black Tests -------------
TEST(BLACK_01, Vector_Magnitude)
{
	ASSERT_EQ(3.742f, VectorMagnitude(1.f, 2.f, 3.f));
	ASSERT_EQ(7.483f, VectorMagnitude(2.f, 4.f, 6.f));
	ASSERT_EQ(1.732f, VectorMagnitude(1.f, 1.f, 1.f));
	ASSERT_EQ(9.014f, VectorMagnitude(5.f, 0.f, 7.5f));
}
TEST(BLACK_02, Biggest_Number)
{
	EXPECT_EQ(10, BiggestNum(2, 1, 10));
	EXPECT_EQ(1005, BiggestNum(8, 23, 84, 109, 55, 462, 48, 94, 1005));
	EXPECT_EQ(10000, BiggestNum(5, 10000, 1000, 100, 10, 1));
	EXPECT_EQ(-45, BiggestNum(5, -51,-45,-68,-210,-9000));
	EXPECT_EQ(0, BiggestNum(5, -51, -45, -68, -210, 0));
}
TEST(BLACK_03, Flip_Number)
{
	EXPECT_EQ(5, FlipNumber(5));
	EXPECT_EQ(12, FlipNumber(21));
	EXPECT_EQ(654321, FlipNumber(123456));
	EXPECT_EQ(987654321, FlipNumber(123456789));
}
TEST(BLACK_04, Count_Space)
{
	EXPECT_EQ(0, CountSpace("Hello"));
	EXPECT_EQ(2, CountSpace("How are you?"));
	EXPECT_EQ(4, CountSpace("This is space a counter!"));
}
TEST(BLACK_05, String_Compare)
{
	EXPECT_EQ(true, StringCompare("ABCD", "ABCD"));
	EXPECT_EQ(false, StringCompare("ABCD", "abcd"));
	EXPECT_EQ(false, StringCompare("ABCD", "EFGH"));
	EXPECT_EQ(false, StringCompare("ABCD", "aBcD"));
	EXPECT_EQ(true, StringCompare("Hello, world!", "Hello, world!"));
	//EXPECT_STREQ("ABCD", "ABCD");
	//EXPECT_STRNE("ABCD", "EFGH");
	//EXPECT_STRCASEEQ("IJKL", "ijkl");
	//EXPECT_STRCASENE("MNOP", "nmop");
}

// ------------- main -------------
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);

	char ch = NULL;
	do
	{
		cout << "1.TEST 2.QUIT >";
		cin >> ch;

		if (ch == '1')
		{
			RUN_ALL_TESTS();
		}

	} while (ch != '2');

	return 0;
}