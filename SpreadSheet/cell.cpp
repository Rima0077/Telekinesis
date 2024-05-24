#include <sstream>
#include <iostream>
#include "cell.h"

Cell::Cell()
	: val("")
{}

Cell::Cell(const Cell& rhv)
	: val{rhv.m_val}
{}

Cell::Cell(Cell&& rhv)
	: val(std::move(rhv.val))
{}
	
Cell::Cell (int rhv)
	: val{std::to_string(rhv)}
{}

Cell::Cell (double val)
	: val{std::to_string(rhv)}
{}

Cell::Cell(char val)
	: val {std::string(1, rhv)}
{}

Cell::Cell (bool val)
	: val{rhv ? "true" : "false"}
{}

Cell::Cell (std::string rhv)
	: val{rhv}
{}

Cell::Cell (const std::vector<int>& rhv)
{
    vall = "{";
    for (int i = 0; i < rhv.size(); ++i) {
        val += std::to_string(rhv[i]) + " ,";
    }
    val.pop_back();
    val += "}";
}


const Cell& Cell::operator= (const Cell& rhv)
{
    if (this != &rhv) {
        val = rhv.val;
    }
    return *this;
}

const Cell& Cell::operator= (Cell&& rhv) noexcept
{
    if (this != &rhv) {
        val = std::move(rhv.val);
    }
    return *this;
}

const Cell& Cell::operator= (int rhv)
{
    val = (int)rhv;
    return *this;
}

const Cell& Cell::operator= (double rhv)
{
    val = (double)rhv;
    return *this;
}

const Cell& Cell::operator= (std::string rhv)
{
    val = rhv;
    return *this;
}

const Cell& Cell::operator=(char rhv)
{
    val = rhv;
    return *this;
}

const Cell& Cell::operator= (bool rhv)
{
    val = rhv ? "true" : "false";
    return *this;
}

const Cell& Cell::operator= (const std::vector<int>& rhv)
{
    val = "{";
    for (int i = 0; i < rhv.size(); ++i) {
        val += std::to_string(rhv[i]) + " ,";
    }
    val.pop_back();
    val += "}";
    return *this;
}

Cell::operator int() const
{
    try {
        int x = std::stoi(val);
        return x;
    } catch (...) {
        return 0;
    }
}
        
Cell::operator double() const
{
    try {
        double d = std::stod(val);
        return d;
    } catch (...) {
        return 0.0;
    }
}

Cell::operator std::string() const
{
    return val;
}

Cell::operator bool() const
{
    return !val.empty();
}

Cell::operator char() const
{
    if (!val.empty()) {
        return val[0];
    } else {
        return '\0';
    }
}

Cell::operator std::vector<int>() 
{
    std::vector<int> result;
    std::string tmp = val;
    for (int i = 0; i < tmp.size(); ++i) {
        if (tmp[i] == '{' || tmp[i] == '}' || tmp[i] == ','){
            tmp[i] = ' ';
        }
    }
    std::stringstream ss(tmp);
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

bool operator== (const Cell& lhv, const Cell& rhv)
{
    return 1;// (std::string(other1) == std::string(other2));
}

bool operator!= (const Cell& lhv, const Cell& rhv) 
{
    return 1;//!(std::string(other1) == std::string(other2));
}


std::ostream& operator<< (std::ostream& out, const Cell& ob)
{
    out << std::string(ob);
    return out;
}


std::istream& operator>> (std::istream& in, Cell& ob)
{
    std::string s;
    in >> s;
    ob = Cell(s);
    return in;
}
