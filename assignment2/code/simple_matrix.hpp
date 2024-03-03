#ifndef SIMPLE_MATRIX_HPP
#define SIMPLE_MATRIX_HPP

#include <vector>
using namespace std;
class SimpleMatrix {

    private: vector<vector<double>> data;
    public:
        class Invalid {};
        SimpleMatrix(std::size_t nrows, std::size_t ncols);
        SimpleMatrix(std::size_t nrows, std::size_t ncols, double init);
        SimpleMatrix(std::initializer_list<std::initializer_list<double>> data);

        SimpleMatrix(const SimpleMatrix& other_mat);
        SimpleMatrix(SimpleMatrix&& other_mat);

        SimpleMatrix& operator=(const SimpleMatrix& other_mat);
        SimpleMatrix& operator=(SimpleMatrix&& other_mat) ;

        std::size_t nrows() const;
        std::size_t ncols() const;

        double & operator()(size_t i, size_t j);
        double operator()(std::size_t i, std::size_t j) const;

        void set_matrix(std::vector<std::vector<double>> data);
    private:
        std::vector<std::vector<double>> data_;
};

#endif  // SIMPLE_MATRIX_HPP
