// Copyright (C) 2020  I. Bogoslavskyi, C. Stachniss
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef SRC_UTILS_VELODYNE_UTILS_H_
#define SRC_UTILS_VELODYNE_UTILS_H_

#include <opencv2/opencv.hpp>

#include <string>
#include <vector>

#include "depth_clustering/projections/projection_params.h"
#include "depth_clustering/utils/cloud.h"

namespace depth_clustering {

const std::vector<float> MOOSMAN_CORRECTIONS{
    {0.02587499999999987,   -0.0061250000000001581, 0.031874999999999876,
     0.001874999999999849,  0.029874999999999874,   -0.1961250000000001,
     0.049874999999999892,  -0.034125000000000183,  0.0038749999999998508,
     0.0058749999999998526, 0.035874999999999879,   -0.064124999999999988,
     0.035874999999999879,  0.001874999999999849,   -0.024125000000000174,
     -0.062124999999999986, 0.039874999999999883,   -0.020125000000000171,
     0.075874999999999915,  -0.024125000000000174,  -0.0041250000000001563,
     -0.058124999999999982, -0.032125000000000181,  -0.058124999999999982,
     0.021874999999999867,  -0.032125000000000181,  0.059874999999999901,
     -0.04412499999999997,  0.075874999999999915,   -0.0041250000000001563,
     0.021874999999999867,  0.0058749999999998526,  -0.036125000000000185,
     -0.022125000000000172, -0.0041250000000001563, -0.058124999999999982,
     -0.026125000000000176, -0.030125000000000179,  0.045874999999999888,
     0.035874999999999879,  -0.026125000000000176,  0.041874999999999885,
     -0.086125000000000007, -0.060124999999999984,  0.031874999999999876,
     -0.010125000000000162, -0.024125000000000174,  -0.048124999999999973,
     -0.038125000000000187, 0.039874999999999883,   -0.026125000000000176,
     0.037874999999999881,  -0.020125000000000171,  0.051874999999999893,
     -0.014125000000000165, 0.019874999999999865,   -0.0021250000000001545,
     0.027874999999999872,  0.0058749999999998526,  0.021874999999999867,
     0.023874999999999869,  0.085874999999999702,   0.085874999999999702,
     0.11587499999999995}};

Cloud::Ptr CloudFromMat(const cv::Mat& image, const ProjectionParams& config);
Cloud::Ptr ReadKittiCloud(const std::string& path);
Cloud::Ptr ReadKittiCloudTxt(const std::string& path);
cv::Mat MatFromDepthPng(const std::string& path);

}  // namespace depth_clustering

#endif  // SRC_UTILS_VELODYNE_UTILS_H_
