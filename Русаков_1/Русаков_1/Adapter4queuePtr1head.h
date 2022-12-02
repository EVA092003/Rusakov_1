#pragma once
#include "QueuePtr1head.h"

class Adapter4queuePtr1head
{
	QueuePtr1head* qu;
	uint64_t* nop;

public:
	Adapter4queuePtr1head() {
		//cout << "\nОбычный конструктор\n";
		qu = new QueuePtr1head();
	}
	~Adapter4queuePtr1head()
	{
		delete qu;
	}
	//adapter4QueuePtr(const adapter4QueuePtr& obj)
	//{
	//	cout << "\nКонструктор копирования\n";
	//}
	void setNOP(uint64_t* _nop) {
		nop = _nop;
		qu->setNOP(nop);
	}
	uint64_t* getNOP() {
		return nop;
	}
	void display() { 
		qu->display();
	}
	void push(int num) {
		qu->push(num);
	}
	void pop() {
		qu->pop();
	}
	int size() {
		return qu->size();
	}
	int front() {
		return qu->front();
	}
	int getElement(int ind) {
		int size = qu->size();
		int element = -1;
		if ((ind >= 0) and (ind < size)) {
			QueuePtr1head* queTmp1 = new QueuePtr1head();
			queTmp1->setNOP(nop);
			for (int i = 0; i <= ind; i++) {
				queTmp1->push(front());
				element = front();
				pop();
			}
			for (int i = ind + 1; i < size; i++) {
				queTmp1->push(front());
				pop();
			}
			for (int i = 0; i < size; i++) {
				push(queTmp1->front());
				queTmp1->pop();
			}
			delete queTmp1;
		}
		return element;
	}
	void  setElement(int ind, int element) {
		int size = qu->size();
		if ((ind >= 0) and (ind < size)) {
			QueuePtr1head* queTmp1 = new QueuePtr1head();
			queTmp1->setNOP(nop);

			for (int i = 0; i < ind; i++) {
				queTmp1->push(front());
				pop();
			}
			queTmp1->push(element);
			pop();
			for (int i = ind + 1; i < size; i++) {
				queTmp1->push(front());
				pop();
			}
			for (int i = 0; i < size; i++) {
				push(queTmp1->front());
				queTmp1->pop();
			}
			delete queTmp1;
		}
	}
	Adapter4queuePtr1head* copy() {
		Adapter4queuePtr1head* queTmp1 = new Adapter4queuePtr1head();
		queTmp1->setNOP(nop);

		int size = qu->size();
		for (int i = 0; i < size; i++) {
			queTmp1->push(front());
			pop();
		}
		return queTmp1;
	}
	
};