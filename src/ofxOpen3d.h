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

void toOpen3d(const ofMesh & src, PclPointCloud & dest);

void toOF(PclPointCloud &src, ofMesh & dest);


void downsampleMesh(const PclPointCloud& pcl_mesh, PclPointCloud& pcl_mesh_down, float voxelSize);
void downsampleMesh(const ofMesh& _original, ofMesh& _downsampled, float voxelSize);


struct IcpParams{
    IcpParams(const PclPointCloud& _source,  const PclPointCloud& _target, float _max_distance, double _relative_fitness, double _relative_rmse, size_t _num_iterations):
    source(_source),
    target(_target),
    max_distance(_max_distance),
    relative_fitness(_relative_fitness),
    relative_rmse(_relative_rmse),
    num_iterations(_num_iterations)
    {
        
    }
    const PclPointCloud& source;
    const PclPointCloud& target;
    float max_distance;
    double relative_fitness;
    double relative_rmse;
    size_t num_iterations;
};

//--------------------------------------------------------------
glm::mat4 computeIcp(const IcpParams& params);

//--------------------------------------------------------------
glm::mat4 computeIcp(const PclPointCloud& source,  const PclPointCloud& target, float max_distance, double relative_fitness, double relative_rmse, size_t num_iterations);

}//namespace ofxOpen3d

