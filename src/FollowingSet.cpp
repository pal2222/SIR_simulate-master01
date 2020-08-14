
#include "FollowingSet.h"
#include <string>
#include <vector>
#include "node.h"

bool FollowingSet::add(int id)
{
		
		Following following;
		following.id = id;
		followings.push_back(following);
		return true;
}

//bool FollowingSet::remove(int id)
//{
//	for (auto& iter = followings.begin(); iter != followings.end();iter++)
//	{
//		if (*iter == id)
//		{
//			Followings.erase(iter);
//			return true;
//		}
//	}
//	return false;
//}

