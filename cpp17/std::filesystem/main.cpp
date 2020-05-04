#include <fstream>
#include <iostream>
#include <filesystem>

//
// std::filesystem
//

namespace detail
{

static const std::string FileName{ "test.txt" };
static const std::string NewDirName{ "test_me" };
static const std::string Tmp{ "/tmp" };

}

int main()
{
	auto path{ std::filesystem::path(detail::Tmp) };
	auto pathToFile{ path };
	std::ofstream(pathToFile.append(detail::FileName)).put('a');
	std::filesystem::create_directory(path.append(detail::NewDirName));

	if (std::filesystem::exists(path) && std::filesystem::exists(pathToFile))
	{
		std::filesystem::copy_file(pathToFile, path.append(detail::FileName));
	}
}