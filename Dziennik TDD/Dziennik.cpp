#include "Dziennik.hpp"
#include <algorithm>
#include <numeric>

bool GLog::isEmpty() const {
	return students.empty();
};

void GLog::addStudent(Student& s) {
	students.emplace_back(s);
};

void GLog::deleteStudent(const Student& s) {
	students.erase(std::remove(students.begin(),students.end(), s));
};

void GLog::addGrade(Student& s, double grade) {
	auto student = std::find(students.begin(), students.end(), s);
	student->grades.push_back(grade);
};

std::vector<double> GLog::returnGrades(const Student& s) {
	auto student = std::find(students.begin(), students.end(), s);
	return student->grades;
};

double GLog::returnAverage(const Student& s) {
	auto student = std::find(students.begin(), students.end(), s);
	return std::accumulate(student->grades.begin(), student->grades.end(), 0.0) / student->grades.size();
};

double GLog::returnClassAverage() {
		double sum{};
		double numberOfGrades{};
		for (int i = 0; i < students.size(); i++) {
			sum += returnAverage(students[i]);
			numberOfGrades++;
		}
		return sum/numberOfGrades;
};

std::vector<Student> GLog::getStudents() const {
	return students;
};