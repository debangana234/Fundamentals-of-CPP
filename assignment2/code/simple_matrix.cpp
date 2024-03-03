#include "simple_matrix.hpp"
#include <initializer_list>
#include <vector>
#include <algorithm>

using namespace std;

//SimpleMatrix::SimpleMatrix = default;
//creating the empty matrix with the specified dimensions
SimpleMatrix::SimpleMatrix(size_t nrows, size_t ncols): data_(nrows, vector<double>(ncols))
{  // one of the invalid conditions should be if there are 0 rows and non zero columns or if there are non zero rows and zero columns
    if((nrows <= 0 && ncols >0 )||(ncols <= 0 && nrows>0))
    {
        throw Invalid();
    }
    //Initializing the matrix with the specified number of rows and columns, and each element is set to a default  0.0 since the vector is of type double.
    data_.resize(nrows, vector<double>(ncols) );
}

//Constructor for creating a matrix with specified dimensions and initialization values
SimpleMatrix::SimpleMatrix(size_t nrows, size_t ncols, double init): data_(nrows, vector<double>(ncols))
{//for this case an empty matrix would be invalid
    if (data.empty())
    {
        throw Invalid();
    }
    //Explicitly resizing each row to have ncols elements, in order to ensure that the matrix has the desired size and shape.
    data.resize(nrows);
    for( auto &ptr : data)
    {
        ptr.resize(ncols);
    }
}


SimpleMatrix::SimpleMatrix(initializer_list<initializer_list<double>> data) {
    if (data.size() == 0) {
        throw Invalid();
    }

    size_t ncols = data.begin()->size();
// invalid input if all the rows don't have the same number of columns
    for (const auto &row : data) {
        if (row.size() != ncols) {
            throw Invalid();
        }
        data_.push_back(row);
    }
}

//copy constructor
SimpleMatrix::SimpleMatrix(const SimpleMatrix& other_mat): data_(other_mat.data_) {}
//copy assignment operator
SimpleMatrix &SimpleMatrix::operator=(const SimpleMatrix &other_mat) {
    //self assignment
    if (&other_mat == this) {
        return *this;
    }
    //assign the current object to the other object
    data_ = other_mat.data_;
    return *this;
}

//MOve constructor
SimpleMatrix::SimpleMatrix(SimpleMatrix &&other_mat)
        : data_(move(other_mat.data_)) {}
 //Move assignment operator
SimpleMatrix &SimpleMatrix::operator=(SimpleMatrix &&other_mat) {
    if (this != &other_mat) {
        data_ = move(other_mat.data_); //Moving data from the other matrix object
    }
    return *this;
}

//Returning the number of rows in the matrix
size_t SimpleMatrix::nrows() const {
    return data_.size();
}

//Returning the number of columns in the matrix
size_t SimpleMatrix::ncols() const {
    return data_[0].size();
}

// Accessing and modifying elements of the matrix
double &SimpleMatrix::operator()(size_t i, size_t j) {
    //Checking for the out of bounds case
    if (i >= nrows() || j >= ncols()) {
        throw Invalid();
    }
    return data_[i][j];
}

// Accessing elements of the matrix using  (const version)
double SimpleMatrix::operator()(size_t i, size_t j) const {
    if (i >= nrows() || j >= ncols()) {
        throw Invalid();
    }
    return data_[i][j];
}

void SimpleMatrix::set_matrix(vector<vector<double>> data) {
    data_ = move(data);
}