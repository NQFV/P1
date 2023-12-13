#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <vector>
#include "../Pr_1/FileData.h"
#include "../Pr_1/FileData.cpp"
#include "../Pr_1/FileDate.h"
#include "../Pr_1/FileDate.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(ValidFormatDate)
		{
			std::vector<std::string> Cases
			{
				"2021.10.12",
				"2001.1.1",
				"2023.12.11"
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = Date::ValidateDate(Cases[i]);
				Assert::IsTrue(result);
			}
		}

		TEST_METHOD(InvalidFormatDate)
		{
			std::vector<std::string> Cases
			{
				"10.12.2023",
				"ab.cd.df",
				"Hello"

			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					Date::InvalidDate(Cases[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidFormatName)
		{
			std::vector<std::string> Cases
			{
				"File1",
				"Dont_Delete_Pls",
				"Very_Important_File",
				"New_file1",
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = FileData::ValidateName(Cases[i]);
				Assert::IsTrue(result);
			}
		}
		TEST_METHOD(InvalidFormatName)
		{
			std::vector<std::string> Cases
			{
				"Hello?",
				"19|84",
				"Привет"

			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					FileData::InvalidName(Cases[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidFormatSize)
		{
			std::vector<int> Cases
			{
				23,
				1,
				0,
				11
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = FileData::ValidateSize(Cases[i]);
				Assert::IsTrue(result);
			}
		}
		TEST_METHOD(InvalidFormatSize)
		{
			std::vector<int> Cases
			{
				-1,
				-2
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					FileData::InvalidSize(Cases[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidTestFileData)
		{
			std::istringstream input("\"File1\" 2023.12.11 2048");
			std::string str_name = "\"File1\"";
			FileData file_data;
			file_data.ReadFileData(input);
			Assert::AreEqual(str_name, file_data.GetName());
			Date date;
			date = file_data.GetCreationDate();
			Assert::AreEqual(2023, static_cast<int>(date.GetYear()));
			Assert::AreEqual(12, static_cast<int>(date.GetMonth()));
			Assert::AreEqual(11, static_cast<int>(date.GetDay()));
			Assert::AreEqual(2048, file_data.GetSize());
		}
		TEST_METHOD(InvalidTestMenu)
		{
			std::vector<std::string> cases
			{
				"1231 13123.1 3213 1 fadasd",
				"aaad 131 vdvs a1",
				"da312 das 123"
			};
			for (int i = 0; i < cases.size(); i++)
			{
				std::istringstream input(cases[i]);
				try
				{
					FileData file_data;
					file_data.ReadFileData(input);
					throw std::runtime_error("Error in runtime");
				}
				catch (const std::runtime_error& e)
				{
					std::cerr << "Error Message: " << e.what() << std::endl;
				}
			}
		}
		TEST_METHOD(ValidMenuWrite)
		{
			std::istringstream input("\"File1\" 2023.12.11 2048");
			FileData file_data;
			file_data.ReadFileData(input);
			std::ostringstream expected_output;
			expected_output << "File Name: " << file_data.GetName() << std::endl;
			Date date = file_data.GetCreationDate();
			date.WriteDate(expected_output);
			expected_output << "Size (in bytes): " << file_data.GetSize() << std::endl;
			std::ostringstream actual_output;
			file_data.WriteFileData(actual_output);
			Assert::AreEqual(expected_output.str(), actual_output.str());
		}

		TEST_METHOD(ValidDateWrite)
		{
			std::istringstream input("2023.12.11");
			Date date;
			const char point = '.';
			date.ReadDate(input);
			std::ostringstream expected_output;
			expected_output << "Creation Date: "
				<< date.GetYear() << point
				<< std::setfill('0') << std::setw(2) << date.GetMonth() << point
				<< std::setfill('0') << std::setw(2) << date.GetDay() << std::endl;
			std::ostringstream actual_output;
			date.WriteDate(actual_output);
			Assert::AreEqual(expected_output.str(), actual_output.str());
		}
	};
}
