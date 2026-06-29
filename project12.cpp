#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

class Student
{
public:
    string name;
    int age;
    float cgpa;

    Student(string n, int a, float c) : name(n), age(a), cgpa(c) {} // Constructor to initialize the member variables of the Student class. It takes three parameters: a string n for the name, an integer a for the age, and a float c for the CGPA. The constructor uses an initializer list to assign the values of these parameters to the corresponding member variables of the class.
};

bool compareByCGPA(Student s1, Student s2)
{                             // Comparison function to sort the students by CGPA in descending order. It takes two Student objects as parameters and returns true if the CGPA of the first student (s1) is greater than the CGPA of the second student (s2), indicating that s1 should come before s2 in the sorted order.
    return s1.cgpa > s2.cgpa; // Return true if s1 has a higher CGPA than s2, which will result in sorting the students in descending order based on their CGPA.
}

void findStudentByName(const map<string, float> &
    
    
    
    studentMap, const string &name)
{                                    // Function to find a student by name in the map of student profiles. It takes a reference to the map and a string name as parameters.
    auto it = studentMap.find(name); // Use the find() method of the map to search for the student by name. The find() method returns an iterator to the element if found, or studentMap.end() if not found.
    if (it != studentMap.end())
    {                                                                                        // Check if the iterator is not equal to studentMap.end(), which indicates that the student was found in the map.
        cout << "Student Found! Name : " << it->first << " | CGPA : " << it->second << endl; // Output the student's name and CGPA using the iterator. The first member of the pair (it->first) represents the student's name, and the second member (it->second) represents the student's CGPA.
    }
    else
    {
        cout << "Student Not Found!" << endl; // If the student was not found in the map, output a message indicating that the student was not found.
    }
}

int main()
{
    vector<Student> students;                       // Create a vector of Student objects to store the student profiles. The vector is a dynamic array that can grow in size as needed.
    students.push_back(Student("Rahul", 20, 8.5));  // Add a Student object to the vector using push_back. This creates a new Student object with the name "Rahul", age 20, and CGPA 8.5, and adds it to the end of the vector.
    students.push_back(Student("Anjali", 22, 9.2)); // Add another Student object to the vector with the name "Anjali", age 22, and CGPA 9.2.
    students.push_back(Student("Vikram", 19, 7.8)); // Add a third Student object to the vector with the name "Vikram", age 19, and CGPA 7.8.
    students.push_back(Student("Priya", 21, 8.9));  // Add a fourth Student object to the vector with the name "Priya", age 21, and CGPA 8.9.
    students.push_back(Student("Amit", 23, 8.0));   // Add a fifth Student object to the vector with the name "Amit", age 23, and CGPA 8.0.

    cout << "---- Original Student Profiles ----" << endl;
    for (const auto &student : students)
    {                                                                                                            // Iterate through the vector of Student objects using a range-based for loop. The loop variable student represents each Student object in the vector during each iteration.
        cout << "Name : " << student.name << " | Age : " << student.age << " | CGPA : " << student.cgpa << endl; // Output the name, age, and CGPA of each student in the vector. The member variables of the Student class are accessed using the dot operator (.) to retrieve the values for each student.
    }

    sort(students.begin(), students.end(), compareByCGPA); // Sort the vector of Student objects in descending order based on their CGPA using the compareByCGPA function.
    cout << "\n---- Student Profiles Sorted by CGPA (Descending) ----" << endl;
    for (const auto &student : students)
    {                                                                                                            // Iterate through the sorted vector of Student objects using a range-based for loop to display the sorted student profiles.
        cout << "Name : " << student.name << " | Age : " << student.age << " | CGPA : " << student.cgpa << endl; // Output the name, age, and CGPA of each student in the sorted vector.
    }

    map<string, float> studentMap; // Create a map to store student profiles with the student's name as the key and the CGPA as the value. The map is an associative container that allows for fast retrieval of values based on unique keys.
    for (const auto &student : students)
    {                                            // Iterate through the vector of Student objects to populate the map. The loop variable student represents each Student object in the vector during each iteration.
        studentMap[student.name] = student.cgpa; // Add each Student object to the map using the student's name as the key. This allows for quick access to a student's profile based on their name.
    }

    cout << "\n---- Student Profiles in Map ----" << endl;
    for (const auto &entry : studentMap)
    {                                                                             // Iterate through the map of student profiles using a range-based for loop. The loop variable entry represents each key-value pair in the map during each iteration.
        cout << "Name : " << entry.first << " | CGPA : " << entry.second << endl; // Output the name and CGPA of each student in the map. The first member of the pair (entry.first) represents the student's name, and the second member (entry.second) represents the student's CGPA.
    }

    string searchName;                                      // Declare a string variable to store the name of the student to be searched in the map.
    cout << "\nEnter the name of the student to search : "; // Prompt the user to enter the name of the student they want to search for in the map.
    cin >> searchName;                                      // Read the input from the user and store it in the search Name variable.
    findStudentByName(studentMap, searchName);              // Call the function to find the student by name in the map.

    queue<string> studentQueue; // Create a queue to store student names. The queue is a FIFO (First In, First Out) data structure that allows for adding elements to the back and removing elements from the front.
    for (const auto &student : students)
    {                                    // Iterate through the vector of Student objects to populate the queue. The loop variable student represents each Student object in the vector during each iteration.
        studentQueue.push(student.name); // Add each student's name to the queue using the push() method. This adds the new element at the back of the queue.
    }

    cout << "\n---- Student Names in Queue ----" << endl;
    while (!studentQueue.empty())
    {                                                                                        // Use a while loop to process the queue until it is empty. The empty() method checks if the queue has any elements left.
        cout << "Student " << studentQueue.front() << " is appearing for the exam." << endl; // Output the name of the student at the front of the queue using the front() method. This retrieves the value of the element at the front without removing it.
        studentQueue.pop();                                                                  // Remove the student name from the front of the queue using the pop() method. This removes the element at the front, allowing the next element to become the new front.
    }

    return 0;
}