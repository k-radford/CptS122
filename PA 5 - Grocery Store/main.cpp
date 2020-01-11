	// Kate Radford
// PA 5 - Grocery Store Simulation
// Due Friday, March 2nd

#include "Data.h"
#include "Queue.h"
#include "QueueNode.h"


int main(void)
{
	srand((unsigned int)time(NULL));
	int n = 0;
	Queue express, normal;

	cout << "*** Welcome to KR's Grocery Store Simulation ***" << endl << endl;
	// Allow for the simulation to run for n number of minutes, where n is inputted by the user.
	cout << "How many minutes would you like this simulation to run?" << endl;
	cin >> n;

	int timeCounter = 0; 
	int customerNumber_N = 0, timeArrival_N = 0, timeDeparture_N = 0, serviceTime_N = 0, totalTime_N = 0; 
	int customerNumber_E = 0, timeArrival_E = 0, timeDeparture_E = 0, serviceTime_E = 0, totalTime_E = 0;
	Data tempN, tempE; // Temperary data queues

	timeArrival_N = rand() % 5 + 1;
	timeArrival_E = rand() % 6 + 3;

	do
	{
		
		// NORMAL LINE

		//When to delete customer
		if (timeDeparture_N == 0)
		{
			if (!normal.isEmpty())
			{
				normal.dequeue();
			}
			if (!normal.isEmpty())
			{
				timeDeparture_N = normal.getpHead()->getDataPtr()->getServiceTime();
			}
		}

		//When to add new customer
		if (timeArrival_N == 0)
		{
			//Add new customer
			customerNumber_N += 1;
			serviceTime_N = rand() % 5 + 1;

			tempN.setCustomerNum(customerNumber_N);
			tempN.setServiceTime(serviceTime_N);
			totalTime_N = normal.calcTotalTime();
			tempN.setTotalTime(totalTime_N);

			normal.enqueue(customerNumber_N, serviceTime_N, totalTime_N);
			// normal.printQueue(tempN); // in order to do this you must calculate totalTime first
			cout << "Customer Number " << customerNumber_N << " in Normal Line" << endl;
			cout << "Service Time:" << serviceTime_N << endl;
			cout << "Total Time:" << totalTime_N << endl << endl;

			if (timeDeparture_N <= 0)
			{
				timeDeparture_N = normal.getpHead()->getDataPtr()->getServiceTime();
			}

			timeArrival_N = rand() % 5 + 1;
		}

			
		// EXPRESS LINE

		//When to delete customer
		if (timeDeparture_E == 0)
		{
			if (!express.isEmpty())
			{
				express.dequeue();
			}
			if (!express.isEmpty())
			{
				timeDeparture_E = express.getpHead()->getDataPtr()->getServiceTime();
			}
		}

		//When to add new customer
		if (timeArrival_E == 0)
		{
			//Add new customer
			customerNumber_E += 1;
			serviceTime_E = rand() % 5 + 1;

			tempE.setCustomerNum(customerNumber_E);
			tempE.setServiceTime(serviceTime_E);
			totalTime_E = express.calcTotalTime();
			tempE.setTotalTime(totalTime_E);

			express.enqueue(customerNumber_E, serviceTime_E, totalTime_E);
			cout << "Customer Number " << customerNumber_E << " in Express Line" << endl;
			cout << "Service Time:" << serviceTime_E << endl;
			cout << "Total Time:" << totalTime_E << endl << endl;

			if (timeDeparture_E <= 0)
			{
				timeDeparture_E = express.getpHead()->getDataPtr()->getServiceTime();
			}

			timeArrival_E = rand() % 5 + 1;
		}

		if (timeCounter != 0 && timeCounter % 10 == 0) // print out queue every 10 'minutes'
		{
			cout << "Normal Line Queue:" << endl;
			normal.printQueue();
			cout << "Express Line Queue:" << endl;
			express.printQueue();
		}
		

		// 1 interval = 1 'minute'
		timeCounter++;
		timeArrival_N--;
		timeDeparture_N--;
		timeArrival_E--;
		timeDeparture_E--;
	} while (timeCounter != n);

	return 0;
}