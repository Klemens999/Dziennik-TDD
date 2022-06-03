#include "pch.h"
#include "Dziennik.hpp"

TEST(BasicGLogTest, CanReturnClassAverage) {
	GLog sut{};
	Student s1{ "Marek","Stanko" };
	Student s2{ "Andrzej","Kowal" };

	sut.addStudent(s1);
	sut.addStudent(s2);
	sut.addGrade(s1, 5);
	sut.addGrade(s1, 2);
	sut.addGrade(s2, 3);
	sut.addGrade(s2, 3);

	auto result = sut.returnClassAverage();
	auto average = 3.25;
	
	EXPECT_EQ(result, average);
}

TEST(BasicGLogTest, CanReturnAverage) {
	GLog sut{};
	Student s1{ "Marek","Stanko" };
	Student s2{ "Andrzej","Kowal" };

	sut.addStudent(s1);
	sut.addStudent(s2);
	sut.addGrade(s1, 5);
	sut.addGrade(s1, 2);
	sut.addGrade(s2, 3);
	sut.addGrade(s2, 3);

	auto result1 = sut.returnAverage(s1);
	auto result2 = sut.returnAverage(s2);
	auto s1average = 3.5;
	auto s2average = 3;

	EXPECT_EQ(result1, s1average);
	EXPECT_EQ(result2, s2average);
}

TEST(BasicGLogTest, CanReturnGrades) {
	GLog sut{};
	Student s1{ "Marek","Stanko" };
	Student s2{ "Andrzej","Kowal" };

	sut.addStudent(s1);
	sut.addStudent(s2);
	sut.addGrade(s1, 5);
	sut.addGrade(s1, 2);
	sut.addGrade(s2, 3);
	sut.addGrade(s2, 3);

	auto result1 = sut.returnGrades(s1);
	auto result2 = sut.returnGrades(s2);
	std::vector<double> s1grades{ 5,2 };
	std::vector<double> s2grades{ 3,3 };
	
	EXPECT_EQ(result1, s1grades);
	EXPECT_EQ(result2, s2grades);
}

TEST(BasicGLogTest, CanReturnStudents) {
	GLog sut{};
	Student s1{"Marek","Stanko"};
	Student s2{"Andrzej","Kowal"};

	sut.addStudent(s1);
	sut.addStudent(s2);
	std::vector<Student> studentVec{s1, s2};
	auto result = sut.getStudents();

	EXPECT_EQ(result, studentVec);
}

TEST(BasicGLogTest, CanDeleteStudent) {
	GLog sut{};
	Student s{};

	sut.addStudent(s);
	sut.deleteStudent(s);

	EXPECT_TRUE(sut.isEmpty());
}


TEST(BasicGLogTest, CanAddStudent) {
	GLog sut{};
	Student s{};

	EXPECT_TRUE(sut.isEmpty());
	
	sut.addStudent(s);
	EXPECT_FALSE(sut.isEmpty());
}













/*
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
*/
