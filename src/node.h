#ifndef _NODE_H_
#define _NODE_H_
#include <string>
#include <vector>
#include <memory>
#include "FollowerSet.h"
#include "FollowingSet.h"

using namespace std;



enum NodeState
{
	S,
	I,
	R
};

struct jsonNode
{
	int json_id;
	string name;
	int Immunology;
};

struct Node
{
	int id = -1;
	NodeState cur_state = S;
	NodeState next_state = S;
	FollowingSet following_set; 
	int kslevel = -1;
	float bc = -1;
	int k = 0;
	//FollowerSet follower_set;
	//float R;     //probability turn to rumor-believing
	//float T;     //probability turn to truth-believing
	float v;       //sus transfer to con
	float r;       //non-rec transfer to rec
	float Neg;     //probability not believe any negative information
	float Pos;     //probability not believe any positive information
};

#endif