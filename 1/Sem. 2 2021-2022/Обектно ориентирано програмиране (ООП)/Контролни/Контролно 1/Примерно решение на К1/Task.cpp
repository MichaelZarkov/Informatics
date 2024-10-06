#define _CRT_SECURE_NO_WARNINGS

#include "Task.h"

#include <cstring>
#include <exception>
#include <limits>

char* copy(const char* source)
{
	if (source == nullptr || strlen(source) == 0)
	{
		throw "Empty string!";
	}

	char* destination = new char[strlen(source) + 1];
	strcpy(destination, source);

	return destination;
}

Task::Task(const char* description, unsigned priority, unsigned length)
	: description(copy(description)), status (false)
{
	try
	{
		this->setPriority(priority);
		this->setLength(length);
	}
	catch(const char* exception)
	{
		delete[] this->description;
		throw;
	}
}

Task::Task(const Task& other)
	:Task(other.description, other.priority, other.length)
{}

Task::~Task()
{
	delete[] this->description;
}

char* readDescriptionFromFile(std::istream& file)
{
	if (!file)
		file.clear();

	char buffer[1024];
	file.getline(buffer, 1024, '\t');

	if (!file)
		file.clear();

	// изчистване до достигане на tab, което е разделител в записа
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\t');

	return copy(buffer);
}

unsigned readPriorityFromFile(std::istream& file)
{
	unsigned priority = Task::MAX_PRIORITY + 1;
	file >> priority;

	if (!file)
	{
		file.clear();
		// изчистване целия запис
		file.ignore(std::numeric_limits<std::streamsize>::max());
	}

	return priority;
}

unsigned readLengthFromFile(std::istream& file)
{
	unsigned length = 0;
	file >> length;

	if (!file)
	{
		file.clear();
		// изчистване целия запис
		file.ignore(std::numeric_limits<std::streamsize>::max());
	}

	return length;
}

Task::Task(std::istream& file)
	: Task(readDescriptionFromFile(file), readPriorityFromFile(file), readLengthFromFile(file))
{}


void Task::setPriority(unsigned priority)
{
	if (priority > this->MAX_PRIORITY)
	{
		throw "Invalid priority value!";
	}

	this->priority = priority;
}

void Task::setLength(unsigned length)
{
	if (0 == length)
		throw "Invalid length value!";

	this->length = length;
}

void Task::setStatus()
{
	this->status = true;
}

const char* Task::getDescription() const
{
	return this->description;
}

unsigned Task::getPriority() const
{
	return this->priority;
}

unsigned Task::getLength() const
{
	return this->length;
}

bool Task::isFinished() const
{
	return this->status;
}

bool operator>(const Task& left, const Task& right)
{
	if (left.getPriority() > right.getPriority())
		return true;

	if (left.getPriority() < right.getPriority())
		return false;

	return left.getLength() < right.getLength();
}

std::ostream& operator<<(std::ostream& output, const Task& task)
{
	output
		<< task.getDescription() << '\t'
		<< task.getPriority() << '\t'
		<< task.getLength() << '\t'
		<< task.isFinished() << '\n';

	return output;
}

bool ScheduledTask::willFinishByTheDay() const
{
	return this->scheduledTime.minutesAfterMidnight() + this->task.getLength() < 24 * 60;
}

Time ScheduledTask::getEnd() const
{
	unsigned endAsMinutes = this->scheduledTime.minutesAfterMidnight() + this->task.getLength();

	return Time(endAsMinutes / 60, endAsMinutes % 60);
}

bool ScheduledTask::startsAfter(const ScheduledTask& otherTask) const
{
	return this->scheduledTime > otherTask.scheduledTime;
}

bool ScheduledTask::endsBefore(const ScheduledTask& otherTask) const
{
	return this->getEnd() < otherTask.getEnd();
}

bool ScheduledTask::overlapsWith(const ScheduledTask& otherTask) const
{
	if ((this->startsAfter(otherTask) && this->endsBefore(otherTask)) ||
		(otherTask.startsAfter(*this) && this->endsBefore(otherTask)) ||
		(this->startsAfter(otherTask) && otherTask.endsBefore(*this)))
		return true;

	return false;
}

bool ScheduledTask::hasBiggerPriorityThan(const ScheduledTask& other) const
{
	return this->task > other.task;
}
