/*
 * SPDX-FileCopyrightText: Copyright (c) 2025 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// NvDsRoiMeta

#include "bind_string_property_definitions.h"
#include "bindroimeta.hpp"
#include "nvdsmeta.h"

namespace py = pybind11;

namespace pydeepstream {
       void bindroimeta(py::module &m) {
              py::enum_<NvDsDataType>(m, "NvDsDataType",
                                   pydsdoc::NvDsRoiMetaDoc::NvDsDataTypeDoc::descr)
                     .value("NvDsDataType_FP32", NvDsDataType_FP32,
                            pydsdoc::NvDsRoiMetaDoc::NvDsDataTypeDoc::NvDsDataType_FP32)
                     .value("NvDsDataType_UINT8", NvDsDataType_UINT8,
                            pydsdoc::NvDsRoiMetaDoc::NvDsDataTypeDoc::NvDsDataType_UINT8)
                     .value("NvDsDataType_INT8", NvDsDataType_INT8,
                            pydsdoc::NvDsRoiMetaDoc::NvDsDataTypeDoc::NvDsDataType_INT8)
                     .value("NvDsDataType_UINT32", NvDsDataType_UINT32,
                            pydsdoc::NvDsRoiMetaDoc::NvDsDataTypeDoc::NvDsDataType_UINT32)
                     .value("NvDsDataType_INT32", NvDsDataType_INT32,
                            pydsdoc::NvDsRoiMetaDoc::NvDsDataTypeDoc::NvDsDataType_INT32)
                     .value("NvDsDataType_FP16", NvDsDataType_FP16,
                            pydsdoc::NvDsRoiMetaDoc::NvDsDataTypeDoc::NvDsDataType_FP16)
                     .export_values();
       
              py::enum_<NvDsUnitType>(m, "NvDsUnitType",
                                   pydsdoc::NvDsRoiMetaDoc::NvDsUnitTypeDoc::descr)
                     .value("NvDsUnitType_FullFrame", NvDsUnitType_FullFrame,
                            pydsdoc::NvDsRoiMetaDoc::NvDsUnitTypeDoc::NvDsUnitType_FullFrame)
                     .value("NvDsUnitType_ROI", NvDsUnitType_ROI,
                            pydsdoc::NvDsRoiMetaDoc::NvDsUnitTypeDoc::NvDsUnitType_ROI)
                     .value("NvDsUnitType_Object", NvDsUnitType_Object,
                            pydsdoc::NvDsRoiMetaDoc::NvDsUnitTypeDoc::NvDsUnitType_Object)
                     .export_values();


              py::class_<NvDsRoiMeta>(m, "NvDsRoiMeta",
                                          pydsdoc::NvDsRoiMetaDoc::NvDsRoiMetaDoc::descr)
                     .def(py::init<>())
                     .def_readwrite("roi", &NvDsRoiMeta::roi)
                     .def_readwrite("converted_buffer", &NvDsRoiMeta::converted_buffer)
                     .def_readwrite("frame_meta", &NvDsRoiMeta::frame_meta)
                     .def_readwrite("scale_ratio_x", &NvDsRoiMeta::scale_ratio_x)
                     .def_readwrite("scale_ratio_y", &NvDsRoiMeta::scale_ratio_y)
                     .def_readwrite("offset_left", &NvDsRoiMeta::offset_left)
                     .def_readwrite("offset_top", &NvDsRoiMeta::offset_top)
                     .def_readwrite("classifier_meta_list", &NvDsRoiMeta::classifier_meta_list)
                     .def_readwrite("roi_user_meta_list", &NvDsRoiMeta::roi_user_meta_list)
                     .def_readwrite("object_meta", &NvDsRoiMeta::object_meta)

                     .def("cast",
                            [](void *data) {
                            return (NvDsRoiMeta *) data;
                            },
                            py::return_value_policy::reference,
                            pydsdoc::NvDsRoiMetaDoc::NvDsRoiMetaDoc::cast);
    }
}