/*      
 * AUTHOR: Henry Nguyen  
 *
 * CONTACT INFORMATION: henry_nguyen777@hotmail.com
 *
 * CREATION DATE:  April 7 2015
 *
 * PROBLEM STATEMENT:  User may input and configure student data (name, grade, and student id).
 * 
 * PROGRAM DESCRIPTION:     The program will prompt users to input data, which are then put
 *                         into variables, thus storing the data. The data can also be stored into
 *                       the disk, in which the file can be opened. There are other functions also,
 *						such as calculate grade average, sort, and search.
 * RUN INSTRUCTIONS: Input as the console window prompts the instruction.
 *                    List include characters to execute a function, and getlines for storing data.
 */
 
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Student {
	
	string name;	//student name
	int grade;		//student grade
	string studentID;	//student ID
	
};

/*
 * TASK:     Adds a single student to the list
 * ACCEPTS:  string, int
 * RETURNS:  void
 * MODIFIES: passes values into vector, modifies the elements using struct attributes
 */

void addSingleStudent(vector<Student>& students, int& n) {

	system("CLS");

	Student aStudent;		//temp variable for user input struct
	int i = 0;
	cout << "To terminate, enter: \"quit\"" << endl;
	while (i < 1) {
		
	i++;
	cout << "Enter student's name: ";

	getline(cin, aStudent.name);	//input student name
		
	if (aStudent.name == "quit") {	
		break;	
	}
		
	cout << "Enter student's grade: ";
	
	cin >> aStudent.grade;
	cin.ignore(256, '\n');
	stringstream buffer;		//converts a value (from int to string)
	string value;				//holds the value
	buffer << aStudent.grade;	//inserts the int
	value = buffer.str();		//set 'value' to become the contents of the stream
		
	if (value == "quit") {
		aStudent.grade = 0;
		break;
	}
		
	cout << "Enter student's ID: ";
		
	getline(cin, aStudent.studentID);	//get student name
		
	if (aStudent.studentID == "quit") {
		aStudent.studentID = "n/a";
		break;
	}
		
	system("CLS");
		
	students.push_back(aStudent);
	n++;
	}
}

/*
 * TASK:     Adds multiple student to the list
 * ACCEPTS:  string, int
 * RETURNS:  void
 * MODIFIES: passes values into vector, modifies the elements using struct attributes
 */
 
void addStudents(vector<Student>& students, int& n) {
	

	Student aStudent;
	
	while (true) {
		system("CLS");
		cout << "To terminate, enter: \"quit\"" << endl;
		
		cout << "Enter student's name: ";

		getline(cin, aStudent.name);	//input student name
		
		if (aStudent.name == "quit") {	
			break;	
		}
		
		cout << "Enter student's grade: ";

		cin >> aStudent.grade;
		
		stringstream buffer;		//converts a value (from int to string)
		string value;				//holds the value
		buffer << aStudent.grade;	//inserts the int
		value = buffer.str();		//set 'value' to become the contents of the stream
		
		if (value == "quit") {
			aStudent.grade = 0;
			break;
		}
		
		cin.ignore(256, '\n');		//clears the cin
		
		cout << "Enter student's ID: ";
	
		getline(cin, aStudent.studentID);	//get student name

		if (aStudent.studentID == "quit") {
			aStudent.studentID = "n/a";
			break;
		}
		
		students.push_back(aStudent);
		
		n++;
		
	}
}

/*
 * TASK:     edits a student name
 * ACCEPTS:  string
 * RETURNS:  void
 * MODIFIES: passes values into vector, modifies the string name of the struct
 */

void editStudentName(vector<Student>& students, int n) {
	

	system("CLS");
	Student aStudent;
	string target;		//target of user input
	bool flag = false;	//flag to determine if target is found
	cout << "Enter a student's' name: " << endl;
	getline(cin, target);
	for (int i = 0; i < n; i++) {
		
		if (target == students[i].name) {
			
			cout << "The name " << target << " is in index " << i << endl <<
			"Replace name with: ";
			getline(cin, aStudent.name);
			students[i].name = aStudent.name;
			flag = true;
		}
	}	
	if (flag == false) {
		
		cout << "The name cannot be found. Please try again." << endl;
	
	}
}

/*
 * TASK:     edits a student grade
 * ACCEPTS:  string, int
 * RETURNS:  void
 * MODIFIES: passes values into vector, modifies the int grade of the struct
 */

void editStudentGrade(vector<Student>& students, int n) {
	

	system("CLS");
	Student aStudent;
	string target;
	bool flag = false;
	cout << "Enter a student's' name:  " << endl;
	getline(cin, target);
	for (int i = 0; i < n; i++) {
		
		if (target == students[i].name) {
			
			cout << "The name " << target << " is in index " << i << " and has the grade of %" <<
			students[i].grade << endl <<
			"Replace grade with: ";
			cin >> aStudent.grade;
			students[i].grade = aStudent.grade;
			flag = true;
		}
	}	
	if (flag == false) {
		
		cout << "The name cannot be found. Please try again." << endl;
	
	}
	
}

/*
 * TASK:     edits a student ID
 * ACCEPTS:  string
 * RETURNS:  void
 * MODIFIES: passes values into vector, modifies the string studentID of the struct
 */

void editStudentID(vector<Student>& students, int n) {
	

	system("CLS");
	Student aStudent;
	string target;
	bool flag = false;
	cout << "Enter a student's' name: " << endl;
	getline(cin, target);

	for (int i = 0; i < n; i++) {
		
		if (target == students[i].name) {
			
			cout << "The name " << target << " is in index " << i << endl <<
			"Student ID: " << students[i].studentID << endl <<
			"Replace student ID with: ";
			cin >> aStudent.studentID;
			students[i].studentID = aStudent.studentID;
			flag = true;
		}
	}	
	if (flag == false) {
		
		cout << "The name cannot be found. Please try again." << endl;
	
	}
}

/*
 * TASK:     removes a student
 * ACCEPTS:  string
 * RETURNS:  void
 * MODIFIES: passes values into vector, erase the vector element
 */
 
void removeStudent(vector<Student>& students, int& n) {
	system("CLS");
	string target;
	bool flag = false;
	cout << "Enter student's name: " << endl;
	getline(cin, target);
	
	for (int i = 0; i < n; i++) {
		if (target == students[i].name) {
			cout << "The student, " << students[i].name << ", has been removed" << endl;
			students.erase(students.begin() + i);
			flag = true;
		}
	}
	if (flag == false)	{
		cout << "The name cannot be found." << endl;
	}

}
/*
 * TASK:     displays student list
 * ACCEPTS:  void
 * RETURNS:  void
 * MODIFIES: void
 */
void displayStudents(const vector<Student> students, int n) {
	
	system("CLS");	
	
	if (n >= 1) {
	
		for (int i = 0; i < n; i++) {
			cout << endl << 
			"Student name: " << students[i].name << endl <<
			"Student grade: %" << students[i].grade << endl <<
			"Student ID: " << students[i].studentID << endl;	
		}
	} else {
		cout << "There is currently no data recorded." << endl;
	}
	
	system("PAUSE"); 	//This prompts the user to enter a key so that the function doesn't end
}

/*
 * TASK:     display the information of a single student
 * ACCEPTS:  string
 * RETURNS:  void
 * MODIFIES: void
 */
void displaySearch(vector<Student> students, int n) {
	
	system("CLS");
	Student aStudent;
	string target;
	bool flag = false;
	cout << "Enter a student's' name: ";
	getline(cin, target);

	for (int i = 0; i < n; i++) {
		
		if (target == students[i].name) {
			
			cout <<	"Index: " << i << endl
			<< "Student Name: " << students[i].name << endl 
			<< "Student ID: " << students[i].studentID << endl
			<< "Student Grade: " << students[i].grade << endl;
			flag = true;
		}
	}	
	if (flag == false) {
		
		cout << "The name cannot be found. Please try again." << endl;
	
	}
	system("PAUSE");
}

/*
 * TASK:     bubble sort names alphabetically
 * ACCEPTS:  void
 * RETURNS:  void
 * MODIFIES: rearranged vector indexes
 */
void sortNames(vector<Student>& students, int n) {	//the reason why you need an ambersand(&), is because
								//vectors are pass-by values. Arrays are pass-by references, so you don't need it.
								//thus, you need to assign pass-by refence to functions involving vectors.
			
	system("CLS");
	for (int i = 1; i< n; i++) {
	
		for (int j = 0; j < n - i; j++) {
			
			if (students[j+1].name < students[j].name) swap(students[j], students[j+1]);	
		}
	}
	
	cout << "Names have been rearranged alphabetically. Display table to check." << endl;
	system("PAUSE");
	
}

/*
 * TASK:     bubble sort grades 
 * ACCEPTS:  void
 * RETURNS:  void
 * MODIFIES: rearranged vector indexes
 */
void sortGrades(vector<Student>& students, int n) {	//the reason why you need an ambersand(&), is because
								//vectors are pass-by values. Arrays are pass-by references, so you don't need it.
								//thus, you need to assign pass-by refence to functions involving vectors.
			
	system("CLS");
	for (int i = 1; i< n; i++) {
	
		for (int j = 0; j < n - i; j++) {
			
			if (students[j+1].grade > students[j].grade) swap(students[j], students[j+1]);	
		}
	}
	
	cout << "Names have been rearranged based on grades. Display table to check." << endl;
	system("PAUSE");
	
}

/*
 * TASK:     saves file
 * ACCEPTS:  void
 * RETURNS:  void
 * MODIFIES: void
 */
void saveFile(const vector<Student> students, int n) {
	
	system("CLS");

	ofstream fout("students.txt", ios::app);	//write to file
	
	if (!fout.fail()) {
	
		for (int i = 0; i < n; i++) {
			fout << students[i].name << ";";
			fout << students[i].grade << ";";
			fout << students[i].studentID;
			if (i < n - 1) {
				fout << endl;
			}
			
		}
	cout << "Student record has been saved to the file: \"students.txt\"" << endl;
	fout.close();
	system("PAUSE");
	} else {
		
		cout << "ERROR: Unable to read file." << endl;
		fout.close();
		system("PAUSE");
	}

}

/*
 * TASK:     opens file
 * ACCEPTS:  void
 * RETURNS:  void
 * MODIFIES: values are passed into vector, increment n as size
 */
void openFile(vector<Student>& students, int& n) {

	system("CLS");
	ifstream fin("students.txt");	//open file
	string temp;		//temp to hold vector value
	stringstream ss;	//conversion of students.age
	Student aStudent;	//increase vector size since it starts at 0
	students.push_back(aStudent);	//above
	n = 0;
	
	if (!fin.fail()) {
 	
		while(!fin.eof() && n < students.size()) {

			getline(fin, temp, ';'); 
			students[n].name = temp;

			getline(fin, temp, ';');
			ss.str(""); 
			ss.clear();
			ss << temp; 
			ss >> students[n].grade;
      
      		getline(fin, temp); 
			students[n].studentID = temp;

			n++;
			students.push_back(aStudent);
   		} 
   	students.pop_back();
   	cout << "File has been opened." << endl;
   	system("PAUSE");
	} else {
		cout << "ERROR: Unable to read file." << endl;
		system("PAUSE");
	}
	fin.close();
}

/*
 * TASK:     calculates student list average grades
 * ACCEPTS:  void
 * RETURNS:  void
 * MODIFIES: void
 */
void gradeAverage(const vector<Student> students, int n) {
	
	system("CLS");	
	int sum = 0;
	if (n > 1) {
	
		for (int i = 0; i < n; i++) {
			sum+= students[i].grade;	
		}
	} else {
		cout << "There is currently no data recorded." << endl;
	}
	cout << "Class GPA is: " << sum/n << endl;
	system("PAUSE"); 	//This prompts the user to enter a key so that the function doesn't end
}

/*
 * TASK:     receive character input to return to the switch statement
 * ACCEPTS:  char
 * RETURNS:  char
 * MODIFIES: void
 */
char getInput() {
	system("CLS");
	cout <<"What would you like to do? Enter one of the following characters: " << endl <<
	"To exit the program, enter: \"quit\"" << endl <<
	"----------------------------" << endl << 
	"\t \n Add" << setw(65) << "(Z) - Open File"  << endl <<
		"\t (O)ne Student" << setw(43) << "(S)ave File" << endl <<
		"\t (M)ultiple Students" << endl <<
	"\t \n Edit Student" << endl <<
		"\t (N)ames" << endl <<
		"\t (G)rades" << endl <<
		"\t (I)Ds" << endl <<
	"\t \n Remove" << endl <<
		"\t (R)emove Student" << endl <<
	"\t \n Sort" << endl <<
		"\t (A)lphabetically (by name, ascending)" << endl <<
		"\t (P)oints (by grade points, ascending)" << endl <<
	"\t \n Display" << endl << 
		"\t (F)ind Student" << endl <<
		"\t (D)isplay Student List" << endl <<
		"\t (C)alculate Grade Point Average" << endl;
	cout << ">";
	char input;
	cin >> input;
	cin.ignore(256, '\n');
	return input;
	
}

/*
 * TASK:     default case, in which it notifies of invalid input
 * ACCEPTS:  void
 * RETURNS:  void
 * MODIFIES: void
 */
void invalid() {
	system("CLS");
	cout << "Invalid Input. Please try again." << endl;
	system("PAUSE");
}

/*
 * TASK:     declarations and calling functions
 * ACCEPTS:  void
 * RETURNS:  void
 * MODIFIES: void
 */
int main() {
	
	system("CLS");
	int n = 0;	//This is the number of students
	vector<Student> students;	//declaration of vector
	bool run = true;	//will run as long as it is true
	
	while (run) {

	switch (toupper(getInput())) {

			case 'O': addSingleStudent(students, n); break;
			case 'M': addStudents(students, n); break;
			case 'N': editStudentName(students, n); break;
			case 'G': editStudentGrade(students, n); break;
			case 'I': editStudentID(students, n); break; 
			case 'R': removeStudent(students, n); break;
			case 'D': displayStudents(students, n);break;
			case 'F': displaySearch(students, n); break;
			case 'A': sortNames(students, n); break;
			case 'P': sortGrades(students, n); break;
			case 'Z': openFile(students, n); break;
			case 'S': saveFile(students, n); break;
			case 'C': gradeAverage(students, n); break;
			case 'Q': run = false; break; 
			default: invalid(); break;
		}
	}
	
	cout << "End." << endl;
}
	


