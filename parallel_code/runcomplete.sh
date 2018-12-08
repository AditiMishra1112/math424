#!/bin/bash

mkdir empty_dir
rsync -a --delete empty_dir/ /ptmp/aditim/OutputFiles/

rm -rf empty_dir;
mkdir /ptmp/aditim/OutputFiles;

gcc mainProg.c -o /ptmp/aditim/output `pkg-config --cflags --libs opencv` InterpolationFunctions.c -lm -fopenmp;

for dir in /ptmp/aditim/Datasets/*
do 
echo $dir
cd $dir
for file in *;
do
input_image=$file
Interpolate_Ratio=10
./../../output $input_image $Interpolate_Ratio 16;
done	
cd ..
done

for dir in /ptmp/aditim/Dataset2/*
do 
echo $dir
cd $dir
for file in *;
do
input_image=$file
echo $file
Interpolate_Ratio=2
./../../output $input_image $Interpolate_Ratio 16;
done	
cd ..
done
