#pragma once

#include "ILinkedList.h"

namespace loop
{
	template<template<typename> typename NodeType, typename KeyType>
	NodeType<KeyType>* LoopExists(const ILinkedList<NodeType, KeyType>& ll)
	{
		// Since the list is at least 2 items long, we know that both of these are valid to start.
		NodeType<KeyType>* slow_node = ll.head();
		NodeType<KeyType>* fast_node = ll.head();

		while (slow_node && fast_node && fast_node->next)
		{
			// Increment these first because when we enter the loop they are the same.
			slow_node = slow_node->next;
			fast_node = fast_node->next->next;

			if (fast_node == slow_node) // Use pointer comparison to see if we're pointing to the same object.
			{
				return slow_node; // Either one, really...
			}
		}

		return nullptr;
	}

	// Assumptions:
	//	1. loop_node is not null
	//	2. loop_node is part of a loop
	//	3. loop_node is in ll
	//	4. ll contains a loop (implied by 3 and 4)
	// loop_node is a node in the loop but it's not necessarily the start of the loop.
	template<template<typename> class NodeType, typename KeyType>
	void FixLoop(NodeType<KeyType>* loop_node, ILinkedList<NodeType, KeyType>& ll)
	{
		NodeType<KeyType>* ptr1 = ll.head(); // ptr1 approaches the start of the loop from outside the loop.
		NodeType<KeyType>* ptr2 = loop_node; // ptr2 is a node in the loop - which MAY be the start of the loop but may not be.

		while (true)
		{
			// Increment ptr2 until it is the start of the loop or until it loops back on itself.
			while (ptr2->next != ptr1 && ptr2->next != loop_node) 
			{
				ptr2 = ptr2->next; 
			}

			// If ptr2 is now the start of the loop, we're done.
			if (ptr2->next == ptr1)
			{
				break;
			}

			// If we're still in this while loop, then ptr1 has not reached the start of the loop.
			ptr1 = ptr1->next;
		}

		// TODO: what about doubly linked lists?
		ptr2->next = nullptr;
	}

} // namespace loop
