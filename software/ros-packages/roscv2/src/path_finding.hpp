#include "obstacle_detect.hpp"
#include <map>
#include <string>
#include <std_msgs/String.h>


//Options
#define MOVE

#ifndef PI
#define PI (3.1415)
#endif

#define ROVER_WIDTH (1.25)
#define MAX_OBS_DIST (5.0)
#define ARC_RAD (PI/8)

#define THRESH_DECAY (0.95f)
#define THRESH_GROWTH (0.2f)
#define THRESH (0.5f)

#define HALF_ANGLE (45.0f)

#define FORWARD (0)
#define LEFT (1)
#define RIGHT (2)

#define HAS_GOAL (0)
#define ANY_GOAL (1)
#define NO_GOAL (2)

void grid_callback(const roscv2::Grid& msg);
void goal_callback(const std_msgs::String& msg);
bool forward_obstacle(const Grid& grid);
bool goal_obstacle(const Grid& grid, float angle, float dist);
void score_directions(const Grid& grid, std::map<int, float>& scores);
void print_grid(const Grid& grid);
void move_forward(bool blocked, std::map<int, float>& scores);
void move_goal(bool goal_blocked, bool direct_blocked, 
               float angle, std::map<int, float>& scores);
static void catch_sig(int sig);
bool has_goal();
