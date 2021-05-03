#pragma once

template <typename T>
struct Box {

	T data;
	Box* next;

	Box(const T& _data, Box* _next) {
		data = _data;
		next = _next;
	}
	Box(const Box<T>& other) {
		data = other.data;
		next = other.next;
	}

};
