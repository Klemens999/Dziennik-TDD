#include "Dziennik.hpp"
#include <algorithm>
#include <numeric>

bool GLog::isEmpty() const {
	return students.empty();
};

void GLog::addStudent(const Student& s) {
	students.emplace_back(s);
};

void GLog::deleteStudent(const Student& s) {
	students.erase(std::remove(students.begin(),students.end(), s));
};

void GLog::addGrade(Student& s, double grade) {
	s.grades.push_back(grade);
};

std::vector<double> GLog::returnGrades(const Student& s) {
	return s.grades;
};

double GLog::returnAverage(const Student& s) {
	return std::accumulate(s.grades.begin(), s.grades.end(), 0.0) / s.grades.size();
};

double GLog::returnClassAverage() {
	double sum{};
	int numberOfGrades{};
	for (auto& classmate : students) {
		for (auto& grade : classmate.grades) {
			sum += classmate.grades[grade];
			numberOfGrades++;
		}
	}
	return sum/numberOfGrades;
};

std::vector<Student> GLog::getStudents() const {
	return students;
};