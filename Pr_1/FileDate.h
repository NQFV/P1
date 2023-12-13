#pragma once

#include <iostream>


struct Date
{
	int yyyy;
	int mm;
	int dd;

	void SetYear(const int year);
	int GetYear() const;

	void SetMonth(const int month);
	int GetMonth() const;

	void SetDay(const int day);
	int GetDay() const;

	void ReadDate(std::istream& in);
	void WriteDate(std::ostream& out = std::cout) const;

	static bool ValidateDate(const std::string& date);
	static void InvalidDate(const std::string& date);
	
	Date(const int& year, const int& month, const int& day);
	Date() : yyyy(0), mm(0), dd(0) {}

};