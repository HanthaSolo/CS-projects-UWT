/* Rohan Seam and Hantha Nyunt
 * 11/16/2018
 * TCES 203
 * Programming Assignment #4
 *
 * The function of this program is to act as a header file for external
 * programs to implement. A header for a Student object with various fields
 * and public methods that can be utilized in external programs.
*/
#include <string>
using namespace std;

class Student {
    private:
        string fullName;
        string hobby;
        int studentId;

    public:
        // Constructors
        Student() { fullName = "" , hobby = "", studentId = 0; }
        Student(const Student &);
        Student(string, string, int);

        // Mutators
        void setName(const string);
        void setHobby(const string);

        // Getters
        string getName() const { return fullName; }
        string getHobby() const { return hobby; }
        int getId() const { return studentId; }

        // Display information
        void displayInfo() const;
};
