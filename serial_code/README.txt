Files:

InterpolationFunctions.c  --> Serial Implementation of functions for Nearest Neighbor Interpolation and Bilinear Interpolation using OpenMP
mainProg.c --> containing main program
runcode.sh --> script file for running entire dataset
runpartial.sh --> script file for running Dataset2

Dataset path --> /ptmp/aditim/

Before running the file change the mode of the two script files
chmod 777 runcode.sh
chmod 777 runpartial.sh

Command for running the script --> ./runcode.sh 
for partial --> ./runpartial.sh

Parameters in shell script files:

./../../output_serial $input_image $Interpolate_Ratio;
Interpolation_Ratio --> factor by how much you want to scale up/down the image
input_image --> defines input image

for Dataset:
folder must be in the format Dataset/image_folder/*.jpg
i.e. base database folder must have subfolders within which images are present

command for getting time of running the entire dataset
time ./runcode.sh 
time ./runpartial.sh

