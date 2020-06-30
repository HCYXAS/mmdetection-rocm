// modified from
// https://github.com/facebookresearch/detectron2/blob/master/detectron2/layers/csrc/vision.cpp
#include <torch/extension.h>

#ifdef WITH_HIP
#include <hip/hip_runtime_api.h>
//int get_hiprt_version() { return HIPRT_VERSION; }
#endif

std::string get_compiling_hip_version() {
#ifdef WITH_HIP
  std::ostringstream oss;

  // copied from
  // https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/cuda/detail/HIPHooks.cpp#L231
  auto printHipStyleVersion = [&](int v) {
    oss << (v / 1000) << "." << (v / 10 % 100);
    if (v % 10 != 0) {
      oss << "." << (v % 10);
    }
  };
  //printHipStyleVersion(get_hiprt_version());
  return oss.str();
#else
  return std::string("not available");
#endif
}

// similar to
// https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/Version.cpp
std::string get_compiler_version() {
  std::ostringstream ss;
#if defined(__GNUC__)
#ifndef __clang__
  { ss << "GCC " << __GNUC__ << "." << __GNUC_MINOR__; }
#endif
#endif

#if defined(__clang_major__)
  {
    ss << "clang " << __clang_major__ << "." << __clang_minor__ << "."
       << __clang_patchlevel__;
  }
#endif

#if defined(_MSC_VER)
  { ss << "MSVC " << _MSC_FULL_VER; }
#endif
  return ss.str();
}

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
  m.def("get_compiler_version", &get_compiler_version, "get_compiler_version");
  m.def("get_compiling_hip_version", &get_compiling_hip_version,
        "get_compiling_hip_version");
}