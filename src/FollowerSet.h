#ifndef _FOLLOWERSET_H_
#define _FOLLOWERSET_H_

#include "node.h"
#include <cstdio>
#include <vector>
#include <functional>
#include <cmath>
using namespace std;

struct Node;
struct probability;

struct Follower
{
	int id;
	probability& prob;
};

struct FollowerSet
{
	vector<Follower> followers;

	bool add(Node& node, probability& prob);
	bool remove(int id);
	bool clear();
	size_t size() const
	{
		return followers.size();
	}
};


#endif