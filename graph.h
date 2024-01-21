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
    protected:
        bool is_prototype;
        node_map nodes; /**< Wierzcholek */

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

            /** @brief Operator porownania elementow.
         * Operator sprawdzajacy czy porownywane elementy sa rowne
         * @param[in] rhs – ... .
         *  bez zadnych konfilktow.
         */
            bool operator==(node_iterator& rhs)
            {
                return this->it == rhs.it;
            }

            /** @brief Operator porownania elementow.
         * Operator sprawdzajacy czy porownywane elementy sa rozne
         * @param[in] rhs – ... .
         *  bez zadnych konfilktow.
         */
            bool operator!=(node_iterator& rhs)
            {
                return this->it != rhs.it;
            }

            /** @brief Pobierz id .
         * Pobiera id ...
         * @return Id ...
         *  bez zadnych konfilktow.
         */
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

        virtual node_iterator_t node_begin();

        virtual node_iterator_t node_end();

        virtual node_iterator_t get_node(int id);

        friend class builder;

        friend class adder_node;

        friend class adder_edge;

        friend class adder_single_edge;

        friend class graph_decorator;

    protected:


        virtual node_iterator_t add_node(int id);


        /** @brief Dodaj krawedz.
         * Dodaje krawedz ...
         * @param[in] src - ...
         * @param[in] dest - ...
         * @param[in] weight - waga krawedzi
         * @return Krawedz
         *  bez zadnych konfilktow.
         */
        virtual node_egde_pair add_edge(int src, int dest, int weight);

        /** @brief Usun krawedz.
         * Usun krawedz @param[in] edge_to_del
         * @param[in] edge_to_del – krawedz grafu do usuniecia.
         *  bez zadnych konfilktow.
         */
        virtual void del_edge(node_egde_pair edge_to_del) noexcept;

        virtual bool is_valid() const;

        virtual void set_prototype(bool prototype) noexcept;

        /** @brief Usun wierzcholek.
         * Usuwa podany wierzcholek
         * @param[in] node_to_del - usuwany wierzcholek
         *  bez zadnych konfilktow.
         */
        virtual void del_node(node_iterator_t node_to_del) noexcept;

    };




#endif //GRAPHMAKER_GRAPH_H
