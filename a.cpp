1.// Write a program to compute the sum of the first n terms of 
//the following series:
 //= 1-1/2�+1/3�-1/44+1/55-�..
//The number of terms n is to be taken from the user through 
//the command line. If the command line argument is not found 
///then prompt the user to enter the value of n.
//CODE
#include <iostream>
#include <cstdlib>
Using namespace std;
int computeSum(int n) {
 int total = 0;
 int sign = 1;
 for (int i = 1; i <= n; ++i) {
 int term = i * sign;
 total += term;
 sign *= -1;
 }
 return total;
}
int main(int argc, char** argv) {
 int n;
 if (argc > 1) {
 n = atoi(argv[1]);
 } else {
 cout << "Enter the value of n: ";
 cin >> n;
 }
 int result = computeSum(n);
 cout << "Sum of the first " << n << " terms: " << result << endl;
 return 0;
}
//2. Write a program to remove the duplicates from an array.
CODE
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
vector<int> removeDuplicates(const vector<int>& arr) {
 unordered_set<int> uniqueElements;
 vector<int> result;
 for (int num : arr) {
 if (uniqueElements.find(num) == uniqueElements.end()) {
 uniqueElements.insert(num);
 result.push_back(num);
 }
 }
 return result;
}
int main() {
 // Example usage
 vector<int> arr = {1, 2, 3, 4, 2, 3, 5, 6, 1, 4};
 vector<int> result = removeDuplicates(arr);
 cout << "Original array: ";
 for (int num : arr) {
 cout << num << " ";
 }
 cout << "\nArray with duplicates removed: ";
 for (int num : result) {
 cout << num << " ";
 }
 cout << endl;
 return 0;
}
//5. Write a program to merge two ordered arrays to get a 
single ordered array.
CODE
#include <iostream>
#include <vector>
using namespace std;
vector<int> mergeArrays(const vector<int>& arr1, const vector<int>& arr2) {
 vector<int> merged;
 int i = 0, j = 0;
 while (i < arr1.size() && j < arr2.size()) {
 if (arr1[i] <= arr2[j]) {
 merged.push_back(arr1[i]);
 i++;
 } else {
 merged.push_back(arr2[j]);
 j++;
 }
 }
 // Add remaining elements from arr1, if any
 while (i < arr1.size()) {
 merged.push_back(arr1[i]);
 i++;
 }
 // Add remaining elements from arr2, if any
 while (j < arr2.size()) {
 merged.push_back(arr2[j]);
 j++;
 }
 return merged;
}
int main() {
 // Example usage
 vector<int> arr1 = {1, 4, 6, 8, 9};
 vector<int> arr2 = {2, 3, 5, 7};
 vector<int> merged = mergeArrays(arr1, arr2);
 cout << "Merged Array: ";
 for (int num : merged) {
 cout << num << " ";
 }
 cout << endl;
 return 0;
}
//6. Write a program to search a given element in a set of N 
numbers using Binary search
(i) with recursion (ii) without recursion.
CODE
#include <iostream>
#include <vector>
using namespace std;
// Binary search with recursion
int binarySearchRecursive(const vector<int>& nums, int target, int left, int right) {
 if (left > right) {
 return -1; // Element not found
 }
 int mid = left + (right - left) / 2;
 if (nums[mid] == target) {
 return mid; // Element found at index mid
 } else if (target < nums[mid]) {
 return binarySearchRecursive(nums, target, left, mid - 1); // Search in the left 
half
 } else {
 return binarySearchRecursive(nums, target, mid + 1, right); // Search in the 
right half
 }
}
// Binary search without recursion
int binarySearchIterative(const vector<int>& nums, int target) {
 int left = 0;
 int right = nums.size() - 1;
 while (left <= right) {
 int mid = left + (right - left) / 2;
 if (nums[mid] == target) {
 return mid; // Element found at index mid
 } else if (target < nums[mid]) {
 right = mid - 1; // Search in the left half
 } else {
 left = mid + 1; // Search in the right half
 }
 }
 return -1; // Element not found
}
int main() {
 vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15};
 int target = 9;
 // Binary search with recursion
 int indexRecursive = binarySearchRecursive(nums, target, 0, nums.size() - 1);
 if (indexRecursive != -1) {
 cout << "Element found at index (using recursion): " << indexRecursive << 
endl;
 } else {
 cout << "Element not found (using recursion)" << endl;
 }
 // Binary search without recursion
 int indexIterative = binarySearchIterative(nums, target);
 if (indexIterative != -1) {
 cout << "Element found at index (without recursion): " << indexIterative << 
endl;
 } else {
 cout << "Element not found (without recursion)" << endl;
 }
 return 0;
}
//7. Write a program to calculate GCD of two numbers (i) with 
recursion (ii) without recursion.
CODE
#include <iostream>
using namespace std;
// Function to calculate GCD using recursion
int gcdRecursive(int a, int b) {
 if (b == 0)
 return a;
 return gcdRecursive(b, a % b);
}
// Function to calculate GCD without recursion
int gcdIterative(int a, int b) {
 while (b != 0) {
 int temp = b;
 b = a % b;
 a = temp;
 }
 return a;
}
int main() {
 int num1, num2;
 cout << "Enter two numbers: ";
 cin >> num1 >> num2;
 // Using recursion
 int gcdRecursiveResult = gcdRecursive(num1, num2);
 cout << "GCD using recursion: " << gcdRecursiveResult << endl;
 // Without recursion
 int gcdIterativeResult = gcdIterative(num1, num2);
 cout << "GCD without recursion: " << gcdIterativeResult << endl;
 return 0;
}
//9. Define a class Person having name as a data member. 
Inherit two classes Student and Employee from Person. 
Student has additional attributes as course, marks and year 
and Employee has department and salary. Write display() 
method in all the three classes to display the corresponding 
attributes. Provide the necessary methods to show runtime
polymorphism.
CODE
#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
 string name;
public:
 Person(const string& n) : name(n) {}
 virtual void display() {
 cout << "Name: " << name << endl;
 }
};
class Student : public Person {
private:
 string course;
 int marks;
 int year;
public:
 Student(const string& n, const string& c, int m, int y) : Person(n), course(c), 
marks(m), year(y) {}
 void display() override {
 cout << "Name: " << name << endl;
 cout << "Course: " << course << endl;
 cout << "Marks: " << marks << endl;
 cout << "Year: " << year << endl;
 }
};
class Employee : public Person {
private:
 string department;
 double salary;
public:
 Employee(const string& n, const string& d, double s) : Person(n), 
department(d), salary(s) {}
 void display() override {
 cout << "Name: " << name << endl;
 cout << "Department: " << department << endl;
 cout << "Salary: " << salary << endl;
 }
};
int main() {
 Person* p1 = new Person("John Doe");
 Person* p2 = new Student("Jane Smith", "Computer Science", 90, 2022);
 Person* p3 = new Employee("Mike Johnson", "Human Resources", 5000.0);
 p1->display();
 p2->display();
 p3->display();
 delete p1;
 delete p2;
 delete p3;
 return 0;
}
//12. Copy the contents of one text file to another file, after
removing all whitespaces.
CODE
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
int main() {
 ifstream inputFile("input.txt");
 ofstream outputFile("output.txt");
 if (!inputFile) {
 cerr << "Error opening input file." << endl;
 return 1;
 }
 if (!outputFile) {
 cerr << "Error creating output file." << endl;
 return 1;
 }
 string line;
 while (getline(inputFile, line)) {
 line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
 outputFile << line << endl;
 }
 cout << "Contents copied successfully." << endl;
 inputFile.close();
 outputFile.close();
 return 0;
}

