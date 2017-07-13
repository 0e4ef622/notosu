#ifndef NOTOSU_RESOURCEMANAGER_HPP
#define NOTOSU_RESOURCEMANAGER_HPP

#include <iostream>
#include <map>

template<typename T>
T &getResource(std::string filename) {

    static std::map<std::string, T> table;

    auto i = table.find(filename);
    if (i != table.end())
        return i->second;

    if (!table[filename].loadFromFile(filename))
        std::cerr << "Someting hapen wen try load " << filename << std::endl;

    return table[filename];
}

#endif // NOTOSU_RESOURCEMANAGER_HPP
