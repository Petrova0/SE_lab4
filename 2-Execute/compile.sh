#!/bin/bash
for file in `ls *.cpp`
do
	g++ $file -o ${file%.*}_Program
done

