/*
 * Developer  : MSc. Shiva Agrawal
 * Date       : 04.10.2018
 * version    : 1.0
 * Place      : Germany
 * Description: It defines the functions to detect the object based on colors.
 *              It uses opencv3 functions to process the image
 */

#ifndef COLOUROBJECTDETECTOR_H_
#define COLOUROBJECTDETECTOR_H_

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<string>

using namespace cv;
using namespace std;

class ColourObjectDetector {

private:

	Mat OrigImage;
	Mat objectDetectImage;

	int rLowValue, rHighValue;
	int gLowValue, gHighValue;
	int bLowValue, bHighValue;

	/*
	 * Static callback function for setting slider position and retriving
	 * the low threshold value of Red colour
	 */
	static void rLowValueCallback(int, void *);

	/*
	 * Static callback function for setting slider position and retriving
	 * the high threshold value of Red colour
	 */
	static void rHighValueCallback(int, void *);

	/*
	 * Static callback function for setting slider position and retriving
	 * the low threshold value of Green colour
	 */
	static void gLowValueCallback(int, void *);

	/*
	 * Static callback function for setting slider position and retriving
	 * the high threshold value of Green colour
	 */
	static void gHighValueCallback(int, void *);

	/*
	 * Static callback function for setting slider position and retriving
	 * the low threshold value of Blue colour
	 */
	static void bLowValueCallback(int, void *);

	/*
	 * Static callback function for setting slider position and retriving
	 * the high threshold value of blue colour
	 */
	static void bHighValueCallback(int, void *);

	/*
	 * Process the image to filter the pixels depending on selected RGB values
	 * in order to highlight the detected object as white.
	 */
	void processImage();

	/*
	 * display the original image and processed image which shows detected object
	 */
	void displayImage();


public:
	/*
	 * Constructor of the class to initializa the thresholds of the RGB values
	 */
	ColourObjectDetector();

	/*
	 * Function to detec the object based on colour values selected by slider
	 * @param: string imageName: name of the image file with extension
	 */
	void detectColourObject(string imageName);

	/*
	 * Destructor call the function to destroy all the opencv windows on exit
	 */
	virtual ~ColourObjectDetector();
};

#endif /* COLOUROBJECTDETECTOR_H_ */
