#pragma once

#ifndef MONTLYPLANNER_H_INCLUDED
#define MONTLYPLANNER_H_INCLUDED

#include "Task.h"

class MonthlyPlanner
{
public:
	MonthlyPlanner(unsigned month);
	MonthlyPlanner(const MonthlyPlanner& other);
	MonthlyPlanner& operator=(const MonthlyPlanner& other) = delete;
	~MonthlyPlanner();

	bool addTask(const Task& task, unsigned day, const Time& time);

	void getUnfinishedTasksForDay(unsigned day);
	void setTaskAsFinished(unsigned day, const Time& time);

	void writeToTextFile(std::ostream& outputFile) const;
	void readFromTextFile(std::istream& inputFile);

private:
	static const unsigned MAX_DAYS = 31;
	static const unsigned MAX_TASKS = 24 * 60;

	const unsigned month;

	ScheduledTask* tasksForMonth[MAX_DAYS][MAX_TASKS]{};
	unsigned numberOfTasksPerDay[MAX_DAYS]{};

private:
	int overlapsTask(unsigned day, const ScheduledTask& task) const;
	void clearOverlapping(unsigned day);
};

#endif // !MONTLYPLANNER_H_INCLUDED


