#include "pch.h"
#include "Dziennik.hpp"
#include <cstring>

class GLogTest : public ::testing::Test{
public:
	GLog sut{};
	Student s1{ "Marek","Stanko" };
	Student s2{ "Andrzej","Kowal" };

	void SetUp() override{
		sut.addStudent("Marek","Stanko", {5,2});
		sut.addStudent("Andrzej", "Kowal", {3,3});
	}
};

TEST(CornerCase, CanAddNamelessStudent) {
	GLog sut{};
	std::string a, b;
	EXPECT_THROW({ sut.addStudent(a, b); }, std::invalid_argument);
}

TEST_F(GLogTest, CannotAddEmptyGrade) {
	GLog sut{};
	int grade{};
	EXPECT_THROW({ sut.addGrade("Marek", "Stanko", grade); }, std::invalid_argument);
}

TEST_F(GLogTest, CannotDeleteNonExistentStudent) {
	EXPECT_THROW({ sut.deleteStudent("Artur", "Kos"); }, std::invalid_argument);
}

//dodaj tego samego studenta - jezeli z ocenami-dodaj same oceny chyba ze sa te same ktore juz istnieja
//rzucony exception
TEST_F(GLogTest, AddingStudentWithExistingGradesAddsOnlyNonexitingGrades) {
	sut.addStudent("Marek", "Stanko", { 3,3 });
	auto result1 = sut.returnGrades("Marek", "Stanko");
	std::vector<double> s1grades{ 5,2,3,3 };

	EXPECT_EQ(s1grades, result1);

	EXPECT_THROW({ sut.addStudent("Marek", "Stanko", { 5,2,3,3 }); }, std::invalid_argument);
		
}



TEST_F(GLogTest, CannotChangeNonexistingGrade) {
	EXPECT_THROW({sut.changeGrade("Marek","Stanko", 4,5);},std::out_of_range);
}

TEST_F(GLogTest, CanAddStudentWithCstring ) {
	const char name[]("Marekk");
	const char surname[]("Stanwwko");
	sut.addStudent(name, surname);
	EXPECT_NO_THROW(sut.deleteStudent(name, surname));
}


//case'y z polowicznymi ocenami typu 3,5
TEST_F(GLogTest, CanAddGradesPoint5) {
	sut.addGrade("Marek", "Stanko", 3.5);
	auto result1 = sut.returnGrades("Marek", "Stanko");
	std::vector<double> s1grades{ 5,2,3.5 };

	EXPECT_EQ(s1grades, result1);
	EXPECT_THROW({ sut.addGrade("Marek","Stanko", 3.76); }, std::invalid_argument);

}

TEST_F(GLogTest, CanChangeGrade) {
	sut.changeGrade("Marek","Stanko", 1, 3);
	std::vector<double> changedGrades{ 5,3 };
	std::vector<double> result = sut.returnGrades("Marek", "Stanko");

	EXPECT_EQ(changedGrades, result);
}

TEST_F(GLogTest, CanReturnBestAndWorstStudent) {
	auto best = sut.returnBestStudent();
	auto worst = sut.returnWorstStudent();

	EXPECT_EQ(best, s1);
	EXPECT_EQ(worst, s2);
}

TEST_F(GLogTest, CanReturnClassAverage) {
	double result = sut.returnClassAverage();
	double average = 3.25;
	
	EXPECT_EQ(result, average);
}

TEST_F(GLogTest, CanReturnAverage) {
	auto result1 = sut.returnAverage("Marek", "Stanko");
	auto result2 = sut.returnAverage("Andrzej", "Kowal");
	auto s1average = 3.5;
	auto s2average = 3;

	EXPECT_DOUBLE_EQ(result1, s1average);
	EXPECT_DOUBLE_EQ(result2, s2average);
}

TEST_F(GLogTest, CanReturnGrades) {
	auto result1 = sut.returnGrades("Marek", "Stanko");
	auto result2 = sut.returnGrades("Andrzej", "Kowal");
	std::vector<double> s1grades{ 5,2 };
	std::vector<double> s2grades{ 3,3 };
	
	EXPECT_EQ(result1, s1grades);
	EXPECT_EQ(result2, s2grades);
}

TEST_F(GLogTest, DoesNotAddIncorrectGrades) {
	EXPECT_THROW({sut.addGrade("Marek","Stanko", 7);},std::invalid_argument);
}


TEST_F(GLogTest, CanReturnStudents) {
	std::vector<Student> studentVec{s1, s2};
	auto result = sut.getStudents();

	EXPECT_EQ(result, studentVec);
}

TEST(BasicGLogTest, CanDeleteStudent) {
	GLog sut{};
	Student s{};

	sut.addStudent("Marek", "Stanko");
	sut.deleteStudent("Marek", "Stanko");

	EXPECT_TRUE(sut.isEmpty());
}

TEST(BasicGLogTest, CanAddStudent) {
	GLog sut{};
	Student s{};

	EXPECT_TRUE(sut.isEmpty());
	
	sut.addStudent("Marek", "Stanko");
	EXPECT_FALSE(sut.isEmpty());
}