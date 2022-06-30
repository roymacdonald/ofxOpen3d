//
//  ofxOpen3d.cpp
//  openGRTest
//
//  Created by Roy Macdonald on 29-06-22.
//

#include "ofxOpen3d.h"

glm::mat4 ofxOpen3d::toGlm(const Eigen::Matrix4d_u& eigen){
    glm::mat4 mat;
    for(size_t i = 0; i < 4; i++){
        for(size_t j = 0; j < 4; j++){
            mat[i][j] = eigen(i, j);
        }
    }
    return mat;
}

void ofxOpen3d::toOpen3d(ofMesh & mesh, PclPointCloud & pointcloud){
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
