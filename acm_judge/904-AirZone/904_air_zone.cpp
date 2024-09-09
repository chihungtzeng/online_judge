#include <algorithm>
#include <iostream>
#include <sstream>
#include <assert.h>
#include <vector>
#include <unordered_map>

typedef long long cord_type;
#define LOGGING 0

class Line {
public:
    cord_type m_x[2];
    Line(cord_type x1, cord_type x2)
    {
        m_x[0] = x1;
        m_x[1] = x2;
    }
    bool is_intersect(const Line& other) const
    {
        if ((m_x[0] > other.m_x[1]) || (m_x[1] < other.m_x[0])) {
            return false;
        } else {
            return true;
        }
    }
    bool contains(const Line& other) const
    {
        if ((m_x[0] <= other.m_x[0]) && (m_x[1] >= other.m_x[1]))
            return true;
        else
            return false;
    }
    bool operator==(const Line& other) const
    {
        return (m_x[0] == other.m_x[0]) && (m_x[1] == other.m_x[1]);
    }
    bool operator!=(const Line& other) const
    {
        return !(*this == other);
    }
    bool operator<(const Line& other) const
    {
        if (*this == other)
            return false;
        else if (m_x[0] != other.m_x[0])
            return m_x[0] < other.m_x[0];
        else
            return m_x[1] < other.m_x[1];
    }
    bool operator>(const Line& other) const
    {
        if (*this == other)
            return false;
        else if (m_x[0] != other.m_x[0])
            return m_x[0] > other.m_x[0];
        else
            return m_x[1] > other.m_x[1];
    }
    cord_type intersect_length(const Line& other) const
    {
        auto overlap = intersect_line(other);
        return overlap.m_x[1] - overlap.m_x[0];
    }
    cord_type length() const
    {
        return m_x[1] - m_x[0];
    }
    Line intersect_line(const Line& other) const
    {
        if (!is_intersect(other))
            return Line(0, 0);
        else
            return Line(std::max(m_x[0], other.m_x[0]),
                std::min(m_x[1], other.m_x[1]));
    }
};

class Cube {
public:
    Line xline, yline, zline;

public:
    Cube()
        : xline(0, 0)
        , yline(0, 0)
        , zline(0, 0)
    {
    }
    Cube(cord_type _x1, cord_type _y1,
        cord_type _z1, cord_type _x2,
        cord_type _y2, cord_type _z2)
        : xline(_x1, _x2)
        , yline(_y1, _y2)
        , zline(_z1, _z2)
    {
    }
    std::string to_string() const
    {
        std::ostringstream result;
        result << "("
               << xline.m_x[0] << ", " << yline.m_x[0] << ", "
               << zline.m_x[0] << "), ("
               << xline.m_x[1] << ", " << yline.m_x[1] << ", "
               << zline.m_x[1] << ")";
        return std::string(result.str());
    }
    bool is_intersect(const Cube& other) const
    {
        if (xline.is_intersect(other.xline)
            && yline.is_intersect(other.yline)
            && zline.is_intersect(other.zline))
            return true;
        else
            return false;
    }
    bool contains(const Cube& other) const
    {
        return xline.contains(other.xline) && yline.contains(other.yline) && zline.contains(other.zline);
    }
    bool operator==(const Cube& other) const
    {
        return (xline == other.xline)
            && (yline == other.yline)
            && (zline == other.zline);
    }
    bool operator!=(const Cube& other) const
    {
        return !(*this == other);
    }
    bool operator<(const Cube& other) const
    {
        if (*this == other)
            return false;
        else if (xline != other.xline)
            return xline < other.xline;
        else if (yline != other.yline)
            return yline < other.yline;
        else
            return zline < other.zline;
    }
    cord_type volume() const
    {
        return xline.length() * yline.length() * zline.length();
    }
    cord_type intersect_volume(const Cube& other) const
    {
        if (!is_intersect(other))
            return 0;
        else {
            return xline.intersect_length(other.xline)
                * yline.intersect_length(other.yline)
                * zline.intersect_length(other.zline);
        }
    }
    Cube intersect_cube(const Cube& other) const
    {
        if (!is_intersect(other))
            return Cube(0, 0, 0, 0, 0, 0);
        else {
            auto x = xline.intersect_line(other.xline);
            auto y = yline.intersect_line(other.yline);
            auto z = zline.intersect_line(other.zline);
            return Cube(x.m_x[0], y.m_x[0], z.m_x[0],
                x.m_x[1], y.m_x[1], z.m_x[1]);
        }
    }
};

void get_pairwise_intersection(std::vector<Cube>& cubes)
{
    std::vector<Cube> result;
    auto num_cube = cubes.size();
    auto max_num_intersection = (num_cube * (num_cube - 1)) >> 1;
    result.reserve(max_num_intersection);

#if LOGGING
    std::cout << "before cubes: ";
    for (const auto &c: cubes) {
        std::cout << c.to_string() << " ";
    }
    std::cout << "\n";
#endif

    for (auto c1 = cubes.begin(); c1 != cubes.end(); c1++) {
        for(auto c2 = c1 + 1; c2 != cubes.end(); c2++) {
            if ((*c1).is_intersect(*c2)) {
                auto intersection = (*c1).intersect_cube(*c2);
                    result.push_back(intersection);
            }
        }
    }
    result.swap(cubes);
    std::sort(cubes.begin(), cubes.end());
#if LOGGING
    std::cout << "after cubes: ";
    for (const auto &c: cubes) {
        std::cout << c.to_string() << " ";
    }
    std::cout << "\n";
#endif
}

void remove_redundant_cubes(std::vector<Cube>& cubes)
{
    std::vector<Cube> result;
    result.reserve(cubes.size());

    for (const auto& c1 : cubes) {
        bool contained = false;
        for (const auto& c2 : cubes) {
            if (c2.contains(c1) && (c1 != c2)) {
                contained = true;
                break;
            }
        }
        if (!contained) {
            if (std::find(result.begin(), result.end(), c1) == result.end()) {
                result.push_back(c1);
            }
        }
    }
    result.swap(cubes);
#if LOGGING
    std::cout << "pruned cubes: ";
    for (const auto &c: cubes) {
        std::cout << c.to_string() << " ";
    }
    std::cout << "\n";
#endif
}

cord_type added_volume(cord_type volume, bool positive)
{
    cord_type result = positive ? volume : -volume;
#if LOGGING
    std::cout << "added volume: " << result << "\n";
#endif
    return result;
}

cord_type calc_overlap_volume_recursive(
    std::vector<Cube>::iterator begin,
    std::vector<Cube>::iterator end
    )
{
    if (begin == end)
        return 0;
    if (begin + 1 == end)
        return (*begin).volume();

    /* A \cup B \cup C = A \cup (B \cup C)
        = A + (B \cup C) - ((A \cap B) \cup (A \cap C))
    */
    cord_type this_volume = (*begin).volume();
    cord_type other_volumes = calc_overlap_volume_recursive(begin + 1, end);
    std::vector<Cube> intersections;
    intersections.reserve(end - begin + 1);
    for (auto c = begin + 1; c != end; c++) {
        if ((*c).is_intersect(*begin)) {
            auto intersection_with_begin = (*c).intersect_cube(*begin);
            intersections.push_back(intersection_with_begin);
        }
    }
    return this_volume + other_volumes
        - calc_overlap_volume_recursive(
            intersections.begin(), intersections.end());
}

cord_type calc_overlap_volume(std::vector<Cube>& cubes)
{
    // Get a set of overlap cubes.
    // The volume of their union is the answer.
    get_pairwise_intersection(cubes);

    // If cube A is contained by cube B, then A can be omitted because
    // we are interested in only the union.
    remove_redundant_cubes(cubes);
    return calc_overlap_volume_recursive(cubes.begin(), cubes.end());
}

int main(int argc, char *argv[])
{
    int nCube = 0;
    cord_type x1, y1, z1, x2, y2, z2;
    FILE *fp = NULL;
#ifdef ONLINE_JUDGE
    fp = stdin;
#else
    fp = fopen("in6.txt", "r");
    assert(NULL != fp);
#endif

    while (1 == fscanf(fp, "%d", &nCube)) {
        std::vector<Cube> cubes;
        cubes.reserve(nCube);
        for (int i = 0; i < nCube; i++) {
            fscanf(fp, "%lld %lld %lld %lld %lld %lld",
                &x1, &y1, &z1, &x2, &y2, &z2);
            cubes.push_back(Cube(x1, y1, z1, x2, y2, z2));
        }
        std::cout << calc_overlap_volume(cubes) << "\n";
    }

#ifndef ONLINE_JUDGE
    fclose(fp);
#endif
    return 0;
}
