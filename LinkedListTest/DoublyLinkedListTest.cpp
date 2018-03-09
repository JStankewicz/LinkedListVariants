#include "pch.h"

#include "..\LinkedList\DoublyLinkedList.h"

using TestType = int;
using TestDoubleNode = DoubleNode<TestType>;
using TestDoublyLinkedList = DoublyLinkedList<TestType>;

TEST(DoublyLinkedListTests, Insert) {
	TestDoublyLinkedList ll;
	ll.Insert(new TestDoubleNode(1));
	ll.Insert(new TestDoubleNode(2));
	ll.Insert(new TestDoubleNode(3));

	ASSERT_EQ(3, ll.Count());
	ASSERT_EQ(3, ll.head()->key);
	ASSERT_EQ(2, ll.head()->next->key);
	ASSERT_EQ(1, ll.head()->next->next->key);
}

TEST(DoublyLinkedListTests, Search) {
	TestDoublyLinkedList ll;
	TestDoubleNode* n1 = new TestDoubleNode(1);
	TestDoubleNode* n2 = new TestDoubleNode(2);
	TestDoubleNode* n3 = new TestDoubleNode(3);
	ll.Insert(n1);
	ll.Insert(n2);
	ll.Insert(n3);

	ASSERT_EQ(n1, ll.Search(1));
	ASSERT_EQ(n2, ll.Search(2));
	ASSERT_EQ(n3, ll.Search(3));
}

TEST(DoublyLinkedListTests, Delete) {
	TestDoublyLinkedList ll;
	ll.Insert(new TestDoubleNode(1));
	ll.Insert(new TestDoubleNode(2));
	ll.Insert(new TestDoubleNode(3));

	ll.Remove(ll.Search(2));

	ASSERT_EQ(2, ll.Count());
	ASSERT_EQ(nullptr, ll.Search(2));
	ASSERT_EQ(3, ll.head()->key);
	ASSERT_EQ(1, ll.head()->next->key);

	ll.Remove(ll.Search(3));
	ll.Remove(ll.Search(1));

	ASSERT_EQ(nullptr, ll.head());
}
