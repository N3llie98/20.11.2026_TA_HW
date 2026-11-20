#include <iostream>
using namespace std;

struct Bus {
	string model;
	string color;
	unsigned int year;
	unsigned int capacity;
	void print() const {
		cout << "Model: " << model << "\nColor: " << color
			<< "\nYear: " << year << "\nCapacity: " << capacity << endl;
	}
};
void printBusArr(Bus arr[], size_t n) {
	for (size_t i = 0; i < n; ++i) {
		cout << " -- BUS " << i + 1 << " --\n";
		arr[i].print();
	}
}

//Insertion sort ascending
void busSortByYear(Bus arr[], size_t n)
{
	if (arr == nullptr || n <= 1) {
		return;
	}
	for (size_t i = 1; i < n; ++i) {
		Bus element = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j].year > element.year) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = element;
	}
}
//Insertion sort descending
void busSortByCapacity(Bus arr[], size_t n)
{
	if (arr == nullptr || n <= 1) {
		return;
	}
	for (size_t i = 1; i < n; ++i) {
		Bus element = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j].capacity < element.capacity) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = element;
	}
}

int main() {
	const int N = 5;
	Bus arr[N]{
		{"Mercedes", "Red", 2015, 50},
		{"Volvo", "Blue", 2018, 60},
		{"Scania", "White", 2020, 55},
		{"MAN", "Green", 2017, 45},
		{"Iveco", "Yellow", 2019, 65}
	};
	cout << "==== BUS ARRAY INITIAL ====\n";
	printBusArr(arr, N);

	cout << "\n==== BUS SORTED BY YEAR (ASCENDING) ====\n";
	busSortByYear(arr, N);
	printBusArr(arr, N);

	cout << "\n==== BUS SORTED BY CAPACITY (DESCENDING) ====\n";
	busSortByCapacity(arr, N);
	printBusArr(arr, N);
	return 0;
}