#include "spreadsheet.h"

Spreadsheet::Spreadsheet ()
	: Spreadsheet (2, 2)
{}

Spreadsheet::Spreadsheet (const Spreadsheet& rhv)
    : rowcnt {rhv.rowcnt}
    , colcnt {rhv.colcnt}
    , board {new Cell*[board]}
{
    for(int i = 0; i < rowcnt; ++i) {
        board[i] = new Cell[colcnt];
    }
    for(int i = 0; i < rowcnt; ++i) {
        for(int j = 0; j < colcnt; ++j) {
            board[i][j] = rhv.board[i][j];
        }
    }
}

Spreadsheet::Spreadsheet (Spreadsheet&& rhv)
    : rowcnt{rhv.rowcnt}
    , colcnt{rhv.colcnt}
    , board{new Cell*[rowcnt]}
{
    rhv.rowcnt = 0;
    rhv.colcnt = 0;
    rhv.board = nullptr;
}

Spreadsheet::Spreadsheet (size_t size)
	: Spreadsheet (size, size)
{}

Spreadsheet::Spreadsheet (size_t row, size_t col)
	: rowcnt {row}
	, colcnt {col}
	, board{new Cell*[rowcnt]}
{
    for(int i = 0; i < rowcnt; ++i) {
        board[i] = new Cell[colcnt];
    }

Spreadsheet::~Spreadsheet () 
{
	clear();
}

const Spreadsheet::Spreadsheet& operator=(const Spreadsheet& rhv)
{
    if (this != &rhv) {
        for (int i = 0; i < rowcnt; ++i) {
            delete[] board[i];
        }
        delete board;
        rowcnt = rhv.rowcnt;
        colcnt = rhv.colcnt;
        board = rhv.board;
        rhv.board = nullptr;
    }
    return *this;
}

const Spreadsheet::Spreadsheet& operator=(Spreadsheet&& rhv)
{
    if (this != &rhv) {
        for (int i = 0; i < rowcnt; ++i) {
            delete[] board[i];
        }
        delete board;
        rowcnt = rhv.rowcnt;
        colcnt = rhv.colcnt;
        board = rhv.board;
        rhv.board = nullptr;
    }
    return *this;
}

Column Spreadsheet::operator[] (size_t pos)
{ 
    return  Column(board[pos]);
}

const Column Spreadsheet::operator[] (size_t pos) const
{
    return Column(board[pos]);
}

void Spreadsheet::clear () noexcept
{
    for (int i = 0; i < rowcnt; ++i) {
        delete[] board[i];
    }
    delete[] board;
    board = nullptr;
    colcnt = 0; 
    rowcnt = 0;
}

size_t Spreadsheet::row() const
{
    return rowcnt;
}
size_t Spreadsheet::col() const
{
    return colcnt;
}
void Spreadsheet::mirrorH()
{
    for(int i = 0; i < rowcnt / 2; ++i) { 
        for(int j = 0; j < colcnt; ++j) {
            std::swap(board[i][j], board[rowcnt - i - 1][j]);
        }
    }
}
void Spreadsheet::mirrorV()
{
    for(int i = 0; i < rowcnt; ++i) {
        for(int j = 0; j < colcnt / 2; ++j) {
            std::swap(board[i][j], board[i][colcnt - j - 1]); 
        }
    }
}
void Spreadsheet::mirrorD()
{
    for(int i = 1; i < rowcnt; ++i) {
        for(int j = 0; j < i; ++j) {
            std::swap(board[i][j], board[j][i]);        
        }
    }
}
void Spreadsheet::mirrorSD()
{
     for(int i = 0; i < rowcnt; ++i) {
        for(int j = 0; j < colcnt - i; ++j) {
            std::swap(board[i][j], board[rowcnt - 1 - j][colcnt - 1 - i]);
        }
    }
}
void Spreadsheet::rotate(int cnt)
{
    bool flag = false;
    if (cnt < 0) {
        flag = true;
        cnt *= -1;
    }
    cnt = cnt % 4;
    if (cnt == 0) {
        return;
    }
    if (!flag) {
        for(int i = 0; i < cnt; ++i) {
            mirrorH();
            mirrorD();
        }
    } else {
        for(int i = 0; i < cnt; ++i) {  
            mirrorV();
            mirrorD();
        }
    }
}

void Spreadsheet::removeRow (size_t row)
{
    if (row >= rowcnt) {
        throw std::out_of_range("Invalid index.");
    }

    row -= 1;
    Cell** temp = new Cell*[rowcnt - 1];
    for (int i = 0, k = 0; i < rowcnt; ++i) {
        if (i == row) {
            continue;
        }
        temp[k] = new Cell[colcnt];
        for (int j = 0; j < colcnt; ++j) {
            temp[k][j] = board[i][j];
        }
        ++k;
    }

    for (int i = 0; i < rowcnt; ++i) {
        delete[] board[i];
    }
    delete[] board;

    board = temp;
    --rowcnt;
}

void Spreadsheet::removeRows (std::initializer_list<size_t> rows)
{
    auto it = rows.end(); 
    while (it != rows.begin()) {
        --it; 
        removeRow(*it); 
    }
}

void Spreadsheet::removeCol (size_t col)
{
    if (col >= colcnt) {
        throw std::out_of_range("Invalid index.");  
    }

    col -= 1;
    Cell** temp = new Cell*[rowcnt];
    for (int i = 0; i < rowcnt; ++i) {
        temp[i] = new Cell[colcnt - 1];
        for (int j = 0, k = 0; j < colcnt; ++j) {
            if (j == col) {
                continue;
            }
            temp[i][k++] = board[i][j];
        }
    }

    for (int i = 0; i < rowcnt; ++i) {
        delete[] board[i];
    }
    delete[] board;

    board = temp;
    --colcnt;
}

void Spreadsheet::removeCols (std::initializer_list<size_t> cols)
{
    auto it = cols.end();
    while (it != cols.begin()) {
        --it;
        removeCol(*it);
    }
}
void Spreadsheet::resizeRow (size_t r)
{
    int size = rowcnt + r;
    Cell** tmp = new Cell*[size];
    for(int i = 0; i < size; ++i){
        tmp[i] = new Cell[colcnt];
    }

    for(int i = 0; i < rowcnt; ++i){
        for(int j = 0; j < colcnt; ++j){
            tmp[i][j] = board[i][j];
        }
    } 

    for(int i = 0; i < rowcnt; ++i){
        delete[] board[i];
    } 

    delete[] board;
    board = tmp;
    rowcnt = size;
    tmp = nullptr;
}

void Spreadsheet::resizeCol (size_t c)
{
    int size = m_col + c;
    Cell** tmp = new Cell*[rowcnt];
    for(int i = 0; i < rowcnt; ++i){
        tmp[i] = new Cell[size];
    }

    for(int i = 0; i < rowcnt; ++i){
        for(int j = 0; j < colcnt; ++j){
            tmp[i][j] = board[i][j];
        }
    }

    for(int i = 0; i < rowcnt; ++i){
        delete[] board[i];
    }

    delete[] board;
    board = tmp;
    colcnt = size;
    tmp = nullptr;
}

void Spreadsheet::resize (size_t r, size_t c)
{
    resize_row(r);
    resize_col(c);
}

SpreadSheet slice (std::initializer_list <size_t> rows, std::initializer_list<size_t> cols)
{
    SpreadSheet slicedSheet;
    size_t numRows = rows.size();
    size_t numCols = cols.size();

    slicedSheet.rowcnt = numRows;
    slicedSheet.colcnt = numCols;
    slicedSheet.board = new Cell*[numRows];

    size_t rowIndex = 0;
    for (auto row : rows) {
        size_t colIndex = 0;
        slicedSheet.board[rowIndex] = new Cell[numCols];
        for (auto col : cols) {
            slicedSheet.board[rowIndex][colIndex] = board[row - 1][col - 1];
            colIndex++;
        }
        rowIndex++;
    }
    return slicedSheet;    
}

Column::Column (Cell* col) 
    : col {col}
{}


Cell& Column::operator[] (size_t index) 
{
    return col[index];
}

const Cell& Column::operator[] (size_t index) const 
{
    return col[index];
}

std::ostream& operator<<(std::ostream& out, const SpreadSheet& ob)
{
    int width = 8;
    double width_table = ob.col() * 9.1;
    int h_line = 1;
    for (size_t i = 0; i < ob.row(); ++i)
    {
        for(size_t k = 0; k < width_table; ++k)
        {
            out << std::setw(1) << "-";
        }
        out << "\n";
        for(size_t j = 0; j < ob.col(); ++j)
       	{
            out << std::setw(h_line) << "|" << std::setw(width) << std::left << ob[i][j];
        }
        out << std::setw(h_line) << "|";
        out << "\n";
    }
    for(size_t k = 0; k < width_table; ++k)
    {
        out << std::setw(1) << "-";
    }
    out << "\n";
    return out;
}

bool operator==(const SpreadSheet& lhv, const SpreadSheet& rhv)
{
    if ((lhv.col() != rhv.col()) || (lhv.row() != rhv.row())) {
        return false;
    }
    for (int i = 0; i < lhv.row(); ++i) {
        for (int j = 0; j < lhv.col(); ++j) {
            if (lhv[i][j] != rhv[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const SpreadSheet& lhv, const SpreadSheet& rhv
{
    return !(lhv == rhv;
}



