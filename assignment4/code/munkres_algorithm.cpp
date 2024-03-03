#include <vector>
#include <iostream>
#include <algorithm>
#include "munkres_algorithm.hpp"

// The idea of implementation is taken from the following reference:
//http://csclab.murraystate.edu/~bob.pilgrim/445/munkres.html

using namespace std;

// Find minimum value of each row and column and subtract from the values respectively
void reduceMatrix(Matrix<int>& c, size_t row_size, size_t col_size) {
    // Reduce each row by its minimum value
    for (size_t row = 0; row < row_size; ++row) {
        int min_row_value = *min_element(&c(row, 0), &c(row, 0) + col_size);
        for (size_t col = 0; col < col_size; ++col) {
            c(row, col) -= min_row_value;
        }
    }
    // Reduce each column by its minimum value
    for (size_t col = 0; col < col_size; ++col) {
        int min_col_value = c(0, col);
        for (size_t row = 1; row < row_size; ++row) {
            if (c(row, col) < min_col_value) {
                min_col_value = c(row, col);
            }
        }
        for (size_t row= 0; row < row_size; ++row) {
            c(row, col) -= min_col_value;
        }
    }
}

void step1(size_t& step, Matrix<int>& c, size_t row_size, size_t col_size) {
    reduceMatrix(c, row_size, col_size);
    step = 2;
}



// Find zeroes in new matrix, if there is no zero, star z, introducing mask matrix
void starZerosAndResetCovers(Matrix<int>& c, size_t row_size, size_t col_size, vector<bool>& cover_r, vector<bool>& cover_c, Matrix<int>& cover_matrix) {
    // Star zeros and update cover arrays
    for (size_t row = 0; row < row_size; ++row) {
        for (size_t col = 0; col < col_size; ++col) {
            if (c(row, col) == 0 && !cover_r[row] && !cover_c[col]) {
                cover_matrix(row, col) = 1;
                cover_r[row] = true;
                cover_c[col] = true;
            }
        }
    }

    // Reset cover arrays for rows and columns
    std::fill(cover_r.begin(), cover_r.end(), false);
    std::fill(cover_c.begin(), cover_c.end(), false);
}

void step2(size_t& step, Matrix<int>& c, size_t row_size, size_t col_size, vector<bool>& cover_r, vector<bool>& cover_c, Matrix<int>& cover_matrix) {
    starZerosAndResetCovers(c, row_size, col_size, cover_r, cover_c, cover_matrix);
    step = 3;
}

// Cover column having starred zero. if n columns are covered go to done, else next step
void coverColumnsWithStarredZeros(const Matrix<int>& cover_matrix, vector<bool>& cover_c, size_t row_size, size_t col_size) {
    for (size_t col = 0; col < col_size; ++col) {
        for (size_t row = 0; row < row_size; ++row) {
            if (cover_matrix(row, col) == 1) {
                cover_c[col] = true;
                break; // Once a starred zero is found in a column, move to the next column
            }
        }
    }
}

void step3(size_t& step, const size_t row_size, const size_t col_size, vector<bool>& cover_c, const Matrix<int>& cover_matrix) {
    coverColumnsWithStarredZeros(cover_matrix, cover_c, row_size, col_size);

    size_t coveredColumnsCount = count(cover_c.begin(), cover_c.end(), true);
    step = (coveredColumnsCount >= col_size || coveredColumnsCount >= row_size) ? 7 : 4;
}

void find_zero(const Matrix<int>& c, const vector<bool>& cover_r, const vector<bool>& cover_c, size_t row_size, size_t col_size, int& row, int& col) {
    row = -1;
    col = -1;

    for (size_t i = 0; i < row_size; ++i) {
        for (size_t j = 0; j < col_size; ++j) {
            if (c(i, j) == 0 && !cover_r[i] && !cover_c[j]) {
                row = static_cast<int>(i);
                col = static_cast<int>(j);
                return; // Exit the function as soon as an uncovered zero is found
            }
        }
    }
}


bool hasStarredZeroInRow(const Matrix<int>& cover_matrix, int row, size_t col_size) {
    for (size_t col = 0; col < col_size; ++col) {
        if (cover_matrix(row, col) == 1) {
            return true; // Return true immediately upon finding a starred zero
        }
    }
    return false; // Return false if no starred zero is found in the row
}

void findStarInRow(const Matrix<int>& cover_matrix, int row, int& col, size_t col_size) {
    col = -1; // Default value indicating no starred zero is found
    for (size_t j = 0; j < col_size; ++j) {
        if (cover_matrix(row, j) == 1) {
            col = static_cast<int>(j);
            break; // Exit the loop as soon as a starred zero is found
        }
    }
}


// Find non-covered zero and prime it
void processUncoveredZeros(Matrix<int>& c, Matrix<int>& cover_matrix, vector<bool>& cover_r, vector<bool>& cover_c, size_t row_size, size_t col_size, int& r_num, int& c_num, size_t& step) {
    while (true) {
        int row, col;
        find_zero(c, cover_r, cover_c, row_size, col_size, row, col);

        if (row == -1) { // No uncovered zero found
            step = 6;
            break;
        }

        cover_matrix(row, col) = 2; // Prime the found zero
        if (!hasStarredZeroInRow(cover_matrix, row, col_size)) {
            r_num = row;
            c_num = col;
            step = 5;
            break;
        }

        findStarInRow(cover_matrix, row, col, col_size);
        cover_r[row] = true;
        cover_c[col] = false;
    }
}

void step4(size_t& step, Matrix<int>& c, Matrix<int>& cover_matrix, vector<bool>& cover_r, vector<bool>& cover_c, size_t row_size, size_t col_size, int& r_num, int& c_num) {
    processUncoveredZeros(c, cover_matrix, cover_r, cover_c, row_size, col_size, r_num, c_num, step);
}

void search_col_star(const int &col_val, int &i, Matrix<int> &cover_matrix, size_t &row_size)
{
    i = -1;
    for(size_t r=0; r<row_size;r++)
    {
        if(cover_matrix(r, col_val) == 1)
        {
            i = r;
        }
    }
}

void row_prime(int &row_val, int &j, Matrix<int> &cover_matrix, size_t &col_size)
{
    for (size_t c=0; c<col_size; c++)
    {
        if (cover_matrix(row_val, c) == 2)
        {
            j = c;
        }
    }
}

// Construct alternate matrix with prime and starred zero.
void updateAlternatingSeries(Matrix<int>& old_matrix, Matrix<int>& cover_matrix, int& r_num, int& c_num, size_t& pcount, size_t row_size, size_t col_size) {
    int row = r_num, col = c_num;
    pcount = 0;

    do {
        old_matrix(pcount, 0) = row;
        old_matrix(pcount, 1) = col;
        pcount++;

        // Find starred zero in the column
        for (row = 0; row < row_size; ++row) {
            if (cover_matrix(row, col) == 1) {
                old_matrix(pcount, 0) = row;
                old_matrix(pcount, 1) = col;
                pcount++;
                break;
            }
        }

        // Find primed zero in the row
        if (row < row_size) {
            for (col = 0; col < col_size; ++col) {
                if (cover_matrix(row, col) == 2) {
                    break;
                }
            }
        }
    } while (row < row_size);
}

void StarsAndPrimes(Matrix<int>& cover_matrix, const Matrix<int>& old_matrix, size_t pcount) {
    for (size_t i = 0; i < pcount; ++i) {
        int r = old_matrix(i, 0), c = old_matrix(i, 1);
        cover_matrix(r, c) = (cover_matrix(r, c) == 1) ? 0 : 1;
    }
}

void resetCoversAndPrimes(vector<bool>& cover_r, vector<bool>& cover_c, Matrix<int>& cover_matrix, size_t row_size, size_t col_size) {
    fill(cover_r.begin(), cover_r.end(), false);
    fill(cover_c.begin(), cover_c.end(), false);

    for (size_t r = 0; r < row_size; ++r) {
        for (size_t c = 0; c < col_size; ++c) {
            if (cover_matrix(r, c) == 2) {
                cover_matrix(r, c) = 0;
            }
        }
    }
}

void step5(size_t& step, Matrix<int>& old_matrix, Matrix<int>& cover_matrix, vector<bool>& cover_r, vector<bool>& cover_c, int r_num, int c_num, size_t row_size, size_t col_size) {
    size_t pcount;
    updateAlternatingSeries(old_matrix, cover_matrix, r_num, c_num, pcount, row_size, col_size);
    StarsAndPrimes(cover_matrix, old_matrix, pcount);
    resetCoversAndPrimes(cover_r, cover_c, cover_matrix, row_size, col_size);
    step = 3;
}


void step6(size_t &step, Matrix<int> &c, vector<bool> &cover_r, vector<bool> &cover_c, size_t &row_size, size_t &col_size)
{
    int new_min_val = 10000000000;
    for (size_t i=0; i<row_size; i++)
    {
        for (size_t j=0; j<col_size; j++)
        {
            if (cover_r[i] == false && cover_c[j] == false)
            {
                if (new_min_val > c(i,j))
                {
                    new_min_val = c(i,j);
                }
            }
        }
    }
    for (size_t i=0; i< row_size; i++)
    {
        for (size_t j=0; j<col_size; j++)
        {
            if (cover_r[i] == true)
            {
                c(i,j) += new_min_val;
            }
            if (cover_c[j] == false)
            {
                c(i,j) -= new_min_val;
            }
        }
    }
    step = 4;

}

Matrix<int> run_munkres_algorithm(Matrix<int> c) {
    size_t row_size, col_size, step = 1;
    int c_num = 0, r_num = 0;
    row_size = c.nrows();
    col_size = c.ncols();
    vector<bool> cover_r(row_size), cover_c(col_size);
    Matrix<int> cover_matrix(row_size, col_size,0);
    Matrix <int> old_matrix(2*row_size, 2,0);
    bool done = false;
    while(!done)
    {
        switch(step)
        {
            case 1:
                step1(step, c, row_size, col_size);
                break;
            case 2:
                step2(step, c, row_size, col_size, cover_r, cover_c, cover_matrix);
                break;
            case 3:
                step3(step, row_size, col_size, cover_c, cover_matrix);
                break;
            case 4:
                step4(step, c, cover_matrix, cover_r, cover_c, row_size, col_size, r_num, c_num);
                break;
            case 5:
                step5(step, old_matrix, cover_matrix, cover_r, cover_c, r_num, c_num, row_size, col_size);
                break;
            case 6:
                step6(step, c, cover_r, cover_c, row_size, col_size);
                break;
            case 7:
                done = true;
                break;
            default:
                break;
        }
    }

    return cover_matrix;
}