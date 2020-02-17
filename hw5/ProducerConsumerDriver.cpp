/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
#include <string>
#include <sstream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
	ProducerConsumer pc;

	string choice;
	int menuChoice;
	string numProduce;
	int numP;
	string itemProduce;
	string numConsume;
	int numC;
	// char num = choice.c_str();

	while(choice != "4")
	{
		menu();

		getline(cin, choice);

		stringstream(choice) >> menuChoice;

		switch(menuChoice)
		{
			case 1:
				cout << "Enter the number of items to be produced: " << endl;
				getline(cin, numProduce);

				stringstream(numProduce) >> numP;

				// int itemNum = pc.queueSize() + 1;

				for(int i = 0; i < numP; i++)
				{
					cout << "Item" << i + 1 << ":" << endl;
					getline(cin, itemProduce);

					pc.enqueue(itemProduce);
				}

				break;

			case 2:
				cout << "Enter the number of items to be consumed: " << endl;
				getline(cin, numConsume);

				stringstream(numConsume) >> numC;
				// int num = stoi(numConsume);

				for(int i = 0 ; i < numC; i++)
				{
					if(pc.isEmpty() == false)
					{
						cout << "Consumed: " << pc.peek() << endl;
						pc.dequeue();
					}
					else
					{
						cout << "No more items to consume from queue" << endl;
						break;
					}

				}

				break;

			case 3:
				cout << "Number of items in the queue:" << pc.queueSize() << endl;
				exit(0);
				break;


		} // switch end



	}


}
