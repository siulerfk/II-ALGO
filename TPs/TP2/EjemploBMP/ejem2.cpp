/*
 * Convierte una imegen bmp a escalas grises.
 * Deben estrar en el mismo directorio para compilar.
 *   g++ ejem1.cpp EasyBMP.cpp -o var
 *   ./var sample_640×426.bmp pru.bmp 
 *           
 * Directorio distinto:
 *   g++ ejem1.cpp ../EasyBMP_1.06/EasyBMP.cpp -o var
 *   ./var sample_640×426.bmp pru.bmp
 */

// #include "../EasyBMP_1.06/EasyBMP.h"    // Mismo direstorio distinto
#include "../EasyBMP_1.06/EasyBMP.h"    // Directorio distinto
using namespace std;
int main( int argc, char* argv[] )
{
BMP SomeImage;
// Set the bit depth to 8 bpp
SomeImage.SetBitDepth(8);
// Get the 40th color
RGBApixel SomeColor = SomeImage.GetColor(40);
// Display the color
cout << (int) SomeColor.Red << ","
<< (int) SomeColor.Green << ","
<< (int) SomeColor.Blue << ","
<< (int) SomeColor.Alpha << endl;
// Change the 14th color to red
RGBApixel NewColor;
NewColor.Red = 255;
NewColor.Green = 0;
NewColor.Blue = 0;
NewColor.Alpha = 0;
SomeImage.SetColor(14,NewColor);
    Input.WriteToFile( "jenan.bmp" );
    return 0;
}
