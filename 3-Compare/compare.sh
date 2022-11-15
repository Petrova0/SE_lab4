#!/bin/bash
for file1 in `ls *output.txt`
do
    for file2 in `ls *output.txt`
    do
        if [ $file1 != $file2 ]; then
            diff $file1 $file2 &> /dev/null
            if [ $? != 0 ]; then
                echo ${file1%%_*}.cpp,file2%%_*}.cpp >> inequal.csv
            else
                echo ${file1%%_*}.cpp,${file2%%_*}.cpp >> equal.csv
            fi      
        fi      
    done      
done

