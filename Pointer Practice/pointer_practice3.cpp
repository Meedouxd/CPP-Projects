/*Write a function that accepts as arguments the following:
A) An array of integers
B) An integer that indicates the number of elements in the array
The function should determine the mode of the array. That is, it should determine
which value in the array occurs most often. The mode is the value the function should
return. If the array has no mode (none of the values occur more than once), the func-
tion should return −1. (Assume the array will always contain nonnegative values.)
Demonstrate your pointer prowess by using pointer notation instead of array notation
in this function.
*/
#include <iostream>

using namespace std;

void display_array(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}

int getBiggestValue(int* arr, int size) {
	int biggest = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > biggest) {
			biggest = arr[i];
		}
	}
	return biggest;
}
bool contains(int* arr, int size, int num) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == num) {
			return true;
		}
	}
	return false;
}
int getMode(int* arr, int size) {
	int* unique_ints = new int[size];
	int* unique_ints_num = new int[size];
	int pos = 0;
	int mode = -1;
	//Set all the initial values of unique_ints and unique_ints_num to -1
	for (int i = 0; i < size; i++) {
		unique_ints[i] = -1;
		unique_ints_num[i] = -1;
	}
	//find all unique ints in the argument array.
	for (int i = 0; i < size; i++) {
		if (!contains(unique_ints, size, arr[i])) {
			unique_ints[pos] = arr[i];
			unique_ints_num[pos] = 0;
			pos++;
		}
	}
	for (int i = 0; i < size; i++) {
		if (unique_ints[i] == -1) break;
		for (int a = 0; a < size; a++) {
			if (arr[a] == unique_ints[i]) {
				unique_ints_num[i] += 1;
			}
		}
	}
	pos = getBiggestValue(unique_ints_num, size);
	for (int i = 0; i < size; i++) {
		if (unique_ints_num[i] == pos) {
			return unique_ints[i];
		}
	}
	return -1;
}
int main() {
	int size_of_array;
	int* arr = nullptr;
	cout << "How big is the array?\n";
	cin >> size_of_array;
	arr = new int[size_of_array];
	for (int i = 0; i < size_of_array; i++) {
		cout << "What is the value of number " << i + 1 << endl;
		cin >> arr[i];
	}
	cout << "Heres the array.\n";
	display_array(arr, size_of_array);
	int mode = getMode(arr, size_of_array);
	if (mode != !1)
		cout << "The mode is : " << mode << endl;
	else
		cout << "There is no mode\n";
	return 0;
}