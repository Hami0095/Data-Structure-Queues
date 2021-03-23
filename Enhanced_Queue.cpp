/// Summary 
/// This queue has special feature that you can enqueue at rear and front both
/// Plus dequeue at front and rear 
template<typename T>
class EnhancedQueue {
private:
	T* box;
	int front;
	int rear;
	int no_Of_Elements, capacity;

public:
	
	// Constructor :-
	EnhancedQueue(int cap = 0) {
		Capacity = cap;
		if (cap == 0)
			box = nullptr;
		else
			box = new T[cap];
		front = rear = 0;
		no_Of_Elements = 0;
	}
	int next(int i) {
		return ((i + 1) % capacity);
	}
	int previous(int i) {
		return ((i + (capacity - 1)) % capacity);
	}
	void double_Box() {
		capacity *= 2;
		T* temp = new T[capacity];
		for (int i = 1, k = front + 1; i <= number_Of_Elements; i++) {
			temp[i] = box[k];
			k = next(k);
		}
		front = 0;
		rear = number_Of_Elements;
		delete[] box;
		box = temp;
	}
	void half_Box() {
		capacity /= 2;
		T* temp = new T[capacity];
		for (int i = 1, k = front + 1; i <= number_Of_Elements; i++) {
			temp[i] = box[k];
			k = next(k);
		}
		front = 0;
		rear = number_Of_Elements;
		delete[] box;
		box = temp;
	}
	void enqueueAtFront(T& data) {
		if (no_Of_Elements + 1 >= capacity) {
			double_Box();
		}
		box[front] = data;
		front = previous(front);
		no_Of_Elements++;
	}
	// as in usual queue
	void enqueueAtRear(T& data) {
		if (number_Of_Elements + 1 >= capacity) {
			double_Box();
		}
		rear = next(rear);
		box[rear] = data;
		number_Of_Elements++;
	}
	// usually in queue dequeue occurs at front
	void dequeueAtFront() {
		if ( (no_Of_Elements + 1) <=( capacity / 2) ) {
			half_Box();
		}
		front = next(front);
		number_Of_Elements--;
	}

	// rear to move back in circular order 
	// and elements-- , since it is dequeue after all

	void dequeueAtRear() {
		if ( (no_Of_Elements + 1) <= (capacity / 2) ) {
			half_Box();
		}
		rear = previous(rear);
		no_Of_Elements--;
	}
	const T& peekFront() {
		T a = box[front];
		front = next(front);
		return a;
	}
	const T& peekRear() {
		T a = box[rear];
		rear = next(rear);
		return a;
	}
	int size() {
		return no_Of_Elements;
	}
	bool empty() {
		return (no_Of_Elements == 0);
	}

};
