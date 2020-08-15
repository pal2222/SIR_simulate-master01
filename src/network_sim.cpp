#include "network_sim.h"
#include <time.h>
#include <algorithm>
#include "json/json.h"
#include <fstream>
#include "omp.h"
using namespace std;

bool Simulation::create_agent(int id)
{
	Node node;
	node.id = id;
	node.cur_state = S;
	network.nodes.insert(make_pair(id, node));
	return true;
}

void Simulation::output_node_state(Network& network)
{
	ofstream out("output.txt", ios::app);
	if (!out.is_open())
		cout << "Output file open error!" << endl;
	int S_num = 0;
	int I_num = 0;
	int R_num = 0;
	for (auto& iter = network.nodes.begin(); iter != network.nodes.end(); iter++)
	{
		auto& node = (*iter).second;
		if (node.cur_state == S)
			S_num++;
		if (node.cur_state == I)
			I_num++;
		if (node.cur_state == R)
			R_num++;

	}
	//out << S_num << " " << I_num <<  " " << R_num;
	//out << endl;
	cout << "S:" << S_num << "I:" << I_num << "R:" << R_num ;
	cout << endl;

}

Simulation::Simulation(Network& network, int simTime, string input_file,int iter_times)
	:network(network),
	sim_times(simTime),
	input_file(input_file),
	iter_times(iter_times)
{
	rng.init_genrand(0);
	ofstream log_file;
	log_file.open("running_log.txt");
	log_file.clear();
	ofstream out;
	out.open("output.csv");
	out.clear();
	out << "NodeId" << "," << "Degree" << "," << "Ks" << "," << "Bc" <<","<<"InfectedNumber"<< endl;
	set_initial_network(input_file);
}


void Simulation::run_all_sim()
{
	//#pragma omp parallel for
	for (auto& iter = network.nodes.begin(); iter != network.nodes.end(); iter++)
	{
		run_simulation((*iter).second.id);
	}
}

void Simulation::run_simulation(int init_node)
{
	for (auto& iter = network.nodes.begin(); iter != network.nodes.end(); iter++)
	{
		Node& e = (*iter).second;
		e.cur_state = S;
		e.next_state = S;
	}
	network.nodes.at(init_node).cur_state = I;
	network.nodes.at(init_node).next_state = I;
	ofstream log_file;
	log_file.open("running_log.txt",ios::app);
	cout << "init node:" << init_node << endl;
	log_file << "init node:" << init_node << endl;
	int infected_number = 0;
	for (int i = 0; i < iter_times; i++)
	{
		//cout << "iteration:" << i << endl;
		Network tmp_network = network;
		infecteds.clear();
		for (int j = 0; j < sim_times; j++)
		{
			srand(time(0));
			for (auto& iter = tmp_network.nodes.begin(); iter != tmp_network.nodes.end(); iter++)
			{
				Node& e = (*iter).second;
				e.cur_state = e.next_state;
				if (e.cur_state == I)
					infecteds.push_back(e.id);
				if (e.cur_state == S)
				{
					int count = 0;               //number of neighbor in I state 
					float prob_to_I = 1;		 //related to lamda
					for (auto& neighbor = e.following_set.followings.begin(); neighbor != e.following_set.followings.end(); neighbor++)
					{
						if (tmp_network.nodes.at((*neighbor).id).cur_state == I)
						{
							count++;
							prob_to_I = prob_to_I * (1 - BETA);
						}
					}
					if (count == 0)
						prob_to_I = 0;
					else
						prob_to_I = 1 - prob_to_I;
					//float rng = rand() / (RAND_MAX + 1.f);
					double r = rng.rand_real_not0();
					if (0 <= r && r < prob_to_I)
						e.next_state = I;
					else
						e.next_state = S;

				}
				if (e.cur_state == I)
					e.next_state = R;
			}
			//output_node_state(tmp_network);
		}
		vector<int>::iterator ite = unique(infecteds.begin(), infecteds.end());
		infecteds.erase(ite, infecteds.end());
		infected_number += infecteds.size();
		//cout << "The infected node number of iteration " << i + 1 << " is " << infecteds.size() << endl;;
		log_file << "The infected node number of iteration"<< i + 1 <<" is "<< infecteds.size() << endl;
	}
	cout << "The average infected node number is " << infected_number <<"/"<<iter_times;
	log_file<< "The average infected node number is " << infected_number << "/" << iter_times;
	infected_number = infected_number / iter_times;

	cout << " which is equal to " << infected_number << endl;
	log_file << " which is equal to " << infected_number << endl;
	ofstream out;
	out.open("output.csv",ios::app);
	int k = network.nodes.at(init_node).k;
	int ks = network.nodes.at(init_node).kslevel;
	float bc =  network.nodes.at(init_node).bc;
	out << init_node << "," <<k<<","<<ks<<","<<bc<<","<< infected_number << endl;
	
}

void Simulation::set_initial_network(string input_file)
{
	cout << "Initializing network please wait..." << endl;
	ifstream ifs;
	ofstream ofs;
	ifstream bc;
	ifstream ks;
	
	ifs.open(input_file , ios::in);
	ofs.open("degree.csv",ios::out);
	bc.open("bc.csv", ios::in);
	ks.open("ksresult.csv",ios::in);
	
	char buff[256];
	if (!ifs.is_open()) 
	{
		cout << "Error opening file"; exit(1);
	}
	if (!ks.is_open())
	{
		cout << "Error opening ks file"; exit(1);
	}
	if (!bc.is_open())
	{
		cout << "Error opening bc file"; exit(1);
	}
	while (!ifs.eof()) 
	{
		char a, b, c;
		int i, j, k;
		ifs >> i >> a >> j;
		if (!network.check_agent(i))
		{
			create_agent(i);
		}
		if (!network.check_agent(j))
		{
			create_agent(j);
		}
		network.nodes.find(i)->second.following_set.add(j);
		network.nodes.find(j)->second.following_set.add(i);
		//i = (int)a;
		//j = (int)b;
		//cout << i << " " << a << " " << j << endl;
		//p[i - 1][j - 1] = 0.5;
		//cout << i << " " << j << " " << p[i - 1][j - 1] << endl;;
	}
	for (auto& iter = network.nodes.begin(); iter != network.nodes.end(); iter++)
	{
		Node& e = (*iter).second;
		ofs << e.id << "," << e.following_set.followings.size() << endl;
		e.k = e.following_set.followings.size();
	}
	while (!ks.eof())
	{
		char a, b, c;
		int i, j, k;
		ks >> i >> a >> j;
		network.nodes.at(i).kslevel = j;
	}
	while (!bc.eof())
	{
		char a, b, c;
		int i;
		float j;
		bc >> i >> a >> j;
		network.nodes.at(i).bc = j;
	}
	cout << "Initialization done." << endl;
}

