#ifndef FOLLOWING_SET_H_
#define FOLLOWING_SET_H_
#include <vector>

using namespace std;

struct Node;

struct probability
{
	float prob_truth;
	float prob_rumor;
};
struct Following
{
	int id;
	//probability prob;
};

struct FollowingSet
{
	vector<Following> followings;
	bool add(int id);
	bool remove(int id);
};


#endif