// tLinkedList.h
#pragma once

template<typename T>
class tList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * prev;                // pointer to node following this node
		Node * next;                // pointer to node following this node
	};

	Node * head;                    // pointer to head of linked list
	Node * tail;                    // pointer to tail of linked list

public:
	tList();                 // initializes head to null
	~tList();                // delete all nodes upon destruction

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front
	void push_back(const T& val);  // adds element to front (i.e. head)
	void pop_back();               // removes element from front

	T& front();                     // returns the element at the head
	const T& front() const;         // returns the element at the head (const)
	T& back();                     // returns the element at the head
	const T& back() const;         // returns the element at the head (const)

	void remove(const T& val);      // removes all elements equal to the given value

	bool empty() const;             // Returns true if there are no elements
	void clear();                   // Destroys every single node in the linked list
	void resize(size_t newSize);    // Resizes the linked list to contain the given number of elements
									// New elements are default-initialized
	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator();                                 // initializes an empty iterator pointing to null
		iterator(Node * startNode);                 // initializes an iterator pointing to the given node

		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		T& operator*() const;                       // returns a reference to the element pointed to by the current node
		iterator& operator++();                     // pre-increment (returns a reference to this iterator after it is incremented)
		iterator operator++(int);                   // post-increment (returns an iterator to current node while incrementing the existing iterator)
	};

	iterator begin();
	iterator end();
};

template<typename T>
inline tList<T>::tList()
{
	head = nullptr;
}

template<typename T>
inline tList<T>::~tList()
{
	delete head;
}

template<typename T>
inline void tList<T>::push_front(const T & val)
{
	Node * N = new Node();
	N->data = val;
	N->prev = nullptr;
	N->next = head;
	if (head != nullptr)
	{
		head->prev = N;
		tail = head;
	}
	else
	{
		tail = N;
	}
	head = N;

}

template<typename T>
inline void tList<T>::pop_front()
{
	if (head != nullptr)
	{
		Node * N = head;
		head = head->next;
		delete N;
	}
}

template<typename T>
inline void tList<T>::push_back(const T & val)
{
	Node * N = new Node();
	N->data = val;
	N->next = nullptr;
	if (tail == nullptr)
	{
		N->prev = head;
		head->next = N;
	}
	else
	{
		N->prev = tail;
		N->next = nullptr;
	}
	tail = N;
}

template<typename T>
inline void tList<T>::pop_back()
{
	if (head != nullptr)
	{
		Node * N = head;
		head = head->next;
		delete N;
	}
}

template<typename T>
inline T & tList<T>::front()
{
	return head.data;
}

template<typename T>
inline const T & tList<T>::front() const
{
	return head.data;
}

template<typename T>
inline void tList<T>::remove(const T & val)
{
	while (head->data == val || head == nullptr)
	{
		pop_front();
	}
	Node * it = head;
	while (it->next != nullptr)
	{
		if (it->next->data == val)
		{
			Node * deletus = it->next;
			it->next = it->next->next;
			delete deletus;
		}
		else
		{
			it = it->next;
		}
	}
}

template<typename T>
inline bool tList<T>::empty() const
{
	if (head == nullptr) {	return true; }
	return false;
}

template<typename T>
inline void tList<T>::clear()
{
	head = nullptr;
}

template<typename T>
inline void tList<T>::resize(size_t newSize)
{
	int track = 0;
	Node * search = head;
	while (track < newSize)
	{
		while (search != nullptr)
		{
			if (track >= newSize) { break; }
			track++;
			search = search->next;
		}
		if (search == nullptr)
		{
			pop_front();
			search = head;
			track++;
		}
	}
	
}



template<typename T>
inline typename tList<T>::iterator tList<T>::begin()
{
	return iterator(head);
}

template<typename T>
inline typename tList<T>::iterator tList<T>::end()
{
	Node *temp = head;
	while (temp != nullptr)
	{
		temp = temp->next;
	}
	return iterator(temp);
}

template<typename T>
inline tList<T>::iterator::iterator()
{
	/*cur = new Node();
	cur->data = 0;*/
	cur = nullptr;
}

template<typename T>
inline tList<T>::iterator::iterator(Node * startNode)
{
	cur = startNode;
}

template<typename T>
inline bool tList<T>::iterator::operator==(const iterator & rhs) const
{
	return (cur == rhs.cur);
}

template<typename T>
inline bool tList<T>::iterator::operator!=(const iterator & rhs) const
{
	return !(*this == rhs);
}

template<typename T>
inline T & tList<T>::iterator::operator*() const
{
	return *(&cur->data);
}

template<typename T>
inline typename tList<T>::iterator & tList<T>::iterator::operator++()
{
	cur = cur->next;
	return *this;
}

template<typename T>
inline typename tList<T>::iterator tList<T>::iterator::operator++(int)
{
	iterator iter(*this);
	cur = cur->next;
	return iter;
}