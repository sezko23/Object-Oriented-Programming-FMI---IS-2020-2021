#pragma once
#include "Box.h"
#include <iostream>

template<typename T>
class LList {
private:
	Box<T>* first;
public:
	bool empty() {
		return first == nullptr;
	}
	LList() {
		first = nullptr;
	}
	~LList() {
		while (!empty()) {
			Box<T>* toDelete = first;
			first = toDelete->next;
			delete[] toDelete;
		}
	}
	void pushBack(const T& add) {
		if (first == nullptr) {
			first = new Box<T>(add, nullptr);
			return;
		}

		Box<T>* current = first;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Box<T>(add, nullptr);
	}

	void reverse() {
		Box<T>* current = first;
		Box<T>* prev = nullptr;
		Box<T>* next = nullptr;
		while (current != nullptr) {
			// Store next
			next = current->next;

			// Reverse current node's pointer
			current->next = prev;

			// Move pointers one position ahead.
			prev = current;
			current = next;
		}
		first = prev;
	}

	void printLog() {
		std::cout << "My Activity Log:" << std::endl;
		Box<T>* current = first;
		while (current != nullptr) {
			std::cout << current->data << " -> ";
			current = current->next;
		}
		std::cout << "End of our list" << std::endl;

	}
	void remove();
};