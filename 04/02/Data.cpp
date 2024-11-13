#include "Data.h"

std::string PrinterHTML::wrap(const Data& data) const {
    return "<html>" + data.data_string + "<html/>";
};

std::string PrinterJSON::wrap(const Data& data) const {
        return "{ \"data\": \"" + data.data_string + "\"}";
};

std::string PrinterText::wrap(const Data& data) const {
    return data.data_string;
};

void DataFormatter::format(Data& data, Printer* printer, std::ofstream& file) const {
    file << printer->wrap(data);
}