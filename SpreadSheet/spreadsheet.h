#ifndef __SPREADSHEET__H__
#define __SPREADSHEET__H__

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <cstddef>
#include <iomanip>

#include "cell.h"

class Spreadsheet
{
private:
    Cell** board;
    size_t rowcnt;
    size_t colcnt;
private:
    class Column;
public:

    Spreadsheet();
    Spreadsheet(const Spreadsheet& rhv);
    Spreadsheet(Spreadsheet&& rhv);
    Spreadsheet(size_t size);
    Spreadsheet(size_t row, size_t col);
    ~Spreadsheet();

    const Spreadsheet& operator=(const Spreadsheet& rhv);
    const Spreadsheet& operator=(Spreadsheet&& rhv);

    Column operator[](size_t pos);
    const Column operator[](size_t pos) const;

    void clear() noexcept;

    size_t row() const;
    size_t col() const;
    
    void mirrorH();
    void mirrorV();
    void mirrorD();
    void mirrorSD();

    void rotate(int cnt);

    void removeRow(size_t row);
    void removeRows(std::initializer_list<size_t> rows);
    void removeCol(size_t col);
    void removeCols(std::initializer_list<size_t> cols);

    void resizeRow(size_t r);
    void resizeCol(size_t c);
    void resize(size_t r, size_t c);


    Spreadsheet slice(std::initializer_list<size_t> rows, std::initializer_list<size_t> cols);        
};


class Spreadsheet::Column {
    private:
        Cell* col;
    public:
        explicit Column(Cell* col);
    public:
        Column() = delete; 

        const Column& operator=(const Column&) = delete;
        const Column& operator=(Column&&) = delete;
    public:
        Cell& operator[](size_t pos);
        const Cell& operator[](size_t pos) const;
};

bool operator==(const Spreadsheet& lhv, const Spreadsheet& rhv);
bool operator!=(const Spreadsheet& lhv, const Spreadsheet& rhv);

std::ostream& operator<<(std::ostream& out, const Spreadsheet& ob); // beauty output using iomanip library



#endif //__SPREADSHEET__H__
