#SIR_simulate 
SIR_simulate is an agent-based (social) simulator for rumor spreading models and rumor control strategies.

SIR_simulate is written in C++,to run it, you need three input files and three parameters:
1st input file is the network structure file you wanna run, ofen in csv format;
2nd input file is kslevel file, containing the kslevel information of all the nodes in the network;
3rd input file is betweenness centrality file, containing the bc information of all the nodes in the network；

Besides,
1st input parameter is the name of network structure file, ofen in csv format,
2nd input parameter is the initial infected node(id) or "all",which means run the process setting each node as init node,
3rd input parameter is the iteration times.

To run SIR_simulate,you need to compile the source file and run the nature2010SIR.exr file 
for example type "nature2010SIR.exe facebook.csv all 100".