#pragma once

class arrayQueue 
{
public:
	arrayQueue(int initialCapacity = 5);
	~arrayQueue() { delete[] queue; }
	bool empty() const { return  -1==theBack; }
	int size() const { return theBack + 1; };
	int getBack()const { return theBack; };
	void push(const int& theElement);
	void output()const;
	bool search(int n);

private:
	int theBack;       // position of theBack element
	int arrayLength;    // queue capacity
	int* queue;           // element array
};

arrayQueue::arrayQueue(int initialCapacity)
{// Constructor.
	if (initialCapacity < 1)
		throw std::out_of_range("Capacity < 1");
	arrayLength = initialCapacity;
	queue = new int[arrayLength];
	theBack = -1;
}

void arrayQueue::push(const int& theElement) {
	if (theBack == arrayLength - 1) {
		for (int i = 0; i < this->theBack; i++)
			queue[i] = queue[i + 1];
		theBack--;
	}
		queue[++theBack] = theElement;
}

void arrayQueue::output() const {
	if (-1 == theBack) return;
	for (int i = 0; i < this->size(); i++)
		std::cout << queue[i] << " ";
	std::cout << std::endl;
}

bool arrayQueue::search(int n) {
	for (int i = 0; i < this->size(); i++) {
		if (queue[i] == n) {
			for (int j = i; j < this->size()-1; j++) {
				queue[j] = queue[j + 1];
			}
			queue[theBack] = n;
			return true;
		}
	}
	return false;
}
