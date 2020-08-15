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
	int iter_times; //ÿ��ģ��ĵ������� 
	int sim_times;  //ģ����� 
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
	//ofstream out_detail;  //��¼���ֽڵ���ÿ�ε�����ÿһʱ�̵ı仯
	//ofstream avg_detail;  //��¼���ֽڵ���ÿһʱ�̱仯��ƽ��ֵ
	//ofstream out_spread_degree; //��¼ÿһʱ�̵Ĵ���ָ��
	Network& network;
	vector<int> infecteds;
	MTwist rng;
	//float sum_spread_degree;
	//vector<vector<float>> spread_degree;
	//vector<vector<vector<int>>> mStore;  // first itreation times,second simulation times,third neu pos and neg number
};




#endif