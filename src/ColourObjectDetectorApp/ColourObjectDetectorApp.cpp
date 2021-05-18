/*
 * Developer  : MSc. Shiva Agrawal
 * Date       : 04.10.2018
 * version    : 1.0
 * Place      : Germany
 * description: test file to run ColourObjectDetector app
 */

#include"ColourObjectDetector.h"

int main()
{
	ColourObjectDetector myApp;
	string image = "colorObjects.jpg";

	myApp.detectColourObject(image);

	waitKey(0);

	return 0;
}

