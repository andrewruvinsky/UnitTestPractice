/**
 * Unit Tests for Password class
**/

// IGNORE ERROR: gtest library included in Docker environment, not here
#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("a");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_leading_letters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aa");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, two_leading_followed_by_different_letter)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aab");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, case_sensitive)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aAb");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_subsequent_after_single_different_letter)
{
	Password my_password;
	int actual = my_password.count_leading_characters("baa");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_case_leading_letters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAa");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, empty_string)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}
