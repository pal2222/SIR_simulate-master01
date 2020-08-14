#include <cmath>
#include "FollowerSet.h"
#include "node.h"

using namespace std;

//bool FollowerSet::add(Node& node, probability prob)
//{
//	Follower follower;
//	follower.id = node.id;
//	follower.prob = prob;
//	followers.push_back(follower);
//	return true;
//}

//bool FollowerSet::remove(int id)
//{
//	auto& iter = followers.begin();
//	for (auto& iter = followers.begin(); iter != followers.end();iter++)
//	{
//		if ((*iter).id == id)
//		{
//			followers.erase(iter);
//			break;
//		}
//	}
//	return true;
//}

bool FollowerSet::clear()
{
	followers.clear();
	return true;
}
