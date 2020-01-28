#pragma once

#include "ILinkedList.h"

namespace loop
{
	template<template<typename> typename NodeType, typename KeyType>
	NodeType<KeyType>* LoopExists(const ILinkedList<NodeType, KeyType>& l)
	{
		// Since the list is at least 2 items long, we know that both of these are valid to start.
		NodeType<KeyType>* slow_node = l.head();
		NodeType<KeyType>* fast_node = l.head();

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
} // namespace loop
