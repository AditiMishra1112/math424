Files:

InterpolationFunctions.c  --> Parallel Implementation of functions for Nearest Neighbor Interpolation and Bilinear Interpolation using OpenMP
mainProg.c --> containing main program
runcomplete.sh --> script file for running entire dataset
runpartial.sh --> script file for running Dataset2
trial.cpp --> file for creating random images of given matrix size

Dataset path --> /ptmp/aditim/

Before running the file change the mode of the two script files
chmod 777 runcomplete.sh
chmod 777 runpartial.sh

Command for running the script --> ./runcomplete.sh 
for partial --> ./runpartial.sh

Parameters in shell script files:

./../../output $input_image $Interpolate_Ratio 16;
Interpolation_Ratio --> factor by how much you want to scale up/down the image
input_image --> defines input image
last parameter defines the number of threads

for Dataset:
folder must be in the format Dataset/image_folder/*.jpg
i.e. base database folder must have subfolders within which images are present

