#pragma once

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>

class Time
{
public:
	Time(unsigned hour = 0, unsigned minutes = 0);

	unsigned getHour() const;
	unsigned getMinutes() const;

	unsigned minutesAfterMidnight() const;

private:
	unsigned hour;
	unsigned minutes;
};

bool operator> (const Time& left, const Time& right);
bool operator>= (const Time& left, const Time& right);
bool operator< (const Time& left, const Time& right);
bool operator<= (const Time& left, const Time& right);
bool operator==(const Time& left, const Time& right);

std::ostream& operator<<(std::ostream& output, const Time& time);
std::istream& operator>>(std::istream& input, Time& time);

#endif // !TIME_H_INCLUDED



