#include "dataframe.hpp"
#include "utils.hpp"
#include "col_type.hpp"


using namespace std;
template <typename T>
Dataframe<T>::Dataframe();
size_t Dataframe::nrows() const
{

    std::list<std::vector<ColType>> data2 = data;
    list<vector<ColType>>::iterator ptr = data2.begin();

    vector<ColType> v2 = *ptr;
    return v2.size();
}

size_t Dataframe::ncols() const
{
    return data.size();
}

template <typename T>
Dataframe<T>::add_column(const std::vector<T>& col_values) {
    vector<T> v;
    for (int i = 0; i < col_values.size(); i++) {
        v.push_back(col_values[i]);
    }
    data.push_back(v);
}

Dataframe<T>::remove_column(const size_t i) {
    typename list<vector<T>>::iterator it = data.begin();
    advance(ptr, i);
    data.erase(ptr);
}
Dataframe<T>::remove_column(const std::string& c) {
    auto ptr = find(colnames.begin(), colnames.end(), c);
    if (ptr != colnames.end()) {
        int i = distance(colnames.begin(), ptr);
        typename list<vector<T>>::iterator ptr2 = data.begin();
        advance(ptr2, i);
        data.erase(ptr2);
    }
}



bool Dataframe::has_rownames() const
{
    if(rownames.empty())
        return false;
    
    else
     return true;
    
}

bool Dataframe::has_colnames() const
{
    if(colnames.empty())
        return false;
    
    else
        return true;
    
}

void Dataframe::set_colnames(const std::vector<std::string>& cnames) {
    colnames.clear();  // Clearing existing colnames before setting new ones

    for (const auto &cname: cnames) {
        colnames.push_back(cname);
    }
}

void Dataframe::set_rownames(const std::vector<std::string>& rnames)
{
    rownames = rnames;  // Using the assignment operator to replace the entire vector
}




void Dataframe::clear_rownames()
{
    rownames.clear();
}

void Dataframe::clear_colnames()
{
    colnames.clear();
}

void Dataframe::swap_columns(const size_t i, const size_t j)
{
    if (i >= data.size() || j >= data.size() || i == j) {
        // Invalid indices or no need to swap
        return;
    }

    auto it_i = std::next(data.begin(), i);
    auto it_j = std::next(data.begin(), j);

    std::iter_swap(it_i, it_j);
}


void Dataframe::swap_columns(const std::string& i, const std::string& j)
{

}