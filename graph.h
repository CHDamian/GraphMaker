//
// Created by damia on 15.01.2024.
//

#ifndef GRAPHMAKER_GRAPH_H
#define GRAPHMAKER_GRAPH_H


#include <map>
#include "node.h"

    using node_map = std::map<int, node_t>;

    /**< Wyjatek dodania tego samego wierzcholka */
    class multiple_nodes_adding_exception : public std::exception {
    public:
        [[nodiscard]] const char *what() const noexcept override {
            return "Node already exists";
        }
    };

    class graph {
    protected:
        bool is_prototype; /**< Czy graf jest w trakcie budowy */
        node_map nodes; /**< Wierzcholek */

        graph() : is_prototype(true) {}

    public:
        /**< Iterator do listy wierzcholkow */
        class node_iterator {
        private:
            node_map::iterator it; /**< Iterator wewnetrzny */

            node_iterator(node_map::iterator it) : it(it) {}

        public:
            node_iterator() = delete;

            /**
             * @brief Operator inkrementacji.
             * Inkrementuje iterator wierzcholkow.
             */
            void operator++() {
                it++;
            }

            /**
             * @brief Operator dekrementacji.
             * Dekrementuje iterator wierzcholkow.
             */
            void operator--() {
                it--;
            }

            /**
            * @brief Operator porównania.
            * Porównuje czy obecny iterator wierzcholka jest równy podanemu iteratorowi.
            * @param[in] rhs – Iterator wierzcholka do porównania.
            * @return True, jeśli iteratory są równe; false w przeciwnym razie.
            */
            bool operator==(node_iterator& rhs)
            {
                return this->it == rhs.it;
            }

            /**
            * @brief Operator nierówności.
            * Sprawdza, czy obecny iterator wierzcholka jest różny od podanego iteratora.
            * @param[in] rhs – Iterator wierzcholka do porównania.
            * @return True, jeśli iteratory są różne; false w przeciwnym razie.
            */
            bool operator!=(node_iterator& rhs)
            {
                return this->it != rhs.it;
            }

            /** @brief Pobierz id wierzcholka.
             * Pobiera id wierzcholka
             * @return Id wierzcholka
             */
            int get_id() {
                return it->first;
            }

            /** @brief Poczatek listy krawedzi.
             * Zwraca iterator na poczatek listy krawedzi
             * @return Iterator na poczatek listy.
             */
            node::edge_iterator_t edge_begin() {
                return it->second->edge_begin();
            }

            /** @brief Koniec listy krawedzi.
             * Zwraca iterator na koniec listy krawedzi
             * @return Iterator na koniec listy.
             */
            node::edge_iterator_t edge_end() {
                return it->second->edge_end();
            }

            friend class graph;
        };

        using node_iterator_t = std::shared_ptr<node_iterator>;
        using node_egde_pair = std::pair<node_iterator_t, node::edge_iterator_t>;

        /** @brief Poczatek listy wierzcholkow.
         * Zwraca iterator na poczatek listy wierzcholkow.
         * @return Iterator na poczatek listy.
         */
        virtual node_iterator_t node_begin();

        /** @brief Koniec listy wierzcholkow.
         * Zwraca iterator na koniec listy wierzcholkow.
         * @return Iterator na koniec listy.
         */
        virtual node_iterator_t node_end();

        /** @brief Dodaj krawedz.
         * Znajdz wierzcholek o id rownym @param[in] id
         * @param[in] id   – id wierzcholka
         * @return Iterator do wierzcholka, jezeli istnieje
         *  lub koniec listy.
         */
        virtual node_iterator_t get_node(int id);

        friend class builder;

        friend class adder_node;

        friend class adder_edge;

        friend class adder_single_edge;

        friend class graph_decorator;

    protected:


        virtual node_iterator_t add_node(int id);


        /** @brief Dodaj krawedz.
         * Dodaje krawedz do grafu.
         * @param[in] src - wierzcholek wychodzacy
         * @param[in] dest - wierzcholek wchodzacy
         * @param[in] weight - waga krawedzi
         * @return Para iteratorow do wierzcholka wychodzacego i krawedzi.
         */
        virtual node_egde_pair add_edge(int src, int dest, int weight);

        /** @brief Usun krawedz.
         * Usun krawedz @param[in] edge_to_del
         * @param[in] edge_to_del – krawedz grafu do usuniecia z wierzcholkiem.
         */
        virtual void del_edge(node_egde_pair edge_to_del) noexcept;

        /** @brief Czy graf jest ok.
         * Sprawdza, czy warunki nalozone na graf sa spelnikne.
         * @return True jezeli sa spelnione, lub false w przeciwnym wypadku.
         */
        virtual bool is_valid() const;

        virtual void set_prototype(bool prototype) noexcept;

        /** @brief Usun wierzcholek.
         * Usuwa podany wierzcholek
         * @param[in] node_to_del - usuwany wierzcholek
         */
        virtual void del_node(node_iterator_t node_to_del) noexcept;

    };




#endif //GRAPHMAKER_GRAPH_H
