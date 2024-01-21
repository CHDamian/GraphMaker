/** @file
 * Deklaracja modulu wierzcholka
 *
 * @author Damian Chanko, Maciej Chanko, Pawel Krol
 * @date 21.01.2024
 */


#ifndef GRAPHMAKER_NODE_H
#define GRAPHMAKER_NODE_H


#include <map>
#include <memory>

    using edge_map = std::map<int, int>;

    class node;

    using node_t = std::shared_ptr<node>;

    /**< Wyjatek wyrzucany przy probie stworzenia krawedzi, ktora juz istnieje */
    class multiple_edges_adding_exception : public std::exception {
    public:
        [[nodiscard]] const char *what() const noexcept override {
            return "Edge already exists";
        }
    };

    class node {
    private:

        int id; /**< Id wierzcholka */
        edge_map edges; /**< Krawedz grafu */


        node(int id) : id(id) {}

    public:

        /**< Iterator krawedzi */
        class edge_iterator {
        private:
            std::map<int, int>::iterator it;

            edge_iterator(std::map<int, int>::iterator it) : it(it) {}

        public:
            edge_iterator() = delete;

            /**
         * @brief Operator inkrementacji.
         * Inkrementuje iterator krawędzi.
         */
            void operator++() {
                it++;
            }

            /**
         * @brief Operator dekrementacji.
         * Dekrementuje iterator krawędzi.
         */
            void operator--() {
                it--;
            }

                /**
            * @brief Operator porównania.
            * Porównuje czy obecny iterator krawędzi jest równy podanemu iteratorowi.
            * @param[in] rhs – Iterator krawędzi do porównania.
            * @return True, jeśli iteratory są równe; false w przeciwnym razie.
            */
            bool operator==(edge_iterator& rhs)
            {
                return this->it == rhs.it;
            }

                /**
            * @brief Operator nierówności.
            * Sprawdza, czy obecny iterator krawędzi jest różny od podanego iteratora.
            * @param[in] rhs – Iterator krawędzi do porównania.
            * @return True, jeśli iteratory są różne; false w przeciwnym razie.
            */
            bool operator!=(edge_iterator& rhs)
            {
                return this->it != rhs.it;
            }


            /** @brief Pobierz id wierzcholka.
         * Pobiera id wierzcholka
         * @return Id wierzcholka
         *  bez zadnych konfilktow.
         */
            int get_node_id() const {
                return it->first;
            }


            /** @brief Pobierz wage krawedzi.
         * Pobiera wage krawedzi
         * @return Waga krawedzi
         *  bez zadnych konfilktow.
         */
            int get_weight() const {
                return it->second;
            }

            friend class node;
        };

        using edge_iterator_t = std::shared_ptr<edge_iterator>;

        node() = delete;

        int get_id() const;

        /** @brief Operator porownania elementow.
             * Operator sprawdzajacy czy porownywane elementy sa rowne
             * @param[in] rhs – ... .
             *  bez zadnych konfilktow.
             */
        edge_iterator_t edge_begin();

        /** @brief Operator porownania elementow.
             * Operator sprawdzajacy czy porownywane elementy sa rowne
             * @param[in] rhs – ... .
             *  bez zadnych konfilktow.
             */
        edge_iterator_t edge_end();

        friend class graph;

    private:

        /** @brief Dodaj krawedz.
         * Dodaj krawedz polaczona do wierzcholka o id rownym @param[in] id
         * oraz wadze @param[in] weight.
         * @param[in] id   – id wierzcholka, do ktorego,
         *                   polaczona zostanie nowa krawedz,
         * @param[in] weight – waga krawedzi.
         * @return Iterator do krawedzi, jezeli krawedz powstala
         *  bez zadnych konfilktow.
         */
        edge_iterator_t add_edge(int id, int weight);


        /** @brief Usun krawedz.
         * Usun krawedz @param[in] edge_to_del
         * @param[in] edge_to_del – krawedz grafu do usuniecia.
         *  bez zadnych konfilktow.
         */
        void del_edge(edge_iterator_t edge_to_del) noexcept;

    };


#endif //GRAPHMAKER_NODE_H
