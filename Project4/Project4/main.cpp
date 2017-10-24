#include <vector>
#include <iostream>
#include <mutex>
#include <thread>

std::thread thread;
std::mutex mutex;
int lastAddedNum;

class concurrent_vector
{
public:
	concurrent_vector() {
		intVect = std::vector<int>();
	};
	void AddToVectorUnsafe(int n) {
		intVect.push_back(n);
		lastAddedNum = n;
	};
	void AddToVectorSafe(int n) {
		mutex.lock();
		intVect.push_back(n);
		lastAddedNum = n;
		mutex.unlock();
	};
	void ClearClass() {
		intVect.clear();
	}

private:
	std::vector<int> intVect;
};

concurrent_vector* cVector = new concurrent_vector();

void AddNumbersUnsafe() {
	std::vector<std::thread> threads;
	for (int i = 0; i < 100; i++)
	{
		threads.push_back(std::thread(&concurrent_vector::AddToVectorUnsafe, cVector, i));
	}

	for (auto& thread : threads) {
		thread.join();
	}

	std::cout << lastAddedNum;
}
void AddNumbersSafe() {
	std::vector<std::thread> threads;
	for (int i = 0; i < 100; i++)
	{
		threads.push_back(std::thread(&concurrent_vector::AddToVectorSafe, cVector, i));
	}

	for (auto& thread : threads) {
		thread.join();
	}

	std::cout << lastAddedNum;
}

int main() {

	for (int i = 0; i < 2000; i++)
	{
		cVector->ClearClass();
		lastAddedNum = 0;
		AddNumbersUnsafe();
		//AddNumbersSafe();
		std::cout << "        " << i << std::endl;
	}
	system("pause");
	return 0;
}