// Lesno domashno 9, zadacha 1

#include <iostream>
#include <ctime>
#include <cstdlib>
#pragma warning(disable : 4996)

// Input for N
int input() {
    int N;
    do {
        std::cout << "N=";
        std::cin >> N;
        if (N > 0) {
            return N;
        }
        else {
            std::cout << "Number must be N > 0.\n";
        }
    } while (true);
}

// Returns the n-th exclamation word
const char* exclamations() {
    int n = rand() % 4;

    switch (n) {
    case 0:
        return "UJAS";
    case 1:
        return "SHOK";
    case 2:
        return "NE4UVANO";
    case 3:
        return "NEVEROQTNO";
    }
}

// Returns the n-th action word
const char* actions() {
    int n = rand() % 4;

    switch (n) {
    case 0:
        return " ograbva";
    case 1:
        return " predava";
    case 2:
        return " tormozi";
    case 3:
        return " bazika";
    }
}

// Returns the n-th subj or obj
const char* ob_sb(bool ob_or_sb) {
    int n;
    if (ob_or_sb)
        n = rand() % 3;
    else
        n = (rand() % 4) + 1;

    switch (n) {
    case 0:
        return " Pozhar";
    case 1:
        return " Ku4e";
    case 2:
        return " Chovek";
    // Only subjects
    case 3:
        return " Delva";
    case 4:
        return " Karuca";
    }

}

// Inserts n exclamation marks
void mark(char* hd, size_t n) {
    for (size_t i = 0; i < n; ++i)
        strcat(hd, "!");

    return;
}

void generate_headline() {
    const char* ex = exclamations();    // Exclamation word

    const char* act = actions();        // Action word

    const char* ob = ob_sb(true);       // Object word

    const char* sb = ob_sb(false);      // Subject word

    size_t sign = (rand() % 7) + 3;     // Number of exclamation marks (n = [3, 9]) (!)

    size_t L = strlen(ex) + sign + strlen(ob) + strlen(act) + strlen(sb) + 1;   // Length of the dinamic array (length of the characters +1 for 0)

    char* hd = new(std::nothrow) char[L];
    if (hd) {
        strcpy(hd, ex);
        mark(hd, sign);
        strcat(hd, ob);
        strcat(hd, act);
        strcat(hd, sb);
        std::cout << hd << std::endl;
    }
    
    delete[] hd;
    return;
}

int main()
{
    srand(time(0));

    int N = input();    // Number of scandalous headlines

    for (int i = 0; i < N; ++i)
        generate_headline();

    return 0;
}