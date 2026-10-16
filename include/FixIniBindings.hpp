#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <fstream>
#include <filesystem>
#include <algorithm>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace FixIniBindings
{
	static std::string FixPipeSpacing(const std::string& input)
	{
		std::string result;
		result.reserve(input.length() + 16);
		size_t i = 0;

		// Skip leading pipes and spaces
		while (i < input.length() && (input[i] == '|' || input[i] == ' ' || input[i] == '\t'))
		{
			i++;
		}

		for (; i < input.length(); i++)
		{
			if (input[i] == '|')
			{
				// Remove trailing spaces
				while (!result.empty() && result.back() == ' ')
				{
					result.pop_back();
				}

				result += ' ';
				result += '|';

				// Skip spaces after pipe
				while (i + 1 < input.length() && (input[i + 1] == ' ' || input[i + 1] == '\t'))
				{
					i++;
				}

				result += ' ';
			}
			else
			{
				result += input[i];
			}
		}

		// Remove trailing spaces
		while (!result.empty() && result.back() == ' ')
		{
			result.pop_back();
		}

		return result;
	}

	static bool IsBindingLine(const std::string& line)
	{
		size_t start = line.find_first_not_of(" \t");
		if (start == std::string::npos)
		{
			return false;
		}

		std::string_view sv(line.data() + start, line.size() - start);

		return sv.substr(0, 10) == ".Bindings="
			|| sv.substr(0, 10) == "+Bindings="
			|| sv.substr(0, 14) == "KeyBindArray1="
			|| sv.substr(0, 14) == "KeyBindArray2=";
	}

	static bool FixLine(std::string& str)
	{
		if (!IsBindingLine(str))
		{
			return false;
		}

		if (str.find("(Name=") == std::string::npos || str.find("Command=") == std::string::npos)
		{
			return false;
		}

		bool wasModified = false;

		// Normalize ", Command=" to ",Command="
		size_t nameEndQuote = str.find("\",");
		if (nameEndQuote != std::string::npos)
		{
			size_t afterComma = nameEndQuote + 2;
			size_t commandKeyword = str.find("Command=", afterComma);
			if (commandKeyword != std::string::npos && commandKeyword > afterComma)
			{
				bool allWhitespace = std::all_of(str.begin() + afterComma, str.begin() + commandKeyword, [](char c) { return c == ' ' || c == '\t'; });
				if (allWhitespace)
				{
					str.erase(afterComma, commandKeyword - afterComma);
					wasModified = true;
				}
			}
		}

		// Fix pipe spacing within Command="..."
		size_t commandPos = str.find(",Command=\"");
		if (commandPos == std::string::npos)
		{
			return wasModified;
		}

		commandPos += 10;

		size_t endQuotePos = str.find('"', commandPos);
		if (endQuotePos == std::string::npos)
		{
			return wasModified;
		}

		std::string commandValue = str.substr(commandPos, endQuotePos - commandPos);
		std::string fixedCommand = FixPipeSpacing(commandValue);

		if (fixedCommand != commandValue)
		{
			str.replace(commandPos, endQuotePos - commandPos, fixedCommand);
			wasModified = true;
		}

		return wasModified;
	}

	static bool FixFile(const std::filesystem::path& filePath)
	{
		if (!std::filesystem::exists(filePath))
		{
			return false;
		}

		std::vector<std::string> lines;
		{
			std::ifstream inFile(filePath, std::ios::binary);
			if (!inFile.is_open())
			{
				return false;
			}

			std::string line;
			while (std::getline(inFile, line))
			{
				if (!line.empty() && line.back() == '\r')
				{
					line.pop_back();
				}

				lines.push_back(std::move(line));
			}
		}

		bool anyModified = false;
		for (auto& l : lines)
		{
			if (FixLine(l))
			{
				anyModified = true;
			}
		}

		if (!anyModified)
		{
			return false;
		}

		std::ofstream outFile(filePath, std::ios::binary | std::ios::trunc);
		if (!outFile.is_open())
		{
			return false;
		}

		for (size_t i = 0; i < lines.size(); i++)
		{
			outFile << lines[i];
			if (i + 1 < lines.size())
			{
				outFile << "\r\n";
			}
		}

		return outFile.good();
	}

	static void FixAll()
	{
		char exePath[MAX_PATH];
		GetModuleFileNameA(NULL, exePath, MAX_PATH);

		std::filesystem::path configDir = std::filesystem::weakly_canonical(std::filesystem::path(exePath).parent_path() / ".." / ".." / "AliceGame" / "Config");

		FixFile(configDir / "DefaultInput.ini");
		FixFile(configDir / "DefaultControlLayout.ini");
	}
}