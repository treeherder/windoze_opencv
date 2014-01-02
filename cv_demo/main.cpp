#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;
using namespace std;

void cam()
{
    int c;
    IplImage* color_img;
    CvCapture* cv_cap = cvCaptureFromCAM(0);
	IplImage *  current_frame = cvQueryFrame (cv_cap);
	CvSize size640x480 = cvSize(current_frame->width, current_frame->height);
    cvNamedWindow("Video",0); // create window
    for(;;) {
        color_img = cvQueryFrame(cv_cap); // get frame
        if(color_img != 0)
            cvShowImage("Video", color_img); // show frame
        c = cvWaitKey(10); // wait 10 ms or for key stroke
    if(c == 27)
        break; // if ESC, break and quit
    }
    /* clean up */
    cvReleaseCapture( &cv_cap );
    cvDestroyWindow("Video");
}

int main( int argc, char** argv )
{
    if( argc != 2)
    {
      cam();
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow( "Display window", CV_WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}