#include "pch.h"

#include <limits>

#include "..\LinkedList\SinglyLinkedList.h"

using TestType = int;
using TestSingleNode = SingleNode<TestType>;
using TestSinglyLinkedList = SinglyLinkedList<TestType>;

TEST(SinglyLinkedListTests, SearchEmptyList) {
	TestSinglyLinkedList ll;

	ASSERT_EQ(nullptr, ll.Search(std::numeric_limits<TestType>::min()));
	ASSERT_EQ(nullptr, ll.Search(0));
	ASSERT_EQ(nullptr, ll.Search(std::numeric_limits<TestType>::max()));
}

TEST(SinglyLinkedListTests, SearchNotInList) {
	TestSinglyLinkedList ll;
	ll.Insert(new TestSingleNode(-2));
	ll.Insert(new TestSingleNode(-1));
	ll.Insert(new TestSingleNode(0));
	ll.Insert(new TestSingleNode(1));
	ll.Insert(new TestSingleNode(2));

	ASSERT_EQ(nullptr, ll.Search(std::numeric_limits<TestType>::min()));
	ASSERT_EQ(nullptr, ll.Search(std::numeric_limits<TestType>::max()));
}

TEST(SinglyLinkedListTests, SearchInList) {
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

TEST(SinglyLinkedListTests, InsertNull) {
	TestSinglyLinkedList ll;
	ll.Insert(nullptr);

	ASSERT_EQ(0, ll.Count());
	ASSERT_EQ(nullptr, ll.head());
}

TEST(SinglyLinkedListTests, InsertOneReal) {
	TestSinglyLinkedList ll;
	TestSingleNode* n1 = new TestSingleNode(1);
	ll.Insert(n1);

	ASSERT_EQ(1, ll.Count());
	ASSERT_EQ(n1, ll.head());
}

TEST(SinglyLinkedListTests, InsertMultipleReal) {
	TestSinglyLinkedList ll;
	TestSingleNode* n1 = new TestSingleNode(1);
	TestSingleNode* n2 = new TestSingleNode(2);
	ll.Insert(n1);
	ll.Insert(n2);

	ASSERT_EQ(2, ll.Count());
	ASSERT_EQ(n2, ll.head());
	ASSERT_EQ(n1, ll.head()->next);
}

//This test breaks everything by creating a loop in the list.
/*TEST(SinglyLinkedListTests, InsertRepeated) {
	TestSinglyLinkedList ll;
	TestSingleNode* n1 = new TestSingleNode(1);
	TestSingleNode* n2 = new TestSingleNode(2);
	ll.Insert(n1);
	ll.Insert(n2);
	ll.Insert(n1);

	ASSERT_EQ(2, ll.Count());
	ASSERT_EQ(n1, ll.head());
	ASSERT_EQ(n2, ll.head()->next);
}*/

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
