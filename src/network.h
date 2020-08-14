#ifndef _NETWORK_H_
#define _NETWORK_H_

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include "node.h"
using namespace std;

class Network
{

public:
	//std::map<int, Agent> agents;
	bool check_agent(int id);
	//Agent& operator[](int index)
	//{ 
	//	//** This allows us to index our Network struct as if it were an array.
	//	//DEBUG_CHECK(index > 0 && index <= agents.size(), "Network out-of-bounds agent access");
	//	return agents.find(index)->second;
	//}

	std::map<int,Node> nodes;
	std::vector<vector<probability>> probs;
};


#endif