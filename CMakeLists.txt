cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

set(CMAKE_SYSTEM_VERSION 10.0 CACHE STRING "" FORCE)

project(OpenGLProject CXX)

################################################################################
# Set target arch type if empty. Visual studio solution generator provides it.
################################################################################
if(NOT CMAKE_VS_PLATFORM_NAME)
    set(CMAKE_VS_PLATFORM_NAME "x64")
endif()
message("${CMAKE_VS_PLATFORM_NAME} architecture in use")

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86"))
    message(FATAL_ERROR "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Global configuration types
################################################################################
set(CMAKE_CONFIGURATION_TYPES
    "Debug"
    "Release"
    CACHE STRING "" FORCE
)

################################################################################
# Global compiler options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_CXX_FLAGS "")
    set(CMAKE_CXX_FLAGS_DEBUG "")
    set(CMAKE_CXX_FLAGS_RELEASE "")
endif()

################################################################################
# Global linker options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_EXE_LINKER_FLAGS "")
    set(CMAKE_MODULE_LINKER_FLAGS "")
    set(CMAKE_SHARED_LINKER_FLAGS "")
    set(CMAKE_STATIC_LINKER_FLAGS "")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "${CMAKE_STATIC_LINKER_FLAGS}")
endif()

################################################################################
# Nuget packages function stub.
################################################################################
function(use_package TARGET PACKAGE VERSION)
    message(WARNING "No implementation of use_package. Create yours. "
                    "Package \"${PACKAGE}\" with version \"${VERSION}\" "
                    "for target \"${TARGET}\" is ignored!")
endfunction()

################################################################################
# Common utils
################################################################################
include(CMake/Utils.cmake)

################################################################################
# Additional Global Settings(add specific info there)
################################################################################
include(CMake/GlobalSettingsInclude.cmake OPTIONAL)

################################################################################
# Use solution folders feature
################################################################################
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# Sub-projects
################################################################################



























set(PROJECT_NAME OpenGLProject)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "res/shader/vbasic.shader"
)
source_group("" FILES ${no_group_source_files})

set(Header_Files
    "SRC/IndexBuffer.h"
    "SRC/Renderer.h"
    "SRC/Shader.h"
    "SRC/tests/test.h"
    "SRC/tests/testClearColor.h"
    "SRC/tests/TestTexture2D.h"
    "SRC/Texture.h"
    "SRC/vendor/glm/common.hpp"
    "SRC/vendor/glm/detail/_features.hpp"
    "SRC/vendor/glm/detail/_fixes.hpp"
    "SRC/vendor/glm/detail/_noise.hpp"
    "SRC/vendor/glm/detail/_swizzle.hpp"
    "SRC/vendor/glm/detail/_swizzle_func.hpp"
    "SRC/vendor/glm/detail/_vectorize.hpp"
    "SRC/vendor/glm/detail/compute_common.hpp"
    "SRC/vendor/glm/detail/compute_vector_relational.hpp"
    "SRC/vendor/glm/detail/func_common.inl"
    "SRC/vendor/glm/detail/func_common_simd.inl"
    "SRC/vendor/glm/detail/func_exponential.inl"
    "SRC/vendor/glm/detail/func_exponential_simd.inl"
    "SRC/vendor/glm/detail/func_geometric.inl"
    "SRC/vendor/glm/detail/func_geometric_simd.inl"
    "SRC/vendor/glm/detail/func_integer.inl"
    "SRC/vendor/glm/detail/func_integer_simd.inl"
    "SRC/vendor/glm/detail/func_matrix.inl"
    "SRC/vendor/glm/detail/func_matrix_simd.inl"
    "SRC/vendor/glm/detail/func_packing.inl"
    "SRC/vendor/glm/detail/func_packing_simd.inl"
    "SRC/vendor/glm/detail/func_trigonometric.inl"
    "SRC/vendor/glm/detail/func_trigonometric_simd.inl"
    "SRC/vendor/glm/detail/func_vector_relational.inl"
    "SRC/vendor/glm/detail/func_vector_relational_simd.inl"
    "SRC/vendor/glm/detail/qualifier.hpp"
    "SRC/vendor/glm/detail/setup.hpp"
    "SRC/vendor/glm/detail/type_float.hpp"
    "SRC/vendor/glm/detail/type_half.hpp"
    "SRC/vendor/glm/detail/type_half.inl"
    "SRC/vendor/glm/detail/type_mat2x2.hpp"
    "SRC/vendor/glm/detail/type_mat2x2.inl"
    "SRC/vendor/glm/detail/type_mat2x3.hpp"
    "SRC/vendor/glm/detail/type_mat2x3.inl"
    "SRC/vendor/glm/detail/type_mat2x4.hpp"
    "SRC/vendor/glm/detail/type_mat2x4.inl"
    "SRC/vendor/glm/detail/type_mat3x2.hpp"
    "SRC/vendor/glm/detail/type_mat3x2.inl"
    "SRC/vendor/glm/detail/type_mat3x3.hpp"
    "SRC/vendor/glm/detail/type_mat3x3.inl"
    "SRC/vendor/glm/detail/type_mat3x4.hpp"
    "SRC/vendor/glm/detail/type_mat3x4.inl"
    "SRC/vendor/glm/detail/type_mat4x2.hpp"
    "SRC/vendor/glm/detail/type_mat4x2.inl"
    "SRC/vendor/glm/detail/type_mat4x3.hpp"
    "SRC/vendor/glm/detail/type_mat4x3.inl"
    "SRC/vendor/glm/detail/type_mat4x4.hpp"
    "SRC/vendor/glm/detail/type_mat4x4.inl"
    "SRC/vendor/glm/detail/type_mat4x4_simd.inl"
    "SRC/vendor/glm/detail/type_quat.hpp"
    "SRC/vendor/glm/detail/type_quat.inl"
    "SRC/vendor/glm/detail/type_quat_simd.inl"
    "SRC/vendor/glm/detail/type_vec1.hpp"
    "SRC/vendor/glm/detail/type_vec1.inl"
    "SRC/vendor/glm/detail/type_vec2.hpp"
    "SRC/vendor/glm/detail/type_vec2.inl"
    "SRC/vendor/glm/detail/type_vec3.hpp"
    "SRC/vendor/glm/detail/type_vec3.inl"
    "SRC/vendor/glm/detail/type_vec4.hpp"
    "SRC/vendor/glm/detail/type_vec4.inl"
    "SRC/vendor/glm/detail/type_vec4_simd.inl"
    "SRC/vendor/glm/exponential.hpp"
    "SRC/vendor/glm/ext.hpp"
    "SRC/vendor/glm/ext/matrix_clip_space.hpp"
    "SRC/vendor/glm/ext/matrix_clip_space.inl"
    "SRC/vendor/glm/ext/matrix_double2x2.hpp"
    "SRC/vendor/glm/ext/matrix_double2x2_precision.hpp"
    "SRC/vendor/glm/ext/matrix_double2x3.hpp"
    "SRC/vendor/glm/ext/matrix_double2x3_precision.hpp"
    "SRC/vendor/glm/ext/matrix_double2x4.hpp"
    "SRC/vendor/glm/ext/matrix_double2x4_precision.hpp"
    "SRC/vendor/glm/ext/matrix_double3x2.hpp"
    "SRC/vendor/glm/ext/matrix_double3x2_precision.hpp"
    "SRC/vendor/glm/ext/matrix_double3x3.hpp"
    "SRC/vendor/glm/ext/matrix_double3x3_precision.hpp"
    "SRC/vendor/glm/ext/matrix_double3x4.hpp"
    "SRC/vendor/glm/ext/matrix_double3x4_precision.hpp"
    "SRC/vendor/glm/ext/matrix_double4x2.hpp"
    "SRC/vendor/glm/ext/matrix_double4x2_precision.hpp"
    "SRC/vendor/glm/ext/matrix_double4x3.hpp"
    "SRC/vendor/glm/ext/matrix_double4x3_precision.hpp"
    "SRC/vendor/glm/ext/matrix_double4x4.hpp"
    "SRC/vendor/glm/ext/matrix_double4x4_precision.hpp"
    "SRC/vendor/glm/ext/matrix_float2x2.hpp"
    "SRC/vendor/glm/ext/matrix_float2x2_precision.hpp"
    "SRC/vendor/glm/ext/matrix_float2x3.hpp"
    "SRC/vendor/glm/ext/matrix_float2x3_precision.hpp"
    "SRC/vendor/glm/ext/matrix_float2x4.hpp"
    "SRC/vendor/glm/ext/matrix_float2x4_precision.hpp"
    "SRC/vendor/glm/ext/matrix_float3x2.hpp"
    "SRC/vendor/glm/ext/matrix_float3x2_precision.hpp"
    "SRC/vendor/glm/ext/matrix_float3x3.hpp"
    "SRC/vendor/glm/ext/matrix_float3x3_precision.hpp"
    "SRC/vendor/glm/ext/matrix_float3x4.hpp"
    "SRC/vendor/glm/ext/matrix_float3x4_precision.hpp"
    "SRC/vendor/glm/ext/matrix_float4x2.hpp"
    "SRC/vendor/glm/ext/matrix_float4x2_precision.hpp"
    "SRC/vendor/glm/ext/matrix_float4x3.hpp"
    "SRC/vendor/glm/ext/matrix_float4x3_precision.hpp"
    "SRC/vendor/glm/ext/matrix_float4x4.hpp"
    "SRC/vendor/glm/ext/matrix_float4x4_precision.hpp"
    "SRC/vendor/glm/ext/matrix_projection.hpp"
    "SRC/vendor/glm/ext/matrix_projection.inl"
    "SRC/vendor/glm/ext/matrix_relational.hpp"
    "SRC/vendor/glm/ext/matrix_relational.inl"
    "SRC/vendor/glm/ext/matrix_transform.hpp"
    "SRC/vendor/glm/ext/matrix_transform.inl"
    "SRC/vendor/glm/ext/quaternion_common.hpp"
    "SRC/vendor/glm/ext/quaternion_common.inl"
    "SRC/vendor/glm/ext/quaternion_common_simd.inl"
    "SRC/vendor/glm/ext/quaternion_double.hpp"
    "SRC/vendor/glm/ext/quaternion_double_precision.hpp"
    "SRC/vendor/glm/ext/quaternion_exponential.hpp"
    "SRC/vendor/glm/ext/quaternion_exponential.inl"
    "SRC/vendor/glm/ext/quaternion_float.hpp"
    "SRC/vendor/glm/ext/quaternion_float_precision.hpp"
    "SRC/vendor/glm/ext/quaternion_geometric.hpp"
    "SRC/vendor/glm/ext/quaternion_geometric.inl"
    "SRC/vendor/glm/ext/quaternion_relational.hpp"
    "SRC/vendor/glm/ext/quaternion_relational.inl"
    "SRC/vendor/glm/ext/quaternion_transform.hpp"
    "SRC/vendor/glm/ext/quaternion_transform.inl"
    "SRC/vendor/glm/ext/quaternion_trigonometric.hpp"
    "SRC/vendor/glm/ext/quaternion_trigonometric.inl"
    "SRC/vendor/glm/ext/scalar_common.hpp"
    "SRC/vendor/glm/ext/scalar_common.inl"
    "SRC/vendor/glm/ext/scalar_constants.hpp"
    "SRC/vendor/glm/ext/scalar_constants.inl"
    "SRC/vendor/glm/ext/scalar_int_sized.hpp"
    "SRC/vendor/glm/ext/scalar_relational.hpp"
    "SRC/vendor/glm/ext/scalar_relational.inl"
    "SRC/vendor/glm/ext/scalar_uint_sized.hpp"
    "SRC/vendor/glm/ext/scalar_ulp.hpp"
    "SRC/vendor/glm/ext/scalar_ulp.inl"
    "SRC/vendor/glm/ext/vector_bool1.hpp"
    "SRC/vendor/glm/ext/vector_bool1_precision.hpp"
    "SRC/vendor/glm/ext/vector_bool2.hpp"
    "SRC/vendor/glm/ext/vector_bool2_precision.hpp"
    "SRC/vendor/glm/ext/vector_bool3.hpp"
    "SRC/vendor/glm/ext/vector_bool3_precision.hpp"
    "SRC/vendor/glm/ext/vector_bool4.hpp"
    "SRC/vendor/glm/ext/vector_bool4_precision.hpp"
    "SRC/vendor/glm/ext/vector_common.hpp"
    "SRC/vendor/glm/ext/vector_common.inl"
    "SRC/vendor/glm/ext/vector_double1.hpp"
    "SRC/vendor/glm/ext/vector_double1_precision.hpp"
    "SRC/vendor/glm/ext/vector_double2.hpp"
    "SRC/vendor/glm/ext/vector_double2_precision.hpp"
    "SRC/vendor/glm/ext/vector_double3.hpp"
    "SRC/vendor/glm/ext/vector_double3_precision.hpp"
    "SRC/vendor/glm/ext/vector_double4.hpp"
    "SRC/vendor/glm/ext/vector_double4_precision.hpp"
    "SRC/vendor/glm/ext/vector_float1.hpp"
    "SRC/vendor/glm/ext/vector_float1_precision.hpp"
    "SRC/vendor/glm/ext/vector_float2.hpp"
    "SRC/vendor/glm/ext/vector_float2_precision.hpp"
    "SRC/vendor/glm/ext/vector_float3.hpp"
    "SRC/vendor/glm/ext/vector_float3_precision.hpp"
    "SRC/vendor/glm/ext/vector_float4.hpp"
    "SRC/vendor/glm/ext/vector_float4_precision.hpp"
    "SRC/vendor/glm/ext/vector_int1.hpp"
    "SRC/vendor/glm/ext/vector_int1_precision.hpp"
    "SRC/vendor/glm/ext/vector_int2.hpp"
    "SRC/vendor/glm/ext/vector_int2_precision.hpp"
    "SRC/vendor/glm/ext/vector_int3.hpp"
    "SRC/vendor/glm/ext/vector_int3_precision.hpp"
    "SRC/vendor/glm/ext/vector_int4.hpp"
    "SRC/vendor/glm/ext/vector_int4_precision.hpp"
    "SRC/vendor/glm/ext/vector_relational.hpp"
    "SRC/vendor/glm/ext/vector_relational.inl"
    "SRC/vendor/glm/ext/vector_uint1.hpp"
    "SRC/vendor/glm/ext/vector_uint1_precision.hpp"
    "SRC/vendor/glm/ext/vector_uint2.hpp"
    "SRC/vendor/glm/ext/vector_uint2_precision.hpp"
    "SRC/vendor/glm/ext/vector_uint3.hpp"
    "SRC/vendor/glm/ext/vector_uint3_precision.hpp"
    "SRC/vendor/glm/ext/vector_uint4.hpp"
    "SRC/vendor/glm/ext/vector_uint4_precision.hpp"
    "SRC/vendor/glm/ext/vector_ulp.hpp"
    "SRC/vendor/glm/ext/vector_ulp.inl"
    "SRC/vendor/glm/fwd.hpp"
    "SRC/vendor/glm/geometric.hpp"
    "SRC/vendor/glm/glm.hpp"
    "SRC/vendor/glm/gtc/bitfield.hpp"
    "SRC/vendor/glm/gtc/bitfield.inl"
    "SRC/vendor/glm/gtc/color_space.hpp"
    "SRC/vendor/glm/gtc/color_space.inl"
    "SRC/vendor/glm/gtc/constants.hpp"
    "SRC/vendor/glm/gtc/constants.inl"
    "SRC/vendor/glm/gtc/epsilon.hpp"
    "SRC/vendor/glm/gtc/epsilon.inl"
    "SRC/vendor/glm/gtc/integer.hpp"
    "SRC/vendor/glm/gtc/integer.inl"
    "SRC/vendor/glm/gtc/matrix_access.hpp"
    "SRC/vendor/glm/gtc/matrix_access.inl"
    "SRC/vendor/glm/gtc/matrix_integer.hpp"
    "SRC/vendor/glm/gtc/matrix_inverse.hpp"
    "SRC/vendor/glm/gtc/matrix_inverse.inl"
    "SRC/vendor/glm/gtc/matrix_transform.hpp"
    "SRC/vendor/glm/gtc/matrix_transform.inl"
    "SRC/vendor/glm/gtc/noise.hpp"
    "SRC/vendor/glm/gtc/noise.inl"
    "SRC/vendor/glm/gtc/packing.hpp"
    "SRC/vendor/glm/gtc/packing.inl"
    "SRC/vendor/glm/gtc/quaternion.hpp"
    "SRC/vendor/glm/gtc/quaternion.inl"
    "SRC/vendor/glm/gtc/quaternion_simd.inl"
    "SRC/vendor/glm/gtc/random.hpp"
    "SRC/vendor/glm/gtc/random.inl"
    "SRC/vendor/glm/gtc/reciprocal.hpp"
    "SRC/vendor/glm/gtc/reciprocal.inl"
    "SRC/vendor/glm/gtc/round.hpp"
    "SRC/vendor/glm/gtc/round.inl"
    "SRC/vendor/glm/gtc/type_aligned.hpp"
    "SRC/vendor/glm/gtc/type_precision.hpp"
    "SRC/vendor/glm/gtc/type_precision.inl"
    "SRC/vendor/glm/gtc/type_ptr.hpp"
    "SRC/vendor/glm/gtc/type_ptr.inl"
    "SRC/vendor/glm/gtc/ulp.hpp"
    "SRC/vendor/glm/gtc/ulp.inl"
    "SRC/vendor/glm/gtc/vec1.hpp"
    "SRC/vendor/glm/gtx/associated_min_max.hpp"
    "SRC/vendor/glm/gtx/associated_min_max.inl"
    "SRC/vendor/glm/gtx/bit.hpp"
    "SRC/vendor/glm/gtx/bit.inl"
    "SRC/vendor/glm/gtx/closest_point.hpp"
    "SRC/vendor/glm/gtx/closest_point.inl"
    "SRC/vendor/glm/gtx/color_encoding.hpp"
    "SRC/vendor/glm/gtx/color_encoding.inl"
    "SRC/vendor/glm/gtx/color_space.hpp"
    "SRC/vendor/glm/gtx/color_space.inl"
    "SRC/vendor/glm/gtx/color_space_YCoCg.hpp"
    "SRC/vendor/glm/gtx/color_space_YCoCg.inl"
    "SRC/vendor/glm/gtx/common.hpp"
    "SRC/vendor/glm/gtx/common.inl"
    "SRC/vendor/glm/gtx/compatibility.hpp"
    "SRC/vendor/glm/gtx/compatibility.inl"
    "SRC/vendor/glm/gtx/component_wise.hpp"
    "SRC/vendor/glm/gtx/component_wise.inl"
    "SRC/vendor/glm/gtx/dual_quaternion.hpp"
    "SRC/vendor/glm/gtx/dual_quaternion.inl"
    "SRC/vendor/glm/gtx/easing.hpp"
    "SRC/vendor/glm/gtx/easing.inl"
    "SRC/vendor/glm/gtx/euler_angles.hpp"
    "SRC/vendor/glm/gtx/euler_angles.inl"
    "SRC/vendor/glm/gtx/extend.hpp"
    "SRC/vendor/glm/gtx/extend.inl"
    "SRC/vendor/glm/gtx/extended_min_max.hpp"
    "SRC/vendor/glm/gtx/extended_min_max.inl"
    "SRC/vendor/glm/gtx/exterior_product.hpp"
    "SRC/vendor/glm/gtx/exterior_product.inl"
    "SRC/vendor/glm/gtx/fast_exponential.hpp"
    "SRC/vendor/glm/gtx/fast_exponential.inl"
    "SRC/vendor/glm/gtx/fast_square_root.hpp"
    "SRC/vendor/glm/gtx/fast_square_root.inl"
    "SRC/vendor/glm/gtx/fast_trigonometry.hpp"
    "SRC/vendor/glm/gtx/fast_trigonometry.inl"
    "SRC/vendor/glm/gtx/float_notmalize.inl"
    "SRC/vendor/glm/gtx/functions.hpp"
    "SRC/vendor/glm/gtx/functions.inl"
    "SRC/vendor/glm/gtx/gradient_paint.hpp"
    "SRC/vendor/glm/gtx/gradient_paint.inl"
    "SRC/vendor/glm/gtx/handed_coordinate_space.hpp"
    "SRC/vendor/glm/gtx/handed_coordinate_space.inl"
    "SRC/vendor/glm/gtx/hash.hpp"
    "SRC/vendor/glm/gtx/hash.inl"
    "SRC/vendor/glm/gtx/integer.hpp"
    "SRC/vendor/glm/gtx/integer.inl"
    "SRC/vendor/glm/gtx/intersect.hpp"
    "SRC/vendor/glm/gtx/intersect.inl"
    "SRC/vendor/glm/gtx/io.hpp"
    "SRC/vendor/glm/gtx/io.inl"
    "SRC/vendor/glm/gtx/log_base.hpp"
    "SRC/vendor/glm/gtx/log_base.inl"
    "SRC/vendor/glm/gtx/matrix_cross_product.hpp"
    "SRC/vendor/glm/gtx/matrix_cross_product.inl"
    "SRC/vendor/glm/gtx/matrix_decompose.hpp"
    "SRC/vendor/glm/gtx/matrix_decompose.inl"
    "SRC/vendor/glm/gtx/matrix_factorisation.hpp"
    "SRC/vendor/glm/gtx/matrix_factorisation.inl"
    "SRC/vendor/glm/gtx/matrix_interpolation.hpp"
    "SRC/vendor/glm/gtx/matrix_interpolation.inl"
    "SRC/vendor/glm/gtx/matrix_major_storage.hpp"
    "SRC/vendor/glm/gtx/matrix_major_storage.inl"
    "SRC/vendor/glm/gtx/matrix_operation.hpp"
    "SRC/vendor/glm/gtx/matrix_operation.inl"
    "SRC/vendor/glm/gtx/matrix_query.hpp"
    "SRC/vendor/glm/gtx/matrix_query.inl"
    "SRC/vendor/glm/gtx/matrix_transform_2d.hpp"
    "SRC/vendor/glm/gtx/matrix_transform_2d.inl"
    "SRC/vendor/glm/gtx/mixed_product.hpp"
    "SRC/vendor/glm/gtx/mixed_product.inl"
    "SRC/vendor/glm/gtx/norm.hpp"
    "SRC/vendor/glm/gtx/norm.inl"
    "SRC/vendor/glm/gtx/normal.hpp"
    "SRC/vendor/glm/gtx/normal.inl"
    "SRC/vendor/glm/gtx/normalize_dot.hpp"
    "SRC/vendor/glm/gtx/normalize_dot.inl"
    "SRC/vendor/glm/gtx/number_precision.hpp"
    "SRC/vendor/glm/gtx/number_precision.inl"
    "SRC/vendor/glm/gtx/optimum_pow.hpp"
    "SRC/vendor/glm/gtx/optimum_pow.inl"
    "SRC/vendor/glm/gtx/orthonormalize.hpp"
    "SRC/vendor/glm/gtx/orthonormalize.inl"
    "SRC/vendor/glm/gtx/perpendicular.hpp"
    "SRC/vendor/glm/gtx/perpendicular.inl"
    "SRC/vendor/glm/gtx/polar_coordinates.hpp"
    "SRC/vendor/glm/gtx/polar_coordinates.inl"
    "SRC/vendor/glm/gtx/projection.hpp"
    "SRC/vendor/glm/gtx/projection.inl"
    "SRC/vendor/glm/gtx/quaternion.hpp"
    "SRC/vendor/glm/gtx/quaternion.inl"
    "SRC/vendor/glm/gtx/range.hpp"
    "SRC/vendor/glm/gtx/raw_data.hpp"
    "SRC/vendor/glm/gtx/raw_data.inl"
    "SRC/vendor/glm/gtx/rotate_normalized_axis.hpp"
    "SRC/vendor/glm/gtx/rotate_normalized_axis.inl"
    "SRC/vendor/glm/gtx/rotate_vector.hpp"
    "SRC/vendor/glm/gtx/rotate_vector.inl"
    "SRC/vendor/glm/gtx/scalar_multiplication.hpp"
    "SRC/vendor/glm/gtx/scalar_relational.hpp"
    "SRC/vendor/glm/gtx/scalar_relational.inl"
    "SRC/vendor/glm/gtx/spline.hpp"
    "SRC/vendor/glm/gtx/spline.inl"
    "SRC/vendor/glm/gtx/std_based_type.hpp"
    "SRC/vendor/glm/gtx/std_based_type.inl"
    "SRC/vendor/glm/gtx/string_cast.hpp"
    "SRC/vendor/glm/gtx/string_cast.inl"
    "SRC/vendor/glm/gtx/texture.hpp"
    "SRC/vendor/glm/gtx/texture.inl"
    "SRC/vendor/glm/gtx/transform.hpp"
    "SRC/vendor/glm/gtx/transform.inl"
    "SRC/vendor/glm/gtx/transform2.hpp"
    "SRC/vendor/glm/gtx/transform2.inl"
    "SRC/vendor/glm/gtx/type_aligned.hpp"
    "SRC/vendor/glm/gtx/type_aligned.inl"
    "SRC/vendor/glm/gtx/type_trait.hpp"
    "SRC/vendor/glm/gtx/type_trait.inl"
    "SRC/vendor/glm/gtx/vec_swizzle.hpp"
    "SRC/vendor/glm/gtx/vector_angle.hpp"
    "SRC/vendor/glm/gtx/vector_angle.inl"
    "SRC/vendor/glm/gtx/vector_query.hpp"
    "SRC/vendor/glm/gtx/vector_query.inl"
    "SRC/vendor/glm/gtx/wrap.hpp"
    "SRC/vendor/glm/gtx/wrap.inl"
    "SRC/vendor/glm/integer.hpp"
    "SRC/vendor/glm/mat2x2.hpp"
    "SRC/vendor/glm/mat2x3.hpp"
    "SRC/vendor/glm/mat2x4.hpp"
    "SRC/vendor/glm/mat3x2.hpp"
    "SRC/vendor/glm/mat3x3.hpp"
    "SRC/vendor/glm/mat3x4.hpp"
    "SRC/vendor/glm/mat4x2.hpp"
    "SRC/vendor/glm/mat4x3.hpp"
    "SRC/vendor/glm/mat4x4.hpp"
    "SRC/vendor/glm/matrix.hpp"
    "SRC/vendor/glm/packing.hpp"
    "SRC/vendor/glm/simd/common.h"
    "SRC/vendor/glm/simd/exponential.h"
    "SRC/vendor/glm/simd/geometric.h"
    "SRC/vendor/glm/simd/integer.h"
    "SRC/vendor/glm/simd/matrix.h"
    "SRC/vendor/glm/simd/packing.h"
    "SRC/vendor/glm/simd/platform.h"
    "SRC/vendor/glm/simd/trigonometric.h"
    "SRC/vendor/glm/simd/vector_relational.h"
    "SRC/vendor/glm/trigonometric.hpp"
    "SRC/vendor/glm/vec2.hpp"
    "SRC/vendor/glm/vec3.hpp"
    "SRC/vendor/glm/vec4.hpp"
    "SRC/vendor/glm/vector_relational.hpp"
    "SRC/vendor/imgui/imconfig.h"
    "SRC/vendor/imgui/imgui.h"
    "SRC/vendor/imgui/imgui_impl_glfw_gl3.h"
    "SRC/vendor/imgui/imgui_internal.h"
    "SRC/vendor/imgui/stb_rect_pack.h"
    "SRC/vendor/imgui/stb_textedit.h"
    "SRC/vendor/imgui/stb_truetype.h"
    "SRC/vendor/stb_image/stb_image.h"
    "SRC/VertexArray.h"
    "SRC/VertexBuffer.h"
    "SRC/VertexBufferLayout.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "SRC/Application.cpp"
    "SRC/IndexBuffer.cpp"
    "SRC/Renderer.cpp"
    "SRC/Shader.cpp"
    "SRC/tests/test.cpp"
    "SRC/tests/testClearColor.cpp"
    "SRC/tests/TestTexture2D.cpp"
    "SRC/Texture.cpp"
    "SRC/VertexBufferLayout.cpp"
    "SRC/vendor/glm/detail/glm.cpp"
    "SRC/vendor/imgui/imgui.cpp"
    "SRC/vendor/imgui/imgui_draw.cpp"
    "SRC/vendor/imgui/imgui_impl_glfw_gl3.cpp"
    "SRC/vendor/stb_image/stb_image.cpp"
    "SRC/VertexArray.cpp"
    "SRC/VertexBuffer.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${no_group_source_files}
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE OpenGLProject)

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/SRC/vendor;"
        "${CMAKE_CURRENT_SOURCE_DIR}/home/dex/Documents/projects/cpp/OGlProj/Depandencies/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/home/dex/Documents/projects/cpp/OGlProj/Depandencies/GLEW/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/%(AdditionalDependencies)"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/SRC/vendor;"
        "${CMAKE_CURRENT_SOURCE_DIR}/home/dex/Documents/projects/cpp/OGlProj/Depandencies/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/home/dex/Documents/projects/cpp/OGlProj/Depandencies/GLEW/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/%(AdditionalDependencies)"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "GLEW_STATIC;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /std:c++17;
                /Od
            >
            $<$<CONFIG:Release>:
                /O2;
                /Oi;
                /Gy
            >
            /permissive-;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od
            >
            $<$<CONFIG:Release>:
                /O2;
                /Oi;
                /Gy
            >
            /permissive-;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /Ot;
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG:FULL
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG:FULL
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
         "GLEW;"
        "GL;"
        "GLU;"
        "glfw3;"
        "m;"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "GLEW;"
        "GL;"
        "GLU;"
        "glfw3;"
        "m;"
        # "glew32"
    )
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_link_directories(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "${CMAKE_SOURCE_DIR}/Depandencies/GLEW/bin/Release/Win32;"
            "${CMAKE_SOURCE_DIR}/Depandencies/lib-vc2019"
        ">"
        "$<$<CONFIG:Release>:"
            "${CMAKE_SOURCE_DIR}/Depandencies/GLEW/lib/Release/Win32;"
            "${CMAKE_SOURCE_DIR}/Depandencies/lib-vc2015"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_link_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_SOURCE_DIR}/Depandencies/GLEW/lib/Release/Win32;"
        "${CMAKE_SOURCE_DIR}/Depandencies/lib-vc2015"
    )
endif()

