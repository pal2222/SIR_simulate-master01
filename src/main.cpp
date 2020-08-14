#include "network.h"
#include <iostream>
#include "network_sim.h"
#include <fstream>
#include <string>
#include <sstream>

void output_network_state(Network& network)
{
	for (auto& iter = network.nodes.begin(); iter != network.nodes.end(); iter++)
	{
		Node& e = (*iter).second;
		cout << "Outputing network state..." << endl;
		cout << "Node ID:" << e.id << "Node state:";
		if (e.cur_state == S)
			cout << "S." << endl;
		else if (e.cur_state == I)
			cout << "I." << endl;
		else if (e.cur_state == R)
			cout << "R." << endl;
	}
}

int main(int argc, char* argv[])
{
	Network nt1,nt2;
	string input_file = argv[1];
	if (argv[2] == "all")
	{

	}
	else
	{
		int init_node = atoi(argv[2]);
		int iter_times = atoi(argv[3]);
		Simulation sim1(nt1,30, input_file,iter_times);
	}
	
	
	
	
	cout << "Initial infected node : " << init_node <<" iteration times : "<<iter_times<< endl;
	//output_network_state(nt1);
	sim1.run_all_sim();
	cout << "----------------------------------------" << endl;
	//output_network_state(nt1);


	//string method_name = argv[2]; 
	//Method method = METHOD1;
	//if (method_name == "none")
	//	method = NONE;
	//else if (method_name == "method1")
	//	method = METHOD1;
	//else if (method_name == "target")
	//	method = TARGET;
	//else if (method_name == "random")
	//	method = RANDOM;
	//else if (method_name == "acquaintance")
	//	method = ACQUAINTANCE;

	////initialization
	//Simulation sim1(nt1, 2, 200, input_file, NONE);
	//Simulation sim2(nt2, 2, 200, input_file, method);

	////run simulation
	//sim1.run_simulation_no_method();
	//if(sim2.method == METHOD1)
	//{ 
	//	sim2.run_simulation_method1(0.33,0.33);
	//}
	//ofstream out_file_detail, out_file_degree;
	//ifstream in_file_avg_a, in_file_avg_b;
	//out_file_detail.open("avg_detail_before_and_after.csv");
	//string lineStr1,lineStr2;

	//out_file_detail.clear();
	//in_file_avg_a.open("avg_detail_after.csv");
	//in_file_avg_b.open("avg_detail_before.csv");
	//while (getline(in_file_avg_a, lineStr1))
	//{
	//	vector<string> tmpArray1;
	//	vector<string> tmpArray2;
	//	string str1, str2;
	//	getline(in_file_avg_b, lineStr2);
	//	stringstream ss1(lineStr1);
	//	stringstream ss2(lineStr2);
	//	while (getline(ss1, str1, ','))
	//		tmpArray1.push_back(str1);
	//	while (getline(ss2,str2,','))
	//		tmpArray2.push_back(str2);
	//	out_file_detail << tmpArray1[0] << "," << tmpArray2[0] << endl;
	//}

	//out_file_degree.open("avg_degree_before_and_after.csv");
	//out_file_degree.clear();
	//ifstream in_file_degree_a, in_file_degree_b;
	//in_file_degree_a.open("spread_degree_after.csv");
	//in_file_degree_b.open("spread_degree_before.csv");
	//while (getline(in_file_degree_a, lineStr1))
	//{
	//	vector<string> tmpArray1;
	//	vector<string> tmpArray2;
	//	string str1, str2;
	//	getline(in_file_degree_b, lineStr2);
	//	stringstream ss1(lineStr1);
	//	stringstream ss2(lineStr2);
	//	while (getline(ss1, str1, ','))
	//		tmpArray1.push_back(str1);
	//	while (getline(ss2, str2, ','))
	//		tmpArray2.push_back(str2);
	//	out_file_degree << tmpArray1[0] << "," << tmpArray2[0] << endl;
	
}