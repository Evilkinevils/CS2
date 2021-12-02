#include <iostream>
#include <string>

using namespace std;

// Structure represeting a course
struct course {
  int code;
  string dept;
  string name;
};

// Function finds how many courses in courseArray contain department
int numCoursesInDepartment(course courseArray[], int numCourses, string department)
{
  int count = 0;
  for (int j = 0; j < numCourses; j++){
    if (courseArray[j].dept == department){
      count++;
    }
  }
  return(count);  
}

int main(){
  const int numOfCourses = 10;
  course curriculum[numOfCourses] = {
    {102, "COMP", "Intro to Computer Programming and Design"},
    {103, "COMP", "Intro to Data Structures & Algorithms"},
    {241, "NWEN", "Systems Programming"},
    {201, "ECEN", "Data Acquisition"},
    {202, "ECEN", "Digital Electronics"},
    {220, "ECEN", "Signals and Systems"},
    {114, "CHEM", "Principles of Chemistry"},
    {115, "CHEM", "Structure and Spectroscopy"},
    {142, "MATH", "Calculus 1B"},
    {151, "MATH", "Alegebra"}
  };

  string department;
  cout << "Enter department:";
  cin >> department;
  cout << "There are " << numCoursesInDepartment(curriculum, numOfCourses, department) << " courses in the " << department << " department.\n";

  return(0);
}
