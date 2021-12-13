# DCA0445 Digital Image Processing
Repository destined to contain the solutions to some problems involving Digital Image Processing.

## Considerations
All code examples are compiled with the command

    $ make /path/to/executable

NOTE: the ```path/to/executable``` is the same path of its ```.cpp``` file.

# First unit exercises

## Exercise 1
This exercise is about the most use case of the ```OpenCV``` library: read an image and display it. For this, the following code was used:

```cpp
    #include <iostream>
    #include <opencv2/opencv.hpp>

    int main(int argc, char** argv){
    cv::Mat image;
    image = cv::imread(argv[1],cv::IMREAD_GRAYSCALE);

    cv::imshow("image", image);
    cv::waitKey();

    return 0;
    }
```

Where the image was read from ```argv[1]```, saved ind a ```cv::Mat``` object and then displayed as a grayscale image. The result was:

<p align="center">
  <img src="imgs/biel.png" />
</p>