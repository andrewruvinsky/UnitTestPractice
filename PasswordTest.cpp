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

/**** count_leading_characters unit tests ****/
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

/**** has_mixed_case unit tests ****/

TEST(PasswordTest, empty_string_mixed_case)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case(""));
}

TEST(PasswordTest, single_character)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("a"));
}

TEST(PasswordTest, special_char_and_num)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("$1"));
}

TEST(PasswordTest, special_char_and_letter)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("$a"));
}

TEST(PasswordTest, all_lower_case_and_number)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("abc123"));
}

TEST(PasswordTest, all_lower_case_with_space)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("abc xyz"));
}

TEST(PasswordTest, all_lower_case_with_newline)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("abc\n"));
}

TEST(PasswordTest, all_lower_case)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("abc"));
}

TEST(PasswordTest, all_upper_case)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("ABC"));
}

TEST(PasswordTest, mixed_case)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("aBc"));
}

// Beats implementation E
TEST(PasswordTest, lower_upper)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("aB"));
}

/**** unique_characters unit tests ****/

/* Receives a string and returns a count of how many case-sensitive
unique characters there are. If there are duplicate instances of
the same character it should only count as a single character.
Even if characters look similar, as long as they have distinct ASCII values,
they should qualify as unique characters. */

TEST(PasswordTest, same_character_lower_upper)
{
	Password my_password;
	ASSERT_EQ(2, my_password.unique_characters("aA"));
}
