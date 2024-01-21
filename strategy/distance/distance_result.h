#ifndef GRAPHMAKER_DISTANCE_RESULT_H
#define GRAPHMAKER_DISTANCE_RESULT_H

#include <memory>
#include <map>

class distance_result {
    std::map<int, int> distance_calc;

    void add(int id);
    void add(int id, int dist);
    bool exists(int id) const;
    int get(int id);
    void del(int id);

public:
    const int INFINITY_DISTANCE = INT32_MAX;
    const int NEG_INFINITY_DISTANCE = INT32_MIN;

    using distance_iterator = std::map<int, int>::const_iterator;

    distance_iterator begin() const;
    distance_iterator end() const;
    distance_iterator find(int id) const;

    friend class distance;
};

using distance_result_t = std::shared_ptr<distance_result>;

#endif //GRAPHMAKER_DISTANCE_RESULT_H
