#! /usr/bin/python


filename = "NRK1000_MAP_Lookup.h"

file = open(filename, "w+")

arraySize = 1024

# Write the leading stuff here
file.write("const uint32_t waterData[1024] =\n{ ")

cnt = 0

for index in range(0,arraySize):
	file.write("\t%d,\n" % ((50000/1024)*(index)))


file.write("};")

file.close()
