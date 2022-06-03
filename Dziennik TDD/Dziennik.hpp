#pragma once
#include "Student.hpp"
#include <vector>

class GLog {
	std::vector<Student> students{};
public:
	bool isEmpty() const;
	void addStudent(const Student& s);
	void deleteStudent(const Student& s);
	void addGrade(Student& s, double grade);
	double returnAverage(const Student& s);
	double returnClassAverage();
	std::vector<double> returnGrades(const Student& s);
	std::vector<Student> getStudents() const;
};
