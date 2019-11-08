#!/bin/bash

g++ -Wall -Werror -std=c++17 -g *.cpp -o lab4

for i in {43..53}
do
	printf "===============CHECK FOR $i TEST FILE================\n"

	#printf "==========INPUT FILE FOR $i FILE===========\n\n"
	#cat ./inputFiles/in$i.txt
	#printf "\n"

	#printf "=====OUTPUT FILE=====\n\n"
	#cat ./outputFiles/out$i.txt
	#cat ./answers/out$i.txt
	./lab4 ./inputFiles/in$i.txt > ./outputFiles/out$i.txt
	diff ./outputFiles/out$i.txt ./answers/out$i.txt

	printf "\n\n"
done	
