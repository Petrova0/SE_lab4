#!/bin/bash
for file in `ls *Program`
do
	rm -f ${file}_output.txt
	while read line
	do
		./$file $line >> ${file}_output.txt 2>&1
		#echo -e >> ${file}_output.txt
	done < input.txt
done


