#include <App.hpp>
#include <Button.hpp>
#include <FileDialog.hpp>
#include <Window.hpp>
#include <ComboBox.hpp>
#include <ImageBox.hpp>
#include <Label.hpp>

using namespace Goo;

class MyWindow : public Window
{
public:
	MyWindow() {
		SetText("Test");
		SetSize({340, 320});

		comboBox.SetBounds({ 50, 50 }, { 120, 20 });
		label.SetBounds({ 180, 53 }, {100, 20});

		button.SetBounds({120, 220}, {80, 25});
		imgBox.SetBounds({ 110, 100 }, { 100, 100 });

		comboBox.AddItem("This is an item!");
		comboBox.AddItem("This is also an item!");

		comboBox.OnSelectionChanged.SetHandler([this](int index)
		{
			label.SetText("Selected item #" + std::to_string(index));
		});
		button.OnClick.SetHandler([this]()
		{
			OpenFileDialog dlg{ "Open an image file", "Bitmap files (*.bmp)|*.bmp" };
			if (dlg.ShowDialog() == DialogResult::OK)
			{
				imgBox.SetImage(Image(dlg.GetFileName()));
			}
		});

		AddControl(label);
		AddControl(button);
		AddControl(comboBox);
		AddControl(imgBox);
	}

	Label label{ "This is a label!" };
	Button button{ "Select Image" };
	ComboBox comboBox;
	ImageBox imgBox;
};

int main()
{
	MyWindow wnd;
	wnd.Show();
	Application::Run();
}
