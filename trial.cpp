#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <omp.h>

using namespace cv;

/// Global Variables
const int NUMBER = 10;
const int DELAY = 100;


const int window_width = 9000;
const int window_height = 9000;
int x_1 = -window_width/2;
int x_2 = window_width;
int y_1 = -window_width/2;
int y_2 = window_width;

/// Function headers
static Scalar randomColor( RNG& rng );
int Drawing_Random_Filled_Polygons( Mat image, RNG rng );
int Drawing_Random_Circles( Mat image, RNG rng );

int main( void )
{
  int c;

 /// Also create a random object (RNG)
  RNG rng( 0xFFFFFFFF );

  /// Initialize a matrix filled with zeros
  Mat image = Mat::zeros( window_height, window_width, CV_8UC3);
   waitKey( DELAY );
  /// Draw filled polygons
  c = Drawing_Random_Filled_Polygons( image, rng );
  if( c != 0 ) return 0;

  /// Draw circles
  c = Drawing_Random_Circles( image, rng );
  if( c != 0 ) return 0;

  return 0;
}

/// Function definitions

/**
 * @function randomColor
 * @brief Produces a random color given a random object
 */
static Scalar randomColor( RNG& rng )
{
  int icolor = (unsigned) rng;
  return Scalar( icolor&255, (icolor>>8)&255, (icolor>>16)&255 );
}


/**
 * @function Drawing_Random_Filled_Polygons
 */
int Drawing_Random_Filled_Polygons( Mat image, RNG rng )
{
  int lineType = 8;

  for ( int i = 0; i < NUMBER; i++ )
  {
    Point pt[2][3];
    pt[0][0].x = rng.uniform(x_1, x_2);
    pt[0][0].y = rng.uniform(y_1, y_2);
    pt[0][1].x = rng.uniform(x_1, x_2);
    pt[0][1].y = rng.uniform(y_1, y_2);
    pt[0][2].x = rng.uniform(x_1, x_2);
    pt[0][2].y = rng.uniform(y_1, y_2);
    pt[1][0].x = rng.uniform(x_1, x_2);
    pt[1][0].y = rng.uniform(y_1, y_2);
    pt[1][1].x = rng.uniform(x_1, x_2);
    pt[1][1].y = rng.uniform(y_1, y_2);
    pt[1][2].x = rng.uniform(x_1, x_2);
    pt[1][2].y = rng.uniform(y_1, y_2);

    const Point* ppt[2] = {pt[0], pt[1]};
    int npt[] = {3, 3};

    fillPoly( image, ppt, npt, 2, randomColor(rng), lineType );
imwrite( "/ptmp/aditim/New_Image_filled_polygons.tiff", image);
  if( waitKey(DELAY) >= 0 )
      { return -1; }
  }
  return 0;
}

/**
 * @function Drawing_Random_Circles
 */
int Drawing_Random_Circles( Mat image, RNG rng )
{
  int lineType = 8;

  for (int i = 0; i < NUMBER; i++)
  {
    Point center;
    center.x = rng.uniform(x_1, x_2);
    center.y = rng.uniform(y_1, y_2);

    circle( image, center, rng.uniform(0, 300), randomColor(rng),
            rng.uniform(-1, 9), lineType );
imwrite( "/ptmp/aditim/New_Image_Circles.tiff", image);
 if( waitKey(DELAY) >= 0 )
      { return -1; }
  }

  return 0;
}

