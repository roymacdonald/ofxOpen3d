# All variables and this file are optional, if they are not present the PG and the
# makefiles will try to parse the correct values from the file system.
#
# Variables that specify exclusions can use % as a wildcard to specify that anything in
# that position will match. A partial path can also be specified to, for example, exclude
# a whole folder from the parsed paths from the file system
#
# Variables can be specified using = or +=
# = will clear the contents of that variable both specified from the file or the ones parsed
# from the file system
# += will add the values to the previous ones in the file or the ones parsed from the file 
# system
# 
# The PG can be used to detect errors in this file, just create a new project with this addon 
# and the PG will write to the console the kind of error and in which line it is

meta:
	ADDON_NAME = ofxOpen3d
	ADDON_DESCRIPTION = 
	ADDON_AUTHOR = @roymacdonald
	ADDON_TAGS = "addon" "open3d"
	ADDON_URL = http://github.com/roymacdonald/ofxOpen3d

common:
	# dependencies with other addons, a list of them separated by spaces 
	# or use += in several lines
	# ADDON_DEPENDENCIES =
	
	# include search paths, this will be usually parsed from the file system
	# but if the addon or addon libraries need special search paths they can be
	# specified here separated by spaces or one per line using +=
	
	
	

	ADDON_INCLUDES = libs/Open3d/include
	ADDON_INCLUDES += /usr/local/include/eigen3
	ADDON_INCLUDES += /usr/local/include
	

	

	# any special flag that should be passed to the compiler when using this
	# addon
	# ADDON_CFLAGS =
	
	# any special flag that should be passed to the compiler for c++ files when 
	# using this addon
	# ADDON_CPPFLAGS =
	
	# any special flag that should be passed to the linker when using this
	# addon, also used for system libraries with -lname
	# ADDON_LDFLAGS =
	
	# source files, these will be usually parsed from the file system looking
	# in the src folders in libs and the root of the addon. if your addon needs
	# to include files in different places or a different set of files per platform
	# they can be specified here
	# ADDON_SOURCES =
	
	# source files that will be included as C files explicitly
	# ADDON_C_SOURCES = 
	
	# source files that will be included as header files explicitly
	# ADDON_HEADER_SOURCES = 
	
	# source files that will be included as c++ files explicitly
	# ADDON_CPP_SOURCES = 
	
	# source files that will be included as objective c files explicitly
	# ADDON_OBJC_SOURCES = 
	
	# derines that will be passed to the compiler when including this addon
	# ADDON_DEFINES
	
	ADDON_DEFINES='_GLIBCXX_USE_CXX11_ABI=1'
	ADDON_DEFINES+=OPEN3D_STATIC
	ADDON_DEFINES+='FMT_HEADER_ONLY=0'
	ADDON_DEFINES+='FMT_USE_WINDOWS_H=0' 
	ADDON_DEFINES+='FMT_STRING_ALIAS=1'

	# some addons need resources to be copied to the bin/data folder of the project
	# specify here any files that need to be copied, you can use wildcards like * and ?
	# ADDON_DATA = 
	
	# when parsing the file system looking for libraries exclude this for all or
	# a specific platform
	# ADDON_LIBS_EXCLUDE =
	
	# binary libraries, these will be usually parsed from the file system but some 
	# libraries need to passed to the linker in a specific order/
	# 
	# For example in the ofxOpenCV addon we do something like this:
	#
	# ADDON_LIBS =
	# ADDON_LIBS += libs/opencv/lib/linuxarmv6l/libopencv_legacy.a
	# ADDON_LIBS += libs/opencv/lib/linuxarmv6l/libopencv_calib3d.a
	# ...
	
	
linux64:
	# linux only, any library that should be included in the project using
	# pkg-config
	# ADDON_PKG_CONFIG_LIBRARIES =
vs:
	# After compiling copy the following dynamic libraries to the executable directory
	# only windows visual studio
	# ADDON_DLLS_TO_COPY = 
	
linuxarmv6l:
linuxarmv7l:
android/armeabi:	
android/armeabi-v7a:	
osx:

ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_assimp.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_blas_mkl_intel_ilp64.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_blas_mkl_tbb_thread.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_blas_tbb_static.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_civetweb_civetweb-cpp.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_civetweb_civetweb.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_curl.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_embree_embree3.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_embree_embree_sse42.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_embree_lexers.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_embree_math.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_embree_simd.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_embree_sys.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_embree_tasking.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_backend.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_bluegl.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_bluevk.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_filabridge.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_filaflat.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_filamat_lite.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_filament.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_filameshio.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_geometry.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_ibl.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_image.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_meshoptimizer.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_smol-v.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_utils.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_filament_vkshaders.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_fmt.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_glew.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_glfw.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_imgui.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_ippicv_ippicv.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_ippicv_ippiw.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_jpeg.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_jsoncpp.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_liblzf.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_png.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_qhull_r.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_qhullcpp.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_rply.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_tbb_tbb_static.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_tbb_tbbmalloc_static.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_tinyfiledialogs.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_vtk_vtkCommonCore-9.1.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_vtk_vtkCommonDataModel-9.1.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_vtk_vtkCommonExecutionModel-9.1.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_vtk_vtkCommonMath-9.1.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_vtk_vtkCommonMisc-9.1.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_vtk_vtkCommonSystem-9.1.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_vtk_vtkCommonTransforms-9.1.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_vtk_vtkFiltersCore-9.1.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_vtk_vtkFiltersGeneral-9.1.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_vtk_vtkkissfft-9.1.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_vtk_vtkpugixml-9.1.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_vtk_vtksys-9.1.a
# ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_webrtc_webrtc.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_webrtc_webrtc_extra.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_zeromq.a
ADDON_LIBS += libs/Open3d/lib/osx/libOpen3D_3rdparty_zlib.a

ADDON_LIBS += /usr/local/lib/libomp.dylib

# -fobjc-link-runtime
# -Wl,-search_paths_first
# -Wl,-headerpad_max_install_names
# /usr/local/lib/libOpen3D.a
# /usr/local/lib/libOpen3D_3rdparty_assimp.a
# /usr/local/lib/libOpen3D_3rdparty_jpeg.a
# /usr/local/lib/libOpen3D_3rdparty_jsoncpp.a
# /usr/local/lib/libOpen3D_3rdparty_liblzf.a
# /usr/local/lib/libOpen3D_3rdparty_curl.a
# /usr/local/lib/libOpen3D_3rdparty_png.a
# /usr/local/lib/libOpen3D_3rdparty_zlib.a
# /usr/local/lib/libOpen3D_3rdparty_rply.a
# /usr/local/lib/libOpen3D_3rdparty_tinyfiledialogs.a
# /usr/local/lib/libOpen3D_3rdparty_qhullcpp.a
# /usr/local/lib/libOpen3D_3rdparty_qhull_r.a
# /usr/local/lib/libOpen3D_3rdparty_imgui.a
# /usr/local/lib/libOpen3D_3rdparty_zeromq.a
# /usr/local/lib/libOpen3D_3rdparty_vtk_vtkFiltersGeneral-9.1.a
# /usr/local/lib/libOpen3D_3rdparty_vtk_vtkFiltersCore-9.1.a
# /usr/local/lib/libOpen3D_3rdparty_vtk_vtkCommonExecutionModel-9.1.a
# /usr/local/lib/libOpen3D_3rdparty_vtk_vtkCommonDataModel-9.1.a
# /usr/local/lib/libOpen3D_3rdparty_vtk_vtkCommonMath-9.1.a
# /usr/local/lib/libOpen3D_3rdparty_vtk_vtkCommonMisc-9.1.a
# /usr/local/lib/libOpen3D_3rdparty_vtk_vtkCommonSystem-9.1.a
# /usr/local/lib/libOpen3D_3rdparty_vtk_vtkCommonTransforms-9.1.a
# /usr/local/lib/libOpen3D_3rdparty_vtk_vtkCommonCore-9.1.a
# /usr/local/lib/libOpen3D_3rdparty_vtk_vtkkissfft-9.1.a
# /usr/local/lib/libOpen3D_3rdparty_vtk_vtkpugixml-9.1.a
# /usr/local/lib/libOpen3D_3rdparty_vtk_vtksys-9.1.a
# /usr/local/lib/libOpen3D_3rdparty_tbb_tbb_static.a
# /usr/local/lib/libOpen3D_3rdparty_tbb_tbbmalloc_static.a
# /usr/local/lib/libOpen3D_3rdparty_blas_mkl_intel_ilp64.a
# /usr/local/lib/libOpen3D_3rdparty_blas_mkl_tbb_thread.a
# /usr/local/lib/libOpen3D_3rdparty_blas_mkl_core.a
# /usr/local/lib/libOpen3D_3rdparty_blas_tbb_static.a
# /usr/local/lib/libOpen3D_3rdparty_embree_embree3.a
# /usr/local/lib/libOpen3D_3rdparty_embree_embree_sse42.a
# /usr/local/lib/libOpen3D_3rdparty_embree_simd.a
# /usr/local/lib/libOpen3D_3rdparty_embree_lexers.a
# /usr/local/lib/libOpen3D_3rdparty_embree_sys.a
# /usr/local/lib/libOpen3D_3rdparty_embree_math.a
# /usr/local/lib/libOpen3D_3rdparty_embree_tasking.a
# /usr/local/lib/libOpen3D_3rdparty_webrtc_webrtc.a
# /usr/local/lib/libOpen3D_3rdparty_webrtc_webrtc_extra.a
# /usr/local/lib/libOpen3D_3rdparty_civetweb_civetweb.a
# /usr/local/lib/libOpen3D_3rdparty_civetweb_civetweb-cpp.a
# /usr/local/lib/libomp.dylib
# /usr/local/lib/libOpen3D_3rdparty_ippicv_ippiw.a
# /usr/local/lib/libOpen3D_3rdparty_ippicv_ippicv.a
# /usr/local/lib/libOpen3D_3rdparty_glew.a
# /usr/local/lib/libOpen3D_3rdparty_glfw.a
# /usr/local/lib/libOpen3D_3rdparty_fmt.a
# /usr/local/lib/libOpen3D_3rdparty_filament_filameshio.a
# /usr/local/lib/libOpen3D_3rdparty_filament_filament.a
# /usr/local/lib/libOpen3D_3rdparty_filament_filamat_lite.a
# /usr/local/lib/libOpen3D_3rdparty_filament_filaflat.a
# /usr/local/lib/libOpen3D_3rdparty_filament_filabridge.a
# /usr/local/lib/libOpen3D_3rdparty_filament_geometry.a
# /usr/local/lib/libOpen3D_3rdparty_filament_backend.a
# /usr/local/lib/libOpen3D_3rdparty_filament_bluegl.a
# /usr/local/lib/libOpen3D_3rdparty_filament_bluevk.a
# /usr/local/lib/libOpen3D_3rdparty_filament_ibl.a
# /usr/local/lib/libOpen3D_3rdparty_filament_image.a
# /usr/local/lib/libOpen3D_3rdparty_filament_meshoptimizer.a
# /usr/local/lib/libOpen3D_3rdparty_filament_smol-v.a
# /usr/local/lib/libOpen3D_3rdparty_filament_utils.a
# /usr/local/lib/libOpen3D_3rdparty_filament_vkshaders.a

ADDON_FRAMEWORKS = SystemConfiguration
ADDON_FRAMEWORKS += Cocoa
ADDON_FRAMEWORKS += IOKit
ADDON_FRAMEWORKS += CoreFoundation
ADDON_FRAMEWORKS += CoreVideo
ADDON_FRAMEWORKS += QuartzCore
ADDON_FRAMEWORKS += OpenGL
ADDON_FRAMEWORKS += Metal
ADDON_FRAMEWORKS += AppKit
ADDON_FRAMEWORKS += OpenGL









	# osx/iOS only, any framework that should be included in the project
	# 
ios:
tvos:

