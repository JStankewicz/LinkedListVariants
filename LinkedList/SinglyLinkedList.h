#pragma once

#include "ILinkedList.h"

template<typename KeyType>
class SinglyLinkedList : public ILinkedList<SingleNode, KeyType>
{
public:	
	SinglyLinkedList() = default;

	SinglyLinkedList(const SinglyLinkedList&) = delete;
	SinglyLinkedList(SinglyLinkedList&&) = delete;

	SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;
	SinglyLinkedList& operator=(SinglyLinkedList&&) = delete;

	virtual ~SinglyLinkedList() = default;

	SingleNode<KeyType>* Search(const KeyType& key) const override;
	void Insert(SingleNode<KeyType>* x) override;
	void Remove(SingleNode<KeyType>* x) override;
};

template<typename KeyType>
SingleNode<KeyType>* SinglyLinkedList<KeyType>::Search(const KeyType& key) const
{
	SingleNode<KeyType>* x = head_;
	while (x && x->key != key)
	{
		x = x->next;
	}
	return x;
}

template<typename KeyType>
inline void SinglyLinkedList<KeyType>::Insert(SingleNode<KeyType>* x)
{
	if (!x)
	{
		return;
	}

	x->next = head_;
	head_ = x;
}

template<typename KeyType>
inline void SinglyLinkedList<KeyType>::Remove(SingleNode<KeyType>* x)
{
	if (!x) 
	{
		return;
	}

	SingleNode<KeyType>* prev = nullptr;
	SingleNode<KeyType>* current = head_;

	while (current)
	{
		if (current == x)
		{
			if (prev)
			{
				prev->next = current->next;
			}

			delete current;
			break;
		}

		prev = current;
		current = current->next;
	}
}

