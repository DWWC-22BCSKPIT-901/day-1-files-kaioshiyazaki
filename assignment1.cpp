/*  
Q1. Sum of Natural Numbers up to N. (V Easy) 
Q2. Count Digits in a Number. (Easy)
Q3. Function Overloading for Calculating Area. (Medium)
*/

#include <iostream>  
#include <math.h>

using namespace std; 
#define M_PI 3.14159265358979323846

int sumNaturalNum();      
int sumNaturalNum(int n); 

int countDigits();
int countDigits(int num); 

float calcCircleArea();           
float calcCircleArea(float rad);

float calcRectangleArea();
float calcRectangleArea(float length, float width);

float calcTriangleArea();                    
float calcTriangleArea(float base, float height);  

int main(int argc, char const *argv[])
{
    cout << "Sum of natural numbers: " << sumNaturalNum() << endl;
    cout << "Number of digits: " << countDigits() << endl;
    cout << "Circle area: " << calcCircleArea() << endl;
    cout << "Rectangle area: " << calcRectangleArea() << endl;
    cout << "Triangle area: " << calcTriangleArea() << endl;

    return 0;
}

int sumNaturalNum(int n){
    int sum = n * (n + 1) / 2;
    return sum; 
}

int sumNaturalNum(){
    int n;
    cout << "Enter a natural number: ";
    cin >> n;
    return sumNaturalNum(n);
}

int countDigits(int num){
    int digitCount = 0;
    while (num != 0)
    {   
        num = num / 10; 
        digitCount++;   
    }
    return digitCount; 
}

int countDigits(){
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    return countDigits(num);
}

float calcCircleArea(float rad){
    float area = M_PI * pow(rad, 2);
    return area;
}

float calcCircleArea(){
    float rad;
    cout << "Enter radius of the circle: ";
    cin >> rad;
    return calcCircleArea(rad);
}

float calcRectangleArea(float length, float width){
    return length * width;
}

float calcRectangleArea(){
    float length, width;
    cout << "Enter length and width of the rectangle: ";
    cin >> length >> width;
    return calcRectangleArea(length, width);
}

float calcTriangleArea(float base, float height){
    return 0.5f * base * height;
}

float calcTriangleArea(){
    float base, height;
    cout << "Enter base and height of the triangle: ";
    cin >> base >> height;
    return calcTriangleArea(base, height);
}
