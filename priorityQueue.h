#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <algorithm>
#include <stdexcept>
#include <iostream>

template <typename T>
class priorityQueue
{
	struct node
    {
        T element;
        unsigned int key;
        node* prev;
        node* next;
        node(const T& element, const int key, node* prev, node* next)
                : element(std::move(element)), key(key), prev(std::move(prev)), next(std::move(next)) {}
    };
    node* head;
    node* tail;
    unsigned int _size;

public:
	priorityQueue() : head(nullptr), tail(nullptr), _size(0) {};
	void insert(const T& element, unsigned int key);
	T min() const;
	T removeMin();
	[[nodiscard]] unsigned int size() const { return _size; };
	[[nodiscard]] bool isEmpty() const { return head == nullptr; };
	void print() const;
};


template <typename T>
void priorityQueue<T>::insert(const T& element, unsigned int key)
{
	node* inserted = new node(element, key, nullptr, nullptr);
	node* current = nullptr;
	if (isEmpty())
	{
		head = tail = inserted;
		_size++;
		return;
	}
	current = head;
	while (current != nullptr && key > current->key)
		current = current->prev;
	if (current == nullptr)
	{
		tail->prev = inserted;
		inserted->next = tail;
		inserted->prev = nullptr;
		tail = inserted;
	}
	else
    {
		inserted->next = current->next;
		inserted->prev = current;
		if (inserted->next != nullptr)
			inserted->next->prev = inserted;
		inserted->prev->next = inserted;
		if (head == tail || key <= head->key)
			head = inserted;
	}
	_size++;
}

template <typename T>
T priorityQueue<T>::min() const
{
	if (isEmpty())
		throw std::runtime_error("Nie mozna usunac elementu kolejki - kolejka jest pusta.");
	return head->element;
}

template <typename T>
T priorityQueue<T>::removeMin()
{
	if (isEmpty())
		throw std::runtime_error("Nie mozna usunac elementu kolejki - kolejka jest pusta.");
	const node* temp = head;
	T savedElement = head->element;
	head = head->prev;
	if (head != nullptr)
		head->next = nullptr;
	delete temp;
	_size--;
	return savedElement;
}

template <typename T>
void priorityQueue<T>::print() const
{
	if (isEmpty())
		throw std::runtime_error("Nie mozna wyswietlic elementow kolejki - kolejka jest pusta.");
	node *current = tail;
	while (current != nullptr)
	{
		std::cout << " -> "
			<< "[" << current->key << "] " << current->element;
		current = current->next;
	}
	std::cout << "\n";
}

#endif