#pragma once

#include <sstream>
#include <iomanip>
#include "FileDate.h"


void Date::SetYear(const int year)
{
	yyyy = year;
}

int Date::GetYear() const 
{
	return yyyy;
}

void Date::SetMonth(const int month)
{
	mm = month;
}

int Date::GetMonth() const
{
	return mm;
}

void Date::SetDay(const int day)
{
	dd = day;
}

int Date::GetDay() const
{
	return dd;
}

void Date::ReadDate(std::istream& in)
{
	int yyyy, mm, dd;
	char point = '.';
	if (in >> yyyy >> point >> mm >> point >> dd)
	{
		this->SetYear(yyyy);
		this->SetMonth(mm);
		this->SetDay(dd);
	}
}

void Date::WriteDate(std::ostream& out) const
{
	const char point = '.';
	out << "Creation Date: "
		<< this->GetYear() << point
		<< std::setfill('0') << std::setw(2) << this->GetMonth() << point
		<< std::setfill('0') << std::setw(2) << this->GetDay() << std::endl;
}

bool Date::ValidateDate(const std::string& date) {
	std::istringstream in(date);
	int yyyy, mm, dd;
	char point = '.';
	in >> yyyy >> point >> mm >> point >> dd;
	if (in.fail() || yyyy < 2000 || yyyy > 9999 || mm > 12 || mm < 1 || dd > 31 || dd < 1) {
		return false;
	}
	return true;
}

void Date::InvalidDate(const std::string& date)
{
	if (date.empty() || !ValidateDate(date)) {
		throw std::runtime_error("Invalid time!");
	}
	ValidateDate(date);
}

Date::Date(const int& year, const int& month, const int& day) : yyyy(year), mm(month), dd(day) {}