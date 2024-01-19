//
// Created by damia on 15.01.2024.
//

#ifndef GRAPHMAKER_GRAPH_H
#define GRAPHMAKER_GRAPH_H


#include <map>
#include "node.h"

    using node_map = std::map<int, node_t>;

    class multiple_nodes_adding_exception : public std::exception {
    public:
        [[nodiscard]] const char *what() const noexcept override {
            return "Node already exists";
        }
    };

    class graph {
    private:
        bool is_prototype;
        node_map nodes;

        graph() : is_prototype(true) {}

    public:
        class node_iterator {
        private:
            node_map::iterator it;

            node_iterator(node_map::iterator it) : it(it) {}

        public:
            node_iterator() = delete;

            void operator++() {
                it++;
            }

            void operator--() {
                it--;
            }

            int get_id() {
                return it->first;
            }

            node::edge_iterator_t edge_begin() {
                return it->second->edge_begin();
            }

            node::edge_iterator_t edge_end() {
                return it->second->edge_end();
            }

            friend class graph;
        };

        using node_iterator_t = std::shared_ptr<node_iterator>;
        using node_egde_pair = std::pair<node_iterator_t, node::edge_iterator_t>;

        node_iterator_t node_begin();

        node_iterator_t node_end();

        node_iterator_t get_node(int id);

        friend class builder;

        friend class adder_node;

        friend class adder_edge;

        friend class adder_single_edge;

    protected:

        virtual node_iterator_t add_node(int id);

        virtual node_egde_pair add_edge(int src, int dest, int weight);

        virtual void del_edge(node_egde_pair edge_to_del) noexcept;

        virtual bool is_valid() const;

        void set_prototype(bool prototype) noexcept;

        virtual void del_node(node_iterator_t node_to_del) noexcept;

    };




#endif //GRAPHMAKER_GRAPH_H
