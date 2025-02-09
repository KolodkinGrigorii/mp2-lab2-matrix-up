#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TMatrix<int> m(static_cast<int>(65537)));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
    TMatrix<int> m(5);

    ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> m1(5);
    m1[0].setElement(0, 1);
    m1[0].setElement(1, 1);
    m1[0].setElement(2, 1);
    TMatrix<int> m2(m1);
    EXPECT_EQ(m2, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> m1(5);
    m1[0].setElement(0, 1);
    m1[0].setElement(1, 1);
    m1[0].setElement(2, 1);
    TMatrix<int> m2(m1);
    m2[0].setElement(0, 5);
    EXPECT_NE(m2, m1);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> m1(5);
    int size = 5;
    EXPECT_EQ(5, m1.getSize());
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> m(5);
    m[0].setElement(1, 5);
    EXPECT_EQ(5, m[0].getElement(1));
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> m(5);
    ASSERT_ANY_THROW(m.getElement(-1));
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> m(5);
    ASSERT_ANY_THROW(m.getElement(7));
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> m1(5);
    ASSERT_NO_THROW(m1 = m1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> m1(5);
    TMatrix<int> m2(5);
    ASSERT_NO_THROW(m2 = m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    const int size1 = 4, size2 = 5;
    TMatrix<int> m1(size1);
    TMatrix<int> m2(size2);
    m1[0].setElement(0, 1);
    m2[0].setElement(1, 2);
    m2 = m1;
    EXPECT_EQ(size1, m2.getSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    const int size1 = 4, size2 = 5;
    TMatrix<int> m1(size1);
    TMatrix<int> m2(size2);
    m1[0].setElement(0, 1);
    m2[0].setElement(1, 2);
    m2 = m1;
    EXPECT_EQ(m1[0].getElement(0),m2[0].getElement(0));
    EXPECT_EQ(m1[0].getElement(1), m2[0].getElement(1));
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> m1(5);
    TMatrix<int> m2(5);
    m1[0].setElement(0, 1);
    m1[0].setElement(1, 2);
    m1[0].setElement(2, 3);
    m2[0].setElement(0, 1);
    m2[0].setElement(1, 2);
    m2[0].setElement(2, 3);
    EXPECT_EQ(true, m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> m1(5);
    TMatrix<int> m2(5);
    m1[0].setElement(0, 1);
    m1[0].setElement(1, 2);
    m1[0].setElement(2, 3);
    EXPECT_EQ(true, m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> m1(5);
    TMatrix<int> m2(6);
    m1[0].setElement(0, 1);
    m1[0].setElement(1, 2);
    m1[0].setElement(2, 3);
    m2[0].setElement(0, 1);
    m2[0].setElement(1, 2);
    m2[0].setElement(2, 3);
    EXPECT_EQ(false, m1 == m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> m1(5);
    TMatrix<int> m2(5);
    TMatrix<int> m3(5);
    m1[0][0] = 1;
    m1[0][1] = 1;
    m2[0][0] = 1;
    m2[0][1] = 1;
    m3[0][0] = 2;
    m3[0][1] = 2;
    EXPECT_EQ(m3, m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> m1(5);
    TMatrix<int> m2(6);
    ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> m1(5);
    TMatrix<int> m2(5);
    TMatrix<int> m3(5);
    m1[0][0] = 1;
    m1[0][1] = 1;
    m2[0][0] = 1;
    m2[0][1] = 1;
    m3[0][0] = 2;
    m3[0][1] = 2;
    EXPECT_EQ(m1, m3-m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> m1(5);
    TMatrix<int> m2(6);
    ASSERT_ANY_THROW(m1 + m2);
}
