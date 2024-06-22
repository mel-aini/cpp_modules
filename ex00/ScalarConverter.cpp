#include "ScalarConverter.hpp"
#include <string>
#include <sstream>
#include <climits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& S) {
    *this = S;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& C) {
    (void)C;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void printType(int type)
{
    std::string ctype;
    if (type == CHAR)
        ctype = "CHAR";
    else if (type == INT)
        ctype = "INT";
    else if (type == FLOAT)
        ctype = "FLOAT";
    else if (type == DOUBLE)
        ctype = "DOUBLE";
    else if (type == NOTN)
        ctype = "NAN";
    else if (type == IMP)
        ctype = "IMP";
    std::cout << "type: " << ctype << std::endl;
}

void ScalarConverter::convert(std::string literal) {
    char    charL = 0;
    int     intL = 0;
    float   floatL = 0.0f;
    double  doubleL = 0.0;
    // detect type of literal (char, int, float, double)
    int type = INT;

    int length = literal.length();
    if (length == 0)
        type = IMP;
    // std::cout << "literal: " << literal << std::endl;

    if (literal == "+inf")
        type = D_P_INF;
    else if (literal == "-inf")
        type = D_M_INF;
    else if (literal == "+inff")
        type = F_P_INF;
    else if (literal == "-inff")
        type = F_M_INF;
    else if (literal == "nan" || literal == "nanf")
        type = NOTN;
    else {
        for (int i = 0; i < length && type != IMP; i++) {
            if (std::isdigit(literal[i]))
                continue;
            else if (literal[i] == '-' || literal[i] == '+') {
                if (i != 0 || length == 1)
                    type = IMP;
            }
            else if (literal[i] == '.') {
                if (type == INT && i != 0 && i != length - 1 && std::isdigit(literal[i + 1]))
                    type = DOUBLE;
                else
                    type = IMP;
            }
            else if (literal[i] >= 32 && literal[i] <= 126) {
                if (length == 1)
                    type = CHAR;
                else if (type == DOUBLE && literal[i] == 'f' && i == length - 1)
                    type = FLOAT;
                else
                    type = IMP;
                break ;
            }
            else
                type = IMP;
        }
    }


    // printType(type);

    // convert literal to its type;

    std::stringstream str(literal);
    {
        if (type == CHAR) {
            if (literal == " ")
                charL = ' ';
            else
                str >> charL;
    
            intL = static_cast<int>(charL);
            floatL = static_cast<float>(charL);
            doubleL = static_cast<double>(charL);
        }
        else if (type == INT) {
            str >> intL;
            charL = static_cast<char>(intL);
            floatL = static_cast<float>(intL);
            doubleL = static_cast<double>(intL);
        }
        else if (type == FLOAT) {
            std::string tmp = literal.erase(literal.length() - 1, 1);
            std::stringstream newStr(tmp);
            newStr >> floatL;
                
            // floatL = static_cast<float>(floatL);
            charL = static_cast<char>(floatL);
            intL = static_cast<int>(floatL);
            doubleL = static_cast<double>(floatL);
        }
        if (type == DOUBLE) {
            str >> doubleL;
            if (type == DOUBLE) {
                // doubleL = static_cast<double>(doubleL);
                charL = static_cast<char>(doubleL);
                intL = static_cast<int>(doubleL);
                floatL = static_cast<float>(doubleL);
            }
        }
    }
    // printType(type);
    {
        {
            // display char result
            std::cout << "char: ";
            // std::cout << (int)charL << std::endl;
            if (type == NOTN || type == IMP || type == F_P_INF 
                || type == F_M_INF || type == D_P_INF || type == D_M_INF)
                std::cout << "Impossible";
            else if (intL < -127 || intL > 127)
                std::cout << "Impossible";
            else if (intL < 32 || intL > 126)
                std::cout << "Non displayable";
            else
                std::cout << "'" << charL << "'";
            std::cout << std::endl;
        }
        {
            // display int result
            std::cout << "int: ";
            if (type == NOTN || type == IMP || type == F_P_INF 
                || type == F_M_INF || type == D_P_INF || type == D_M_INF)
                std::cout << "Impossible";
            else if (intL == INT_MAX && strncmp(literal.c_str(), "2147483647", 10) != 0 && strncmp(literal.c_str(), "+2147483647", 11) != 0)
                std::cout << "Impossible";
            else if (intL == INT_MIN && strncmp(literal.c_str(), "-2147483648", 11) != 0)
                std::cout << "Impossible";
            else
                std::cout << intL;
            std::cout << std::endl;
        }
        {
            // display float result
            std::cout << "float: ";
            if (type == NOTN)
                std::cout << "nanf";
            else if (type == IMP)
                std::cout << "Impossible";
            else if (type == F_P_INF || type == D_P_INF)
                std::cout << "+inff";
            else if (type == F_M_INF || type == D_M_INF)
                std::cout << "-inff";
            else {
                    std::stringstream str2(literal);
                    long double tmp;
                    str2 >> tmp;
                    if (tmp > std::numeric_limits<float>::max() || tmp < std::numeric_limits<float>::max() * -1)
                        std::cout << "Impossible";
                    else {
                        std::cout << floatL;
                        if (floatL == static_cast<int>(floatL))
                            std::cout << ".0";
                        std::cout << "f";
                    }
            }
            std::cout << std::endl;
        }
        {
            // display double result
            std::cout << "double: ";
            if (type == NOTN)
                std::cout << "nan";
            else if (type == IMP)
                std::cout << "Impossible";
            else if (type == F_P_INF || type == D_P_INF)
                std::cout << "+inf";
            else if (type == F_M_INF || type == D_M_INF)
                std::cout << "-inf";
            else {
                std::stringstream str2(literal);
                long double tmp;
                str2 >> tmp;
                if (tmp > std::numeric_limits<double>::max() || tmp < std::numeric_limits<double>::max() * -1)
                    std::cout << "Impossible";
                else {
                    std::cout << doubleL;
                    if (doubleL == static_cast<int>(doubleL))
                        std::cout << ".0";
                }
            }
            std::cout << std::endl;
        }
    }
}