#pragma once

template<template<typename> class NodeType, typename KeyType>
class ILinkedList
{
public:
	ILinkedList() = default;

	ILinkedList(const ILinkedList&) = delete;
	ILinkedList(ILinkedList&&) = delete;

	ILinkedList& operator=(const ILinkedList&) = delete;
	ILinkedList& operator=(ILinkedList&&) = delete;

	virtual ~ILinkedList();

	virtual NodeType<KeyType>* Search(const KeyType& key) const = 0;
	virtual void Insert(NodeType<KeyType>* x) = 0;
	virtual void Remove(NodeType<KeyType>* x) = 0;
	
	NodeType<KeyType>* head() const { return head_; }
	size_t Count() const;

protected:
	NodeType<KeyType>* head_ = nullptr;
};

template<template<typename> class NodeType, typename KeyType>
inline ILinkedList<NodeType, KeyType>::~ILinkedList()
{
	NodeType<KeyType>* to_delete = head_;
	while (to_delete)
	{
		NodeType<KeyType>* temp = to_delete->next;
		delete to_delete;
		to_delete = temp;
	}
}

template<template<typename> class NodeType, typename KeyType>
inline size_t ILinkedList<NodeType, KeyType>::Count() const
{
	size_t size = 0;
	NodeType<KeyType>* node = head_;

	while (node)
	{
		if (size > 0 && node == head_)
		{
			break; //We're in an infinite loop.
		}

		size++;
		node = node->next;
	}

	return size;
}
