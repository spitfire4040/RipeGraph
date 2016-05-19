#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

int main()
{
	ifstream fin1, fin2, fin3;
	ofstream fout1, fout2, fout3, fout4;
	string num1, num2, temp, infile1, infile2, infile3, outfile1, outfile2, outfile3, outfile4;
	int x, y, ipcount, tracecount, edgecount;

	set<string> ip;
	set<string>::iterator ip_itr;
	set<string> trace;
	set<string>::iterator trace_itr;
	set<string> edge;
	set<string>::iterator edge_itr;

	for (x = 1; x < 31; x++) // iterate through 30 days (num1)
	{
		ip.clear();
		trace.clear();
		edge.clear();
		ipcount = 0;
		tracecount = 0;
		edgecount = 0;

		num1 = to_string(x);

		outfile1 = "Day_" + num1 + "_ip.txt";
		outfile2 = "Day_" + num1 + "_trace.txt";
		outfile3 = "Day_" + num1 + "_edge.txt";
		outfile4 = "Day_" + num1 + "_stats.txt";

		fout1.clear();
		fout2.clear();
		fout3.clear();
		fout4.clear();

		fout1.open(outfile1);
		fout2.open(outfile2);
		fout3.open(outfile3);
		fout4.open(outfile4);

		for (y = 1; y < 13; y++) // iterate through each folder (num2)
		{
			num2 = to_string(y);

			infile1 = "RipeData" + num2 + '/' +  num1 + "/all_nodes/ips.txt";
			infile2 = "RipeData" + num2 + '/' +  num1 + "/all_nodes/traces.txt";
			infile3 = "RipeData" + num2 + '/' +  num1 + "/all_nodes/edges.txt";

			fin1.open(infile1);
			fin2.open(infile2);
			fin3.open(infile3);	

			// read ips into set
			while (fin1.good())
			{
				fin1 >> temp;
				ip.insert(temp);
			}

			// read traces into set
			while (fin2.good())
			{
				getline(fin2,temp);
				trace.insert(temp);
			}

			// read edges into set
			while (fin3.good())
			{
				getline(fin3,temp);
				edge.insert(temp);
			}

			fin1.close();
			fin2.close();
			fin3.close();

		for (ip_itr = ip.begin(); ip_itr != ip.end(); ip_itr++)
		{
			fout1 << *ip_itr << endl;
			ipcount++;
		}

		for (trace_itr = trace.begin(); trace_itr != trace.end(); trace_itr++)
		{
			fout2 << *trace_itr << endl;
			tracecount++;	
		}

		for (edge_itr = edge.begin(); edge_itr != edge.end(); edge_itr++)
		{
			fout3 << *edge_itr << endl;
			edgecount++;		
		}

		fout4 << " Statistics Day " << num1 << endl;
		fout4 << "Total IPs: " << ' ' << ipcount << endl;
		fout4 << "Total Traces: " << ' ' << tracecount << endl;
		fout4 << "Total Edges: " << ' ' << edgecount << endl;

		fout1.close();
		fout2.close();
		fout3.close();
		fout4.close();
		}
	}


	return 0;
}