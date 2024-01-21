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


//#define DIJKSTRA_TEST
//#define TEST_DAMIANA
//#define TREE_TEST
//#define POSITIVE_TEST
#define CONNECTED_TEST

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

#ifdef TREE_TEST
    auto fac = graph_facade();
    auto bul = fac.make_graph();

    bul->add_node(1);
    bul->add_node(2);
    bul->add_node(3);
    bul->add_edge(1,2,12);
    bul->add_single_edge(2,3,23);
    bul->add_edge(3,2,13);
    try{
        bul->make_tree();
    }catch (exception e)
    {
        cout<<"Zlapano: "<<e.what()<<endl;
    }
    bul->undo();
    bul->make_tree();

    graph_t gr = NULL;
    try{
        gr = bul->build();
    }catch (exception e)
    {
        cout<<"Zlapano: "<<e.what()<<endl;
    }
    bul->add_single_edge(3,2,23);

    gr = bul->build();

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

#ifdef CONNECTED_TEST
    auto fac = graph_facade();
    auto bul = fac.make_graph();

    bul->add_node(1);
    bul->add_node(2);
    bul->add_node(3);
    bul->add_node(4);
    bul->add_edge(1,2,12);
    bul->add_single_edge(2,3,23);

    graph_t gr = NULL;
    bul->make_connected();

    try{
        gr = bul->build();
    }catch (exception e)
    {
        cout<<"Zlapano: "<<e.what()<<endl;
    }
    bul->add_edge(3,4,34);
    try{
        gr = bul->build();
    }catch (exception e)
    {
        cout<<"Zlapano: "<<e.what()<<endl;
    }
    bul->add_single_edge(4,1,41);

    gr = bul->build();

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
    fac.set_traversing(std::make_shared<dfs>(dfs::get_instance()));

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
    fac.set_traversing(std::make_shared<bfs>(bfs::get_instance()));

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


#ifdef BELLMAN_FORD_TEST

    distance_result_t result = bellman_ford::get_instance().execute(gr, 1);


    for(auto it = result->begin(); it != result->end(); it++)
    {
        cout<<"Node: "<<it->first<<" | Edge: "<<it->second<<endl;
    }

#endif

#ifdef DIJKSTRA_TEST

    distance_result_t result = dijkstra::get_instance().execute(gr, 1);

    for(auto it = result->begin(); it != result->end(); it++)
    {
        cout<<"Node: "<<it->first<<" | Edge: "<<it->second<<endl;
    }

#endif

#ifdef POSITIVE_TEST
    auto bul = facade::make();

    bul->add_node(1);
    bul->add_node(2);
    bul->add_node(3);
    bul->add_edge(1,2,12);
    bul->add_single_edge(2,3,23);
    bul->add_edge(1,3,-69);

    try {
        bul->make_positive();
    } catch (graph_not_positive_exception e) {
        cout << "Graf nie jest dodatni! 1" << endl;
    }

    bul->undo();

    try {
        bul->make_positive();
    } catch (graph_not_positive_exception e) {
        cout << "Graf nie jest dodatni! 2" << endl;
    }

    try {
        bul->add_edge(1,3, -20);
    } catch (exception e) {
        cout << "Nie można dodać ujemnej krawedzi!" << endl;
    }

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
}
