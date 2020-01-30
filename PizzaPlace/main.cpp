/*
Joe’s Pizza Palace needs a program to calculate the number of slices a pizza of any size can be divided into.
The program should perform the following steps:
A) Ask the user for the diameter of the pizza in inches.
B) Calculate the number of slices that may be taken from a pizza of that size if each slice has an area of 14.125 square inches.
C) Display a message telling the number of slices.
The number of square inches in the total pizza can be calculated with this formula: A = Pi r squared
*/
#include <iostream>
#include <cmath>

#define PI 3.14

using namespace std;

int main()
{
    float diameter, radius;
    float sliceArea = 14.125;

    //cout << "Hello world!" << endl;
    cout << "Enter the diameter of the pizza in inches :";
    cin >> diameter;

    radius = diameter/2;

    float totalArea = PI * pow(radius, 2);
    int slices = totalArea/sliceArea;


    cout << "Total number of slices : " << slices << end1;



    return 0;
}
