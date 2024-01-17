#ifndef GRAPHMAKER_NODE_H
#define GRAPHMAKER_NODE_H


#include <map>
#include <memory>

    using edge_map = std::map<int, int>;

    class node;

    using node_t = std::shared_ptr<node>;

    class multiple_edges_adding_exception : public std::exception {
    public:
        [[nodiscard]] const char *what() const noexcept override {
            return "Edge already exists";
        }
    };

    class node {
    private:

        int id;
        edge_map edges;


        node(int id) : id(id) {}

    public:

        class edge_iterator {
        private:
            std::map<int, int>::iterator it;

            edge_iterator(std::map<int, int>::iterator it) : it(it) {}

        public:
            edge_iterator() = delete;

            void operator++() {
                it++;
            }

            void operator--() {
                it--;
            }

            int get_node_id() const {
                return it->first;
            }

            int get_weight() const {
                return it->second;
            }

            friend class node;
        };

        using edge_iterator_t = std::shared_ptr<edge_iterator>;

        node() = delete;

        int get_id() const;

        edge_iterator_t edge_begin();

        edge_iterator_t edge_end();

        friend class graph;

    private:
        edge_iterator_t add_edge(int id, int weight);

        void del_edge(edge_iterator_t edge_to_del) noexcept;

    };


#endif //GRAPHMAKER_NODE_H
