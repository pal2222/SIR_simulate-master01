cmake_minimum_required(VERSION 3.6.1)
project(nature2010SIR)
add_executable(nature2010SIR
               node.h 
               main.cpp
			   FollowerSet.h
			   FollowerSet.cpp
			   FollowingSet.h
			   FollowingSet.cpp
               network.h
			   network.cpp
			   network_sim.cpp
			   network_sim.h)