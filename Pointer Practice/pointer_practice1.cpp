//Pointer Practice :)

#include <iostream>

using namespace std;
void display_array(double* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}
void sort_array(double *arr, int size) {
	double temp;
	for (int a = 0; a < size; a++) {
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}
double get_average(double* arr, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum / size;
}
double get_average_drop_lowest(double* arr, int size) {
	double sum = 0;
	for (int i = 1; i < size; i++) {
		sum += arr[i];
	}
	return sum / (size-1);
}
int main() {
	double* grade_array = nullptr;
	cout << "How many test grades are there?\n";
	int num_of_grades;
	cin >> num_of_grades;
	grade_array = new double[num_of_grades];
	for (int i = 0; i < num_of_grades; i++) {
		cout << "What is the score of grade " << i + 1 << endl;
		cin >> grade_array[i];

	}
	//display_array(grade_array, num_of_grades);
	cout << "Now Sorted:\n";
	sort_array(grade_array, num_of_grades);
	display_array(grade_array, num_of_grades);
	cout << "Average: " << get_average(grade_array, num_of_grades);
	cout << " Average Drop Lowest: " << get_average_drop_lowest(grade_array, num_of_grades);
	return 0;
}