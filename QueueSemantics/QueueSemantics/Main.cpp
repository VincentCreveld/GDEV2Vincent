#include <string>
#include <iostream>
#include "TemplateQueue.h"

template <typename T>
void SortArray(T *array, int sizeArray) {
	for (int i = 0; i<sizeArray - 1; i++)
	{
		for (int j = i + 1; j<sizeArray; j++)
		{
			if (array[i]>array[j])
			{
				T item;
				item = array[i];
				array[i] = array[j];
				array[j] = item;
			}
		}
	}
}

//TemplateQueue<int>* intQueue = new TemplateQueue<int>(40);

int main() {



	/*
	intQueue->Put(10);
	intQueue->Put(20);
	intQueue->Put(7);
	intQueue->Put(2687482);
	intQueue->Put(3782);

	std::cout << intQueue->Size() << std::endl;

	std::cout << intQueue->Peek() << std::endl;

	std::cout << intQueue->Get() + intQueue->Get() << std::endl;

	std::cout << intQueue->Size() << std::endl;

	std::cout << intQueue->Peek() << std::endl;
	*/

	float floatArray[10] = { 1.8f, 1.685f, 2.0f, 10.267f, 10.266f, 3.45f, 3.46f, 8.32f, 1.342f, 1.7f };
	std::string stringArray[10] = { "spagoot", "sten", "steen", "segre" "schaar", "love", "parelketting", "kat", "hond", "doggo" };

	std::cout << "The array consists of" << std::endl;
	for (int i = 0; i<10; i++)
		std::cout << floatArray[i] << std::endl;

	SortArray(floatArray, 10);

	std::cout << "The array sorted" << std::endl;
	for (int i = 0; i<10; i++)
		std::cout << floatArray[i] << std::endl;
	std::cout << std::endl;

	std::cout << "The array consists of" << std::endl;
	for (int i = 0; i<10; i++)
		std::cout << stringArray[i] << std::endl;

	SortArray(stringArray, 10);

	std::cout << "The array sorted" << std::endl;
	for (int i = 0; i<10; i++)
		std::cout << stringArray[i] << std::endl;




	system("pause");
	return 0 ;

}