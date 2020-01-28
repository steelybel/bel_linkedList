// tLinkedList.h
#pragma once

template<typename T>
class tForwardList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * next;                // pointer to node following this node
	};

	Node * head;                    // pointer to head of linked list

public:
	tForwardList();                 // initializes head to null
	~tForwardList();                // delete all nodes upon destruction

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front

	T& front();                     // returns the element at the head
	const T& front() const;         // returns the element at the head (const)

	void remove(const T& val);      // removes all elements equal to the given value
};

template<typename T>
inline tForwardList<T>::tForwardList()
{
	head = nullptr;
}

template<typename T>
inline tForwardList<T>::~tForwardList()
{
	delete head;
}

template<typename T>
inline void tForwardList<T>::push_front(const T & val)
{
	Node N = new Node;
	N.data = val;
	N.next = head;
	head = N;
}

template<typename T>
inline void tForwardList<T>::pop_front()
{
	if (head != nullptr)
	{
		Node N = head;
		head = head->next;
		delete N;
	}
}

template<typename T>
inline T & tForwardList<T>::front()
{
	return head.data;
}

template<typename T>
inline const T & tForwardList<T>::front() const
{
	return head.data;
}

template<typename T>
inline void tForwardList<T>::remove(const T & val)
{
	Node * it = head;
	while ((it.next != nullptr) && (it.next.data != val))
	{
		it = it.next;
	}
	if (it.next.data == val)
	{
		it = it.next;
		delete it;
	}
}
