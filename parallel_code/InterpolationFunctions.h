IplImage *bilinearInterpolation(IplImage *img, float Ratio, int thread_count);
IplImage *NearestNeighborInterpolation(IplImage *img, float Ratio, int thread_count);
IplImage *createImage(int w, int h, int depth, int channels);

