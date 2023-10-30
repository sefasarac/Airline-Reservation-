#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// https://github.com/sefasarac
typedef struct
{
	char flightNumber[5];
	char departureCity[16];
	char arrivalCity[16];
	char departureDay[11];
	char departureTime[6];
	char arrivalDay[11];
	char arrivalTime[6];
	int passengers[1000];
	int numberOfPassengers;
} Flight;

typedef struct
{
	int id;
	char firstName[16];
	char lastName[16];
	char departureCity[16];
	char arrivalCity[16];
	char departureDay[11];
	int flightNumber;
} Passenger;

// (flights[i].departureCity == passengers[j].departureCity ) && (flights[i].arrivalCity == passengers[j].arrivalCity ) && (flights[i].departureDay == passengers[j].departureDay))
void makeReservation(Passenger *passenger, Flight *flights, int sizeOfFlights)
{
	int counter = 0;
	for (int i = 0; i < sizeOfFlights; i++)
	{
		if (flights[i].departureCity == passenger->departureCity && flights[i].arrivalCity == passenger->arrivalCity && flights[i].departureDay == passenger->departureDay)
		{
			flights[i].passengers[counter] = passenger->id;
			printf("atanan deger : %d, sayac: %d, son deger: %d \n", passenger->id, counter, flights[i].passengers[counter]);
			counter++;
		}
	}
}

void searchFlight(char flightNumber[5], Flight *flights, int sizeOfFlights)
{
	for (int i = 0; i < sizeOfFlights; i++)
	{
		if (strcmp(flights[i].flightNumber, flightNumber) == 0)
		{
			printf("%s %s %s %s %s %s %s\n\n", flights[i].flightNumber, flights[i].departureCity, flights[i].arrivalCity, flights[i].departureDay, flights[i].departureTime, flights[i].arrivalDay, flights[i].arrivalTime);
			return;
		}
	}
	printf("No flight with number %s\n\n", flightNumber);
}

void searchDeparture(char departureCity[16], Flight *flights, int sizeOfFlights)
{
	int countDeparture = 0;
	for (int j = 0; j < sizeOfFlights; j++)
	{
		if (strcmp(flights[j].departureCity, departureCity) == 0)
		{
			printf("%s %s %s %s %s %s %s\n", flights[j].flightNumber, flights[j].departureCity, flights[j].arrivalCity, flights[j].departureDay, flights[j].departureTime, flights[j].arrivalDay, flights[j].arrivalTime);
			countDeparture += 1;
			continue;
			return;
		}
	}
	if (countDeparture == 0)
	{
		printf("No departure city %s\n\n", departureCity);
	}
}

void searchArrival(char arrivalCity[16], Flight *flights, int sizeOfFlights)
{
	int countArrival = 0;
	for (int j = 0; j < sizeOfFlights; j++)
	{
		if (strcmp(flights[j].arrivalCity, arrivalCity) == 0)
		{
			printf("%s %s %s %s %s %s %s\n", flights[j].flightNumber, flights[j].departureCity, flights[j].arrivalCity, flights[j].departureDay, flights[j].departureTime, flights[j].arrivalDay, flights[j].arrivalTime);
			countArrival += 1;
			continue;
			return;
		}
	}
	if (countArrival == 0)
	{
		printf("No arrival city %s\n", arrivalCity);
	}
}

void printFlight(char flightNumber[5], Flight *flights, int sizeOfFlights)
{

	for (int m = 0; m < sizeOfFlights; m++)
	{
		if (strcmp(flights[m].flightNumber, flightNumber) == 0)
		{
			printf("%s %s %s %s %s %s %s %d\n", flights[m].flightNumber, flights[m].departureCity, flights[m].arrivalCity, flights[m].departureDay, flights[m].departureTime, flights[m].arrivalDay, flights[m].arrivalTime, flights[m].numberOfPassengers);
			return;
		}
	}
}

void printInfo(char flightNumber[5], Passenger *passengers, int sizeOfPassengers, Flight *flights, int sizeOfFlights)
{
	printFlight(flightNumber, flights, sizeOfFlights);
	Flight myFlight;
	for (int k = 0; k < sizeOfFlights; k++)
	{
		if (strcmp(flights[k].flightNumber, flightNumber) == 0)
		{
			myFlight = flights[k];
		}
	}
	for (int x = 1; x <= myFlight.numberOfPassengers; x++)
	{
		for (int u = 0; u < sizeOfPassengers; u++)
		{
			//	  printf("%d %d\n",passengers[u].id,myFlight.passengers[x]);
			if (passengers[u].id == myFlight.passengers[x])
			{

				printf("%s %s\n", passengers[u].firstName, passengers[u].lastName);
			}
		}
	}
}

int main()
{
	char girdi[30];
	int i, j, m, k;
	int sizeOfFlights = 0, sizeOfPassengers = 0;
	// printf("ucus sayisi : ");
	scanf("%d", &sizeOfFlights);
	Flight *flights = (Flight *)malloc(sizeof(Flight) * sizeOfFlights);
	for (int i = 0; i < sizeOfFlights; i++)
	{
		scanf("%s %s %s %s %s %s %s", flights[i].flightNumber, flights[i].departureCity, flights[i].arrivalCity, flights[i].departureDay, flights[i].departureTime, flights[i].arrivalDay, flights[i].arrivalTime);
		flights[i].numberOfPassengers = 0;
		// printf("flightNumber:%s \n departureCity:%s\n arrivalcity:%s\n departureDay:%s\n departureTime:%s\n arrivalDay:%s\n arrivalTime:%s\n",flights[i].flightNumber,flights[i].departureCity,flights[i].arrivalCity,flights[i].departureDay,flights[i].departureTime,flights[i].arrivalDay,flights[i].arrivalTime);
		// printf("%s %s %s %s %s %s %s\n",flights[i].flightNumber,flights[i].departureCity,flights[i].arrivalCity,flights[i].departureDay,flights[i].departureTime,flights[i].arrivalDay,flights[i].arrivalTime);
	}
	// printf("yolcu sayisi :");
	scanf("%d", &sizeOfPassengers);
	Passenger *passengers = (Passenger *)malloc(sizeof(Passenger) * sizeOfPassengers);

	int id = 0;
	for (int j = 0; j < sizeOfPassengers; j++)
	{
		scanf("%s %s %s %s %s", passengers[j].firstName, passengers[j].lastName, passengers[j].departureCity, passengers[j].arrivalCity, passengers[j].departureDay);
		passengers[j].id = ++id;
		// printf("Atandi %d . indexte bulunan ucus degeri : %s",i,flights[i].flightNumber);
		// printf("%d %s %s %s %s %s\n",passengers[j].id,passengers[j].firstName,passengers[j].lastName,passengers[j].departureCity,passengers[j].arrivalCity,passengers[j].departureDay);
	}
	int atandiMi = 0;
	for (int y = 0; y < sizeOfPassengers; y++)
	{
		for (int i = 0; i < sizeOfFlights; i++)
		{
			if (strcmp(flights[i].departureCity, passengers[y].departureCity) == 0 && strcmp(flights[i].arrivalCity, passengers[y].arrivalCity) == 0 && strcmp(flights[i].departureDay, passengers[y].departureDay) == 0)
			{
				atandiMi = 1;
				flights[i].passengers[++flights[i].numberOfPassengers] = passengers[y].id;
			}
		}
		if (atandiMi == 0)
		{
			printf("%s %s %s %s %s No reservation\n\n", passengers[y].firstName, passengers[y].lastName, passengers[y].departureCity, passengers[y].arrivalCity, passengers[y].departureDay);
		}
		atandiMi = 0;
	}

	char first[160];
	char second[160];
	char value[150];

	char firstN[30];
	char lastN[30];

	while (1)
	{
		scanf("%s", first);
		if (strcmp(first, "search") == 0)
		{
			scanf("%s", second);
			if (strcmp(second, "flightNumber") == 0)
			{
				scanf("%s", value);
				searchFlight(value, flights, sizeOfFlights);
				continue;
			}
			if (strcmp(second, "departure") == 0)
			{
				scanf("%s", value);
				searchDeparture(value, flights, sizeOfFlights);
				printf("\n");
				continue;
			}
			if (strcmp(second, "arrival") == 0)
			{
				scanf("%s", value);
				searchArrival(value, flights, sizeOfFlights);
				printf("\n");
				continue;
			}
		}

		if (strcmp(first, "print") == 0)
		{
			scanf("%s", value);
			printFlight(value, flights, sizeOfFlights);
			printf("\n");
			continue;
		}

		if (strcmp(first, "printwP") == 0)
		{
			scanf("%s", value);
			printInfo(value, passengers, sizeOfPassengers, flights, sizeOfFlights);
			printf("\n");
			continue;
		}

		if (strcmp(first, "printR") == 0)
		{
			scanf("%s %s", &firstN, lastN);
			printf("%s %s ", firstN, lastN);
			Passenger myPassenger;
			for (int q = 0; q < sizeOfPassengers; q++)
			{
				if (strcmp(firstN, passengers[q].firstName) == 0 && strcmp(lastN, passengers[q].lastName) == 0)
				{
					myPassenger = passengers[q];
				}
			}
			int passengerId = myPassenger.id;
			for (int x = 0; x < sizeOfFlights; x++)
			{
				for (int u = 0; u < sizeOfPassengers; u++)
				{
					if (passengerId == flights[x].passengers[u])
					{
						printf("%s %s %s %s %s %s %s\n", flights[x].flightNumber, flights[x].departureCity, flights[x].arrivalCity, flights[x].departureDay, flights[x].departureTime, flights[x].arrivalDay, flights[x].arrivalTime);
						printf("\n");
					}
				}
			}
		}

		if (first[0] == 'E' && first[1] == 'N' && first[2] == 'D')
		{
			break;
		}
	}
	return 0;
}
// https://github.com/sefasarac