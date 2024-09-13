#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Function implementations for part 1
int* createArray(int size) {
    return new int[size];
}

void initializeArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }
}

void printArray(const int* array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void deleteArray(int* array) {
    delete[] array;
    cout << "Array Successfully deleted!";
}


/// @brief The Point class
class Point {
private:
    int x,y,z; // Class attributes (x,y,z coordinates)

public:

    /// @brief Constructor with parameters for each axis (default is origin)
    /// @param x 
    /// @param y 
    /// @param z 
    Point(int x = 0, int y = 0, int z = 0) {
        this->x = x;
        this->y = y;
        this->z = z;      
    }

    /// @brief Destructor (empty because there is no dynamically allocated memory)
    ~Point() { cout << "\nPoint successfully destroyed"; }

    /// @brief Shifts the Point by distance d on the given axis
    /// @param d Distance by which the point is shifted
    /// @param axis Axis on which the point will be shifted
    /// @return 0 if point has been successfully shifted, -1 otherwise
    int translate (int d, char axis) {
        if(axis == 'x'){
            x += d;
        } else if(axis == 'y'){
            y += d;
        } else if(axis == 'z'){
            z += d;
        } else{
            return -1;
        }
        return 0;
    }

    // Getter methods
    int getx() const {
        return x;
    }

    int gety() const {
        return y;
    }

    int getz() const {
        return z;
    }

    // Displays the coordinates of the point
    void display() const {
        cout << "\n(" << x << ", " << y << ", " << z << ")";
    }
};

/// @brief Triangle made up of 3 Point objects
class Triangle {
private:
    Point *vertex_1, *vertex_2, *vertex_3; // 3 pointers to Point objects

public:

    /// @brief Default Constructor (vertices are null pointers)
    Triangle(){
        vertex_1 = nullptr;
        vertex_2 = nullptr;
        vertex_3 = nullptr;
    }

    /// @brief Constructor with parameters of type Point
    /// @param p1
    /// @param p2
    /// @param p3
    Triangle(Point p1, Point p2, Point p3){
        vertex_1 = new Point(p1);
        vertex_2 = new Point(p2);
        vertex_3 = new Point(p3);
    }

    /// @brief Destructor: deletes each vertex and prints a message
    ~Triangle(){
        delete vertex_1;
        delete vertex_2;
        delete vertex_3;
        cout << "\nTriangle successfully destroyed";
    }

    /// @brief Shifts the triangle by distance d on the given axis
    /// @param d distance by which the Triangle is shifted
    /// @param axis axis on which the triangle is shifted
    /// @return 0 if triangle has been successfully shifted, -1 otherwise
    int translate (int d, char axis){
        if(axis == 'x'){
            vertex_1->translate(d,'x');
            vertex_2->translate(d,'x');
            vertex_3->translate(d,'x');

        } else if(axis == 'y'){
            vertex_1->translate(d,'y');
            vertex_2->translate(d,'y');
            vertex_3->translate(d,'y');

        } else if(axis == 'z'){
            vertex_1->translate(d,'z');
            vertex_2->translate(d,'z');
            vertex_3->translate(d,'z');

        } else{
            return -1;
        }
        return 0;
    }

    /// @brief Calculates the area of the Triangle object using 3D vectors
    /// @return the area of the triangle
    double calcArea(){

        double x1 = vertex_1->getx(), y1 = vertex_1->gety(), z1 = vertex_1->getz(); // stores vertex 1 coordinates
        double x2 = vertex_2->getx(), y2 = vertex_2->gety(), z2 = vertex_2->getz(); // stores vertex 2 coordinates
        double x3 = vertex_3->getx(), y3 = vertex_3->gety(), z3 = vertex_3->getz(); // stores vertex 3 coordinates

        // getting 2 vectors from the triangle

        //Components of vector v
        double vx = x2 - x1;
        double vy = y2 - y1;
        double vz = z2 - z1;

        // Components of vector w
        double wx = x3 - x1;
        double wy = y3 - y1;
        double wz = z3 - z1;

        // Finding the cross product of vectors v and w
        double i = vy * wz - vz * wy;
        double j = -(vx * wz - vz * wx);
        double k = vx * wy - vy * wx;

        // Calculate the area of the triangle
        double area = 0.5 * sqrt(pow(i, 2) + pow(j, 2) + pow(k, 2));

        return area;
    }

    // Displays the coordinates of the 3 vertices
    void display() const {
        cout << "The coordinates of vertex 1, 2 and 3 respectively are: ";

        vertex_1->display();
        vertex_2->display();
        vertex_3->display();

    }

};

/// @brief Displays an option menu for the user
void menu() {
    cout << "\nWhat would you like to do? \n";
    cout << "1. Translate Triangle\n";
    cout << "2. Display Triangle\n";
    cout << "3. Calculate Area of triangle\n";
    cout << "4. Exit\n";
    cout << "\nEnter your choice: ";
}

/// @brief Clears the error state of the stream and ignore remaining input
void clearInputStream() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}


int main() {

    // PART 1

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* array = createArray(size);
    initializeArray(array, size);
    printArray(array, size);
    deleteArray(array);

    // PART 2

    int choice  ;

    cout << "\n\nWelcome to the triangle creation program!\n";

    int x1, y1, z1, x2, y2, z2, x3, y3, z3; // variables used to store the coordinates of triangle vertices

    cout << "\nPlease enter the coordinates for vertex 1 (seperated by a space): ";
    while (!(cin >> x1 >> y1 >> z1)) {
        cout << "Invalid input. Please enter three integers: ";
        clearInputStream();
    }
    cout << "Please enter the coordinates for vertex 2 (seperated by a space): ";
    while (!(cin >> x2 >> y2 >> z2)) {
        cout << "Invalid input. Please enter three integers: ";
        clearInputStream();
    }
    cout << "Please enter the coordinates for vertex 3 (seperated by a space): ";
    while (!(cin >> x3 >> y3 >> z3)) {
        cout << "Invalid input. Please enter three integers: ";
        clearInputStream();
    }

    // Create 3 point objects using the user input
    Point p1 = Point(x1, y1, z1);
    Point p2 = Point(x2, y2, z2);
    Point p3 = Point(x3, y3, z3);

    Triangle triangle = Triangle(p1, p2, p3); // create triangle objects using these points

    cout << "\nTriangle successfully created!\n";

    do{
        menu();
        cin >> choice;

        switch(choice) {
            // Translate triangle
            case 1: 
                int d;
                char axis;

                // get distance and axis from user
                cout << "Please enter the distance by which you would like to translate the triangle: ";

                // Handles incorrect user input
                while (!(cin >> d)) {
                    cout << "Invalid input, please enter an integer value: ";
                    clearInputStream();
                }
                cout << "Please enter the axis (x, y, or z): ";
                cin >> axis;
                triangle.translate(d, axis); // translate triangle
                break;

            // Display triangle
            case 2: 
                triangle.display();
                break;
            
            // Calculate area of triangle
            case 3: 
                cout << "The area of the triangle is " << triangle.calcArea() << " square units\n";
                break;

            // Exit program
            case 4:
                cout << "Exiting program...\nGoodbye!\n";
                break;

            // Invalid user input
            default:
                cout << "Invalid choice. Try again.\n";
                clearInputStream();

        }
    } while(choice != 4);
    return 0;
}