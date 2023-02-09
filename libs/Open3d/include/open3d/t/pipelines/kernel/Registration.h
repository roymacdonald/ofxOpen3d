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

#include "open3d/core/Tensor.h"
#include "open3d/t/pipelines/registration/Registration.h"
#include "open3d/t/pipelines/registration/RobustKernel.h"

namespace open3d {
namespace t {
namespace pipelines {
namespace kernel {

/// \brief Computes pose for point to plane registration method.
///
/// \param source_positions source point positions of Float32 or Float64 dtype.
/// \param target_positions target point positions of same dtype as source point
/// positions.
/// \param target_normals target point normals of same dtype as source point
/// positions.
/// \param correspondence_indices Tensor of type Int64 containing indices of
/// corresponding target positions, where the value is the target index and the
/// index of the value itself is the source index. It contains -1 as value at
/// index with no correspondence.
/// \param kernel statistical robust kernel for outlier rejection.
/// \return Pose [alpha beta gamma, tx, ty, tz], a shape {6} tensor of dtype
/// Float64, where alpha, beta, gamma are the Euler angles in the ZYX order.
core::Tensor ComputePosePointToPlane(const core::Tensor &source_positions,
                                     const core::Tensor &target_positions,
                                     const core::Tensor &target_normals,
                                     const core::Tensor &correspondence_indices,
                                     const registration::RobustKernel &kernel);

/// \brief Computes pose for colored-icp registration method.
///
/// \param source_positions source point positions of Float32 or Float64 dtype.
/// \param source_colors source point colors of same dtype as source point
/// positions.
/// \param target_positions target point positions of same dtype as source point
/// positions.
/// \param target_normals target point normals of same dtype as source point
/// positions.
/// \param target_colors target point colors of same dtype as source point
/// positions.
/// \param target_color_gradients targets point color gradients of same dtype as
/// source point positions.
/// \param correspondence_indices Tensor of type Int64 containing indices of
/// corresponding target positions, where the value is the target index and the
/// index of the value itself is the source index. It contains -1 as value at
/// index with no correspondence.
/// \param kernel statistical robust kernel for outlier rejection.
/// \param lambda_geometric `λ ∈ [0,1]` in the overall energy `λEG + (1−λ)EC`.
/// Refer the documentation of Colored-ICP for more information.
/// \return Pose [alpha beta gamma, tx, ty, tz], a shape {6} tensor of dtype
/// Float64, where alpha, beta, gamma are the Euler angles in the ZYX order.
core::Tensor ComputePoseColoredICP(const core::Tensor &source_positions,
                                   const core::Tensor &source_colors,
                                   const core::Tensor &target_positions,
                                   const core::Tensor &target_normals,
                                   const core::Tensor &target_colors,
                                   const core::Tensor &target_color_gradients,
                                   const core::Tensor &correspondence_indices,
                                   const registration::RobustKernel &kernel,
                                   const double &lambda_geometric);

/// \brief Computes (R) Rotation {3,3} and (t) translation {3,}
/// for point to point registration method.
///
/// \param source_positions source point positions of Float32 or Float64 dtype.
/// \param target_positions target point positions of same dtype as source point
/// positions.
/// \param correspondence_indices Tensor of type Int64 containing indices of
/// corresponding target positions, where the value is the target index and the
/// index of the value itself is the source index. It contains -1 as value at
/// index with no correspondence.
/// \return tuple of (R, t). [Dtype: Float64].
std::tuple<core::Tensor, core::Tensor> ComputeRtPointToPoint(
        const core::Tensor &source_positions,
        const core::Tensor &target_positions,
        const core::Tensor &correspondence_indices);

/// \brief Computes `Information Matrix` of shape {6, 6}, of dtype `Float64` on
/// device `CPU:0`, from the target point cloud and correspondence indices
/// w.r.t. target point cloud.
/// Only target positions and correspondence indices are required.
///
/// \param target_positions The target point positions.
/// \param correspondence_indices Tensor of type Int64 containing indices of
/// corresponding target positions, where the value is the target index and the
/// index of the value itself is the source index. It contains -1 as value
/// at index with no correspondence.
core::Tensor ComputeInformationMatrix(
        const core::Tensor &target_positions,
        const core::Tensor &correspondence_indices);

}  // namespace kernel
}  // namespace pipelines
}  // namespace t
}  // namespace open3d
