#include <iostream>
#include "candybar.h"

using namespace std;

int main()
{
    CandyBar snack = {"Mocha Munch", 2.3, 350};
    cout << "The brandname is : " << snack.brand << endl;
    cout << "Weight           : " << snack.weight<< endl;
    cout << "Calories         : " << snack.calories<<endl;


    return 0;
}
