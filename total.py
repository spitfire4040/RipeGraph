import sys
import os

for x in range(1, 31):

	unique_ip = set()
	unique_trace = set()
	unique_edge = set()

	for x in range(1,(x+1)):
		infile1 = open("Day_" + str(x) + "_ip.txt", "r")
		infile2 = open("Day_" + str(x) + "_trace.txt", "r")
		infile3 = open("Day_" + str(x) + "_edge.txt", "r")

		for item in infile1:
			unique_ip.add(item)

		for item in infile2:
			unique_trace.add(item)

		for item in infile3:
			unique_edge.add(item)

		infile1.close()
		infile2.close()
		infile3.close()

	out = open("cumulative 1-" + str(x), "w")
	out.write("Total IPs: " + str(len(unique_ip)) + '\n')
	out.write("Total Traces: " + str(len(unique_trace)) + '\n')
	out.write("Total Edges: " + str(len(unique_edge)) + '\n')
	out.close()