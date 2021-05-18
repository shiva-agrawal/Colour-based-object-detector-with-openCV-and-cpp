/*
 * Developer  : MSc. Shiva Agrawal
 * Date       : 04.10.2018
 * version    : 1.0
 * Place      : Germany
 * Description: It defines the functions to detect the object based on colors.
 *              It uses opencv3 functions to process the image
 */

#include "ColourObjectDetector.h"

ColourObjectDetector::ColourObjectDetector()
{
	// set initial values for thresholds(lower and upper) of each RGB color
	rLowValue = 20;
	rHighValue = 100;
	gLowValue = 20;
	gHighValue = 100;
	bLowValue = 20;
	bHighValue = 100;

}

void ColourObjectDetector::detectColourObject(string imageName)
{
	OrigImage = imread(imageName,IMREAD_COLOR);

	// window for original image and processed image
	namedWindow("Original Image");
	namedWindow("Colour Object detected Image");

	// window for slider palatte
	namedWindow("Colour Selector Sliders",WINDOW_NORMAL);


	// six trackbars for each threshold values of RGB low and high
	createTrackbar("R low", "Colour Selector Sliders", &rLowValue, 255,
			rLowValueCallback, this);
	createTrackbar("R High", "Colour Selector Sliders", &rHighValue, 255,
			rHighValueCallback,this);
	createTrackbar("G low", "Colour Selector Sliders", &gLowValue, 255,
			gLowValueCallback,this);
	createTrackbar("G High", "Colour Selector Sliders", &gHighValue, 255,
			gHighValueCallback,this);
	createTrackbar("B low", "Colour Selector Sliders", &bLowValue, 255,
			bLowValueCallback,this);
	createTrackbar("B high", "Colour Selector Sliders", &bHighValue, 255,
			bHighValueCallback,this);

	processImage();
	displayImage();

}

void ColourObjectDetector::rLowValueCallback(int, void* classPtr)
{
	ColourObjectDetector* myClass = (ColourObjectDetector*) classPtr;
	myClass->rLowValue = min(myClass->rHighValue - 1, myClass->rLowValue);
	setTrackbarPos("R low", "Colour Selector Sliders", myClass->rLowValue);
	myClass->processImage();
	myClass->displayImage();
}

void ColourObjectDetector::rHighValueCallback(int, void* classPtr)
{
	ColourObjectDetector* myClass = (ColourObjectDetector*) classPtr;
	myClass->rHighValue = max(myClass->rLowValue + 1, myClass->rHighValue);
	setTrackbarPos("R High", "Colour Selector Sliders", myClass->rHighValue);
	myClass->processImage();
	myClass->displayImage();
}

void ColourObjectDetector::gLowValueCallback(int, void* classPtr)
{
	ColourObjectDetector* myClass = (ColourObjectDetector*) classPtr;
	myClass->gLowValue = min(myClass->gHighValue - 1, myClass->gLowValue);
	setTrackbarPos("G low", "Colour Selector Sliders", myClass->gLowValue);
	myClass->processImage();
	myClass->displayImage();
}

void ColourObjectDetector::gHighValueCallback(int, void* classPtr)
{
	ColourObjectDetector* myClass = (ColourObjectDetector*) classPtr;
	myClass->gHighValue = max(myClass->gLowValue + 1, myClass->gHighValue);
	setTrackbarPos("G High", "Colour Selector Sliders", myClass->gHighValue);
	myClass->processImage();
	myClass->displayImage();
}

void ColourObjectDetector::bLowValueCallback(int, void* classPtr)
{
	ColourObjectDetector* myClass = (ColourObjectDetector*) classPtr;
	myClass->bLowValue = min(myClass->bHighValue - 1, myClass->bLowValue);
	setTrackbarPos("B low", "Colour Selector Sliders", myClass->bLowValue);
	myClass->processImage();
	myClass->displayImage();
}

void ColourObjectDetector::bHighValueCallback(int, void* classPtr)
{
	ColourObjectDetector* myClass = (ColourObjectDetector*) classPtr;
	myClass->bHighValue = max(myClass->bLowValue + 1, myClass->bHighValue);
	setTrackbarPos("B high", "Colour Selector Sliders", myClass->bHighValue);
	myClass->processImage();
	myClass->displayImage();
}

void ColourObjectDetector::processImage()
{
	inRange(OrigImage, Scalar(bLowValue, gLowValue, rLowValue),
					Scalar(bHighValue, gHighValue, rHighValue), objectDetectImage);

}

void ColourObjectDetector::displayImage()
{
	imshow("Original Image", OrigImage);
	imshow("Colour Object detected Image", objectDetectImage);
}

ColourObjectDetector::~ColourObjectDetector()
{
	destroyAllWindows();
}

