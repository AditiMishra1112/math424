#include <stdio.h>
#include <stdlib.h>
#include "cv.h"
#include "highgui.h"
#include "InterpolationFunctions.h"
#include<string.h>
#include <unistd.h>
#include <libgen.h>
#include<omp.h>

int main(int argc, char *argv[])
{

//Define image containers for holding all images 
  IplImage *img,*img2, *img3;
  char *filename;
  float Ratio;
  int thread_count;
  char output_name_bilinear[]="OutputBilinear";
  char output_name_nearestneighbor[]="OutputNearestNeighbor";
  char op_path[] = "/ptmp/aditim/";  
  char *output_folder="OutputFiles"; 
  char* opfold = malloc(200*sizeof(char));
  char *imagefolder;
  char* imfold = malloc(200*sizeof(char));
  char cwd[PATH_MAX];
  char* path1 = malloc(200*sizeof(char));
  char* path2 = malloc(200*sizeof(char));

  if (getcwd(cwd, sizeof(cwd)) != NULL) {
       //printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }
  
  imagefolder = basename(cwd);
  strcpy(opfold,output_folder);
  strcpy(imfold,imagefolder);

//take image input file from user (read from runcode.sh file)
  filename = argv[1];
  
//take the ratio for image interpolation from user (read from runcode.sh file)
  Ratio = atof(argv[2]);
 
//Load input image    
  img=cvLoadImage(filename,CV_LOAD_IMAGE_COLOR);
  
  if(!img)
  {
    printf("Wrong file format %s\n",argv[1]);
    exit(0);
  }

  if(argc < 3)
  {
    printf("Invalid Parameters passed\n");
    printf("Usage : ./a.out <input_image_file> <Interpolate Ratio>");
    exit(0);
  }

 
strcpy(path1,op_path);
strcpy(path2,op_path);
strcat(path1, opfold);
strcat(path2, opfold);
strcat(path1, "/");
strcat(path2, "/");
strcat(path1,  imfold);
strcat(path2,  imfold);

strcat(output_name_bilinear,filename);
strcat(path1,output_name_bilinear);

printf("Image name for bilinear = %s\n", path1);

strcat(output_name_nearestneighbor,filename);
strcat(path2,output_name_nearestneighbor);

printf("Image name for Nearest Neighbor = %s\n", path2);

//Image Interpolation using Nearest Neighbor Interpolation
printf("Executing for Nearest Neighbor Interpolation\n");
img2 = NearestNeighborInterpolation(img, Ratio);

//Save the output image in NearestNeighborInterpolation.png
cvSaveImage(path2, img2,0);

printf("Executing for Bilinear Interpolation\n");
//Image Interpolation using Bilinear Interpolation
img3 = bilinearInterpolation(img, Ratio);

//Save the output image in bilinearInterpolation.png
cvSaveImage(path1,img3,0);

cvReleaseImage(&img);
cvReleaseImage(&img2);
cvReleaseImage(&img3);
free(opfold);
free(path1);
free(path2);
return 0;

}

