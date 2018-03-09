#pragma once
#include "ILinkedList.h"

template<typename KeyType>
class DoublyLinkedList : public ILinkedList<DoubleNode, KeyType>
{
public:
	DoublyLinkedList() = default;
	virtual ~DoublyLinkedList() = default;
	
	DoubleNode<KeyType>* Search(const KeyType& key) const;
	void Insert(DoubleNode<KeyType>* x);
	void Remove(DoubleNode<KeyType>* x);
};

template<typename KeyType>
inline DoubleNode<KeyType>* DoublyLinkedList<KeyType>::Search(const KeyType & key) const
{
	DoubleNode<KeyType>* x = head_;
	while (x && x->key != key)
	{
		x = x->next;
	}
	return x;
}

template<typename KeyType>
inline void DoublyLinkedList<KeyType>::Insert(DoubleNode<KeyType>* x)
{
	x->next = head_;
	if (head_)
	{
		head_->prev = x;
	}
	head_ = x;
	x->prev = nullptr;
}

template<typename KeyType>
inline void DoublyLinkedList<KeyType>::Remove(DoubleNode<KeyType>* x)
{
	if (!x)
	{
		return;
	}

	if (x->prev)
	{
		x->prev->next = x->next;
	}
	else
	{
		head_ = x->next;
	}

	if (x->next)
	{
		x->next->prev = x->prev;
	}

	delete x;
}
