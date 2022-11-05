#include <iostream>
#include <string>
using namespace std;
/*allow the user to enter name-score
pairs. For each student taking a test, the user types the student’s name followed by the
student’s integer test score. Modify the sorting function so it takes an array holding
the student names and an array holding the student test scores. When the sorted list
of scores is displayed, each student’s name should be displayed along with his or her
score. In stepping through the arrays, use pointers rather than array subscripts*/
void sort_array(double* arr, string* name_arr, int size) {
	double grade_temp;
	string name_temp;
	for (int a = 0; a < size; a++) {
		for (int i = 0; i < size - 1; i++) {
			if (*(arr + i) > *(arr + i + 1)) {
				grade_temp = *(arr + i);
				name_temp = *(name_arr + i);
				*(arr + i) = *(arr + i + 1);
				*(name_arr + i) = *(name_arr + i + 1);
				*(arr + i + 1) = grade_temp;
				*(name_arr + i + 1) = name_temp;
			}
		}
	}
	
}
void display_array(double* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}
void display_array(string* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}
int main() {
	string* name_ptr = nullptr;
	double* grade_ptr = nullptr;
	int num_of_students;
	cout << "How many students are there? \n";
	cin >> num_of_students;
	name_ptr = new string[num_of_students];
	grade_ptr = new double[num_of_students];
	for (int i = 0; i < num_of_students; i++) {
		cout << "What is the name of student " << i + 1 << endl;
		cin >> name_ptr[i];
		cout << "What is the grade of student " << i + 1 << endl;
		cin >> grade_ptr[i];
	}
	cout << "****************Before Sorting*************************\n";
	display_array(name_ptr, num_of_students);
	display_array(grade_ptr, num_of_students);
	sort_array(grade_ptr, name_ptr, num_of_students);
	cout << "****************After Sorting*************************\n";
	display_array(name_ptr, num_of_students);
	display_array(grade_ptr, num_of_students);
	return 0;
}