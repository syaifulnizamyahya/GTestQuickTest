#pragma once
#include "pch.h"
#include "../MathLibrary/MathLibrary.h"

//===================================================================================================
//TEST(<ClassName>Test, <Method>_<Scenario>_<ExpectedBehaviour>)
 //unit tests for static or global functions or simple classes
TEST(ArithmeticStaticMethod, Add_Int_ReturnSums)
{
    // Arrange
    double expected = 5;
    // Act
    double actual = MathLibrary::Arithmetic::Add(2, 3);

    // Assert
    EXPECT_EQ(expected, actual);
}

//===================================================================================================
// TestFixture for non static method
class ArithmeticFixtureTest : public testing::Test
{
protected:

    ArithmeticFixtureTest() {
        // You can do set-up work for each test here.
    }

    ~ArithmeticFixtureTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    // Class members declared here can be used by all tests in the test suite
    // for Foo.
};

// need access to objects and subroutines in the unit test
TEST_F(ArithmeticFixtureTest, Divide_TwoInteger_ReturnDivided)
{
    // Arrange
    MathLibrary::Arithmetic arithmetic;
    double expected = 5;
    // Act
    double actual = arithmetic.Divide(10, 2);

    // Assert
    EXPECT_EQ(expected, actual);
}

//===================================================================================================
// Parametric test
class ArithmeticParametricTest :public ::testing::TestWithParam<std::tuple<double, double, double>> {
protected:

    ArithmeticParametricTest() {
        // You can do set-up work for each test here.
    }

    ~ArithmeticParametricTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    // Class members declared here can be used by all tests in the test suite
    // for Foo.
    MathLibrary::Arithmetic arithmetic;
};

// Define parameter
INSTANTIATE_TEST_CASE_P(
    ArithmeticMultiplyParametricTest,
    ArithmeticParametricTest,
    ::testing::Values(
        std::make_tuple(2, 3, 6)
        , std::make_tuple(3, 4, 12)
    ));

// Tests with parameter
TEST_P(ArithmeticParametricTest, Multiply_TwoInteger_ReturnMult)
{
    // Arrange
    double expected = std::get<2>(GetParam());

    // Act
    double actual = arithmetic.Multiply(std::get<0>(GetParam()), std::get<1>(GetParam()));

    // Assert
    EXPECT_EQ(expected, actual);
}

