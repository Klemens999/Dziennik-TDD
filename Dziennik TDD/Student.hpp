#pragma once
#include <string>
#include <vector>

struct Student {
	std::string imie{};
	std::string nazwisko{};
	std::vector<double> grades{};

	friend bool operator==(const Student& lhs, const Student& rhs)
	{
		return lhs.imie == rhs.imie && lhs.nazwisko == rhs.nazwisko;
	}
	friend bool operator!=(const Student& lhs, const Student& rhs)
	{
		return !(lhs == rhs);
	}
};