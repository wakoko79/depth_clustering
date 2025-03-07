// Copyright (C) 2017  I. Bogoslavskyi, C. Stachniss, University of Bonn

// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.

// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details.

// You should have received a copy of the GNU General Public License along
// with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef SRC_ROS_BRIDGE_CLOUD_ODOM_ROS_PUBLISHER_H_
#define SRC_ROS_BRIDGE_CLOUD_ODOM_ROS_PUBLISHER_H_

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>

#include <opencv4/opencv2/core/cuda.hpp>
// #include <opencv4/opencv2/cudaarithm.hpp>
// #include <opencv4/opencv2/cudaimgproc.hpp>

#include <algorithm>

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include "depth_clustering/communication/abstract_client.h"
#include "depth_clustering/communication/abstract_sender.h"
#include "depth_clustering/projections/projection_params.h"
#include <unordered_map>
#include <pcl/point_cloud.h>
#include "depth_clustering/utils/radians.h"
#include "depth_clustering/utils/cloud.h"
#include <pcl_conversions/pcl_conversions.h>
namespace depth_clustering {


using sensor_msgs::PointCloud2;
using sensor_msgs::PointCloud2ConstPtr;
typedef pcl::PointXYZL PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

class CloudRosPublisher : public AbstractClient<Cloud> {
                           
 public:
  CloudRosPublisher(ros::NodeHandle* node_handle, const std::string& frame_id, const std::string& topic_clouds) :
      _node_handle{node_handle},
      _frame_id{frame_id},
      _topic_clouds{topic_clouds},
      _cloud_pub{_node_handle->advertise<PointCloud2>(_topic_clouds, 1)}
    {}      
  virtual ~CloudRosPublisher() {}

  void OnNewObjectReceived(const Cloud& cloud, const int id) override;

  void PointsToPcl(const Cloud& cloud, PointCloudT& pcl_cloud);

  void ImageToPcl(const Cloud& cloud, PointCloudT& pcl_cloud);

  void PublishCloud(const PointCloudT& pcl_cloud);

 protected:
  ros::NodeHandle* _node_handle;
  std::string _frame_id, _topic_clouds;
  ros::Publisher _cloud_pub;
};

}  // namespace depth_clustering

#endif  // SRC_ROS_BRIDGE_CLOUD_ODOM_ROS_PUBLISHER_H_
