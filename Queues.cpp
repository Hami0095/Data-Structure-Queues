#include<iostream>
using namespace std;

/// <summary>
/// This queue is VECTOR BASED queue with following functions and the use of function is also given :)
/// Enqueue() -> To Enter new element at the rear of the Queue
/// Dequeue() -> To remove the first element, i.e at Front
/// Peek() -> To return the value at the first i.e front + 1
/// next() -> To get the next value in queue
/// previous() -> not used yet, but it can be used to go back to previous term in queue
/// Empty() -> to tell wether the queue is empty or not?
/// PrintQueue() -> just to check wether our queue is working good?
/// doubleBox() -> to manage our queue
/// get_Number_Of_Elements() -> to check how many elements we have in our queue?
/// </summary>
/// <typeparam name="T"></typeparam>

template<typename T>
class Queue {
private:
	T* box;
	int front;
	int rear;
	int number_Of_Elements;
	int capacity;
public:
	 
	Queue(int cap = 1) {
		capacity = cap;
		front = rear = 0;
		number_Of_Elements = 0;
		if (cap == 0) {
			box = NULL;
		}
		else
			box = new T[cap];
	}

	// No error in is_Empty() 
	bool is_Empty() {
		return (number_Of_Elements == 0);
	}
	// next is working accurately
	int next(int i) {
		return ((i + 1) % capacity);
	}
	// No error in previous()
	int previous(int i) {
		return ((i + (capacity - 1)) % capacity);
	}
	// No error in get_Number_Of_Elements()
	int get_Number_Of_Elements() {
		return number_Of_Elements;
	}
	// no error in Double Box
	void double_Box() {
		capacity *= 2;
		T * temp = new T[capacity];
		for (int i = 1, k = front + 1; i <= number_Of_Elements; i++) {
			temp[i] = box[k];
			k = next(k);
		}
		front = 0;
		rear = number_Of_Elements;
		delete[] box;
		box = temp;
	}
	
	// working great
	const T& peek() {
		T a = box[front];
		return a;
	}
	// working Ok
	void printQueue() {
		cout << "Front is at : " << front << endl;
		cout << "Rear is at : " << rear << endl;
		for (int i = front + 1; i != rear;) {
			cout << "box[" << i << "]" << " : " << box[i] << endl;
			i = next(i);
		}
		
		cout << "------------------------" << endl;
	}
	// working OK -> Enqueue && Dequeue both:
	
	void Enqueue(const T& data);
	void Dequeue();
	~Queue() {
		delete[] box;
	}
};


template<typename T>
void Queue<T>::Enqueue(const T& data) {
	if (number_Of_Elements + 1 == capacity) {
		double_Box();
	}
	rear = next(rear);
	box[rear] = data;
	number_Of_Elements++;
}

template<class T>
void Queue<T> ::Dequeue() {
	front = next(front);
	number_Of_Elements--;
}
