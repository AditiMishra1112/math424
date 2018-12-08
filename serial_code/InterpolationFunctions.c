#include <cv.h>
#include <highgui.h>
#include "InterpolationFunctions.h"
#include<stdio.h>


//create an image container for the given image dimensions

IplImage * createImage(int w, int h, int depth, int channels)
{
   IplImage * img = NULL;
   img = cvCreateImage(cvSize(w,h), depth, channels);
   return img;
	}

//Function for Nearest Neighbor Interpolation takes input image and the ratio by which you want to interpolate the input image
//This approach takes into account only the next pixel value

	IplImage * NearestNeighborInterpolation(IplImage *img, float Ratio)
{
 	int newWidth, newHeight;
	int imagewidth = img->width;
	int imageheight = img->height;
	newWidth = (int)(imagewidth *Ratio);
	newHeight = (int)(imageheight * Ratio);
	int depth = img->depth;
        int channels = img->nChannels;
	IplImage *outputImg;
	outputImg = createImage(newWidth,newHeight,depth,channels);
	uchar * InputImagedata = img->imageData;
	uchar * OutputImageData = outputImg->imageData;
	int i,j,k;
	int r,c;
	float rf,cf;
	uchar temp;
	rf = (float)(img->width-1) /newWidth ;
	cf =  (float)(img->height-1) / newHeight;
    	for(i=0;i<newHeight;i++)
	   for(j=0;j<newWidth;j++)
	      {
	        r = ceil(rf*j);
	        c = ceil(cf*i);
	//As the image is an RGB image thus the calculation is to be done 3 times
            	   for(k=0;k<3;k++)
	             {
	 //consider only next pixel value for interpolating data
	            	temp = InputImagedata[c*img->widthStep + r*img->nChannels +k];
	            	OutputImageData[i*outputImg->widthStep + j*outputImg->nChannels +k]=temp;
	             }
	       }
	  return outputImg;
}

//Function for Bilinear Interpolation takes input image and the ratio by which you want to interpolate the input image
//This function takes into account value of surrounding 4 pixels

	IplImage * bilinearInterpolation(IplImage *img, float Ratio)
	{
		int newWidth, newHeight;
		int imagewidth = img->width;
		int imageheight = img->height;
		newWidth = (int)(imagewidth *Ratio);
		newHeight = (int)(imageheight * Ratio);
		int depth = img->depth;
        	int channels = img->nChannels;
		IplImage *outputImg;
		outputImg = createImage(newWidth,newHeight,depth,channels);
   	 	uchar * InputImagedata = img->imageData;
		uchar * OutputImageData = outputImg->imageData;

//values for four neighboring pixels
		int a1, a2, a3, a4;
		int r, c, index;
	  float rf = (float)(img->width-1)/newWidth;
	  float cf = (float)(img->height-1)/newHeight;
	  float delta_r, delta_c;
	  int i,j,k;

    for(i=0; i<newHeight; i++)
      for(j=0; j<newWidth; j++)
	      {
	        r = (int)(rf * j);
	        c = (int)(cf * i);
          delta_r = ((rf * j) - r);
          delta_c = ((cf * i) - c);
       index = c*img->widthStep + r*img->nChannels;

	              a1 = (int)index;
	              a2 = (int)(index + img->nChannels);
	              a3 = (int)(index + img->widthStep);
	              a4 = (int)(index + img->widthStep + img->nChannels);
// Get kth channel and interpolate the pixel values for that channel
	              for(k=0; k<3; k++)
	              OutputImageData[i*outputImg->widthStep + j*outputImg->nChannels +k] =
	              InputImagedata[a1+k]*(1-delta_r)*(1-delta_c)
	              +InputImagedata[a2+k]*(1-delta_c)*(delta_r)
	              +InputImagedata[a3+k]*(delta_c)*(1-delta_r)
	              +InputImagedata[a4+k]*(delta_c)*(delta_r);
	   }
 return outputImg;
}


