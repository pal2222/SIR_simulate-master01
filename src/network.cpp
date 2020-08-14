#include "network.h"
using namespace std;


bool Network::check_agent(int id)
{
	for (auto iter = nodes.begin(); iter != nodes.end(); iter++)
	{
		if (iter->first == id)
			return true;
	}
	return false;
}
