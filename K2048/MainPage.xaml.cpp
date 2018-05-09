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

}


void K2048::MainPage::GridGameBoard_KeyDown(Platform::Object^ sender, Windows::UI::Xaml::Input::KeyRoutedEventArgs^ e)
{
	if (e->Key == Windows::System::VirtualKey::Down)
	{
		for (auto i = board_size - 2; 0 <= i; i--)
		{
			for (auto j = 0; j < board_size; j++)
			{
				if (board[Get_I(j, i)] == board[Get_I(j, i + 1)])
				{
					board[Get_I(j, i + 1)] *= 2;
					board[Get_I(j, i)] = 0;
				}

				if (board[Get_I(j, i + 1)] == 0)
					board[Get_I(j, i + 1)] = board[Get_I(j, i)];
			}
		}
	}
	else if (e->Key == Windows::System::VirtualKey::Right)
	{
		auto x = 0;
	}
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
		const int offset = 90;
		square->Margin = Thickness(Get_X(i) * offset, Get_Y(i) * offset, 0, 0);

		square->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Left;
		square->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
		GridGameBoard->Children->Append(square);
	}
}


void K2048::MainPage::Refresh()
{
	for (auto i = 0; i < board_size*board_size; i++)
	{

	}
}

void K2048::MainPage::Grid_KeyDown(Platform::Object^ sender, Windows::UI::Xaml::Input::KeyRoutedEventArgs^ e)
{
	if (e->Key == Windows::System::VirtualKey::Down)
	{
		auto x = 0;
	}
	else if (e->Key == Windows::System::VirtualKey::Right)
	{
		auto x = 0;
	}
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
	return y * board_size + x;
}
