#include <vector.hpp>

using namespace IBusko::Vector

template <typename T>

Vector::Vector() noexcept {
	T* arr = new arr*[capacity];
}

Vector::~Vector() noexcept {
	delete [] T;
}

bool Vector::push_back(const T& value) noexcept {
	if (size >= capacity) {
		extend_capacity();
	}
	arr[size++] = value;
	return true;
}

bool Vector::has_item(const T& value) const noexcept {
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			return true;
		}
	}
	return false;
}

bool Vector::insert(const int position, const T& value) {
	if (size >= capacity) {
		extend_capacity();
	}
	for (int i = size; i > position; i--) {
		arr[i] = arr[i-1];
	}
	arr[position] = value;
	size++;
	return true;
}

void Vector::print() const noexcept {
	std::cout << "{";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i];
		if (i < size-1) std::cout << ", ";
	}
	std::cout << "}" << std::endl;
}

bool Vector::remove_first(const T& value) noexcept {
	bool delete_happened = false;
	if (size == capacity) extend_capacity();
	for (int i = 0; i < size; i++) {
		if (arr[i] == value and delete_happened == false) {
			delete_happened == true;
		}
		if (delete_happened) {
			arr[i] = arr[i+1];
		}
	}
	if (delete_happened) size--;
	return delete_happened;
}

std::size_t Vector::size() const noexcept {
	return size*sizeof(T);
}

bool Vector::extend_capacity() noexcept {
	capacity *= 10;
	T* arr_ext = new T[capacity];
	delete [] arr;
	arr = arr_ext;
}
