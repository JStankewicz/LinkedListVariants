#include "pch.h"

#include "..\LinkedList\SinglyLinkedList.h"

using TestType = int;
using TestSingleNode = SingleNode<TestType>;
using TestSinglyLinkedList = SinglyLinkedList<TestType>;

TEST(SinglyLinkedListTests, Insert) {
	TestSinglyLinkedList ll;
	ll.Insert(new TestSingleNode(1));
	ll.Insert(new TestSingleNode(2));
	ll.Insert(new TestSingleNode(3));

	ASSERT_EQ(3, ll.Count());
	ASSERT_EQ(3, ll.head()->key);
	ASSERT_EQ(2, ll.head()->next->key);
	ASSERT_EQ(1, ll.head()->next->next->key);
}

TEST(SinglyLinkedListTests, Search) {
	TestSinglyLinkedList ll;
	TestSingleNode* n1 = new TestSingleNode(1);
	TestSingleNode* n2 = new TestSingleNode(2);
	TestSingleNode* n3 = new TestSingleNode(3);
	ll.Insert(n1);
	ll.Insert(n2);
	ll.Insert(n3);
	
	ASSERT_EQ(n1, ll.Search(1));
	ASSERT_EQ(n2, ll.Search(2));
	ASSERT_EQ(n3, ll.Search(3));
}

TEST(SinglyLinkedListTests, Delete) {
	TestSinglyLinkedList ll;
	ll.Insert(new TestSingleNode(1));
	ll.Insert(new TestSingleNode(2));
	ll.Insert(new TestSingleNode(3));

	ll.Remove(ll.Search(2));

	ASSERT_EQ(2, ll.Count());
	ASSERT_EQ(nullptr, ll.Search(2));
	ASSERT_EQ(3, ll.head()->key);
	ASSERT_EQ(1, ll.head()->next->key);

	ll.Remove(ll.Search(3));
	ll.Remove(ll.Search(1));

	ASSERT_EQ(nullptr, ll.head());
}
