
//          Copyright RedPortal, mujjingun 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <gtest/gtest.h>

#define ERROR_CHECK_EXCEPTION true

#include <mgcpp/matrix/column_view.hpp>
#include <mgcpp/matrix/device_matrix.hpp>
#include <mgcpp/vector/device_vector.hpp>

TEST(column_view, construction) {
  auto mat = mgcpp::device_matrix<float>::from_list({{1, 2, 3}, {4, 5, 6}});

  auto view = mat.column(0);

  EXPECT_NO_THROW(do {
    EXPECT_EQ(view.check_value(0), 1);
    EXPECT_EQ(view.check_value(1), 4);

    EXPECT_EQ(view.shape(), 2);
  } while (false));
}

TEST(column_view, copy_from_init_list) {
  mgcpp::device_matrix<float> mat({2, 3});

  auto first = mat.column(0);
  auto second = mat.column(1);
  auto third = mat.column(2);
  first = {1, 2};
  second = {3, 4};
  third = {5, 6};

  EXPECT_NO_THROW(do {
    EXPECT_EQ(mat.check_value(0, 0), 1);
    EXPECT_EQ(mat.check_value(1, 0), 2);
    EXPECT_EQ(mat.check_value(0, 1), 3);
    EXPECT_EQ(mat.check_value(1, 1), 4);
    EXPECT_EQ(mat.check_value(0, 2), 5);
    EXPECT_EQ(mat.check_value(1, 2), 6);
  } while (false));
}

TEST(column_view, copy_from_device_vector) {
  mgcpp::device_matrix<float> mat({3, 2});

  auto first = mat.column(0);
  auto second = mat.column(1);
  first = mgcpp::device_vector<float>({1, 2, 3});
  second = mgcpp::device_vector<float>({4, 5, 6});

  EXPECT_NO_THROW(do {
    EXPECT_EQ(mat.check_value(0, 0), 1);
    EXPECT_EQ(mat.check_value(1, 0), 2);
    EXPECT_EQ(mat.check_value(2, 0), 3);
    EXPECT_EQ(mat.check_value(0, 1), 4);
    EXPECT_EQ(mat.check_value(1, 1), 5);
    EXPECT_EQ(mat.check_value(2, 1), 6);
  } while (false));
}

// TEST(row_view, construction)
// {
//     auto mat = mgcpp::device_matrix<float>::from_list(
//         {{1, 2, 3},
//          {4, 5, 6}});

//     auto view = mat.row(0);

//     EXPECT_NO_THROW(
//         do
//         {
//             EXPECT_EQ(view.check_value(0), 1);
//             EXPECT_EQ(view.check_value(1), 2);
//             EXPECT_EQ(view.check_value(2), 3);

//             EXPECT_EQ(view.shape(), 3);
//         }while(false));
// }

// TEST(row_view, copy_from_init_list)
// {
//     mgcpp::device_matrix<float> mat({2, 3});

//     auto first  = mat.row(0);
//     auto second = mat.row(1);
//     first  = {1, 2, 3};
//     second = {4, 5, 6};

//     EXPECT_NO_THROW(
//         do
//         {
//             EXPECT_EQ(mat.check_value(0, 0), 1);
//             EXPECT_EQ(mat.check_value(0, 1), 2);
//             EXPECT_EQ(mat.check_value(0, 2), 3);
//             EXPECT_EQ(mat.check_value(1, 0), 4);
//             EXPECT_EQ(mat.check_value(1, 1), 5);
//             EXPECT_EQ(mat.check_value(1, 2), 6);
//         }while(false));
// }

// TEST(row_view, copy_from_device_vector)
// {
//     mgcpp::device_matrix<float> mat({2, 3});

//     auto first = mat.row(0);
//     auto second = mat.row(1);
//     first = mgcpp::device_vector<float, mgcpp::row>({1, 2, 3});
//     second = mgcpp::device_vector<float, mgcpp::row>({4, 5, 6});

//     EXPECT_NO_THROW(
//         do
//         {
//             EXPECT_EQ(mat.check_value(0, 0), 1);
//             EXPECT_EQ(mat.check_value(0, 1), 2);
//             EXPECT_EQ(mat.check_value(0, 2), 3);
//             EXPECT_EQ(mat.check_value(1, 0), 4);
//             EXPECT_EQ(mat.check_value(1, 1), 5);
//             EXPECT_EQ(mat.check_value(1, 2), 6);
//         }while(false));
// }
