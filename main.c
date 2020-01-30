/* Hantha Nyunt
   10/19/2018
   TCES 203
   Assignment #2

   The purpose of this program is to simulate a reservation service for CES airlines with 10 total
   seats. The program allows a user to reserve a seat as long as it is not previously booked. It
   also allows the user to pick their seat and class, view the seating chart, and quit the
   program.
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define TOTAL_SEATS 10
#define FIRST_CLASS_MAX 5
#define ECONOMY_MAX 10
#define NAME_LEN 25

typedef enum
{
    FIRST=1,
    ECONOMY=2,
    CHART=3,
    QUIT=4
} seat_type;


void init_seats(int[]);
void print_seat_chart(int seats[]);
int flight_menu(void);
int check_full(int seats[], seat_type type);
void assign(seat_type, int seats[]);
int assign_seat(char *, char *, int seats[], seat_type type);
void print_boarding_pass(char *, char *, int seat, seat_type);

int main()
{
    int seats[TOTAL_SEATS];
    int type;

    init_seats(seats);
    do
    {
        type = flight_menu();

        switch(type)
        {
        case FIRST:
            assign(FIRST, seats);
            break;
        case ECONOMY:
            assign(ECONOMY, seats);
            break;
        case CHART:
            print_seat_chart(seats);
            break;
        case QUIT:
            printf("Goodbye!\n");
        }
    }
    while(type <QUIT);
    return 0;
}

/**
 Assigns a seat for FIRST or ECONOMY.
 */
void assign(seat_type type, int seats[])
{
    int first_full = FALSE, economy_full = FALSE;
    int seat;
    char first_name[NAME_LEN], last_name[NAME_LEN];
    char response = 'y';

    //Check if the first class and economy
    //seats are full
    if (!check_full(seats, FIRST))
    {
        first_full = TRUE;
    }
    if (!check_full(seats, ECONOMY))
    {
        economy_full = TRUE;
    }

    //If both are full, display message and exit.
    if (first_full && economy_full)
    {
        printf("\nNext flight leaves in 3 hours.");
    }
    else
    {
        if (type == FIRST && first_full)
        {
            printf("\nSorry, first class is full.");
            printf("\nWould you like to be placed in the economy section? (y/n) ");
            scanf(" %c", &response);
            type = ECONOMY;
        }
        if (type == ECONOMY && economy_full)
        {
            printf("\nSorry, economy class is full.");
            printf("\nWould you like to be placed in the first class section? (y/n) ");
            scanf(" %c", &response);
            type = FIRST;
        }
        if (response != 'n' && response != 'N')
        {
            seat = assign_seat(first_name, last_name, seats, type);
            printf("\nCongratulations, printing your boarding pass....\n");
            print_boarding_pass(first_name, last_name, seat, type);
        }
        else
        {
            printf("\nNext flight leaves in 3 hours.");
        }
    }
}

/**
 Initializes all the seats to 0 to show that they are available.
 */
void init_seats(int seats[])
{
    int i;
    for(i = 0; i < TOTAL_SEATS; i++)
    {
        seats[i] = 0;
    }
}

/**
 Prints the seat chart (0 if available, 1 if taken).
 See executable for format.
 */
void print_seat_chart(int seats[])
{
    printf("\n\nSeating Chart (0-Available, 1-Taken)\n");
    printf(" 1  2  3  4  5  6  7  8  9  10\n");
    int i;
    for(i = 0; i < TOTAL_SEATS; i++)
    {
        printf(" %d ", seats[i]);
    }
    printf("\n\n\n");
}

/**
 Displays the flight menu and returns the choice made.
 Validates to make sure that only 1-4 are entered.
 */
int flight_menu(void)
{
    int choice;
    printf("      -------------------------\n");
    printf("      Welcome to CES Airline!\n");
    printf("\t    Please type 1 for first class\n");
    printf("\t    Please type 2 for economy\n");
    printf("\t    Please type 3 for seat chart\n");
    printf("\t    Please type 4 to quit\n");
    printf("\t    Your choice: ");
    scanf("%d", &choice);
    return choice;
}

/**
 Find a seat in first or economy and assign to the user
 and return the seat number.
 */
int assign_seat(char *first_name, char *last_name, int seats[], seat_type type)
{
    // upperBound is the higher seat number, lowerBound is the lower seat number.
    int seat, upperBound = ECONOMY_MAX, lowerBound = 1;
    printf("\nEnter your name (first name followed by last name): ");
    scanf("%s %s", first_name, last_name);
    if (type == FIRST)
    {
        // Changes the upperBound of the available seats to 5 to represent the bounds
        // of the first class section (1 - 5).
        upperBound = FIRST_CLASS_MAX;
    }
    else
    {
        // Changes the lowerBound of the available seats to 5 to represent the bounds
        // of the economy class section (6- 10).
        lowerBound = FIRST_CLASS_MAX + 1;
    }
    printf("Enter a seat number (%d-%d): ", lowerBound, upperBound);
    scanf("%d", &seat);
    // If the seat the user chose is already taken, the condition of the while loop will
    // be true.
    while(seats[seat - 1] == 1 || seat < lowerBound || seat > upperBound)
    {
        printf("\nChoose a valid seat. Please choose another.\n");
        printf("Enter a seat number (%d-%d): ", lowerBound, upperBound);
        scanf("%d", &seat);
    }
    // Assigns the user's seat choice.
    seats[seat - 1] = 1;
    return seat;
}

/**
 Checks if the seats are full for first or
 economy class.
 */
int check_full(int seats[], seat_type type)
{
    // return 0 if full otherwise 1.
    int upperBound = ECONOMY_MAX, lowerBound = 0, i;
    // Changes the bounds of the for loop below based on what class the user
    // chooses.
    if (type == FIRST)
    {
        upperBound = FIRST_CLASS_MAX;
    }
    else
    {
        lowerBound = FIRST_CLASS_MAX + 1;
    }
    for(i = lowerBound; i < upperBound; i++)
    {
        // return a number > 0 if the seats are available.
        if (seats[i] == 0)
        {
            return 1;
        }
    }
    // return 0 if the seats are full.
    return 0;
}

/**
 Print the boarding pass in the format
 CES Airlines Boarding Pass
 Passenger Name          SEAT : 1
 FIRST CLASS | ECONOMY

 Example:
 CES Airlines Boarding Pass
 Menaka Abraham          SEAT : 1
 FIRST CLASS

 */
void print_boarding_pass(char *first_name, char *last_name, int seat, seat_type type)
{
    printf("\n\nCES Airlines Boarding Pass\n");
    printf("%s %s\t  SEAT : %d\n", first_name, last_name, seat);
    if (type == FIRST)
    {
        printf("\t\t  FIRST CLASS\n");
    }
    else
    {
        printf("\t\t  ECONOMY\n");
    }
    printf("\n\n");
}
