#pragma once
#include "Student.hpp"
#include <vector>
#include <string>


class GLog {
	std::vector<Student> students{};
public:
	bool isEmpty() const;
	void addStudent(const std::string& name, const std::string& surname);
	void addStudent(const std::string& name, const std::string& surname, const std::vector<double>& grades);
	void deleteStudent(const std::string& name, const std::string& surname);
	void addGrade(const std::string& name, const std::string& surname, double grade);
	void changeGrade(const std::string& name, const std::string& surname, size_t it, double nGrade);
	double returnAverage(const std::string& name, const std::string& surname);
	double returnClassAverage();
	Student returnBestStudent(); //zwraca imie i nazwisko
	Student returnWorstStudent(); //zwraca imie i nazwisko
	std::vector<double> returnGrades(const std::string& name, const std::string& surname);
	std::vector<Student> getStudents() const; //zwraca imiona i nazwiska studentow
};
