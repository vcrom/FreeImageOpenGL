#-------------------------------------------------
#
# Project created by QtCreator 2015-12-31T15:45:11
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = FreeImageOpenGL
TEMPLATE = app

INCLUDEPATH += $$_PRO_FILE_PWD_/include
win32: LIBS += $$_PRO_FILE_PWD_/lib64/FreeImage.lib $$_PRO_FILE_PWD_/lib64/FreeImagePlus.lib
unix: LIBS += -L$$_PRO_FILE_PWD_/lib64

CONFIG(release, debug|release): DESTDIR = $$OUT_PWD/release
CONFIG(debug, debug|release): DESTDIR = $$OUT_PWD/debug
CONFIG(debug, debug|release): DEFINES += _DEBUG

DllFiles.path = $$DESTDIR
DllFiles.files += $$files(dll/*.dll)

INSTALLS += DllFiles

SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    fimage.cpp \
    include/src/glad.c \
    glslshader.cpp \
    renderableobject.cpp \
    screenquad.cpp \
    include/glm/detail/dummy.cpp \
    include/glm/detail/glm.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    image.h \
    fimage.h \
    include/glad/glad.h \
    glslshader.h \
    renderableobject.h \
    screenquad.h \
    utils.h \
    include/FreeImage/FreeImage.h \
    include/FreeImage/FreeImagePlus.h \
    include/glm/detail/_features.hpp \
    include/glm/detail/_fixes.hpp \
    include/glm/detail/_noise.hpp \
    include/glm/detail/_swizzle.hpp \
    include/glm/detail/_swizzle_func.hpp \
    include/glm/detail/_vectorize.hpp \
    include/glm/detail/func_common.hpp \
    include/glm/detail/func_exponential.hpp \
    include/glm/detail/func_geometric.hpp \
    include/glm/detail/func_integer.hpp \
    include/glm/detail/func_matrix.hpp \
    include/glm/detail/func_packing.hpp \
    include/glm/detail/func_trigonometric.hpp \
    include/glm/detail/func_vector_relational.hpp \
    include/glm/detail/intrinsic_common.hpp \
    include/glm/detail/intrinsic_exponential.hpp \
    include/glm/detail/intrinsic_geometric.hpp \
    include/glm/detail/intrinsic_integer.hpp \
    include/glm/detail/intrinsic_matrix.hpp \
    include/glm/detail/intrinsic_trigonometric.hpp \
    include/glm/detail/intrinsic_vector_relational.hpp \
    include/glm/detail/precision.hpp \
    include/glm/detail/setup.hpp \
    include/glm/detail/type_float.hpp \
    include/glm/detail/type_gentype.hpp \
    include/glm/detail/type_half.hpp \
    include/glm/detail/type_int.hpp \
    include/glm/detail/type_mat.hpp \
    include/glm/detail/type_mat2x2.hpp \
    include/glm/detail/type_mat2x3.hpp \
    include/glm/detail/type_mat2x4.hpp \
    include/glm/detail/type_mat3x2.hpp \
    include/glm/detail/type_mat3x3.hpp \
    include/glm/detail/type_mat3x4.hpp \
    include/glm/detail/type_mat4x2.hpp \
    include/glm/detail/type_mat4x3.hpp \
    include/glm/detail/type_mat4x4.hpp \
    include/glm/detail/type_vec.hpp \
    include/glm/detail/type_vec1.hpp \
    include/glm/detail/type_vec2.hpp \
    include/glm/detail/type_vec3.hpp \
    include/glm/detail/type_vec4.hpp \
    include/glm/gtc/bitfield.hpp \
    include/glm/gtc/color_space.hpp \
    include/glm/gtc/constants.hpp \
    include/glm/gtc/epsilon.hpp \
    include/glm/gtc/integer.hpp \
    include/glm/gtc/matrix_access.hpp \
    include/glm/gtc/matrix_integer.hpp \
    include/glm/gtc/matrix_inverse.hpp \
    include/glm/gtc/matrix_transform.hpp \
    include/glm/gtc/noise.hpp \
    include/glm/gtc/packing.hpp \
    include/glm/gtc/quaternion.hpp \
    include/glm/gtc/random.hpp \
    include/glm/gtc/reciprocal.hpp \
    include/glm/gtc/round.hpp \
    include/glm/gtc/type_precision.hpp \
    include/glm/gtc/type_ptr.hpp \
    include/glm/gtc/ulp.hpp \
    include/glm/gtc/vec1.hpp \
    include/glm/gtx/associated_min_max.hpp \
    include/glm/gtx/bit.hpp \
    include/glm/gtx/closest_point.hpp \
    include/glm/gtx/color_space.hpp \
    include/glm/gtx/color_space_YCoCg.hpp \
    include/glm/gtx/common.hpp \
    include/glm/gtx/compatibility.hpp \
    include/glm/gtx/component_wise.hpp \
    include/glm/gtx/dual_quaternion.hpp \
    include/glm/gtx/euler_angles.hpp \
    include/glm/gtx/extend.hpp \
    include/glm/gtx/extented_min_max.hpp \
    include/glm/gtx/fast_exponential.hpp \
    include/glm/gtx/fast_square_root.hpp \
    include/glm/gtx/fast_trigonometry.hpp \
    include/glm/gtx/gradient_paint.hpp \
    include/glm/gtx/handed_coordinate_space.hpp \
    include/glm/gtx/hash.hpp \
    include/glm/gtx/integer.hpp \
    include/glm/gtx/intersect.hpp \
    include/glm/gtx/io.hpp \
    include/glm/gtx/log_base.hpp \
    include/glm/gtx/matrix_cross_product.hpp \
    include/glm/gtx/matrix_decompose.hpp \
    include/glm/gtx/matrix_interpolation.hpp \
    include/glm/gtx/matrix_major_storage.hpp \
    include/glm/gtx/matrix_operation.hpp \
    include/glm/gtx/matrix_query.hpp \
    include/glm/gtx/matrix_transform_2d.hpp \
    include/glm/gtx/mixed_product.hpp \
    include/glm/gtx/norm.hpp \
    include/glm/gtx/normal.hpp \
    include/glm/gtx/normalize_dot.hpp \
    include/glm/gtx/number_precision.hpp \
    include/glm/gtx/optimum_pow.hpp \
    include/glm/gtx/orthonormalize.hpp \
    include/glm/gtx/perpendicular.hpp \
    include/glm/gtx/polar_coordinates.hpp \
    include/glm/gtx/projection.hpp \
    include/glm/gtx/quaternion.hpp \
    include/glm/gtx/range.hpp \
    include/glm/gtx/raw_data.hpp \
    include/glm/gtx/rotate_normalized_axis.hpp \
    include/glm/gtx/rotate_vector.hpp \
    include/glm/gtx/scalar_multiplication.hpp \
    include/glm/gtx/scalar_relational.hpp \
    include/glm/gtx/simd_mat4.hpp \
    include/glm/gtx/simd_quat.hpp \
    include/glm/gtx/simd_vec4.hpp \
    include/glm/gtx/spline.hpp \
    include/glm/gtx/std_based_type.hpp \
    include/glm/gtx/string_cast.hpp \
    include/glm/gtx/transform.hpp \
    include/glm/gtx/transform2.hpp \
    include/glm/gtx/type_aligned.hpp \
    include/glm/gtx/vector_angle.hpp \
    include/glm/gtx/vector_query.hpp \
    include/glm/gtx/wrap.hpp \
    include/glm/common.hpp \
    include/glm/exponential.hpp \
    include/glm/ext.hpp \
    include/glm/fwd.hpp \
    include/glm/geometric.hpp \
    include/glm/glm.hpp \
    include/glm/integer.hpp \
    include/glm/mat2x2.hpp \
    include/glm/mat2x3.hpp \
    include/glm/mat2x4.hpp \
    include/glm/mat3x2.hpp \
    include/glm/mat3x3.hpp \
    include/glm/mat3x4.hpp \
    include/glm/mat4x2.hpp \
    include/glm/mat4x3.hpp \
    include/glm/mat4x4.hpp \
    include/glm/matrix.hpp \
    include/glm/packing.hpp \
    include/glm/trigonometric.hpp \
    include/glm/vec2.hpp \
    include/glm/vec3.hpp \
    include/glm/vec4.hpp \
    include/glm/vector_relational.hpp \
    include/KHR/khrplatform.h

FORMS    += mainwindow.ui

DISTFILES +=
