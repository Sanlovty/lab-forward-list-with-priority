#include "ForwardList.h"

ForwardList::ForwardList() : head_(nullptr)
{
}

ForwardList::ForwardList(const ForwardList& other)
{
	if (other.isEmpty())
	{
		head_ = nullptr;
		return;
	}
	head_ = new Node(other.front());
	Node* myIt = head_;
	Node* otherIt = other.head_;
	while (otherIt->getNext() != nullptr)
	{
		otherIt = otherIt->getNext();
		Node* newNode = new Node(otherIt->getData());
		myIt->setNext(newNode);
		myIt = myIt->getNext();
	}
}

ForwardList::~ForwardList()
{
	while (!isEmpty())
	{
		popFront();
	}
}

void ForwardList::pushBack(const int& data)
{
	Node* newNode = new Node(data);
	if (isEmpty())
	{
		head_ = newNode;
		return;
	}
	Node* it = head_;
	while (it->getNext() != nullptr)
	{
		it = it->getNext();
	}

	it->setNext(newNode);
}

void ForwardList::pushFront(const int& data)
{
	Node* newNode = new Node(data, head_);
	if (isEmpty())
	{
		head_ = newNode;
		return;
	}
	head_ = newNode;
}

void ForwardList::popFront()
{
	if (isEmpty())
	{
		throw exception("Try to popFront element from empty list");
	}
	const Node* willBeDeleted = head_;
	head_ = head_->getNext();
	delete willBeDeleted;
}

void ForwardList::popBack()
{
	if (isEmpty())
	{
		throw exception("Try to popBack element from empty list");
	}
	Node* it = head_;
	if (it->getNext() == nullptr)
	{
		delete head_;
		head_ = nullptr;
		return;
	}
	while (it->getNext()->getNext() != nullptr)
	{
		it = it->getNext();
	}
	const Node* willBeDeleted = it->getNext();
	it->setNext(nullptr);
	delete willBeDeleted;
}

void ForwardList::pushByPriorityAsc(const int& data)
{
	if (isEmpty() || head_->getData() > data)
	{
		pushFront(data);
		return;
	}
	if (head_->getNext() == nullptr)
	{
		if (head_->getData() > data)
		{
			pushFront(data);
		}
		else
		{
			pushBack(data);
		}
		return;
	}
	Node* it = head_;
	while (it->getNext() != nullptr && it->getNext()->getData() < data)
	{
		it = it->getNext();
	}
	Node* newNode = new Node(data, it->getNext());
	it->setNext(newNode);
}

void ForwardList::pushByPriorityDesc(const int& data)
{
	if (isEmpty() || head_->getData() < data)
	{
		pushFront(data);
		return;
	}
	if (head_->getNext() == nullptr)
	{
		if (head_->getData() < data)
		{
			pushFront(data);
		}
		else
		{
			pushBack(data);
		}
		return;
	}
	Node* it = head_;
	while (it->getNext() != nullptr && it->getNext()->getData() > data)
	{
		it = it->getNext();
	}
	Node* newNode = new Node(data, it->getNext());
	it->setNext(newNode);
}

bool ForwardList::isEmpty() const
{
	return head_ == nullptr;
}

int ForwardList::front() const
{
	if (isEmpty())
	{
		throw exception("Try to take front element from empty list");
	}
	return head_->getData();
}
