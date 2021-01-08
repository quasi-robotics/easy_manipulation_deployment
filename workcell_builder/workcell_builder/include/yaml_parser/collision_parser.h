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


#ifndef COLLISION_PARSER_H
#define COLLISION_PARSER_H

#include "yaml-cpp/yaml.h"

#include "origin_parser.h"
#include "material_parser.h"
#include "geometry_parser.h"
#include "collision.h"


struct CollisionParser
{
    static void generate_collision(YAML::Emitter*** out, Collision collision)
    {

        //***out<<YAML::BeginMap;
        ***out<< YAML::Key <<"collision";
        ***out<<YAML::Value;
        ***out<<YAML::BeginMap;

        ***out<< YAML::Key <<"name";
        ***out<<YAML::Value<< collision.name;

        GeometryParser::generate_geometry(&out, collision.geometry);

        if(collision.origin.is_origin)
        {
            OriginParser::generate_origin(&out, collision.origin);
        }

        ***out<<YAML::EndMap;


    }
};

#endif // COLLISIONLINK_H
