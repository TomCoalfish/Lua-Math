
//          Copyright RedPortal, mujjingun 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef _MGCPP_SYSTEM_ERROR_CODE_
#define _MGCPP_SYSTEM_ERROR_CODE_

#include <string>
#include <system_error>
#include <type_traits>

#include <mgcpp/system/cublas_error.hpp>
#include <mgcpp/system/cuda_error.hpp>
#include <mgcpp/system/cufft_error.hpp>
#include <mgcpp/system/mgblas_error.hpp>

namespace mgcpp {
enum class status_t { success = 0 };

std::error_condition make_error_condition(mgcpp::status_t err) noexcept;
}  // namespace mgcpp

namespace std {
template <>
struct is_error_condition_enum<mgcpp::status_t> : public std::true_type {};
}  // namespace std

#endif
