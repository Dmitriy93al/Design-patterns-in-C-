#include "Data.h"

int main(int argc, char* argv[]) {
    std::ofstream file("file.txt");
    Data data{ "hello world!" };
    Printer* printer = new PrinterJSON{};
    DataFormatter formatter{};
    formatter.format(data, printer, file);
    return 0;
}