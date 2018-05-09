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

}


void K2048::MainPage::GridGameBoard_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	board = new int[board_size*board_size];

	for (auto i = 0; i < board_size*board_size; i++)
	{
		//MainPage::d

		TextBox^ square = ref new TextBox();
		square->Text = i.ToString();
		square->Width = 80;
		square->Height = 80;
		square->IsEnabled = false;
		const int offset = 170;
		square->Margin = Thickness((i % board_size) * offset, (i / board_size) * offset, 0, 0);
		//square->HorizontalAlignment = HorizontalAlignment;
		//autkco a = square->HorizontalContentAlignment;
		//square->Margin = Thickness(0, 0, (i % board_size) * offset, (i / board_size) * offset);
		GridGameBoard->Children->Append(square);
	}
}
