#include <iostream>
#include "graph_maker.h"

using namespace std;

#define MOCKUP_FACADE

#ifdef MOCKUP_FACADE

class facade
{
public:
    static std::shared_ptr<builder> make()
    {
        return std::shared_ptr<builder>(new builder());
    }
};

#endif

#include "graph_facade.h"
#include "strategy/traversing/dfs.h"
#include "strategy/traversing/bfs.h"

#define BFS_TEST

int main() {

#ifdef TEST_DAMIANA

    auto bul = facade::make();

    bul->add_node(1);
    bul->add_node(2);
    bul->add_node(3);
    bul->add_edge(1,2,12);
    bul->add_single_edge(2,3,23);
    bul->add_edge(1,3,13);
    bul->undo();
    auto gr = bul->build();

    for(auto node_it = gr->node_begin(); *node_it != *(gr->node_end()); ++(*node_it))
    {
        cout<<"Node: "<<node_it->get_id()<<endl;
        cout<<"Edges:";
        for(auto edge_it = node_it->edge_begin(); *edge_it != *(node_it->edge_end()); ++(*edge_it))
        {
            cout<<" "<<edge_it->get_node_id()<<"("<<edge_it->get_weight()<<")";
        }
        cout<<endl<<endl;
    }

#endif

#ifdef DFS_TEST
    auto bul = facade::make();

    bul->add_node(1);
    bul->add_node(2);
    bul->add_node(3);
    bul->add_edge(1,2,12);
    bul->add_single_edge(2,3,23);
    bul->add_edge(1,3,13);
    bul->undo();
    auto gr = bul->build();

    auto fac = graph_facade();
    fac.set_traversing(std::make_shared<dfs>());

    auto gr_result = fac.execute_traversing(gr, 2);

    for(auto node_it = gr_result->node_begin(); *node_it != *(gr_result->node_end()); ++(*node_it))
    {
        cout<<"Node: "<<node_it->get_id()<<endl;
        cout<<"Edges:";
        for(auto edge_it = node_it->edge_begin(); *edge_it != *(node_it->edge_end()); ++(*edge_it))
        {
            cout<<" "<<edge_it->get_node_id()<<"("<<edge_it->get_weight()<<")";
        }
        cout<<endl<<endl;
    }
#endif

#ifdef BFS_TEST
    auto bul = facade::make();

    bul->add_node(1);
    bul->add_node(2);
    bul->add_node(3);
    bul->add_edge(1,2,12);
    bul->add_single_edge(2,3,23);
    bul->add_edge(1,3,13);
    bul->undo();
    auto gr = bul->build();

    auto fac = graph_facade();
    fac.set_traversing(std::make_shared<bfs>());

    auto gr_result = fac.execute_traversing(gr, 2);

    for(auto node_it = gr_result->node_begin(); *node_it != *(gr_result->node_end()); ++(*node_it))
    {
        cout<<"Node: "<<node_it->get_id()<<endl;
        cout<<"Edges:";
        for(auto edge_it = node_it->edge_begin(); *edge_it != *(node_it->edge_end()); ++(*edge_it))
        {
            cout<<" "<<edge_it->get_node_id()<<"("<<edge_it->get_weight()<<")";
        }
        cout<<endl<<endl;
    }
#endif
}
