#pragma once
#include <vector>

template<class T>
class TemplateQueue{
public:
	TemplateQueue(T obj) {
		queue = new std::vector<T>();
		Put(obj);
	}

	void Put(T obj) {
		queue->push_back(obj);
	}

	T Get() {
		T obj;
		obj = queue->front();
		queue->erase(queue->begin());
		return obj;
	}

	T Peek() {
		return queue->front();
	}

	int Size() {
		return queue->size();
	}
private: 
	std::vector<T>* queue;
};