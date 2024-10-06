#include  "MonthlyPlanner.h"

#include <iostream>

int main()
{
	MonthlyPlanner may(5);

	Task oopHomework("OOP Homework", 10, 120);
	Time scheduledTime(10, 30);

	may.addTask(oopHomework, 22, scheduledTime);

	may.writeToTextFile(std::cout);

	return 0;
}
