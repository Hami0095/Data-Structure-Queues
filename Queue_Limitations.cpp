#include<iostream>
#include<queue>
using namespace std;


void EmptyQueue(queue<int>& q) {
	while (!q.empty()) {
		q.pop();
	}
}

void copyQueue(queue<int>& source, queue<int>& dest) 
{
	while (!source.empty()) {
		int front = source.front();
		source.pop();
		dest.push(front);
	}
	EmptyQueue(source);
}


void SortUsingTwoQueues() 
{
	queue<int> q;
	queue<int> temp1;
	queue<int> temp2;

	// data in q
	q.push(5);
	q.push(13);
	q.push(0);
	q.push(1);
	q.push(2);


	// add one check here
	if (q.size() <= 1) {		// queue with less or equal to 1 size is already in sorted order 
		return;
	}

	int frontOfQue = q.front();
	q.pop();
	temp1.push(frontOfQue);

	while (!q.empty()) {

		frontOfQue = q.front();
		q.pop();


		bool isFrontPushed = false;		// to check either frontofQue is pushed in temp2 or not
		// move all elements of temp1 in temp2 que which are less than 'a' [a --> front of 'q' que] 
		while (!temp1.empty()) {
			int temp = temp1.front();

			if (temp < frontOfQue) {
				temp2.push(temp);
			}
			else {
				temp2.push(frontOfQue);
				isFrontPushed = true;
				break;
			}
			temp1.pop();
		}

		// insert remaining elements of temp1 que in temp2 que
		while (!temp1.empty())
		{
			int temp = temp1.front();
			temp1.pop();
			temp2.push(temp);
		}


		// if front is not pushed in temp2 yet, push it
		if (!isFrontPushed) {
			temp2.push(frontOfQue);
		}
		copyQueue(temp2, temp1);
	}

	std::cout << "\n1)Sorted Que is: ";
	while (!temp1.empty()) {
		std::cout << temp1.front() << " ";
		temp1.pop();
	}
}

void SortUsingOneQueue()
{
	queue<int> q;
	queue<int> temp1;

	// data in q
	q.push(5);
	q.push(13);
	q.push(0);
	q.push(1);
	q.push(2);


	// add one check here
	if (q.size() <= 1) {		// queue with less or equal to 1 size is already in sorted order 
		return;
	}

	int frontOfQue = q.front();
	q.pop();
	temp1.push(frontOfQue);

	while (!q.empty()) {

		frontOfQue = q.front();
		q.pop();


		bool isFrontPushed = false;		// to check either frontofQue is pushed in temp2 or not
		
	
		// move all elements of temp1 in temp2 que which are less than 'a' [a --> front of 'q' que] 
		int temp1_size = temp1.size();
		int i = 0;		// loop variable/iterator
		for(; i < temp1_size; ++i) {
			int temp = temp1.front();

			if (temp < frontOfQue) {
				temp1.push(temp);
			}
			else {
				temp1.push(frontOfQue);
				isFrontPushed = true;
				break;
			}
			temp1.pop();
		}

		// insert remaining elements of temp1 que in temp2 que
		for (; i < temp1_size; ++i)
		{
			int temp = temp1.front();
			temp1.pop();
			temp1.push(temp);
		}


		// if front is not pushed in temp2 yet, push it
		if (!isFrontPushed) {
			temp1.push(frontOfQue);
		}
	}

	std::cout << "\n2)Sorted Que is: ";
	while (!temp1.empty()) {
		std::cout << temp1.front() << " ";
		temp1.pop();
	}
}
