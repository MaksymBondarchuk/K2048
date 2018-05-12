//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace K2048;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}


void K2048::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Refresh();
}

void K2048::MainPage::GridGameBoard_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	board = new int[board_size*board_size];

	for (auto i = 0; i < board_size*board_size; i++)
	{
		TextBox^ square = ref new TextBox();
		square->Text = i.ToString();
		square->Width = 80;
		square->Height = 80;
		square->IsEnabled = false;
		square->FontSize = 48;
		square->Foreground = ref new SolidColorBrush(Windows::UI::Colors::Black);
		const int offset = 90;
		square->Margin = Thickness(Get_X(i) * offset, Get_Y(i) * offset, 0, 0);

		square->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Left;
		square->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
		GridGameBoard->Children->Append(square);
	}

	for (auto i = 0; i < board_size*board_size; i++)
		board[i] = 0;

	//Get_New_Number();
	board[0] = 2;
	board[4] = 8;
	board[5] = 2;
	board[8] = 2;
	board[9] = 32;
	board[10] = 2;
	board[12] = 8;
	board[13] = 256;
	board[14] = 32;
	Refresh();
}


void K2048::MainPage::Refresh()
{
	for (auto i = 0; i < board_size*board_size; i++)
	{
		auto square = (TextBox^)GridGameBoard->Children->GetAt(i);
		square->Text = board[i] == 0 ? "" : board[i].ToString();
	}
}

void K2048::MainPage::Grid_KeyDown(Platform::Object^ sender, Windows::UI::Xaml::Input::KeyRoutedEventArgs^ e)
{
	bool* merged = new bool[board_size*board_size];
	for (auto i = 0; i < board_size*board_size; i++)
		merged[i] = false;

	bool moved = false;

	if (e->Key == Windows::System::VirtualKey::Down)
	{
		for (auto j = 0; j < board_size; j++)
		{
			for (auto i = board_size - 1; 0 < i; i--)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				if (board[Get_I(j, i)] == board[Get_I(j, i - 1)] &&
					!merged[Get_I(j, i)] && !merged[Get_I(j, i - 1)])
				{
					board[Get_I(j, i)] *= 2;
					merged[Get_I(j, i)] = true;
					board[Get_I(j, i - 1)] = 0;
					moved = true;
				}
			}

			for (auto i = board_size - 1; 0 <= i; i--)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				for (auto i1 = i + 1; i1 < board_size &&
					board[Get_I(j, i1)] == 0 &&
					!merged[Get_I(j, i1 - 1)]; i1++)
				{
					board[Get_I(j, i1)] = board[Get_I(j, i1 - 1)];
					board[Get_I(j, i1 - 1)] = 0;
					moved = true;
				}
			}

			for (auto i = board_size - 1; 0 < i; i--)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				if (board[Get_I(j, i)] == board[Get_I(j, i - 1)] &&
					!merged[Get_I(j, i)] && !merged[Get_I(j, i - 1)])
				{
					board[Get_I(j, i)] *= 2;
					merged[Get_I(j, i)] = true;
					board[Get_I(j, i - 1)] = 0;
					moved = true;
				}
			}

			for (auto i = board_size - 1; 0 <= i; i--)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				for (auto i1 = i + 1; i1 < board_size &&
					board[Get_I(j, i1)] == 0; i1++)
				{
					board[Get_I(j, i1)] = board[Get_I(j, i1 - 1)];
					board[Get_I(j, i1 - 1)] = 0;
					moved = true;
				}
			}
		}
	}
	else if (e->Key == Windows::System::VirtualKey::Up)
	{
		for (auto j = 0; j < board_size; j++)
		{
			for (auto i = 0; i < board_size - 1; i++)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				if (board[Get_I(j, i)] == board[Get_I(j, i + 1)] &&
					!merged[Get_I(j, i)] && !merged[Get_I(j, i + 1)])
				{
					board[Get_I(j, i)] *= 2;
					merged[Get_I(j, i)] = true;
					board[Get_I(j, i + 1)] = 0;
					moved = true;
				}
			}

			for (auto i = 0; i < board_size; i++)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				for (auto i1 = i - 1; 0 <= i1 &&
					board[Get_I(j, i1)] == 0 &&
					!merged[Get_I(j, i1 + 1)]; i1--)
				{
					board[Get_I(j, i1)] = board[Get_I(j, i1 + 1)];
					board[Get_I(j, i1 + 1)] = 0;
					moved = true;
				}
			}

			for (auto i = 0; i < board_size - 1; i++)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				if (board[Get_I(j, i)] == board[Get_I(j, i + 1)] &&
					!merged[Get_I(j, i)] && !merged[Get_I(j, i + 1)])
				{
					board[Get_I(j, i)] *= 2;
					merged[Get_I(j, i)] = true;
					board[Get_I(j, i + 1)] = 0;
					moved = true;
				}
			}

			for (auto i = 0; i < board_size; i++)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				for (auto i1 = i - 1; 0 <= i1 &&
					board[Get_I(j, i1)] == 0 ; i1--)
				{
					board[Get_I(j, i1)] = board[Get_I(j, i1 + 1)];
					board[Get_I(j, i1 + 1)] = 0;
					moved = true;
				}
			}
		}
	}
	else if (e->Key == Windows::System::VirtualKey::Left)
	{
		for (auto i = 0; i < board_size; i++)
		{
			for (auto j = 0; j < board_size - 1; j++)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				if (board[Get_I(j, i)] == board[Get_I(j + 1, i)] &&
					!merged[Get_I(j, i)] && !merged[Get_I(j + 1, i)])
				{
					board[Get_I(j, i)] *= 2;
					merged[Get_I(j, i)] = true;
					board[Get_I(j + 1, i)] = 0;
					moved = true;
				}
			}

			for (auto j = 0; j < board_size; j++)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				for (auto j1 = j - 1; 0 <= j1 &&
					board[Get_I(j1, i)] == 0 &&
					!merged[Get_I(j1 + 1, i)]; j1--)
				{
					board[Get_I(j1, i)] = board[Get_I(j1 + 1, i)];
					board[Get_I(j1 + 1, i)] = 0;
					moved = true;
				}
			}

			for (auto j = 0; j < board_size - 1; j++)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				if (board[Get_I(j, i)] == board[Get_I(j + 1, i)] &&
					!merged[Get_I(j, i)] && !merged[Get_I(j + 1, i)])
				{
					board[Get_I(j, i)] *= 2;
					merged[Get_I(j, i)] = true;
					board[Get_I(j + 1, i)] = 0;
					moved = true;
				}
			}

			for (auto j = 0; j < board_size; j++)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				for (auto j1 = j - 1; 0 <= j1 &&
					board[Get_I(j1, i)] == 0; j1--)
				{
					board[Get_I(j1, i)] = board[Get_I(j1 + 1, i)];
					board[Get_I(j1 + 1, i)] = 0;
					moved = true;
				}
			}
		}
	}
	else if (e->Key == Windows::System::VirtualKey::Right)
	{
		for (auto i = 0; i < board_size; i++)
		{
			for (auto j = board_size - 1; 0 < j; j--)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				if (board[Get_I(j, i)] == board[Get_I(j - 1, i)] &&
					!merged[Get_I(j, i)] && !merged[Get_I(j - 1, i)])
				{
					board[Get_I(j, i)] *= 2;
					merged[Get_I(j, i)] = true;
					board[Get_I(j - 1, i)] = 0;
					moved = true;
				}
			}

			for (auto j = board_size - 1; 0 <= j; j--)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				for (auto j1 = j + 1; j1 < board_size &&
					board[Get_I(j1, i)] == 0 &&
					!merged[Get_I(j1 - 1, i)]; j1++)
				{
					board[Get_I(j1, i)] = board[Get_I(j1 - 1, i)];
					board[Get_I(j1 - 1, i)] = 0;
					moved = true;
				}
			}

			for (auto j = board_size - 1; 0 < j; j--)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				if (board[Get_I(j, i)] == board[Get_I(j - 1, i)] &&
					!merged[Get_I(j, i)] && !merged[Get_I(j - 1, i)])
				{
					board[Get_I(j, i)] *= 2;
					merged[Get_I(j, i)] = true;
					board[Get_I(j - 1, i)] = 0;
					moved = true;
				}
			}

			for (auto j = board_size - 1; 0 <= j; j--)
			{
				if (board[Get_I(j, i)] == 0)
					continue;

				for (auto j1 = j + 1; j1 < board_size &&
					board[Get_I(j1, i)] == 0; j1++)
				{
					board[Get_I(j1, i)] = board[Get_I(j1 - 1, i)];
					board[Get_I(j1 - 1, i)] = 0;
					moved = true;
				}
			}
		}
	}

	if (moved)
		Get_New_Number();
}

int K2048::MainPage::Get_X(int i)
{
	return i % board_size;
}

int K2048::MainPage::Get_Y(int i)
{
	return i / board_size;
}

int K2048::MainPage::Get_I(int x, int y)
{
	if (x < 0 || board_size <= x)
		throw ref new InvalidArgumentException("X is out of range");
	if (y < 0 || board_size <= y)
		throw ref new InvalidArgumentException("Y is out of range");
	return y * board_size + x;
}

bool K2048::MainPage::Get_New_Number()
{
	int count_of_zeros = 0;
	for (int i = 0; i < board_size * board_size; i++)
	{
		if (board[i] == 0)
			count_of_zeros++;
	}

	if (count_of_zeros == 0)
		return false;

	srand((unsigned)time(0));

	int one_to_ten = 1 + (rand() % 10);
	int new_number = one_to_ten <= 9 ? 2 : 4;

	int* zeros_indeces = new int[count_of_zeros];
	int j = 0;
	for (int i = 0; i < board_size * board_size; i++)
	{
		if (board[i] == 0)
		{
			zeros_indeces[j] = i;
			j++;
		}
	}

	int where_to_put_new_number = rand() % count_of_zeros;
	board[zeros_indeces[where_to_put_new_number]] = new_number;

	Refresh();

	return true;
}


void K2048::MainPage::Button_Click_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	for (auto i = 0; i < board_size*board_size; i++)
		board[i] = 0;

	board[0] = 2;
	board[4] = 2;
	board[8] = 2;
	board[12] = 2;
	Refresh();
}


void K2048::MainPage::ButtonNewGame_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	for (auto i = 0; i < board_size*board_size; i++)
		board[i] = 0;

	Get_New_Number();
}
