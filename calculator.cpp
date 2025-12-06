#include <iostream>
using namespace std;
#include <limits>

class Course
{
private:
    float credits;
    float grade_point;

public:
    string name;       // course name
    float getCredits() // get credits
    {
        return credits;
    }
    float getGradePoint() // get grade point
    {
        return grade_point;
    }
    void setCredits(float c) // set credits
    {
        credits = c;
    }
    void setGradePoint(float g) // set grade point
    {
        grade_point = g;
    }
    float getWeightedGradePoint() // calculate weighted grade point for each course
    {
        return credits * grade_point;
    }
};
float TotalWeightedGradePoints(Course courses[], int n) // calculate total weighted grade points
{
    float total = 0.0;
    for (int i = 0; i < n; i++)
    {
        total += courses[i].getWeightedGradePoint();
    }
    return total;
}
float TotalCredits(Course courses[], int n) // calculate total credits
{
    float total = 0.0;
    for (int i = 0; i < n; i++)
    {
        total += courses[i].getCredits();
    }
    return total;
}
float CalculateCGPA(float total_weighted_grade_points, float total_credits) // calculate CGPA
{
    return total_weighted_grade_points / total_credits;
}
void InputCourseDetails(Course courses[], int n) // input course details
{
    for (int i = 0; i < n; i++)
    {
        float credits, grade_point;
        cout << "Enter course name: ";
        cin >> courses[i].name; // input course name
        cout << "Enter credits for " << courses[i].name << ": ";
        do
        { // a better approach as compared if-continue because does not start the course iput from start and hence more user friendly
            cin >> credits;
            if (cin.fail() || credits <= 0 || credits > 50)
            {                                                        // added upper and lower limits to avoid unrealistic credit values
                cin.clear();                                         // clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Invalid credits. Please enter a positive number." << endl;
            }
        } while (cin.fail() || credits <= 0 || credits > 50);
        // cin >> credits;                 // input credits
        // if(cin.fail() || credits <= 0){
        //     cin.clear(); // clear the fail state
        //     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        //     cout<<"Invalid credits. Please enter a positive number."<<endl;
        //     i--; // repeat this iteration
        //     continue;               // restart loop
        // }
        courses[i].setCredits(credits); // set credits
        cout << "Enter grade point for " << courses[i].name << ": ";

        do
        {
            cin >> grade_point;
            if (cin.fail() || grade_point < 0.0 || grade_point > 10.0)
            {                                                        // added limits to grade points as per common grading systems
                cin.clear();                                         // clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Invalid grade point. Please enter a valid number." << endl;
            }
        } while (cin.fail() || grade_point < 0.0 || grade_point > 10.0);
        // cin >> grade_point;
        //  if(cin.fail()){
        //      cin.clear(); // clear the fail state
        //      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        //      cout<<"Invalid grade point. Please enter a valid number."<<endl;
        //      i--; // repeat this iteration
        //      continue;               // restart loop
        //  }                                             // input grade point
        courses[i].setGradePoint(grade_point); // set grade point
    }
}
void DisplayCourseDetails(Course courses[], int n) // display course details
{
    cout << "Course Details:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Course Name: " << courses[i].name << ", Grade Points: " << courses[i].getWeightedGradePoint() << endl;
    }
}
void RunSystem()
{
    cout << "Enter number of courses: ";
    int n;
    do
    {
        cin >> n;
        if (cin.fail() || n <= 0 || n > 50)
        {                                                        // added upper limit to avoid large memory allocation and lower to handle -ve and zero courses
            cin.clear();                                         // clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid number of courses. Please enter a positive integer." << endl;
        }
    } while (cin.fail() || n <= 0 || n > 50);

    // cin>>n;
    // if(cin.fail() || n <= 0){
    //     cin.clear(); // clear the fail state
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
    //     cout<<"Invalid number of courses. Please enter a positive integer."<<endl;
    //     return;
    // }
    Course *courses = new Course[n];                                                           // dynamic array of courses
    InputCourseDetails(courses, n);                                                            // input course details
    float gpa = CalculateCGPA(TotalWeightedGradePoints(courses, n), TotalCredits(courses, n)); // calculate CGPA
    cout << "Your CGPA is: " << gpa << endl;                                                   // display CGPA
    DisplayCourseDetails(courses, n);                                                          // display course details
    delete[] courses;                                                                          // free dynamic memory
}
int main()
{
    cout << "Welcome to the Apexcify Technologies CGPA Calculator System" << endl;
    RunSystem();
    return 0;
}