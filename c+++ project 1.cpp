#include <iostream>
#include <iomanip>
#include<fstream>
using namespace std;

const int ROWS = 12;
const int COLUMNS = 13;

string rowNumber[] =
{
    "Row 1:  ",
    "Row 2:  ",
    "Row 3:  ",
    "Row 4:  ",
    "Row 5:  ",
    "Row 6:  ",
    "Row 7:  ",
    "Row 8:  ",
    "Row 9:  ",
    "Row 10: ",
    "Row 11: ",
    "Row 12: ",
};

int seatingChart[ROWS][COLUMNS] =
{
    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20, 10, 10},
    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20, 30, 50},
    {10, 10, 20, 20, 20, 20, 20, 20, 10, 10, 10, 10, 10},
    {10, 10, 20, 20, 20, 20, 20, 20, 10, 10, 40, 70, 50},
    {10, 10, 20, 20, 20, 20, 20, 20, 10, 10, 60, 40, 20},
    {20, 20, 30, 30, 40, 40, 30, 30, 20, 20, 70, 20, 15},
    {20, 30, 30, 40, 50, 50, 40, 30, 30, 20, 60, 50, 30},
    {30, 40, 50, 50, 50, 50, 50, 50, 40, 30, 45, 55, 25},
	{10, 40, 20, 30, 52, 30, 25, 30, 20, 40, 35, 43, 45},
	{50, 58, 65, 65, 85, 20, 60, 74, 75, 56, 90, 55, 50},
	{42, 35, 75, 85, 95, 54, 74, 50, 10, 50, 60, 40, 30},
};

int main()
{
	
    bool isDone = false;
    cout<<"\n\n";
    cout << "\t **********ALLOCATE THE SEAT WITH PRICE ***********:\n\n" << endl;
    cout << "        1   2   3   4   5   6   7   8   9   10	 11  12  13" << endl;
    cout << "        *******************AUDITORIUM********************" << endl;
    cout<<"\n\n\n";

    for (int row = 0; row < 12; row++)
    {
        cout << rowNumber[row];

        for (int column = 0; column < 13; column++)
        {
            cout << setw(2) << seatingChart[row][column] << "  ";
        }

        cout << endl;
    }

    cout << "\n" << endl;
    
    do
    {
        bool found = false;

        char input;

        cout << "Press (S) to select a specific seat\n";
        cout << "Press (P) to select a seat based on price\n";
        cout << "Press (Q) to quit\n\n";
        cout << "select : ";
        cin >> input;

        
        if (input == 's' || input == 'S')
        {
            int xCoord;
            int yCoord;

            cout << "\nPlease input the row number: ";
            cin >> yCoord;

            int seatRow = yCoord - 1;

            cout << "Please input the seat number: ";
            cin >> xCoord;

            int seatNumber = xCoord - 1;

            if (seatingChart[seatRow][seatNumber] == 0)
            {
                cout << "\nI'm sorry that seat has been sold. Please select a different seat." << endl;
            }else
            {
                cout << "\nThe seat you selected is $" << seatingChart[seatRow][seatNumber] << endl;

                seatingChart[seatRow][seatNumber] = seatingChart[seatRow][seatNumber] / 10;
            }

        }else if (input == 'p' || input == 'P')
        {
            int seatPrice;
            cout << "Please enter a seat price: $";
            cin >> seatPrice;
            if (seatPrice == 10)
            {
                for (int row = 0; row < 12; row++)
                {
                    for (int column = 0; column < 13; column++)
                    {
                        if (seatingChart[row][column] == 10 && !found)
                        {
                            found = true;

                            seatingChart[row][column] = 1;

                            cout << "\nSeat " << column + 1 << ", in row " << row + 1 << ", is available for $10\n" << endl;

                        }else if(seatingChart[row][column] == 1 && found)
                        {
                            cout << "I'm sorry there are no more seats available at that price" << endl;
                        }
                    }
                }
            }

            else if (seatPrice == 20)
            {
                for (int row = 0; row < 12; row++)
                {
                    for (int column = 0; column < 13; column++)
                    {
                        if (seatingChart[row][column] == 20 && !found)
                        {
                            found = true;

                            seatingChart[row][column] = 2;

                            cout << "\nSeat " << column + 1 << ", in row " << row + 1 << ", is available for $20\n" << endl;

                        }else if(seatingChart[row][column] == 2 && found)
                        {
                            cout << "I'm sorry there are no more seats available at that price" << endl;
                        }
                    }
                }
            }
            else if (seatPrice == 30)
            {
                for (int row = 0; row < 12; row++)
                {
                    for (int column = 0; column < 13; column++)
                    {
                        if (seatingChart[row][column] == 30 && !found)
                        {
                            found = true;

                            seatingChart[row][column] = 3;

                            cout << "\nSeat " << column + 1 << ", in row " << row + 1 << ", is available for $30\n" << endl;


                        }else if(seatingChart[row][column] == 3 && found)
                        {
                            cout << "I'm sorry there are no more seats available at that price" << endl;
                        }
                    }
                }
            }
            else if (seatPrice == 40)
            {
                for (int row = 0; row < 12; row++)
                {
                    for (int column = 0; column < 13; column++)
                    {
                        if (seatingChart[row][column] == 40 && !found)
                        {
                            found = true;

                            seatingChart[row][column] = 4;

                            cout << "\nSeat " << column + 1 << ", in row " << row + 1 << ", is available for $40\n" << endl;


                        }else if (seatingChart[row][column] == 4 && found)
                        {
                            cout << "I'm sorry there are no more seats available at that price" << endl;
                        }
                    }
                }
            }
            else if (seatPrice == 50)
            {
                for (int row = 0; row < 12; row++)
                {
                    for (int column = 0; column < 13; column++)
                    {

                        if (seatingChart[row][column] == 50 && !found)
                        {
                            found = true;

                            seatingChart[row][column] = 5;

                            cout << "\nSeat " << column + 1 << ", in row " << row + 1 << ", is available for $50\n" << endl;

                        }else if (seatingChart[row][column] == 5 && found)
                        {
                            cout << "Sorry, there are no more seats available at that price" << endl;

                        }
                    }
                }
            }else 
            {
                cin.fail();
                cout << "\nSorry, there are no seats available for that price" << endl;
            }

        }else if (input == 'q' || input == 'Q')
        {
            isDone = true;

        }else
        {
            cin.fail();
            cout << "\nInvalid allocated of seat in the auditorium" << endl;
        }

        cout << "\n" << endl;

    }while (isDone == false);


    cout << " seat allocated" << "\n" << endl;
    double total = 0;

    for (int row = 0; row < 12; row++)
    {
        for (int column = 0; column < 13; column++)
        {
            if (seatingChart[row][column] == 1 || seatingChart[row][column] == 2 || seatingChart[row][column] == 3 || seatingChart[row][column] == 4 || seatingChart[row][column] == 5)
            {
                total = total + seatingChart[row][column];

                cout << "this seat is allocated " << column + 1 << " Row: " << row + 1 << " for $" << seatingChart[row][column] * 10 << endl;
            }
        }
    }

    cout << endl << "Your purchase total is: $" << total * 10 << endl << "\n" << endl;
    return 0;
}

