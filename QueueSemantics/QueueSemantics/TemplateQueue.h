#pragma once
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

template<class T>
class TemplateQueue{
public:
	TemplateQueue(T obj) {
		objArray[0] = obj;
		//objArray = new T[0];
		//tempArray = T[0];
	}

	void Put(T obj) {
		//Add tempArray to heap
		int arraySize = Size() + 1;
		tempArray = T[arraySize];
		//Fill tempArray with current array
		for (int i = 0; i < Size(); i++)
		{
			tempArray[i] = objArray[i];
		}

		//Add new object to tempArray
		tempArray[arraySize] = obj;

		//Destroy current Array
		destroy(objArray);

		//Create new Array
		objArray = T[arraySize] ;

		//Set new Array equals to tempArray
		objArray = tempArray;
	}
	T Get() {
		T obj;

		//Add tempArray to heap
		int arraySize = Size() - 1;
		tempArray = T[arraySize];
		obj = objArray[0];

		//Fill tempArray with current array
		for (int i = 1; i < Size(); i++)
		{
			tempArray[i-1] = objArray[i];
		}

		//Destroy current Array
		//destroy(objArray);

		//Create new Array
		objArray = T[arraySize] ;

		//Set new Array equals to tempArray
		objArray = tempArray;

		return obj;
	}

	T Peek() {
		return objArray[0];
	}

	int Size() {
		int size = my_sizeof(objArray) / my_sizeof(objArray[0]);
		return size;
	}
private: 
	T objArray[1];
	T tempArray[1];
};