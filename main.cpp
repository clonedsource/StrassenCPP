#include <iostream>
#include <string>
#include <format>
#include "Matrix.h"

using namespace std;

// Variable used to track memory used by matrices.
size_t TRACKED_MEM = 0;

// size_t -> "X B";
string format_byte_size(const size_t byte_size) {
    // Converts it to a sufficiently long type.
    long double doubleized = (long double)byte_size;
    // Takes the Log.
    int doublelog = (int)(std::log10l(doubleized)/std::log10l(1000.0));

    /* Domain expansion: string maniulation.
        Jokes aside basically first line is a ternary that processes a list of characters
        into the correct prefix letter for byte shorthands. The second line checks if
        the suffix contains "B" or a non "B" character and therefore needs to append
        the "B" character.
    */
    string suffix(1, "BKMGT?"[((doublelog > 5) ? 5 : doublelog)]); // B, K, M, G, T, ?.
    suffix = (suffix.compare("B") == 0) ? suffix : suffix.append("B"); // B, KB, MB, GB, TB, ?B.
    
    char* buffer = new char[10]; // xxx.xx NB \0
    // Formats.
    snprintf(buffer, sizeof(char)*10, "%.2f %s", doubleized / std::powl(1000.0, doublelog), suffix.c_str());
    // Returns.
    return buffer;
};

int main() {

    Matrix ma(8, 8, new double[64]{1.0});
    Matrix cm = ma * 3.0;
    cm *= 5.0;
    cm /= 3.0;
    try {
        cm += ma;
    } catch (const std::runtime_error &e) {std::cerr << "Error: " << e.what() << std::endl;};
    string size_mem_str = format_byte_size(ma.size_mem() + cm.size_mem());
    std::cout << size_mem_str << std::endl;
    std::cout << ma.format() << std::endl;
    std::cout << cm.format() << std::endl;
    return 0;
}