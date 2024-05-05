#include <doubly_linked_list.hpp>

using namespace IBusko::DoublyLinkedList

template <typename T>

DoublyLinkedList<T>::~DoublyLinkedList() noexcept {
	while (begin != nullptr) {
		Node* current = begin;
		begin = begin->next;
		delete current;
	}
}

void DoublyLinkedList<T>::push_back(const T& value) noexcept {
	Node* current = new Node(value);
	if (begin == nullptr) {
		begin = current; 
	} else if (end == nullptr){
		end = current;
		end.prev = *begin;
		begin.next = *end;
	} else {
		current.prev = *end;
		end.next = *current;
		end = end -> next;
	}
}

bool DoublyLinkedList<T>::has_item(const T& value) noexcept {
	Node* current = begin;
	while (current != nullptr) {
		if (current->value == value) {
			return true;
		}
		current = current -> next;
	}
	return false;
}

void DoublyLinkedList<T>::print() noexcept {
	Node* current = begin;
	while (current != nullptr){
		std::cout << current->value << std::endl;
	}
}

bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
	Node* current = begin;
	while (current != nullptr) {
		if (current->value == value) {
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}
		return true;
	}
	return false;
}

std::size_t DoublyLinkedList<T>::size() const noexcept {
	int length = 0;
	Node* current = begin;
	while (current != nullptr){
		length += 1;
		current = current->next;
	}
	return length * sizeof(T);
}
