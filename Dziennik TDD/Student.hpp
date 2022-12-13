#pragma once
#include <string>
#include <vector>

struct Student {
	std::string name{};
	std::string surname{};
	std::vector<double> grades{};

	friend bool operator==(const Student& lhs, const Student& rhs)
	{
		return lhs.name == rhs.name && lhs.surname == rhs.surname;
	}
	friend bool operator!=(const Student& lhs, const Student& rhs)
	{
		return !(lhs == rhs);
	}
};