#include <iostream>
#include <limits>       // For std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#include <iomanip>      // For std::setprecision();

//      Difficult homework 2        //


// TESTS:
/*
Ans: ~ 28
5 5 2 -5 2 -5 -2 5 -2 5 2

Ans: ~ 7.434
5 0 0 1 1 2 0 3 0 0 2

Ans: ~10.214
5  0 0  0 3  3 3  0 0  100 40

*/


const double pi = 3.14;

const double xmax = 5.0;    //
const double ymax = 2.0;    //  Size of the football field.
const double xmin = -5.0;   //
const double ymin = -2.0;   //

const double round_input = 5.0;             // Number of decimal places to which the imput is rounded.
const double round_when_in_field_check = 2.0;     // Number of decimal pleces of precision when checking if a point lies on the border of the field.


struct point {
    double x, y;

    point(const double setX, const double setY) {
        x = setX;
        y = setY;
        return;
    }

    point() {
        // input 'x'
        do {
            std::cout << "x = ";
            if (std::cin >> x)
                break;
            else {
                std::cout << "Invalid number! Try again!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);

        // input 'y'
        do {
            std::cout << "y = ";
            if (std::cin >> y)
                break;
            else {
                std::cout << "Invalid number! Try again!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);

        RoundInput();

        return;
    }

    // Rounds 'x' and 'y' to round_input decimal places.
    void RoundInput() {

        // This does not need to be computed every time.
        // I'm leaving it this way because now there are only 2 constants ('round_when_in_field_check' and 'round_input')
        // which set the rouding precision. This way we do not have to worry about the actual rounding procedure
        // and just easyly change the 2 constants if we want different precision.
        double m = pow(10.0, round_input);  

        // If 'x' is positive round with +0.5, else round with -0.5.
        if (x > 0)
            x = (int)((x * m) + 0.5) / m;
        else
            x = (int)((x * m) - 0.5) / m;

        // Same for 'y'.
        if (y > 0)
            y = (int)((y * m) + 0.5) / m;
        else
            y = (int)((y * m) - 0.5) / m;
    }

};

//-------------------------------------------------- Input --------------------------------------------------

// User input for number of points.
// There must be 2 or more points (n >= 2).
int Inp_n() {
    int n = 0;

    std::cout << "How many points?\n";
    do {
        std::cout << "n = ";
        if (std::cin >> n && n > 1)
            break;
        else {
            std::cout << "n must be bigger than 1! Try again!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (true);
   
    return n;
}

//-------------------------------------------------- Input --------------------------------------------------

//-------------------------------------------------- Logic --------------------------------------------------

// Rounds 'num' to 'decimal_precision' of decimal places and returns the result as 'int'.
int RoundANumber(double num, double decimal_precision) {

    // This does not need to be computed every time.
    // I'm leaving it this way because now there are only 2 constants ('round_when_in_field_check' and 'round_input')
    // which set the rouding precision. This way we do not have to worry about the actual rounding procedure
    // and just easyly change the 2 constants if we want different precision.
    double m = pow(10.0, decimal_precision);
    if (num > 0)
        return (num * m) + 0.5;
    else
        return (num * m) - 0.5;
}

// Returns true if the point is in the field.
// Returns false otherwise.
// The points are compared with 'round_when_in_field_check' digits of preision after the decimal point.
// Points which lie on the contour of the field are considered inside the field.
bool IsPointInField(point p, const int xmax_r, const int ymax_r, const int xmin_r, const int ymin_r) {

    // 'x' and 'y' of the point rounded to 'round_when_in_field_check' decimal places.
    int x_r = RoundANumber(p.x, round_when_in_field_check);
    int y_r = RoundANumber(p.y, round_when_in_field_check);
   
    if (xmin_r <= x_r && x_r <= xmax_r &&
        ymin_r <= y_r && y_r <= ymax_r)
    {
        return true;
    }
    else
        return false;
    
}

// Takes in the distance between 2 points and approximates the distance traversed by the player.
double ApproximateDistance(const double dist) {
    return ((pi * dist) / 2 + dist) / 2;
}

// Returns the coordinater of the point at which the linesegment A1A2 crosses the border of the field.
point CrossingPoint(const point A1, const point A2) {
    
    // General equation of a line: ax + by + c = 0.
    // The equations for the sides of the field are:
    // g1: x = 5,
    // g2: y = 2,
    // g3: x = -5,
    // g4: y = -2.
    point cross(0.0, 0.0);
    double a = A2.y - A1.y;
    double b = A1.x - A2.x;
    double c = A2.x * A1.y - A1.x * A2.y;

    // First side (of the rectangle).
    double var = ((a * 5.0) + c) / -b;
    if (-2.0 <= var && var <= 2.0) {
        cross.x = 5.0;
        cross.y = var;
        return cross;
    }

    // Second side.
    var = ((b * 2.0) + c) / -a;
    if (-5.0 <= var && var <= 5.0) {
        cross.x = var;
        cross.y = 2.0;
        return cross;
    }

    // Third side.
    var = ((a * -5.0) + c) / -b;
    if (-2.0 <= var && var <= 2.0) {
        cross.x = -5.0;
        cross.y = var;
        return cross;
    }

    // Fourth side.
    var = ((b * -2.0) + c) / -a;
    if (-5.0 <= var && var <= 5.0) {
        cross.x = var;
        cross.y = -2.0;
        return cross;
    }

    return cross;
}

// Returns the total distance traversed by the football player.
double ComputeDistance(point* positions, int n) {
    
    /* Round the numbers which define the boundaries of the field. */
    // This does not need to be computed every time.
    // I'm leaving it this way because now there are only 2 constants ('round_when_in_field_check' and 'round_input')
    // which set the rouding precision. This way we do not have to worry about the actual rounding procedure
    // and just easyly change the 2 constants if we want different precision.
    int xmax_r = RoundANumber(xmax, round_when_in_field_check);
    int ymax_r = RoundANumber(ymax, round_when_in_field_check);
    int xmin_r = RoundANumber(xmin, round_when_in_field_check);
    int ymin_r = RoundANumber(ymin, round_when_in_field_check);

    bool previous_point = true;    // 'True' if the previous point is in the boundaries of the field, 'false' if otherwise.
    bool current_point = true;     // 'True' if the current point is in the boundaries of the field, 'false' if otherwise.

    // Is the first point in the field.
    previous_point = IsPointInField(positions[0], xmax_r, ymax_r, xmin_r, ymin_r);

    // Go through all points and calculate the distance between them.
    double total_distance = 0.0;
    for (int i = 1; i < n; ++i) {
        current_point = IsPointInField(positions[i], xmax_r, ymax_r, xmin_r, ymin_r);

        if (current_point && previous_point) {  // Current and previous point are in the field.
            total_distance += ApproximateDistance(sqrt(pow(positions[i-1].x - positions[i].x, 2.0) + pow(positions[i-1].y - positions[i].y, 2.0)));
        }
        else if ((!current_point) && (!previous_point)) {   // Both current and previous are outside the field.
            continue;
        }
        else {  // One of the points is in the field and the other is outside.
            
            point cross = CrossingPoint(positions[i - 1], positions[i]);
            if (previous_point) {// Previous point is in.
                total_distance += ApproximateDistance(sqrt(pow(positions[i - 1].x - cross.x, 2.0) + pow(positions[i - 1].y - cross.y, 2.0)));
            }
            else {  // Previous point is out.
                total_distance += ApproximateDistance(sqrt(pow(positions[i].x - cross.x, 2.0) + pow(positions[i].y - cross.y, 2.0)));
            }

            previous_point = current_point;
        }
    }

    return total_distance;
}

//-------------------------------------------------- Logic --------------------------------------------------


void TestFunction(point* positions, int n);

int main() {
    int n = Inp_n();
    // Array of points with size 'n'.
    point* positions = new(std::nothrow) point[n];
    if (!positions) {
        std::cout << "\n\nFail to allocate memory!\nClosing the program...\n";
        return 1;
    }

    // The total distance traverced by the player during the game.
    double distance = ComputeDistance(positions, n);

    std::cout << "\n\nThe total distance traverced by the player during the game is "
            << std::fixed << std::setprecision(3) << distance << " units.\n\n";
    // 'std::fixed' - write floating-point values in fixed-point notation.

    // Test
   // TestFunction(positions, n);

    delete[] positions;
    return 0;
}

// Place to write tests for the program.
// Not used in the final program.
void TestFunction(point* positions, int n) {
    
    std::cout << std::setprecision(64) << "\n\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "\n" << i + 1 << "| x = " << positions[i].x
            << "\n" << i + 1 << "| y = " << positions[i].y;
    }
}