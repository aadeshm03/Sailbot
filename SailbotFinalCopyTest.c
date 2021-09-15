#pragma once

#include "pch.h"
#include "Header.h"


TEST(TestboundTo180, Zerotest) {
	float angle = 360;
	angle = boundTo180(angle);
	EXPECT_EQ(angle, 0);
}

TEST(TestboundTo180, Boundtest) {
	float angle = 180;
	angle = boundTo180(angle);
	EXPECT_EQ(angle, -180);
}

TEST(TestboundTo180, AlternateBoundTest) {
	float angle = -180;
	angle = boundTo180(angle);
	EXPECT_EQ(angle, -180);
}

TEST(TestboundTo180, Negativetest) {
	float angle = -6785;
	angle = boundTo180(angle);
	EXPECT_EQ(angle, 55);
}

TEST(TestboundTo180, PositiveTest) {
	float angle = 4698;
	angle = boundTo180(angle);
	EXPECT_EQ(angle, 18);
}

TEST(TestboundTo180, Test) {
	float angle = 30;
	angle = boundTo180(angle);
	EXPECT_EQ(angle, 30);
}

TEST(TestboundTo180, UnchangedTest) {
	float angle = -178;
	angle = boundTo180(angle);
	EXPECT_EQ(angle, -178);
}
//  EXPECT_TRUE(true);

//Tests for bool function
TEST(TestisAngleBetween, Firsttest) 
{
	float firstangle = 375;
	float secondangle = 500;
	float middleangle = 70;
	EXPECT_TRUE(isAngleBetween(firstangle, middleangle, secondangle));
}

//Outside bounds case
TEST(TestisAngleBetween, Secondtest)
{
	float firstangle = 375;
	float secondangle = 500;
	float middleangle = 550;
	EXPECT_FALSE(isAngleBetween(firstangle, middleangle, secondangle));
}

TEST(TestisAngleBetween, ThirdTest)
{
	float firstangle = -456;
	float secondangle = 789;
	float middleangle = 345;
	EXPECT_TRUE(isAngleBetween(firstangle, middleangle, secondangle));
}

TEST(TestisAngleBetween, FourthTest)
{
	float firstangle = 5;
	float secondangle = 350;
	float middleangle = 360;
	EXPECT_TRUE(isAngleBetween(firstangle, middleangle, secondangle));
}

//Checks for 180 degrees case
TEST(TestisAngleBetween, FifthTest)
{
	float firstangle = 0;
	float secondangle = 180;
	float middleangle = 47;
	EXPECT_FALSE(isAngleBetween(firstangle, middleangle, secondangle));
}

