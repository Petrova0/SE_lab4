#!/bin/bash
for file in `ls *Program`
do
	rm -f ${file}_output.txt
    rm -f $file
done