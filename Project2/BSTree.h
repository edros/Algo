#pragma once

#include <iostream>
#include <unordered_map>
#include <queue>



namespace ds
{

class BSTree
{

struct node
{
	node* left;
	node* right;
	int value;
} *root = nullptr;

void printVerticalCountHelper(node*, int, std::unordered_map<int, int>&) const;

public:
	void insert(int val);

	void printVerticalCount() const;

	node* getRoot() const noexcept;
	void printLevelCount () const;
};

// namespace ds
}