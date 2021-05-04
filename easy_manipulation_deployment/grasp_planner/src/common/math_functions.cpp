// Copyright 2020 Advanced Remanufacturing and Technology Centre
// Copyright 2020 ROS-Industrial Consortium Asia Pacific Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// Main PCL files

#include "grasp_planner/common/math_functions.hpp"


float MathFunctions::normalize(const float & target, const float & min, const float & max)
{
  if(target == min && min == max)
  {
    return 1;
  }
  else
  {
    return (target - min) / (max - min);
  }
  //return (target + 1e-8 - min) / (max - min);
}

float MathFunctions::normalizeInt(const int & target, const int & min, const int & max)
{
  return float(target - min) / float(max - min);
}

float MathFunctions::getAngleBetweenVectors(Eigen::Vector3f vector_1, Eigen::Vector3f vector_2)
{
  return(1e-8 + std::abs((vector_1.dot(vector_2)) /(vector_1.norm() * vector_2.norm())));
}

Eigen::Vector3f MathFunctions::getPointInDirection(
  Eigen::Vector3f base_point,
  Eigen::Vector3f vector_direction,
  float distance)
{
  Eigen::Vector3f direction_normalized = vector_direction/vector_direction.norm();
  return(base_point + distance * direction_normalized);
}