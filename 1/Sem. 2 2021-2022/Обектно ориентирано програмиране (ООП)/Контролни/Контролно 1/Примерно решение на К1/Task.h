#pragma once

#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#include <fstream>
#include <iostream>

class Task
{
public:
	Task(const char* description, unsigned priority, unsigned length);
	Task(const Task& other);
	Task& operator=(const Task& other) = delete;
	~Task();

	Task(std::istream& file);

	void setPriority(unsigned prio);
	void setLength(unsigned len);
	void setStatus();

	const char* getDescription() const;
	unsigned getPriority() const;
	unsigned getLength() const;
	bool isFinished() const;

public:
	static const unsigned MAX_PRIORITY = 60;

private:
	const char* const description;
	unsigned priority;
	unsigned length;
	bool status;
};

bool operator>(const Task& left, const Task& right);

std::ostream& operator<<(std::ostream& output, const Task& task);

#include "Time.h"

class ScheduledTask
{
public:
	Task task;
	Time scheduledTime;

	Time getEnd() const;

	bool willFinishByTheDay() const;

	bool startsAfter(const ScheduledTask& otherTask) const;
	bool endsBefore(const ScheduledTask& otherTask) const;

	bool overlapsWith(const ScheduledTask& otherTask) const;

	bool hasBiggerPriorityThan(const ScheduledTask& otherTask) const;
};

#endif // !TASK_H_INCLUDED



