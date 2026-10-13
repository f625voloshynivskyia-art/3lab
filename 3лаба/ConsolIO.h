#ifndef CONSOLIO_H
#define CONSOLIO_H

#include <iostream>
#include <string>
#include <limits>
#include <Windows.h>

class ConsolIO {
public:
    static double GetValue(std::istream& is) {
        double value;
        while (true) {
            if (is >> value) {
                is.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                return value;
            }
            else {
                std::cout << "\n\tÍÅÊÎÐÅÊÒÍÈÉ ÂÂ²Ä! Î÷³êóºòüñÿ ÷èñëî. Ïîâòîð³òü ââ³ä: ";
                is.clear();
                is.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            }
        }
    }

    static int GetInt(std::istream& is) {
        return static_cast<int>(GetValue(is));
    }

    static std::string GetText(std::istream& is) {
        std::string buffer;
        while (true) {
            std::getline(is, buffer);
            if (!buffer.empty()) {
                bool onlySpaces = true;
                for (char c : buffer) {
                    if (c != ' ' && c != '\t' && c != '\r') {
                        onlySpaces = false;
                        break;
                    }
                }
                if (!onlySpaces) {
                    return buffer;
                }
            }
            std::cout << "\n\tÍÅÊÎÐÅÊÒÍÈÉ ÂÂ²Ä! Ââåä³òü òåêñòîâå çíà÷åííÿ: ";
        }
    }
};

#endif // CONSOLIO_H