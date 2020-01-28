#pragma once

#include "ILinkedList.h"

namespace loop
{
	template<template<typename> typename NodeType, typename KeyType>
	bool LoopExists(const ILinkedList<NodeType, KeyType>& l)
	{
		// No loops in empty or one-node lists.
		if (l.Count() == 0 || l.Count() == 1)
		{
			return false;
		}

		// Since the list is at least 2 items long, we know that both of these are valid to start.
		NodeType<KeyType>* slow_node = l.head();
		NodeType<KeyType>* fast_node = slow_node->next;

		while (fast_node->next && fast_node->next->next)
		{
			if (fast_node == slow_node) // Use pointer comparison to see if we're pointing to the same object
			{
				return true;
			}

			fast_node = fast_node->next->next;
			slow_node = slow_node->next;
		}

		return false;
	}
} // namespace loop
