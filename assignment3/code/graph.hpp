#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <stdexcept>
#include <vector>
using namespace std;

// an unweighted directed Graph whose vertex properties (e.g. int, Color,
// std::pair<int, Color>, etc.) can be passed as template parameter
// for simplicity vertices can only be added, but not removed
template <typename VertexProp>
class Graph {
public:

    class dfs_iterator;
    class const_dfs_iterator;
    class dfsu_iterator;
    class const_dfsu_iterator;

    // builds an empty graph
    Graph() = default;

    // builds a graph with num_vertices unconnected vertices
    explicit Graph(std::size_t num_vertices) : adj_mat_(num_vertices, std::vector<bool>(num_vertices, false)),vertex_props_(num_vertices)
    {
        adj_mat_.resize(num_vertices);
        vertex_props_.resize(num_vertices);

    }


    //resize the adj_mat_ and vertex_props_ vectors
    /* for (size_t i = 0; i< num_vertices; i++ )
     {
     for (size_t j = 0; j< num_vertices; j++ )
     {
     adj_mat_[i][j] = false;
     }
     }*/







    // adds a vertex and returns its index
    std::size_t add_vertex(VertexProp &&prop);

    // creates an edge between two vertices and returns true if the creation was
    // successful and false for an unsuccessful edge insertion
    bool add_edge(const size_t v_idx1, const size_t v_idx2);

    // removes an edge between two vertices and returns if the removal was
    // successful
    bool remove_edge(const std::size_t v_idx1, const std::size_t v_idx2);



    // returns if there is an edge between v_idx1 and v_idx2
    bool has_edge(const std::size_t v_idx1, const std::size_t v_idx2) const;

    // returns if a directed path exists between two nodes
    // in case of v_idx1==v_idx2 return true iff v_idx is part of a directed cycle
    bool path_exists(const std::size_t v_idx, const std::size_t v_idx2) const
    {}

    // returns the properties for a given vertex index
    VertexProp& get_vertex(const std::size_t v_idx);
    const VertexProp &get_vertex(const std::size_t v_idx) const;




    // returns the number of vertices
    std::size_t num_vertices() const;

    // returns the number of edges
    std::size_t num_edges() const;



    std::list<std::size_t> get_neighbors(const std::size_t v_idx) const;

    // returns the neighbors of a vertex ignoring edge directions
    std::list<std::size_t> get_undirected_neighbors(
            const std::size_t v_idx) const;



    dfs_iterator dfs_begin(std::size_t vertex_idx)
    {
        return dfs_iterator(this, vertex_idx);
    }

    dfs_iterator dfs_end(std::size_t vertex_idx)
    {
        return dfs_iterator(this, adj_mat_.size()); // Represents the end of traversal
    }

    const_dfs_iterator dfs_begin(std::size_t vertex_idx) const;

    const_dfs_iterator dfs_end(std::size_t vertex_idx) const;

    dfsu_iterator dfsu_begin(std::size_t vertex_idx);

    dfsu_iterator dfsu_end(std::size_t vertex_idx);

    const_dfsu_iterator dfsu_begin(
            std::size_t vertex_idx) const;

    const_dfsu_iterator dfsu_end(
            std::size_t vertex_idx) const;

private:
    // stores the neighbors of each vertex
    std::vector<std::vector<bool>> adj_mat_;
    // stores the vertex properties
    std::vector<VertexProp> vertex_props_;
};

template<typename VertexProp>
std::list<std::size_t> Graph<VertexProp>::get_neighbors(const std::size_t v_idx) const {
    list<size_t> neighbors;

    // Iterate through the row corresponding to v_idx in the adjacency matrix
    for (size_t col = 0; col < adj_mat_[v_idx].size(); ++col) {
        if (adj_mat_[v_idx][col]) {
            neighbors.push_back(col); // If there's an edge, add the index to the neighbors list
        }
    }

    return neighbors;
}

template<typename VertexProp>
std::size_t Graph<VertexProp>::num_edges() const {
    size_t no_edges = 0;  // Initialize the edge count
    for (const auto& row : adj_mat_) {
        // Count the number of 'true' values in each row
        no_edges += count(row.begin(), row.end(), true);
    }
    return no_edges;
}

template<typename VertexProp>
std::size_t Graph<VertexProp>::num_vertices() const {
    return adj_mat_.size();
}

template<typename VertexProp>
const VertexProp &Graph<VertexProp>::get_vertex(const std::size_t v_idx) const {
    if (v_idx >= vertex_props_.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return vertex_props_.at(v_idx);
}

template<typename VertexProp>
VertexProp &Graph<VertexProp>::get_vertex(const std::size_t v_idx) {
    if (v_idx >= vertex_props_.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return this -> vertex_props_.at(v_idx);
}

template<typename VertexProp>
bool Graph<VertexProp>::has_edge(const std::size_t v_idx1, const std::size_t v_idx2) const {
    if (v_idx1 >= adj_mat_.size() || v_idx2 >= adj_mat_.size()) {
        return false;
    }
    return adj_mat_[v_idx1][v_idx2];

}

template<typename VertexProp>
bool Graph<VertexProp>::remove_edge(const std::size_t v_idx1, const std::size_t v_idx2) {
    // Check if the indices are within the bounds of the matrix
    if (v_idx1 >= adj_mat_.size() || v_idx2 >= adj_mat_[v_idx1].size()) {
        return false;

    }
    // Check if the edge actually exists
    if (!adj_mat_[v_idx1][v_idx2]) {
        return false;
    }

    // Remove the edge by setting the corresponding matrix entry to false
    adj_mat_[v_idx1][v_idx2] = false;
    //adj_mat_[v_idx2][v_idx1] = false; // Add this for undirected graph
    return true;
}

template<typename VertexProp>
bool Graph<VertexProp>::add_edge(const size_t v_idx1, const size_t v_idx2) {
    // Check if the indices are valid and if the vertices exist in the graph

    if (v_idx1 >= vertex_props_.size() || v_idx2 >= vertex_props_.size()) {
        return false; // One or both vertices do not exist in the graph
    }
    /*if(!add_vertex(v_idx1) || !add_vertex(v_idx2))
    {
        return false;
    }*/

    // Check if the indices are within the bounds of the adjacency matrix
    if (v_idx1 >= adj_mat_.size() || v_idx2 >= adj_mat_[v_idx1].size()) {
        return false;
    }

    // Check for self-loops
    if (v_idx1 == v_idx2) {
        return false; // Self-loops are not allowed
    }

    // Check if the edge already exists
    if (adj_mat_[v_idx1][v_idx2]) {
        return false; // Edge already exists
    }

    // Add the edge
    adj_mat_[v_idx1][v_idx2] = true;


    return true;
}



template<typename VertexProp>
size_t Graph<VertexProp>::add_vertex(VertexProp &&prop) {
    size_t current_size = adj_mat_.size();

    // Add a new row for the new vertex with 'false' for all existing vertices
    adj_mat_.push_back(std::vector<bool>(current_size, false));

    // Now, add a new column to each existing row for the new vertex
    for (size_t i = 0; i < current_size; ++i) {
        adj_mat_[i].push_back(false);
    }

    // Add the vertex property
    vertex_props_.push_back(forward<VertexProp>(prop));

    // Return the index of the new vertex
    return current_size; // This is the index of the new vertex
}

/*void get_adj_mat_()
{
    return get_adj_mat_();
}*/


#endif  // GRAPH_HPP

