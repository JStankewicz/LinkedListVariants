#include "pch.h"

#include "gtest/gtest.h"

#include "../LinkedList/LoopDetection.h"
#include "../LinkedList/SinglyLinkedList.h"

using TestType = int;
using TestNode = SingleNode<TestType>;
using TestLinkedList = SinglyLinkedList<TestType>;

TEST(SinglyLoopTest, EmptyList)
{
	TestLinkedList ll;

	ASSERT_FALSE(loop::LoopExists(ll));
}

TEST(SinglyLoopTest, OneNodeList)
{
	TestLinkedList ll;
	TestNode* n1 = new TestNode(1);
	ll.Insert(n1);

	ASSERT_FALSE(loop::LoopExists(ll));
}

TEST(SinglyLoopTest, NotALoop)
{
	TestLinkedList ll;
	TestNode* n1 = new TestNode(1);
	TestNode* n2 = new TestNode(2);
	TestNode* n3 = new TestNode(3);
	TestNode* n4 = new TestNode(4);

	ASSERT_EQ(0, ll.Count());
	ASSERT_FALSE(loop::LoopExists(ll));

	ll.Insert(n1);
	ASSERT_EQ(1, ll.Count());
	ASSERT_FALSE(loop::LoopExists(ll));

	ll.Insert(n2);
	ASSERT_EQ(2, ll.Count());
	ASSERT_FALSE(loop::LoopExists(ll));

	ll.Insert(n3);
	ASSERT_EQ(3, ll.Count());
	ASSERT_FALSE(loop::LoopExists(ll));

	ll.Insert(n4);
	ASSERT_EQ(4, ll.Count());
	ASSERT_FALSE(loop::LoopExists(ll));
}

TEST(SinglyLoopTest, TwoItemsLoop)
{
	TestLinkedList ll;
	TestNode* n1 = new TestNode(1);
	TestNode* n2 = new TestNode(2);
	ll.Insert(n1);
	ll.Insert(n2);
	ll.Insert(n1);

	ASSERT_EQ(2, ll.Count());
	ASSERT_EQ(n1, ll.head());
	ASSERT_EQ(n2, ll.head()->next);
	ASSERT_EQ(n1, ll.head()->next->next);

	ASSERT_TRUE(loop::LoopExists(ll));
}

TEST(SinglyLoopTest, ThreeItemsLoop)
{
	TestLinkedList ll;
	TestNode* n1 = new TestNode(1);
	TestNode* n2 = new TestNode(2);
	TestNode* n3 = new TestNode(3);
	ll.Insert(n1); // n1 is head, head->next is null
	ll.Insert(n2); // n2 is head, head->next is n1
	ll.Insert(n3); // n3 is head, head->next is n2
	ll.Insert(n1); // n1 is head, head->next is n3

	ASSERT_EQ(3, ll.Count());
	ASSERT_EQ(n1, ll.head());
	ASSERT_EQ(n3, ll.head()->next);
	ASSERT_EQ(n2, ll.head()->next->next);
	ASSERT_EQ(n1, ll.head()->next->next->next);

	ASSERT_TRUE(loop::LoopExists(ll));
}

TEST(SinglyLoopTest, ThreeItemsLoopNotHead)
{
	TestLinkedList ll;
	TestNode* n1 = new TestNode(1);
	TestNode* n2 = new TestNode(2);
	TestNode* n3 = new TestNode(3);
	ll.Insert(n1); // n1 is head, head->next is null
	ll.Insert(n2); // n2 is head, head->next is n1
	ll.Insert(n1); // n1 is head, head->next is n2
	ll.Insert(n3); // n3 is head, head->next is n1

	ASSERT_EQ(3, ll.Count());
	ASSERT_EQ(n3, ll.head());
	ASSERT_EQ(n1, ll.head()->next);
	ASSERT_EQ(n2, ll.head()->next->next);
	ASSERT_EQ(n1, ll.head()->next->next->next);

	ASSERT_TRUE(loop::LoopExists(ll));
}

TEST(SinglyLoopTest, FourItemsLoop)
{
	TestLinkedList ll;
	TestNode* n1 = new TestNode(1);
	TestNode* n2 = new TestNode(2);
	TestNode* n3 = new TestNode(3);
	TestNode* n4 = new TestNode(4);
	ll.Insert(n1); // n1 is head, head->next is null
	ll.Insert(n2); // n2 is head, head->next is n1
	ll.Insert(n3); // n3 is head, head->next is n2
	ll.Insert(n4); // n4 is head, head->next is n3
	ll.Insert(n1); // n1 is head, head->next is n4

	ASSERT_EQ(4, ll.Count());
	ASSERT_EQ(n1, ll.head());
	ASSERT_EQ(n4, ll.head()->next);
	ASSERT_EQ(n3, ll.head()->next->next);
	ASSERT_EQ(n2, ll.head()->next->next->next);
	ASSERT_EQ(n1, ll.head()->next->next->next->next);

	ASSERT_TRUE(loop::LoopExists(ll));
}

TEST(SinglyLoopTest, FourItemsLoopNotHead)
{
	TestLinkedList ll;
	TestNode* n1 = new TestNode(1);
	TestNode* n2 = new TestNode(2);
	TestNode* n3 = new TestNode(3);
	TestNode* n4 = new TestNode(4);
	ll.Insert(n1); // n1 is head, head->next is null
	ll.Insert(n2); // n2 is head, head->next is n1
	ll.Insert(n3); // n3 is head, head->next is n1
	ll.Insert(n1); // n1 is head, head->next is n3
	ll.Insert(n4); // n4 is head, head->next is n1

	ASSERT_EQ(4, ll.Count());
	ASSERT_EQ(n4, ll.head());
	ASSERT_EQ(n1, ll.head()->next);
	ASSERT_EQ(n3, ll.head()->next->next);
	ASSERT_EQ(n2, ll.head()->next->next->next);
	ASSERT_EQ(n1, ll.head()->next->next->next->next);

	ASSERT_TRUE(loop::LoopExists(ll));
}
