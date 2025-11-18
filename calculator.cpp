#include <iostream>
using namespace std;
class Course
{ 
private:
    float credits;
    float grade_point;
public:
    string name;
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
int main()
{
    int n;
    float total_credits = 0.0;
    float total_weighted_grade_points = 0.0;
    cout << "Enter number of courses: ";
    cin >> n;
    Course courses[n];
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
        total_weighted_grade_points += courses[i].getWeightedGradePoint(); // calculate total weighted grade points
        total_credits += courses[i].getCredits();                          // calculate total credits
    }
    float cgpa = total_weighted_grade_points / total_credits; // calculate CGPA
    cout << "Your CGPA is: " << cgpa << endl;
    return 0;
}