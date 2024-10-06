#include "MonthlyPlanner.h"
#include "Time.h"

#include <iostream>

unsigned validateMonth(unsigned month)
{
	if (month > 12 || month == 0)
	{
		throw "Invalid month!";
	}

	return month;
}

MonthlyPlanner::MonthlyPlanner(unsigned month)
	: month(validateMonth(month))
{}

MonthlyPlanner::MonthlyPlanner(const MonthlyPlanner& other)
	: month(other.month)
{
	try {
		for (unsigned i = 0; i < MAX_DAYS; ++i)
		{
			for (unsigned j = 0; j < other.numberOfTasksPerDay[i]; ++j)
			{
				this->tasksForMonth[i][j] = new ScheduledTask(*other.tasksForMonth[i][j]);
			}
			numberOfTasksPerDay[i] = other.numberOfTasksPerDay[i];
		}
	}
	catch (...) 
	{
		for (unsigned i = 0; i < MAX_DAYS; ++i)
		{
			for (unsigned j = 0; j < other.numberOfTasksPerDay[i]; ++j)
			{
				delete this->tasksForMonth[i][j];
			}
		}

		throw;
	}
}

MonthlyPlanner::~MonthlyPlanner()
{
	for (unsigned i = 0; i < MAX_DAYS; ++i)
	{
		for (unsigned j = 0; j < this->numberOfTasksPerDay[i]; ++j)
		{
			delete this->tasksForMonth[i][j];
		}
	}
}

bool isValidDay(unsigned day, unsigned month)
{
	// валидация на деня, спрямо месеца...
	return true;
}

int MonthlyPlanner::overlapsTask(unsigned day, const ScheduledTask& scheduledTask) const
{
	unsigned max_priority = 0;
	int index = -1;

	for (unsigned i = 0; i < this->numberOfTasksPerDay[day]; ++i)
	{
		if (scheduledTask.overlapsWith(*this->tasksForMonth[day][i]))
		{
			if (max_priority < this->tasksForMonth[day][i]->task.getPriority())
			{
				index = i;
				max_priority = this->tasksForMonth[day][i]->task.getPriority();
			}
		}
	}

	return index;
}

void MonthlyPlanner::clearOverlapping(unsigned day)
{
	const ScheduledTask* lastTask = tasksForMonth[day][numberOfTasksPerDay[day] - 1];
	for (unsigned i = 0; i < this->numberOfTasksPerDay[day] - 1; ++i)
	{
		if (lastTask->overlapsWith(*this->tasksForMonth[day][i]))
		{
			delete this->tasksForMonth[day][i];
			this->tasksForMonth[day][i] = nullptr;
		}
	}

	unsigned total = 0;
	for (unsigned i = 0; i < this->numberOfTasksPerDay[day]; ++i)
	{
		if (this->tasksForMonth[day][i])
			this->tasksForMonth[day][total++] = this->tasksForMonth[day][i];
	}
	
	this->numberOfTasksPerDay[day] = total;
}

bool MonthlyPlanner::addTask(const Task& task, unsigned day, const Time& time)
{
	if (!isValidDay(day, this->month))
		return false;

	ScheduledTask newTask{ task, time };
	if (!newTask.willFinishByTheDay())
		return false;

	--day;
	int index = overlapsTask(day, newTask);
	if (index == -1 || newTask.hasBiggerPriorityThan(*this->tasksForMonth[day][index]))
	{
		this->tasksForMonth[day][this->numberOfTasksPerDay[day]] = new ScheduledTask{ newTask };
		++this->numberOfTasksPerDay[day];
		
		if (index >= 0) 
		{
			clearOverlapping(day);
		}

		return true;
	}

	return false;
}

void MonthlyPlanner::getUnfinishedTasksForDay(unsigned day)
{
	--day;

	// should be sorted by time
	// there is an operator < defined in Time
	for (unsigned i = 0; i < this->numberOfTasksPerDay[day]; ++i)
	{
		if (!this->tasksForMonth[day][i]->task.isFinished())
		{
			std::cout << this->tasksForMonth[day][i]->task;
		}
	}
}

void MonthlyPlanner::setTaskAsFinished(unsigned day, const Time& time)
{
	--day;

	for (unsigned i = 0; i < this->numberOfTasksPerDay[day]; ++i)
	{
		if (this->tasksForMonth[day][i]->scheduledTime == time)
		{
			this->tasksForMonth[day][i]->task.setStatus();
			return;
		}
	}
}

void MonthlyPlanner::writeToTextFile(std::ostream& outputFile) const
{
	if (!outputFile)
		return;

	outputFile << this->month << std::endl;

	for (unsigned day = 0; day < this->MAX_DAYS; ++day)
	{
		outputFile << day + 1 << std::endl;

		outputFile << this->numberOfTasksPerDay[day] << std::endl;
		for (unsigned i = 0; i < this->numberOfTasksPerDay[day]; ++i)
		{
			outputFile << this->tasksForMonth[day][i]->scheduledTime << '\t';
			outputFile << this->tasksForMonth[day][i]->task << std::endl;
		}
	}
}

void MonthlyPlanner::readFromTextFile(std::istream& inputFile)
{
	if (!inputFile)
		return;

	unsigned month;
	inputFile >> month;

	// файлът не е за този месец
	if (month != this->month)
		return;

	while (inputFile)
	{
		unsigned day = 0;
		inputFile >> day;
		--day;

		inputFile >> this->numberOfTasksPerDay[day];
		for (unsigned i = 0; i < this->numberOfTasksPerDay[day]; ++i)
		{
			Time scheduledTime;
			inputFile >> scheduledTime;

			Task task(inputFile);
			this->addTask(task, day, scheduledTime);
		}
	}
}

