#include <iostream>
#include <vector>
#include <type_traits>
#include <fstream>
#include <memory>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG_LOG 1
#endif

typedef int pos_t;
constexpr pos_t MAX_COORDINATION = 51;

enum class action { forward, left, right };
enum class orientation { north, south, east, west};

char orientation_to_char(orientation o){
    char result = 'N';
    switch (o) {
        case orientation::north:
            result = 'N';
            break;
        case orientation::west:
            result = 'W';
            break;
        case orientation::east:
            result = 'E';
            break;
        case orientation::south:
            result = 'S';
            break;
        default:
            break;
   }
   return result;
}

struct Pos {
    pos_t m_x, m_y;
    Pos(pos_t x, pos_t y): m_x(x), m_y(y) {}
};

struct Trap {
    pos_t m_x, m_y;
    orientation m_orientation;
    Trap(pos_t x = 0, pos_t y = 0, orientation o = orientation::north): 
        m_x(x), m_y(y), m_orientation(o) {}
    bool operator==(Trap &rhs){
        //if ((m_x == rhs.m_x) && (m_y == rhs.m_y) && (m_orientation == rhs.m_orientation)){
        if ((m_x == rhs.m_x) && (m_y == rhs.m_y)){
            return true;
        }
        else {
            return false;
        }
    }
};

class Grid {
    public:
        Grid(pos_t width = 0, pos_t height = 0): 
            m_width(width), 
            m_height(height),
            m_traps(0){
        }
        bool is_trap(pos_t x, pos_t y, orientation o){
            Trap trap(x, y, o);
            bool result = false;
            for(auto it : m_traps){
                if (it == trap) {
                    result = true;
                }
            }
            return result;
        }
        void add_trap(pos_t x, pos_t y, orientation o) {
            Trap trap(x, y, o);
            m_traps.push_back(trap);
        }
        pos_t get_width() { return m_width; }
        pos_t get_height() { return m_height; }
    private:
        pos_t m_width, m_height;
        std::vector<Trap> m_traps;
};

class Robot {
    public:
        Robot(pos_t x=0, pos_t y=0, orientation o=orientation::north): 
            m_x(x), m_y(y), m_orientation(o), m_lost(false) {}
        Pos get_position() const {
            return Pos(m_x, m_y);
        }
        void set_position(pos_t x, pos_t y) { m_x = x; m_y = y;}
        void set_orientation(orientation o) { m_orientation = o;}
        orientation get_orientation() { return m_orientation; }
        bool is_lost() {return m_lost;}
        void set_lost(bool lost = true) { m_lost = lost; }
        void turn(action act);
        void move();
        void move_back();
        void report();

    private:
        pos_t m_x, m_y;
        orientation m_orientation = orientation::north;
        bool m_lost;
};

void Robot::report(){
#ifdef DEBUG_LOG
    std::cout << "robot: " << m_x << " " << m_y << "," << orientation_to_char(m_orientation) << "\n";
#endif
}

void Robot::turn(action act){
    if (act != action::forward){
        switch (m_orientation){
            case orientation::north:
                if (act == action::left){
                    m_orientation = orientation::west;
                } 
                else {
                    m_orientation = orientation::east;
                }
                break;
            case orientation::south:
                if (act == action::left){
                    m_orientation = orientation::east;
                } 
                else {
                    m_orientation = orientation::west;
                }
                break;
            case orientation::east:
                if (act == action::left){
                    m_orientation = orientation::north;
                } 
                else {
                    m_orientation = orientation::south;
                }
                break;
            case orientation::west:
                if (act == action::left){
                    m_orientation = orientation::south;
                } 
                else {
                    m_orientation = orientation::north;
                }
                break;
            default:
                break;
        }
    }
}

void Robot::move(){
    switch (m_orientation) {
        case orientation::north:
            ++m_y;
            break;
        case orientation::south:
            --m_y;
            break;
        case orientation::east:
            ++m_x;
            break;
        case orientation::west:
            --m_x;
            break;
        default:
            break;
    }
#ifdef DEBUG_LOG
    std::cout << "move to " << m_x << " " << m_y << "\n";
#endif
}

void Robot::move_back(){
    switch (m_orientation) {
        case orientation::north:
            --m_y;
            break;
        case orientation::south:
            ++m_y;
            break;
        case orientation::east:
            --m_x;
            break;
        case orientation::west:
            ++m_x;
            break;
        default:
            break;
    }
}
class Master {
    public:
        Master(pos_t width = 0, pos_t height = 0): 
            m_grid(width, height), m_robot() {}

        void set_actions(std::string actions) {m_actions = actions;}
        void set_robot_position(pos_t x, pos_t y) {m_robot.set_position(x,y);}
        void set_robot_orientation(char c) {
            m_robot.set_orientation(char_to_orientation(c));
        }
        void set_robot_orientation(orientation o) {
            m_robot.set_orientation(o);
        }
        void simulate();
        void report_robot_position();
        void set_robot_lost(bool lost=false);

        static orientation char_to_orientation(char cOrit){
            orientation result = orientation::north;
            switch(cOrit) {
                case 'E':
                    result = orientation::east;
                    break;
                case 'W':
                    result = orientation::west;
                    break;
                case 'S':
                    result = orientation::south;
                    break;
                default:
                    break;
            }
            return result;
        }

    private:
        Grid m_grid;
        Robot m_robot;
        std::string m_actions;

        bool is_robot_lost(); 
};

bool Master::is_robot_lost(){
    Pos p = m_robot.get_position();
    pos_t width = m_grid.get_width();
    pos_t height = m_grid.get_height();

    if ((p.m_x < 0) || (p.m_y < 0) || (p.m_x > width) || (p.m_y > height)) {
#ifdef DEBUG_LOG
        std::cout << "robot lost at " << p.m_x << " " << p.m_y << "\n"; 
#endif
        return true;
    }
    else {
        return false;
    }
}

void Master::set_robot_lost(bool lost){
    m_robot.set_lost(lost);
}

void Master::simulate(){
    for(int nSize=m_actions.size(), i=0; (i < nSize) && !m_robot.is_lost(); ++i){
        Pos robot_pos = m_robot.get_position();
        char ch_action = m_actions[i];

        if ('F' == ch_action){
            bool is_trap = m_grid.is_trap(robot_pos.m_x, robot_pos.m_y, m_robot.get_orientation());
            m_robot.move();
            if (!is_trap){
                if (is_robot_lost()){
#ifdef DEBUG_LOG
        std::cout << "robot goes out of grid!\n"; 
#endif
                    m_grid.add_trap(robot_pos.m_x, robot_pos.m_y, m_robot.get_orientation());
                    m_robot.set_lost();
                    m_robot.move_back();
                }
            }
            else {
                if (is_robot_lost()){
                    m_robot.move_back();
                }
            }
        }
        else if ('L' == ch_action){
            m_robot.turn(action::left);
        }
        else {
            m_robot.turn(action::right);
        }
#ifdef DEBUG_LOG
        m_robot.report();
#endif
    }
}

void Master::report_robot_position() {
    Pos robot_pos = m_robot.get_position();

    std::cout << robot_pos.m_x << " " << robot_pos.m_y 
        << " " << orientation_to_char(m_robot.get_orientation());
    if (m_robot.is_lost()){
        std::cout << " LOST";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]){
#ifndef ONLINE_JUDGE
    std::ifstream input("in.txt");
    std::cin.rdbuf(input.rdbuf());
#endif
    pos_t width, height;
    pos_t x, y;
    char orit;

    std::string actions;
    std::cin >> width >> height;
    Master master(width, height);
    
    while(std::cin >> x >> y >> orit) {
        std::cin >> actions;
#ifdef DEBUG_LOG
        std::cout << "------------\n";
#endif
        master.set_robot_position(x, y);
        master.set_robot_orientation(orit);
        master.set_robot_lost(false);
        master.set_actions(actions);
        master.simulate();
        master.report_robot_position();
    }

    return 0;
}
