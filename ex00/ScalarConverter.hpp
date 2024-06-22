#pragma once
#include <iostream>
#include <limits>

enum types {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    F_P_INF,
    F_M_INF,
    D_P_INF,
    D_M_INF,
    NOTN,
    IMP,
};

class ScalarConverter {
    private:
        ScalarConverter();

    public:
        ScalarConverter(const ScalarConverter& S);
        ScalarConverter& operator= (const ScalarConverter& C);
        ~ScalarConverter();

        static void convert(std::string literal);
};

// > 255 impossible