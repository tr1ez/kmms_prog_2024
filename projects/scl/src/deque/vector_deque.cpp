#include <vector.hpp>

using namespace IBusko::Vector

template <typename T>

Vector::VectorDeque() noexcept {
	T* arr = new arr*[capacity];
}

VectorDeque::~VectorDeque() noexcept {
	delete [] T;
}

bool VectorDeque::empty() const noexcept {
	if (size == 0) return true;
	return false;
}

void VectorDeque::push_back(const T& value) noexcept {
	if (size >= capacity) extend_capacity();
	arr[size++] = value;
}

void VectorDeque::pop_back() const noexcept {
	if (not empty()) {
		if (size >= capacity) extend_capacity();
		arr[--size] = arr[size + 1];
		size--;
	}
}

void VectorDeque::push_front(const T& value) {
	if (size >= capacity) extend_capacity();
	for (int i = size; i > 0; i--) {
		arr[i] = arr[i-1];
	}
	arr[0] = value;
	size++;
}

void VectorDeque::pop_front(const T& value) noexcept {
	if (size == capacity) extend_capacity();
	if (not empty()) {
		for (int i = 0; i < size; i++) {
			arr[i] = arr[i + 1];
		}
	size--;
	}
}

bool VectorDeque::extend_capacity() noexcept {
	capacity *= 10;
	T* arr_ext = new T[capacity];
	delete [] arr;
	arr = arr_ext;
}

std::size_t VectorDeque::get_size() const noexcept {
	return size*sizeof(T);
}

T VectorDeque::back() noexcept {
	if (not empty()) return arr[size - 1];
	else return NULL;
}

T VectorDeque::front() noexcept {
	if (not empty()) return arr[0];
	else return NULL;
}
