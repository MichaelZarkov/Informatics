#include "Time.h"

Time::Time(unsigned hour, unsigned minutes)
{
	if (hour > 23)
		throw "Invalid hour!";

	if (minutes > 59)
		throw "Invalid minutes!";

	this->hour = hour;
	this->minutes = minutes;
}

unsigned Time::getHour() const 
{
	return this->hour;
}

unsigned Time::getMinutes() const 
{
	return this->minutes;
}

unsigned Time::minutesAfterMidnight() const
{
	return this->hour * 60 + this->minutes;
}

bool operator>(const Time& left, const Time& right)
{
	if (left.getHour() > right.getHour())
		return true;

	if (left.getHour() < right.getHour())
		return false;

	return left.getMinutes() > right.getMinutes();
}

bool operator>=(const Time& left, const Time& right)
{
	if (left.getHour() >= right.getHour())
		return true;

	if (left.getHour() < right.getHour())
		return false;

	return left.getMinutes() >= right.getMinutes();
}

bool operator<(const Time& left, const Time& right) 
{
	return !(left >= right);
}

bool operator<=(const Time& left, const Time& right)
{
	return !(left > right);
}

bool operator==(const Time& left, const Time& right) 
{
	return left.getHour() == right.getHour() && left.getMinutes() == left.getMinutes();
}

std::ostream& operator<<(std::ostream& output, const Time& time)
{
	output << time.getHour() << ":" << time.getMinutes();
	return output;
}

std::istream& operator>>(std::istream& input, Time& time)
{
	unsigned hour;
	input >> hour;

	// :
	input.ignore();

	unsigned minutes;
	input >> minutes;

	Time newTime{ hour, minutes };
	time = newTime;

	return input;
}