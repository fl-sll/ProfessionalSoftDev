#ifndef PATRON_H
#define PATRON_H

#include <string>

class Patron {
public:
    Patron(std::string name);
    std::string getName() const;
private:
    std::string name;
};

#endif  // PATRON_H