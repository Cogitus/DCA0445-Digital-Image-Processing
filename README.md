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

## Exercise 2.1
*Utilizando o programa [```exemplos/pixels.cpp```](https://agostinhobritojr.github.io/tutorial/pdi/exemplos/pixels.cpp) como referência, implemente um programa regions.cpp. Esse programa deverá solicitar ao usuário as coordenadas de dois pontos $P_1$ e $P_2$ localizados dentro dos limites do tamanho da imagem e exibir que lhe for fornecida. Entretanto, a região definida pelo retângulo de vértices opostos definidos pelos pontos $P_1$ e $P_2$ será exibida com o negativo da imagem na região correspondente. O efeito é ilustrado na Figura 4*.

The solution of this problem was relatively easy, since it was only a matter of two aditional steps:

1) Read the coordinates of the area that will be  modified to negative:
  ```cpp
    void read_coordinates(int& x, int& y, int& width, int& height) {
      cout << "Write the rectangle area to invert: " << endl;
      cout << "x: "; cin >> x;
      cout << "y: "; cin >> y;
      cout << "width: "; cin >> width;
      cout << "height: "; cin >> height;
    }
  ```

2) And then modify the image ate the area by taking the complement of the pixels' values in the area specified before

  ```cpp
      void invert_image_region(Mat& image, int x, int y, int width, int height) {
        for (int i = x; i < (x + height); i++) {
          for (int j = y; j < (y + width); j++) {
            // realizing the inversion as a complement operation
            image.at<uchar>(i, j) = 255 - image.at<uchar>(i, j);
          }
        }
      }
  ```

Resulting on the following result for the coordinates $(80, 70)$ and $(170, 160)$, *i.e.*, 

* $x = 80$; 
* $y = 70$;
* $with = 80$;
* $height = 90$;
  
<p align="center">
  <img src="imgs/inverted_biel.png" />
</p>

## Exercise 2.2
*Utilizando o programa [```exemplos/pixels.cpp```](https://agostinhobritojr.github.io/tutorial/pdi/exemplos/pixels.cpp) como referência, implemente um programa ```trocaregioes.cpp```. Seu programa deverá trocar os quadrantes em diagonal na imagem. Explore o uso da classe ```Mat``` e seus construtores para criar as regiões que serão trocadas. O efeito é ilustrado na Figura 5.*