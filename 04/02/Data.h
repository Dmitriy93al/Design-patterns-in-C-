#pragma once
#include <iostream>
#include <fstream>
#include <string>

struct Data {
    std::string data_string;
};

class Printer {
public:
    Printer() = default;
    virtual ~Printer() = default;
    virtual std::string wrap(const Data& data) const = 0;
    Data data;
};

class PrinterHTML : public Printer {
public:
    std::string wrap(const Data& data) const override;
};

class PrinterJSON : public Printer {
public:
    std::string wrap(const Data& data) const override;
};

class PrinterText : public Printer {
public:
    std::string wrap(const Data& data) const override;
};

class DataFormatter {
public:
    void format(Data& data, Printer* printer, std::ofstream& file) const;
};