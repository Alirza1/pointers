#include <iostream>
using namespace std;

/*void main() {
	//1.Pointer to const value
	/*const int value = 10000;
	const int* ptr = &value;*/

	//*ptr = 0; false

	//We can't change value but we can change pointer's value
	/*int value2 = 200;
	ptr = &value2;*/

	//2.Const pointer to value
	/*int value = 10000;
	int value = 20000;
	int*const ptr = &value;*/

	//We can't change address of data in pointer but we can change data in pointer
	//*ptr = 5000;
	
	//ptr = &value2; false

	//Const pointer to const value
	/*const int value = 10000;
	const int* const ptr = &value;
	int a = 10;*/
	//*ptr = 1000; false
	//ptr = &a; false

//}
// Stack'i emeliyyat sistemi idare eliyir
//Heap'in yaddasi ram qederdir

//void main() {
	/*int* ptr = new int(200);
	cout << *ptr << endl;
	delete ptr;
	ptr = nullptr;*/
	//cout << *ptr << endl;

	//double* ptr = new double(12.23);
	//delete ptr; MEMORY LEAK (datanin adresini, datani itirmeden itiririk)

	/*int size = 0;
	cout << "Enter number: ";
	cin >> size;
	int* arr = new int[size] {};

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = i + 10;
	}
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}*/
//}

int* reserveArray(int size) {
	auto arr = new int[size] {};
	return arr;
}

void initArray(int* arr, int *size) {
	int min = 1;
	int max = 1000;
	int random = 0;
	for (size_t i = 0; i < *size; i++)
	{
		random = min + rand() % (max - min);
		arr[i] = random;
	}
}

void printArray(int* arr, int *size) {
	for (size_t i = 0; i < *size; i++)
	{
		cout << arr[i] << " ";
	}cout << endl;
}

int* pushBack(int* arr, int *size, int number) {
	int* newarray = new int[*size + 1]{};
	for (size_t i = 0; i < *size; i++)
	{
		newarray[i] = arr[i];
	}
	newarray[*size] = number;
	delete[]arr; //deletes old data (old array)
	arr = newarray; //updates array
	newarray = arr;
	newarray = nullptr;
	(*size) += 1;
	return arr;
}

int* pushFront(int* arr, int* size, int number) {
	int* newarray = new int[*size + 1]{};
	newarray[0] = number;
	for (size_t i = 1; i < *size; i++)
	{
		newarray[i] = arr[i - 1];
	}
	delete[]arr;
	arr = newarray;
	newarray = arr;
	newarray = nullptr;
	(*size) += 1;
	return arr;
}

int* pushWhereYouWant(int* arr, int* size, int number,int index) {
	int* newarray = new int[*size+1]{};
	for (size_t i = 0; i < index; i++)
	{
		newarray[i] = arr[i];
	}
	newarray[index] = number;
	for (size_t i = index + 1; i < *size + 1; i++)
	{
		newarray[i] = arr[i];
	}
	delete[]arr;
	arr = newarray;
	//newarray = arr;
	newarray = nullptr;
	((*size))++;
	return arr;
}

void main() {
	int size = 0;
	cin >> size;
	auto arr=reserveArray(size);
	initArray(arr, &size);
	printArray(arr, &size);
	//arr = pushBack(arr, &size, 55);
	arr = pushWhereYouWant(arr, &size, 111,2);
	printArray(arr, &size);
}