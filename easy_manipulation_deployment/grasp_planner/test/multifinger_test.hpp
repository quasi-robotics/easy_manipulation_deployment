// Copyright 2020 Advanced Remanufacturing and Technology Centre
// Copyright 2020 ROS-Industrial Consortium Asia Pacific Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//`
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#ifndef MULTIFINGER_TEST_HPP_
#define MULTIFINGER_TEST_HPP_

#include <gtest/gtest.h>

// Other Libraries
#include <math.h>
#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <cmath>
#include <memory>
#include <string>
#include <vector>
#include <limits>

#include "emd/grasp_planner/end_effectors/finger_gripper.hpp"
#include "emd/common/pcl_functions.hpp"
#include "emd/common/fcl_types.hpp"
#include "emd/grasp_planner/grasp_object.hpp"

class MultiFingerTest : public ::testing::Test
{
public:
  using CollisionObject = grasp_planner::collision::CollisionObject;
  std::shared_ptr<GraspObject> object;
  std::string id;
  int num_fingers_side_1;
  int num_fingers_side_2;
  float distance_between_fingers_1;
  float distance_between_fingers_2;
  float finger_thickness;
  float gripper_stroke;
  float voxel_size;
  float grasp_quality_weight1;
  float grasp_quality_weight2;
  float grasp_plane_dist_limit;
  float cloud_normal_radius;
  float worldXAngleThreshold;
  float worldYAngleThreshold;
  float worldZAngleThreshold;
  std::string grasp_stroke_direction;
  std::string grasp_stroke_normal_direction;
  std::string grasp_approach_direction;
  std::string camera_frame;

  std::shared_ptr<FingerGripper> gripper;
  std::shared_ptr<grasp_planner::collision::CollisionObject> collision_object_ptr;

  // pcl::visualization::PCLVisualizer::Ptr viewer;

  MultiFingerTest();
  void ResetVariables();
  void LoadGripper();
  void GenerateObjectHorizontal();
  void GenerateObjectVertical();
  void GenerateObjectCollision(float length, float breadth, float height);


  void SetUp(void)
  {
    std::cout << "Setup" << std::endl;
  }
  void TearDown(void)
  {
    std::cout << "Teardown" << std::endl;
  }
};

#endif  // MULTIFINGER_TEST_HPP_
