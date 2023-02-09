//
//  ofxOpen3d.cpp
//  openGRTest
//
//  Created by Roy Macdonald on 29-06-22.
//

#include "ofxOpen3d.h"

//using namespace open3d::pipelines::registration;

glm::mat4 ofxOpen3d::toGlm(const Eigen::Matrix4d_u& eigen){
    glm::mat4 mat;
    for(size_t i = 0; i < 4; i++){
        for(size_t j = 0; j < 4; j++){
            mat[i][j] = eigen(i, j);
        }
    }
    return mat;
}

void ofxOpen3d::toOpen3d(const ofMesh & mesh, PclPointCloud & pointcloud){
    pointcloud = std::make_shared<open3d::geometry::PointCloud>();
    
    pointcloud->points_.resize(mesh.getNumVertices());
    
    size_t cnt = 0;
    for(auto& v: mesh.getVertices()){
        pointcloud->points_[cnt++] = Eigen::Vector3d(v.x, v.y, v.z);
    }
//    cout << "To open3d " << (pointcloud?"1":"0") << endl;
//    cout << pointcloud->points_.size() << endl;
    
}

void ofxOpen3d::toOF(PclPointCloud &pointCloud, ofMesh & mesh){
    if(pointCloud == nullptr)return;
    mesh.clear();
    mesh.setMode(OF_PRIMITIVE_POINTS);
    for(auto& p: pointCloud->points_){
        mesh.addVertex(glm::vec3(p.x(), p.y(), p.z()));
    }
}


void ofxOpen3d::downsampleMesh(const PclPointCloud& pcl_mesh, PclPointCloud& pcl_mesh_down, float voxelSize){
    pcl_mesh_down = pcl_mesh->VoxelDownSample(voxelSize);
    pcl_mesh_down->EstimateNormals( open3d::geometry::KDTreeSearchParamHybrid(2 * voxelSize, 30));
}

void ofxOpen3d::downsampleMesh(const ofMesh& _original, ofMesh& _downsampled, float voxelSize){
    
    PclPointCloud pcl_mesh, pcl_mesh_down;
    ofxOpen3d::toOpen3d(_original, pcl_mesh );
    
    downsampleMesh(pcl_mesh, pcl_mesh_down, voxelSize);

    ofxOpen3d::toOF(pcl_mesh_down, _downsampled);
        
    
}

glm::mat4 ofxOpen3d::computeIcp(const PclPointCloud& source,  const PclPointCloud& target, float max_distance, double relative_fitness, double relative_rmse, size_t num_iterations){
    
    auto result = open3d::pipelines::registration::RegistrationGeneralizedICP(
            *source,
            *target,
            max_distance,
            Eigen::Matrix4d::Identity(),
            open3d::pipelines::registration::TransformationEstimationForGeneralizedICP(),
            open3d::pipelines::registration::ICPConvergenceCriteria(relative_fitness, relative_rmse, num_iterations));
    
    
    return toGlm(result.transformation_);
     
}
glm::mat4 ofxOpen3d::computeIcp(const ofxOpen3d::IcpParams& param){
    return ofxOpen3d::computeIcp( param.source, param.target, param.max_distance, param.relative_fitness, param.relative_rmse, param.num_iterations);
}
