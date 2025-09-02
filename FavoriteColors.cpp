#include <iostream>

class ColorsSingleton
{
private:
	int color = 0;

	static ColorsSingleton* m_instance;
	ColorsSingleton() = default;

	ColorsSingleton(ColorsSingleton&) = delete;
	ColorsSingleton& operator = (ColorsSingleton&) = delete;
	ColorsSingleton(ColorsSingleton&&) = delete;
	ColorsSingleton& operator = (ColorsSingleton&&) = delete;

	int GetColorBit(int ColorIndex)
	{
		int i = 1;
		i = i << ColorIndex;
		return i;
	}

public:

	static ColorsSingleton* instance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new ColorsSingleton();
		}
		return m_instance;
	}

	void AddColor(const int ColorIndex)
	{

		if (ColorIndex <= 12 && ColorIndex >= 0)
		{
			int i = GetColorBit(ColorIndex);
			color = color | i;
			std::cout << "Successfully added:) \n\n";
		}
	}
	void RemoveColor(const int RemoveColor)
	{

		if (RemoveColor <= 12 && RemoveColor >= 0)
		{
			int i = GetColorBit(RemoveColor);
			if (color & i)
			{
				color = color ^ i;
				std::cout << "Successfully removed :( \n\n";
			}
			else
			{
				std::cout << "This color wasn't your favorite \n\n";
			}
		}
	}

	void PrintFavoriteColors()
	{

		if (color == 0)
		{
			std::cout << "You have no favorite colors\n";
		}
		else
		{
			int ColorIndex = 0;
			std::cout << "Your favorite colors are:";
			while (ColorIndex < 13)
			{
				int i = GetColorBit(ColorIndex);
				int Favorite = color & i;
				if (Favorite)
				{
					std::cout << " " << ColorIndex;
				}
				ColorIndex++;
			}
			std::cout << "\n";
		}


	}
};

ColorsSingleton* ColorsSingleton::m_instance = nullptr;

int GetColorIndex()
{
	int ColorIndex;
	std::cout << "Enter color folowing the instruction: \n"
		<< "0 - red \n" << "1 - blue \n" << "2 - green \n"
		<< "3 - yellow \n" << "4 - violet \n" << "5 - sky-blue \n"
		<< "6 - white \n" << "7 - black \n" << "8 - orange \n"
		<< "9 - beige \n" << "10 - pink \n" << "11 - light green \n"
		<< "12 - grey \n \n";

	std::cin >> ColorIndex;
	return ColorIndex;
}


int main()
{
	while (true)
	{
		std::cout << "1. Add favorite color \n"
			<< "2. Remove favorite \n"
			<< "3. Show favorites \n"
			<< "4. Exit \n"
			<< "Please, choose one of the points: \n \n";
		int input = 0;
		std::cin >> input;

		if (input == 1)
		{
			ColorsSingleton* s = ColorsSingleton::instance();
			int ColorIndex = GetColorIndex();
			s->AddColor(ColorIndex);

		}
		else if (input == 2)
		{
			ColorsSingleton* s = ColorsSingleton::instance();
			int ColorIndex = GetColorIndex();
			s->RemoveColor(ColorIndex);

		}
		else if (input == 3)
		{
			ColorsSingleton* s = ColorsSingleton::instance();
			s->PrintFavoriteColors();
		}
		else if (input == 4)
		{
			return 0;
		}

	}

	return 0;
}