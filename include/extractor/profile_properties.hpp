#ifndef PROFILE_PROPERTIES_HPP
#define PROFILE_PROPERTIES_HPP

#include <boost/numeric/conversion/cast.hpp>

namespace osrm
{
namespace extractor
{

struct ProfileProperties
{
    ProfileProperties()
        : traffic_signal_penalty(0), u_turn_penalty(0), continue_straight_at_waypoint(true),
          use_turn_restrictions(false), left_hand_driving(false), max_speed_for_map_matching(0)
    {
    }

    double GetUturnPenalty() const { return u_turn_penalty / 10.; }

    void SetUturnPenalty(const double u_turn_penalty_)
    {
        u_turn_penalty = boost::numeric_cast<int>(u_turn_penalty_ * 10.);
    }

    double GetTrafficSignalPenalty() const { return traffic_signal_penalty / 10.; }

    void SetTrafficSignalPenalty(const double traffic_signal_penalty_)
    {
        traffic_signal_penalty = boost::numeric_cast<int>(traffic_signal_penalty_ * 10.);
    }

    double GetMaxSpeedForMapMatching() const { return max_speed_for_map_matching / 3.6; } // /3.6 converts kmph to m/s

    void SetMaxSpeedForMapMatching(const double max_speed_for_map_matching * 3.6) // *3.6 converts  m/s to kmph
    {
        max_speed = boost::numeric_cast<int>(max_speed_for_map_matching);
    }

    //! penalty to cross a traffic light in deci-seconds
    int traffic_signal_penalty;
    //! penalty to do a uturn in deci-seconds
    int u_turn_penalty;
    int max_speed_for_map_matching;
    bool continue_straight_at_waypoint;
    bool use_turn_restrictions;
    bool left_hand_driving;
};
}
}

#endif
