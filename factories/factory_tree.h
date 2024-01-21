//
// Created by macie on 1/20/2024.
//

#ifndef GRAPHMAKER_FACTORY_TREE_H
#define GRAPHMAKER_FACTORY_TREE_H


#include "factory.h"
#include <set>

class factory_tree : public factory
{
protected:

    factory_tree() = default;

private:

    void dfs_check_edges(std::shared_ptr<graph> graph_ptr, std::map<std::pair<int, int>, std::pair<int, bool>> &edge_checker,
                         std::set<int> &visited, graph::node_iterator_t nod, graph::node_iterator_t parent);

public:

    /** @brief Operator porownania elementow.
             * Operator sprawdzajacy czy porownywane elementy sa rowne
             * @param[in] rhs – ... .
             *  bez zadnych konfilktow.
             */
    static factory& get_instance()
    {
        static factory_tree* instance = new factory_tree();
        return *instance;
    }

    virtual std::shared_ptr<graph> create(std::shared_ptr<graph> graph_ptr);

};

#endif //GRAPHMAKER_FACTORY_TREE_H
