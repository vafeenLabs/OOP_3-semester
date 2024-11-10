#pragma once
#include <iterator>
#include <sstream>
#include <iostream>
#include <conio.h>
#include <istream>
#include <ostream>

using namespace std;

template <class T>
struct Node
{
	T data;
	Node *next;

	Node<T>(T data) : data(data), next(nullptr) {}
};

template <class T>
class Iterator : public std::iterator<std::forward_iterator_tag, T, ptrdiff_t, T *, T &>
{
	Node<T> *itr;

public:
	Iterator() : itr(nullptr) {}
	Iterator(Node<T> *other) : itr(other) {}

	T &operator*() { return itr->data; }
	T &operator->() { return itr->data; }

	const T operator*() const { return itr->data; }
	const T operator->() const { return itr->data; }

	Node<T> *GetNode() { return itr; }

	Iterator &operator++()
	{
		itr = itr->next;
		return *this;
	}
	Iterator operator++(int)
	{
		Iterator tmp = *this;
		tmp = ++(*this);
		return tmp;
	}

	bool operator==(const Iterator &other) const { return itr == other.itr; }
	bool operator!=(const Iterator &other) const { return itr != other.itr; }

	// operator Iterator <const T>();
};

template <class T>
class TList
{
	Node<T> *head;

public:
	TList() : head(nullptr) {}

	typedef Iterator<T> iterator;
	typedef Iterator<const T> const_iterator;

	iterator begin() { return iterator(head); }
	iterator end() { return iterator(nullptr); }

	// const_iterator cbegin() const {return const_iterator(head);}
	// const_iterator cend() const {return const_iterator(nullptr);}

	T operator[](int pos)
	{
		iterator iterBegin = begin();

		for (int i = 0; i <= pos; ++i)
		{
			++iterBegin;
		}
		return *iterBegin;
	}

	void InsertArray(T *a, int n, int pos = -1)
	{
		int i = 0;
		if (!head)
		{
			head = new Node<T>(a[0]);
			++i;
		}
		else if (pos == -1)
		{
			AddToHead(a[0]);
			++i;
		}

		iterator cur = begin();

		for (int j = 0; j < pos; ++j)
		{
			++cur;
		}

		for (; i < n; ++i)
		{
			AddAfterIterator(cur, a[i]);
			++cur;
		}
	}

	void Insert(const iterator &iterBegin, const iterator &iterEnd, int pos = -1)
	{
		int n = 0;
		iterator temp = iterBegin;
		while (temp != iterEnd)
		{
			++n;
			++temp;
		}
		T *a = new T[n];
		temp = iterBegin;
		for (int i = 0; i < n; ++i, ++temp)
		{
			a[i] = *temp;
		}
		InsertArray(a, n, pos);
		delete[] a;
	}

	void Replace(iterator &iterBeginDelete, iterator &iterEndDelete,
				 const iterator &iterBeginInsert, const iterator &iterEndInsert)
	{
		iterator temp = begin();
		int pos = -1;
		while (temp != iterBeginDelete)
		{
			++temp;
			++pos;
		}
		Delete(iterBeginDelete, iterEndDelete);
		Insert(iterBeginInsert, iterEndInsert, pos);
	}

	void Delete(iterator &iterBegin, iterator &iterEnd)
	{

		if (iterBegin == begin())
		{
			head = iterEnd.GetNode();
		}
		else
		{
			Node<T> *temp = head;
			while (temp->next != iterBegin.GetNode())
			{
				temp = temp->next;
			}
			temp->next = iterEnd.GetNode();
		}
		while (iterBegin != iterEnd)
		{
			iterator temp = iterBegin;
			++iterBegin;
			delete temp.GetNode();
		}
	}

	void AddToHead(T elem)
	{
		Node<T> *p = new Node<T>(elem);
		p->next = head;
		head = p;
	}

	void AddAfterIterator(iterator &iterator, T elem)
	{
		Node<T> *current = iterator.GetNode();
		Node<T> *p = new Node<T>(elem);
		p->next = current->next;
		current->next = p;
	}

	Node<T> *lastElement()
	{
		Node<T> *p = head;
		while (p->next != nullptr)
			p = p->next;
		return p;
	}

	void Push_back(T elem)
	{
		if (head)
			lastElement()->next = new Node<T>(elem);
		else
			head = new Node<T>(elem);
	}

	iterator Search(T elem)
	{
		iterator iterBegin = begin();
		iterator iterEnd = end();
		while (iterBegin != iterEnd)
		{
			if (*iterBegin == elem)
				return iterBegin;
			++iterBegin;
		}
		return end();
	}
	bool BoolSearch(T elem)
	{
		iterator iterBegin = begin();
		iterator iterEnd = end();
		while (iterBegin != iterEnd)
		{
			if (*iterBegin == elem)
				return 1;
			++iterBegin;
		}
		return 0;
	}
	iterator Search(TList<T> &other)
	{
		iterator iterBegin1 = begin();
		iterator iterBegin2 = other.begin();
		iterator iterEnd = end();
		while (iterBegin1 != iterEnd)
		{
			if (*iterBegin1 == *iterBegin2)
			{
				iterator possibleRes = iterBegin1;
				iterator iterTemp1 = iterBegin1;
				iterator iterTemp2 = iterBegin2;
				++iterTemp2;
				++iterTemp1;
				while (iterTemp2 != iterEnd && *iterTemp2 == *iterTemp1)
				{
					++iterTemp2;
					++iterTemp1;
				}
				if (iterTemp2 == iterEnd)
					return possibleRes;

				return iterEnd;
			}

			++iterBegin1;
		}
		return iterEnd;
	}

	TList<T> Union(TList<T> other)
	{
		TList<T> result;
		Node<T> *p = head;
		while (p != nullptr)
		{
			result.Push_back(p->data);
			p = p->next;
		}
		p = other.head;
		while (p != nullptr)
		{
			if (result.BoolSearch(p->data) == 0)
				result.Push_back(p->data);
			p = p->next;
		}
		return result;
	}

	TList<T> Intersection(TList<T> other)
	{
		iterator iterBeginOther = other.begin();
		iterator iterEnd = end();
		TList<T> result;
		iterator iterBeginResult = result.begin();
		while (iterBeginOther != iterEnd)
		{
			if (this->Search(*iterBeginOther) != iterEnd && result.Search(*iterBeginOther) == iterEnd)
			{
				if (result.IsEmpty())
				{
					result.AddToHead(*iterBeginOther);
					iterBeginResult = result.begin();
				}
				else
				{
					result.AddAfterIterator(iterBeginResult, *iterBeginOther);
					++iterBeginResult;
				}
			}
			++iterBeginOther;
		}
		return result;
	}

	std::string ToString()
	{
		iterator iterBegin = begin();
		iterator iterEnd = end();

		std::string result;
		while (iterBegin != iterEnd)
		{
			result += *iterBegin + " ";
		}
		return result;
	}

	bool IsEmpty()
	{
		return (head == nullptr);
	}

	friend std::ostream &operator<<(std::ostream &os, TList<T> &obj)
	{

		Node<T> *p = obj.head;
		while (p != nullptr)
		{
			os << p->data << ' ';

			p = p->next;
		}

		return os;
	}

	friend void operator>>(std::istream &is, TList<T> &obj)
	{
		T input;
		std::string strInput;

		is.clear();
		is.ignore(is.rdbuf()->in_avail());

		getline(is, strInput);

		std::stringstream ss(strInput);
		while (ss >> input)
		{
			obj.Push_back(input);
			// cout << input << ' ';
		}
		// cout << "\n\n";
	}
};
