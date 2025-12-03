#include <iostream>
using namespace std;
class Course
{ 
private:
    float credits;
    float grade_point;
public:
    string name; // course name
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
float TotalWeightedGradePoints(Course courses[], int n)   // calculate total weighted grade points
{
    float total = 0.0;
    for (int i = 0; i < n; i++)
    {
        total += courses[i].getWeightedGradePoint();
    }
    return total;
}
float TotalCredits(Course courses[], int n)   // calculate total credits
{
    float total = 0.0;
    for (int i = 0; i < n; i++)
    {
        total += courses[i].getCredits();
    }
    return total;
}
float CalculateCGPA(float total_weighted_grade_points, float total_credits)  // calculate CGPA
{
    return total_weighted_grade_points / total_credits;
}
void InputCourseDetails(Course courses[], int n)  // input course details
{
    for (int i = 0; i < n; i++)
    {
        float credits, grade_point;
        cout << "Enter course name: ";
        cin >> courses[i].name; // input course name
        cout << "Enter credits for " << courses[i].name << ": ";
        cin >> credits;                 // input credits
        courses[i].setCredits(credits); // set credits
        cout << "Enter grade point for " << courses[i].name << ": ";
        cin >> grade_point;                                                // input grade point
        courses[i].setGradePoint(grade_point);                             // set grade point
    }
}
void DisplayCourseDetails(Course courses[], int n)  // display course details
{
    cout << "Course Details:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Course Name: " << courses[i].name << ", Grade Points: " << courses[i].getWeightedGradePoint() << endl;
    }
}
void RunSystem (){
    cout<<"Enter number of courses: ";
    int n;  
    cin>>n;
    Course* courses = new Course[n]; // dynamic array of courses
    InputCourseDetails(courses, n);  // input course details
   float gpa=CalculateCGPA(TotalWeightedGradePoints(courses, n), TotalCredits(courses, n)); // calculate CGPA
    cout << "Your CGPA is: " << gpa << endl; // display CGPA
    DisplayCourseDetails(courses, n); // display course details
    delete[] courses;                         // free dynamic memory

}
int main()
{
    cout << "Welcome to the Apexcify Technologies CGPA Calculator System" << endl;
    RunSystem();
    return 0;
}