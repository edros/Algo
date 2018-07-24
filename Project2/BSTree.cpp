#include "BSTree.h"

namespace ds 
{

	//return the root of the tree
	BSTree::node* BSTree::getRoot() const noexcept
	{
		return root;
	}

	void BSTree::insert(int val)
	{
		if (root == nullptr)
		{
			root = new node;
			root->value = val;
			root->right = nullptr;
			root->left = nullptr;
			return;
		}
		node* temp = root;

		while (1)
		{
			if (temp->value < val)
			{
				if (temp->right == nullptr)
				{
					temp->right = new node;
					temp->right->value = val;
					temp->right->right = nullptr;
					temp->right->left = nullptr;
					break;
				}
				else
				{
					temp = temp->right;
				}
			}
			else
			{
				if (temp->left == nullptr)
				{
					temp->left = new node;
					temp->left->value = val;
					temp->left->right = nullptr;
					temp->left->left = nullptr;
					break;
				}
				else
				{
					temp = temp->left;
				}
			}
		}
	}

	void BSTree::printVerticalCount() const 
	{
		if (root == nullptr) { return; }
		std::unordered_map<int, int> M;
		printVerticalCountHelper(root, 0, M);

		for (auto iter = M.begin(); iter != M.end(); ++iter) 
		{
			std::cout << iter->first << " " << iter->second << std::endl;;
		}
	}

	void BSTree::printVerticalCountHelper(node* root, int level, std::unordered_map<int, int>& M) const
	{
		if (root == nullptr) { return; }
		M[level] += root->value;
		printVerticalCountHelper(root->left, level - 1, M);
		printVerticalCountHelper(root->right, level + 1, M);
	}

	//prints the number of iterms on each level
	void BSTree::printLevelCount() const
	{
		int currentMax = 1;
		int currentLayer = 1, nextLayer = 1;
		std::queue<node*> Q;
		Q.push(root);

		while (!Q.empty())
		{
			currentLayer = nextLayer;
			if (currentLayer > currentMax)
			{
				currentMax = currentLayer; 
			}
			nextLayer = 0;

			while (currentLayer--)
			{
				node* temp = Q.front();
				Q.pop();

				if (temp->left)
				{
					nextLayer++;
					Q.push(temp->left);
				}
				if (temp->right)
				{
					nextLayer++;
					Q.push(temp->right);
				}
			}
		}
		std::cout << currentMax << std::endl;
	}
}