#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;



void read_coordinates(int& x, int& y, int& width, int& height) {
	cout << "Write the rectangle area to invert: " << endl;
	cout << "x: "; cin >> x;
	cout << "y: "; cin >> y;
	cout << "width: "; cin >> width;
	cout << "height: "; cin >> height;
}

void invert_image_region(Mat& image, int x, int y, int width, int height) {
	for (int i = x; i < (x + height); i++) {
		for (int j = y; j < (y + width); j++) {
			// realizing the inversion as a complement operation
			image.at<uchar>(i, j) = 255 - image.at<uchar>(i, j);
		}
	}
}


int main(int argc, char** argv) {
	cv::Mat image;

	image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
	if (!image.data) {
		std::cout << "The image could not be opened." << std::endl;
		exit(-1);
	}
    
	int x, y, width, height;
	read_coordinates(x, y, width, height);
	invert_image_region(image, x, y, width, height);

	cv::imshow("inverted image", image);
	imwrite("inverted_biel.png", image);
	cv::waitKey();
	
    return 0;
}