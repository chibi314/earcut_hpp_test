#include "earcut.hpp"
#include <iostream>
#include <ros/ros.h>
#include <visualization_msgs/MarkerArray.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "earcut_sample");
  ros::NodeHandle nh;
  ros::Publisher vis_pub_ = nh.advertise<visualization_msgs::MarkerArray>("visualization_marker", 1);
  ros::Rate rate(10);
  using Coord = double;
  using N = uint32_t;
  using Point = std::array<Coord, 2>;
  std::vector<std::vector<Point>> polygon;
  polygon.push_back({{-160, 92.4}, {-160, 892.4}, {160, 892.4}, {160, 92.4}, {852.84, -307.4}, {692.84, -584.76}, {0, -184.76}, {-692.84, -584.76}, {-852.84, -307.4}});
  std::vector<N> indices = mapbox::earcut<N>(polygon);
  /*
  for (const auto &i : indices) {
    std::cout << i << std::endl;
  }
  */
  while (ros::ok()) {
    visualization_msgs::MarkerArray marker_array;
    visualization_msgs::Marker marker;
    marker.header.frame_id = "/world";
    marker.header.stamp = ros::Time::now();
    marker.ns = "mesh";
    marker.id = 0;
    marker.type = visualization_msgs::Marker::TRIANGLE_LIST;
    marker.action = visualization_msgs::Marker::ADD;
    marker.lifetime = ros::Duration();
    marker.pose.position.x = 0.0;
    marker.pose.position.y = 0.0;
    marker.pose.position.z = 0.0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 0.0;
    marker.scale.x = 1.0;
    marker.scale.y = 1.0;
    marker.scale.z = 1.0;
    for (const auto& i : indices) {
      geometry_msgs::Point point;
      point.x = polygon.at(0).at(i).at(0) * 0.001;
      point.y = polygon.at(0).at(i).at(1) * 0.001;
      point.z = 0.0;
      std_msgs::ColorRGBA color;
      color.r = 1.0;
      color.g = 0.0;
      color.b = 0.0;
      color.a = 1.0;
      marker.points.push_back(point);
      marker.colors.push_back(color);
    }
    marker_array.markers.push_back(marker);
    vis_pub_.publish(marker_array);
    ros::spinOnce();
    rate.sleep();
  }
  return 0;
}
