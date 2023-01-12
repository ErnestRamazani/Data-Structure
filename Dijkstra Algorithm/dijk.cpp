#include<iostream>
#include<vector>
#include"dijk.h"
using namespace std;


//This function find the shortest path from the graph vector 
//This function takes two arguments
//This function call another function 
int self = -1;
void mainImpl(vector<vector<double>>mat, double inVer) {
	double numVer = mat[0].size();
	vector<double>sDis(numVer);

	vector<bool>added(numVer);
	//added =false 
	for (double i = 0; i < numVer; i++) {
		sDis[i] = INT_MAX;
		added[i] = false;
	}
	sDis[inVer] = 0;
	vector<double>parents(numVer);
	parents[inVer] = self;

	//finding shortest path  
	for (double i = 1; i < numVer; i++) {
		double nearVer = -1;
		double sDist = INT_MAX;
		//run the algo if the distance is higher 
		for (double j = 0; j < numVer; j++) {
			if (!added[j] && sDis[j] < sDist) {
				nearVer = j;
				sDist = sDis[j];
			}
		}
		added[nearVer] = true;
		//chnaging the valuye of vertices
		for (double k = 0; k < numVer; k++) {
			double dEdge = mat[nearVer][k];

			if (dEdge > 0 && ((sDist + dEdge) < sDis[k])) {
				parents[k] = nearVer;
				sDis[k] = sDist + dEdge;
			}
		}
	}
	resp(inVer, sDis, parents);
}

//This function prints the shortest path and the distance
//This function takes 3 arguments 
void resp(double inVer, vector<double>dis, vector<double>parents) {
	double numVer = dis.size();
	cout << "\tDistance\tPath";

	//Using a loop to print all the path and distance 
	for (double i = 0; i < numVer; i++) {
		if (i != inVer) {
			cout << "\n" << inVer << "--";
			cout << i << "\t\t";
			cout << dis[i] << "\t\t";
			path(i, parents);
		}
	}
}

//This functions prints all the paths 
//This functions takes 2 arguments 
void path(double ver, vector<double>parents) {
	if (ver == self) {
		return;
	}
	path(parents[ver], parents);
	cout << ver << " ";
}

