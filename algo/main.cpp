#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <chrono>
#include <queue>

#include "BSTree.h"

int main() 
{
	ds::BSTree t;
	t.insert(7);
	t.insert(3);
	t.insert(11);
	t.insert(2);
	t.insert(4);
	t.insert(8);
	t.insert(12);
	t.insert(13);

	//t.printVerticalCount();
	t.printLevelCount();
	system("pause");
}