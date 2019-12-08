
template<typename T>
class arrayStack  {
public:
	arrayStack(int initialCapacity = 2);
	~arrayStack() { delete[] stack; }
	bool empty() const { return stackTop == -1; };
	int size() const { return stackTop + 1; };
	T& top()const {
		if (-1 == stackTop)
			throw std::out_of_range("stackTop = -1");
		return stack[stackTop];
	};
	void pop() {
		if (-1 == stackTop)
			throw std::out_of_range("stackTop = -1");
		//stack[stackTop--].~T();
		--stackTop;
	}
	void push(const T& theElement);
	void output(std::ostream& out)const;
private:
	int stackTop;         // current top of stack
	int arrayLength;      // stack capacity
	T* stack;           // element array
};

template<typename T>
arrayStack<T>::arrayStack(int initialCapacity) {
	if (initialCapacity < 1)
		throw std::invalid_argument("initialCapacity < 1");
	arrayLength = initialCapacity;
	stack = new T[arrayLength];
	stackTop = -1;
}

template<typename T>
void arrayStack<T>::push(const T& theElement) {
	if (stackTop == arrayLength - 1) {
		throw std::out_of_range("stack full!");
	}
	stack[++stackTop] = theElement;
}

template<class T>
void arrayStack<T>::output(std::ostream& out) const {
	std::copy(stack, stack + stackTop + 1, std::ostream_iterator<T>(out, "  "));
	out << std::endl;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const arrayStack<T>& x) {
	x.output(out);
	return out;
}