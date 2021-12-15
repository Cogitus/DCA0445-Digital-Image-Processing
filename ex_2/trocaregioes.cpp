#include <iostream>
#include <vector>
#include <utility>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;



int main(int argc, char** argv) {
	cv::Mat image;

	image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
	if (!image.data) {
		std::cout << "The image could not be opened." << std::endl;
		exit(-1);
	}

	// as the image will be sorted by its half, then we get the half coordinates
	// which values will be used to get the subregions areas (in this case, rectangles)
	int rect_height = image.cols/2;
	int rect_width = image.rows/2;

	// segmenting the Rect() areas of the original image
	cv::Rect rect_left_up(0, 0, rect_width, rect_height);
	cv::Rect rect_right_up(rect_width, 0, rect_width, rect_height);
	cv::Rect rect_left_down(0, rect_height, rect_width, rect_height);
	cv::Rect rect_right_down(rect_width, rect_height, rect_width, rect_height);

	// making the Rect() areas Mat() images
	cv::Mat image_left_up = image(rect_left_up);
	cv::Mat image_right_up = image(rect_right_up);
	cv::Mat image_left_down = image(rect_left_down);
	cv::Mat image_right_down = image(rect_right_down);
	
	// mapping the sorting of the images in a vector
	vector<pair<cv::Rect, cv::Mat>> mapping; 
	mapping.push_back({rect_left_up, image_right_down});
	mapping.push_back({rect_right_up, image_left_down});
	mapping.push_back({rect_left_down, image_right_up}); 
	mapping.push_back({rect_right_down, image_left_up});
	

	// making a copy of the image to not change the original one
	cv::Mat sorted_image = image.clone();

	for(pair<cv::Rect, cv::Mat>& sort_map : mapping) {
		// inserting the sorted image part in the sorted_image
		// for this, we do something like cv::Mat.copyTo(sorted_image(cv::Rect));
		(sort_map.second).copyTo(sorted_image(sort_map.first));
	}

	cv::imshow("sorted biel", sorted_image);
	imwrite("sorted_biel.png", sorted_image);
	cv::waitKey();

	return 0;
}