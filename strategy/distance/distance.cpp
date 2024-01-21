#include "distance.h"

void distance::add_dist(distance_result_t result_proxy, int id)
{
    result_proxy->add(id);
}

void distance::add_dist(distance_result_t result_proxy, int id, int dist)
{
    result_proxy->add(id, dist);
}

bool distance::exists_dist(distance_result_t result_proxy, int id) const
{
    return result_proxy->exists(id);
}

int distance::get_dist(distance_result_t result_proxy, int id)
{
    return result_proxy->exists(id);
}

void distance::del_dist(distance_result_t result_proxy, int id)
{
    result_proxy->del(id);
}

