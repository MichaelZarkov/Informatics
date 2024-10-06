#include <iostream>
#include <limits>       // For std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#include <cstdlib>      // !!!

// TO DO !!!:
//  - find out what was <cstdlib> for.
//  - in the requirements of the task is written that the floating point precision must be 3 digits after the decimal point,
//      I have not done that here :)


const double R1 = 8.0;  //
const double R2 = 3.0;  // radii of the circles
const double R3 = 1.0;  //

const int R1_score = 10;        //
const int R2_score = 20;        // Points
const int R3_score = 60;        //
const int wire_score = 0;       //

const int max_str_len = 50;

// If there is a valid double number in the string -
// returns a pointer to the character in the string after the number.
// Returns 'nullptr' otherwise.
char* IsNumber(char* ptr) {
    if (*ptr < '0' || '9' < *ptr)
        return nullptr;

    // Skip to the decimal point.
    do {
        ++ptr;
    } while ('0' <= *ptr && *ptr <= '9');

    if (*ptr != '.')
        return nullptr;
    
    ++ptr;
    if (*ptr < '0' || '9' < *ptr)
        return nullptr;

    // Skip to the decimal point.
    do {
        ++ptr;
    } while ('0' <= *ptr && *ptr <= '9');

    return ptr;
}

// Returns (x,y) coordinates.
void Input(double& x0, double& y0) {
    char coord[max_str_len];
    do {
        std::cin.get(coord, max_str_len, '\n');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        char* pcoord = coord;
        char* psec_num = nullptr;

        // Check for '('
        if (*pcoord != '(') {
            std::cout << "Invalid coordinates! Try again!\n";
            continue;
        }

        pcoord = IsNumber(pcoord + 1);
        if (!pcoord) {
            std::cout << "Invalid coordinates! Try again!\n";
            continue;
        }

        // Check for ','
        if (*pcoord != ',') {
            std::cout << "Invalid coordinates! Try again!\n";
            continue;
        }
        psec_num = pcoord + 1;

        pcoord = IsNumber(pcoord + 1);
        if (!pcoord) {
            std::cout << "Invalid coordinates! Try again!\n";
            continue;
        }

        // Check for ')'
        if (*pcoord != ')' || *(pcoord + 1)) {
            std::cout << "Invalid coordinates! Try again!\n";
            continue;
        }
        else {
            x0 = atof(coord + 1);
            y0 = atof(psec_num);
            return;        
        }
    } while (true);


    return;
}

// Calculates the actual score of Integralcho and returns it.
int Score(double x, double y, double u, double v) {
    double xtrue = x + u;
    double ytrue = y + v;
    double radius = (xtrue * xtrue) + (ytrue * ytrue);
    radius = sqrt(radius);
    // double radius = sqrt((xtrue * xtrue) + (ytrue * ytrue));    // Distance of the point to the real center of the dart board.

    std::cout << "\n" << radius << "\n";

    if (radius >= R1) {     // Outside of R1.
        return wire_score;
    }
    else if (radius > R2) { // Between R1 and R2.
        return R1_score;
    }
    else if (radius > R3) { // Between R2 and R3.
        if (radius == R2)   // The dart hits the wire.
            return wire_score;
        else
            return R2_score;
    }
    else {                  // Between 
        if (radius == R3)
            return wire_score;
        else
            return R3_score;
    }
}

int main() {
    
    double x = 0.0, y = 0.0, u = 0.0, v = 0.0;
    
    std::cout << "Input (x,y) = ";      // Point at which Integralcho is aiming
    Input(x, y);
    std::cout << "Input (u,v) = ";      // Integralcho's sight deviation
    Input(u, v);

    std::cout << "\nThe real score of Integralcho is " << Score(x, y, u, v) << " points\n";

    /*
    int a = 2;
    std::cout << "a = " << a << "\n";

    do {
        std::cout << "Input an integer number: ";
        
        if (std::cin >> a) {
            break;      // If everything is OK then 'break'.
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "The input was no an integer! Try again.\n";
            std::cout << "a = " << a << "\n";
        }
    } while (1);

    std::cout << "a = " << a;
    std::cout << "\ncin state: " << std::cin.rdstate();

    int b = 3;
    std::cin >> b;
    std::cout << "\nb = " <<b;
    std::cout << "\ncin state: " << std::cin.rdstate();
*/

/*
    std::string mystring;
    std::getline(std::cin, mystring);
    std::cout << "\nmystring: " << mystring;
*/

    return 0;
}