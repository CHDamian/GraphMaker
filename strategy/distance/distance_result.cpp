#include "distance_result.h"


void distance_result::add(int id)
{
    distance_calc[id] = INFINITY_DISTANCE;
}

void distance_result::add(int id, int dist)
{
    distance_calc[id] = dist;
}

bool distance_result::exists(int id) const
{
    return distance_calc.find(id) == distance_calc.end();
}

int distance_result::get(int id)
{
    return distance_calc[id];
}
void distance_result::del(int id)
{
    distance_calc.erase(id);
}

distance_result::distance_iterator distance_result::begin() const
{
    return distance_calc.cbegin();
}

distance_result::distance_iterator distance_result::end() const
{
    return distance_calc.cend();
}

distance_result::distance_iterator distance_result::find(int id) const
{
    return distance_calc.find(id);
}
