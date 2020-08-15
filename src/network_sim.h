#ifndef NETWORK_SIM_H
#define NETWORK_SIM_H
#define BETA 0.08



#include "node.h"
#include "network.h"
#include <fstream>
#include "mtwist.h"
using namespace std;

enum Method
{
	NONE,
	METHOD1,
	TARGET,
	RANDOM,
	ACQUAINTANCE
};



class Simulation
{
public:
	int iter_times; //每次模拟的迭代次数 
	int sim_times;  //模拟次数 
	int init_node;
	Method method;
	//Simulation( Network& network,int iterTimes, int simTime,string input_file,Method method);
	Simulation( Network& network,int simTime,string input_file,int iter_times);
	~Simulation() {}
	string input_file;
	void set_initial_network(string input_file);
	bool create_agent(int id);
	void run_simulation(int init_node);
	void output_node_state(Network& network);
	void run_all_sim();
	//void run_simulation_method1(float prob_1,float prob_2);
private:
	//ofstream out_detail;  //记录三种节点在每次迭代中每一时刻的变化
	//ofstream avg_detail;  //记录三种节点在每一时刻变化的平均值
	//ofstream out_spread_degree; //记录每一时刻的传播指数
	Network& network;
	vector<int> infecteds;
	MTwist rng;
	//float sum_spread_degree;
	//vector<vector<float>> spread_degree;
	//vector<vector<vector<int>>> mStore;  // first itreation times,second simulation times,third neu pos and neg number
};




#endif