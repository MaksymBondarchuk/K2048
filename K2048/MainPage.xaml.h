//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace K2048
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();


	private:
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void GridGameBoard_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

		const int board_size = 4;
		int* board;

		void Refresh();

		void Grid_KeyDown(Platform::Object^ sender, Windows::UI::Xaml::Input::KeyRoutedEventArgs^ e);

		int Get_X(int i);
		int Get_Y(int i);
		int Get_I(int x, int y);

		int Get_Count_Of_Empty_Squares();
		bool Get_New_Number();
		bool Is_Game_Over();

		void Button_Click_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ButtonNewGame_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
