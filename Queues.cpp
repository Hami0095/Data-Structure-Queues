#include<iostream>
using namespace std;

/// <summary>
/// This queue is VECTOR BASED queue
/// 
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
	bool Empty() {
		return size == 0;
	}
	int next(int i) {
		return ((i + 1) % capacity);
	}
	int previous(int i) {
		return ((i + (capacity - 1)) % capacity);
	}
	int get_Number_Of_Elements() {
		return number_Of_Elements;
	}
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
	const T & peek() {
		T a = box[front];
		front = next(front);
		return a;
	}
	void printQueue() {
		cout << "Front is at : " << front << endl;
		cout << "Rear is at : " << rear << endl;
		for (int i = front + 1; i != rear;) {
			cout << "box[" << i << "]" << " : " << box[i] << endl;
			i = next(i);
		}
		
		cout << "------------------------" << endl;
	}
	void Enqueue(const T& data);
	const T& Dequeue();
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
const T& Queue<T> ::Dequeue() {
	front = previous(front);
	number_Of_Elements--;
}
