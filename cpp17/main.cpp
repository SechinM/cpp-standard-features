#include <iostream>
#include <unordered_map>

//
// Structured binding
//

const std::unordered_map<std::string, std::string> ImgTypes{
	{ ".png", "image/png" },
	{ ".gif", "image/gif" },
};

std::pair<std::string, std::string> GetFirst()
{
	return *ImgTypes.begin();
}

int main()
{
	for (const auto& [extension, type] : ImgTypes)
	{
		std::cout << "Extension - \"" << extension << "\" Type - \"" << type << "\"" << std::endl;
	}

	const auto& [ext, type] = GetFirst();
	std::cout << "Type - \"" << type << "\" Extension - \"" << ext << "\"" << std::endl;
}