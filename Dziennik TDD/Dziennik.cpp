#include "Dziennik.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cmath>

bool GLog::isEmpty() const {
	return students.empty();
};

void GLog::addStudent(const std::string& name, const std::string& surname) {
	if (name.empty() == true) throw std::invalid_argument("Pole 'imie' nie moze byc puste");
	if (surname.empty() == true) throw std::invalid_argument("Pole 'nazwisko' nie moze byc puste");
	addStudent(name, surname, {});
};

void GLog::addStudent(const std::string& name, const std::string& surname, const std::vector<double>& grades) {
	Student student{ name, surname, grades};
	auto it = std::find(students.begin(), students.end(), student);
	if (it != students.end()) {
		if (grades != it->grades && !it->grades.empty()) {
			for (int i = 0; i < grades.size(); i++) {
				addGrade(name, surname, grades[i]);
			}
		}
		else { throw std::invalid_argument("Student: " + name + " " + surname + " juz istnieje"); }
		return;
	}
	students.emplace_back(student);
};


void GLog::deleteStudent(const std::string& name, const std::string& surname) {
	Student s{ name,surname };
	if (std::find(students.begin(), students.end(), s) == students.end()) throw std::invalid_argument("Student: " + name+ " " + surname + " nie istnieje");
	students.erase(std::remove(students.begin(),students.end(), s));
};

void GLog::addGrade(const std::string& name, const std::string& surname, double grade) {
	int regularGrade = grade;
	if (grade > 6 || grade < 1) throw std::invalid_argument("Ocena: " + std::to_string(grade) + " nie miesci sie w przedziale 1-6");
	if (grade >regularGrade && floor(grade) != grade - 0.500000) throw std::invalid_argument("Ocena: " + std::to_string(grade) + "jest niepoprawna.");
	Student s{ name,surname };
	auto student = std::find(students.begin(), students.end(), s);
	student->grades.push_back(grade);
};

void GLog::changeGrade(const std::string& name, const std::string& surname, size_t it, double nGrade) {
	Student s{ name,surname };
	auto student = std::find(students.begin(), students.end(), s);
	student->grades.at(it) = nGrade;
};

std::vector<double> GLog::returnGrades(const std::string& name, const std::string& surname) {
	Student s{ name,surname };
	auto student = std::find(students.begin(), students.end(), s);
	return student->grades;
};

double GLog::returnAverage(const std::string& name, const std::string& surname) {
	Student s{ name,surname };
	auto student = std::find(students.begin(), students.end(), s);
	return std::accumulate(student->grades.begin(), student->grades.end(), 0.0) / student->grades.size();
};

Student GLog::returnBestStudent() {
	double max{};
	Student best;
	for (int i = 0; i < students.size(); i++) {
		if (returnAverage(students[i].name, students[i].surname) > max) {
			max = returnAverage(students[i].name, students[i].surname);
			best = students[i];
		}
	}
	return best;
};

Student GLog::returnWorstStudent() {
	double min{};
	Student worst;
	for (int i = 0; i < students.size(); i++) {
		if (returnAverage(students[i].name, students[i].surname) < min || min==0) {
			min = returnAverage(students[i].name, students[i].surname);
			worst = students[i];
		}
	}
	return worst;
};

double GLog::returnClassAverage() {
		double sum{};
		double numberOfGrades{};
		for (int i = 0; i < students.size(); i++) {
			sum += returnAverage(students[i].name, students[i].surname);
			numberOfGrades++;
		}
		return sum/numberOfGrades;
};

std::vector<Student> GLog::getStudents() const {
	return students;
};