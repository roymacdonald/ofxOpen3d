// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018-2021 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#pragma once

#include <memory>
#include <vector>

#include "open3d/utility/Eigen.h"
#include "open3d/utility/IJsonConvertible.h"

namespace open3d {
namespace pipelines {
namespace registration {

/// \class PoseGraphNode
///
/// \brief Node of PoseGraph.
class PoseGraphNode : public utility::IJsonConvertible {
public:
    /// \brief Default Constructor.
    PoseGraphNode(const Eigen::Matrix4d &pose = Eigen::Matrix4d::Identity())
        : pose_(pose) {}
    ~PoseGraphNode();

public:
    bool ConvertToJsonValue(Json::Value &value) const override;
    bool ConvertFromJsonValue(const Json::Value &value) override;

public:
    Eigen::Matrix4d_u pose_;
};

/// \class PoseGraphEdge
///
/// \brief Edge of PoseGraph.
class PoseGraphEdge : public utility::IJsonConvertible {
public:
    /// \brief Parameterized Constructor.
    ///
    /// \param source_node_id Source PoseGraphNode id.
    /// \param target_node_id Target PoseGraphNode id.
    /// \param transformation Transformation matrix.
    /// \param information Information matrix.
    /// \param uncertain Whether the edge is uncertain.
    /// \param confidence Confidence value of the edge.
    PoseGraphEdge(
            int source_node_id = -1,
            int target_node_id = -1,
            const Eigen::Matrix4d &transformation = Eigen::Matrix4d::Identity(),
            const Eigen::Matrix6d &information = Eigen::Matrix6d::Identity(),
            bool uncertain = false,
            double confidence = 1.0)
        : source_node_id_(source_node_id),
          target_node_id_(target_node_id),
          transformation_(transformation),
          information_(information),
          uncertain_(uncertain),
          confidence_(confidence) {}
    ~PoseGraphEdge();

public:
    bool ConvertToJsonValue(Json::Value &value) const override;
    bool ConvertFromJsonValue(const Json::Value &value) override;

public:
    /// Source PoseGraphNode id.
    int source_node_id_;
    /// Target PoseGraphNode id.
    int target_node_id_;
    /// Transformation matrix.
    Eigen::Matrix4d_u transformation_;
    /// Information matrix.
    Eigen::Matrix6d_u information_;
    /// \brief Whether the edge is uncertain.
    ///
    /// Odometry edge has uncertain == false
    /// loop closure edges has uncertain == true
    bool uncertain_;
    /// \brief Confidence value of the edge.
    ///
    /// if uncertain_ is true, it has confidence bounded in [0,1].
    /// 1 means reliable, and 0 means unreliable edge.
    /// This correspondence to line process value in [Choi et al 2015]
    /// See core/registration/globaloptimization.h for more details.
    double confidence_;
};

/// \class PoseGraph
///
/// \brief Data structure defining the pose graph.
class PoseGraph : public utility::IJsonConvertible {
public:
    /// \brief Default Constructor.
    PoseGraph();
    ~PoseGraph() override;

public:
    bool ConvertToJsonValue(Json::Value &value) const override;
    bool ConvertFromJsonValue(const Json::Value &value) override;

public:
    /// List of PoseGraphNode.
    std::vector<PoseGraphNode> nodes_;
    /// List of PoseGraphEdge.
    std::vector<PoseGraphEdge> edges_;
};

}  // namespace registration
}  // namespace pipelines
}  // namespace open3d
