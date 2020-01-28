#pragma once

#include <set>

template<typename KeyType>
struct SingleNode
{
public:
	SingleNode(const KeyType& k) : key(k) {}

	SingleNode(const SingleNode&) = delete;
	SingleNode(SingleNode&&) = delete;

	SingleNode& operator=(const SingleNode&) = delete;
	SingleNode& operator=(SingleNode&&) = delete;

	~SingleNode() = default;

	KeyType key;
	SingleNode* next = nullptr;
};

template<typename KeyType>
struct DoubleNode
{
public:
	DoubleNode(const KeyType& k);

	DoubleNode(const DoubleNode&) = delete;
	DoubleNode(DoubleNode&&) = delete;

	DoubleNode& operator=(const DoubleNode&) = delete;
	DoubleNode& operator=(DoubleNode&&) = delete;

	~DoubleNode() = default;

	KeyType key;
	DoubleNode* next = nullptr;
	DoubleNode* prev = nullptr;
};

template<typename KeyType>
inline DoubleNode<KeyType>::DoubleNode(const KeyType& k) : key(k) {}

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
	std::set<NodeType<KeyType>*> nodes; // Cheat in case of loops.
	NodeType<KeyType>* node = head_;
	bool added_node = true;

	while (node && added_node)
	{
		auto p = nodes.insert(node);
		added_node = p.second;
		node = node->next;
	}

	for (auto node : nodes)
	{
		delete node;
	}
}

template<template<typename> class NodeType, typename KeyType>
inline size_t ILinkedList<NodeType, KeyType>::Count() const
{
	std::set<NodeType<KeyType>*> nodes; // Cheat in case of loops.
	NodeType<KeyType>* node = head_;
	bool added_node = true;

	while (node && added_node)
	{
		auto p = nodes.insert(node);
		added_node = p.second;
		node = node->next;
	}

	return nodes.size();
}
