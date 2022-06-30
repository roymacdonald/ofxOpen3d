//
//  ofxOpen3d.hpp
//  openGRTest
//
//  Created by Roy Macdonald on 29-06-22.
//

#pragma once
#include "ofMain.h"
#include "open3d/Open3D.h"

typedef std::shared_ptr<open3d::geometry::PointCloud> PclPointCloud;

namespace ofxOpen3d{


glm::mat4 toGlm(const Eigen::Matrix4d_u& eigen);

void toOpen3d(ofMesh & src, PclPointCloud & dest);

void toOF(PclPointCloud &src, ofMesh & dest);





}//namespace ofxOpen3d

