#include "pch.h"

#include "../LinkedList/DoublyLinkedList.h"
#include "../LinkedList/SinglyLinkedList.h"

TEST(SingleNodeTest, Construction)
{
	const int ARBITRARY_INT = 1;
	SingleNode<int> node(ARBITRARY_INT);

	ASSERT_EQ(ARBITRARY_INT, node.key);
	ASSERT_EQ(nullptr, node.next);
}

TEST(DoubleNodeTest, Construction)
{
	const int ARBITRARY_INT = 1;
	DoubleNode<int> node(ARBITRARY_INT);

	ASSERT_EQ(ARBITRARY_INT, node.key);
	ASSERT_EQ(nullptr, node.next);
	ASSERT_EQ(nullptr, node.prev);
}
